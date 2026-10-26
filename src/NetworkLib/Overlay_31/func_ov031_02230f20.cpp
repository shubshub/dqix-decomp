#include <globaldefs.h>

typedef void (*Type_ov031_022234d8)(void*, int, int);

extern "C" void func_ov031_022234d8(int a0, Type_ov031_022234d8 cb);

extern "C" extern int LoadToMainBG2CharacterData(int, int, unsigned int);
extern "C" extern void LoadToMainBGStandardPalette(int, int, unsigned int);
extern "C" extern int LoadToMainBG2ScreenData(int, int, unsigned int);

extern char data_ov031_0224bb8c;
extern char data_ov031_0224bba4;
extern char data_ov031_0224bbbc;

// USA: func_ov031_02230f20
extern "C" ARM void func_ov031_02230f20(void) {
	func_ov031_022234d8((int)&data_ov031_0224bb8c, (Type_ov031_022234d8)LoadToMainBG2CharacterData);
	func_ov031_022234d8((int)&data_ov031_0224bba4, (Type_ov031_022234d8)LoadToMainBGStandardPalette);
	func_ov031_022234d8((int)&data_ov031_0224bbbc, (Type_ov031_022234d8)LoadToMainBG2ScreenData);

	unsigned short *a = (unsigned short*)0x4001008;
	unsigned short *b = (unsigned short*)0x400000a;
	a[0] = (a[0] & ~3) | 3;
	a[1] = (a[1] & ~3) | 3;
	b[0] = (b[0] & ~3) | 3;
	b[1] = (b[1] & ~3) | 3;
}
