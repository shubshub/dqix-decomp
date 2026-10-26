#include <globaldefs.h>

typedef void (*Type_ov031_022234d8)(void*, int, int);

extern "C" void func_ov031_022234d8(int a0, Type_ov031_022234d8 cb);
extern "C" extern int LoadToMainBG2ScreenData(int arg0, int arg1, unsigned int arg2);

extern int data_ov031_0224bdb4;

// USA: func_ov031_02234354
extern "C" ARM void func_ov031_02234354(void) {
    func_ov031_022234d8((int)&data_ov031_0224bdb4, (Type_ov031_022234d8)LoadToMainBG2ScreenData);
    volatile unsigned short* var0 = (volatile unsigned short*)0x4001008;
    volatile unsigned short* var1 = (volatile unsigned short*)0x4000008;
    volatile unsigned short* var2 = (volatile unsigned short*)0x400000a;
    *var0 = (*var0 & ~3) | 3;
    *(var0 + 1) = (*(var0 + 1) & ~3) | 3;
    *var1 = (*var1 & ~3) | 3;
    *var2 = (*var2 & ~3) | 3;
    *(var2 + 1) = (*(var2 + 1) & ~3) | 3;
}
