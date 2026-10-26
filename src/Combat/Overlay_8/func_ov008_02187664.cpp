#include <globaldefs.h>
#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif

#include "std_library_functions.h"

extern "C" void func_ov008_02187708(void* obj, void* ptr, int arg2);
#if defined(jpn)
extern "C" void Window_OpenPane(void* a, void* b, int c, int d, int e, int f, int g);
#else
extern "C" void Window_OpenPane(void* a, void* b, int c, int d, int e, int f, int g, int h);
#endif

struct Struct_ov008_02184a4c_13 {
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

// USA: func_ov008_02187664
extern "C" ARM void func_ov008_02187664(Struct_ov008_02184a4c_13* obj, int arg1) {
    obj->unknown_1d0_ = 0x1e;
    obj->unknown_1d2_ = LOW_REGION(2, 3);
    obj->unknown_1d4_ = 2;
    obj->unknown_1d6_ = 0;
    obj->unknown_1d8_ = LOW_REGION(0, 1);
    obj->unknown_1da_ = LOW_REGION(3, 2);
    obj->unknown_1dc_ = 0xa;
    obj->unknown_1de_ = 0xa;
    obj->unknown_1e7_ = 0xa;
    obj->unknown_1e1_ = 0;
    obj->unknown_1e5_ = 1;
    obj->unknown_1e6_ = 1;
    memset(obj->ptrB8, 0, LOW_REGION(0x800, 0x960));
    func_ov008_02187708(obj, obj->ptrB8, arg1);
#if defined(jpn)
    Window_OpenPane((char*)obj + 0x130, obj->ptrB8, 0, 0, 0, 0, 0);
#else
    Window_OpenPane((char*)obj + 0x130, obj->ptrB8, 0, 0, 0, 0, 0, 0);
#endif
}
