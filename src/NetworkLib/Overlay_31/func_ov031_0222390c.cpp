#include <globaldefs.h>

typedef void (*Type_ov031_022234d8)(void*, int, int);
extern "C" void func_ov031_022234d8(int a0, Type_ov031_022234d8 cb);
extern "C" void* func_ov031_0223cf4c(unsigned int len, int align);
extern "C" unsigned int func_ov031_02227558(void);
extern "C" int LoadToMainBG1ScreenData(int, int, unsigned int);
extern "C" int LoadToMainBG1CharacterData(int arg0, int arg1, unsigned int arg2);

extern void* data_ov031_02250bf4;
extern unsigned char data_ov031_0224b410;
extern int data_ov031_0224b3c0[];

// USA: func_ov031_0222390c
extern "C" ARM void func_ov031_0222390c(void) {
	data_ov031_02250bf4 = func_ov031_0223cf4c(0xc0, 4);
	func_ov031_022234d8((int)&data_ov031_0224b410, (Type_ov031_022234d8)LoadToMainBG1CharacterData);
	unsigned int field = func_ov031_02227558();
	switch (field) {
	case 0:
		func_ov031_022234d8(data_ov031_0224b3c0[0], (Type_ov031_022234d8)LoadToMainBG1ScreenData);
		break;
	case 1:
		func_ov031_022234d8(data_ov031_0224b3c0[1], (Type_ov031_022234d8)LoadToMainBG1ScreenData);
		break;
	}
}
