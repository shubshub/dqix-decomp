#include <globaldefs.h>

extern "C" void func_ov031_022234d8(void* data, void* fn);
extern "C" int func_ov031_02223478(void* buf);
extern "C" int func_ov031_0223b61c(int t, int a, int b);
extern "C" void func_ov031_0223cb68(int a, int b);

extern "C" void LoadToMainObjStandardPalette(int, int, unsigned int);
extern "C" void LoadToMainBG2CharacterData(int, int, unsigned int);
extern "C" void LoadToMainBGStandardPalette(int, int, unsigned int);
extern "C" void LoadToMainBG2ScreenData(int, int, unsigned int);

struct Struct_ov031_0224906c {
	unsigned char bytes[22];
};

extern Struct_ov031_0224906c data_ov031_0224906c;
extern unsigned char data_ov031_0224bc94[1];
extern unsigned char data_ov031_0224bca8[1];
extern unsigned char data_ov031_0224bcc0[1];
extern unsigned char data_ov031_0224bcd8[1];

struct Struct_ov031_02290cc0_2 { void* field0; void* field4; };
extern Struct_ov031_02290cc0_2 data_ov031_02290cc0;

// USA: func_ov031_02232568
extern "C" ARM void func_ov031_02232568(void) {
	Struct_ov031_0224906c name = data_ov031_0224906c;

	func_ov031_022234d8(data_ov031_0224bc94, (void*)LoadToMainObjStandardPalette);
	func_ov031_022234d8(data_ov031_0224bca8, (void*)LoadToMainBG2CharacterData);
	func_ov031_022234d8(data_ov031_0224bcc0, (void*)LoadToMainBGStandardPalette);
	func_ov031_022234d8(data_ov031_0224bcd8, (void*)LoadToMainBG2ScreenData);

	int t = func_ov031_02223478(name.bytes);

	int r = func_ov031_0223b61c(t, 0, 4);
	*(int*)data_ov031_02290cc0.field4 = r;
	func_ov031_0223cb68(1, 0x10);

	unsigned short* p2 = (unsigned short*)0x4001008;
	unsigned short* p1 = (unsigned short*)0x400000a;
	p2[0] = (p2[0] & ~3) | 3;
	p2[1] = (p2[1] & ~3) | 3;
	p1[0] = (p1[0] & ~3) | 3;
	p1[1] = (p1[1] & ~3) | 3;
}
