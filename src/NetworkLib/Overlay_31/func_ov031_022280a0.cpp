#include <globaldefs.h>

extern "C" void func_ov031_022234d8(void* data, void* fn);
extern "C" int func_ov031_02223478(void* buf);
extern "C" int func_ov031_0223b61c(int t, int a, int b);

extern "C" void LoadToMainBG2CharacterData(int, int, unsigned int);
extern "C" void LoadToMainBGStandardPalette(int, int, unsigned int);
extern "C" void LoadToMainBG2ScreenData(int, int, unsigned int);

struct Struct_ov031_02248dae {
	unsigned char bytes[22];
};

extern Struct_ov031_02248dae data_ov031_02248dae;
extern unsigned char data_ov031_0224b82c[1];
extern unsigned char data_ov031_0224b844[1];
extern unsigned char data_ov031_0224b85c[1];
extern unsigned char data_ov031_02290c50[8];

// USA: func_ov031_022280a0
extern "C" ARM void func_ov031_022280a0(void) {
	Struct_ov031_02248dae name = data_ov031_02248dae;

	func_ov031_022234d8(data_ov031_0224b82c, (void*)LoadToMainBG2CharacterData);
	func_ov031_022234d8(data_ov031_0224b844, (void*)LoadToMainBGStandardPalette);
	func_ov031_022234d8(data_ov031_0224b85c, (void*)LoadToMainBG2ScreenData);

	int t = func_ov031_02223478(name.bytes);
	int r = func_ov031_0223b61c(t, 0, 4);
	*(int*)(data_ov031_02290c50 + 4) = r;

	unsigned short* p2 = (unsigned short*)0x4001008;
	unsigned short* p1 = (unsigned short*)0x400000a;
	p2[0] = (p2[0] & ~3) | 3;
	p2[1] = (p2[1] & ~3) | 3;
	p1[0] = (p1[0] & ~3) | 3;
	p1[1] = (p1[1] & ~3) | 3;
}
