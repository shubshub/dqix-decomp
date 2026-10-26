#include <globaldefs.h>

struct Struct_020e23c0;

struct Struct_0204459c_3 {
    short b;
    short a;
};

struct Struct_0204459c {
    char pad0[0x14];
    short f14;
    short unknown_16_;
    short f18;
    short unknown_1a_;
};

struct Struct_0204459c_2 {
#if !defined(jpn)
    char pad0[0x34];
#endif
    void* field34;
    struct Struct_020e23c0* field38;
#if defined(jpn)
    char unknown_8_[0x7d0 - 0x8];
#else
    char unknown_3c_[0x900 - 0x3c];
#endif
    struct Struct_0204459c pose;
    char unknown_91c_[0x9a0 - 0x91c];
    int mode;
#if defined(jpn)
    char unknown_874_[0x17de - 0x874];
#else
    char unknown_9a4_[0x19ae - 0x9a4];
#endif
    signed char unknown_19ae_;
    unsigned char unknown_19af_;
#if defined(jpn)
    char unknown_17e0_[0x17fb - 0x17e0];
#else
    char unknown_19b0_[0x19ca - 0x19b0];
#endif
    unsigned char unknown_19ca_;
};

extern "C" void func_0204455c(void* obj, short* a, short* b);
extern "C" void func_0204f914(void* obj, int mode, short a, short b, short c, short d);
extern "C" void func_020e23c0(struct Struct_020e23c0*, int, int, int, short, short);

// USA: func_0204459c
extern "C" ARM void func_0204459c(struct Struct_0204459c_2* obj, int flag) {
    if (obj->mode == 1 || obj->mode == 3 || obj->mode == 2) {
        if (obj->unknown_19ca_ == 0) return;
        if (flag != 0) {
            struct Struct_0204459c_3 var0;
            func_0204455c(obj->field34, &var0.a, &var0.b);
            int b = var0.b;
            int a = var0.a;
            func_0204f914(obj->field34, 0, a - 3, b, a + 4, b + 4);
        }
    }
    if (obj->unknown_19af_ != 1) return;
    if (flag != 0) {
        short p;
        short q;
        func_0204455c(obj->field34, &p, &q);
        if (obj->unknown_19ae_ <= 15) return;
        for (short i = 0; i < 4; i++) {
            func_0204f914(obj->field34, 15, p - (3 - i), q + i, p + (4 - i), q + i + 1);
        }
        return;
    }
    short x = obj->pose.unknown_1a_;
    short y = obj->pose.unknown_16_;
    short z = obj->pose.f18;
    short w = obj->pose.f14;
    int var10 = w + (z >> 1);
    int var11 = y + x - 3;
    if (obj->field38 != 0) {
        if (obj->unknown_19ae_ <= 15) return;
        int base = x - 8;
        for (short i = 0; i < 4; i++) {
            func_020e23c0(obj->field38, 15, (short)((z >> 1) - (3 - i)), (short)(base + i), (4 - i) + (z >> 1), base + i + 1);
        }
        return;
    }
    unsigned int v = 0xf000f000;
    volatile unsigned int* var15 = (volatile unsigned int*)0x04000444;
    var15[0] = 0;
    var15[0x3c / 4] = 0x7fff;
    var15[0x64 / 4] = 0x900000;
    var15[0x60 / 4] = 0x3e1f00c0;
    var15[0] = 0;
    var15[0x2c / 4] = var10 << 12;
    var15[0x2c / 4] = var11 << 12;
    var15[0x2c / 4] = 0x400000;
    var15[0x28 / 4] = 0x6000;
    var15[0x28 / 4] = 0x6000;
    var15[0x28 / 4] = 0x1000;
    var15[0xbc / 4] = 0;
    var15[0x48 / 4] = 0;
    var15[0x48 / 4] = 0;
    var15[0x48 / 4] = v;
    var15[0x48 / 4] = 0;
    var15[0x48 / 4] = v - 0xe000;
    var15[0x48 / 4] = 0;
    var15[0xc0 / 4] = 0;
    var15[4 / 4] = 1;
    var15[4 / 4] = 1;
}
