#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
#include "NitroSDK/Matrix.h"
#include "Resource/Brightness.h"

struct Struct_ov000_02161e30;
struct Struct_ov000_0217e870_2;
struct Struct_02049f50;

struct Struct_0203d028 {
    unsigned int unknown_0_[10];
    unsigned int unknown_28_[10];
    unsigned int unknown_50_;
    unsigned int unknown_54_;
    unsigned int unknown_58_[2];
    unsigned int unknown_60_[2];
};

struct Struct_02078398_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[0xf];
    unsigned char unknown_10_;
    unsigned char unknown_11_0_ : 1;
    unsigned char unknown_11_1_ : 1;
    unsigned char unknown_11_2_ : 1;
    unsigned char unknown_11_3_ : 1;
    unsigned char unknown_11_4_ : 1;
    unsigned char unknown_11_5_ : 1;
    unsigned char unknown_11_6_ : 1;
    unsigned char unknown_11_7_ : 1;
    short unknown_12_;
    short unknown_14_;
    short unknown_16_;
    short unknown_18_;
    short unknown_1a_;
    short unknown_1c_;
    short unknown_1e_;
    int unknown_20_;
    int unknown_24_;
    int unknown_28_;
    Vector3fix unknown_2c_;
    Vector3fix unknown_38_;
    Vector3fix unknown_44_;
};

struct Struct_ov000_02160da0 {
    char unknown_0_[0x30];
    SafeAllocator unknown_30_;
    char unknown_44_[0x258];
    Struct_ov000_02161e30* unknown_29c_;
    Struct_ov000_0217e870_2* unknown_2a0_;
    char unknown_2a4_[0x34bc];
    char unknown_3760_[0x1d72];
    unsigned short unknown_54d2_;
    char unknown_54d4_[0x223d];
    unsigned char unknown_7711_;
    signed char unknown_7712_;
    char unknown_7713_[0x1];
    short unknown_7714_;
    short unknown_7716_[4];
    short unknown_771e_;
    short unknown_7720_;
    short unknown_7722_;
    short unknown_7724_;
    short unknown_7726_;
    char unknown_7728_[0x21];
    unsigned char unknown_7749_;
    char unknown_774a_[0x2];
    SafeAllocator unknown_774c_;
    Struct_0203d028 unknown_7760_;
};

struct Struct_ov026_021db5a4 {
    unsigned char unknown_0_[3];
};

struct Struct_ov026_021de6a0 {
    char unknown_0_[0xa];
    Struct_ov026_021db5a4 unknown_a_;
    char unknown_d_[0xb];
};

extern "C" void func_0207df50(Struct_0203d028* arg0);
void SetBrightness(GameResources*, int, int);
int IsBrightnessTransitionActive(GameResources*);
void SetMainBrightness(GameResources*, int, int);
extern "C" void func_0205eb54(void* arg0, int arg1, int arg2);
extern "C" void func_0205eb90(void* arg0, int arg1, int arg2);
extern "C" void func_0205eb80(void* arg0);
extern "C" void func_02078484(Struct_02078398_2* arg0);
extern "C" int func_02057fb4(void* arg0, int arg1, void* arg2);
extern "C" void func_02049f50(Struct_02049f50* arg0, int arg1, int arg2);
extern "C" void func_ov000_021637c8(void* arg0);
extern "C" void func_ov000_021636ac(void* arg0);
extern "C" void func_ov000_02163710(void* arg0, int arg1);
extern "C" void func_ov000_02167e6c(unsigned char* arg0);

