#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"
#include <std_library_functions.h>
#include "Memory/SafeAllocator.h"

#if defined(jpn)
#include "Resource/CharacterCreationUI.h"

// Overlay 9, originally func_ov009_021842a0 (USA/EUR 0x021842a0, JPN 0x021853a0)
extern "C" ARM void CharacterCreationUI_Allocate(void* scene, SafeAllocator* allocator) {
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
    self->mainSpriteContext = (SpriteContext0205ac40*)allocator->Allocate(0x54);
    self->mainSprites = (B174Outer*)allocator->Allocate(0xf0);
    self->mainSpriteEntries = (Container0205a3d0*)allocator->Allocate(8);
    self->subSpriteContext = (SpriteContext0205ac40*)allocator->Allocate(0x54);
    self->subSprites = (B174Outer*)allocator->Allocate(0x3e8);
    self->subSpriteEntries = (Container0205a3d0*)allocator->Allocate(8);
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

void Keyboard_Init(Struct0215efb8* keyboard);
void KeyboardLayout_Init(ResetLayout_0215e6d8* layout);

struct CharacterCreation {
    SafeAllocator allocators_[9];
    SafeAllocator* modelAllocator_;
    SafeAllocator* previewAllocators_;
    void* savedKey_;
    Struct0215efb8* keyboard_;
    ResetLayout_0215e6d8* keyboardLayout_;
    char unk_c8[0x7d8 - 0xc8];
    void* mainSpriteContext_;
    void* mainSprites_;
    void* mainSpriteEntries_;
    void* subSpriteContext_;
    void* subSprites_;
    void* subSpriteEntries_;
    char unk_7f0[0xd95 - 0x7f0];
    unsigned char mode_;
    char unk_d96[0xdb0 - 0xd96];
    char** names_;
};

extern "C" ARM void CharacterCreationUI_Allocate(CharacterCreation* self, SafeAllocator* allocator)
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
        self->names_[i] = (char*)allocator->Allocate(CreationName_BufferSize);
        memset(self->names_[i], 0, CreationName_BufferSize);
    }
    self->keyboard_ = (Struct0215efb8*)allocator->Allocate(0x28);
    self->keyboardLayout_ = (ResetLayout_0215e6d8*)allocator->Allocate(0x10);
    Keyboard_Init(self->keyboard_);
    KeyboardLayout_Init(self->keyboardLayout_);
    self->mainSpriteContext_ = allocator->Allocate(0x54);
    self->mainSprites_ = allocator->Allocate(0xf0);
    self->mainSpriteEntries_ = allocator->Allocate(8);
    self->subSpriteContext_ = allocator->Allocate(0x54);
    self->subSprites_ = allocator->Allocate(0x3e8);
    self->subSpriteEntries_ = allocator->Allocate(8);
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
