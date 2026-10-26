#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct_ov028_021d98b8 {
    float scale;
    unsigned int unk4;
    unsigned short unknown_8_;
    unsigned short unknown_a_;
};

struct Struct_020979c0 {
    unsigned int data[8];
};

struct Struct_ov028_021d8b90 {
    Struct_ov028_021d98b8 unknown_0_;
    unsigned char unknown_c_[0x10];
    unsigned char unknown_1c_;
    unsigned char unknown_1d_;
    Struct_020979c0 unknown_20_;
    unsigned int unknown_40_;
    SafeAllocator allocator;
    unsigned int unknown_58_;
    unsigned int unknown_5c_;
    unsigned int unknown_60_;
    unsigned int unknown_64_;
    unsigned int unk68;
    unsigned short unknown_6c_;
    unsigned char unknown_6e_;
    int unknown_70_;
    unsigned int unknown_74_;
    unsigned int unknown_78_;
    unsigned int unknown_7c_;
    unsigned char unknown_80_;
    unsigned char unknown_81_;
};

extern "C" void func_020979c0(Struct_020979c0* obj, unsigned char flag);
extern "C" Struct_ov028_021d98b8* func_ov028_021d98b8(Struct_ov028_021d98b8* self);

static inline unsigned int inline_ov017_021a86d0(void) {
    return (*(volatile unsigned int*)0x4000000 & 0x1f00) >> 8;
}

static inline unsigned int inline_ov028_021d8b90(void) {
    return (*(volatile unsigned int*)0x4001000 & 0x1f00) >> 8;
}

// USA: func_ov028_021d8b90
extern "C" ARM void func_ov028_021d8b90(Struct_ov028_021d8b90* self) {
    func_ov028_021d98b8(&self->unknown_0_);
    self->unknown_1c_ = 0;
    self->unknown_1d_ = 0;
    func_020979c0(&self->unknown_20_, 0);
    self->unknown_40_ = 0;
    self->allocator.ResetAllocatorPointer();
    self->unknown_58_ = inline_ov017_021a86d0();
    self->unknown_5c_ = inline_ov028_021d8b90();
    self->unknown_60_ = 0;
    self->unknown_64_ = 0;
    self->unknown_6c_ = 0;
    self->unk68 = 0;
    self->unknown_6e_ = 0;
    self->unknown_70_ = -1;
    self->unknown_74_ = 0;
    self->unknown_78_ = 0;
    self->unknown_7c_ = 0;
    self->unknown_80_ = 0;
    self->unknown_81_ = 0;
}