extern "C" {
void* func_02057924();
int func_02057e6c(void* arg0, int arg1, SafeAllocator* arg2, void* arg3, unsigned int arg4, Struct_0203d028* arg5);
void func_02057f00(void* arg0, int arg1);
int func_ov000_021759f4(void* arg0);
void func_ov000_02175808(void* arg0);
void func_ov000_021626a0(Struct_ov000_02160da0* arg0, int arg1, int arg2);
void func_ov000_02163894(Struct_ov000_02160da0* arg0);
void func_ov000_02163928(Struct_ov000_02160da0* arg0);
void func_ov026_021dc440(SafeAllocator* arg0, Struct_ov000_02160da0* arg1, Struct_ov000_02161e30* arg2, Struct_ov000_0217e870_2* arg3, const char* arg4);
int func_ov026_021dc040(SafeAllocator* arg0, Struct_ov000_02160da0* arg1, Struct_ov000_02161e30* arg2, Struct_ov000_0217e870_2* arg3);
}

extern const char data_ov026_021dee0c[];
extern const char data_ov026_021dee23[];
extern const char data_ov026_021dee3a[];
extern const char data_ov026_021dedec[];
extern const Rodata021de6a0 data_ov026_021de6a0;
extern char g_sePlayer[];

// USA: func_ov026_021db5a4
extern "C" ARM void func_ov026_021db5a4(Struct_ov000_02160da0* arg0) {
    GameResources* var0 = GetGameResources();

    if (arg0->unknown_7712_ == 0) {
        if (func_ov000_021759f4(arg0->unknown_3760_)) {
            arg0->unknown_774c_.Reset();
            func_0207df50(&arg0->unknown_7760_);
            arg0->unknown_7714_ = arg0->unknown_771e_ = arg0->unknown_7720_ = -1;
            SetBrightness(var0, -0x10, 0xf);
            arg0->unknown_7714_ = BackgroundLoader::GetInstance()->QueueLoadFile(data_ov026_021dee0c, &arg0->unknown_774c_);
            arg0->unknown_771e_ = BackgroundLoader::GetInstance()->QueueLoadFile(data_ov026_021dee23, &arg0->unknown_774c_);
            arg0->unknown_7720_ = BackgroundLoader::GetInstance()->QueueLoadFile(data_ov026_021dee3a, &arg0->unknown_774c_);
            arg0->unknown_7712_ = 1;
            arg0->unknown_7749_ = 1;
        }
    } else if (arg0->unknown_7712_ == 1) {
        BackgroundLoader* var1 = BackgroundLoader::GetInstance();
        if (var1->GetTaskStatus(arg0->unknown_771e_) && var1->GetTaskStatus(arg0->unknown_7720_) &&
            var1->GetTaskStatus(arg0->unknown_7714_) && !IsBrightnessTransitionActive(var0)) {
            short* var2;
            unsigned char* var3;
            int var4;
            short var5[3] = {arg0->unknown_7714_, arg0->unknown_771e_, arg0->unknown_7720_};
            Struct_ov026_021db5a4 var6 = data_ov026_021de6a0.unknown_a_;
            var3 = var6.unknown_0_;
            var2 = var5;
            for (var4 = 0; var4 < 3; var4++) {
                void* var7;
                unsigned int var8;
                var1->GetLoadedFileByID(*var2, &var7, &var8);
                func_02057e6c(func_02057924(), *var3, &arg0->unknown_774c_, var7, var8, &arg0->unknown_7760_);
                var1->RemoveTask(*var2);
                var3++;
                var2++;
            }
            arg0->unknown_7714_ = arg0->unknown_771e_ = arg0->unknown_7720_ = -1;
            func_ov000_021626a0(arg0, 0x26, 1);
            func_ov000_021626a0(arg0, 0x27, 0);
            func_ov000_02167e6c((unsigned char*)arg0);
            arg0->unknown_7712_ = 2;
        }
    } else if (self->phase == 2) {
        InitStruct02078484Struct req;
        SetForwardAndStore0205eb54(g_sePlayer, 0x1b3, 0x1b3);
        DispatchIfField0xc4NonNeg_0205eb90(g_sePlayer, 1, 0);
        self->fadeActive = 1;
        func_ov000_021626a0(self, 0x26, 0);
        func_ov000_021626a0(self, 0x27, 0);
        SetFlags04((GameResources*)res, 0x100000);
        InitStruct02078484(&req);
        req.b0 = 1;
        req.f10 = 1;
        req.scale.x = 0x800;
        req.scale.y = 0x800;
        req.scale.z = 0x800;
        req.offset.x = 0;
        req.offset.z = 0;
        req.offset.y = -0xa000;
        self->objId7722 = FindNodeAndProcess02057fb4(func_02057924(), 0x1d, &req);
        self->objId7724 = FindNodeAndProcess02057fb4(func_02057924(), 0x1e, &req);
        self->objId7726 = 0;
        SetMainBrightness(res, 0, 0xf);
        self->phase = 3;
    } else if (self->phase == 3) {
        int done = 0;
        GameObject* obj = GameState::GetInstance()->GetGameObjectByIndex(self->objId7722);
        if (obj != NULL) {
            int span = obj->obj3D_.normalizedAnimationTime_ - obj->obj3D_.prevFrameNormalizedAnimationTime_;
            if (span > 0) {
                int rate = fix32_Divide(obj->obj3D_.animationTime_ - obj->obj3D_.prevFrameAnimationTime_, span);
                int left = (int)(((long long)rate * (0x1000 - obj->obj3D_.normalizedAnimationTime_) + 0x800) >> 12);
                if (left <= 0x1e000) {
                    done = 1;
                }
            }
        }
        if (var11 == NULL || var10) {
            arg0->unknown_7726_ = 0;
            SetMainBrightness(var0, -0x10, 0xf);
            arg0->unknown_7712_ = 4;
        }
    } else if (arg0->unknown_7712_ == 4) {
        if (!IsBrightnessTransitionActive(var0)) {
            SetMainBrightness(var0, -0x10, 0);
            func_02057f00(func_02057924(), 0x1d);
            func_02057f00(func_02057924(), 0x1e);
            arg0->unknown_7722_ = arg0->unknown_7724_ = -1;
            func_ov000_021626a0(arg0, 0x26, 1);
            ClearFlags04((GameResources*)var0, 0x100000);
            arg0->unknown_7712_ = 5;
        }
    } else if (self->phase == 5) {
        InitStruct02078484Struct req;
        ForwardField0xc0_0205eb80(g_sePlayer);
        self->fadeActive = 0;
        SetMainBrightness(res, -0x10, 0);
        GameState* gs = GameState::GetInstance();
        InitStruct02078484(&req);
        for (int i = 0; i < 4; i++) {
            GameObject* c = gs->GetCombatantByIndex(i);
            if (c != NULL) {
                SetField41AndScaleSub02049f50((Obj02049f50*)c, 0x1f, 0);
            }
            var15.unknown_14_ = var17;
            var15.unknown_10_ = 0;
            arg0->unknown_7716_[var17] = func_02057fb4(func_02057924(), 0x12, &var15);
        }
        func_ov000_02175808(self->list);
        self->uiFlags |= 0x200;
        ResetTwoFields021637c8(self);
        func_ov026_021dc440(&self->cmdAlloc, self, self->battle, self->party, data_ov026_021dedec);
        func_ov000_02163894(self);
        UpdateFlag8AndBit4_021636ac(self);
        self->phase = 6;
        SetForwardAndStore0205eb54(g_sePlayer, 0x1b3, 0x1b3);
        DispatchIfField0xc4NonNeg_0205eb90(g_sePlayer, 2, 0);
        self->fadeActive = 1;
    } else if (self->phase == 6) {
        func_ov000_02163928(self);
        if (func_ov026_021dc040(&self->alloc, self, self->battle, self->party)) {
            ClearFlagIfParityMismatch02163710_02163710(self, 0);
            self->phase = -1;
        }
    } else if (arg0->unknown_7712_ == -1) {
        func_ov000_02163928(arg0);
    }
}
