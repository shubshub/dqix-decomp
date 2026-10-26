#include <globaldefs.h>

struct Struct_02094b9c_2 {
    char unknown_0_[0x08];
    int unknown_8_[3];
    int unknown_14_[3];
    char unknown_20_[0x02];
    short unknown_22_;
    int unknown_24_;
    int unknown_28_;
};

struct Struct_02094b9c {
    int unknown_0_[6];
};

struct Struct_02032148 {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
    int unknown_c_;
    int unknown_10_;
};

extern "C" ARM int Bounds3D_ContainsPointRotated(void* anchor, struct Bounds02094b9c* b, short d, int* pos, int e);
extern "C" ARM int func_02032148(void* anchor, struct Shape02094b9c* s, int e);

// USA: func_02094b9c
extern "C" ARM int func_02094b9c(struct Struct_02094b9c_2* arg0, void* arg1) {
    if (arg0->unknown_28_ & 8) {
        return 0;
    }

    struct Struct_02094b9c var0;
    struct Struct_02032148 var1;
    struct Struct_02094b9c var2;

    var2.unknown_0_[0] = arg0->unknown_8_[0] + (arg0->unknown_14_[0] >> 1);
    var2.unknown_0_[1] = arg0->unknown_8_[1] + (arg0->unknown_14_[1] >> 1);
    var2.unknown_0_[2] = arg0->unknown_8_[2] + (arg0->unknown_14_[2] >> 1);
    var2.unknown_0_[3] = arg0->unknown_8_[0] - (arg0->unknown_14_[0] >> 1);
    var2.unknown_0_[4] = arg0->unknown_8_[1] - (arg0->unknown_14_[1] >> 1);
    var2.unknown_0_[5] = arg0->unknown_8_[2] - (arg0->unknown_14_[2] >> 1);

    var0 = var2;

    int result = 0;
    int ret;
    int hasSize = p->size[2] > 0;
    if (hasSize) {
        ret = Bounds3D_ContainsPointRotated(anchor, &b, p->f22, &p->pos[0], p->f24);
    } else {
        var1.unknown_0_ = arg0->unknown_8_[0];
        var1.unknown_4_ = arg0->unknown_8_[1];
        var1.unknown_8_ = arg0->unknown_8_[2];
        var1.unknown_c_ = arg0->unknown_14_[0];
        var1.unknown_10_ = arg0->unknown_14_[1];
        var4 = func_02032148(arg1, &var1, var1.unknown_10_);
    }
    if (var4) {
        var3 = 1;
    }

    int var6 = arg0->unknown_28_;
    if (var3 != 0) {
        if (var6 & 1) {
            if (var6 & 4) {
                var3 = 0;
            } else {
                arg0->unknown_28_ = var6 | 2;
            }
        }
    } else {
        if (var6 & 1) {
            if (var6 & 2) {
                arg0->unknown_28_ = var6 | 4;
            }
        }
    }
    return var3;
}