#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"
#include "Resource/GameResources.h"
#include "Combat/Main/BattleList.h"
#include "Util/Random.h"
#include "Resource/CharacterCreationUI.h"
#include "Resource/Brightness.h"

struct Struct_ov026_021d8ba0_4;
struct Struct_ov000_02160da0;
struct Struct_ov000_02161e30;
struct Struct_ov000_0217e870_2;
struct Struct_ov026_021d8ba0_5;
struct Struct_ov023_021f4c04;
struct Struct_ov026_021d8ba0_6;
struct Struct_ov026_021d8ba0_7;
struct Struct_ov026_021d8ba0_8;
struct Struct_ov026_021d8ba0_9;
struct Struct_020a36a8;
struct Struct_0200f3a4_8;
struct Struct_0209a470;
struct Struct_02086f24_6;
struct Struct_02013fb4;
struct Struct_0204671c;
struct Struct_020d6ec8;
struct Struct_ov000_02163a7c;
struct Struct_02010088;
struct Struct_ov026_021d8ba0_10;
struct Struct_0203c108_3;
struct Struct_02053dc0;
struct Struct_02010604;
struct Struct_02015ef4_5;
struct Struct_020e385c;
struct Struct_02046574_2;
struct Struct_02012de8;
struct Struct_02038598_4;
struct Struct_0202b2f0;
struct Struct_02053dd0;

struct Struct_ov026_021d8ba0 {
    unsigned char unknown_0_[4];
    signed char unknown_4_;
    unsigned short unknown_6_;
    unsigned short unknown_8_;
};

struct Struct_ov026_021de6dc { int unknown_0_[3]; };
struct Struct_ov026_021d8ba0_2 { int unknown_0_, unknown_4_; };
struct Struct_020e6e88 { char unknown_0_[0x80]; };
struct Struct_ov026_021d8ba0_3 {
    char unknown_0_[8][3];
    int unknown_18_;
    const char* unknown_1c_[8];
};

inline Struct_ov026_021d8ba0_3& inline_ov026_021d8ba0_2() {
    static Struct_ov026_021d8ba0_3 s = {
        {"f4", "f3", "f1", "f2", "b4", "b1", "b2", "b3"},
        -1,
        {s.unknown_0_[2], s.unknown_0_[3], s.unknown_0_[1], s.unknown_0_[0], s.unknown_0_[5], s.unknown_0_[6], s.unknown_0_[7], s.unknown_0_[4]},
    };
    return s;
}

struct Struct_ov000_0215440c_6 {
    unsigned char unknown_0_;
    unsigned char unknown_1_0_ : 4;
    unsigned char unknown_1_4_ : 2;
    unsigned char unknown_1_6_ : 2;
    unsigned char unknown_2_[4];
    unsigned char unknown_6_[8];
    unsigned char unknown_e_0_ : 4;
    unsigned char unknown_e_4_ : 4;
    unsigned char unknown_f_[9];
};

extern "C" int func_020100a8(GameState*);
extern "C" Struct_ov026_021d8ba0_6* func_ov026_021dae60(Struct_ov026_021d8ba0_4*, int);
extern "C" Struct_ov023_021f4c04* func_020421a0();
extern "C" void* func_0202ae24();
extern "C" void* func_020d6c00();
extern "C" unsigned char* func_020e3580();
extern "C" int func_ov000_0215fc60(char*);
extern "C" void func_ov000_02160d80(void*, int);
extern "C" void func_ov000_02160fa8(void*, int);
extern "C" void func_ov000_02160fbc(void*, int);
extern "C" int func_ov000_02160fd4(void*, int);
extern "C" void func_ov000_0218173c(void*);
extern "C" int func_02012060(void*);
extern "C" int func_0202b7d8(int*);
extern "C" int func_020a36a8(Struct_020a36a8*);
extern "C" void func_ov000_0215e8e8(void*);
extern "C" void func_0209a338(Struct_0200f3a4_8*);
extern "C" void func_0209a470(Struct_0209a470*, SafeAllocator*, Struct_02013fb4*, int);
extern "C" void func_0209a804(int*);
extern "C" void func_0209a8b4(Struct_02086f24_6*, SafeAllocator*, Struct_02013fb4*, int);
extern "C" void func_0205eb80(void*);
extern "C" int func_0204671c(Struct_0204671c*);
extern "C" void func_ov000_02180b3c(void*);
extern "C" Struct_ov026_021d8ba0_8* func_ov000_0216f208(void*);
extern "C" void func_ov000_0216118c(void*, int);
extern "C" void func_ov000_02163710(void*, int);
extern "C" void func_ov000_02167e6c(unsigned char*);
extern "C" Struct_020d6ec8* func_ov000_02163524(void*);
extern "C" void func_020d6f44(Struct_020d6ec8*);
extern "C" void func_020d738c(void*);
extern "C" void func_ov000_02163a7c(Struct_ov000_02163a7c*);
extern "C" int func_020493a4(unsigned char*);
extern "C" void func_02049390(unsigned char*, unsigned char);
extern "C" void func_02049bd4(unsigned char*, int*);
extern "C" void func_02043204(char*);
extern "C" void func_ov000_02174dc0(void*);
extern "C" GameObject* func_0200fea4(GameState*, int);
extern "C" char* func_0200ff58(GameState*, int);
extern "C" int func_02010088(Struct_02010088*);
extern "C" int func_ov026_021dd3c4(Struct_ov026_021d8ba0_10*);
extern "C" void func_0203c108(Struct_0203c108_3*, char*);
extern "C" void func_ov000_021744f4(int, void*);
extern "C" void func_ov000_02176054(void*);
extern "C" int func_020a35e0(unsigned char*, unsigned char);
extern "C" void* func_02053dc0(Struct_02053dc0*);
extern "C" void func_02033b88(Struct_02010604*, int);
extern "C" void func_ov000_02181364(void*);
extern "C" void func_ov000_021816e8(void*, int);
extern "C" void func_ov000_02181694(void*, int);
extern "C" void func_ov000_0217f5d0(void*);
extern "C" void func_0207dfc8(Struct_02015ef4_5*, Struct_02015ef4_5*);
extern "C" void func_ov017_021ca174(unsigned short);
extern "C" Struct_020e385c* func_020e3808();
extern "C" int func_020e3ad0(Struct_020e385c*, int, int);
extern "C" unsigned char* func_020e385c(Struct_020e385c*, int, int);
extern "C" void func_020e3994(Struct_020e385c*, int, int);
void SetBrightness(GameResources*, int, int);
extern "C" int func_02046b08(void**);
extern "C" void func_ov000_02174514(void*);
extern "C" void func_02088e64(unsigned char*);
extern "C" void* func_020e0434(Struct_0201099c_3*, int);
extern "C" void func_02046574(Struct_02046574_2*, int, char*);
extern "C" int func_02046708(Struct_02012de8*, unsigned int);
extern "C" void func_020466e4(unsigned int*, unsigned int);
extern "C" void func_020466f4(Struct_02038598_4*, unsigned int);
extern "C" int func_020e37e8(unsigned char*);
extern "C" void func_020e3798(unsigned char*);
extern "C" void func_020e36f0(unsigned char*);
extern "C" int func_ov000_0217fb98(void*);
extern "C" void func_ov000_02162c90(char*, int, int);
extern "C" int func_0202c1c0(Struct_0202b2f0*, int);
extern "C" int func_ov000_02168720(char*);
extern "C" void func_ov000_021813d4(void*);
extern "C" void func_0205eb54(void*, int, int);
extern "C" void func_0205eb90(void*, int, int);
extern "C" void func_ov017_021cefe0(unsigned short, unsigned char, unsigned char);
extern "C" void func_ov017_021cf650(unsigned short, int, int);
extern "C" int func_0205e488(void*);
extern "C" void func_02053dd0(Struct_02053dd0*);
extern "C" void func_ov000_021637c8(void*);

