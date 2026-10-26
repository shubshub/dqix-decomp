#include <globaldefs.h>

extern int data_ov031_0224bc0c;
extern int data_ov031_0224bc24;
extern int data_ov031_0224bc3c;

typedef void (*Type_ov031_022234d8)(void*, int, int);
extern "C" void func_ov031_022234d8(int a0, Type_ov031_022234d8 cb);

extern "C" int LoadToMainBG2CharacterData(int arg0, int arg1, unsigned int arg2);
extern "C" ARM void LoadToMainBGStandardPalette(int src, int dstOffset, unsigned int size);
extern "C" ARM int LoadToMainBG2ScreenData(int arg0, int arg1, unsigned int arg2);

// USA: func_ov031_02231c0c
extern "C" ARM void func_ov031_02231c0c(void) {
    func_ov031_022234d8((int)&data_ov031_0224bc0c, (Type_ov031_022234d8)LoadToMainBG2CharacterData);
    func_ov031_022234d8((int)&data_ov031_0224bc24, (Type_ov031_022234d8)LoadToMainBGStandardPalette);
    func_ov031_022234d8((int)&data_ov031_0224bc3c, (Type_ov031_022234d8)LoadToMainBG2ScreenData);
    volatile unsigned short* p3 = (volatile unsigned short*)0x4001008;
    volatile unsigned short* p1 = (volatile unsigned short*)0x400000a;
    volatile unsigned short* p2 = (volatile unsigned short*)0x4000008;
    *p3 = (*p3 & ~3) | 3;
    *(p3 + 1) = (*(p3 + 1) & ~3) | 3;
    *p2 = (*p2 & ~3) | 3;
    *p1 = (*p1 & ~3) | 3;
    *(p1 + 1) = (*(p1 + 1) & ~3) | 3;
}
