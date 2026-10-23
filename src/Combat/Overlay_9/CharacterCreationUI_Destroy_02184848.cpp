#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"
#include "Memory/SafeAllocator.h"

void* GetDataPtr02114e04_020d6c00(void);
struct FlagWord020466f4;
void ClearFlags020466f4(struct FlagWord020466f4* word, unsigned int mask);
void CharacterModel_Destroy(void* obj);
int GetGlobalField0x1c020421a0();
struct CombatSlots02045cac;
void InitCombatSlots02045cac(struct CombatSlots02045cac* obj);
void ReinitController02043204(char* obj);
extern "C" void func_02043124(char* obj);
void EmptyDestructor0205a494(void* obj);
void* GetGlobalPtr02105244_0203bd14();
void ResetBattleObject0203c4c4(char* obj);
struct Obj0204b010;
void Background_ClearMap(Obj0204b010* obj, void* p);
extern "C" void Background_FlushMap(void* p, int flag);
extern "C" void Background_TransferMap(void* p, int flag);
struct List0204afb4;
void ResetRecordList0204afb4(struct List0204afb4* obj);
struct Obj0205d048;
extern "C" void func_0205d048(struct Obj0205d048* obj);
extern "C" void* __clear(void* dst, int count);

// Overlay 9, originally func_ov009_02184848 (USA/EUR 0x02184848, JPN 0x021858e4)
extern "C" ARM void CharacterCreationUI_Destroy(CharacterCreationUI* self) {
    if (self->mode == CreationMode_PartyMemberCreation) {
        ClearFlags020466f4((struct FlagWord020466f4*)GetDataPtr02114e04_020d6c00(), 0xf);
    }
    CharacterModel_Destroy(self->characterModels[0]);
    CharacterModel_Destroy(self->characterModels[1]);
    void* messageSystem = (void*)GetGlobalField0x1c020421a0();
    InitCombatSlots02045cac((struct CombatSlots02045cac*)messageSystem);
    ReinitController02043204((char*)messageSystem);
    func_02043124((char*)messageSystem);
    if (self->mainSpriteContext != 0) {
        EmptyDestructor0205a494(self->mainSpriteContext);
    }
    if (self->subSpriteContext != 0) {
        EmptyDestructor0205a494(self->subSpriteContext);
    }
    ResetBattleObject0203c4c4((char*)GetGlobalPtr02105244_0203bd14());
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
            Background_ClearMap((Obj0204b010*)layer, 0);
            Background_FlushMap(layer, 0);
            Background_TransferMap(layer, 0);
            ResetRecordList0204afb4((struct List0204afb4*)layer);
        }
    }
    func_0205d048((struct Obj0205d048*)&self->windows[0]);
    func_0205d048((struct Obj0205d048*)&self->windows[1]);
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
    allocators[0] = &self->allocators[7];
    allocators[1] = &self->allocators[6];
    allocators[2] = &self->allocators[5];
    allocators[3] = &self->allocators[4];
    allocators[4] = &self->allocators[3];
    allocators[5] = &self->allocators[2];
    allocators[6] = &self->allocators[1];
    allocators[7] = &self->allocators[0];
#else
    allocators[0] = &self->allocators[8];
    allocators[1] = &self->allocators[7];
    allocators[2] = &self->allocators[6];
    allocators[3] = &self->allocators[5];
    allocators[4] = &self->allocators[4];
    allocators[5] = &self->allocators[3];
    allocators[6] = &self->allocators[2];
    allocators[7] = &self->allocators[1];
    allocators[8] = &self->allocators[0];
#endif
    int i = 0;
    while (allocators[i] != 0) {
        if (allocators[i]->GetSignedAllocator() != 0) {
            allocators[i]->Destroy();
        }
        i++;
    }
}
