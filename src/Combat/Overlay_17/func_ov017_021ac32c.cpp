#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "GameState/GameState.h"

extern "C" void FontBankLoader_CancelLoads(void);
extern "C" int MessageSystem_GetInstance(void);
extern "C" void MessageSystem_Reset(char* obj);
extern "C" void MessageSystem_Stop(void* self);
extern "C" int FontBankLoader_GetInstance(void);
extern "C" void GameObject_EnableControl(void* obj);
extern "C" int GameState_GetFollowCamera(char* obj);
extern "C" void func_020a28b0(unsigned char* obj, int mask);
extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
extern "C" void ROMFilesystem_InitFileTables(void);

extern int g_mainAllocator;

struct Struct_ov017_021ac32c {
    char pad0[0xc];
    int unknown_c_;
    SafeAllocator allocator;
};

// USA: func_ov017_021ac32c
extern "C" ARM void func_ov017_021ac32c(struct Struct_ov017_021ac32c* self) {
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
    self->unknown_c_ = 0;
    int flag = GameState_GetFollowCamera((char*)battle);
    if (flag == 0) return;
    func_020a28b0((unsigned char*)flag, 3);
}
