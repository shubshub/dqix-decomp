#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov017_021abba8_340 = 0x148 };
#else
enum { Enum_ov017_021abba8_340 = 0x154 };
#endif

#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
#include "NitroSDK/OverlayId.h"
#include "World/Object3D.h"
#include "Resource/Brightness.h"

#if defined(jpn)
#define func_0205ec34 func_0205ff20
#endif

#if defined(jpn)
#define func_0206df6c func_0206f0c0
#endif

struct Struct_02018300_3;
struct Struct_02038598_5;
struct Struct_0203d028;
struct Struct_02010834;
struct Struct_0206f81c_2;
struct Struct_0206f81c_3;
struct Struct_0206f81c_4;
struct Struct_0206f81c_5;
struct Struct_0201bdac_2;
struct Struct_0201bdac;

struct Struct_ov017_021abba8_2 {
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
    Vector3i unknown_2c_;
    int unknown_38_;
    int unknown_3c_;
    int unknown_40_;
    Vector3i unknown_44_;
};

struct Struct_ov017_021abba8 {
    char unknown_0_;
    unsigned char unknown_1_;
    char unknown_2_[6];
    unsigned char unknown_8_;
    char unknown_9_;
    short unknown_a_;
    unsigned char unknown_c_;
    unsigned char unknown_d_;
    char unknown_e_[2];
    SafeAllocator unknown_10_;
    int unknown_24_;
};

extern "C" void* func_0202ae18(void);
extern "C" void* func_02057924(void);
extern "C" void func_020397cc(Struct_02018300_3* arg0, int arg1);
extern "C" int func_02046b60(Struct_02038598_5* arg0, int arg1);
extern "C" void func_ov017_021ac2a8(void* arg0);
extern "C" void func_02046a8c(void* arg0, void* arg1);
extern "C" int func_02046b08(void** arg0);
extern "C" int func_02094a00(void);
extern "C" void func_02094ab0(int arg0);
extern "C" void func_020a0cc4(unsigned int arg0);
extern "C" void* func_02012d88(AllocatorUnion* arg0, unsigned int arg1);
extern "C" void func_0207df50(Struct_0203d028* arg0);
extern "C" int func_02057e6c(void* arg0, int arg1, SafeAllocator* arg2, void* arg3, unsigned int arg4, Struct_0203d028* arg5);
extern "C" void func_02010834(Struct_02010834* arg0, int arg1, int* arg2, int* arg3);
extern "C" int func_0202c508(void* arg0);
extern "C" void func_02057fb4(void* arg0, int arg1, void* arg2);
extern "C" void func_0205ebc0(void* arg0, int arg1, int arg2);
extern "C" void func_0205ebfc(void* arg0, int arg1, int arg2);
void SetBrightness(GameResources* resources, int brightness, int duration);
int IsBrightnessTransitionActive(GameResources* resources);
extern "C" void func_ov017_02197528(void);
extern "C" void func_020397c0(void* arg0);
extern "C" void func_0205ebec(void* arg0);
extern "C" void* func_0205ec34(void);
extern "C" void func_0206df6c(void* arg0, unsigned char* arg1, int arg2, int arg3);
extern "C" int func_02011b50(void* arg0, int arg1);
extern "C" void func_ov017_021b2174(unsigned char* arg0);
extern "C" void func_ov017_021b2ba0(Struct_0206f81c_2* arg0, char* arg1);
extern "C" void func_ov017_021b2bd0(void* arg0, int arg1, int arg2);
extern "C" void func_ov017_021b2bf4(Struct_0206f81c_3* arg0, unsigned int arg1);
extern "C" void func_ov017_021b2c0c(Struct_0206f81c_4* arg0, unsigned int arg1);
extern "C" void func_ov017_021b2bdc(Struct_0206f81c_5* arg0, unsigned int arg1);
extern "C" void func_020469b4(Struct_0201bdac_2* arg0, Struct_0201bdac* arg1);
extern "C" void func_ov004_021689d8(SafeAllocator* arg0, void* arg1);

extern char data_ov017_021d78da;
extern char data_ov017_021d78f1;
extern char g_sePlayer;
extern AllocatorUnion data_02114e20;

