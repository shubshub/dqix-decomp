#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"
#include "Memory/SafeAllocator.h"

void* GlobalFlags_GetInstance(void);
struct FlagWord020466f4;
void FlagWord_ClearBits(struct FlagWord020466f4* word, unsigned int mask);
void CharacterModel_Destroy(void* obj);
int MessageSystem_GetInstance();
struct CombatSlots02045cac;
void MessageSystem_ResetGlyphs(struct CombatSlots02045cac* obj);
void MessageSystem_Reset(char* obj);
extern "C" void MessageSystem_Stop(char* obj);
void SpriteContext_Destroy(void* obj);
void* CachedTextTable_GetInstance();
void CachedTextTable_Reset(char* obj);
struct BackgroundGraphics;
void Background_ClearMap(BackgroundGraphics* obj, void* p);
extern "C" void Background_FlushMap(void* p, int flag);
extern "C" void Background_TransferMap(void* p, int flag);
void Background_Destroy(struct BackgroundGraphics* obj);
extern "C" void Window_Destroy(CreationWindow* window); // resets the window's panes and layers
extern "C" void* __clear(void* dst, int count);

// Overlay 9, originally func_ov009_02184848 (USA/EUR 0x02184848, JPN 0x021858e4)
extern "C" ARM void CharacterCreationUI_Destroy(CharacterCreationUI* self) {
    if (self->mode == CreationMode_PartyMemberCreation) {
        FlagWord_ClearBits((struct FlagWord020466f4*)GlobalFlags_GetInstance(), 0xf);
    }
    CharacterModel_Destroy(self->characterModels[0]);
    CharacterModel_Destroy(self->characterModels[1]);
    void* messageSystem = (void*)MessageSystem_GetInstance();
    MessageSystem_ResetGlyphs((struct CombatSlots02045cac*)messageSystem);
    MessageSystem_Reset((char*)messageSystem);
    MessageSystem_Stop((char*)messageSystem);
    if (self->mainSpriteContext != 0) {
        SpriteContext_Destroy(self->mainSpriteContext);
    }
    if (self->subSpriteContext != 0) {
        SpriteContext_Destroy(self->subSpriteContext);
    }
    CachedTextTable_Reset((char*)CachedTextTable_GetInstance());
    {
        void* layers[6];
        layers[0] = &self->layers[0];
        layers[1] = &self->layers[1];
        layers[2] = &self->layers[2];
        layers[3] = &self->layers[3];
        layers[4] = &self->layers[4];
        layers[5] = &self->layers[5];
        for (int i = 0; i < 6; i++) {
            void* layer = layers[i];
            Background_ClearMap((BackgroundGraphics*)layer, 0);
            Background_FlushMap(layer, 0);
            Background_TransferMap(layer, 0);
            Background_Destroy((struct BackgroundGraphics*)layer);
        }
    }
    Window_Destroy(&self->windows[CreationWindowIndex_Summary]);
    Window_Destroy(&self->windows[CreationWindowIndex_Bottom]);
    *(int*)&self->textBuffer = 0;
    *(int*)&self->windowBuffers[0] = 0;
    *(int*)&self->windowBuffers[1] = 0;
    if (self->previewAllocators != 0) {
        self->previewAllocators[0].Destroy();
        self->previewAllocators[1].Destroy();
    }
    if (self->modelAllocator != 0) {
        self->modelAllocator->Destroy();
    }
#if defined(jpn)
    SafeAllocator* allocators[9];
#else
    SafeAllocator* allocators[10];
#endif
    __clear(allocators, sizeof(allocators));
#if defined(jpn)
    allocators[0] = &self->allocators[CreationAllocator_NameFilter];
    allocators[1] = &self->allocators[CreationAllocator_Sprites];
    allocators[2] = &self->allocators[CreationAllocator_Texts];
    allocators[3] = &self->allocators[CreationAllocator_ItemTable];
    allocators[4] = &self->allocators[CreationAllocator_Characters];
    allocators[5] = &self->allocators[CreationAllocator_BottomText];
    allocators[6] = &self->allocators[CreationAllocator_TabLayers];
    allocators[7] = &self->allocators[CreationAllocator_MainLayers];
#else
    allocators[0] = &self->allocators[CreationAllocator_KeyboardLayout];
    allocators[1] = &self->allocators[CreationAllocator_NameFilter];
    allocators[2] = &self->allocators[CreationAllocator_Sprites];
    allocators[3] = &self->allocators[CreationAllocator_Texts];
    allocators[4] = &self->allocators[CreationAllocator_ItemTable];
    allocators[5] = &self->allocators[CreationAllocator_Characters];
    allocators[6] = &self->allocators[CreationAllocator_BottomText];
    allocators[7] = &self->allocators[CreationAllocator_TabLayers];
    allocators[8] = &self->allocators[CreationAllocator_MainLayers];
#endif
    int i = 0;
    while (allocators[i] != 0) {
        if (allocators[i]->GetSignedAllocator() != 0) {
            allocators[i]->Destroy();
        }
        i++;
    }
}
