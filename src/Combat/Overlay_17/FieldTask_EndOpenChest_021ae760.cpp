#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "GameState/GameState.h"
#include "Resource/Brightness.h"
#include "World/FieldTask.h"

void GameResources_ReleaseSpecialItemEffect(unsigned char* obj);
void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
void GameObject_EnableControl(void* obj);
int GetFieldIfFlag4_020100f8(char* obj);
void FollowCamera_EnableFollow(void* obj);

extern int g_mainAllocator;

// Overlay 17, originally func_ov017_021ae760 (USA/EUR 0x021ae760, JPN 0x021aee74)
extern "C" ARM void FieldTask_EndOpenChest(OpenChestTask* self) {
    void* res = GetGameResources();
    self->done = 1;
    unsigned char special = self->special;
    if (special != 0 && res != NULL) {
        GameResources_ReleaseSpecialItemEffect((unsigned char*)res);
        void* buffer = self->allocator.GetSignedAllocator();   // the block FieldTask_OpenChest gave it
        if (buffer != NULL) {
            self->allocator.Destroy();
            AllocatorUnion_Free((AllocatorUnion*)&g_mainAllocator, buffer);
        }
        self->special = 0;
    }

    GameState* gs = GameState::GetInstance();
    GameObject* leader = gs->GetUnknownGameObject();
    if (leader != NULL) {
        GameObject_EnableControl(leader);
    }
    int camera = GetFieldIfFlag4_020100f8((char*)gs);
    if (camera != 0) {
        FollowCamera_EnableFollow((void*)camera);
    }

    if (res == NULL) return;
    ClearFlags04((GameResources*)res, 0x80);
}
