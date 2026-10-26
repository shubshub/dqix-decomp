#include <globaldefs.h>

struct Foo0207df50;

extern "C" void VramState_Reserve(void* state, int a, int b);
extern "C" void VramState_Rewind(struct Foo0207df50* p);

struct Struct_ov005_02155d6c {
    char unk_0[0x70];
};

struct EquipmentMenu {
    char unk_0[0x294];
    Struct_ov005_02155d6c vramState_;
    Struct_ov005_02155d6c slotVramStates_[24];
    Struct_ov005_02155d6c dragVramState_;
};

// USA: func_ov005_02153b20
extern "C" ARM void func_ov005_02153b20(EquipmentMenu* self) {
    for (int i = 0; i < 24; i++) {
        VramState_Reserve(&self->slotVramStates_[i], 0x120, 0x20);
        VramState_Rewind((struct Foo0207df50*)&self->slotVramStates_[i]);
    }
    VramState_Reserve(&self->dragVramState_, 0x120, 0x20);
    VramState_Rewind((struct Foo0207df50*)&self->dragVramState_);
    VramState_Reserve(&self->vramState_, 0x3000, 0x400);
    VramState_Rewind((struct Foo0207df50*)&self->vramState_);
}
