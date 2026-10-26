#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct EquipmentMenu {
    char unk_0[R(0x3d30, 0x3db8)];
    unsigned char state_;
    unsigned char unknown_3db9_;
    unsigned char step_;
    signed char slot_;
    unsigned char kind_;
    signed char page_;
    unsigned char unknown_3dbe_;
    signed char unknown_3dbf_;
    signed char unknown_3dc0_;
    char unknown_3dc1_[0x3dcc - 0x3dc1];
    unsigned int flags_;
    char unknown_3dd0_[0x3df0 - 0x3dd0];
    signed char unknown_3df0_;
    signed char unknown_3df1_;
    signed char unknown_3df2_;
};

extern "C" void func_ov005_021571d0(EquipmentMenu* self);

// USA: func_ov005_0215792c
extern "C" ARM void func_ov005_0215792c(EquipmentMenu* self, unsigned char state) {
    self->unknown_3db9_ = self->state_;
    self->state_ = state;
    self->step_ = 0;
    if (self->state_ == 0) {
        self->unknown_3dbe_ = self->kind_;
        self->flags_ |= 0x400;
    } else {
        self->flags_ &= ~0x400;
    }
    if (self->state_ == 0 && self->unknown_3db9_ == 1) {
        self->unknown_3df0_ = 3;
        self->unknown_3df1_ = 30;
        self->unknown_3df2_ = 30;
        self->flags_ &= ~0x1000;
        self->flags_ &= ~0x2000;
    } else if (self->unknown_3db9_ == 3) {
        self->unknown_3df0_ = 0;
        self->flags_ &= ~0x1000;
    }
    if (self->state_ != 5 && self->state_ != 1 && self->state_ != 7)
        func_ov005_021571d0(self);
}
