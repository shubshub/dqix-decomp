#include <globaldefs.h>

struct Struct_ov028_021d98b8 {
    float scale;
    unsigned int unk4;
    unsigned short unknown_8_;
    unsigned short unknown_a_;
};

// USA: func_ov028_021d98b8
extern "C" ARM Struct_ov028_021d98b8* func_ov028_021d98b8(Struct_ov028_021d98b8* self) {
    self->unk4 = 0;
    self->unknown_8_ = 0;
    self->unknown_a_ = 0;
    self->scale = 1.0f;
    return self;
}
