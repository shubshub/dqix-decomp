#if defined(jpn)
#define R(j,u) (j)
#define data_ov013_02187d94 data_ov013_02188cd0
#define func_ov008_02187b20 func_ov008_021888fc
#define func_ov012_0218432c func_ov012_021853a0
#define func_ov012_0218930c func_ov012_02189be8
#define func_ov012_0218adac func_ov012_0218bba0
#define func_ov013_02185900 func_ov013_02186aec
#define func_ov023_021e6de4 func_ov023_021e7148
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_ov008_02187b20(void* obj, void* ptr, int arg2);
#if defined(jpn)
extern "C" void Window_OpenPane(void* a, void* b, int c, int d, int e, int f, int g);
#else
extern "C" void Window_OpenPane(void* a, void* b, int c, int d, int e, int f, int g, int h);
#endif

struct Struct_ov008_02187a70 {
    char pad0[0xb8];
    void* ptrB8;
    char pad1[0x1d0 - 0xbc];
    unsigned short unknown_1d0_;
    unsigned short unknown_1d2_;
    unsigned short unknown_1d4_;
    unsigned short unknown_1d6_;
    unsigned short unknown_1d8_;
    unsigned short unknown_1da_;
    unsigned short unknown_1dc_;
    unsigned short unknown_1de_;
    char pad2[0x1e1 - 0x1e0];
    unsigned char unknown_1e1_;
    char pad3[0x1e5 - 0x1e2];
    unsigned char unknown_1e5_;
    unsigned char unknown_1e6_;
    unsigned char unknown_1e7_;
};

// USA: func_ov008_02187a70
extern "C" ARM void func_ov008_02187a70(Struct_ov008_02187a70* obj, int arg1) {
    obj->unknown_1d0_ = 0x12;
    obj->unknown_1d2_ = R(0xc,0xb);
    obj->unknown_1d4_ = 0xd;
    obj->unknown_1d6_ = 3;
    obj->unknown_1d8_ = 2;
    obj->unknown_1da_ = 1;
    obj->unknown_1dc_ = 0xa;
    obj->unknown_1de_ = 0xf;
    obj->unknown_1e7_ = 0xa;
    obj->unknown_1e1_ = 3;
    obj->unknown_1e5_ = 1;
    obj->unknown_1e6_ = 1;
    memset(obj->ptrB8, 0, R(0x800,0x960));
    func_ov008_02187b20(obj, obj->ptrB8, arg1);
#if defined(jpn)
    Window_OpenPane((char*)obj + 0x130, obj->ptrB8, 0, 0, 0, 0, 0);
#else
    Window_OpenPane((char*)obj + 0x130, obj->ptrB8, 0, 0, 0, 0, 0, 0);
#endif
}
