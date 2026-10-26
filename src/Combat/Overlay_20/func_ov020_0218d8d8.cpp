#include <globaldefs.h>

#if defined(jpn)
enum { kAllocatorOffset = 0x400 };
#else
enum { kAllocatorOffset = 0x470 };
#endif

#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"

extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
extern "C" unsigned char func_0200fb9c(char* obj);

struct Actor0209c678;
extern "C" void BgmPlayer_FadeOut(struct Actor0209c678* actor, int arg);

struct Actor0209c20c;
extern "C" void func_0209c20c(struct Actor0209c20c* actor);

struct Obj_0205e8ec;
extern "C" void func_0205e8ec(struct Obj_0205e8ec* a);

extern AllocatorUnion g_mainAllocator;
extern char g_bgmPlayer;
extern char g_sePlayer;

struct Struct_ov020_0218b710_3 {
    char pad[kAllocatorOffset];
    SafeAllocator allocator;
};

// USA: func_ov020_0218d8d8
extern "C" ARM void func_ov020_0218d8d8(struct Struct_ov020_0218b710_3* obj) {
    GameState* battleStruct = GameState::GetInstance();
    SignedAllocatorHeader* header = obj->allocator.GetSignedAllocator();
    obj->allocator.Destroy();
    AllocatorUnion_Free(&g_mainAllocator, header);
    if (func_0200fb9c((char*)battleStruct) == 2) {
        return;
    }
    BgmPlayer_FadeOut((struct Actor0209c678*)&g_bgmPlayer, 0);
    func_0209c20c((struct Actor0209c20c*)&g_bgmPlayer);
    func_0205e8ec((struct Obj_0205e8ec*)&g_sePlayer);
}
