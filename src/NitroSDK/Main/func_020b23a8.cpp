#include <globaldefs.h>

typedef unsigned short u16;
typedef signed char Type_ov002_0215ab60;

struct Struct_020b1d70;
struct Struct_020b1d70_2;
extern "C" int func_020b1d70(struct Struct_020b1d70* arg0, struct Struct_020b1d70_2** arg1, int arg2, int arg3, int arg4, unsigned short arg5);

typedef u16 (*Type_020b23a8)(const void** ppChar);

struct Struct_020b1020 {
    void* unknown_0_;
    Type_020b23a8 unknown_4_;
};

struct Struct_020b23a8 {
    struct Struct_020b1d70* unknown_0_;
    const Struct_020b1020* unknown_4_;
    int unknown_8_;
    int unknown_c_;
};

struct Struct_020b23a8_2 {
    Type_ov002_0215ab60 x;
    Type_ov002_0215ab60 y;
};

static inline Type_020b23a8 inline_020b23a8(const Struct_020b1020* arg0) {
    return arg0->unknown_4_;
}

// USA: func_020b23a8
extern "C" ARM void func_020b23a8(const Struct_020b23a8* arg0, int x, int y, int arg3, const void* str, const void** arg5, Struct_020b23a8_2 dir) {
    const void* pos;
    int var1;
    const Struct_020b1020* var2;
    u16 c;
    Type_020b23a8 var4;

    var1 = arg0->unknown_8_;
    var2 = arg0->unknown_4_;
    pos = str;
    var4 = inline_020b23a8(var2);

    while ((c = var4((const void**)&pos)) != 0) {
        if (c == '\n') {
            break;
        }

        {
            int w = func_020b1d70(arg0->unknown_0_, (struct Struct_020b1d70_2**)var2, x, y, arg3, c) + var1;
            x += w * dir.x;
            y += w * dir.y;
        }
    }

    if (arg5 != NULL) {
        *arg5 = (c == '\n') ? pos : NULL;
    }
}
