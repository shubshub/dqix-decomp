#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif

#include "std_library_functions.h"

struct Struct_020938f0 {
    char pad0[IS_JPN ? 0x100 : 0x340];
    int unknown_340_;
    int unknown_344_;
    char pad1[IS_JPN ? 0x30 : 0x80];
    unsigned char unknown_3c8_0_ : 7;
    unsigned char unknown_3c8_7_ : 1;
    unsigned char unknown_3c9_0_ : 1;
    unsigned char unknown_3ca_;
    unsigned char unknown_3cb_;
    unsigned char unknown_3cc_;
    unsigned char unknown_3cd_;
};

extern "C" void func_02093980(char* obj);

// USA: func_020938f0
extern "C" ARM void func_020938f0(char* obj) {
    int i;
    for (i = 0; i < 8; i++) {
        func_02093980(obj + i * (IS_JPN ? 0x10 : 0x34));
        func_02093980(obj + (IS_JPN ? 0x80 : 0x1a0) + i * (IS_JPN ? 0x10 : 0x34));
    }
    struct Struct_020938f0* p = (struct Struct_020938f0*)obj;
    p->unknown_340_ = -1;
    p->unknown_344_ = 0;
    memset(obj + (IS_JPN ? 0x108 : 0x348), 0, (IS_JPN ? 0x30 : 0x80));
    p->unknown_3c8_0_ = 0;
    ((unsigned char*)obj)[(IS_JPN ? 0x138 : 0x3c8)] |= 0x80;
    p->unknown_3c9_0_ = 0;
    p->unknown_3cb_ = p->unknown_3ca_ = 0;
    p->unknown_3cc_ = 0;
    p->unknown_3cd_ = p->unknown_3cc_ | 8;
}
