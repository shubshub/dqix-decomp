#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"

struct BackgroundGraphics;
extern "C" void Background_Init(BackgroundGraphics* obj);

struct Struct_ov003_02173c40 {
    int field0;
    class SafeAllocator unknown_4_;
    class SafeAllocator unknown_18_;
    class SafeAllocator unknown_2c_;
    unsigned char list40[0x20];
    unsigned char list60[0x20];
    unsigned char unknown_80_[0xac];
    unsigned char unknown_12c_;
    signed char unknown_12d_;
    int unknown_130_;
    int unknown_134_;
    int unknown_138_;
    int unknown_13c_;
    unsigned char b140;
    unsigned char unknown_141_;
    unsigned char unknown_142_;
    unsigned char unknown_143_;
    unsigned char unknown_144_[0x160 - 0x144];
    int unknown_160_;
};

// USA: func_ov003_0217bcb8
extern "C" ARM void func_ov003_0217bcb8(Struct_ov003_02173c40* self) {
    self->field0 = 0;
    self->unknown_4_.ResetAllocatorPointer();
    self->unknown_18_.ResetAllocatorPointer();
    self->unknown_2c_.ResetAllocatorPointer();
    Background_Init((BackgroundGraphics*)self->list40);
    Background_Init((BackgroundGraphics*)self->list60);
    ((Object3D*)self->unknown_80_)->Initialize();
    self->unknown_12c_ = 0;
    int var0 = self->unknown_12c_ - 1;
    self->unknown_12d_ = var0;
    self->unknown_130_ = var0;
    self->unknown_134_ = var0;
    self->unknown_138_ = var0;
    self->unknown_13c_ = var0;
    self->b140 = 0;
    self->unknown_141_ = 0;
    self->unknown_143_ = 0;
    self->unknown_142_ = 0;
    self->unknown_160_ = 0;
    *(short*)((char*)self + 0x15c) = 0;
}
