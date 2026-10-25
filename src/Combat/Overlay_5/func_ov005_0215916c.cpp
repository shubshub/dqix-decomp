#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>

struct Struct_ov005_02153ba4 {
    short unknown_0_;
    char unknown_2_[0x1c - 2];
};

struct Struct_ov005_02153954 {
    char unknown_0_[LOW_REGION(0x2d08, 0x2d90)];
    Struct_ov005_02153ba4 unknown_2d90_[24];
    char unknown_3030_[LOW_REGION(0x3d33 - 0x2fa8, 0x3dbb - 0x3030)];
    signed char unknown_3dbb_;
    char unknown_3dbc_[LOW_REGION(0x3d54 - 0x3d34, 0x3ddc - 0x3dbc)];
    unsigned char unknown_3ddc_;
    unsigned char unknown_3ddd_;
    signed char unknown_3dde_;
    unsigned char unknown_3ddf_;
};

extern "C" void EquipMenu_EquipItem(EquipmentMenu* self, int item, int keep);

// USA: func_ov005_0215916c
extern "C" ARM void
#if defined(jpn)
func_ov005_0215a688
#else
func_ov005_0215916c
#endif
(EquipmentMenu* self) {
    if (self->menuStep_ == 0) {
        if (self->slot_ >= 0 && self->slot_ < 8)
            EquipMenu_EquipItem(self, 0xffff, 0);
        else if (self->slot_ >= 8 && self->slot_ < 24)
            EquipMenu_EquipItem(self, self->slots_[self->slot_].item_, 0);
        self->menuStep_++;
    } else if (self->menuStep_ == 1) {
        self->menuState_ = 4;
        self->menuStep_ = 0;
    }
}
