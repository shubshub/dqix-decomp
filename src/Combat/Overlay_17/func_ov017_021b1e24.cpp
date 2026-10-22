#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/OverlayId.h"

#include "Resource/GameResources.h"

struct Struct_ov017_021b1e24;

extern "C" void func_020a1940(unsigned int id);
extern "C" void func_ov031_02243518(void* state, int mode);
void RunStateTableEntry_02243690(Obj_02243690* obj);
void ShutdownAndReinit0205e92c(void* obj);
void ResetAndReinit0209c278(void* obj);
void Dispatch0203a974With0x57000_0209c290(void* obj);
void SetupContextForMode0205ea20(void* obj, int mode);
extern char g_sePlayer;
extern char data_02109bf4;

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

// USA: func_ov017_021b1e24
extern "C" ARM void func_ov017_021b1e24(Struct_ov017_021b1e24_3* arg0) {
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
        ResetAndReinit0209c278(&data_02109bf4);
        func_020a1940(OVERLAY_ID(31));
        func_ov031_02243518(arg0->unknown_24_, arg0->unknown_21_);
        arg0->unknown_24_->unknown_28_ = &arg0->unknown_c_;
        inline_ov017_021b1e24(arg0->unknown_24_, arg0->unknown_34_, arg0->unknown_38_);
        func_ov031_02243690((Struct_ov017_021b1e24*)arg0->unknown_24_);
        arg0->unknown_20_++;
        return;
    }
    if (arg0->unknown_20_ != 1) {
        return;
    }
    func_ov031_02243690((Struct_ov017_021b1e24*)arg0->unknown_24_);
    if (arg0->unknown_24_->unknown_30_ == 0) {
        return;
    }
    func_020a1940(OVERLAY_ID(32));
    ResetAndReinit0209c278(&data_02109bf4);
    Dispatch0203a974With0x57000_0209c290(&data_02109bf4);
    ShutdownAndReinit0205e92c(&g_sePlayer);
    SetupContextForMode0205ea20(&g_sePlayer, 100);
    SignedAllocatorHeader* block = task->allocator.GetSignedAllocator();
    if (block != NULL) {
        task->allocator.Destroy();
        task->heap->Free(block);
    }
    arg0->unknown_1_ = 1;
}
