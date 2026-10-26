#include <globaldefs.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Struct_020b27c8 {
    unsigned char fontType;
    signed char unknown_1_;
} Struct_020b27c8;

typedef struct Struct_020b1020 {
    Struct_020b27c8* unknown_0_;
} Struct_020b1020;

typedef struct Struct_020b1020_2 {
    int width;
    int height;
} Struct_020b1020_2;

int func_020b0f00(const Struct_020b1020* arg0, int arg1, const void* str, const void** arg3);

static inline int inline_020b1020(const Struct_020b1020* arg0) {
    return arg0->unknown_0_->unknown_1_;
}

// USA: func_020b1020
ARM Struct_020b1020_2 func_020b1020(const Struct_020b1020* arg0, int arg1, int arg2, const void* arg3) {
    int var0 = 1;
    Struct_020b1020_2 rect = {0, 0};

    while (arg3 != NULL) {
        const int width = func_020b0f00(arg0, arg1, arg3, &arg3);
        if (width > rect.width) {
            rect.width = width;
        }
        var0++;
    }

    rect.height = (var0 - 1) * (inline_020b1020(arg0) + arg2) - arg2;

    return rect;
}

#ifdef __cplusplus
}
#endif
