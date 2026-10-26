#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"
#include <std_library_functions.h>
#include "Memory/SafeAllocator.h"
#include "Graphics/SpriteAffineTransform.h"

#if defined(jpn)
#include "Resource/CharacterCreationUI.h"

// Overlay 9, originally func_ov009_021842a0 (USA/EUR 0x021842a0, JPN 0x021853a0)
extern "C" ARM void CharacterCreationUI_Allocate(void* scene, SafeAllocator* allocator) {
    CharacterCreationUI* self = (CharacterCreationUI*)scene;
    if (allocator == NULL) return;
    self->allocators[CreationAllocator_MainLayers].CreateTypeA(allocator->Allocate(0x3800), 0x3800);
    self->allocators[CreationAllocator_TabLayers].CreateTypeA(allocator->Allocate(0x2800), 0x2800);
    self->allocators[CreationAllocator_BottomText].CreateTypeA(allocator->Allocate(0x1000), 0x1000);
    self->allocators[CreationAllocator_Characters].CreateTypeA(allocator->Allocate(0x2b240), 0x2b240);
    self->allocators[CreationAllocator_ItemTable].CreateTypeA(allocator->Allocate(0xc00), 0xc00);
    self->allocators[CreationAllocator_Texts].CreateTypeA(allocator->Allocate(0x2000), 0x2000);
    self->allocators[CreationAllocator_Sprites].CreateTypeA(allocator->Allocate(0x400), 0x400);
    self->allocators[CreationAllocator_NameFilter].CreateTypeA(allocator->Allocate(0x800), 0x800);
    self->mainSpriteContext = (SpriteContext0205ac40*)allocator->Allocate(0x54);
    self->mainSprites = (B174Outer*)allocator->Allocate(MainSprites_Count * sizeof(B174Outer));
    self->mainSpriteEntries = (Container0205a3d0*)allocator->Allocate(8);
    self->subSpriteContext = (SpriteContext0205ac40*)allocator->Allocate(0x54);
    self->subSprites = (B174Outer*)allocator->Allocate(SubSprites_Count * sizeof(B174Outer));
    self->subSpriteEntries = (Container0205a3d0*)allocator->Allocate(8);
    if (self->mode != CreationMode_NewGame) return;
    self->modelAllocator = (SafeAllocator*)allocator->Allocate(sizeof(SafeAllocator));
    self->previewAllocators = (SafeAllocator*)allocator->Allocate(2 * sizeof(SafeAllocator));
    self->modelAllocator->ResetAllocatorPointer();
    for (int i = 0; i < 2; ++i) self->previewAllocators[i].ResetAllocatorPointer();
    self->modelAllocator->CreateTypeA(allocator->Allocate(0xc000), 0xc000);
    self->previewAllocators[0].CreateTypeA(allocator->Allocate(0x3000), 0x3000);
    self->previewAllocators[1].CreateTypeA(allocator->Allocate(0x1800), 0x1800);
}
#else
struct Struct0215efb8;
struct KeyboardLayout;

extern "C" void Keyboard_Init(Struct0215efb8* keyboard);
extern "C" void KeyboardLayout_Init(KeyboardLayout* layout);

extern "C" ARM void CharacterCreationUI_Allocate(CharacterCreationUI* self, SafeAllocator* allocator)
{
    if (allocator == NULL)
        return;

    self->allocators[CreationAllocator_MainLayers].CreateTypeA(allocator->Allocate(0x3800), 0x3800);
    self->allocators[CreationAllocator_TabLayers].CreateTypeA(allocator->Allocate(0x3400), 0x3400);
    self->allocators[CreationAllocator_BottomText].CreateTypeA(allocator->Allocate(0x1000), 0x1000);
    self->allocators[CreationAllocator_Characters].CreateTypeA(allocator->Allocate(0x2b240), 0x2b240);
    self->allocators[CreationAllocator_ItemTable].CreateTypeA(allocator->Allocate(0xc00), 0xc00);
    self->allocators[CreationAllocator_Texts].CreateTypeA(allocator->Allocate(0x2000), 0x2000);
    self->allocators[CreationAllocator_Sprites].CreateTypeA(allocator->Allocate(0x400), 0x400);
    self->allocators[CreationAllocator_NameFilter].CreateTypeA(allocator->Allocate(0x800), 0x800);
    self->allocators[CreationAllocator_KeyboardLayout].CreateTypeA(allocator->Allocate(0x1800), 0x1800);
    self->names = (char**)allocator->Allocate(2 * sizeof(char*));
    for (int i = 0; i < 2; i++)
    {
        self->names[i] = (char*)allocator->Allocate(CreationName_BufferSize);
        memset(self->names[i], 0, CreationName_BufferSize);
    }
    self->keyboard = (Keyboard*)allocator->Allocate(0x28);
    self->keyboardLayout = allocator->Allocate(0x10);
    Keyboard_Init((Struct0215efb8*)self->keyboard);
    KeyboardLayout_Init((KeyboardLayout*)self->keyboardLayout);
    self->mainSpriteContext = (SpriteContext0205ac40*)allocator->Allocate(0x54);
    self->mainSprites = (B174Outer*)allocator->Allocate(MainSprites_Count * sizeof(B174Outer));
    self->mainSpriteEntries = (Container0205a3d0*)allocator->Allocate(8);
    self->subSpriteContext = (SpriteContext0205ac40*)allocator->Allocate(0x54);
    self->subSprites = (B174Outer*)allocator->Allocate(SubSprites_Count * sizeof(B174Outer));
    self->subSpriteEntries = (Container0205a3d0*)allocator->Allocate(8);
    if (self->mode != CreationMode_NewGame)
        return;

    self->modelAllocator = (SafeAllocator*)allocator->Allocate(sizeof(SafeAllocator));
    self->previewAllocators = (SafeAllocator*)allocator->Allocate(2 * sizeof(SafeAllocator));
    self->modelAllocator->ResetAllocatorPointer();
    for (int i = 0; i < 2; i++)
        self->previewAllocators[i].ResetAllocatorPointer();
    self->modelAllocator->CreateTypeA(allocator->Allocate(0xc000), 0xc000);
    self->previewAllocators[0].CreateTypeA(allocator->Allocate(0x3000), 0x3000);
    self->previewAllocators[1].CreateTypeA(allocator->Allocate(0x1800), 0x1800);
}
#endif
