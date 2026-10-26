#include <globaldefs.h>
#if defined(jpn)
enum { kAllocatorOffset = 0x24 };
#else
enum { kAllocatorOffset = 0x58 };
#endif

#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/Brightness.h"

void GameObject_EnableControl(void* obj);
void* GlobalFlags_GetInstance(void);
struct FlagWord020466f4;
void FlagWord_ClearBits(struct FlagWord020466f4* word, unsigned int mask);
void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
extern int g_mainAllocator;

struct Obj020d9d60 {
    char pad[kAllocatorOffset];
    SafeAllocator allocator;
};

// USA: func_020d9d60
ARM void ShutdownObject020d9d60(struct Obj020d9d60* self) {
    GameObject_EnableControl((void*)GameState::GetInstance()->GetLeader());
    ClearFlags00(GetGameResources(), 0x10);
    FlagWord_ClearBits((struct FlagWord020466f4*)GlobalFlags_GetInstance(), 0xe);
    void* p = self->allocator.GetSignedAllocator();
    if (p == NULL) return;
    self->allocator.Destroy();
    AllocatorUnion_Free((AllocatorUnion*)&g_mainAllocator, p);
}
