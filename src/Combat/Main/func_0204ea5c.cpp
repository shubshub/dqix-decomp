#include <globaldefs.h>

#if defined(jpn)
enum { Enum_0204ea5c_21 = 31, Enum_0204ea5c_22 = 32, Enum_0204ea5c_24 = 34, Enum_0204ea5c_23 = 33 };
#else
enum { Enum_0204ea5c_21 = 21, Enum_0204ea5c_22 = 22, Enum_0204ea5c_24 = 24, Enum_0204ea5c_23 = 23 };
#endif

struct Struct_0204cd60 {
    char pad0[8];
    unsigned char* buf;
    short arrA[18];
    short arrB[18];
    short unknown_54_[18];
    short unknown_78_[18];
    char unknown_9c_[4];
    int unknown_a0_;
    int unknown_a4_;
    short unknown_a8_;
    short unknown_aa_;
    char padAC[4];
    short unknown_b0_;
    short unknown_b2_;
    char padB4[2];
    short unknown_b6_;
    char unknown_b8_[2];
    short sizeTagLineHeight_;
    short unknown_bc_;
    short unknown_be_;
    char unknown_c0_[5];
    unsigned char flags;
    unsigned char unknown_c6_;
    unsigned char unknown_c7_;
    char unknown_c8_[0x10];
    unsigned char bit0 : 2;
    unsigned char unknown_d8_2_ : 1;
    unsigned char unknown_d8_3_ : 5;
    char unknown_d9_[2];
    signed char unknown_db_[4];
};

extern "C" int func_0204fd00(Struct_0204cd60* ctx, int mask);
extern "C" void func_0204f914(Struct_0204cd60* wnd, int mode, short arg2, short arg3, short x1, short arg5);
extern "C" void* func_020421b0(int idx);
extern "C" void func_0204e1c8(Struct_0204cd60* wnd, char* entry, int x, int y, int w, int h, int color, int font);

// USA: func_0204ea5c
extern "C" ARM void func_0204ea5c(Struct_0204cd60* wnd) {
    if (wnd->flags & 0x10) {
        return;
    }
    if (!func_0204fd00(wnd, 1)) {
        func_0204f914(wnd, 0, 0, 0, 8, 8);
        char* entry = (char*)func_020421b0(Enum_0204ea5c_21);
        if (entry) {
            func_0204e1c8(wnd, entry, 0, 0, 8, 8, 0xf0, 0xf);
        }
    }
    if (!func_0204fd00(wnd, 2)) {
        func_0204f914(wnd, 0, (short)((wnd->unknown_a8_ - 1) << 3), 0, (short)(wnd->unknown_a8_ << 3), 8);
        char* entry = (char*)func_020421b0(Enum_0204ea5c_22);
        if (entry) {
            func_0204e1c8(wnd, entry, (short)((wnd->unknown_a8_ - 1) << 3), 0, 8, 8, 0xf0, 0xf);
        }
    }
    if (!func_0204fd00(wnd, 4)) {
        func_0204f914(wnd, 0, 0, (short)((wnd->unknown_aa_ - 1) << 3), 8, (short)(wnd->unknown_aa_ << 3));
        char* entry = (char*)func_020421b0(Enum_0204ea5c_24);
        if (entry) {
            func_0204e1c8(wnd, entry, 0, (short)((wnd->unknown_aa_ - 1) << 3), 8, 8, 0xf0, 0xf);
        }
    }
    if (!func_0204fd00(wnd, 8)) {
        func_0204f914(wnd, 0, (short)((wnd->unknown_a8_ - 1) << 3), (short)((wnd->unknown_aa_ - 1) << 3), (short)(wnd->unknown_a8_ << 3), (short)(wnd->unknown_aa_ << 3));
        char* entry = (char*)func_020421b0(Enum_0204ea5c_23);
        if (entry) {
            func_0204e1c8(wnd, entry, (short)((wnd->unknown_a8_ - 1) << 3), (short)((wnd->unknown_aa_ - 1) << 3), 8, 8, 0xf0, 0xf);
        }
    }
}
