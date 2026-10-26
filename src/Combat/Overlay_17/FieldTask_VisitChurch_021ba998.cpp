#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/Brightness.h"

struct Struct_02018300_3;
struct Struct_0206f7f4;
struct Struct_ov017_021ba998 { char unknown_0_[0x5a0]; signed char unknown_5a0_; char unknown_5a1_[0x5c0 - 0x5a1]; };
struct Struct_ov017_021ba998_2 {
    unsigned char unknown_0_; unsigned char unknown_1_; char unknown_2_[6];
    SafeAllocator unknown_8_;
    Struct_ov017_021ba998* unknown_1c_;
    unsigned char unknown_20_; signed char unknown_21_; unsigned char unknown_22_;
};
unsigned char* GameState_GetFollowCamera(char*);
void GameObject_DisableControl(Obj020397cc*, int);
void SetFlagsAt0x244_020a28a0(unsigned char*, unsigned char);
void ClearFlagBits_020a28b0(unsigned char*, int);
extern "C" void func_020a0cc4(unsigned int);
void* AllocatorUnion_AllocateRounded(AllocatorUnion*, unsigned int);
extern "C" void ROMFilesystem_InitFileTables();
void PushInputLogA_020a1df8(int);
List0206f7f4* GetData02108d18_0206f504();
short GetHalfwordChecked(List0206f7f4*, int);
extern "C" void func_ov003_02158bb8(Dialog*);
void SetField587_02159174(void*, unsigned char);
extern "C" void func_ov003_02158a84(Dialog*, SafeAllocator*);
extern "C" int func_ov017_021959b4();
void SetFlag8At_02159240(void*);
extern "C" int func_ov003_02158e94(Dialog*, int);
extern "C" void Party_ReformLine(void*, int, int, int, int);
extern "C" void func_ov003_02158d4c(Dialog*);
int GetField94_0215916c(void*);
void GameObject_EnableControl(void*);
extern "C" void func_ov017_021ba94c(DialogTask*);
extern AllocatorUnion g_mainAllocator;
#define REG_DISPCNT (*(volatile unsigned int*)0x04000000)

// Overlay 17, originally func_ov017_021ba998 (USA/EUR 0x021ba998, JPN 0x021baf8c)
extern "C" ARM void FieldTask_VisitChurch(DialogTask* self) {
    GameState* state = GameState::GetInstance();
    unsigned int* flags = (unsigned int*)state->GetResources();
    GameObject* actor = state->GetLeader();
    unsigned char* field = GameState_GetFollowCamera((char*)state);
    SetFlags04((GameResources*)flags, 0xc0);
    GameObject_DisableControl((Obj020397cc*)actor, 1);
    SetFlagsAt0x244_020a28a0(field, 3);
    int ticks = state->GetTickCount();
    if (ticks < 0) ticks = 1;
    if (self->phase_ == 0) {
        func_020a0cc4(0x16e00);
        void* buffer = AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x16e00);
        if (!buffer) {
            ROMFilesystem_InitFileTables(); self->finished_ = 1;
            return;
        }
        self->allocator_.CreateTypeA(buffer, 0x16e00);
        self->allocator_.Reset();
        self->dialog_ = (Dialog*)self->allocator_.Allocate(0x5c0);
        if (!self->dialog_) {
            ROMFilesystem_InitFileTables(); self->finished_ = 1;
            return;
        }
        PushInputLogA_020a1df8(3);
        short selected;
        if (self->mode_) selected = self->selection_ - 1;
        else selected = GetHalfwordChecked(GetData02108d18_0206f504(), 0) - 1;
        if (selected < 0) selected = 0;
        self->selection_ = selected;
        func_ov003_02158bb8(self->dialog_);
        SetField587_02159174(self->dialog_, self->mode_);
        self->dialog_->selection_ = self->selection_;
        func_ov003_02158a84(self->dialog_, &self->allocator_);
        ++self->phase_;
    } else if (self->phase_ == 1) {
        if (func_ov017_021959b4()) SetFlag8At_02159240(self->dialog_);
        if (func_ov003_02158e94(self->dialog_, ticks)) ++self->phase_;
    } else if (self->phase_ == 2) {
        Party_ReformLine(GetGameResources(), 1, 1, 1, 1);
        func_ov003_02158d4c(self->dialog_);
        ++self->phase_;
    } else if (self->phase_ == 3) {
        int displayMode = GetField94_0215916c(self->dialog_);
        REG_DISPCNT = (REG_DISPCNT & ~0x1f00) | displayMode << 8;
        ClearFlags04((GameResources*)flags, 0xc0);
        GameObject_EnableControl(actor);
        ClearFlagBits_020a28b0(field, 3);
        func_ov017_021ba94c(self);
        ROMFilesystem_InitFileTables();
        self->finished_ = 1;
    }
}
