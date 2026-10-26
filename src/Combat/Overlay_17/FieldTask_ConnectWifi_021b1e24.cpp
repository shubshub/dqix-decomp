#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/OverlayId.h"

#include "Resource/GameResources.h"

struct Struct_ov017_021b1e24;

extern "C" void Overlay_Load(unsigned int id);
extern "C" void func_ov031_02243518(void* state, int mode);
void RunStateTableEntry_02243690(Obj_02243690* obj);
void ShutdownAndReinit0205e92c(void* obj);
void ResetAndReinit0209c278(void* obj);
void BgmPlayer_LoadArchive(void* obj);
void SePlayer_LoadArchive(void* obj, int mode);
extern char g_sePlayer;
extern char g_bgmPlayer;

struct Struct_ov017_021b1e24_2 {
    char unknown_0_[0x28];
    SafeAllocator* unknown_28_;
    char unknown_2c_[0x30 - 0x2c];
    int unknown_30_;
    char unknown_34_[0x37c - 0x34];
    int unknown_37c_;
    int unknown_380_;
};

struct Struct_ov017_021b1e24_3 {
    char unknown_0_;
    unsigned char unknown_1_;
    char unknown_2_[8 - 2];
    SafeAllocator* unknown_8_;
    SafeAllocator unknown_c_;
    unsigned char unknown_20_;
    unsigned char unknown_21_;
    char unknown_22_[0x24 - 0x22];
    Struct_ov017_021b1e24_2* unknown_24_;
    char unknown_28_[0x32 - 0x28];
    unsigned char unknown_32_;
    char unknown_33_;
    int unknown_34_;
    int unknown_38_;
};

static inline void inline_ov017_021b1e24(Struct_ov017_021b1e24_2* arg0, int arg1, int arg2) {
    arg0->unknown_37c_ = arg1;
    arg0->unknown_380_ = arg2;
}

// Overlay 17, originally func_ov017_021b1e24 (USA/EUR 0x021b1e24, JPN 0x021b24ac)
extern "C" ARM void FieldTask_ConnectWifi(Task021b1e24* task) {
    GameState::GetInstance();
    GetGameResources();
    if (arg0->unknown_20_ == 0) {
        if (arg0->unknown_8_ == NULL || arg0->unknown_32_ != 0) {
            arg0->unknown_1_ = 1;
            return;
        }
        arg0->unknown_24_ = (Struct_ov017_021b1e24_2*)arg0->unknown_8_->Allocate(0xa3c);
        if (arg0->unknown_24_ == NULL) {
            arg0->unknown_1_ = 1;
            return;
        }
        unsigned int size = task->heap->GetMaxPossibleAllocation();
        task->allocator.CreateTypeA(task->heap->Allocate(size), size);
        task->allocator.Reset();
        ShutdownAndReinit0205e92c(&g_sePlayer);
        ResetAndReinit0209c278(&g_bgmPlayer);
        Overlay_Load(OVERLAY_ID(31));
        func_ov031_02243518(task->state, task->mode);
        task->state->allocator = &task->allocator;
        SetPair(task->state, task->f34, task->f38);
        RunStateTableEntry_02243690((Obj_02243690*)task->state);
        task->step++;
        return;
    }
    if (arg0->unknown_20_ != 1) {
        return;
    }
    func_ov031_02243690((Struct_ov017_021b1e24*)arg0->unknown_24_);
    if (arg0->unknown_24_->unknown_30_ == 0) {
        return;
    }
    Overlay_Load(OVERLAY_ID(32));
    ResetAndReinit0209c278(&g_bgmPlayer);
    BgmPlayer_LoadArchive(&g_bgmPlayer);
    ShutdownAndReinit0205e92c(&g_sePlayer);
    SePlayer_LoadArchive(&g_sePlayer, 100);
    SignedAllocatorHeader* block = task->allocator.GetSignedAllocator();
    if (block != NULL) {
        task->allocator.Destroy();
        task->heap->Free(block);
    }
    arg0->unknown_1_ = 1;
}
