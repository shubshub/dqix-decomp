#include "Combat/MenuNodeChain.h"
#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov006_02154348_1948 = 0x718, Enum_ov006_02154348_76 = 0x48, Enum_ov006_02154348_64 = 0x34 };
#else
enum { Enum_ov006_02154348_1948 = 0x79c, Enum_ov006_02154348_76 = 0x4c, Enum_ov006_02154348_64 = 0x40 };
#endif

#include "Memory/SafeAllocator.h"

struct Struct_ov006_02154348 {
#if !defined(jpn)
    char unknown_0_[0x180];
#endif
    SafeAllocator* allocators;
    SafeAllocator* unknown_184_;
    SafeAllocator* unknown_188_;
    char unknown_18c_[0x38];
    unsigned char* unknown_1c4_;
    void* unknown_1c8_;
    char (*pairBuffer)[0x20];
    char (*singleBuffer)[0xe0];
    Manager0207f7f0* unknown_1d4_;
    char unknown_1d8_[8];
    char (*entryBuffer)[0x28];
    char unknown_1e4_[0x8a0];
    SafeAllocator unknown_a84_[4];
    char unknown_ad4_[0x10];
    char unknown_ae4_[Enum_ov006_02154348_1948];
    SafeAllocator* unknown_1280_;
    SafeAllocator* unknown_1284_;
};
extern "C" {
extern unsigned int data_ov006_0215ff7c[];
void func_ov023_021dbfd0(void*, SafeAllocator*);
extern "C" void func_ov023_021dbfa8(void*, void*);
extern "C" void func_ov023_021e20c0(void*);
extern "C" void Background_Init(void*);
void WindowPane_Init(void*);
extern "C" void Sprite_Init(void*);
}
// USA: func_ov006_02154348
extern "C" ARM void func_ov006_02154348(Struct_ov006_02154348* state, SafeAllocator* allocator, void* context)
{
    state->allocators = (SafeAllocator*)allocator->Allocate(0x78);
    state->unknown_184_ = (SafeAllocator*)allocator->Allocate(0x14);
    state->unknown_188_ = (SafeAllocator*)allocator->Allocate(0x14);
    state->unknown_1c4_ = (unsigned char*)allocator->Allocate(0x80);
    state->unknown_1c8_ = allocator->Allocate(Enum_ov006_02154348_76);
    state->pairBuffer = (char (*)[0x20])allocator->Allocate(0x40);
    state->singleBuffer = (char (*)[0xe0])allocator->Allocate(0xe0);
    state->unknown_1d4_ = static_cast<Manager0207f7f0*>(allocator->Allocate(Enum_ov006_02154348_64));
    state->entryBuffer = (char (*)[0x28])allocator->Allocate(0x2a8);
    state->unknown_184_->CreateTypeA(allocator->Allocate(0x258), 0x258);
    state->unknown_188_->CreateTypeA(allocator->Allocate(0x258), 0x258);
    state->unknown_184_->Reset();
    state->unknown_188_->Reset();
    state->unknown_1280_ = (SafeAllocator*)allocator->Allocate(0x14);
    state->unknown_1284_ = (SafeAllocator*)allocator->Allocate(0x14);
    state->unknown_1280_->CreateTypeA(allocator->Allocate(0x1e00), 0x1e00);
    state->unknown_1280_->Reset();
    state->unknown_1284_->CreateTypeA(allocator->Allocate(0x80), 0x80);
    state->unknown_1284_->Reset();
    func_ov023_021dbfd0(state->unknown_ae4_, state->unknown_1280_);
    func_ov023_021dbfa8(state->unknown_ae4_, context);
    for (unsigned char index = 0; index < 6; index++) {
        unsigned int size = data_ov006_0215ff7c[index];
        state->allocators[index].CreateTypeA(allocator->Allocate(size), size);
        state->allocators[index].Reset();
    }
    for (unsigned char index = 0; index < 4; index++) {
        state->unknown_a84_[index].CreateTypeA(allocator->Allocate(0x280), 0x280);
        state->unknown_a84_[index].Reset();
    }
    state->unknown_1c4_[0] = 0;
    func_ov023_021e20c0(state->unknown_1c8_);
    for (unsigned char index = 0; index < 2; index++) Background_Init(state->pairBuffer[index]);
    for (unsigned char index = 0; index < 1; index++) WindowPane_Init(state->singleBuffer[index]);
    func_0207f84c(state->unknown_1d4_);
    for (unsigned char index = 0; index < 17; index++) Sprite_Init(state->entryBuffer[index]);
}
