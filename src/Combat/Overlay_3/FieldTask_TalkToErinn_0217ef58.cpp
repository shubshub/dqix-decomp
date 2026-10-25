#include <globaldefs.h>
#if defined(jpn)
enum { Enum_ov003_0217ef58_5140 = 0x12a4 };
#else
enum { Enum_ov003_0217ef58_5140 = 0x1414 };
#endif
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "Resource/GameResources.h"
#include "Resource/Brightness.h"

struct Struct_02018300_3;

struct Struct_ov003_0217ef58 {
    char unknown_0_[4];
    short unknown_4_;
    char unknown_6_[4];
    short unknown_a_;
};

struct Struct_ov003_0217ef58_2 {
    char unknown_0_;
    unsigned char unknown_1_;
    char unknown_2_[6];
    int unknown_8_;
    Struct_ov003_0217ef58* unknown_c_;
    int unknown_10_;
    SafeAllocator unknown_14_;
    char unknown_28_[2];
    char unknown_2a_[0x10];
};

extern "C" void func_02074af4(void* arg0);
extern "C" void func_020a0cc4(unsigned int arg0);
extern "C" void func_020a0c0c(void);
void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern "C" void VectorizedMemset(void* dst, int val, unsigned int len);
void PushInputLogA_020a1df8(int id);
extern "C" void func_ov003_0216d63c(Scene0217ef58* scene);
extern "C" void func_ov003_0216ae0c(Scene0217ef58* scene, SafeAllocator* allocator);
extern "C" int func_ov003_0216af14(Scene0217ef58* scene);
void GameObject_DisableControl(Obj020397cc* obj, int arg1);
int GetFieldIfFlag4_020100f8(char* obj);
void ClearIntAt0x23c_020a27b8(unsigned char* obj);
extern "C" int func_ov017_021959b4(void);
extern "C" void func_ov003_0217f194(Obj0217ef58* obj);
extern "C" void func_ov003_0217f118(Obj0217ef58* obj);
void GameObject_EnableControl(void* obj);
void SetField0x23cTrue_020a27ac(void* obj);
void ClearFlagBits_020a28b0(unsigned char* obj, int mask);
void InitObjAndClearFlags_0217f1b8(unsigned char* obj);
extern AllocatorUnion g_mainAllocator;

// Overlay 3, originally func_ov003_0217ef58 (USA/EUR 0x0217ef58, JPN 0x0217dc5c)
extern "C" ARM void FieldTask_TalkToErinn(Obj0217ef58* self) {
    GameState* gs = GameState::GetInstance();

    if (arg0->unknown_10_ == 0) {
        func_02074af4(arg0->unknown_2a_);
        SetFlags04(GetGameResources(), 0xc0);
        func_020a0cc4(0x1e800);
        void* buffer = AllocatorUnion_AllocateRounded(&g_mainAllocator, 0xb000);
        if (buffer == 0) {
            func_020a0c0c();
            arg0->unknown_1_ = 1;
            return;
        }
        VectorizedMemset(var1, 0, 0xb000);
        arg0->unknown_14_.CreateTypeA(var1, 0xb000);
        arg0->unknown_14_.Reset();
        arg0->unknown_c_ = (Struct_ov003_0217ef58*)arg0->unknown_14_.Allocate(Enum_ov003_0217ef58_5140);
        if (arg0->unknown_c_ == 0) {
            func_020a0c0c();
            arg0->unknown_1_ = 1;
            return;
        }
        PushInputLogA_020a1df8(3);
        func_ov003_0216d63c(self->scene);
        func_ov003_0216ae0c(self->scene, &self->allocator);
        self->scene->id = self->id;
        GameObject_DisableControl((Obj020397cc*)gs->GetUnknownGameObject(), 1);
        ClearIntAt0x23c_020a27b8((unsigned char*)GetFieldIfFlag4_020100f8((char*)gs));
        self->state = 1;
    } else if (self->state == 1) {
        if (func_ov003_0216af14(self->scene) == 0) {
            self->state = 2;
        }
        func_ov017_021959b4();
        if (func_ov017_021959b4() != 0 && arg0->unknown_c_->unknown_4_ != 5) {
            func_ov003_0217f194(arg0);
            arg0->unknown_10_ = 3;
        }
    } else if (self->state == 2) {
        func_ov003_0217f118(self);
        GameObject_EnableControl(gs->GetUnknownGameObject());
        int flags = GetFieldIfFlag4_020100f8((char*)gs);
        SetField0x23cTrue_020a27ac((void*)flags);
        ClearFlagBits_020a28b0((unsigned char*)flags, 2);
        ClearFlags04(GetGameResources(), 0xc0);
        arg0->unknown_10_ = -1;
    } else if (arg0->unknown_10_ == 3) {
        if (func_ov003_0216af14(arg0->unknown_c_) == 0) {
            func_ov003_0217f1b8((unsigned char*)arg0);
        }
    }
}
