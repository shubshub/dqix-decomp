#include <globaldefs.h>

struct Struct_020b1540 {
    signed char left;
    unsigned char glyphWidth;
    signed char unknown_2_;
};

struct Struct_020b27c8 {
    unsigned char fontType;
    signed char unknown_1_;
    unsigned short unknown_2_;
    Struct_020b1540 defaultWidth;
    unsigned char unknown_7_;
};

struct Struct_020b1020 {
    Struct_020b27c8* unknown_0_;
};

struct Struct_020b23a8 {
    const void* unknown_0_;
    const Struct_020b1020* unknown_4_;
    int unknown_8_;
    int unknown_c_;
};

struct Struct_020b245c {
    signed char x;
    signed char y;
};

enum {
    Enum_020b245c_1024 = 0x400,
    Enum_020b245c_2048 = 0x800
};

extern "C" int func_020b0f00(const Struct_020b1020* arg0, int arg1, const void* str, const void** arg3);
extern "C" void func_020b23a8(const Struct_020b23a8* arg0, int x, int y, int arg3, const void* str, const void** arg5, Struct_020b245c dir);

static inline int inline_020b1020(const Struct_020b1020* arg0) {
    return arg0->unknown_0_->unknown_1_;
}

static inline int inline_020b245c(const Struct_020b23a8* arg0, const void* str, const void** arg2) {
    return func_020b0f00(arg0->unknown_4_, arg0->unknown_8_, str, arg2);
}

// USA: func_020b245c
extern "C" ARM void func_020b245c(const Struct_020b23a8* arg0, int x, int y, int areaWidth, int arg4, unsigned int flags, const void* arg6, Struct_020b245c dir) {
    const void* str;
    int var1;
    int var2;
    int var3;
    int line;

    var1 = inline_020b1020(arg0->unknown_4_) + arg0->unknown_c_;
    var2 = var1 * -dir.y;
    var3 = var1 * dir.x;
    str = arg6;

    line = 0;

    while (str != NULL) {
        int px = x + line * var2;
        int var6 = y + line * var3;

        if (flags & Enum_020b245c_2048) {
            int width = inline_020b245c(arg0, str, NULL);
            int var8 = areaWidth - width;
            px += var8 * dir.x;
            var6 += var8 * dir.y;
        } else if (flags & Enum_020b245c_1024) {
            int width = inline_020b245c(arg0, str, NULL);
            int var10 = (areaWidth + 1) / 2 - (width + 1) / 2;
            px += var10 * dir.x;
            var6 += var10 * dir.y;
        }

        func_020b23a8(arg0, px, var6, arg4, str, &str, dir);
        line++;
    }
}