extern "C" {
int* func_0202ae18();
void func_ov026_021d8aac( Struct_ov000_02160da0*, int arg1, int arg2);
void func_ov000_02181608(void*);
void func_ov000_0218048c(void*);
void func_ov000_02162cbc( Struct_ov000_02160da0*);
void func_ov000_021626a0( Struct_ov000_02160da0*, int, int);
void func_ov000_021629ec( Struct_ov000_02160da0*);
int func_ov000_0215e9fc(Struct_ov000_02161e30*, short*, int, int);
int func_ov000_0215ec1c(Struct_ov000_02161e30*, short*, int, int);
int func_ov000_0215eb1c(Struct_ov000_02161e30*, short*, int, int);
Struct_ov026_021d8ba0_2 func_ov000_0216f74c(int* arg0);
void func_02043124(Struct_ov023_021f4c04*);
void func_ov026_021daec8(Struct_ov000_02161e30*, void*, int);
void func_ov000_02174614(void*, int);
void func_020e4864(void*, char*, int, int, int, int);
void __clear(void*, int);
void func_02046608(Struct_ov023_021f4c04*, int, char*, char*, int, int, int);
void func_ov000_0217f518(Struct_ov026_021d8ba0_6*);
void func_ov000_02162c14( Struct_ov000_02160da0*, int, void*);
void func_ov000_0217fa60(void*);
void func_ov000_02175258(void*);
void func_ov000_02174c14(void*);
void func_ov000_021814bc(void*);
void func_ov026_021dc8fc( Struct_ov000_02160da0*, Struct_ov000_02161e30*, Struct_ov000_0217e870_2*, void*, void*, void*, int);
void* memset(void*, int, unsigned int);
void func_ov000_0217fcc4(void*, int);
int func_0202c540(int*);
void func_ov017_021c6814(unsigned short, unsigned short, Struct_ov026_021d8ba0*, unsigned char, int, int);
int func_ov026_021ddd84(GameResources*, Struct_ov000_02160da0*, Struct_ov000_02161e30*, Struct_ov000_0217e870_2*, void*, void*, int);
void func_ov017_021c847c();
void func_020dd0b0(int, void*);
void func_0204500c(Struct_ov023_021f4c04*, void*, int, int);
int func_ov026_021d8a40();
void func_ov026_021dce34(int, Struct_ov000_02160da0*, Struct_ov000_02161e30*, Struct_ov000_0217e870_2*, void*, void*, void*, void*, void*, void*, void*, void*);
void func_ov026_021dd8a8(Struct_ov000_02161e30*, Struct_ov000_0217e870_2*);
void func_ov000_0217fbf4(void*, int);
void func_02046380(Struct_ov023_021f4c04*);
void func_020e4ce8(void*, char*, int);
void func_ov000_0216258c( Struct_ov000_02160da0*);
void func_ov026_021db3d8( Struct_ov000_02160da0*);
int func_0202c508(int*);
void func_ov000_02175be4(void*);
void func_ov026_021db5a4( Struct_ov000_02160da0*);
void func_ov026_021dbba8( Struct_ov000_02160da0*);
void func_ov000_0217457c(void*, int);
unsigned char func_ov026_021dd3dc(Struct_ov000_02161e30*, Struct_ov000_0217e870_2*, void*);
void* func_ov000_02160f14( Struct_ov000_02160da0*);
void func_ov017_021c894c(unsigned short);
void func_ov017_021c8758(unsigned short);
void func_ov017_021c8654();
void* func_02057924();
void func_02057f00(void*, int);
void func_ov000_02168144( Struct_ov000_02160da0*);
void func_ov000_0215d588(Struct_ov000_02161e30*);
void func_ov000_02160da0( Struct_ov000_02160da0*);
void func_ov026_021dc440(SafeAllocator*, Struct_ov000_02160da0*, Struct_ov000_02161e30*, Struct_ov000_0217e870_2*, int);
int func_ov026_021dc040(SafeAllocator*, Struct_ov000_02160da0*, Struct_ov000_02161e30*, Struct_ov000_0217e870_2*);
void func_ov000_02163894( Struct_ov000_02160da0*);
void func_ov000_02163928( Struct_ov000_02160da0*);
}

extern char data_ov026_021dedbc[];
extern char data_ov026_021dedd4[];
extern char g_sePlayer;
extern Vec3i data_ov026_021de6dc;
extern NameBuf data_ov026_021de6f8;
extern NameBuf data_ov026_021de778;
extern char data_ov026_021dedec[];

#define POWCNT (*(volatile unsigned short*)0x04000304)

static inline int inline_ov017_021c9d2c(int arg0) {
    return arg0 >= 0 && arg0 <= 3;
}

struct Struct_ov026_021d8ba0_6 {
    char unknown_0_[0x10];
    signed char unknown_10_[8];
    signed char unknown_18_;
};

struct Struct_ov026_021d8ba0_7 {
    char unknown_0_[0x14];
    char* unknown_14_;
};

struct Struct_ov026_021d8ba0_8 {
    char unknown_0_[0xc];
    int unknown_c_;
};

struct Struct_ov026_021d8ba0_9 {
    char unknown_0_[0xc];
    int unknown_c_;
};

struct Struct_ov023_021f4c04 {
    char unknown_0_[0x20];
    char* unknown_20_;
    char unknown_24_[0x38];
    char* unknown_5c_;
    char unknown_60_[0x938];
    int unknown_998_;
    char unknown_99c_[0x1013];
    unsigned char unknown_19af_;
    char unknown_19b0_[0x1a];
    unsigned char unknown_19ca_;
};

struct Struct_ov026_021d8ba0_5 {
    char unknown_0_[0xf78];
    unsigned char unknown_f78_[4];
    unsigned char unknown_f7c_;
};

struct Struct_ov000_0217e870_2 {
    char unknown_0_[0x8];
    unsigned short unknown_8_;
    char unknown_a_[0x2];
    int unknown_c_;
    char unknown_10_[0x1a];
    unsigned char unknown_2a_;
    char unknown_2b_[0x1];
    int unknown_2c_;
    int unknown_30_;
    unsigned char unknown_34_;
};

struct Struct_ov000_02161e30 {
    Random unknown_0_;
    char unknown_20_[0x8190];
    Struct_ov000_0215440c_6 unknown_81b0_[4];
    char unknown_8210_[0xc04];
    unsigned char unknown_8e14_;
    char unknown_8e15_[0x3];
    Struct_ov026_021d8ba0_9* unknown_8e18_;
    char unknown_8e1c_[0x4];
    int unknown_8e20_;
    char unknown_8e24_[0x23];
    unsigned char unknown_8e47_;
    char unknown_8e48_[0x1];
    unsigned char unknown_8e49_;
};

