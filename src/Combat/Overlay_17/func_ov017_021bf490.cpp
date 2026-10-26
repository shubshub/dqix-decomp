#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "Resource/Brightness.h"

extern "C" void GameResources_ReleaseSpecialItemEffect(unsigned char* obj);
extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
extern "C" int GameState_GetFollowCamera(char* obj);
extern "C" void func_020a27ac(void* obj);
extern AllocatorUnion g_mainAllocator;

// USA: func_ov017_021bf490
extern "C" ARM void func_ov017_021bf490(void* objRaw) {
    unsigned char* obj = (unsigned char*)objRaw;
    SafeAllocator* allocA = (SafeAllocator*)(obj + 0x34);
    SafeAllocator* var2 = (SafeAllocator*)(obj + 0x4c);

    void* ov = GetGameResources();
    unsigned char field48 = obj[0x48];
    if (field48 != 0 && ov != NULL) {
        GameResources_ReleaseSpecialItemEffect((unsigned char*)ov);
        obj[0x48] = 0;
    }

    SignedAllocatorHeader* h1 = allocA->GetSignedAllocator();
    if (h1 != NULL) {
        allocA->Destroy();
        AllocatorUnion_Free(&g_mainAllocator, h1);
    }

    SignedAllocatorHeader* h2 = var2->GetSignedAllocator();
    if (h2 != NULL) {
        var2->Destroy();
        AllocatorUnion_Free(&g_mainAllocator, h2);
    }

    int flagResult = GameState_GetFollowCamera((char*)GameState::GetInstance());
    if (flagResult != 0) {
        func_020a27ac((void*)flagResult);
    }

    if (ov == NULL) return;
    ClearFlags04((GameResources*)ov, 0x80);
}
