#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
#include "NitroSDK/OverlayId.h"
#include "World/Object3D.h"
#include "Input/Input.h"
#include "Resource/Brightness.h"

#if defined(jpn)
#define func_0205ec34 func_0205ff20
#endif

#if defined(jpn)
#define func_0206df6c func_0206f0c0
#endif

struct Struct_02018300_3;
struct Struct_0209494c;
struct Struct_0203d028;
struct Struct_02010834;
struct Struct_0206f81c_2;
struct Struct_0206f81c_3;
struct Struct_0206f81c_4;
struct Struct_0206f81c_5;
struct Struct_0201bdac_2;
struct Struct_0201bdac;
struct Struct_020469f8;
struct Struct_020469f8_2;
struct Struct_ov003_021638e4_2;

#if defined(jpn)
struct Struct_02046574_2;
extern "C" void func_02046574(Struct_02046574_2*, int, char*);
extern "C" void func_0204500c(void* arg0, const char* arg1, int arg2);
extern "C" char data_ov017_021d7f3b;
enum { Enum_ov017_021acdf4_17582 = 0x41fe, Enum_ov017_021acdf4_17584 = 0x4200, Enum_ov017_021acdf4_6578 = 0x17e2, Enum_ov017_021acdf4_2456 = 0x868, Enum_ov017_021acdf4_32648 = 0x7cb4, Enum_ov017_021acdf4_32636 = 0x7ca8 };
#else
enum { Enum_ov017_021acdf4_17582 = 0x44ae, Enum_ov017_021acdf4_17584 = 0x44b0, Enum_ov017_021acdf4_6578 = 0x19b2, Enum_ov017_021acdf4_2456 = 0x998, Enum_ov017_021acdf4_32648 = 0x7f88, Enum_ov017_021acdf4_32636 = 0x7f7c };
#endif

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

struct Struct_ov017_021acdf4 {
    char unknown_0_;
    unsigned char unknown_1_;
    char unknown_2_[6];
    SafeAllocator unknown_8_;
    char unknown_1c_[0x1c - 8 - sizeof(SafeAllocator)];
    unsigned char unknown1_1c_;
    unsigned char unknown_1d_;
    unsigned char unknown_1e_;
    unsigned char unknown_1f_;
    Vector3i unknown_20_;
    char unknown_2c_[0x14];
    short unknown_40_;
    char unknown_42_[2];
#if defined(jpn)
    unsigned char unknown_44_[0x20c - 0x44];
#else
    unsigned char unknown_44_[0x27c - 0x44];
#endif
    unsigned char unknown_27c_;
    unsigned char unknown_27d_;
    unsigned char unknown_27e_;
    unsigned char unknown_27f_;
    unsigned char unknown_280_;
    unsigned char unknown_281_;
    unsigned char unknown_282_;
};

