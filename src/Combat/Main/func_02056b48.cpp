#include <globaldefs.h>

extern "C" void Mat4x3_WriteIdentity(void* mtx);

struct Struct_02056b48 {
    unsigned char unknown_0_[0x04];
    int f04;
    int f08;
    unsigned char unknown_c_[0x04];
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    unsigned char unknown_28_[0x10];
    unsigned char unknown_38_;
    unsigned char unknown_39_[0x03];
    unsigned short f3c;
    unsigned char unknown_3e_[0x0e];
    int unknown_4c_;
    int unknown_50_;
    int unknown_54_;
    int unknown_58_;
    unsigned short unknown_5c_;
    unsigned short unknown_5e_;
    unsigned short f60;
    unsigned short unknown_62_;
    int f64[3];
    int unknown_70_[3];
    int f7c[3];
    unsigned short unknown_88_[3];
    unsigned short unknown_8e_[3];
    unsigned short unknown_94_[3];
    int f9c;
    unsigned short unknown_a0_;
    unsigned char unknown_a2_[0x02];
    int unknown_a4_[3];
    int unknown_b0_[3];
    unsigned short unknown_bc_[3];
    unsigned short unknown_c2_;
    unsigned char unknown_c4_[0x24];
    unsigned int mtx[12];
    int unknown_118_;
    int unknown_11c_;
    int unknown_120_;
    int unknown_124_;
    int f128[3];
    int unknown_134_[3];
    int unknown_140_[3];
    unsigned char unknown_14c_[0x04];
    int f150;
    unsigned char unknown_154_[0x04];
    int unknown_158_[3];
    int unknown_164_[3];
};

// USA: func_02056b48
extern "C" ARM void func_02056b48(struct Struct_02056b48* p) {
    p->unknown_38_ = 0;
    p->f04 = 0;
    p->f08 = 0;
    p->f10 = 0;
    p->f14 = 0;
    p->f18 = 0;
    p->f1c = 0;
    p->f20 = 0;
    p->f24 = 0;
    p->f3c = 0;
    p->unknown_4c_ = 0;
    p->unknown_50_ = 0;
    p->unknown_54_ = 0;
    p->unknown_58_ = 0;
    p->unknown_118_ = 0;
    p->unknown_11c_ = 0;
    p->unknown_120_ = 0;
    p->unknown_124_ = 0;
    p->unknown_5c_ = 0;
    p->unknown_5e_ = 0;
    p->f60 = 0;
    p->unknown_62_ = 0;
    p->f9c = 0;
    p->unknown_a0_ = 0;
    p->f150 = 0;

    for (int i = 0; i < 3; i++) {
        p->f128[i] = 0;
        p->unknown_134_[i] = 0;
        p->unknown_140_[i] = 0;
        p->f64[i] = 0;
        p->unknown_70_[i] = 0;
        p->f7c[i] = 0;
        p->unknown_88_[i] = 0;
        p->unknown_8e_[i] = 0;
        p->unknown_94_[i] = 0;
    }

    for (int i = 0; i < 3; i++) {
        p->unknown_158_[i] = 0;
        p->unknown_164_[i] = 0;
        p->unknown_a4_[i] = 0;
        p->unknown_b0_[i] = 0;
        p->unknown_bc_[i] = 0;
    }

    p->unknown_c2_ = 0;
    Mat4x3_WriteIdentity(&p->mtx);
}