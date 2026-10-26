#include <globaldefs.h>

typedef void (*Type_ov031_022234d8)(void*, int, int);
extern "C" ARM void func_ov031_022234d8(int a0, Type_ov031_022234d8 cb);

extern "C" int LoadToMainObjStandardPalette(int arg0, int arg1, unsigned int arg2);
extern "C" int LoadToMainBG2CharacterData(int arg0, int arg1, unsigned int arg2);
extern "C" void LoadToMainBGStandardPalette(int src, int dstOffset, unsigned int size);
extern "C" int LoadToMainBG2ScreenData(int arg0, int arg1, unsigned int arg2);

extern int data_ov031_0224ba80;
extern int data_ov031_0224ba94;
extern int data_ov031_0224baac;
extern int data_ov031_0224bac4;

// USA: func_ov031_0222d894
extern "C" ARM void func_ov031_0222d894(void) {
    func_ov031_022234d8((int)&data_ov031_0224ba80, (Type_ov031_022234d8)LoadToMainObjStandardPalette);
    func_ov031_022234d8((int)&data_ov031_0224ba94, (Type_ov031_022234d8)LoadToMainBG2CharacterData);
    func_ov031_022234d8((int)&data_ov031_0224baac, (Type_ov031_022234d8)LoadToMainBGStandardPalette);
    func_ov031_022234d8((int)&data_ov031_0224bac4, (Type_ov031_022234d8)LoadToMainBG2ScreenData);

    volatile unsigned short* var0 = (volatile unsigned short*)0x4001008;
    volatile unsigned short* var1 = (volatile unsigned short*)0x400100a;
    volatile unsigned short* var2 = (volatile unsigned short*)0x4000008;
    volatile unsigned short* var3 = (volatile unsigned short*)0x400000a;
    volatile unsigned short* var4 = (volatile unsigned short*)0x400000c;

    *var0 = (*var0 & ~3) | 3;
    *var1 = (*var1 & ~3) | 3;
    *var2 = (*var2 & ~3) | 2;
    *var3 = (*var3 & ~3) | 3;
    *var4 = (*var4 & ~3) | 3;
}
