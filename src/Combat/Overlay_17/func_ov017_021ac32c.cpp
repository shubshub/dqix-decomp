#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "GameState/GameState.h"

extern "C" void FontBankLoader_CancelLoads(void);
int MessageSystem_GetInstance(void);
void MessageSystem_Reset(char* obj);
extern "C" void MessageSystem_Stop(void* self);
int FontBankLoader_GetInstance(void);
void GameObject_EnableControl(void* obj);
int GameState_GetFollowCamera(char* obj);
void ClearFlagBits_020a28b0(unsigned char* obj, int mask);
void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
extern "C" void ROMFilesystem_InitFileTables(void);

extern int g_mainAllocator;

struct Struct_ov017_021ac32c {
    char unknown_0_[0xc];
    int unknown_c_;
    SafeAllocator unknown_10_;
};

// USA: func_ov017_021ac32c
extern "C" ARM void func_ov017_021ac32c(struct Obj021ac32c* self) {
    void* ctrl = (void*)MessageSystem_GetInstance();
    MessageSystem_Reset((char*)ctrl);
    MessageSystem_Stop(ctrl);
    FontBankLoader_GetInstance();
    FontBankLoader_CancelLoads();
    GameState* battle = GameState::GetInstance();
    GameObject_EnableControl(battle->GetLeader());

    void* p = self->allocator.GetSignedAllocator();
    if (p != NULL) {
        self->allocator.Destroy();
        AllocatorUnion_Free((AllocatorUnion*)&g_mainAllocator, p);
        ROMFilesystem_InitFileTables();
    }
    self->field0xc = 0;
    int flag = GameState_GetFollowCamera((char*)battle);
    if (flag == 0) return;
    ClearFlagBits_020a28b0((unsigned char*)flag, 3);
}
