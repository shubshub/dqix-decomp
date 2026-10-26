#include <globaldefs.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Struct_020b27c8 Struct_020b27c8;
typedef struct Struct_020b1540_3 Struct_020b1540_3;

typedef struct Struct_020b1020 {
    Struct_020b27c8* unknown_0_;
} Struct_020b1020;

typedef struct Struct_020b23a8 {
    const Struct_020b1540_3* unknown_0_;
    const Struct_020b1020* unknown_4_;
    int unknown_8_;
    int unknown_c_;
} Struct_020b23a8;

typedef struct Struct_020b23a8_2 {
    signed char x;
    signed char y;
} Struct_020b23a8_2;

typedef struct Struct_020b1020_2 {
    int width;
    int height;
} Struct_020b1020_2;

typedef char Type_020b1020;

enum {
    Enum_020b25c4_2 = 0x2,
    Enum_020b25c4_4 = 0x4,
    Enum_020b25c4_16 = 0x10,
    Enum_020b25c4_32 = 0x20
};

Struct_020b1020_2 func_020b1020(const Struct_020b1020* arg0, int arg1, int arg2, const void* arg3);
void func_020b245c(const Struct_020b23a8* arg0, int x, int y, int areaWidth, int arg4, unsigned int flags, const void* arg6, Struct_020b23a8_2 d);

static inline Struct_020b1020_2 inline_020b25c4(const Struct_020b1020* arg0, int arg1, int arg2, const Type_020b1020* arg3) {
    Struct_020b1020_2 rect = func_020b1020(arg0, arg1, arg2, arg3);
    return rect;
}

static inline Struct_020b1020_2 inline_020b25c4_2(const Struct_020b23a8* arg0, const Type_020b1020* arg1) {
    return inline_020b25c4(arg0->unknown_4_, arg0->unknown_8_, arg0->unknown_c_, arg1);
}

// USA: func_020b25c4
ARM void func_020b25c4(const Struct_020b23a8* arg0, int x, int y, int arg3, unsigned int flags, const void* arg5, Struct_020b23a8_2 d) {
    Struct_020b1020_2 area;

    {
        area = inline_020b25c4_2(arg0, arg5);

        if (flags & Enum_020b25c4_16) {
            const int offset = -(area.width + 1) / 2;
            x += offset * d.x;
            y += offset * d.y;
        } else if (flags & Enum_020b25c4_32) {
            const int offset = -area.width;
            x += offset * d.x;
            y += offset * d.y;
        }

        if (flags & Enum_020b25c4_2) {
            const int offset = -(area.height + 1) / 2;
            x += offset * -d.y;
            y += offset * d.x;
        } else if (flags & Enum_020b25c4_4) {
            const int offset = -area.height;
            x += offset * -d.y;
            y += offset * d.x;
        }
    }

    func_020b245c(arg0, x, y, area.width, arg3, flags, arg5, d);
}

#ifdef __cplusplus
}
#endif
