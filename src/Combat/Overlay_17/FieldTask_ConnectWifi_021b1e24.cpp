#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/OverlayId.h"

#include "Resource/GameResources.h"

struct Struct_ov017_021b1e24;

extern "C" void Overlay_Load(unsigned int id);
extern "C" void func_ov031_02243518(void* state, int mode);
extern "C" void func_ov031_02243690(Struct_ov017_021b1e24* obj);
extern "C" void func_0205e92c(void* obj);
extern "C" void func_0209c278(void* obj);
extern "C" void BgmPlayer_LoadArchive(void* obj);
extern "C" void SePlayer_LoadArchive(void* obj, int mode);
extern char g_sePlayer;
extern char g_bgmPlayer;

struct Struct_ov017_021b1e24_2 {
    char pad0[0x28];
    SafeAllocator* allocator;
    char pad1[0x30 - 0x2c];
    int done;
    char pad2[0x37c - 0x34];
    int unknown_37c_;
    int unknown_380_;
};

struct Task021b1e24 {
    char pad0;
    unsigned char failed;
    char pad1[8 - 2];
    SafeAllocator* heap;
    SafeAllocator allocator;
    unsigned char step;
    unsigned char mode;
    char pad2[0x24 - 0x22];
    Struct_ov017_021b1e24_2* state;
    char pad3[0x32 - 0x28];
    unsigned char busy;
    char pad4;
    int f34;
    int unknown_38_;
};

static inline void inline_ov017_021b1e24(Struct_ov017_021b1e24_2* state, int first, int second) {
    state->unknown_37c_ = first;
    state->unknown_380_ = second;
}

// Overlay 17, originally func_ov017_021b1e24 (USA/EUR 0x021b1e24, JPN 0x021b24ac)
extern "C" ARM void FieldTask_ConnectWifi(Task021b1e24* task) {
    GameState::GetInstance();
    GetGameResources();
    if (task->step == 0) {
        if (task->heap == NULL || task->busy != 0) {
            task->failed = 1;
            return;
        }
        task->state = (Struct_ov017_021b1e24_2*)task->heap->Allocate(0xa3c);
        if (task->state == NULL) {
            task->failed = 1;
            return;
        }
        unsigned int size = task->heap->GetMaxPossibleAllocation();
        task->allocator.CreateTypeA(task->heap->Allocate(size), size);
        task->allocator.Reset();
        func_0205e92c(&g_sePlayer);
        func_0209c278(&g_bgmPlayer);
        Overlay_Load(OVERLAY_ID(31));
        func_ov031_02243518(task->state, task->mode);
        task->state->allocator = &task->allocator;
        inline_ov017_021b1e24(task->state, task->f34, task->unknown_38_);
        func_ov031_02243690((Struct_ov017_021b1e24*)task->state);
        task->step++;
        return;
    }
    if (task->step != 1) {
        return;
    }
    func_ov031_02243690((Struct_ov017_021b1e24*)task->state);
    if (task->state->done == 0) {
        return;
    }
    Overlay_Load(OVERLAY_ID(32));
    func_0209c278(&g_bgmPlayer);
    BgmPlayer_LoadArchive(&g_bgmPlayer);
    func_0205e92c(&g_sePlayer);
    SePlayer_LoadArchive(&g_sePlayer, 100);
    SignedAllocatorHeader* block = task->allocator.GetSignedAllocator();
    if (block != NULL) {
        task->allocator.Destroy();
        task->heap->Free(block);
    }
    task->failed = 1;
}
