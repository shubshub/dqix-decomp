#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"
#include <std_library_functions.h>
#include "Memory/SafeAllocator.h"

#if defined(jpn)
#include "Resource/CharacterCreationUI.h"

extern "C" ARM void func_ov009_021842a0(void* scene, SafeAllocator* allocator) {
    CharacterCreationUI* self = (CharacterCreationUI*)scene;
    if (allocator == NULL) return;
    self->allocators[0].CreateTypeA(allocator->Allocate(0x3800), 0x3800);
    self->allocators[1].CreateTypeA(allocator->Allocate(0x2800), 0x2800);
    self->allocators[2].CreateTypeA(allocator->Allocate(0x1000), 0x1000);
    self->allocators[3].CreateTypeA(allocator->Allocate(0x2b240), 0x2b240);
    self->allocators[4].CreateTypeA(allocator->Allocate(0xc00), 0xc00);
    self->allocators[5].CreateTypeA(allocator->Allocate(0x2000), 0x2000);
    self->allocators[6].CreateTypeA(allocator->Allocate(0x400), 0x400);
    self->allocators[7].CreateTypeA(allocator->Allocate(0x800), 0x800);
    self->firstSpriteContext = (SpriteContext0205ac40*)allocator->Allocate(0x54);
    self->firstSprites = (B174Outer*)allocator->Allocate(0xf0);
    self->firstSpriteEntries = (Container0205a3d0*)allocator->Allocate(8);
    self->spriteContext = (SpriteContext0205ac40*)allocator->Allocate(0x54);
    self->sprites = (B174Outer*)allocator->Allocate(0x3e8);
    self->spriteEntries = (Container0205a3d0*)allocator->Allocate(8);
    if (self->mode != CreationMode_NewGame) return;
    self->modelAllocator = (SafeAllocator*)allocator->Allocate(0x14);
    self->previewAllocators = (SafeAllocator*)allocator->Allocate(0x28);
    self->modelAllocator->ResetAllocatorPointer();
    for (int i = 0; i < 2; ++i) self->previewAllocators[i].ResetAllocatorPointer();
    self->modelAllocator->CreateTypeA(allocator->Allocate(0xc000), 0xc000);
    self->previewAllocators[0].CreateTypeA(allocator->Allocate(0x3000), 0x3000);
    self->previewAllocators[1].CreateTypeA(allocator->Allocate(0x1800), 0x1800);
}
#else
struct Struct_ov003_0215efb8;
struct Struct_ov003_0215e6d8;

extern "C" void func_ov003_0215efb8(Struct_ov003_0215efb8* arg0);
extern "C" void func_ov003_0215e6d8(Struct_ov003_0215e6d8* arg0);

struct Struct_ov009_021842a0_2 {
    SafeAllocator unknown_0_[9];
    SafeAllocator* unknown_b4_;
    SafeAllocator* unknown_b8_;
    void* unknown_bc_;
    Struct_ov003_0215efb8* unknown_c0_;
    Struct_ov003_0215e6d8* unknown_c4_;
    char unknown_c8_[0x7d8 - 0xc8];
    void* unknown_7d8_;
    void* unknown_7dc_;
    void* unknown_7e0_;
    void* unknown_7e4_;
    void* unknown_7e8_;
    void* unknown_7ec_;
    char unknown_7f0_[0xd95 - 0x7f0];
    unsigned char unknown_d95_;
    char unknown_d96_[0xdb0 - 0xd96];
    char** unknown_db0_;
};

// USA: func_ov009_021842a0
extern "C" ARM void func_ov009_021842a0(Struct_ov009_021842a0_2* arg0, SafeAllocator* arg1)
{
    if (arg1 == NULL)
        return;

    arg0->unknown_0_[0].CreateTypeA(arg1->Allocate(0x3800), 0x3800);
    arg0->unknown_0_[1].CreateTypeA(arg1->Allocate(0x3400), 0x3400);
    arg0->unknown_0_[2].CreateTypeA(arg1->Allocate(0x1000), 0x1000);
    arg0->unknown_0_[3].CreateTypeA(arg1->Allocate(0x2b240), 0x2b240);
    arg0->unknown_0_[4].CreateTypeA(arg1->Allocate(0xc00), 0xc00);
    arg0->unknown_0_[5].CreateTypeA(arg1->Allocate(0x2000), 0x2000);
    arg0->unknown_0_[6].CreateTypeA(arg1->Allocate(0x400), 0x400);
    arg0->unknown_0_[7].CreateTypeA(arg1->Allocate(0x800), 0x800);
    arg0->unknown_0_[8].CreateTypeA(arg1->Allocate(0x1800), 0x1800);
    arg0->unknown_db0_ = (char**)arg1->Allocate(8);
    for (int var2 = 0; var2 < 2; var2++)
    {
        arg0->unknown_db0_[var2] = (char*)arg1->Allocate(0x48);
        memset(arg0->unknown_db0_[var2], 0, 0x48);
    }
    self->keyboard_ = (Struct0215efb8*)allocator->Allocate(0x28);
    self->layout_ = (ResetLayout_0215e6d8*)allocator->Allocate(0x10);
    InitStruct0215efb8(self->keyboard_);
    ResetStruct_0215e6d8(self->layout_);
    self->renderer_ = allocator->Allocate(0x54);
    self->sprites_ = allocator->Allocate(0xf0);
    self->unk_7e0 = allocator->Allocate(8);
    self->renderer2_ = allocator->Allocate(0x54);
    self->sprites2_ = allocator->Allocate(0x3e8);
    self->unk_7ec = allocator->Allocate(8);
    if (self->mode_ != CreationMode_NewGame)
        return;

    arg0->unknown_b4_ = (SafeAllocator*)arg1->Allocate(0x14);
    arg0->unknown_b8_ = (SafeAllocator*)arg1->Allocate(0x28);
    arg0->unknown_b4_->ResetAllocatorPointer();
    for (int var3 = 0; var3 < 2; var3++)
        arg0->unknown_b8_[var3].ResetAllocatorPointer();
    arg0->unknown_b4_->CreateTypeA(arg1->Allocate(0xc000), 0xc000);
    arg0->unknown_b8_[0].CreateTypeA(arg1->Allocate(0x3000), 0x3000);
    arg0->unknown_b8_[1].CreateTypeA(arg1->Allocate(0x1800), 0x1800);
}
#endif
