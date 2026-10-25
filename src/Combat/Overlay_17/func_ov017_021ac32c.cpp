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
int GetFieldIfFlag4_020100f8(char* obj);
void ClearFlagBits_020a28b0(unsigned char* obj, int mask);
void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
extern "C" void func_020a0c0c(void);

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
    GameObject_EnableControl(battle->GetUnknownGameObject());

    void* p = self->allocator.GetSignedAllocator();
    if (p != NULL) {
        self->allocator.Destroy();
        AllocatorUnion_Free((AllocatorUnion*)&g_mainAllocator, p);
        func_020a0c0c();
    }
    arg0->unknown_c_ = 0;
    int var3 = func_020100f8((char*)var1);
    if (var3 == 0) return;
    func_020a28b0((unsigned char*)var3, 3);
}
