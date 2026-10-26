#include <globaldefs.h>
#include "World/Object3D.h"

struct Struct_02040bcc {
    char pad0[0x14];
    void* field14;
    char pad18[0x18 - 0x14 - 4];
    signed char field18;
    char unknown_19_[0xac - 0x18 - 1];
    unsigned short field_ac;
    char unknown_ae_[0xc4 - 0xac - 2];
    unsigned char field_c4;
    char unknown_c5_[0xcc - 0xc4 - 1];
    void* field_cc;
    int field_d0;
    unsigned char unknown_d4_0_ : 1;
};

// USA: func_02041538
extern "C" ARM void func_02041538(struct Struct_02040bcc* self) {
    if (self->unknown_d4_0_) return;
    self->field_ac &= ~1;
    if (self->field_cc != NULL) {
        if (self->field14 == self->field_cc) return;
        ((Object3D*)self)->SetAnimationByName((char const*)self->field_cc, self->field_d0);
    } else {
        if (self->field_c4 == self->field18) return;
        ((Object3D*)self)->SetAnimationByIndex(self->field_c4, self->field_d0);
    }
}
