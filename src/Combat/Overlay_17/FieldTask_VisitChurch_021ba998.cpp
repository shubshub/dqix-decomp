#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/Brightness.h"

struct Obj020397cc;
struct Struct_0206f7f4;
struct Struct_ov017_021ba998 { char pad0[0x5a0]; signed char selection_; char unknown_5a1_[0x5c0 - 0x5a1]; };
struct DialogTask {
    unsigned char unknown_0_; unsigned char finished_; char pad2[6];
    SafeAllocator allocator_;
    Struct_ov017_021ba998* unknown_1c_;
    unsigned char mode_; signed char selection_; unsigned char phase_;
};
extern "C" unsigned char* GameState_GetFollowCamera(char*);
extern "C" void GameObject_DisableControl(Obj020397cc*, int);
extern "C" void func_020a28a0(unsigned char*, unsigned char);
extern "C" void func_020a28b0(unsigned char*, int);
extern "C" void func_020a0cc4(unsigned int);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion*, unsigned int);
extern "C" void ROMFilesystem_InitFileTables();
extern "C" void func_020a1df8(int);
extern "C" Struct_0206f7f4* func_0206f504();
extern "C" short func_0206f7f4(Struct_0206f7f4*, int);
extern "C" void func_ov003_02158bb8(Struct_ov017_021ba998*);
extern "C" void func_ov003_02159174(void*, unsigned char);
extern "C" void func_ov003_02158a84(Struct_ov017_021ba998*, SafeAllocator*);
extern "C" int func_ov017_021959b4();
extern "C" void func_ov003_02159240(void*);
extern "C" int func_ov003_02158e94(Struct_ov017_021ba998*, int);
extern "C" void Party_ReformLine(void*, int, int, int, int);
extern "C" void func_ov003_02158d4c(Struct_ov017_021ba998*);
extern "C" int func_ov003_0215916c(void*);
extern "C" void GameObject_EnableControl(void*);
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
    func_020a28a0(field, 3);
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
        self->unknown_1c_ = (Struct_ov017_021ba998*)self->allocator_.Allocate(0x5c0);
        if (!self->unknown_1c_) {
            ROMFilesystem_InitFileTables(); self->finished_ = 1;
            return;
        }
        func_020a1df8(3);
        short selected;
        if (self->mode_) selected = self->selection_ - 1;
        else selected = func_0206f7f4(func_0206f504(), 0) - 1;
        if (selected < 0) selected = 0;
        self->selection_ = selected;
        func_ov003_02158bb8(self->unknown_1c_);
        func_ov003_02159174(self->unknown_1c_, self->mode_);
        self->unknown_1c_->selection_ = self->selection_;
        func_ov003_02158a84(self->unknown_1c_, &self->allocator_);
        ++self->phase_;
    } else if (self->phase_ == 1) {
        if (func_ov017_021959b4()) func_ov003_02159240(self->unknown_1c_);
        if (func_ov003_02158e94(self->unknown_1c_, ticks)) ++self->phase_;
    } else if (self->phase_ == 2) {
        Party_ReformLine(GetGameResources(), 1, 1, 1, 1);
        func_ov003_02158d4c(self->unknown_1c_);
        ++self->phase_;
    } else if (self->phase_ == 3) {
        int displayMode = func_ov003_0215916c(self->unknown_1c_);
        REG_DISPCNT = (REG_DISPCNT & ~0x1f00) | displayMode << 8;
        ClearFlags04((GameResources*)flags, 0xc0);
        GameObject_EnableControl(actor);
        func_020a28b0(field, 3);
        func_ov017_021ba94c(self);
        ROMFilesystem_InitFileTables();
        self->finished_ = 1;
    }
}
