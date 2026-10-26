#include <globaldefs.h>

extern int data_ov031_0224bda0;
extern "C" ARM int LoadToMainBG2ScreenData(int, int, unsigned int);
typedef void (*Type_ov031_022234d8)(void*, int, int);
extern "C" ARM void func_ov031_022234d8(int a0, Type_ov031_022234d8 cb);

// USA: func_ov031_02234118
extern "C" ARM void func_ov031_02234118(void) {
	func_ov031_022234d8((int)&data_ov031_0224bda0, (Type_ov031_022234d8)LoadToMainBG2ScreenData);
	volatile unsigned short* p1 = (volatile unsigned short*)0x4001008;
	volatile unsigned short* p2 = (volatile unsigned short*)0x400000a;
	p1[0] = (p1[0] & ~3) | 3;
	p1[1] = (p1[1] & ~3) | 3;
	p2[0] = (p2[0] & ~3) | 3;
	p2[1] = (p2[1] & ~3) | 3;
}
