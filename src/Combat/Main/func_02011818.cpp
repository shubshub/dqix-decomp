#include <globaldefs.h>
#include "NitroSDK/Memory.h"

struct Struct_02011818 {
    unsigned char f0;
    unsigned char f1;
    unsigned char f2;
    char pad3;
    unsigned short f4;
    unsigned char unknown_6_;
    signed char unknown_7_;
    char pad8[0xb];
    signed char unknown_13_;
    char unknown_14_[0xc];
    unsigned int unknown_20_;
    unsigned char unknown_24_;
    char unknown_25_;
    unsigned short unknown_26_;
};

#if defined(jpn)
enum { Enum_02011818_0 = 0x280, Enum_02011818_0_2 = 0x240 };
#else
enum { Enum_02011818_0 = 0, Enum_02011818_0_2 = 0 };
#endif

// USA: func_02011818
extern "C" ARM void func_02011818(void* obj, struct Struct_02011818* src) {
    unsigned char* base = (unsigned char*)obj;
    base[0x646c - Enum_02011818_0] = 1;
    base[0x646d - Enum_02011818_0] = src->unknown_6_;
    base[0x6470 - Enum_02011818_0] = src->f0;
    if (src->f0 == 1) {
        base[0x6471 - Enum_02011818_0] = src->f1;
        *(unsigned short*)(base + (0x6472 - Enum_02011818_0)) = src->f4;
    } else {
        base[0x6471 - Enum_02011818_0] = src->f1;
        *(unsigned short*)(base + (0x6472 - Enum_02011818_0)) = src->f2;
        if (src->unknown_26_ != 0) *(unsigned short*)(base + (0x647e - Enum_02011818_0)) = src->unknown_26_;
    }
    if (src->unknown_7_ != 0) {
        VectorizedInvertedMemcpy(&src->unknown_7_, base + (0x64df - Enum_02011818_0_2), 0xa);
    } else {
        base[0x64df - Enum_02011818_0_2] = 0;
    }
    if (src->unknown_13_ != 0) {
        VectorizedInvertedMemcpy(&src->unknown_13_, base + (0x64e9 - Enum_02011818_0_2), 0xa);
    } else {
        base[0x64e9 - Enum_02011818_0_2] = 0;
    }
    if (src->unknown_24_ != 0) base[0x647c - Enum_02011818_0] = src->unknown_24_;
    *(unsigned int*)(base + (0x6478 - Enum_02011818_0)) = src->unknown_20_;
    *(int*)(base + (0x6474 - Enum_02011818_0)) = -1;
}
