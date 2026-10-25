#include <globaldefs.h>

#if defined(jpn)
enum { kAllocatorOffset = 0x400 };
#else
enum { kAllocatorOffset = 0x470 };
#endif

#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"

void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
unsigned char GetByte0x4_0200fb9c(char* obj);

struct Actor0209c678;
void BgmPlayer_FadeOut(struct Actor0209c678* actor, int arg);

struct Actor0209c20c;
void InitActorContext0209c20c(struct Actor0209c20c* actor);

struct Obj_0205e8ec;
void RefreshDisplayState0205e8ec(struct Obj_0205e8ec* a);

extern AllocatorUnion g_mainAllocator;
extern char g_bgmPlayer;
extern char g_sePlayer;

struct AllocGroup0218d8d8 {
    char pad[kAllocatorOffset];
    SafeAllocator allocator;
};

// USA: func_ov020_0218d8d8
ARM void ResetAllocatorAndDispatchState_0218d8d8(struct AllocGroup0218d8d8* obj) {
    GameState* battleStruct = GameState::GetInstance();
    SignedAllocatorHeader* header = obj->allocator.GetSignedAllocator();
    obj->allocator.Destroy();
    AllocatorUnion_Free(&g_mainAllocator, header);
    if (GetByte0x4_0200fb9c((char*)battleStruct) == 2) {
        return;
    }
    BgmPlayer_FadeOut((struct Actor0209c678*)&g_bgmPlayer, 0);
    InitActorContext0209c20c((struct Actor0209c20c*)&g_bgmPlayer);
    RefreshDisplayState0205e8ec((struct Obj_0205e8ec*)&g_sePlayer);
}
