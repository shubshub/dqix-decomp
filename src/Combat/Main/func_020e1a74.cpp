#include <globaldefs.h>

struct Struct_020439b0;
extern "C" ARM void func_020e2cc4(struct Struct_020439b0*, int);

struct Struct_020e13dc;
extern "C" ARM void func_020e13dc(struct Struct_020e13dc*);

extern "C" ARM void func_020e2d4c(unsigned char*, unsigned char);

struct Struct_020439b0_3;
extern "C" ARM void func_020e2d2c(struct Struct_020439b0_3*, int, int, int, int);

struct Struct_020439b0_4;
extern "C" ARM void func_020e2c34(struct Struct_020439b0_4*);

struct Struct_020e1a74 {
    unsigned char pad[0x38];
    unsigned char unknown_38_;
    unsigned char unknown_39_;
    unsigned char unknown_3a_;
    unsigned char unknown_3b_;
    unsigned char unknown_3c_[2];
    unsigned char unknown_3e_;
    union {
        unsigned char unknown_3f_;
        struct {
            unsigned char bit0 : 1;
            unsigned char unknown_3f_1_ : 1;
        };
    };
};

struct Struct_020e1a74_2 {
    char pad0[4];
    struct Struct_020e1a74* target;
};

// USA: func_020e1a74
extern "C" ARM void func_020e1a74(struct Struct_020e1a74_2* self) {
    if (self->target == 0) return;
    if (self->target->unknown_3f_1_) {
        func_020e2cc4((struct Struct_020439b0*)((char*)self + 0x28), 0);
        func_020e13dc((struct Struct_020e13dc*)((char*)self->target + 0xc));
        self->target->unknown_3f_ &= ~2;
    }
    if (self->target->bit0) {
        func_020e2d4c((unsigned char*)((char*)self + 0x28), self->target->unknown_3e_);
        int a = self->target->unknown_38_ + 2;
        int b = self->target->unknown_39_ + 2;
        int c = self->target->unknown_3a_ - 4;
        int d = self->target->unknown_3b_ - 4;
        func_020e2d2c((struct Struct_020439b0_3*)((char*)self + 0x28), a, b, c, d);
        func_020e2c34((struct Struct_020439b0_4*)((char*)self + 0x28));
    }
}