struct Struct_ov000_02160da0 {
    char unknown_0_[0x30];
    char unknown_30_[0x11c];
    char unknown_14c_[0x150];
    Struct_ov000_02161e30* unknown_29c_;
    Struct_ov000_0217e870_2* unknown_2a0_;
    char unknown_2a4_[0x974];
    char unknown_c18_[0x220];
    unsigned char unknown_e38_;
    unsigned char unknown_e39_;
    char unknown_e3a_[0x5e];
    char unknown_e98_[0x8];
    char unknown_ea0_[0x8];
    char unknown_ea8_[0x4];
    int unknown_eac_;
    char unknown_eb0_[0x4];
    unsigned char unknown_eb4_;
    unsigned char unknown_eb5_;
    char unknown_eb6_[0x12];
    char unknown_ec8_[0x2898];
    char unknown_3760_[0xb8];
    Struct_0201099c_3 unknown_3818_;
    char unknown_3820_[0xbc];
    int unknown_38dc_;
    char unknown_38e0_[0x7d0];
    int unknown_40b0_;
    unsigned char unknown_40b4_;
    char unknown_40b5_[0x11b7];
    char unknown_526c_[0x150];
    char unknown_53bc_[0xc0];
    int unknown_547c_[8];
    int unknown_549c_[8];
    unsigned char unknown_54bc_;
    char unknown_54bd_[0x3];
    signed char unknown_54c0_[8];
    signed char unknown_54c8_;
    char unknown_54c9_[0x9];
    unsigned short unknown_54d2_;
    char unknown_54d4_[0x4];
    unsigned char unknown_54d8_;
    char unknown_54d9_[0x7];
    unsigned char unknown_54e0_;
    unsigned char unknown_54e1_;
    char unknown_54e2_[0x2];
    Struct_ov026_021d8ba0 unknown_54e4_;
    char unknown_54ee_[0x2];
    int unknown_54f0_;
    int unknown_54f4_[4];
    char unknown_5504_[0xd4];
    int unknown_55d8_;
    char unknown_55dc_[0x18];
    int unknown_55f4_;
    char unknown_55f8_[0x130];
    char unknown_5728_[0x1a6];
    unsigned short unknown_58ce_;
    char unknown_58d0_[0x40];
    char unknown_5910_[0x40];
    unsigned char unknown_5950_;
    char unknown_5951_[0x3];
    char unknown_5954_[0xac];
    char unknown_5a00_[0x23c];
    char unknown_5c3c_[0x1200];
    unsigned int unknown_6e3c_;
    unsigned int unknown_6e40_;
    char unknown_6e44_[0x8cc];
    signed char unknown_7710_;
    unsigned char unknown_7711_;
    signed char unknown_7712_;
    char unknown_7713_[0x1];
    short unknown_7714_;
    short unknown_7716_[4];
    short unknown_771e_;
    short unknown_7720_;
    short unknown_7722_;
    short unknown_7724_;
    char unknown_7726_[0x9];
    unsigned char unknown_772f_;
    char unknown_7730_[0x4];
    int unknown_7734_;
    int unknown_7738_;
    char unknown_773c_[0xc];
    unsigned char unknown_7748_;
    unsigned char unknown_7749_;
    unsigned char unknown_774a_;
    char unknown_774b_[0x1];
    char unknown_774c_[0x14];
    char unknown_7760_[0x150];
    Struct_0201099c_3* inline_ov026_021d8ba0() { return &unknown_3818_; }
};

