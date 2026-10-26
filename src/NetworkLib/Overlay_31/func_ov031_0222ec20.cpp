#include <globaldefs.h>

extern "C" void func_ov031_022234d8(void* data, void* fn);
extern "C" int func_ov031_02223478(void* buf);
extern "C" int func_ov031_0223b61c(int t, int a, int b);
extern "C" void func_ov031_02234ea8(void* arg);
extern "C" void func_ov031_02234f34();

extern "C" void LoadToMainObjStandardPalette(int, int, unsigned int);
extern "C" void LoadToMainBG3CharacterData(int, int, unsigned int);
extern "C" void LoadToMainBG2CharacterData(int, int, unsigned int);
extern "C" void LoadToMainBGStandardPalette(int, int, unsigned int);
extern "C" void LoadToMainBG3ScreenData(int, int, unsigned int);

struct Struct_ov031_02248fd3 { char s[23]; };
struct Struct_ov031_02248fa8 { char s[21]; };
struct Struct_ov031_02248fbd { char s[22]; };
extern Struct_ov031_02248fd3 data_ov031_02248fd3;
extern Struct_ov031_02248fa8 data_ov031_02248fa8;
extern Struct_ov031_02248fbd data_ov031_02248fbd;

extern unsigned char data_ov031_0224bb0c[1];
extern unsigned char data_ov031_0224bb20[1];
extern unsigned char data_ov031_0224bb38[1];
extern unsigned char data_ov031_0224bb50[1];

struct Struct_ov031_0222ec20 { char pad[8]; int field8; int fieldc; int field10; void* field14; };
struct Struct_ov031_02290ca0_2 { char pad[8]; Struct_ov031_0222ec20* field8; };
extern Struct_ov031_02290ca0_2 data_ov031_02290ca0;

// USA: func_ov031_0222ec20
extern "C" ARM void func_ov031_0222ec20(void) {
	Struct_ov031_02248fd3 a = data_ov031_02248fd3;
	Struct_ov031_02248fa8 b = data_ov031_02248fa8;
	Struct_ov031_02248fbd c = data_ov031_02248fbd;

	volatile unsigned short* var3 = (volatile unsigned short*)0x400000c;
	*var3 = (*var3 & 0x43) | 0xe18;

	func_ov031_022234d8(data_ov031_0224bb0c, (void*)LoadToMainObjStandardPalette);
	func_ov031_022234d8(data_ov031_0224bb20, (void*)LoadToMainBG3CharacterData);
	func_ov031_022234d8(data_ov031_0224bb38, (void*)LoadToMainBG2CharacterData);
	func_ov031_022234d8(&b, (void*)LoadToMainBGStandardPalette);
	func_ov031_022234d8(data_ov031_0224bb50, (void*)LoadToMainBG3ScreenData);

	int var4 = func_ov031_02223478(&a);
	int h1 = func_ov031_0223b61c(var4, 0, 4);
	data_ov031_02290ca0.field8->field8 = h1;
	func_ov031_02234ea8((void*)data_ov031_02290ca0.field8->field8);
	func_ov031_02234f34();
	int t2 = func_ov031_02223478(&b);
	int h2 = func_ov031_0223b61c(t2, 0, 4);
	data_ov031_02290ca0.field8->fieldc = h2;
	int var8 = func_ov031_02223478(&c);
	int h3 = func_ov031_0223b61c(var8, 0, 4);
	data_ov031_02290ca0.field8->field10 = h3;

	volatile unsigned short* var10 = (volatile unsigned short*)0x4001008;
	volatile unsigned short* var11 = (volatile unsigned short*)0x4000008;
	volatile unsigned short* var12 = (volatile unsigned short*)0x400000a;
	*var10 = (*var10 & ~3) | 3;
	*(var10 + 1) = (*(var10 + 1) & ~3) | 3;
	*var11 = (*var11 & ~3) | 3;
	*var12 = (*var12 & ~3) | 2;
	*(var12 + 1) = (*(var12 + 1) & ~3) | 3;
	*(var12 + 2) = (*(var12 + 2) & ~3) | 2;
}