extern "C" void* func_0202ae18(void);
extern "C" void* func_02057924(void);
extern "C" void func_0205c904(unsigned char* arg0, int arg1);
extern "C" void func_020397cc(Struct_02018300_3* arg0, int arg1);
extern "C" Struct_0209494c* func_020936f8(void);
extern "C" int func_0209494c(Struct_0209494c* arg0);
extern "C" void func_020a0cc4(unsigned int arg0);
extern "C" void func_020a0c0c(void);
extern "C" void func_ov017_021adb50(char* arg0);
extern "C" unsigned char* func_0200fd0c(GameState* arg0);
extern "C" void func_02070378(char* arg0);
extern "C" void* func_02012d88(AllocatorUnion* arg0, unsigned int arg1);
extern "C" void func_0207df50(Struct_0203d028* arg0);
extern "C" void func_0205ce94(unsigned char* arg0);
extern "C" int func_02057e6c(void* arg0, int arg1, SafeAllocator* arg2, void* arg3, unsigned int arg4, Struct_0203d028* arg5);
extern "C" void func_02010834(Struct_02010834* arg0, int arg1, int* arg2, int* arg3);
extern "C" int func_0202c508(void* arg0);
extern "C" void func_02057fb4(void* arg0, int arg1, void* arg2);
extern "C" int func_0202b7d8(int* arg0);
extern "C" void func_ov017_021ce014(int arg0, unsigned short arg1, unsigned short arg2, unsigned short arg3);
extern "C" void func_0205ebc0(void* arg0, int arg1, int arg2);
extern "C" void func_0205ebfc(void* arg0, int arg1, int arg2);
void SetBrightness(GameResources* resources, int brightness, int duration);
extern "C" void func_ov017_021a65c4(void* arg0, unsigned char arg1, int arg2);
extern "C" void func_ov017_0219e310(unsigned char* arg0, int arg1);
extern "C" void func_020469b4(Struct_0201bdac_2* arg0, Struct_0201bdac* arg1);
extern "C" void func_0200fb40(void* arg0);
extern "C" int func_02011b50(void* arg0, int arg1);
extern "C" void func_ov017_021b2174(unsigned char* arg0);
extern "C" void func_ov017_021b2ba0(Struct_0206f81c_2* arg0, char* arg1);
extern "C" void func_ov017_021b2bd0(void* arg0, int arg1, int arg2);
extern "C" void func_ov017_021b2bf4(Struct_0206f81c_3* arg0, unsigned int arg1);
extern "C" void func_ov017_021b2c0c(Struct_0206f81c_4* arg0, unsigned int arg1);
extern "C" void func_ov017_021b2bdc(Struct_0206f81c_5* arg0, unsigned int arg1);
extern "C" void func_ov004_021689d8(SafeAllocator* arg0, void* arg1);
extern "C" void* func_0205ec34(void);
extern "C" void func_0206df6c(void* arg0, unsigned char* arg1, int arg2, int arg3);
int IsBrightnessTransitionActive(GameResources* resources);
extern "C" void func_02057f00(void* arg0, int arg1);
extern "C" void func_0205ebec(void* arg0);
extern "C" void func_ov017_02197528(void);
extern "C" void func_020397c0(void* arg0);
extern "C" void func_02039d58(unsigned char* arg0);
extern "C" void func_ov017_021c37a4(void);
extern "C" void func_ov017_021b11b0(Struct_ov003_021638e4_2* arg0);
extern "C" void func_020469f8(Struct_020469f8* arg0, Struct_020469f8_2* arg1);
extern "C" int func_020421a0(void);
extern "C" void func_020e4c74(void* arg0, GameObject* arg1);
extern "C" int func_020e51cc(int arg0);
#if !defined(jpn)
extern "C" void func_0204500c(void* arg0, int arg1, int arg2, int arg3);
#endif
extern "C" int func_020100f8(char* arg0);
extern "C" void func_0202ea10(unsigned char* arg0, int arg1, int arg2);
extern "C" int func_020a277c(void* arg0);
extern "C" void func_020a2770(void* arg0, short arg1);
extern "C" void func_0205ec20(void* arg0, void* arg1, int arg2);
extern "C" void func_ov017_02191108(GameResources* arg0, int arg1, int arg2, int arg3, int arg4);
extern "C" void func_02043204(char* arg0);
extern "C" void func_ov017_021adb1c(Struct_ov017_021acdf4* arg0);

extern AllocatorUnion data_02114e20;
extern char data_ov017_021d795c;
extern char data_ov017_021d7978;
extern char g_sePlayer;
extern char data_ov017_021d798f;

struct Struct_01ff91ac_21 {
    char unknown_0_[0xa];
    unsigned char unknown_a_;
    void inline_ov017_021acdf4(unsigned char arg0) { unknown_a_ = arg0; }
};

static inline Struct_01ff91ac_21* inline_ov017_021acdf4_2(GameResources* arg0) {
    return (Struct_01ff91ac_21*)arg0->unknown_ptr_array_3afc[0x24];
}

