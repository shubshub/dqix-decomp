#include <globaldefs.h>

struct Struct_ov031_02249118 { char name[22]; };
extern Struct_ov031_02249118 data_ov031_02249118;

typedef void (*Type_ov031_022234d8)(void*, int, int);
extern "C" void func_ov031_022234d8(int a0, Type_ov031_022234d8 cb);
extern "C" void LoadToMainBG2CharacterData(int, int, unsigned int);
extern "C" void LoadToMainBGStandardPalette(int, int, unsigned int);
extern "C" void LoadToMainBG2ScreenData(int, int, unsigned int);

extern int data_ov031_0224bd04;
extern int data_ov031_0224bd1c;
extern int data_ov031_0224bd34;

extern "C" const char* func_ov031_02223478(const char* a0);
extern "C" void* func_ov031_0223b61c(const char* path, unsigned int* outSize, int arg2);

struct Struct_ov031_02290cc8_2 { unsigned char field0; signed char field1; unsigned char field2; int field4; };
extern Struct_ov031_02290cc8_2 data_ov031_02290cc8;

// USA: func_ov031_0223336c
extern "C" ARM void func_ov031_0223336c(void) {
    Struct_ov031_02249118 buf = data_ov031_02249118;

    func_ov031_022234d8((int)&data_ov031_0224bd04, (Type_ov031_022234d8)LoadToMainBG2CharacterData);
    func_ov031_022234d8((int)&data_ov031_0224bd1c, (Type_ov031_022234d8)LoadToMainBGStandardPalette);
    func_ov031_022234d8((int)&data_ov031_0224bd34, (Type_ov031_022234d8)LoadToMainBG2ScreenData);

    const char* name = func_ov031_02223478(buf.name);
    void* result = func_ov031_0223b61c(name, 0, 4);
    data_ov031_02290cc8.field4 = (int)result;

    volatile unsigned short* var3 = (volatile unsigned short*)0x4001008;
    volatile unsigned short* var4 = (volatile unsigned short*)0x400000a;
    *var3 = (*var3 & ~3) | 3;
    *(var3 + 1) = (*(var3 + 1) & ~3) | 3;
    *var4 = (*var4 & ~3) | 3;
    *(var4 + 1) = (*(var4 + 1) & ~3) | 3;
}
