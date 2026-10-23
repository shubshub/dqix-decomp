#include <globaldefs.h>

struct Struct_0203d028;

extern "C" void VramState_Reserve(void* state, int a, int b);
void CopyInternalFields0207df50(struct Foo0207df50* p);

struct Struct_ov005_02155d6c {
    char unknown_0_[0x70];
};

struct Struct_ov005_02153954 {
    char unknown_0_[0x294];
    Struct_ov005_02155d6c unknown_294_;
    Struct_ov005_02155d6c unknown_304_[24];
    Struct_ov005_02155d6c unknown_d84_;
};

// USA: func_ov005_02153b20
extern "C" ARM void func_ov005_02153b20(EquipmentMenu* self) {
    for (int i = 0; i < 24; i++) {
        VramState_Reserve(&self->slotVramStates_[i], 0x120, 0x20);
        CopyInternalFields0207df50((struct Foo0207df50*)&self->slotVramStates_[i]);
    }
    VramState_Reserve(&self->dragVramState_, 0x120, 0x20);
    CopyInternalFields0207df50((struct Foo0207df50*)&self->dragVramState_);
    VramState_Reserve(&self->vramState_, 0x3000, 0x400);
    CopyInternalFields0207df50((struct Foo0207df50*)&self->vramState_);
}
