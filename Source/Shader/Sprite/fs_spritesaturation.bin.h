static const uint8_t fs_spritesaturation_glsl[439] =
{
	0x46, 0x53, 0x48, 0x06, 0x01, 0x83, 0xf2, 0xe1, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x0c, 0x75, // FSH............u
	0x5f, 0x61, 0x64, 0x6a, 0x75, 0x73, 0x74, 0x6d, 0x65, 0x6e, 0x74, 0x02, 0x01, 0x00, 0x00, 0x01, // _adjustment.....
	0x00, 0x0a, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x00, 0x01, 0x00, 0x00, // ..s_texColor....
	0x01, 0x00, 0x80, 0x01, 0x00, 0x00, 0x76, 0x61, 0x72, 0x79, 0x69, 0x6e, 0x67, 0x20, 0x76, 0x65, // ......varying ve
	0x63, 0x34, 0x20, 0x76, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x3b, 0x0a, 0x76, 0x61, 0x72, // c4 v_color0;.var
	0x79, 0x69, 0x6e, 0x67, 0x20, 0x76, 0x65, 0x63, 0x32, 0x20, 0x76, 0x5f, 0x74, 0x65, 0x78, 0x63, // ying vec2 v_texc
	0x6f, 0x6f, 0x72, 0x64, 0x30, 0x3b, 0x0a, 0x75, 0x6e, 0x69, 0x66, 0x6f, 0x72, 0x6d, 0x20, 0x76, // oord0;.uniform v
	0x65, 0x63, 0x34, 0x20, 0x75, 0x5f, 0x61, 0x64, 0x6a, 0x75, 0x73, 0x74, 0x6d, 0x65, 0x6e, 0x74, // ec4 u_adjustment
	0x3b, 0x0a, 0x75, 0x6e, 0x69, 0x66, 0x6f, 0x72, 0x6d, 0x20, 0x73, 0x61, 0x6d, 0x70, 0x6c, 0x65, // ;.uniform sample
	0x72, 0x32, 0x44, 0x20, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x3b, 0x0a, // r2D s_texColor;.
	0x76, 0x6f, 0x69, 0x64, 0x20, 0x6d, 0x61, 0x69, 0x6e, 0x20, 0x28, 0x29, 0x0a, 0x7b, 0x0a, 0x20, // void main ().{.
	0x20, 0x76, 0x65, 0x63, 0x34, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x31, 0x3b, 0x0a, //  vec4 tmpvar_1;.
	0x20, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x31, 0x20, 0x3d, 0x20, 0x28, 0x76, 0x5f, //   tmpvar_1 = (v_
	0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x20, 0x2a, 0x20, 0x74, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, // color0 * texture
	0x32, 0x44, 0x20, 0x28, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x2c, 0x20, // 2D (s_texColor,
	0x76, 0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, 0x29, 0x29, 0x3b, 0x0a, 0x20, // v_texcoord0));.
	0x20, 0x76, 0x65, 0x63, 0x34, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x32, 0x3b, 0x0a, //  vec4 tmpvar_2;.
	0x20, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x32, 0x2e, 0x78, 0x79, 0x7a, 0x20, 0x3d, //   tmpvar_2.xyz =
	0x20, 0x6d, 0x69, 0x78, 0x20, 0x28, 0x76, 0x65, 0x63, 0x33, 0x28, 0x64, 0x6f, 0x74, 0x20, 0x28, //  mix (vec3(dot (
	0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x31, 0x2e, 0x78, 0x79, 0x7a, 0x2c, 0x20, 0x76, 0x65, // tmpvar_1.xyz, ve
	0x63, 0x33, 0x28, 0x30, 0x2e, 0x32, 0x31, 0x32, 0x35, 0x2c, 0x20, 0x30, 0x2e, 0x37, 0x31, 0x35, // c3(0.2125, 0.715
	0x34, 0x2c, 0x20, 0x30, 0x2e, 0x30, 0x37, 0x32, 0x31, 0x29, 0x29, 0x29, 0x2c, 0x20, 0x74, 0x6d, // 4, 0.0721))), tm
	0x70, 0x76, 0x61, 0x72, 0x5f, 0x31, 0x2e, 0x78, 0x79, 0x7a, 0x2c, 0x20, 0x75, 0x5f, 0x61, 0x64, // pvar_1.xyz, u_ad
	0x6a, 0x75, 0x73, 0x74, 0x6d, 0x65, 0x6e, 0x74, 0x2e, 0x78, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x74, // justment.x);.  t
	0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x32, 0x2e, 0x77, 0x20, 0x3d, 0x20, 0x74, 0x6d, 0x70, 0x76, // mpvar_2.w = tmpv
	0x61, 0x72, 0x5f, 0x31, 0x2e, 0x77, 0x3b, 0x0a, 0x20, 0x20, 0x67, 0x6c, 0x5f, 0x46, 0x72, 0x61, // ar_1.w;.  gl_Fra
	0x67, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x20, 0x3d, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, // gColor = tmpvar_
	0x32, 0x3b, 0x0a, 0x7d, 0x0a, 0x0a, 0x00,                                                       // 2;.}...
};
static const uint8_t fs_spritesaturation_essl[467] =
{
	0x46, 0x53, 0x48, 0x06, 0x01, 0x83, 0xf2, 0xe1, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x0c, 0x75, // FSH............u
	0x5f, 0x61, 0x64, 0x6a, 0x75, 0x73, 0x74, 0x6d, 0x65, 0x6e, 0x74, 0x02, 0x01, 0x00, 0x00, 0x01, // _adjustment.....
	0x00, 0x0a, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x00, 0x01, 0x00, 0x00, // ..s_texColor....
	0x01, 0x00, 0x9c, 0x01, 0x00, 0x00, 0x76, 0x61, 0x72, 0x79, 0x69, 0x6e, 0x67, 0x20, 0x68, 0x69, // ......varying hi
	0x67, 0x68, 0x70, 0x20, 0x76, 0x65, 0x63, 0x34, 0x20, 0x76, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, 0x72, // ghp vec4 v_color
	0x30, 0x3b, 0x0a, 0x76, 0x61, 0x72, 0x79, 0x69, 0x6e, 0x67, 0x20, 0x68, 0x69, 0x67, 0x68, 0x70, // 0;.varying highp
	0x20, 0x76, 0x65, 0x63, 0x32, 0x20, 0x76, 0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, //  vec2 v_texcoord
	0x30, 0x3b, 0x0a, 0x75, 0x6e, 0x69, 0x66, 0x6f, 0x72, 0x6d, 0x20, 0x68, 0x69, 0x67, 0x68, 0x70, // 0;.uniform highp
	0x20, 0x76, 0x65, 0x63, 0x34, 0x20, 0x75, 0x5f, 0x61, 0x64, 0x6a, 0x75, 0x73, 0x74, 0x6d, 0x65, //  vec4 u_adjustme
	0x6e, 0x74, 0x3b, 0x0a, 0x75, 0x6e, 0x69, 0x66, 0x6f, 0x72, 0x6d, 0x20, 0x73, 0x61, 0x6d, 0x70, // nt;.uniform samp
	0x6c, 0x65, 0x72, 0x32, 0x44, 0x20, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, // ler2D s_texColor
	0x3b, 0x0a, 0x76, 0x6f, 0x69, 0x64, 0x20, 0x6d, 0x61, 0x69, 0x6e, 0x20, 0x28, 0x29, 0x0a, 0x7b, // ;.void main ().{
	0x0a, 0x20, 0x20, 0x6c, 0x6f, 0x77, 0x70, 0x20, 0x76, 0x65, 0x63, 0x34, 0x20, 0x74, 0x6d, 0x70, // .  lowp vec4 tmp
	0x76, 0x61, 0x72, 0x5f, 0x31, 0x3b, 0x0a, 0x20, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, // var_1;.  tmpvar_
	0x31, 0x20, 0x3d, 0x20, 0x28, 0x76, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x20, 0x2a, 0x20, // 1 = (v_color0 *
	0x74, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x32, 0x44, 0x20, 0x28, 0x73, 0x5f, 0x74, 0x65, 0x78, // texture2D (s_tex
	0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x2c, 0x20, 0x76, 0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, // Color, v_texcoor
	0x64, 0x30, 0x29, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x6c, 0x6f, 0x77, 0x70, 0x20, 0x76, 0x65, 0x63, // d0));.  lowp vec
	0x34, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x32, 0x3b, 0x0a, 0x20, 0x20, 0x74, 0x6d, // 4 tmpvar_2;.  tm
	0x70, 0x76, 0x61, 0x72, 0x5f, 0x32, 0x2e, 0x78, 0x79, 0x7a, 0x20, 0x3d, 0x20, 0x6d, 0x69, 0x78, // pvar_2.xyz = mix
	0x20, 0x28, 0x76, 0x65, 0x63, 0x33, 0x28, 0x64, 0x6f, 0x74, 0x20, 0x28, 0x74, 0x6d, 0x70, 0x76, //  (vec3(dot (tmpv
	0x61, 0x72, 0x5f, 0x31, 0x2e, 0x78, 0x79, 0x7a, 0x2c, 0x20, 0x76, 0x65, 0x63, 0x33, 0x28, 0x30, // ar_1.xyz, vec3(0
	0x2e, 0x32, 0x31, 0x32, 0x35, 0x2c, 0x20, 0x30, 0x2e, 0x37, 0x31, 0x35, 0x34, 0x2c, 0x20, 0x30, // .2125, 0.7154, 0
	0x2e, 0x30, 0x37, 0x32, 0x31, 0x29, 0x29, 0x29, 0x2c, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, // .0721))), tmpvar
	0x5f, 0x31, 0x2e, 0x78, 0x79, 0x7a, 0x2c, 0x20, 0x75, 0x5f, 0x61, 0x64, 0x6a, 0x75, 0x73, 0x74, // _1.xyz, u_adjust
	0x6d, 0x65, 0x6e, 0x74, 0x2e, 0x78, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, // ment.x);.  tmpva
	0x72, 0x5f, 0x32, 0x2e, 0x77, 0x20, 0x3d, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x31, // r_2.w = tmpvar_1
	0x2e, 0x77, 0x3b, 0x0a, 0x20, 0x20, 0x67, 0x6c, 0x5f, 0x46, 0x72, 0x61, 0x67, 0x43, 0x6f, 0x6c, // .w;.  gl_FragCol
	0x6f, 0x72, 0x20, 0x3d, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x32, 0x3b, 0x0a, 0x7d, // or = tmpvar_2;.}
	0x0a, 0x0a, 0x00,                                                                               // ...
};
static const uint8_t fs_spritesaturation_spv[1701] =
{
	0x46, 0x53, 0x48, 0x06, 0x01, 0x83, 0xf2, 0xe1, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x0c, 0x75, // FSH............u
	0x5f, 0x61, 0x64, 0x6a, 0x75, 0x73, 0x74, 0x6d, 0x65, 0x6e, 0x74, 0x12, 0x01, 0x00, 0x00, 0x01, // _adjustment.....
	0x00, 0x7c, 0x06, 0x00, 0x00, 0x03, 0x02, 0x23, 0x07, 0x00, 0x00, 0x01, 0x00, 0x07, 0x00, 0x08, // .|.....#........
	0x00, 0xd4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 0x02, 0x00, 0x01, 0x00, 0x00, // ................
	0x00, 0x0b, 0x00, 0x06, 0x00, 0x01, 0x00, 0x00, 0x00, 0x47, 0x4c, 0x53, 0x4c, 0x2e, 0x73, 0x74, // .........GLSL.st
	0x64, 0x2e, 0x34, 0x35, 0x30, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, // d.450...........
	0x00, 0x01, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x08, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, // ................
	0x00, 0x6d, 0x61, 0x69, 0x6e, 0x00, 0x00, 0x00, 0x00, 0x7a, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x00, // .main....z...~..
	0x00, 0x89, 0x00, 0x00, 0x00, 0x10, 0x00, 0x03, 0x00, 0x04, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, // ................
	0x00, 0x03, 0x00, 0x03, 0x00, 0x05, 0x00, 0x00, 0x00, 0xf4, 0x01, 0x00, 0x00, 0x05, 0x00, 0x04, // ................
	0x00, 0x04, 0x00, 0x00, 0x00, 0x6d, 0x61, 0x69, 0x6e, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x06, // .....main.......
	0x00, 0x09, 0x00, 0x00, 0x00, 0x42, 0x67, 0x66, 0x78, 0x53, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x72, // .....BgfxSampler
	0x32, 0x44, 0x00, 0x00, 0x00, 0x06, 0x00, 0x06, 0x00, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 2D..............
	0x00, 0x6d, 0x5f, 0x73, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x72, 0x00, 0x00, 0x00, 0x06, 0x00, 0x06, // .m_sampler......
	0x00, 0x09, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x6d, 0x5f, 0x74, 0x65, 0x78, 0x74, 0x75, // .........m_textu
	0x72, 0x65, 0x00, 0x00, 0x00, 0x05, 0x00, 0x05, 0x00, 0x28, 0x00, 0x00, 0x00, 0x73, 0x5f, 0x74, // re.......(...s_t
	0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x00, 0x00, 0x05, 0x00, 0x07, 0x00, 0x2a, 0x00, 0x00, // exColor......*..
	0x00, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x53, 0x61, 0x6d, 0x70, 0x6c, // .s_texColorSampl
	0x65, 0x72, 0x00, 0x00, 0x00, 0x05, 0x00, 0x07, 0x00, 0x2d, 0x00, 0x00, 0x00, 0x73, 0x5f, 0x74, // er.......-...s_t
	0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x54, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x00, 0x00, // exColorTexture..
	0x00, 0x05, 0x00, 0x04, 0x00, 0x61, 0x00, 0x00, 0x00, 0x24, 0x47, 0x6c, 0x6f, 0x62, 0x61, 0x6c, // .....a...$Global
	0x00, 0x06, 0x00, 0x07, 0x00, 0x61, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x75, 0x5f, 0x61, // .....a.......u_a
	0x64, 0x6a, 0x75, 0x73, 0x74, 0x6d, 0x65, 0x6e, 0x74, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x03, // djustment.......
	0x00, 0x63, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x05, 0x00, 0x7a, 0x00, 0x00, // .c...........z..
	0x00, 0x76, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x05, // .v_color0.......
	0x00, 0x7e, 0x00, 0x00, 0x00, 0x76, 0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, // .~...v_texcoord0
	0x00, 0x05, 0x00, 0x06, 0x00, 0x89, 0x00, 0x00, 0x00, 0x62, 0x67, 0x66, 0x78, 0x5f, 0x46, 0x72, // .........bgfx_Fr
	0x61, 0x67, 0x44, 0x61, 0x74, 0x61, 0x30, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00, 0x2d, 0x00, 0x00, // agData0..G...-..
	0x00, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00, 0x2d, 0x00, 0x00, // .".......G...-..
	0x00, 0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x00, 0x05, 0x00, 0x61, 0x00, 0x00, // .!.......H...a..
	0x00, 0x00, 0x00, 0x00, 0x00, 0x23, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x47, 0x00, 0x03, // .....#.......G..
	0x00, 0x61, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00, 0x63, 0x00, 0x00, // .a.......G...c..
	0x00, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00, 0x63, 0x00, 0x00, // .".......G...c..
	0x00, 0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00, 0x7a, 0x00, 0x00, // .!.......G...z..
	0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00, 0x7e, 0x00, 0x00, // .........G...~..
	0x00, 0x1e, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x47, 0x00, 0x04, 0x00, 0x89, 0x00, 0x00, // .........G......
	0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x13, 0x00, 0x02, 0x00, 0x02, 0x00, 0x00, // ................
	0x00, 0x21, 0x00, 0x03, 0x00, 0x03, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x1a, 0x00, 0x02, // .!..............
	0x00, 0x06, 0x00, 0x00, 0x00, 0x16, 0x00, 0x03, 0x00, 0x07, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, // ............. ..
	0x00, 0x19, 0x00, 0x09, 0x00, 0x08, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, // ................
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, // ................
	0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x04, 0x00, 0x09, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, // ................
	0x00, 0x08, 0x00, 0x00, 0x00, 0x17, 0x00, 0x04, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, // ................
	0x00, 0x02, 0x00, 0x00, 0x00, 0x17, 0x00, 0x04, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, // ................
	0x00, 0x04, 0x00, 0x00, 0x00, 0x17, 0x00, 0x04, 0x00, 0x13, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, // ................
	0x00, 0x03, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x27, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, // ..... ...'......
	0x00, 0x09, 0x00, 0x00, 0x00, 0x3b, 0x00, 0x04, 0x00, 0x27, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, // .....;...'...(..
	0x00, 0x06, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x29, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, // ..... ...)......
	0x00, 0x06, 0x00, 0x00, 0x00, 0x3b, 0x00, 0x04, 0x00, 0x29, 0x00, 0x00, 0x00, 0x2a, 0x00, 0x00, // .....;...)...*..
	0x00, 0x06, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x2c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ..... ...,......
	0x00, 0x08, 0x00, 0x00, 0x00, 0x3b, 0x00, 0x04, 0x00, 0x2c, 0x00, 0x00, 0x00, 0x2d, 0x00, 0x00, // .....;...,...-..
	0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0x00, 0x04, 0x00, 0x30, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, // .........0... ..
	0x00, 0x01, 0x00, 0x00, 0x00, 0x2b, 0x00, 0x04, 0x00, 0x30, 0x00, 0x00, 0x00, 0x35, 0x00, 0x00, // .....+...0...5..
	0x00, 0x00, 0x00, 0x00, 0x00, 0x1b, 0x00, 0x03, 0x00, 0x39, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, // .........9......
	0x00, 0x2b, 0x00, 0x04, 0x00, 0x07, 0x00, 0x00, 0x00, 0x5b, 0x00, 0x00, 0x00, 0x9a, 0x99, 0x59, // .+.......[.....Y
	0x3e, 0x2b, 0x00, 0x04, 0x00, 0x07, 0x00, 0x00, 0x00, 0x5c, 0x00, 0x00, 0x00, 0x74, 0x24, 0x37, // >+...........t$7
	0x3f, 0x2b, 0x00, 0x04, 0x00, 0x07, 0x00, 0x00, 0x00, 0x5d, 0x00, 0x00, 0x00, 0x2a, 0xa9, 0x93, // ?+.......]...*..
	0x3d, 0x2c, 0x00, 0x06, 0x00, 0x13, 0x00, 0x00, 0x00, 0x5e, 0x00, 0x00, 0x00, 0x5b, 0x00, 0x00, // =,.......^...[..
	0x00, 0x5c, 0x00, 0x00, 0x00, 0x5d, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x03, 0x00, 0x61, 0x00, 0x00, // .....].......a..
	0x00, 0x0d, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x62, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, // ..... ...b......
	0x00, 0x61, 0x00, 0x00, 0x00, 0x3b, 0x00, 0x04, 0x00, 0x62, 0x00, 0x00, 0x00, 0x63, 0x00, 0x00, // .a...;...b...c..
	0x00, 0x02, 0x00, 0x00, 0x00, 0x15, 0x00, 0x04, 0x00, 0x64, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, // .........d... ..
	0x00, 0x00, 0x00, 0x00, 0x00, 0x2b, 0x00, 0x04, 0x00, 0x64, 0x00, 0x00, 0x00, 0x65, 0x00, 0x00, // .....+...d...e..
	0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x66, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, // ..... ...f......
	0x00, 0x07, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x79, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, // ..... ...y......
	0x00, 0x0d, 0x00, 0x00, 0x00, 0x3b, 0x00, 0x04, 0x00, 0x79, 0x00, 0x00, 0x00, 0x7a, 0x00, 0x00, // .....;...y...z..
	0x00, 0x01, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x7d, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, // ..... ...}......
	0x00, 0x0b, 0x00, 0x00, 0x00, 0x3b, 0x00, 0x04, 0x00, 0x7d, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x00, // .....;...}...~..
	0x00, 0x01, 0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x88, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, // ..... ..........
	0x00, 0x0d, 0x00, 0x00, 0x00, 0x3b, 0x00, 0x04, 0x00, 0x88, 0x00, 0x00, 0x00, 0x89, 0x00, 0x00, // .....;..........
	0x00, 0x03, 0x00, 0x00, 0x00, 0x36, 0x00, 0x05, 0x00, 0x02, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, // .....6..........
	0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x02, 0x00, 0x05, 0x00, 0x00, // ................
	0x00, 0x3d, 0x00, 0x04, 0x00, 0x06, 0x00, 0x00, 0x00, 0x2b, 0x00, 0x00, 0x00, 0x2a, 0x00, 0x00, // .=.......+...*..
	0x00, 0x3d, 0x00, 0x04, 0x00, 0x08, 0x00, 0x00, 0x00, 0x2e, 0x00, 0x00, 0x00, 0x2d, 0x00, 0x00, // .=...........-..
	0x00, 0x50, 0x00, 0x05, 0x00, 0x09, 0x00, 0x00, 0x00, 0x2f, 0x00, 0x00, 0x00, 0x2b, 0x00, 0x00, // .P......./...+..
	0x00, 0x2e, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x03, 0x00, 0x28, 0x00, 0x00, 0x00, 0x2f, 0x00, 0x00, // .....>...(.../..
	0x00, 0x3d, 0x00, 0x04, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x7b, 0x00, 0x00, 0x00, 0x7a, 0x00, 0x00, // .=.......{...z..
	0x00, 0x3d, 0x00, 0x04, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x7f, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x00, // .=...........~..
	0x00, 0x3d, 0x00, 0x04, 0x00, 0x09, 0x00, 0x00, 0x00, 0xa8, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, // .=...........(..
	0x00, 0x51, 0x00, 0x05, 0x00, 0x06, 0x00, 0x00, 0x00, 0xd2, 0x00, 0x00, 0x00, 0xa8, 0x00, 0x00, // .Q..............
	0x00, 0x00, 0x00, 0x00, 0x00, 0x51, 0x00, 0x05, 0x00, 0x08, 0x00, 0x00, 0x00, 0xd3, 0x00, 0x00, // .....Q..........
	0x00, 0xa8, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x56, 0x00, 0x05, 0x00, 0x39, 0x00, 0x00, // .........V...9..
	0x00, 0xc8, 0x00, 0x00, 0x00, 0xd3, 0x00, 0x00, 0x00, 0xd2, 0x00, 0x00, 0x00, 0x57, 0x00, 0x05, // .............W..
	0x00, 0x0d, 0x00, 0x00, 0x00, 0xca, 0x00, 0x00, 0x00, 0xc8, 0x00, 0x00, 0x00, 0x7f, 0x00, 0x00, // ................
	0x00, 0x85, 0x00, 0x05, 0x00, 0x0d, 0x00, 0x00, 0x00, 0xab, 0x00, 0x00, 0x00, 0x7b, 0x00, 0x00, // .............{..
	0x00, 0xca, 0x00, 0x00, 0x00, 0x4f, 0x00, 0x08, 0x00, 0x13, 0x00, 0x00, 0x00, 0xad, 0x00, 0x00, // .....O..........
	0x00, 0xab, 0x00, 0x00, 0x00, 0xab, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, // ................
	0x00, 0x02, 0x00, 0x00, 0x00, 0x94, 0x00, 0x05, 0x00, 0x07, 0x00, 0x00, 0x00, 0xae, 0x00, 0x00, // ................
	0x00, 0xad, 0x00, 0x00, 0x00, 0x5e, 0x00, 0x00, 0x00, 0x50, 0x00, 0x06, 0x00, 0x13, 0x00, 0x00, // .....^...P......
	0x00, 0xaf, 0x00, 0x00, 0x00, 0xae, 0x00, 0x00, 0x00, 0xae, 0x00, 0x00, 0x00, 0xae, 0x00, 0x00, // ................
	0x00, 0x41, 0x00, 0x06, 0x00, 0x66, 0x00, 0x00, 0x00, 0xb0, 0x00, 0x00, 0x00, 0x63, 0x00, 0x00, // .A...f.......c..
	0x00, 0x35, 0x00, 0x00, 0x00, 0x65, 0x00, 0x00, 0x00, 0x3d, 0x00, 0x04, 0x00, 0x07, 0x00, 0x00, // .5...e...=......
	0x00, 0xb1, 0x00, 0x00, 0x00, 0xb0, 0x00, 0x00, 0x00, 0x50, 0x00, 0x06, 0x00, 0x13, 0x00, 0x00, // .........P......
	0x00, 0xb2, 0x00, 0x00, 0x00, 0xb1, 0x00, 0x00, 0x00, 0xb1, 0x00, 0x00, 0x00, 0xb1, 0x00, 0x00, // ................
	0x00, 0x4f, 0x00, 0x08, 0x00, 0x13, 0x00, 0x00, 0x00, 0xb5, 0x00, 0x00, 0x00, 0xab, 0x00, 0x00, // .O..............
	0x00, 0xab, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, // ................
	0x00, 0x0c, 0x00, 0x08, 0x00, 0x13, 0x00, 0x00, 0x00, 0xcf, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, // ................
	0x00, 0x2e, 0x00, 0x00, 0x00, 0xaf, 0x00, 0x00, 0x00, 0xb5, 0x00, 0x00, 0x00, 0xb2, 0x00, 0x00, // ................
	0x00, 0x51, 0x00, 0x05, 0x00, 0x07, 0x00, 0x00, 0x00, 0xb8, 0x00, 0x00, 0x00, 0xab, 0x00, 0x00, // .Q..............
	0x00, 0x03, 0x00, 0x00, 0x00, 0x51, 0x00, 0x05, 0x00, 0x07, 0x00, 0x00, 0x00, 0xb9, 0x00, 0x00, // .....Q..........
	0x00, 0xcf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x51, 0x00, 0x05, 0x00, 0x07, 0x00, 0x00, // .........Q......
	0x00, 0xba, 0x00, 0x00, 0x00, 0xcf, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x51, 0x00, 0x05, // .............Q..
	0x00, 0x07, 0x00, 0x00, 0x00, 0xbb, 0x00, 0x00, 0x00, 0xcf, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, // ................
	0x00, 0x50, 0x00, 0x07, 0x00, 0x0d, 0x00, 0x00, 0x00, 0xbc, 0x00, 0x00, 0x00, 0xb9, 0x00, 0x00, // .P..............
	0x00, 0xba, 0x00, 0x00, 0x00, 0xbb, 0x00, 0x00, 0x00, 0xb8, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x03, // .............>..
	0x00, 0x89, 0x00, 0x00, 0x00, 0xbc, 0x00, 0x00, 0x00, 0xfd, 0x00, 0x01, 0x00, 0x38, 0x00, 0x01, // .............8..
	0x00, 0x00, 0x00, 0x10, 0x00,                                                                   // .....
};
static const uint8_t fs_spritesaturation_mtl[869] =
{
	0x46, 0x53, 0x48, 0x06, 0x01, 0x83, 0xf2, 0xe1, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x0c, 0x75, // FSH............u
	0x5f, 0x61, 0x64, 0x6a, 0x75, 0x73, 0x74, 0x6d, 0x65, 0x6e, 0x74, 0x02, 0x01, 0x00, 0x00, 0x01, // _adjustment.....
	0x00, 0x0a, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x00, 0x01, 0x00, 0x00, // ..s_texColor....
	0x01, 0x00, 0x2e, 0x03, 0x00, 0x00, 0x75, 0x73, 0x69, 0x6e, 0x67, 0x20, 0x6e, 0x61, 0x6d, 0x65, // ......using name
	0x73, 0x70, 0x61, 0x63, 0x65, 0x20, 0x6d, 0x65, 0x74, 0x61, 0x6c, 0x3b, 0x0a, 0x73, 0x74, 0x72, // space metal;.str
	0x75, 0x63, 0x74, 0x20, 0x78, 0x6c, 0x61, 0x74, 0x4d, 0x74, 0x6c, 0x53, 0x68, 0x61, 0x64, 0x65, // uct xlatMtlShade
	0x72, 0x49, 0x6e, 0x70, 0x75, 0x74, 0x20, 0x7b, 0x0a, 0x20, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, // rInput {.  float
	0x34, 0x20, 0x76, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x3b, 0x0a, 0x20, 0x20, 0x66, 0x6c, // 4 v_color0;.  fl
	0x6f, 0x61, 0x74, 0x32, 0x20, 0x76, 0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, // oat2 v_texcoord0
	0x3b, 0x0a, 0x7d, 0x3b, 0x0a, 0x73, 0x74, 0x72, 0x75, 0x63, 0x74, 0x20, 0x78, 0x6c, 0x61, 0x74, // ;.};.struct xlat
	0x4d, 0x74, 0x6c, 0x53, 0x68, 0x61, 0x64, 0x65, 0x72, 0x4f, 0x75, 0x74, 0x70, 0x75, 0x74, 0x20, // MtlShaderOutput
	0x7b, 0x0a, 0x20, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x34, 0x20, 0x67, 0x6c, 0x5f, 0x46, 0x72, // {.  float4 gl_Fr
	0x61, 0x67, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x3b, 0x0a, 0x7d, 0x3b, 0x0a, 0x73, 0x74, 0x72, 0x75, // agColor;.};.stru
	0x63, 0x74, 0x20, 0x78, 0x6c, 0x61, 0x74, 0x4d, 0x74, 0x6c, 0x53, 0x68, 0x61, 0x64, 0x65, 0x72, // ct xlatMtlShader
	0x55, 0x6e, 0x69, 0x66, 0x6f, 0x72, 0x6d, 0x20, 0x7b, 0x0a, 0x20, 0x20, 0x66, 0x6c, 0x6f, 0x61, // Uniform {.  floa
	0x74, 0x34, 0x20, 0x75, 0x5f, 0x61, 0x64, 0x6a, 0x75, 0x73, 0x74, 0x6d, 0x65, 0x6e, 0x74, 0x3b, // t4 u_adjustment;
	0x0a, 0x7d, 0x3b, 0x0a, 0x66, 0x72, 0x61, 0x67, 0x6d, 0x65, 0x6e, 0x74, 0x20, 0x78, 0x6c, 0x61, // .};.fragment xla
	0x74, 0x4d, 0x74, 0x6c, 0x53, 0x68, 0x61, 0x64, 0x65, 0x72, 0x4f, 0x75, 0x74, 0x70, 0x75, 0x74, // tMtlShaderOutput
	0x20, 0x78, 0x6c, 0x61, 0x74, 0x4d, 0x74, 0x6c, 0x4d, 0x61, 0x69, 0x6e, 0x20, 0x28, 0x78, 0x6c, //  xlatMtlMain (xl
	0x61, 0x74, 0x4d, 0x74, 0x6c, 0x53, 0x68, 0x61, 0x64, 0x65, 0x72, 0x49, 0x6e, 0x70, 0x75, 0x74, // atMtlShaderInput
	0x20, 0x5f, 0x6d, 0x74, 0x6c, 0x5f, 0x69, 0x20, 0x5b, 0x5b, 0x73, 0x74, 0x61, 0x67, 0x65, 0x5f, //  _mtl_i [[stage_
	0x69, 0x6e, 0x5d, 0x5d, 0x2c, 0x20, 0x63, 0x6f, 0x6e, 0x73, 0x74, 0x61, 0x6e, 0x74, 0x20, 0x78, // in]], constant x
	0x6c, 0x61, 0x74, 0x4d, 0x74, 0x6c, 0x53, 0x68, 0x61, 0x64, 0x65, 0x72, 0x55, 0x6e, 0x69, 0x66, // latMtlShaderUnif
	0x6f, 0x72, 0x6d, 0x26, 0x20, 0x5f, 0x6d, 0x74, 0x6c, 0x5f, 0x75, 0x20, 0x5b, 0x5b, 0x62, 0x75, // orm& _mtl_u [[bu
	0x66, 0x66, 0x65, 0x72, 0x28, 0x30, 0x29, 0x5d, 0x5d, 0x0a, 0x20, 0x20, 0x2c, 0x20, 0x20, 0x20, // ffer(0)]].  ,
	0x74, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x32, 0x64, 0x3c, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x3e, // texture2d<float>
	0x20, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x20, 0x5b, 0x5b, 0x74, 0x65, //  s_texColor [[te
	0x78, 0x74, 0x75, 0x72, 0x65, 0x28, 0x30, 0x29, 0x5d, 0x5d, 0x2c, 0x20, 0x73, 0x61, 0x6d, 0x70, // xture(0)]], samp
	0x6c, 0x65, 0x72, 0x20, 0x5f, 0x6d, 0x74, 0x6c, 0x73, 0x6d, 0x70, 0x5f, 0x73, 0x5f, 0x74, 0x65, // ler _mtlsmp_s_te
	0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x20, 0x5b, 0x5b, 0x73, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x72, // xColor [[sampler
	0x28, 0x30, 0x29, 0x5d, 0x5d, 0x29, 0x0a, 0x7b, 0x0a, 0x20, 0x20, 0x78, 0x6c, 0x61, 0x74, 0x4d, // (0)]]).{.  xlatM
	0x74, 0x6c, 0x53, 0x68, 0x61, 0x64, 0x65, 0x72, 0x4f, 0x75, 0x74, 0x70, 0x75, 0x74, 0x20, 0x5f, // tlShaderOutput _
	0x6d, 0x74, 0x6c, 0x5f, 0x6f, 0x3b, 0x0a, 0x20, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x34, 0x20, // mtl_o;.  float4
	0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x31, 0x20, 0x3d, 0x20, 0x30, 0x3b, 0x0a, 0x20, 0x20, // tmpvar_1 = 0;.
	0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x31, 0x20, 0x3d, 0x20, 0x28, 0x5f, 0x6d, 0x74, 0x6c, // tmpvar_1 = (_mtl
	0x5f, 0x69, 0x2e, 0x76, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x20, 0x2a, 0x20, 0x73, 0x5f, // _i.v_color0 * s_
	0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x2e, 0x73, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x28, // texColor.sample(
	0x5f, 0x6d, 0x74, 0x6c, 0x73, 0x6d, 0x70, 0x5f, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, // _mtlsmp_s_texCol
	0x6f, 0x72, 0x2c, 0x20, 0x28, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x32, 0x29, 0x28, 0x5f, 0x6d, 0x74, // or, (float2)(_mt
	0x6c, 0x5f, 0x69, 0x2e, 0x76, 0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, 0x29, // l_i.v_texcoord0)
	0x29, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x34, 0x20, 0x74, 0x6d, 0x70, // ));.  float4 tmp
	0x76, 0x61, 0x72, 0x5f, 0x32, 0x20, 0x3d, 0x20, 0x30, 0x3b, 0x0a, 0x20, 0x20, 0x74, 0x6d, 0x70, // var_2 = 0;.  tmp
	0x76, 0x61, 0x72, 0x5f, 0x32, 0x2e, 0x78, 0x79, 0x7a, 0x20, 0x3d, 0x20, 0x6d, 0x69, 0x78, 0x20, // var_2.xyz = mix
	0x28, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x33, 0x28, 0x64, 0x6f, 0x74, 0x20, 0x28, 0x74, 0x6d, 0x70, // (float3(dot (tmp
	0x76, 0x61, 0x72, 0x5f, 0x31, 0x2e, 0x78, 0x79, 0x7a, 0x2c, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, // var_1.xyz, float
	0x33, 0x28, 0x30, 0x2e, 0x32, 0x31, 0x32, 0x35, 0x2c, 0x20, 0x30, 0x2e, 0x37, 0x31, 0x35, 0x34, // 3(0.2125, 0.7154
	0x2c, 0x20, 0x30, 0x2e, 0x30, 0x37, 0x32, 0x31, 0x29, 0x29, 0x29, 0x2c, 0x20, 0x74, 0x6d, 0x70, // , 0.0721))), tmp
	0x76, 0x61, 0x72, 0x5f, 0x31, 0x2e, 0x78, 0x79, 0x7a, 0x2c, 0x20, 0x5f, 0x6d, 0x74, 0x6c, 0x5f, // var_1.xyz, _mtl_
	0x75, 0x2e, 0x75, 0x5f, 0x61, 0x64, 0x6a, 0x75, 0x73, 0x74, 0x6d, 0x65, 0x6e, 0x74, 0x2e, 0x78, // u.u_adjustment.x
	0x29, 0x3b, 0x0a, 0x20, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x32, 0x2e, 0x77, 0x20, // );.  tmpvar_2.w
	0x3d, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x31, 0x2e, 0x77, 0x3b, 0x0a, 0x20, 0x20, // = tmpvar_1.w;.
	0x5f, 0x6d, 0x74, 0x6c, 0x5f, 0x6f, 0x2e, 0x67, 0x6c, 0x5f, 0x46, 0x72, 0x61, 0x67, 0x43, 0x6f, // _mtl_o.gl_FragCo
	0x6c, 0x6f, 0x72, 0x20, 0x3d, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x32, 0x3b, 0x0a, // lor = tmpvar_2;.
	0x20, 0x20, 0x72, 0x65, 0x74, 0x75, 0x72, 0x6e, 0x20, 0x5f, 0x6d, 0x74, 0x6c, 0x5f, 0x6f, 0x3b, //   return _mtl_o;
	0x0a, 0x7d, 0x0a, 0x0a, 0x00,                                                                   // .}...
};
static const uint8_t fs_spritesaturation_dx9[487] =
{
	0x46, 0x53, 0x48, 0x06, 0x01, 0x83, 0xf2, 0xe1, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x0a, 0x73, // FSH............s
	0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x01, 0x00, 0x00, 0x01, 0x00, 0x0c, // _texColor0......
	0x75, 0x5f, 0x61, 0x64, 0x6a, 0x75, 0x73, 0x74, 0x6d, 0x65, 0x6e, 0x74, 0x12, 0x01, 0x00, 0x00, // u_adjustment....
	0x01, 0x00, 0xb0, 0x01, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xfe, 0xff, 0x2d, 0x00, 0x43, 0x54, // ............-.CT
	0x41, 0x42, 0x1c, 0x00, 0x00, 0x00, 0x87, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0x02, 0x00, // AB..............
	0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x04, 0x11, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x44, 0x00, // ..............D.
	0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, // ..........P.....
	0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x70, 0x00, // ..`...........p.
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, // ......s_texColor
	0x00, 0xab, 0x04, 0x00, 0x0c, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, // ................
	0x00, 0x00, 0x75, 0x5f, 0x61, 0x64, 0x6a, 0x75, 0x73, 0x74, 0x6d, 0x65, 0x6e, 0x74, 0x00, 0xab, // ..u_adjustment..
	0xab, 0xab, 0x01, 0x00, 0x03, 0x00, 0x01, 0x00, 0x04, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, // ................
	0x00, 0x00, 0x70, 0x73, 0x5f, 0x33, 0x5f, 0x30, 0x00, 0x4d, 0x69, 0x63, 0x72, 0x6f, 0x73, 0x6f, // ..ps_3_0.Microso
	0x66, 0x74, 0x20, 0x28, 0x52, 0x29, 0x20, 0x48, 0x4c, 0x53, 0x4c, 0x20, 0x53, 0x68, 0x61, 0x64, // ft (R) HLSL Shad
	0x65, 0x72, 0x20, 0x43, 0x6f, 0x6d, 0x70, 0x69, 0x6c, 0x65, 0x72, 0x20, 0x31, 0x30, 0x2e, 0x31, // er Compiler 10.1
	0x00, 0xab, 0x51, 0x00, 0x00, 0x05, 0x01, 0x00, 0x0f, 0xa0, 0x9a, 0x99, 0x59, 0x3e, 0x74, 0x24, // ..Q.........Y>t$
	0x37, 0x3f, 0x2a, 0xa9, 0x93, 0x3d, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x02, 0x0a, 0x00, // 7?*..=..........
	0x00, 0x80, 0x00, 0x00, 0x0f, 0x90, 0x1f, 0x00, 0x00, 0x02, 0x05, 0x00, 0x00, 0x80, 0x01, 0x00, // ................
	0x03, 0x90, 0x1f, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x90, 0x00, 0x08, 0x0f, 0xa0, 0x42, 0x00, // ..............B.
	0x00, 0x03, 0x00, 0x00, 0x0f, 0x80, 0x01, 0x00, 0xe4, 0x90, 0x00, 0x08, 0xe4, 0xa0, 0x05, 0x00, // ................
	0x00, 0x03, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x00, 0xe4, 0x80, 0x00, 0x00, 0xe4, 0x90, 0x08, 0x00, // ................
	0x00, 0x03, 0x01, 0x00, 0x07, 0x80, 0x00, 0x00, 0xe4, 0x80, 0x01, 0x00, 0xe4, 0xa0, 0x01, 0x00, // ................
	0x00, 0x02, 0x01, 0x00, 0x07, 0x80, 0x01, 0x00, 0xe4, 0x80, 0x01, 0x00, 0x00, 0x02, 0x01, 0x00, // ................
	0x07, 0x80, 0x01, 0x00, 0xe4, 0x80, 0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x07, 0x80, 0x00, 0x00, // ................
	0xe4, 0x80, 0x01, 0x00, 0x00, 0x02, 0x02, 0x00, 0x07, 0x80, 0x00, 0x00, 0x00, 0xa0, 0x01, 0x00, // ................
	0x00, 0x02, 0x03, 0x00, 0x07, 0x80, 0x01, 0x00, 0xe4, 0x81, 0x02, 0x00, 0x00, 0x03, 0x00, 0x00, // ................
	0x07, 0x80, 0x00, 0x00, 0xe4, 0x80, 0x03, 0x00, 0xe4, 0x80, 0x05, 0x00, 0x00, 0x03, 0x00, 0x00, // ................
	0x07, 0x80, 0x00, 0x00, 0xe4, 0x80, 0x02, 0x00, 0xe4, 0x80, 0x02, 0x00, 0x00, 0x03, 0x00, 0x00, // ................
	0x07, 0x80, 0x00, 0x00, 0xe4, 0x80, 0x01, 0x00, 0xe4, 0x80, 0x01, 0x00, 0x00, 0x02, 0x00, 0x08, // ................
	0x07, 0x80, 0x00, 0x00, 0xe4, 0x80, 0x01, 0x00, 0x00, 0x02, 0x00, 0x08, 0x08, 0x80, 0x00, 0x00, // ................
	0xff, 0x80, 0xff, 0xff, 0x00, 0x00, 0x00,                                                       // .......
};
static const uint8_t fs_spritesaturation_dx11[754] =
{
	0x46, 0x53, 0x48, 0x06, 0x01, 0x83, 0xf2, 0xe1, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x0c, 0x75, // FSH............u
	0x5f, 0x61, 0x64, 0x6a, 0x75, 0x73, 0x74, 0x6d, 0x65, 0x6e, 0x74, 0x12, 0x00, 0x00, 0x00, 0x01, // _adjustment.....
	0x00, 0x0a, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x01, 0x00, 0x00, // ..s_texColor0...
	0x01, 0x00, 0xb8, 0x02, 0x00, 0x00, 0x44, 0x58, 0x42, 0x43, 0xef, 0xf0, 0xbc, 0x79, 0x40, 0xb2, // ......DXBC...y@.
	0x68, 0xba, 0x56, 0x59, 0xcb, 0xc3, 0x6e, 0x0f, 0xe0, 0x98, 0x01, 0x00, 0x00, 0x00, 0xb8, 0x02, // h.VY..n.........
	0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x2c, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x00, 0x00, 0xd4, 0x00, // ......,.........
	0x00, 0x00, 0x49, 0x53, 0x47, 0x4e, 0x6c, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x08, 0x00, // ..ISGNl.........
	0x00, 0x00, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x03, 0x00, // ..P.............
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x5c, 0x00, 0x00, 0x00, 0x00, 0x00, // ................
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x0f, 0x0f, // ................
	0x00, 0x00, 0x62, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, // ..b.............
	0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x53, 0x56, 0x5f, 0x50, 0x4f, 0x53, // ..........SV_POS
	0x49, 0x54, 0x49, 0x4f, 0x4e, 0x00, 0x43, 0x4f, 0x4c, 0x4f, 0x52, 0x00, 0x54, 0x45, 0x58, 0x43, // ITION.COLOR.TEXC
	0x4f, 0x4f, 0x52, 0x44, 0x00, 0xab, 0x4f, 0x53, 0x47, 0x4e, 0x2c, 0x00, 0x00, 0x00, 0x01, 0x00, // OORD..OSGN,.....
	0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ...... .........
	0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x53, 0x56, // ..............SV
	0x5f, 0x54, 0x41, 0x52, 0x47, 0x45, 0x54, 0x00, 0xab, 0xab, 0x53, 0x48, 0x44, 0x52, 0xdc, 0x01, // _TARGET...SHDR..
	0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x77, 0x00, 0x00, 0x00, 0x59, 0x00, 0x00, 0x04, 0x46, 0x8e, // ..@...w...Y...F.
	0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x5a, 0x00, 0x00, 0x03, 0x00, 0x60, //  .........Z....`
	0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x58, 0x18, 0x00, 0x04, 0x00, 0x70, 0x10, 0x00, 0x00, 0x00, // ......X....p....
	0x00, 0x00, 0x55, 0x55, 0x00, 0x00, 0x62, 0x10, 0x00, 0x03, 0xf2, 0x10, 0x10, 0x00, 0x01, 0x00, // ..UU..b.........
	0x00, 0x00, 0x62, 0x10, 0x00, 0x03, 0x32, 0x10, 0x10, 0x00, 0x02, 0x00, 0x00, 0x00, 0x65, 0x00, // ..b...2.......e.
	0x00, 0x03, 0xf2, 0x20, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x68, 0x00, 0x00, 0x02, 0x04, 0x00, // ... ......h.....
	0x00, 0x00, 0x45, 0x00, 0x00, 0x09, 0xf2, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46, 0x10, // ..E...........F.
	0x10, 0x00, 0x02, 0x00, 0x00, 0x00, 0x46, 0x7e, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, // ......F~.......`
	0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x07, 0xf2, 0x00, 0x10, 0x00, 0x00, 0x00, // ......8.........
	0x00, 0x00, 0x46, 0x0e, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46, 0x1e, 0x10, 0x00, 0x01, 0x00, // ..F.......F.....
	0x00, 0x00, 0x36, 0x00, 0x00, 0x08, 0x72, 0x00, 0x10, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x40, // ..6...r........@
	0x00, 0x00, 0x9a, 0x99, 0x59, 0x3e, 0x74, 0x24, 0x37, 0x3f, 0x2a, 0xa9, 0x93, 0x3d, 0x00, 0x00, // ....Y>t$7?*..=..
	0x00, 0x00, 0x10, 0x00, 0x00, 0x07, 0x42, 0x00, 0x10, 0x00, 0x01, 0x00, 0x00, 0x00, 0x46, 0x02, // ......B.......F.
	0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46, 0x02, 0x10, 0x00, 0x01, 0x00, 0x00, 0x00, 0x36, 0x00, // ......F.......6.
	0x00, 0x05, 0x72, 0x00, 0x10, 0x00, 0x01, 0x00, 0x00, 0x00, 0xa6, 0x0a, 0x10, 0x00, 0x01, 0x00, // ..r.............
	0x00, 0x00, 0x36, 0x00, 0x00, 0x05, 0x72, 0x00, 0x10, 0x00, 0x01, 0x00, 0x00, 0x00, 0x46, 0x02, // ..6...r.......F.
	0x10, 0x00, 0x01, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x05, 0x72, 0x00, 0x10, 0x00, 0x01, 0x00, // ......6...r.....
	0x00, 0x00, 0x46, 0x02, 0x10, 0x00, 0x01, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x05, 0x72, 0x00, // ..F.......6...r.
	0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46, 0x02, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36, 0x00, // ......F.......6.
	0x00, 0x06, 0x72, 0x00, 0x10, 0x00, 0x02, 0x00, 0x00, 0x00, 0x06, 0x80, 0x20, 0x00, 0x00, 0x00, // ..r......... ...
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x06, 0x72, 0x00, 0x10, 0x00, 0x03, 0x00, // ......6...r.....
	0x00, 0x00, 0x46, 0x02, 0x10, 0x80, 0x41, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, // ..F...A.........
	0x00, 0x07, 0x72, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46, 0x02, 0x10, 0x00, 0x00, 0x00, // ..r.......F.....
	0x00, 0x00, 0x46, 0x02, 0x10, 0x00, 0x03, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x07, 0x72, 0x00, // ..F.......8...r.
	0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46, 0x02, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46, 0x02, // ......F.......F.
	0x10, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x72, 0x00, 0x10, 0x00, 0x00, 0x00, // ..........r.....
	0x00, 0x00, 0x46, 0x02, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46, 0x02, 0x10, 0x00, 0x01, 0x00, // ..F.......F.....
	0x00, 0x00, 0x36, 0x00, 0x00, 0x05, 0x72, 0x20, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46, 0x02, // ..6...r ......F.
	0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x05, 0x82, 0x20, 0x10, 0x00, 0x00, 0x00, // ......6.... ....
	0x00, 0x00, 0x3a, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x00, 0x01, 0x00, 0x00, // ..:.......>.....
	0x10, 0x00,                                                                                     // ..
};
extern const uint8_t* fs_spritesaturation_pssl;
extern const uint32_t fs_spritesaturation_pssl_size;
