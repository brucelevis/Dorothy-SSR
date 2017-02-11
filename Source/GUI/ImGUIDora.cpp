/* Copyright (c) 2017 Jin Li, http://www.luvfight.me

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#include "Const/Header.h"
#include "GUI/ImGUIDora.h"
#include "imgui.h"
#include "Other/utf8.h"

NS_DOROTHY_BEGIN

ImGUIDora::ImGUIDora():
_keydownDel(0),
_editingDel(0),
_textLength(0),
_textEditing{},
_textInputing(false),
_viewId(255),
_mousePressed{ false, false, false },
_mouseWheel(0.0f),
_listener(Listener::create("AppSDLEvent"_slice, std::make_pair(this, &ImGUIDora::handleEvent)))
{
	_vertexDecl
		.begin()
			.add(bgfx::Attrib::Position, 2, bgfx::AttribType::Float)
			.add(bgfx::Attrib::TexCoord0, 2, bgfx::AttribType::Float)
			.add(bgfx::Attrib::Color0, 4, bgfx::AttribType::Uint8, true)
		.end();
}

ImGUIDora::~ImGUIDora()
{
	if (bgfx::isValid(_textureSampler))
	{
		bgfx::destroyUniform(_textureSampler);
	}
	ImGui::Shutdown();
}

const char* ImGUIDora::getClipboardText(void*)
{
	return SDL_GetClipboardText();
}

void ImGUIDora::setClipboardText(void*, const char* text)
{
	SDL_SetClipboardText(text);
}

bool ImGUIDora::init()
{
	bgfx::setViewName(_viewId, "ImGui");
	bgfx::setViewSeq(_viewId, true);

	ImGuiIO& io = ImGui::GetIO();
	io.KeyMap[ImGuiKey_Tab] = SDLK_TAB;
	io.KeyMap[ImGuiKey_LeftArrow] = SDL_SCANCODE_LEFT;
	io.KeyMap[ImGuiKey_RightArrow] = SDL_SCANCODE_RIGHT;
	io.KeyMap[ImGuiKey_UpArrow] = SDL_SCANCODE_UP;
	io.KeyMap[ImGuiKey_DownArrow] = SDL_SCANCODE_DOWN;
	io.KeyMap[ImGuiKey_PageUp] = SDL_SCANCODE_PAGEUP;
	io.KeyMap[ImGuiKey_PageDown] = SDL_SCANCODE_PAGEDOWN;
	io.KeyMap[ImGuiKey_Home] = SDL_SCANCODE_HOME;
	io.KeyMap[ImGuiKey_End] = SDL_SCANCODE_END;
	io.KeyMap[ImGuiKey_Delete] = SDLK_DELETE;
	io.KeyMap[ImGuiKey_Backspace] = SDLK_BACKSPACE;
	io.KeyMap[ImGuiKey_Enter] = SDLK_RETURN;
	io.KeyMap[ImGuiKey_Escape] = SDLK_ESCAPE;
	io.KeyMap[ImGuiKey_A] = SDLK_a;
	io.KeyMap[ImGuiKey_C] = SDLK_c;
	io.KeyMap[ImGuiKey_V] = SDLK_v;
	io.KeyMap[ImGuiKey_X] = SDLK_x;
	io.KeyMap[ImGuiKey_Y] = SDLK_y;
	io.KeyMap[ImGuiKey_Z] = SDLK_z;

	io.RenderDrawListsFn = ImGUIDora::renderDrawLists;
	io.SetClipboardTextFn = ImGUIDora::setClipboardText;
	io.GetClipboardTextFn = ImGUIDora::getClipboardText;
	io.ClipboardUserData = nullptr;

#if BX_PLATFORM_WINDOWS
	SDL_Window* window = SharedApplication.getSDLWindow();
	SDL_SysWMinfo wmInfo;
	SDL_VERSION(&wmInfo.version);
	SDL_GetWindowWMInfo(window, &wmInfo);
	io.ImeWindowHandle = wmInfo.info.win.window;
#endif // BX_PLATFORM_WINDOWS

	Shader* vertShader = SharedShaderCache.load("vs_ocornut_imgui.bin");
	Shader* fragShader = SharedShaderCache.load("fs_ocornut_imgui.bin");
	_effect = Effect::create(vertShader, fragShader);
	_textureSampler = bgfx::createUniform("s_tex", bgfx::UniformType::Int1);

	uint8_t* data;
	int32_t width;
	int32_t height;
	io.Fonts->GetTexDataAsRGBA32(&data, &width, &height);

	bgfx::TextureHandle textureHandle = bgfx::createTexture2D(
		s_cast<uint16_t>(width), s_cast<uint16_t>(height),
		false, 1, bgfx::TextureFormat::BGRA8, BGFX_TEXTURE_U_CLAMP | BGFX_TEXTURE_V_CLAMP,
		bgfx::copy(data, width*height * 4));

	bgfx::TextureInfo info;
	bgfx::calcTextureSize(info,
		s_cast<uint16_t>(width), s_cast<uint16_t>(height),
		0, false, false, 1, bgfx::TextureFormat::BGRA8);

	_fontTexture = Texture2D::create(textureHandle, info);

	SharedDirector.getSystemScheduler()->schedule([this](double deltaTime)
	{
		if (!_inputs.empty())
		{
			const auto& event = _inputs.front();
			ImGuiIO& io = ImGui::GetIO();
			switch (event.type)
			{
				case SDL_TEXTINPUT:
				{
					io.AddInputCharactersUTF8(event.text.text);
					break;
				}
				case SDL_KEYDOWN:
				case SDL_KEYUP:
				{
					int key = event.key.keysym.sym & ~SDLK_SCANCODE_MASK;
					io.KeysDown[key] = (event.type == SDL_KEYDOWN);
					io.KeyShift = ((SDL_GetModState() & KMOD_SHIFT) != 0);
					io.KeyCtrl = ((SDL_GetModState() & KMOD_CTRL) != 0);
					io.KeyAlt = ((SDL_GetModState() & KMOD_ALT) != 0);
					io.KeySuper = ((SDL_GetModState() & KMOD_GUI) != 0);
					break;
				}
			}
			_inputs.pop_front();
		}
		return false;
	});

	return true;
}

void ImGUIDora::begin()
{
	ImGuiIO& io = ImGui::GetIO();

	io.DisplaySize.x = s_cast<float>(SharedApplication.getWidth());
	io.DisplaySize.y = s_cast<float>(SharedApplication.getHeight());
	io.DeltaTime = s_cast<float>(SharedApplication.getDeltaTime());

	if (_textInputing != io.WantTextInput)
	{
		_textInputing = io.WantTextInput;
		Event::sendInternal(_textInputing ? "AppTextInputStart"_slice : "AppTextInputStop"_slice);
	}

	int mx, my;
	SDL_Window* window = SharedApplication.getSDLWindow();
	Uint32 mouseMask = SDL_GetMouseState(&mx, &my);
	int w, h;
	SDL_GetWindowSize(window, &w, &h);
	mx = s_cast<int>(io.DisplaySize.x * (s_cast<float>(mx) / w));
	my = s_cast<int>(io.DisplaySize.y * (s_cast<float>(my) / h));
	bool hasMousePos = (SDL_GetWindowFlags(window) & SDL_WINDOW_MOUSE_FOCUS) != 0;
	io.MousePos = hasMousePos ? ImVec2((float)mx, (float)my) : ImVec2(-1, -1);
	io.MouseDown[0] = _mousePressed[0] || (mouseMask & SDL_BUTTON(SDL_BUTTON_LEFT)) != 0;
	io.MouseDown[1] = _mousePressed[1] || (mouseMask & SDL_BUTTON(SDL_BUTTON_RIGHT)) != 0;
	io.MouseDown[2] = _mousePressed[2] || (mouseMask & SDL_BUTTON(SDL_BUTTON_MIDDLE)) != 0;
	_mousePressed[0] = _mousePressed[1] = _mousePressed[2] = false;

	io.MouseWheel = _mouseWheel;
	_mouseWheel = 0.0f;

	// Hide OS mouse cursor if ImGui is drawing it
	SDL_ShowCursor(io.MouseDrawCursor ? 0 : 1);

	// Start the frame
	ImGui::NewFrame();
}

void ImGUIDora::end()
{
	ImGui::Render();
}

inline bool checkAvailTransientBuffers(uint32_t _numVertices, const bgfx::VertexDecl& _decl, uint32_t _numIndices)
{
	return _numVertices == bgfx::getAvailTransientVertexBuffer(_numVertices, _decl)
		&& _numIndices == bgfx::getAvailTransientIndexBuffer(_numIndices);
}

void ImGUIDora::renderDrawLists(ImDrawData* _drawData)
{
	ImGUIDora* guiDora = SharedImGUI.getTarget();
	uint8_t viewId = guiDora->_viewId;
	bgfx::UniformHandle sampler = guiDora->_textureSampler;
	bgfx::TextureHandle textureHandle = guiDora->_fontTexture->getHandle();
	bgfx::ProgramHandle program = guiDora->_effect->getProgram();

	const ImGuiIO& io = ImGui::GetIO();
	const float width = io.DisplaySize.x;
	const float height = io.DisplaySize.y;

	bgfx::setViewRect(viewId, 0, 0, bgfx::BackbufferRatio::Equal);
	bgfx::touch(viewId);

	{
		float ortho[16];
		bx::mtxOrtho(ortho, 0.0f, width, height, 0.0f, -1.0f, 1.0f);
		bgfx::setViewTransform(viewId, nullptr, ortho);
	}

	// Render command lists
	for (int32_t ii = 0, num = _drawData->CmdListsCount; ii < num; ++ii)
	{
		bgfx::TransientVertexBuffer tvb;
		bgfx::TransientIndexBuffer tib;

		const ImDrawList* drawList = _drawData->CmdLists[ii];
		uint32_t numVertices = (uint32_t)drawList->VtxBuffer.size();
		uint32_t numIndices = (uint32_t)drawList->IdxBuffer.size();

		if (!checkAvailTransientBuffers(numVertices, guiDora->_vertexDecl, numIndices))
		{
			Log("not enough space in transient buffer just quit drawing the rest.");
			break;
		}

		bgfx::allocTransientVertexBuffer(&tvb, numVertices, guiDora->_vertexDecl);
		bgfx::allocTransientIndexBuffer(&tib, numIndices);

		ImDrawVert* verts = (ImDrawVert*)tvb.data;
		memcpy(verts, drawList->VtxBuffer.begin(), numVertices * sizeof(ImDrawVert));

		ImDrawIdx* indices = (ImDrawIdx*)tib.data;
		memcpy(indices, drawList->IdxBuffer.begin(), numIndices * sizeof(ImDrawIdx));

		uint32_t offset = 0;
		for (const ImDrawCmd* cmd = drawList->CmdBuffer.begin(), *cmdEnd = drawList->CmdBuffer.end(); cmd != cmdEnd; ++cmd)
		{
			if (cmd->UserCallback)
			{
				cmd->UserCallback(drawList, cmd);
			}
			else if (0 != cmd->ElemCount)
			{
				if (nullptr != cmd->TextureId)
				{
					union
					{
						ImTextureID ptr;
						struct
						{
							bgfx::TextureHandle handle;
							uint8_t flags;
							uint8_t mip;
						} s;
					} texture = { cmd->TextureId };
					textureHandle = texture.s.handle;
				}

				uint64_t state = 0
					| BGFX_STATE_RGB_WRITE
					| BGFX_STATE_ALPHA_WRITE
					| BGFX_STATE_MSAA
					| BGFX_STATE_BLEND_FUNC(BGFX_STATE_BLEND_SRC_ALPHA, BGFX_STATE_BLEND_INV_SRC_ALPHA);

				const uint16_t xx = uint16_t(bx::fmax(cmd->ClipRect.x, 0.0f));
				const uint16_t yy = uint16_t(bx::fmax(cmd->ClipRect.y, 0.0f));
				bgfx::setScissor(xx, yy,
					uint16_t(bx::fmin(cmd->ClipRect.z, 65535.0f) - xx),
					uint16_t(bx::fmin(cmd->ClipRect.w, 65535.0f) - yy));
				bgfx::setState(state);
				bgfx::setTexture(0, sampler, textureHandle);
				bgfx::setVertexBuffer(&tvb, 0, numVertices);
				bgfx::setIndexBuffer(&tib, offset, cmd->ElemCount);
				bgfx::submit(viewId, program);
			}

			offset += cmd->ElemCount;
		}
	}
}

void ImGUIDora::handleEvent(Event* e)
{
	if (!e->isInternal()) return;

	SDL_Event event;
	e->retrieve(event);

	switch (event.type)
	{
		case SDL_MOUSEWHEEL:
		{
			if (event.wheel.y > 0)
			{
				_mouseWheel = 1;
			}
			if (event.wheel.y < 0)
			{
				_mouseWheel = -1;
			}
			break;
		}
		case SDL_MOUSEBUTTONDOWN:
		{
			if (event.button.button == SDL_BUTTON_LEFT) _mousePressed[0] = true;
			if (event.button.button == SDL_BUTTON_RIGHT) _mousePressed[1] = true;
			if (event.button.button == SDL_BUTTON_MIDDLE) _mousePressed[2] = true;
			break;
		}
		case SDL_KEYDOWN:
		case SDL_KEYUP:
		{
			int key = event.key.keysym.sym & ~SDLK_SCANCODE_MASK;
			if (event.type == SDL_KEYDOWN && key == SDLK_BACKSPACE)
			{
				if (_editingDel == 0)
				{
					_inputs.push_back(event);
				}
			}
			else
			{
				_inputs.push_back(event);
			}
			break;
		}
		case SDL_TEXTINPUT:
		{
			const char* newText = event.text.text;
			if (strcmp(newText, _textEditing) != 0)
			{
				if (_textLength > 0)
				{
					for (int i = 0; i < _textLength; i++)
					{
						SDL_Event e;
						e.type = SDL_KEYDOWN;
						e.key.keysym.sym = SDLK_BACKSPACE;
						_inputs.push_back(e);
						e.type = SDL_KEYUP;
						_inputs.push_back(e);
					}
				}
				_inputs.push_back(event);
			}
			memset(_textEditing, 0, SDL_TEXTINPUTEVENT_TEXT_SIZE);
			_textLength = 0;
			_keydownDel = 0;
			_editingDel = 0;
			break;
		}
		case SDL_TEXTEDITING:
		{
			const char* newText = event.text.text;
			if (strcmp(newText, _textEditing) != 0)
			{
				size_t lastLength = strlen(_textEditing);
				size_t newLength = strlen(newText);
				const char* oldChar = _textEditing;
				const char* newChar = newText;
				while (*oldChar == *newChar && *oldChar != '\0' && *newChar != '\0')
				{
					oldChar++; newChar++;
				}
				size_t toDel = _textEditing + lastLength - oldChar;
				size_t toAdd = newText + newLength - newChar;
				if (toDel > 0)
				{
					int charCount = utf8_countCharacters(oldChar);
					_textLength -= charCount;
					_editingDel = charCount - _keydownDel;
					for (int i = 0; i < _editingDel; i++)
					{
						SDL_Event e;
						e.type = SDL_KEYDOWN;
						e.key.keysym.sym = SDLK_BACKSPACE;
						_inputs.push_back(e);
						e.type = SDL_KEYUP;
						_inputs.push_back(e);
					}
				}
				if (toAdd > 0)
				{
					SDL_Event e;
					_textLength += toAdd;
					if (toDel == 0) _editingDel = 0;
					e.type = SDL_TEXTINPUT;
					memcpy(e.text.text, newChar, toAdd + 1);
					_inputs.push_back(e);
				}
				memcpy(_textEditing, newText, SDL_TEXTINPUTEVENT_TEXT_SIZE);
			}
			break;
		}
	}
}

bool ImGUIDora::handle(const SDL_Event& event)
{
	return ImGui::IsAnyItemActive();
}

NS_DOROTHY_END