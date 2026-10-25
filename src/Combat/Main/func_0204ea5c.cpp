#include <globaldefs.h>

#if defined(jpn)
enum { Enum_0204ea5c_21 = 31, Enum_0204ea5c_22 = 32, Enum_0204ea5c_24 = 34, Enum_0204ea5c_23 = 33 };
#else
enum { Enum_0204ea5c_21 = 21, Enum_0204ea5c_22 = 22, Enum_0204ea5c_24 = 24, Enum_0204ea5c_23 = 23 };
#endif

struct Wnd0204cd60 {
    char pad0[8];
    unsigned char* buf;
    short arrA[18];
    short arrB[18];
    short arrC[18];
    short arrD[18];
    char pad9C[4];
    int fA0;
    int fA4;
    short fA8;
    short fAA;
    char padAC[4];
    short fB0;
    short fB2;
    char padB4[2];
    short fB6;
    char padB8[2];
    short sizeTagLineHeight_;
    short fBC;
    short fBE;
    char padC0[5];
    unsigned char flags;
    unsigned char fC6;
    unsigned char fC7;
    char padC8[0x10];
    unsigned char bit0 : 2;
    unsigned char useBg : 1;
    unsigned char bit3 : 5;
    char padD9[2];
    signed char margins[4];
};

extern "C" int func_0204fd00(Struct_0204cd60* arg0, int arg1);
extern "C" void func_0204f914(Struct_0204cd60* arg0, int arg1, short arg2, short arg3, short arg4, short arg5);
extern "C" void* func_020421b0(int arg0);
extern "C" void func_0204e1c8(Struct_0204cd60* arg0, char* arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7);

// USA: func_0204ea5c
extern "C" ARM void func_0204ea5c(Struct_0204cd60* arg0) {
    if (arg0->unknown_c5_ & 0x10) {
        return;
    }
    if (!func_0204fd00(arg0, 1)) {
        func_0204f914(arg0, 0, 0, 0, 8, 8);
        char* var0 = (char*)func_020421b0(Enum_0204ea5c_21);
        if (var0) {
            func_0204e1c8(arg0, var0, 0, 0, 8, 8, 0xf0, 0xf);
        }
    }
    if (!func_0204fd00(arg0, 2)) {
        func_0204f914(arg0, 0, (short)((arg0->unknown_a8_ - 1) << 3), 0, (short)(arg0->unknown_a8_ << 3), 8);
        char* var1 = (char*)func_020421b0(Enum_0204ea5c_22);
        if (var1) {
            func_0204e1c8(arg0, var1, (short)((arg0->unknown_a8_ - 1) << 3), 0, 8, 8, 0xf0, 0xf);
        }
    }
    if (!func_0204fd00(arg0, 4)) {
        func_0204f914(arg0, 0, 0, (short)((arg0->unknown_aa_ - 1) << 3), 8, (short)(arg0->unknown_aa_ << 3));
        char* var2 = (char*)func_020421b0(Enum_0204ea5c_24);
        if (var2) {
            func_0204e1c8(arg0, var2, 0, (short)((arg0->unknown_aa_ - 1) << 3), 8, 8, 0xf0, 0xf);
        }
    }
    if (!func_0204fd00(arg0, 8)) {
        func_0204f914(arg0, 0, (short)((arg0->unknown_a8_ - 1) << 3), (short)((arg0->unknown_aa_ - 1) << 3), (short)(arg0->unknown_a8_ << 3), (short)(arg0->unknown_aa_ << 3));
        char* var3 = (char*)func_020421b0(Enum_0204ea5c_23);
        if (var3) {
            func_0204e1c8(arg0, var3, (short)((arg0->unknown_a8_ - 1) << 3), (short)((arg0->unknown_aa_ - 1) << 3), 8, 8, 0xf0, 0xf);
        }
    }
}