// USA: func_ov017_021abba8
extern "C" ARM void func_ov017_021abba8(Struct_ov017_021abba8* arg0, Struct_02038598_5* arg1) {
    GameState* var0 = GameState::GetInstance();
    void* var1 = func_0202ae18();
    GameResources* var2 = GetGameResources();
    GameObject* var3 = var0->GetUnknownGameObject();
    void* var4 = func_02057924();
    BackgroundLoader* var5 = BackgroundLoader::GetInstance();
    int var6 = var0->GetTickCount();

    if (arg0->unknown_8_ == 0) {
        func_020397cc((Struct_02018300_3*)var3, 1);
        if (func_02046b60(arg1, 0x4e)) {
            arg0->unknown_1_ = 1;
            func_ov017_021ac2a8(arg0);
            if (func_02046b60(arg1, 3)) {
                func_02046a8c(arg1, var2->unknown_ptr_array_36fc[4]);
            }
        } else if (func_02046b08((void**)var2->unknown_ptr_array_36fc[1])) {
            SetFlags00(var2, 0x10);
            func_02094ab0(func_02094a00());
            func_020a0cc4(0x2800);
            arg0->unknown_24_ = var5->QueueLoadFile(&data_ov017_021d78da, NULL);
            arg0->unknown_8_++;
        }
    } else if (arg0->unknown_8_ == 1) {
        if (var5->GetTaskStatus(arg0->unknown_24_) != 0) {
            if (var5->GetDetailedTaskStatus(arg0->unknown_24_) != 2) {
                var5->RemoveTask(arg0->unknown_24_);
                arg0->unknown_1_ = 1;
            }
            unsigned int var7;
            void* var8;
            var5->GetLoadedFileByID(arg0->unknown_24_, &var8, &var7);
            arg0->unknown_10_.CreateTypeA(func_02012d88(&data_02114e20, 0x2800), 0x2800);
            arg0->unknown_10_.Reset();
            Struct_0203d028* var9 = (Struct_0203d028*)(*(char**)((char*)var0->GetUnknownGameObject() + Enum_ov017_021abba8_340) + 0x568);
            func_0207df50(var9);
            void* var10 = arg0->unknown_10_.Allocate(var7);
            memcpy(var10, var8, var7);
            func_02057e6c(var4, 5, &arg0->unknown_10_, var10, var7, var9);
            var5->RemoveTask(arg0->unknown_24_);
            arg0->unknown_8_++;
        }
    } else if (arg0->unknown_8_ == 2) {
        int var11 = 0;
        int var12[5];
        Struct_ov017_021abba8_2 var13[5];
        if (arg0->unknown_c_ != 0) {
            func_02010834((Struct_02010834*)var0, var3->obj3D_.unknown_4_, var12, &var11);
            for (int var14 = 0; var14 < var11; var14++) {
                arg0->unknown_d_ |= 1 << var12[var14];
            }
            if (var0->GetGameObjectByIndex(0xce) && func_0202c508(var1)) {
                var12[var11] = 0xce;
                arg0->unknown_d_ |= 0x10;
                var11++;
            }
        } else {
            for (int var15 = 0; var15 < 5; var15++) {
                if (arg0->unknown_d_ & (1 << var15)) {
                    if (var15 != 4) {
                        var12[var11] = var15;
                    } else {
                        var12[var11] = 0xce;
                    }
                    var11++;
                }
            }
        }
        for (int var16 = 0; var16 < var11; var16++) {
            GameObject* var17 = var0->GetGameObjectByIndex(var12[var16]);
            if (var17) {
                var13[var16].unknown_0_ = 0;
                var13[var16].unknown_10_ = 1;
                var13[var16].unknown_12_ = 0;
                var13[var16].unknown_14_ = -1;
                var13[var16].unknown_16_ = -1;
                var13[var16].unknown_18_ = -1;
                var13[var16].unknown_1a_ = -1;
                var13[var16].unknown_1c_ = -0x1000;
                var13[var16].unknown_20_ = 0;
                var13[var16].unknown_24_ = 0;
                var13[var16].unknown_28_ = 0;
                var13[var16].unknown_2c_.x = 0;
                var13[var16].unknown_2c_.y = 0;
                var13[var16].unknown_2c_.z = 0;
                var13[var16].unknown_38_ = 0;
                var13[var16].unknown_3c_ = 0;
                var13[var16].unknown_40_ = 0;
                var13[var16].unknown_44_.x = 0x1000;
                var13[var16].unknown_44_.y = 0x1000;
                var13[var16].unknown_44_.z = 0x1000;
                var13[var16].unknown_11_0_ = 0;
                var13[var16].unknown_11_1_ = 0;
                var13[var16].unknown_11_2_ = 1;
                var13[var16].unknown_11_3_ = 0;
                var13[var16].unknown_11_4_ = 0;
                var13[var16].unknown_11_5_ = 0;
                var13[var16].unknown_11_6_ = 0;
                var13[var16].unknown_11_7_ = 0;
                var13[var16].unknown_2c_ = var17->obj3D_.position_;
                var13[var16].unknown_44_ = var17->obj3D_.GetScale();
                func_02057fb4(var4, 5, &var13[var16]);
            }
        }
        self->state++;
    } else if (self->state == 3) {
        self->timer += delta;
        if (self->timer > 8) {
            SetForwardAndStore0205ebc0(&g_sePlayer, 0xb1, 0xb1);
            DispatchIfField0xc4NonNeg_0205ebfc(&g_sePlayer, 0, 0);
            self->state++;
        }
    } else if (arg0->unknown_8_ == 4) {
        arg0->unknown_a_ += var6;
        if (arg0->unknown_a_ > 0x32) {
            for (int var18 = 0; var18 < 5; var18++) {
                if (arg0->unknown_d_ & (1 << var18)) {
                    GameObject* var19 = var0->GetGameObjectByIndex(var18 != 4 ? var18 : 0xce);
                    if (var19) {
                        var19->obj3D_.EnableFlag(1);
                    }
                }
            }
            arg0->unknown_8_++;
        }
    } else if (arg0->unknown_8_ == 5) {
        arg0->unknown_a_ += var6;
        if (arg0->unknown_a_ > 0x6e) {
            SetBrightness(var2, -0x10, 0x1e);
            arg0->unknown_8_++;
        }
    } else if (arg0->unknown_8_ == 6) {
        arg0->unknown_a_ += var6;
        if (arg0->unknown_a_ > 0xaa && !IsBrightnessTransitionActive(var2)) {
            for (int var20 = 0; var20 < 5; var20++) {
                if (arg0->unknown_d_ & (1 << var20)) {
                    GameObject* var21 = var0->GetGameObjectByIndex(var20 != 4 ? var20 : 0xce);
                    if (var21) {
                        var21->obj3D_.DisableFlag(1);
                    }
                }
            }
            ClearFlags00(res, 0x10);
            CallListIfFlagsSet_02197528();
            self->done = 1;
            SetByteField0x253_020397c0(leader);
            func_ov017_021ac2a8(self);
            ForwardField0xc0_0205ebec(&g_sePlayer);
            if (func_0202c508(search)) {
                unsigned char* flags = (unsigned char*)func_0205ec34();
                func_0206df6c(flags, flags + 0x8c, 0x113d, 1);
            }
            if (func_02011b50(var0, 1) && arg0->unknown_c_ != 0) {
                Struct_0201bdac_2* var23;
                unsigned char* var24 = (unsigned char*)var2->unknown_ptr_array_3afc[0x14];
                var23 = (Struct_0201bdac_2*)var2->unknown_ptr_array_36fc[0];
                func_ov017_021b2174(var24);
                func_ov017_021b2ba0((Struct_0206f81c_2*)var24, &data_ov017_021d78f1);
                func_ov017_021b2bd0(var24, (int)func_ov004_021689d8, OVERLAY_ID(4));
                func_ov017_021b2bf4((Struct_0206f81c_3*)var24, 1);
                func_ov017_021b2c0c((Struct_0206f81c_4*)var24, 1);
                func_ov017_021b2bdc((Struct_0206f81c_5*)var24, 0);
                func_020469b4(var23, (Struct_0201bdac*)var24);
            }
        }
    }
}