// USA: func_ov017_021acdf4
extern "C" ARM void func_ov017_021acdf4(Struct_ov017_021acdf4* arg0, Struct_020469f8* arg1) {
    GameState* var0 = GameState::GetInstance();
    GameResources* var1 = GetGameResources();
    GameObject* var2 = var0->GetUnknownGameObject();
    void* var3 = func_02057924();
    BackgroundLoader* var4 = BackgroundLoader::GetInstance();

    if (var2 == NULL) {
        arg0->unknown_1_ = 1;
        func_ov017_021adb1c(arg0);
    }
    unsigned int var5 = var0->GetTickCount();
    func_0205c904(arg0->unknown_44_, var5 ? var5 : 1);
    func_020397cc((Struct_02018300_3*)var2, 1);
    *(short*)((char*)var2 + 0xb2) = 0;

    if (arg0->unknown1_1c_ == 0) {
        if (arg0->unknown_280_ && !func_0209494c(func_020936f8())) {
            return;
        }
        func_020a0cc4(0x7000);
        if (arg0->unknown_282_) {
            func_ov017_021adb50((char*)arg0);
        }
        if (arg0->unknown_281_) {
            unsigned char* var6 = func_0200fd0c(var0);
            func_02070378((char*)var6);
            var6[2] = 1;
            *(unsigned short*)var6 = 0xc3b5;
            var6[7] = 1;
            *(short*)(var6 + 0x1c) = 0;
            *(int*)(var6 + 0x10) = 0x48cc;
            *(int*)(var6 + 0x14) = 0x199;
            *(int*)(var6 + 0x18) = -0x733;
            var6[0x66] = 1;
            var6[0x65] = 1;
        }
        arg0->unknown_8_.CreateTypeA(func_02012d88(&data_02114e20, 0x7000), 0x7000);
        arg0->unknown_8_.Reset();
        if (arg0->unknown_280_) {
            arg0->unknown_40_ = var4->QueueLoadFile(&data_ov017_021d795c, &arg0->unknown_8_);
        } else {
            arg0->unknown_40_ = var4->QueueLoadFile(&data_ov017_021d7978, &arg0->unknown_8_);
        }
        arg0->unknown1_1c_ = 0xe;
    } else if (arg0->unknown1_1c_ == 0xe) {
        if (var4->GetTaskStatus(arg0->unknown_40_) == 0) {
            return;
        }
        if (arg0->unknown_280_ && !arg0->unknown_27f_) {
            if (g_keyManager.TestKeysPressed(0x401) == 0 && g_touchInput.released_ == 0) {
                return;
            }
        }
        Struct_0203d028* var7 = (Struct_0203d028*)((char (*)[0x70])var1->unknown_2cc_)[0x1c];
        func_0207df50(var7);
        unsigned int var8;
        void* var9;
        var4->GetLoadedFileByID(arg0->unknown_40_, &var9, &var8);
        if (var9 == NULL) {
            var4->RemoveTask(arg0->unknown_40_);
            func_ov017_021adb1c(arg0);
            func_020a0c0c();
            arg0->unknown_1_ = 1;
            return;
        }
        if (arg0->unknown_280_ && !arg0->unknown_27f_) {
            func_0205ce94(arg0->unknown_44_);
        }
        func_02057e6c(var3, 8, &arg0->unknown_8_, var9, var8, var7);
        var4->RemoveTask(arg0->unknown_40_);
        arg0->unknown1_1c_ = 1;
    } else if (arg0->unknown1_1c_ == 1) {
        int var10 = 0;
        int var11[5];
        Struct_ov017_021abba8_2 var12[5];
        Vector3i var13;
        void* var14 = func_0202ae18();
        func_02010834((Struct_02010834*)var0, *(short*)((char*)var2 + 4), var11, &var10);
        for (int var15 = 0; var15 < var10; var15++) {
            arg0->unknown_1e_ |= 1 << var11[var15];
        }
        if (var0->GetGameObjectByIndex(0xce) && func_0202c508(var14)) {
            var11[var10] = 0xce;
            arg0->unknown_1e_ |= 0x10;
            var10++;
        }
        GameObject* var16 = var0->GetUnknownGameObject();
        int var17 = -1;
        if (var16) {
            var17 = *(short*)((char*)var16 + 4);
        }
        for (int var18 = 0; var18 < var10; var18++) {
            GameObject* var19 = var0->GetGameObjectByIndex(var11[var18]);
            if (var19 && ((Object3D*)var19)->IsVisible() && ((Object3D*)var19)->GetInheritedAlpha()) {
                if (TestFlags04((GameResources*)var1, 4) == 0 || var17 == var11[var18]) {
                    var12[var18].unknown_0_ = 0;
                    var12[var18].unknown_10_ = 1;
                    var12[var18].unknown_12_ = 0;
                    var12[var18].unknown_14_ = -1;
                    var12[var18].unknown_16_ = -1;
                    var12[var18].unknown_18_ = -1;
                    var12[var18].unknown_1a_ = -1;
                    var12[var18].unknown_1c_ = -0x1000;
                    var12[var18].unknown_20_ = 0;
                    var12[var18].unknown_24_ = 0;
                    var12[var18].unknown_28_ = 0;
                    var12[var18].unknown_2c_.x = 0;
                    var12[var18].unknown_2c_.y = 0;
                    var12[var18].unknown_2c_.z = 0;
                    var12[var18].unknown_38_ = 0;
                    var12[var18].unknown_3c_ = 0;
                    var12[var18].unknown_40_ = 0;
                    var12[var18].unknown_44_.x = 0x1000;
                    var12[var18].unknown_44_.y = 0x1000;
                    var12[var18].unknown_44_.z = 0x1000;
                    var12[var18].unknown_11_0_ = 0;
                    var12[var18].unknown_11_1_ = 0;
                    var12[var18].unknown_11_2_ = 1;
                    var12[var18].unknown_11_3_ = 0;
                    var12[var18].unknown_11_4_ = 0;
                    var12[var18].unknown_11_5_ = 0;
                    var12[var18].unknown_11_6_ = 0;
                    var12[var18].unknown_11_7_ = 0;
                    var12[var18].unknown_2c_ = ((Object3D*)var19)->position_;
                    var12[var18].unknown_44_ = ((Object3D*)var19)->GetScale();
                    func_02057fb4(var3, 8, &var12[var18]);
                }
            }
        }
        int var20;
        unsigned char var21;
        if (func_0202b7d8((int*)func_0202ae18()) && (var21 = arg0->unknown_1e_) != 0) {
            var20 = *(short*)((char*)var2 + 4);
            func_ov017_021ce014(var20, 3, (int)((Object3D*)var2)->GetField06(), var21);
        }
        if (self->special) {
            SetForwardAndStore0205ebc0(&g_sePlayer, 0xa3, 0xa3);
            DispatchIfField0xc4NonNeg_0205ebfc(&g_sePlayer, 5, 0);
        } else {
            SetForwardAndStore0205ebc0(&g_sePlayer, 0xb2, 0xb2);
            DispatchIfField0xc4NonNeg_0205ebfc(&g_sePlayer, 0, 0);
        }
        arg0->unknown1_1c_++;
    } else if (arg0->unknown1_1c_ == 2) {
        arg0->unknown_1d_ += var0->GetTickCount();
        unsigned int var22 = arg0->unknown_280_ ? 0x19 : 0x28;
        if (var22 < arg0->unknown_1d_) {
            for (int var23 = 0; var23 < 5; var23++) {
                if (arg0->unknown_1e_ & (1 << var23)) {
                    GameObject* var24 = var0->GetGameObjectByIndex(var23 != 4 ? var23 : 0xce);
                    if (var24) {
                        ((Object3D*)var24)->EnableFlag(1);
                    }
                }
            }
            if (arg0->unknown_27e_) {
                arg0->unknown1_1c_ = 0xa;
            } else {
                arg0->unknown1_1c_++;
            }
        }
    } else if (arg0->unknown1_1c_ == 3) {
        arg0->unknown_1d_ += var0->GetTickCount();
        if (arg0->unknown_1d_ > 0x64) {
            if (arg0->unknown_27f_) {
                SetBrightness(var1, 0x10, 0x1e);
            } else {
                SetBrightness(var1, -0x10, 0x1e);
            }
            arg0->unknown1_1c_++;
        }
    } else if (arg0->unknown1_1c_ == 4) {
        arg0->unknown_1d_ += var0->GetTickCount();
        if (arg0->unknown_1d_ > 0x8c) {
            for (int var25 = 0; var25 < 5; var25++) {
                if (arg0->unknown_1e_ & (1 << var25)) {
                    GameObject* var26 = var0->GetGameObjectByIndex(var25 != 4 ? var25 : 0xce);
                    if (var26) {
                        ((Object3D*)var26)->DisableFlag(1);
                    }
                }
            }
            if (!arg0->unknown_27c_) {
                if (arg0->unknown_280_) {
                    func_ov017_021a65c4(var1, 2, arg0->unknown_27d_);
                } else {
                    func_ov017_021a65c4(var1, 0, arg0->unknown_27d_);
                }
                if (arg0->unknown_280_ && !arg0->unknown_27f_) {
                    inline_ov017_021acdf4_2(var1)->inline_ov017_021acdf4(1);
                }
            }
            if (arg0->unknown_27c_) {
                unsigned char* var27;
                GameResources* var28;
                GameState* var29;
                Struct_ov017_021acdf4* var30;
                var29 = GameState::GetInstance();
                var27 = func_0200fd0c(var29);
                var28 = GetGameResources();
                var30 = (Struct_ov017_021acdf4*)var28->unknown_ptr_array_3afc[9];
                func_02070378((char*)var27);
                var27[4] = 0;
                var27[5] = 1;
                *(unsigned short*)var27 = *(unsigned short*)((char*)var29 + Enum_ov017_021acdf4_32648);
                *(Vector3i*)(var27 + 0x10) = *(Vector3i*)((char*)var29 + Enum_ov017_021acdf4_32636);
                var27[7] = 1;
                var27[0x62] = 1;
                var27[0x63] = var30->unknown_27d_;
                if (*(unsigned short*)((char*)var29 + Enum_ov017_021acdf4_32648) == 0x2710) {
                    *(short*)var27 = 0x170c;
                    *(int*)(var27 + 0x10) = -0x7000;
                    *(int*)(var27 + 0x14) = 0x2e1;
                    *(int*)(var27 + 0x18) = 0;
                    if (var27[0x63]) {
                        var27[0x64] = 1;
                    }
                }
                func_ov017_0219e310((unsigned char*)var28->unknown_ptr_array_36fc[4], 0);
                func_020469b4((Struct_0201bdac_2*)var28->unknown_ptr_array_36fc[0], (Struct_0201bdac*)var28->unknown_ptr_array_36fc[4]);
                func_0200fb40(var29);
                func_ov017_021a65c4(var1, 0, arg0->unknown_27d_);
            } else if (func_02011b50(var0, 1)) {
                Struct_0201bdac_2* var31;
                unsigned char* var32 = (unsigned char*)var1->unknown_ptr_array_3afc[0x14];
                var31 = (Struct_0201bdac_2*)var1->unknown_ptr_array_36fc[0];
                func_ov017_021b2174(var32);
                func_ov017_021b2ba0((Struct_0206f81c_2*)var32, &data_ov017_021d798f);
                func_ov017_021b2bd0(var32, (int)func_ov004_021689d8, OVERLAY_ID(4));
                func_ov017_021b2bf4((Struct_0206f81c_3*)var32, 1);
                func_ov017_021b2c0c((Struct_0206f81c_4*)var32, 1);
                func_ov017_021b2bdc((Struct_0206f81c_5*)var32, 0);
                func_020469b4(var31, (Struct_0201bdac*)var32);
            }
            if (func_0202c508(func_0202ae18())) {
                unsigned char* var33 = (unsigned char*)func_0205ec34();
                func_0206df6c(var33, var33 + 0x8c, 0x113d, 1);
            }
            if (arg0->unknown_27f_) {
                arg0->unknown1_1c_ = 6;
            } else {
                arg0->unknown1_1c_++;
            }
        }
    } else if (arg0->unknown1_1c_ == 5) {
        if (IsBrightnessTransitionActive(var1)) {
            return;
        }
        func_02057f00(mgr, 8);
        ForwardField0xc0_0205ebec(&g_sePlayer);
        CallListIfFlagsSet_02197528();
        self->done = 1;
        SetByteField0x253_020397c0(leader);
        ((Object3D*)leader)->SetInheritedAlpha(0x1f);
        ClearFlag0x1ceBit0x4_02039d58((unsigned char*)leader);
        func_ov017_021adb1c(self);
        func_020a0c0c();
        if (arg0->unknown_280_) {
            func_ov017_021c37a4();
        }
        *(short*)((char*)var1 + Enum_ov017_021acdf4_17582) = 0;
        *(short*)((char*)var1 + Enum_ov017_021acdf4_17584) = 0;
    } else if (arg0->unknown1_1c_ == 6) {
        if (IsBrightnessTransitionActive(var1)) {
            return;
        }
        Struct_ov003_021638e4_2* var34 = (Struct_ov003_021638e4_2*)var1->unknown_ptr_array_3afc[0xe];
        func_ov017_021b11b0(var34);
        func_020469f8(arg1, (Struct_020469f8_2*)var34);
        arg0->unknown1_1c_ = 5;
    } else if (arg0->unknown1_1c_ == 0xa) {
        arg0->unknown_1d_ += var0->GetTickCount();
        if (arg0->unknown_1d_ > 0x37) {
            for (int var35 = 0; var35 < 5; var35++) {
                if (arg0->unknown_1e_ & (1 << var35)) {
                    char* var36 = (char*)var0->GetPartyMemberByIndex(var35 != 4 ? var35 : 0xce);
                    if (var36) {
                        ((Object3D*)var36)->DisableFlag(1);
                        *(short*)(var36 + 0x12c) = 0;
                        *(int*)(var36 + 0x124) = *(int*)(var36 + 0x48) + 0x9ccc;
                        *(int*)(var36 + 0x128) = *(int*)(var36 + 0x48);
                    }
                }
            }
            char* var37 = (char*)func_020421a0();
#if defined(jpn)
            func_02046574((Struct_02046574_2*)var37, 0, *(char**)((char*)var0->GetUnknownGameObject() + 0x134));
            func_0204500c(var37, &data_ov017_021d7f3b, 0);
#else
            char var38[0xc];
            func_020e4c74(var38, var0->GetUnknownGameObject());
            *(char**)var37 = var38;
            func_0204500c(var37, func_020e51cc(0x39), 0, 0xe3);
#endif
            g[MessageDone] = 0;
            *(int*)(g + MessageActive) = 1;
            unsigned char* obj = (unsigned char*)GetFieldIfFlag4_020100f8((char*)gs);
            StoreFields0x1e4And0x1e8IfNonZero_0202ea10(obj, 0xcc, 0x3e8);
            self->savedPos = *(Vector3i*)(obj + 0x10);
            self->savedField = GetField0x21c020a277c(obj);
            SetField0x21c_020a2770(obj, -1);
            *(Vector3i*)(obj + 0x10) = self->savedPos;
            Forward0205ec20(&g_sePlayer, 0, 0);
            DispatchIfField0xc4NonNeg_0205ebfc(&g_sePlayer, 1, 0);
            self->state++;
        }
    } else if (arg0->unknown1_1c_ == 0xb) {
        *(Vector3i*)((char*)func_020100f8((char*)var0) + 0x10) = arg0->unknown_20_;
        int var40 = 1;
        for (int var41 = 0; var41 < 5; var41++) {
            if (arg0->unknown_1e_ & (1 << var41)) {
                char* var42 = (char*)var0->GetPartyMemberByIndex(var41 != 4 ? var41 : 0xce);
                if (var42 && *(int*)(var42 + 0x124)) {
                    var40 = 0;
                }
            }
        }
        if (var40) {
            arg0->unknown_1d_ = 0;
            arg0->unknown1_1c_++;
        }
        return;
    } else if (arg0->unknown1_1c_ == 0xc) {
        arg0->unknown_1d_ += var0->GetTickCount();
        if (arg0->unknown_1d_ > 10) {
            arg0->unknown1_1c_++;
        }
    } else if (self->state == 0xd) {
        char* g = (char*)GetGlobalField0x1c020421a0();
        SetField0x21c_020a2770((void*)GetFieldIfFlag4_020100f8((char*)gs), self->savedField);
        func_02057f00(mgr, 8);
        ForwardField0xc0_0205ebec(&g_sePlayer);
        for (int i = 0; i < 5; i++) {
            if (self->members & (1 << i)) {
                GameObject* member = gs->GetGameObjectByIndex(i != 4 ? i : 0xce);
                if (member) {
                    ((Object3D*)member)->DisableFlag(1);
                }
            }
        }
        arg0->unknown_1_ = 1;
        func_ov017_02191108(var1, 1, 1, 1, 1);
        func_020397c0(var2);
        func_02043204(var43);
        func_ov017_021adb1c(arg0);
        func_020a0c0c();
    }
}
