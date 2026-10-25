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
unsigned char* GetFieldIfFlag4_020100f8(char*);
void GameObject_DisableControl(Obj020397cc*, int);
void SetFlagsAt0x244_020a28a0(unsigned char*, unsigned char);
void ClearFlagBits_020a28b0(unsigned char*, int);
extern "C" void func_020a0cc4(unsigned int);
void* AllocatorUnion_AllocateRounded(AllocatorUnion*, unsigned int);
extern "C" void func_020a0c0c();
extern "C" void func_020a1df8(int);
extern "C" Struct_0206f7f4* func_0206f504();
extern "C" short func_0206f7f4(Struct_0206f7f4*, int);
extern "C" void func_ov003_02158bb8(Struct_ov017_021ba998*);
extern "C" void func_ov003_02159174(void*, unsigned char);
extern "C" void func_ov003_02158a84(Struct_ov017_021ba998*, SafeAllocator*);
extern "C" int func_ov017_021959b4();
extern "C" void func_ov003_02159240(void*);
extern "C" int func_ov003_02158e94(Struct_ov017_021ba998*, int);
extern "C" void func_ov017_02191108(void*, int, int, int, int);
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
    GameObject* actor = state->GetUnknownGameObject();
    unsigned char* field = GetFieldIfFlag4_020100f8((char*)state);
    SetFlags04((GameResources*)flags, 0xc0);
    GameObject_DisableControl((Obj020397cc*)actor, 1);
    SetFlagsAt0x244_020a28a0(field, 3);
    int ticks = state->GetTickCount();
    if (ticks < 0) ticks = 1;
    if (self->phase_ == 0) {
        func_020a0cc4(0x16e00);
        void* buffer = AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x16e00);
        if (!buffer) {
            func_020a0c0c(); self->finished_ = 1;
            return;
        }
        arg0->unknown_8_.CreateTypeA(var5, 0x16e00);
        arg0->unknown_8_.Reset();
        arg0->unknown_1c_ = (Struct_ov017_021ba998*)arg0->unknown_8_.Allocate(0x5c0);
        if (!arg0->unknown_1c_) {
            func_020a0c0c(); arg0->unknown_1_ = 1;
            return;
        }
        func_020a1df8(3);
        short var6;
        if (arg0->unknown_20_) var6 = arg0->unknown_21_ - 1;
        else var6 = func_0206f7f4(func_0206f504(), 0) - 1;
        if (var6 < 0) var6 = 0;
        arg0->unknown_21_ = var6;
        func_ov003_02158bb8(arg0->unknown_1c_);
        func_ov003_02159174(arg0->unknown_1c_, arg0->unknown_20_);
        arg0->unknown_1c_->unknown_5a0_ = arg0->unknown_21_;
        func_ov003_02158a84(arg0->unknown_1c_, &arg0->unknown_8_);
        ++arg0->unknown_22_;
    } else if (arg0->unknown_22_ == 1) {
        if (func_ov017_021959b4()) func_ov003_02159240(arg0->unknown_1c_);
        if (func_ov003_02158e94(arg0->unknown_1c_, var4)) ++arg0->unknown_22_;
    } else if (arg0->unknown_22_ == 2) {
        func_ov017_02191108(GetGameResources(), 1, 1, 1, 1);
        func_ov003_02158d4c(self->dialog_);
        ++self->phase_;
    } else if (self->phase_ == 3) {
        int displayMode = GetField94_0215916c(self->dialog_);
        REG_DISPCNT = (REG_DISPCNT & ~0x1f00) | displayMode << 8;
        ClearFlags04((GameResources*)flags, 0xc0);
        GameObject_EnableControl(actor);
        ClearFlagBits_020a28b0(field, 3);
        func_ov017_021ba94c(self);
        func_020a0c0c();
        arg0->unknown_1_ = 1;
    }
}
