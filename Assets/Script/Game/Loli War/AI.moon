Dorothy builtin.Platformer
{store:Store} = Data
{
	:MaxBunnies
} = Store

gameEndWait = Seq {
	Con "game end",=> Store.winner ~= nil
	Sel {
		Seq {
			 Con "need wait",=> @onSurface and not @isDoing "wait"
			Act "cancel"
			Act "wait"
		}
		Pass!
	}
}

Store["PlayerControlAI"] = Sel {
	Seq {
		Con "is dead",=> @entity.hp <= 0
		Pass!
	}
	Seq {
		Con "pushing switch",=> @isDoing "pushSwitch"
		Pass!
	}
	Seq {
		Seq {
			Con "move key down",=>
				not (@entity.keyLeft and @entity.keyRight) and
				(
					(@entity.keyLeft and @faceRight) or
					(@entity.keyRight and not @faceRight)
				)
			Act "turn"
		}
		Reject!
	}
	Seq {
		Con "attack key down",=> Store.winner == nil and @entity.keyF
		Sel {
			Seq {
				Con "at switch",=>
					theSwitch = @entity.atSwitch
					theSwitch ~= nil and not theSwitch.entity.pushed and
					(@x < theSwitch.x == @faceRight)
				Act "pushSwitch"
			}
			Act "villyAttack"
			Act "meleeAttack"
			Act "rangeAttack"
		}
	}
	Sel {
		Seq {
			Con "is falling",=> not @onSurface
			Act "fallOff"
		}
		Seq {
			Con "jump key down",=> @entity.keyUp
			Act "jump"
		}
	}
	Seq {
		Con "move key down",=> @entity.keyLeft or @entity.keyRight
		Act "walk"
	}
	Seq {
		Con "need stop",=> @onSurface and @isDoing "walk"
		Act "cancel"
		Act "idle"
	}
	Act "idle"
}

heroes = Group {"hero"}
Store["HeroAI"] = Sel {
	Seq {
		Con "is dead",=> @entity.hp <= 0
		Pass!
	}
	Seq {
		Con "is falling",=> not @onSurface
		Act "fallOff"
	}
	gameEndWait
	Seq {
		Con "need attack",=>
			attackUnits = AI\getUnitsInAttackRange!
			for unit in *attackUnits
				if Relation.Enemy == Data\getRelation(@,unit) and
					(@x < unit.x) == @faceRight
					return true
			false
		Sel {
			Act "villyAttack"
			Act "rangeAttack"
			Act "meleeAttack"
		}
	}
	Seq {
		Con "not facing enemy",=> heroes\each (hero)->
			{:unit} = hero
			if Relation.Enemy == Data\getRelation unit,@
				if (@x > unit.x) == @faceRight
					return true
		Act "turn"
	}
	Seq {
		Con "need turn",=> 
			(@x < 100 and not @faceRight) or (@x > 3990 and @faceRight)
		Act "turn"
	}
	Seq {
		Con "wanna jump",=> App.rand % 20 == 0
		Act "jump"
	}
	Seq {
		Con "is at enemy side",=> heroes\each (hero)->
			{:unit} = hero
			if Relation.Enemy == Data\getRelation unit,@
				if math.abs(@x - unit.x) < 50
					return true
		Act "idle"
	}
	Act "walk"
}

Store["BunnyForwardReturnAI"] = Sel {
	Seq {
		Con "is dead",=> @entity.hp <= 0
		Pass!
	}
	Seq {
		Con "is falling",=> not @onSurface
		Act "fallOff"
	}
	gameEndWait
	Seq {
		Con "need attack",=>
			attackUnits = AI\getUnitsInAttackRange!
			for unit in *attackUnits
				if Relation.Enemy == Data\getRelation(@,unit) and
					(@x < unit.x) == @faceRight
					return App.rand % 5 ~= 0
			false
		Act "meleeAttack"
	}
	Seq {
		Con "need turn",=>
			(@x < 100 and not @faceRight) or (@x > 3990 and @faceRight)
		Act "turn"
	}
	Act "walk"
}

Store["SwitchAI"] = Sel {
	Seq {
		Con "is pushed",=> @entity.pushed
		Act "pushed"
	}
	Act "waitUser"
}

switches = Group {"switch_"}
turnToSwitch = Seq {
	Con "go to switch",=> switches\each (switch_)->
		if switch_.group == @group and @entity.targetSwitch == switch_.switch_
			return (@x > switch_.unit.x) == @faceRight
	Act "turn"
	Reject!
}
Store["BunnySwitcherAI"] = Sel {
	Seq {
		Con "is dead",=> @entity.hp <= 0
		Pass!
	}
	Seq {
		Con "is falling",=> not @onSurface
		Act "fallOff"
	}
	gameEndWait
	Seq {
		Con "need attack",=>
			attackUnits = AI\getUnitsInAttackRange!
			for unit in *attackUnits
				if Relation.Enemy == Data\getRelation(@,unit) and
					(@x < unit.x) == @faceRight
					return App.rand % 5 ~= 0
			false
		Act "meleeAttack"
	}
	Seq {
		Con "at switch",=> with @entity
			return .atSwitch ~= nil and .atSwitch.entity.switch_ == .targetSwitch
		Sel {
			Seq {
				Con "switch available",=> heroes\each (hero)->
					return false if @group ~= hero.group
					needEP,available = switch @entity.targetSwitch
						when "Switch"
							bunnyCount = 0
							Group({"bunny"})\each (bunny)->
								bunnyCount += 1 if bunny.group == @group
							1,bunnyCount < MaxBunnies
						when "SwitchG"
							2,hero.defending
					if hero.ep >= needEP and available
						if not @entity.atSwitch\isDoing "pushed"
							hero.defending = false if @entity.targetSwitch == "SwitchG"
							return true
				Act "pushSwitch"
			}
			Seq {
				Con "need stop",=> @onSurface and @isDoing "walk"
				Act "cancel"
				Reject!
			}
			turnToSwitch
			Act "idle"
		}
	}
	Seq {
		Con "need turn",=>
			(@x < 100 and not @faceRight) or (@x > 3990 and @faceRight)
		Act "turn"
	}
	turnToSwitch
	Act "walk"
}