// USA: func_ov026_021d8ba0
extern "C" ARM void func_ov026_021d8ba0(Struct_ov000_02160da0* arg0) {
    char var0[0x80];
    Struct_020e6e88 var1;
    char var2[0x80];
    Struct_020e6e88 var3;
    char var4[12];
    Struct_ov026_021d8ba0 var5;
    Struct_ov026_021d8ba0 var6;
    Struct_ov026_021d8ba0 var7;
    Struct_ov026_021d8ba0 var8;
    Struct_ov026_021d8ba0 var9;
    short var10[8];
    Struct_ov026_021d8ba0 var11;
    Struct_ov026_021de6dc var12;
    unsigned char var13[12];
    unsigned char var14[12][2];
    unsigned char* var15[12];
    short var16[12];
    GameState* var17;
    GameResources* var18;
    Struct_ov000_02161e30* var19;
    Struct_ov026_021d8ba0_6* var20;
    Struct_ov023_021f4c04* var21;
    int* var22;
    BackgroundLoader* var23;
    void* var24;
    void* var25;
    unsigned char* var26;
    GameObject* var27;
    int var28;
    int var29;
    unsigned char var30;
    unsigned char var31;
    unsigned char var32;
    unsigned char var33;
    int var34;
    GameState* var35;
    GameObject* var36;
    unsigned char var37;
    int var38;
    int var39;
    Struct_ov023_021f4c04* var40;
    char* var41;
    char* var42;
    GameState* var43;
    Struct_ov000_02161e30* var44;
    Struct_ov000_0217e870_2* var45;
    int* var46;
    void** var47;
    Struct_ov026_021d8ba0_7* var48;
    unsigned char var49;

    var17 = GameState::GetInstance();
    var18 = GetGameResources();
    var22 = func_0202ae18();
    var19 = arg0->unknown_29c_;
    var20 = func_ov026_021dae60((Struct_ov026_021d8ba0_4*)arg0->unknown_3760_, func_020100a8(var17));
    var21 = func_020421a0();
    var23 = BackgroundLoader::GetInstance();
    var24 = func_0202ae24();
    var25 = func_020d6c00();
    var47 = (void**)var18->unknown_ptr_array_36fc[2];
    var26 = func_020e3580();

    if (var19 == 0 || var20 == 0) {
        return;
    }
    if (func_ov000_0215fc60((char*)var19) != 0 && var19->unknown_8e20_ == 2) {
        func_ov000_02160d80(arg0, 4);
        return;
    }
    {
        int var50 = var19->unknown_8e20_;
        func_ov026_021d8aac(arg0, var50, func_ov000_0215fc60((char*)var19));
    }
    if (var18->unknown_42e2_ != 0 && var23->GetNumQueuedTasks() == 0) {
        func_ov000_02160fa8(arg0, 0x2000000);
        return;
    }

    if (arg0->unknown_eac_ == 0) {
        func_ov000_02181608(arg0->unknown_3760_);
        func_ov000_0218173c(arg0->unknown_3760_);
        arg0->unknown_774a_ = 0;
        if (func_02012060(var17) != 0) {
            Struct_ov000_0217e870_2* var51 = arg0->unknown_2a0_;
            if (var51->unknown_c_ < 0 && var51->unknown_2c_ == 0) {
                arg0->unknown_eac_ = 6;
                goto state1;
            }
        }
        ((SafeAllocator*)(arg0->unknown_30_))->Reset();
        inline_ov026_021d8ba0_2().unknown_18_ = var23->QueueLoadFile(data_ov026_021dedbc, 0);
        arg0->unknown_eac_ = 1;
        if (func_0202b7d8(var22) && func_020a36a8((Struct_020a36a8*)arg0->unknown_2a0_)) {
            func_ov000_0215e8e8(arg0->unknown_29c_);
        }
    }
state1:
    if (arg0->unknown_eac_ == 1) {
        void* var52;
        unsigned int var53;
        if (!var23->GetTaskStatus(inline_ov026_021d8ba0_2().unknown_18_)) {
            return;
        }
        var23->GetLoadedFileByID(inline_ov026_021d8ba0_2().unknown_18_, &var52, &var53);
        func_0209a338((Struct_0200f3a4_8*)(arg0->unknown_e98_));
        func_0209a470((Struct_0209a470*)(arg0->unknown_e98_), (SafeAllocator*)(arg0->unknown_30_), (Struct_02013fb4*)var52, var53);
        var23->RemoveTask(inline_ov026_021d8ba0_2().unknown_18_);
        inline_ov026_021d8ba0_2().unknown_18_ = -1;
        inline_ov026_021d8ba0_2().unknown_18_ = var23->QueueLoadFile(data_ov026_021dedd4, 0);
        arg0->unknown_eac_ = 2;
    }
    if (arg0->unknown_eac_ == 2) {
        void* var54;
        unsigned int var55;
        if (!var23->GetTaskStatus(inline_ov026_021d8ba0_2().unknown_18_)) {
            return;
        }
        var23->GetLoadedFileByID(inline_ov026_021d8ba0_2().unknown_18_, &var54, &var55);
        func_0209a804((int*)(arg0->unknown_ea0_));
        func_0209a8b4((Struct_02086f24_6*)(arg0->unknown_ea0_), (SafeAllocator*)(arg0->unknown_30_), (Struct_02013fb4*)var54, var55);
        var23->RemoveTask(inline_ov026_021d8ba0_2().unknown_18_);
        inline_ov026_021d8ba0_2().unknown_18_ = -1;
        arg0->unknown_eac_ = 3;
    }
    if (self->state == 3) {
        int i;
        if (self->fadeActive != 0) {
            ForwardField0xc0_0205eb80(&g_sePlayer);
            self->fadeActive = 0;
        }
        arg0->unknown_7734_ = arg0->unknown_55f4_;
        arg0->unknown_7710_ = 0;
        arg0->unknown_7738_ = func_0204671c((Struct_0204671c*)func_020d6c00());
        arg0->unknown_eb4_ = 0;
        func_ov000_02160fa8(arg0, 0x80000);
        ClearFlags00(var18, 0x10);
        func_ov000_0218048c(arg0->unknown_3760_);
        func_ov000_02180b3c(arg0->unknown_3760_);
        arg0->unknown_54e0_ = 0;
        arg0->unknown_54e1_ = 0;
        arg0->unknown_7712_ = 0;
        arg0->unknown_7714_ = arg0->unknown_771e_ = arg0->unknown_7720_ = -1;
        arg0->unknown_7722_ = arg0->unknown_7724_ = -1;
        {
            int var57;
            for (var57 = 0; var57 < 4; var57++) {
                arg0->unknown_7716_[var57] = -1;
            }
        }
        var49 = 1;
        arg0->unknown_772f_ = 1;
        arg0->unknown_40b0_ = var19->unknown_8e20_;
        arg0->unknown_40b4_ = var19->unknown_8e49_;
        if (arg0->unknown_e38_ == 2) {
            var49 = 0;
        }
        ClearFlags00(var18, 0x800);
        if (func_ov000_0216f208(arg0->unknown_c18_)->unknown_c_ <= 0) {
            arg0->unknown_e39_ = 1;
            ClearFlags04(var18, 0x400);
            func_ov000_0216118c(arg0, 1);
        }
        func_ov000_02163710(arg0, 1);
        func_ov000_02167e6c((unsigned char*)arg0);
        {
            Struct_020d6ec8* var58 = func_ov000_02163524(arg0);
            func_020d6f44(var58);
            func_020d738c(var58);
        }
        if (var19->unknown_8e20_ > 0) {
            func_ov000_02162cbc(arg0);
        }
        func_ov000_021626a0(arg0, 0x26, 0);
        func_ov000_021626a0(arg0, 0x27, 1);
        func_ov000_02163a7c((Struct_ov000_02163a7c*)arg0);
        func_ov000_021629ec(arg0);
        {
            int var59;
            int var60, var61;
            int var62;
            unsigned char* var63;
            unsigned char* var64;
            short* var65;
            unsigned char** var66;

            var35 = GameState::GetInstance();
            var34 = 0;
            var34 = var34 + func_ov000_0215e9fc(var19, var16, 12, var34);
            var34 = var34 + func_ov000_0215ec1c(var19, &var16[var34], 12 - var34, 0);
            var33 = 0;
            var32 = 0;
            var31 = var33;
            var30 = var33;
            var29 = var33;
            var66 = var15;
            var64 = var14[0];
            var65 = var16;
            for (; var29 < var34; var64 += 2, var66++, var65++, var29++) {
                *var66 = (unsigned char*)var35->GetCombatantByIndex(*var65);
                if (*var66 != 0) {
                    int var67 = func_020493a4(*var66);
                    var64[0] = var67 % 9;
                    var64[1] = var67 / 9;
                    if (var64[0] < 3) var30 = 1;
                    if (var64[0] > 5) var31 = 1;
                    if (var64[1] < 3) var33 = 1;
                    if (var64[1] > 5) var32 = 1;
                }
            }
            var61 = 0;
            var60 = var61;
            if (var31 != 0 && var30 == 0) var61 = -1;
            if (var31 == 0 && var30 != 0) var61 = 1;
            if (var33 == 0 && var32 != 0) var60 = -2;
            if (var33 != 0 && var32 == 0) var60 = 2;
            if (var61 != 0 || var60 != 0) {
                var63 = var13;
                var64 = var14[0];
                for (var59 = 0; var59 < var34; var64 += 2, var63++, var59++) {
                    *var63 = (var64[0] + var61) + (var64[1] + var60) * 9;
                    if (*var63 >= 81) goto shifted;
                }
                var63 = var13;
                var66 = var15;
                for (var62 = 0; var62 < var34; var66++, var63++, var62++) {
                    if (*var66 != 0) {
                        int var68;
                        func_02049390(*var66, *var63);
                        var68 = *var63;
                        const Struct_ov026_021d8ba0_2& var69 = func_ov000_0216f74c(&var68);
                        Struct_ov026_021d8ba0_2 var70 = var69;
                        var12 = data_ov026_021de6dc;
                        var12.unknown_0_[0] = var70.unknown_0_;
                        var12.unknown_0_[2] = var70.unknown_4_;
                        func_02049bd4(*var66, var12.unknown_0_);
                    }
                }
            }
        }
    shifted:
        func_02043204((char*)var21);
        func_02043124(var21);
        func_ov026_021daec8(arg0->unknown_29c_, arg0->unknown_c18_, var49);
        {
            Struct_ov000_02161e30* var71 = arg0->unknown_29c_;
            Struct_ov000_0215440c_6* var72;
            int var73;
            int var74;
            var43 = GameState::GetInstance();
            var42 = arg0->unknown_526c_;
            var41 = arg0->unknown_53bc_;
            var72 = var71->unknown_81b0_;
            var40 = func_020421a0();
            var74 = 0;
            func_ov000_02174614(arg0->unknown_3760_, -1);
            func_ov000_02174dc0(arg0->unknown_3760_);
            var39 = 0;
            for (var38 = 0; var38 < var72->unknown_1_4_; var38++) {
                var37 = 0;
                for (var73 = 0; var73 < var72[var38].unknown_e_0_; var73++) {
                    var36 = func_0200fea4(var43, var72[var38].unknown_6_[var73] + 0xc0);
                    if (var36 == 0 || func_02010088((Struct_02010088*)var36) || func_ov026_021dd3c4((Struct_ov026_021d8ba0_10*)var36)) {
                        continue;
                    }
                    var48 = *(Struct_ov026_021d8ba0_7**)((char*)var36 + 0x144);
                    if (var48 == 0) {
                        continue;
                    }
                    {
                        var3 = data_ov026_021de6f8;
                        func_020e4864((char*)var36 + 0x14c, var3.unknown_0_ + 5, 1, 0, 0, 0);
                        __clear(var2, sizeof(var2));
                        func_02046608(var40, 0xa, var3.unknown_0_, var2, 0x100, 0, 0);
                        func_0203c108((Struct_0203c108_3*)(var41 + var74 * 0x18), var2);
                    }
                    arg0->unknown_547c_[var74] = *((unsigned char*)var36 + 0x17c);
                    arg0->unknown_549c_[var74] = var72[var38].unknown_6_[var73] + 0xc0;
                    if (var37 == 0) {
                        var37 = 1;
                        var1 = data_ov026_021de778;
                        func_020e4864(var48->unknown_14_, var1.unknown_0_ + 5, 1, 0, 0, 0);
                        __clear(var0, sizeof(var0));
                        func_02046608(var40, 0xa, var1.unknown_0_, var0, 0x100, 0, 0);
                        func_0203c108((Struct_0203c108_3*)(var42 + var39 * 0x18), var0);
                        var39++;
                    }
                    var74++;
                }
            }
            func_ov000_021744f4((int)arg0->unknown_3760_, (void*)var74);
            var72 = var19->unknown_81b0_;
            arg0->unknown_54bc_ = var72->unknown_1_0_;
        }
        arg0->unknown_5950_ = 0;
        ((Object3D*)(arg0->unknown_5954_))->MakeHidden();
        ((Object3D*)(arg0->unknown_5a00_))->MakeHidden();
        func_ov000_02160fbc(arg0, 0x20000);
        for (var56 = 0; var56 < 4; var56++) {
            Struct_ov026_021d8ba0_6* var75 = func_ov026_021dae60((Struct_ov026_021d8ba0_4*)arg0->unknown_3760_, var56);
            if (var75 != 0) {
                func_ov000_0217f518(var75);
            }
        }
        func_ov000_02162c14(arg0, func_020100a8(var17), &arg0->unknown_54e4_);
        func_ov000_0217fa60(arg0->unknown_3760_);
        func_ov000_02176054(arg0->unknown_3760_);
        func_ov000_02175258(arg0->unknown_3760_);
        func_ov000_02174c14(arg0->unknown_3760_);
        func_ov000_021814bc(arg0->unknown_3760_);
        arg0->unknown_54d2_ &= ~0x600;
        if (func_ov000_0215fc60((char*)var19) != 0) {
            arg0->unknown_54d8_ = 1;
        }
        {
            Struct_ov000_0217e870_2* var76;
            int var77;
            var44 = arg0->unknown_29c_;
            var76 = arg0->unknown_2a0_;
            for (var77 = 0; var77 < 4; var77++) {
                if (func_020a35e0((unsigned char*)var76, var77)) {
                    func_ov026_021dc8fc(arg0, var44, var76, arg0->unknown_3760_, arg0->unknown_e98_, arg0->unknown_ea0_, var77);
                }
            }
        }
        for (var56 = 0; var56 < 4; var56++) {
            void* var78;
            if (!func_020a35e0((unsigned char*)arg0->unknown_2a0_, var56)) continue;
            var27 = func_0200ff1c(var17, var56);
            if (var27 == 0) continue;
            var78 = func_02053dc0((Struct_02053dc0*)var27);
            if (var78 != 0) {
                memset(var78, 0, 6);
            }
            arg0->unknown_54f0_ = arg0->unknown_38dc_;
            if (func_02010088((Struct_02010088*)var27)) continue;
            func_02033b88((Struct_02010604*)var27, 0);
        }
        if (var19->unknown_8e20_ == 0 && arg0->unknown_29c_->unknown_8e49_ == 2) {
            func_ov000_02181364(arg0->unknown_3760_);
            func_ov000_0217fcc4(arg0->unknown_3760_, -1);
            arg0->unknown_772f_ = 0;
        }
        if (func_ov000_0215fc60((char*)var19) != 0) {
            if (func_0202c540(var22) != 0) {
                func_ov000_02181364(arg0->unknown_3760_);
                func_ov000_0217fcc4(arg0->unknown_3760_, -1);
                func_ov000_021816e8(arg0->unknown_3760_, -1);
                func_ov000_02181694(arg0->unknown_3760_, 0);
                arg0->unknown_772f_ = 0;
            } else {
                for (var56 = 1; var56 < 4; var56++) {
                    Struct_ov026_021d8ba0_6* var79 = func_ov026_021dae60((Struct_ov026_021d8ba0_4*)arg0->unknown_3760_, var56);
                    if (var79 != 0) {
                        func_ov000_0217f5d0(var79);
                        var79->unknown_10_[var79->unknown_18_] = 100;
                    }
                }
            }
        }
        if (func_020a36a8((Struct_020a36a8*)arg0->unknown_2a0_)) {
            func_ov000_02160fa8(arg0, 0x40000000);
        }
        if (((SafeAllocator*)arg0->unknown_774c_)->GetSignedAllocator() == 0) {
            ((SafeAllocator*)arg0->unknown_774c_)->CreateTypeA(((SafeAllocator*)(arg0->unknown_30_))->Allocate(0x16000), 0x16000);
            func_0207dfc8((Struct_02015ef4_5*)(arg0->unknown_14c_), (Struct_02015ef4_5*)(arg0->unknown_7760_));
        }
        arg0->unknown_eac_ = 0xe;
        {
            Struct_ov026_021d8ba0_5* var80 = (Struct_ov026_021d8ba0_5*)func_02010828(var17);
            unsigned char var81;
            for (var81 = 0; var81 < var80->unknown_f7c_; var81++) {
                if (arg0->unknown_774a_ != 0) {
                    Struct_ov026_021d8ba0_6* var82 = func_ov026_021dae60((Struct_ov026_021d8ba0_4*)arg0->unknown_3760_, var81);
                    if (var82 != 0) {
                        func_ov000_0217f518(var82);
                    }
                }
                func_ov000_02162c14(arg0, var80->unknown_f78_[var81], &var5);
                func_ov017_021c6814(arg0->unknown_2a0_->unknown_8_, var80->unknown_f78_[var81], &var5, 0, -1, 0);
            }
        }
    }
    if (arg0->unknown_eac_ == 0xe) {
        if (func_ov026_021ddd84(var18, arg0, arg0->unknown_29c_, arg0->unknown_2a0_, arg0->unknown_3760_, &arg0->unknown_7748_, 1) != 0) {
            return;
        }
        if (func_ov000_02160fd4(arg0, 0x40000000) != 0) {
            if (arg0->unknown_774a_ != 0) {
                int var83;
                for (var83 = 0; var83 < 4; var83++) {
                    Struct_ov026_021d8ba0_6* var84 = func_ov026_021dae60((Struct_ov026_021d8ba0_4*)arg0->unknown_3760_, var83);
                    if (var84 != 0) {
                        func_ov000_0217f518(var84);
                    }
                }
                arg0->unknown_774a_ = 0;
            }
            func_ov017_021ca174(arg0->unknown_2a0_->unknown_8_);
            arg0->unknown_eac_ = 0x11;
            func_ov017_021c847c();
        }
    }
    if (arg0->unknown_eac_ == 0x11) {
        int var85;
        Struct_020e385c* var86;
        var85 = var19->unknown_8e18_->unknown_c_ >= 0 ? 1 : 0;
        var21->unknown_19af_ = 0;
        var21->unknown_19ca_ = 0;
        var86 = func_020e3808();
        if (!var85 || (func_020e3ad0(var86, 1, -1) && var85)) {
            unsigned char* var87 = func_020e385c(var86, 1, -1);
            int var88 = 0;
            int var89;
            if (var87 != 0 && (var87[5] & (1 << func_020100a8(var17)))) {
                var88 = 1;
            }
            var89 = 0;
            if (var87 != 0 && (var87[5] & arg0->unknown_2a0_->unknown_34_) == var87[5]) {
                var89 = 1;
            }
            if (var89 || !var88 || !var87) {
                func_02043204((char*)var21);
                arg0->unknown_eac_ = 4;
                func_020e3994(var86, 1, -1);
                return;
            }
        }
        if (((POWCNT & 0x8000) >> 15) == 1 && (IsBrightnessOutsideValidRange((GameResources*)var18, false) || IsBrightnessOutsideValidRange((GameResources*)var18, true)) && arg0->unknown_7712_ == 0) {
            SetBrightness(var18, 0, 0xf);
            if (var21->unknown_998_ == 0) {
                void* var90 = func_020421a0()->unknown_5c_;
                memset(var90, 0, 0x960);
                func_020dd0b0(0, var90);
                func_0204500c(var21, var90, 0, 0xe3);
                var21->unknown_998_ = 1;
            }
        }
        if (func_ov026_021ddd84(var18, arg0, arg0->unknown_29c_, arg0->unknown_2a0_, arg0->unknown_3760_, &arg0->unknown_7748_, 1) != 0) {
            return;
        }
        if (func_ov026_021d8a40() && func_02046b08(var47) && func_020a35e0((unsigned char*)arg0->unknown_2a0_, arg0->unknown_2a0_->unknown_2a_)) {
            func_ov026_021dce34(-1, arg0, arg0->unknown_29c_, arg0->unknown_2a0_, arg0->unknown_3760_, arg0->unknown_ec8_, arg0->unknown_5c3c_, arg0->unknown_5728_, arg0->unknown_e98_, arg0->unknown_ea0_, arg0->unknown_5910_, arg0->unknown_c18_);
        }
    }
    if (arg0->unknown_eac_ == 4) {
        int var91;
        int var92;
        if (((POWCNT & 0x8000) >> 15) == 1 && (IsBrightnessOutsideValidRange((GameResources*)var18, false) || IsBrightnessOutsideValidRange((GameResources*)var18, true)) && arg0->unknown_7712_ == 0) {
            SetBrightness(var18, 0, 0xf);
            func_ov026_021dd8a8(var19, arg0->unknown_2a0_);
            arg0->unknown_eb5_ = 0;
        } else if (arg0->unknown_eb5_ != 0) {
            func_ov026_021dd8a8(var19, arg0->unknown_2a0_);
            arg0->unknown_eb5_ = 0;
        }
        if (arg0->unknown_772f_ & (var21->unknown_998_ == 0)) {
            func_ov000_0217fbf4(arg0->unknown_3760_, -1);
            arg0->unknown_772f_ = 0;
        }
        func_ov000_02174514(arg0->unknown_3760_);
        if (func_ov026_021ddd84(var18, arg0, arg0->unknown_29c_, arg0->unknown_2a0_, arg0->unknown_3760_, &arg0->unknown_7748_, 1) != 0) {
            return;
        }
        {
            GameState* var93;
            int var94;
            int var95;
            short var96[8];
            var28 = -1;
            memset(var96, var28, sizeof(var96));
            var95 = func_ov000_0215eb1c(var19, var96, 8, 0);
            var93 = GameState::GetInstance();
            for (var94 = 0; var94 < var95; var94++) {
                GameObject* var97 = func_0200fea4(var93, var96[var94]);
                if (var97 != 0) {
                    ModifiableCombatStats* var98 = var97->currentStats_;
                    if ((*(int*)&var98->unk1[4] & 0x1000) && func_0200ff1c(var93, *(short*)&var98->unk1[0x1a]) == 0) {
                        var28 = var96[var94];
                        func_02088e64((unsigned char*)var97->currentStats_);
                        var91 = 1;
                        goto checked;
                    }
                }
            }
            var91 = 0;
        }
    checked:
        if (var91) {
            Struct_ov023_021f4c04* var99 = func_020421a0();
            Struct_0201099c_3* var100 = arg0->inline_ov026_021d8ba0();
            GameObject* var101 = func_0200fea4(var17, var28);
            void* var102 = func_020e0434(var100, 0x28);
            if (var102 != 0 && var101 != 0) {
                func_02046380(var99);
                func_02046574((Struct_02046574_2*)var99, 0, (char*)var101 + 0x14c);
                func_020e4ce8(var4, (char*)var101, 1);
                var99->unknown_20_ = var4;
                func_0204500c(var99, var102, 0, 0xe3);
                var99->unknown_998_ = 1;
                arg0->unknown_eac_ = 0xf;
                return;
            }
        }
        if (func_ov026_021d8a40() && func_02046b08(var47) && func_020a35e0((unsigned char*)arg0->unknown_2a0_, arg0->unknown_2a0_->unknown_2a_)) {
            func_ov026_021dce34(-1, arg0, arg0->unknown_29c_, arg0->unknown_2a0_, arg0->unknown_3760_, arg0->unknown_ec8_, arg0->unknown_5c3c_, arg0->unknown_5728_, arg0->unknown_e98_, arg0->unknown_ea0_, arg0->unknown_5910_, arg0->unknown_c18_);
        }
        if (var19->unknown_8e47_ == 0) {
            if (func_02046708((Struct_02012de8*)var25, 0x200) == 0) {
                int var103 = var19->unknown_8e20_;
                int var104 = var19->unknown_8e49_;
                int var105 = 1;
                if (var103 == 0 && var104 == 2) {
                    var105 = 0;
                }
                if (var105) {
                    func_020466e4((unsigned int*)var25, 0x200);
                }
            }
            if (func_020a36a8((Struct_020a36a8*)arg0->unknown_2a0_) && func_020e37e8(var26)) {
                func_020e3798(var26);
            }
        }
        func_ov000_0216258c(arg0);
        {
            int var106 = (signed char)func_020100a8(var17);
            int var107 = 0;
            int var108 = var107;
            int var109 = var107;
            if (func_0202b7d8(var22) && var19->unknown_8e20_ == 0 && arg0->unknown_29c_->unknown_8e49_ == 2) {
                if (var21->unknown_998_ != 0) {
                    var109 = 1;
                }
            }
            if (var109 == 0) {
                if (arg0->unknown_54f4_[var106] != (func_ov000_0217fb98(arg0->unknown_3760_) == 0)) {
                    var108 = 1;
                }
                func_ov000_02162c90((char*)arg0, var106, func_ov000_0217fb98(arg0->unknown_3760_) == 0);
            }
            func_ov026_021db3d8(arg0);
            if (func_020a36a8((Struct_020a36a8*)arg0->unknown_2a0_)) {
                var45 = arg0->unknown_2a0_;
                var107 = 1;
                var46 = func_0202ae18();
                if (func_0202b7d8(var46)) {
                    for (var92 = 0; var92 < 4; var92++) {
                        if (func_020a35e0((unsigned char*)var45, var92) && func_0202c1c0((Struct_0202b2f0*)var46, var92)) {
                            var107 = (var107 & arg0->unknown_54f4_[var92]) ? 1 : 0;
                        }
                    }
                } else if (arg0->unknown_54f4_[0] == 0) {
                    var107 = 0;
                }
            } else if (arg0->unknown_5950_ != 0) {
                var107 = 1;
            }
            if (var107) {
                func_ov000_0217fcc4(arg0->unknown_3760_, -1);
            }
            if (func_ov000_02168720((char*)arg0) > 0 || var21->unknown_998_ != 0) {
                var107 = 0;
            }
            if (var107 && func_0202b7d8(var22) && func_020a36a8((Struct_020a36a8*)arg0->unknown_2a0_)) {
                if (func_ov026_021d8a40() == 0) {
                    var107 = 0;
                }
            }
            if (func_0202b7d8(var22)) {
                int var110 = arg0->unknown_54f0_;
                int var111 = 0;
                int var112;
                if (var110 >= 0) {
                    var111 = var110 <= 3;
                }
                if (var111) {
                    int var113;
                    func_ov000_02162c14(arg0, var110, &var6);
                    var113 = !(var6.unknown_0_[0] == arg0->unknown_54e4_.unknown_0_[0] && var6.unknown_0_[1] == arg0->unknown_54e4_.unknown_0_[1] && var6.unknown_0_[2] == arg0->unknown_54e4_.unknown_0_[2] &&
                                var6.unknown_0_[3] == arg0->unknown_54e4_.unknown_0_[3] && var6.unknown_6_ == arg0->unknown_54e4_.unknown_6_ && var6.unknown_8_ == arg0->unknown_54e4_.unknown_8_ && var6.unknown_4_ == arg0->unknown_54e4_.unknown_4_);
                    if (var113 || var108) {
                        func_ov017_021c6814(arg0->unknown_2a0_->unknown_8_, arg0->unknown_54f0_, &var6, arg0->unknown_54f4_[var106], -1, 0);
                        arg0->unknown_54e4_.unknown_0_[0] = var6.unknown_0_[0];
                        arg0->unknown_54e4_.unknown_0_[1] = var6.unknown_0_[1];
                        arg0->unknown_54e4_.unknown_0_[2] = var6.unknown_0_[2];
                        arg0->unknown_54e4_.unknown_0_[3] = var6.unknown_0_[3];
                        arg0->unknown_54e4_.unknown_4_ = var6.unknown_4_;
                        arg0->unknown_54e4_.unknown_6_ = var6.unknown_6_;
                        arg0->unknown_54e4_.unknown_8_ = var6.unknown_8_;
                        if (func_0202c508(var22) != 0 && ((var6.unknown_0_[0] == 100 && var6.unknown_0_[1] == 6) || var6.unknown_0_[0] == 0xd)) {
                            Struct_ov026_021d8ba0_5* var114 = (Struct_ov026_021d8ba0_5*)func_02010828(var17);
                            int var115;
                            for (var115 = 0; var115 < var114->unknown_f7c_; var115++) {
                                if (arg0->unknown_54f0_ == var115) continue;
                                func_ov000_02162c14(arg0, var114->unknown_f78_[var115], &var7);
                                func_ov017_021c6814(arg0->unknown_2a0_->unknown_8_, var114->unknown_f78_[var115], &var7, arg0->unknown_54f4_[var106], -1, 0);
                            }
                        }
                    }
                }
                var112 = arg0->unknown_38dc_;
                if (arg0->unknown_54f0_ != var112) {
                    arg0->unknown_54f0_ = var112;
                    if (inline_ov017_021c9d2c(var112)) {
                        func_ov000_02162c14(arg0, var112, &var8);
                        func_ov017_021c6814(arg0->unknown_2a0_->unknown_8_, var112, &var8, arg0->unknown_54f4_[var106], -1, 0);
                    }
                }
            }
            if (var107 && (arg0->unknown_54d2_ & 0x200)) {
                if (arg0->unknown_54c0_[arg0->unknown_54c8_] == 100) {
                    func_ov000_02175be4(arg0->unknown_3760_);
                    arg0->unknown_54d2_ &= ~0x200;
                    arg0->unknown_54d2_ |= 0x400;
                    arg0->unknown_eb4_ = 0;
                }
                arg0->unknown_774a_ = 1;
                var107 = 0;
            }
            func_ov026_021db5a4(arg0);
            if ((arg0->unknown_54d2_ & 0x200) || arg0->unknown_7712_ > 0) {
                var107 = 0;
            }
            if (arg0->unknown_7749_ != 0 && arg0->unknown_7712_ == 0) {
                func_ov026_021dbba8(arg0);
                func_ov000_0216118c(arg0, 0);
            }
            self->ready = redo ? 1 : 0;
            if (redo) {
                ClearSlotBitndSetByte_021813d4(self->list);
                func_ov000_0217fcc4(self->list, -1);
                func_ov000_0217457c(self->list, -1);
                if (self->phase == -1) {
                    self->fadeTimer = 60;
                    ForwardField0xc0_0205eb80(&g_sePlayer);
                    self->fadeActive = 0;
                    SetForwardAndStore0205eb54(&g_sePlayer, 0x1b3, 0x1b3);
                    DispatchIfField0xc4NonNeg_0205eb90(&g_sePlayer, 0, 0);
                    self->fadeActive = 1;
                }
                {
                    Object3D* var116;
                    int var117;
                    for (var117 = 0; var117 < 4; var117++) {
                        var116 = (Object3D*)var17->GetGameObjectByIndex(arg0->unknown_7716_[var117]);
                        if (var116 != 0) {
                            var116->StopCurrentAnimation();
                            var116->MaybeSetRegularAnimation(data_ov026_021dedec, 1);
                        }
                    }
                }
                func_ov000_02160fbc(arg0, 0x40000000);
                if (!func_0202b7d8(var22)) {
                    Random* var118;
                    arg0->unknown_5950_ = func_ov026_021dd3dc(arg0->unknown_29c_, arg0->unknown_2a0_, arg0->unknown_3760_);
                    var118 = &arg0->unknown_29c_->unknown_0_;
                    arg0->unknown_6e3c_ = GetRandomStateHi(var118);
                    arg0->unknown_6e40_ = GetRandomStateLo(var118);
                    arg0->unknown_eac_ = 5;
                } else {
                    int var119;
                    int var120;
                    if (arg0->unknown_7749_ == 0) {
                        func_ov000_02167e6c((unsigned char*)arg0);
                    }
                    func_ov026_021daec8(var19, func_ov000_02160f14(arg0), 0);
                    if (func_020a36a8((Struct_020a36a8*)arg0->unknown_2a0_)) {
                        arg0->unknown_5950_ = func_ov026_021dd3dc(arg0->unknown_29c_, arg0->unknown_2a0_, arg0->unknown_3760_);
                        func_ov017_021cefe0(arg0->unknown_2a0_->unknown_8_, arg0->unknown_5950_, arg0->unknown_7748_);
                        func_ov000_02160fa8(arg0, 0x800000);
                    }
                    if (func_02046708((Struct_02012de8*)var25, 0x200)) {
                        func_020e36f0(var26);
                    }
                    arg0->unknown_eac_ = 0x12;
                    func_ov017_021c894c(arg0->unknown_2a0_->unknown_8_);
                    func_ov017_021c8758(arg0->unknown_2a0_->unknown_8_);
                    func_ov017_021c8654();
                    func_ov017_021c847c();
                    var119 = 1;
                    for (var120 = 0; var120 < 4; var120++) {
                        GameObject* var121;
                        if (func_020a35e0((unsigned char*)arg0->unknown_2a0_, var120) && (var121 = var17->GetCombatantByIndex(var120)) != 0) {
                            if (func_02010088((Struct_02010088*)var121) == 0) {
                                var119 = 0;
                            }
                        }
                    }
                    if (var119) {
                        var19->unknown_8e14_ = 2;
                        func_ov000_02160d80(arg0, 0xa);
                    }
                }
            }
        }
    } else if (arg0->unknown_eac_ == 0x12) {
        if (func_ov026_021ddd84(var18, arg0, arg0->unknown_29c_, arg0->unknown_2a0_, arg0->unknown_3760_, &arg0->unknown_7748_, 0) != 0) {
            return;
        }
        if (func_020e37e8(var26) != 0 || func_02046708((Struct_02012de8*)var25, 0x200) == 0) {
            func_020466f4((Struct_02038598_4*)var25, 0x200);
            if (func_020a36a8((Struct_020a36a8*)arg0->unknown_2a0_)) {
                arg0->unknown_eac_ = 8;
            } else {
                arg0->unknown_eac_ = 0xa;
            }
        }
    } else if (arg0->unknown_eac_ == 8) {
        if (func_ov026_021ddd84(var18, arg0, arg0->unknown_29c_, arg0->unknown_2a0_, arg0->unknown_3760_, &arg0->unknown_7748_, 0) != 0) {
            return;
        }
        if (func_0205e488(var24)) {
            int var122;
            for (var122 = 0; var122 < 4; var122++) {
                if (func_020a35e0((unsigned char*)arg0->unknown_2a0_, var122)) {
                    func_0200ff58(var17, var122);
                    func_ov000_02162c14(arg0, var122, &var9);
                    func_ov017_021c6814(arg0->unknown_2a0_->unknown_8_, var122, &var9, 1, -1, 1);
                }
            }
            arg0->unknown_eac_ = 9;
        }
    } else if (arg0->unknown_eac_ == 9) {
        if (func_ov026_021ddd84(var18, arg0, arg0->unknown_29c_, arg0->unknown_2a0_, arg0->unknown_3760_, &arg0->unknown_7748_, 0) != 0) {
            return;
        }
        if (func_0205e488(var24)) {
            Random* var123 = &arg0->unknown_29c_->unknown_0_;
            arg0->unknown_6e3c_ = GetRandomStateHi(var123);
            arg0->unknown_6e40_ = GetRandomStateLo(var123);
            func_ov017_021cf650(arg0->unknown_2a0_->unknown_8_, arg0->unknown_6e3c_, arg0->unknown_6e40_);
            arg0->unknown_eac_ = 0xb;
        }
    } else if (arg0->unknown_eac_ >= 0xb && arg0->unknown_eac_ <= 0xd) {
        if (arg0->unknown_eac_ == 0xd) {
            arg0->unknown_eac_ = 5;
        } else {
            arg0->unknown_eac_ = arg0->unknown_eac_ + 1;
        }
    } else if (arg0->unknown_eac_ == 0xa) {
        if (func_ov026_021ddd84(var18, arg0, arg0->unknown_29c_, arg0->unknown_2a0_, arg0->unknown_3760_, &arg0->unknown_7748_, 0) != 0) {
            return;
        }
        if (func_ov000_02160fd4(arg0, 0x20000)) {
            arg0->unknown_eac_ = 5;
        }
    } else if (arg0->unknown_eac_ == 5) {
        int var124;
        if (func_0202b7d8(var22) && var22[0xfc0 / 4] != 0) {
            return;
        }
        if (arg0->unknown_7711_ != 0 && arg0->unknown_7710_ != 0) {
            return;
        }
        if (arg0->unknown_7748_ != 0) {
            int var125 = func_ov000_0215ec1c(var19, var10, 8, 0);
            int var126;
            for (var126 = 0; var126 < var125; var126++) {
                GameObject* var127 = func_0200fea4(var17, var10[var126]);
                if (var127 != 0) {
                    ModifiableCombatStats* var128 = var127->currentStats_;
                    var128->primaryStats.currHP = var128->primaryStats.maxHP;
                }
            }
            arg0->unknown_7748_ = 0;
        }
        if (arg0->unknown_7712_ == -1) {
            for (var124 = 0; var124 < 4; var124++) {
                if (var17->GetGameObjectByIndex(arg0->unknown_7716_[var124]) != 0) {
                    return;
                }
            }
            func_ov026_021dbba8(arg0);
        }
        ((SafeAllocator*)arg0->unknown_774c_)->Destroy();
        arg0->unknown_7749_ = 0;
        func_02057f00(func_02057924(), 0x13);
        if (func_02046b08((void**)var18->unknown_ptr_array_36fc[1]) == 0) {
            return;
        }
        SetFlags00(var18, 0x10);
        memset(arg0->unknown_54f4_, 0, 0x10);
        arg0->unknown_2a0_->unknown_30_ = 0;
        func_ov000_02160fbc(arg0, 0x4000000);
        func_ov000_02160fbc(arg0, 0x8000000);
        func_ov000_02160fbc(arg0, 0x10000000);
        func_ov000_02160fbc(arg0, 0x20000000);
        {
            Object3D* var129;
            int var130;
            for (var130 = 0; var130 < 4; var130++) {
                if (func_020a35e0((unsigned char*)arg0->unknown_2a0_, var130)) {
                    func_ov000_02162c14(arg0, var130, &var11);
                    var129 = (Object3D*)var17->GetGameObjectByIndex(var130);
                    if (var129 != 0) {
                        var129->DisableFlag(0x1000);
                    }
                }
            }
        }
        {
            Struct_ov000_0217e870_2* var131 = arg0->unknown_2a0_;
            int var132;
            Struct_ov026_021d8ba0_5* var133;
            var17 = GameState::GetInstance();
            for (var124 = 0; var124 < 4; var124++) {
                GameObject* var134;
                if (func_020a35e0((unsigned char*)var131, var124) && (var134 = func_0200ff1c(var17, var124)) != 0) {
                    func_02053dd0((Struct_02053dd0*)var134);
                }
            }
            var133 = (Struct_ov026_021d8ba0_5*)func_02010828(var17);
            if (var133 != 0) {
                for (var132 = 0; var132 < var133->unknown_f7c_; var132++) {
                    GameObject* var135 = func_0200ff1c(var17, var133->unknown_f78_[var132]);
                    if (var135 != 0 && func_02010088((Struct_02010088*)var135) == 0) {
                        arg0->unknown_58ce_++;
                        break;
                    }
                }
            }
        }
        func_ov000_02168144(arg0);
        func_0209a338((Struct_0200f3a4_8*)(arg0->unknown_e98_));
        ((SafeAllocator*)(arg0->unknown_30_))->Reset();
        arg0->unknown_55d8_ = 0;
        func_ov000_0215d588(var19);
        if (func_0202b7d8(var22) && func_020e37e8(var26)) {
            func_020e3798(var26);
        }
        if (arg0->unknown_5950_ == 1) {
            func_ov000_02160da0(arg0);
        } else {
            func_ov000_02160d80(arg0, 0xb);
        }
    } else if (arg0->unknown_eac_ == 6) {
        if (var23->GetNumQueuedTasks() > 0) {
            return;
        }
        func_ov000_021637c8(arg0);
        func_ov026_021dc440((SafeAllocator*)(arg0->unknown_30_), arg0, arg0->unknown_29c_, arg0->unknown_2a0_, 0);
        func_ov026_021dc040((SafeAllocator*)(arg0->unknown_30_), arg0, arg0->unknown_29c_, arg0->unknown_2a0_);
        func_ov000_02163894(arg0);
        arg0->unknown_eac_ = 7;
    } else if (arg0->unknown_eac_ == 7) {
        func_ov000_02163928(arg0);
        if (func_ov026_021dc040((SafeAllocator*)(arg0->unknown_30_), arg0, arg0->unknown_29c_, arg0->unknown_2a0_) != 0) {
            arg0->unknown_eac_ = 0;
        }
    }
    if (arg0->unknown_eac_ == 0xf && func_020421a0()->unknown_998_ == 0) {
        arg0->unknown_eac_ = 4;
    }
}
