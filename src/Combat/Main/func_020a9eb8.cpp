#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/GrottoStruct.h"
#include "Resource/GameResources.h"
#include "NitroSDK/Memory.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "std_library_functions.h"

#if defined(jpn)
#define func_0205ec34 func_0205ff20
#endif

struct Struct_020a99d0_3 {
    unsigned short unknown_0_[70];
    unsigned char unknown_8c_[0x15f];
    unsigned char unknown_1eb_[0xd5];
    unsigned short unknown_2c0_[6];
    unsigned char unknown_2cc_[102];
    unsigned char unknown_332_;
};

struct Struct_020a95a4_7 {
    signed char unknown_0_0_ : 6;
    unsigned char unknown_1_[0x23c - 1];
};

struct Struct_020a95a4_8 {
    unsigned char unknown_0_[0x1d4];
    unsigned char unknown_1d4_[0xe04 - 0x1d4];
    unsigned char unknown_e04_[0x128];
    unsigned char unknown_f2c_[0xf68 - 0xf2c];
    int unknown_f68_;
    int unknown_f6c_;
    int unknown_f70_;
    int unknown_f74_;
    unsigned char unknown_f78_[5];
    unsigned char unknown_f7d_;
    unsigned char unknown_f7e_[2];
    Struct_020a95a4_7 unknown_f80_[13];
    unsigned char unknown_2c8c_;
    unsigned char unknown_2c8d_[7];
    unsigned int unknown_2c94_;
};

struct Struct_020a95a4 {
    unsigned char unknown_0_[0xd98];
    unsigned char unknown_d98_[0xd98];
    unsigned char unknown_1b30_[4];
    int unknown_1b34_;
    int unknown_1b38_;
    int unknown_1b3c_;
    unsigned char unknown_1b40_[4];
    int unknown_1b44_;
    int unknown_1b48_;
    int unknown_1b4c_;
    int unknown_1b50_;
    int unknown_1b54_;
    unsigned char unknown_1b58_[9];
    unsigned char unknown_1b61_;
};

struct Struct_020a95a4_2 {
    unsigned short unknown_0_;
#if defined(jpn)
    unsigned char unknown_2_[0x860 - 2];
#else
    unsigned char unknown1_2_[0x840 - 2];
#endif
    Struct_020a95a4 unknown_840_;
#if defined(jpn)
    unsigned char unknown_23c4_[0x2774 - 0x23a4 + 0x20];
#else
    unsigned char unknown_23a4_[0x2774 - 0x23a4];
#endif
    Vector3i unknown_2774_;
    int unknown_2780_;
    short unknown_2784_;
    unsigned short unknown_2786_;
    unsigned char unknown_2788_;
    unsigned char unknown_2789_[0x2794 - 0x2789];
    int unknown_2794_;
    Vector3i unknown_2798_;
    int unknown_27a4_;
    short unknown_27a8_;
    unsigned short unknown_27aa_;
    unsigned char unknown_27ac_;
    unsigned char unknown_27ad_[3];
    int unknown_27b0_;
    unsigned short unknown_27b4_;
    unsigned short unknown_27b6_;
    unsigned char unknown_27b8_[0x27d0 - 0x27b8];
    unsigned char unknown_27d0_;
    unsigned char unknown_27d1_;
    unsigned short unknown_27d2_;
    unsigned short unknown_27d4_;
};

struct Struct_ov031_0224e6e0 {
    int unknown_0_;
    unsigned char unknown_4_[0x100d - 4];
    unsigned char unknown_100d_;
};

struct Struct_020a95a4_3 {
    unsigned char unknown_0_[0xa0];
    unsigned char unknown_a0_[0x178 - 0xa0];
    unsigned char unknown_178_[0x330];
    unsigned char unknown_4a8_[0x1a];
};

struct Struct_02109bf4_7 {
    unsigned char unknown_0_[0xc8];
    unsigned char unknown_c8_0_ : 1;
    unsigned char unknown_c8_1_ : 1;
    unsigned char unknown_c8_2_ : 1;
};

struct Struct_020a9eb8 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    TreasureMapMetadata unknown_2_[99];
};

struct Struct_020a9eb8_2 {
    unsigned char unknown_0_[0x3e4];
    float unknown_3e4_;
#if defined(jpn)
    unsigned char unknown_3e8_[0x569c - 0x3e8 - 0x260];
#else
    unsigned char unknown1_3e8_[0x569c - 0x3e8];
#endif
    unsigned char unknown_569c_[0x7c];
    unsigned char unknown_5718_[0x5cc8 - 0x5718];
    unsigned char unknown_5cc8_;
    unsigned char unknown_5cc9_[7];
    unsigned char unknown_5cd0_[10];
    unsigned char unknown_5cda_;
    unsigned char unknown_5cdb_;
    unsigned char unknown_5cdc_[0x190];
    unsigned char unknown_5e6c_[0x110];
    int unknown_5f7c_;
    unsigned char unknown_5f80_[0x200];
    unsigned char unknown_6180_[0x200];
    unsigned char unknown_6380_[0x63dc - 0x6380];
    unsigned char unknown_63dc_;
#if defined(jpn)
    unsigned char unknown_617d_[0x64f4 - 0x63dd + 0x20];
#else
    unsigned char unknown_63dd_[0x64f4 - 0x63dd];
#endif
    Struct_020a9eb8 unknown_64f4_;
    unsigned char unknown_6fca_[2];
    unsigned char unknown_6fcc_[0x200];
    unsigned int unknown_71cc_;
    unsigned char unknown_71d0_[0x71fc - 0x71d0];
    unsigned char unknown_71fc_[0x2c4];
    unsigned char unknown_74c0_[0x74fe - 0x74c0];
    struct Struct_020a9eb8_3 { unsigned char unknown_0_[6]; } unknown_74fe_;
    unsigned char unknown_7504_[0xec];
    unsigned char unknown_75f0_[0x4d0];
    unsigned char unknown_7ac0_[0x3b4];
    int unknown_7e74_;
};

struct Struct_020a95a4_5 {
    unsigned char unknown_0_[0x454];
    unsigned char unknown_454_[0x10];
};

struct Struct_020fdd44 {
    unsigned short unknown_0_;
    unsigned short unknown_2_0_ : 4;
    unsigned short unknown_2_4_ : 12;
    unsigned short unknown_4_;
};

struct Struct_0203dce4_2;
struct Struct_02028460_3;
struct Struct_0203e524 {
    short unknown_0_, unknown_2_, unknown_4_;
};
struct Struct_02087574;
struct Struct_02087574_2 {
    unsigned char unknown_0_[0x14];
};

struct Struct_020a95a4_6 {
    Struct_020a95a4_7 unknown_0_[13];
    unsigned char unknown_1d0c_;
    unsigned char unknown_1d0d_[4];
    unsigned char unknown_1d11_;
    struct Struct_01ff85b8 { unsigned char unknown_0_[0x12]; } unknown_1d12_[4];
    unsigned char unknown_1d5a_[2];
    unsigned char unknown_1d5c_[0x1d4];
    unsigned short unknown_1f30_[0x3f0];
    unsigned char unknown_2710_[0x3f0];
    unsigned char unknown_2b00_[8];
    unsigned char unknown_2b08_[0x128];
    int unknown_2c30_;
    int unknown_2c34_;
    int unknown_2c38_;
    int unknown_2c3c_;
    int unknown_2c40_;
    unsigned char unknown_2c44_[7];
    unsigned char unknown_2c4b_;
    unsigned short unknown_2c4c_;
    unsigned short unknown_2c4e_;
    unsigned short unknown_2c50_[4];
    unsigned char unknown_2c58_;
    unsigned char unknown_2c59_;
    unsigned char unknown_2c5a_;
    unsigned char unknown_2c5b_;
    unsigned short unknown_2c5c_;
    short unknown_2c5e_;
    Vector3i unknown_2c60_;
    int unknown_2c6c_;
    int unknown_2c70_;
    unsigned char unknown_2c74_;
    unsigned char unknown_2c75_;
    unsigned char unknown_2c76_;
    unsigned char unknown_2c77_;
    Struct_020a9eb8_2::Struct_020a9eb8_3 unknown_2c78_;
    unsigned char unknown_2c7e_[2];
    int unknown_2c80_;
    int unknown_2c84_;
    unsigned char unknown_2c88_[0x1a];
    unsigned char unknown_2ca2_;
    unsigned char unknown_2ca3_[5];
};

struct Struct_020a9eb8_4 {
    int unknown_0_;
    struct Struct_020a9eb8_5 {
        unsigned char unknown_0_;
        unsigned char unknown_1_;
        unsigned char unknown_2_[2];
        char unknown_4_[8];
        float unknown_c_;
    } unknown_4_;
};

struct Struct_020a9eb8_6 {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
    int unknown_c_;
    Struct_020a99d0_3 unknown_10_;
};

struct Struct_020a9eb8_7 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[3];
    unsigned char unknown_4_[0x190];
};

struct Struct_020a9eb8_8 {
    unsigned char unknown_0_[0xd98];
    int unknown_d98_;
    int unknown_d9c_;
    int unknown_da0_;
    unsigned short unknown_da4_;
    unsigned char unknown_da6_;
    unsigned char unknown_da7_;
};

struct Struct_020a9eb8_9 {
    unsigned char unknown_0_[0x200];
    unsigned char unknown_200_[0x200];
    int unknown_400_;
};

struct Struct_020a9eb8_10 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    Vector3i unknown_4_;
    unsigned short unknown_10_;
    unsigned short unknown_12_;
    unsigned char unknown_14_;
    unsigned char unknown_15_;
    Struct_0203e524 unknown_16_;
};

struct Struct_020a9eb8_11 {
    unsigned char unknown_0_[0x200];
    unsigned int unknown_200_;
    unsigned char unknown_204_[10];
};

struct Struct_020a9eb8_12 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    Struct_02087574_2 unknown_4_[3];
};

struct Struct_020a9eb8_13 {
    unsigned int unknown_0_;
    Struct_020a95a4_6 unknown_4_;
    Struct_020a9eb8_6 unknown_2cac_;
    unsigned char unknown_2ff0_[0xa0];
    unsigned char unknown_3090_[0x330];
    Struct_020a9eb8_7 unknown_33c0_;
    unsigned char unknown_3554_[0x4d0];
    unsigned char unknown_3a24_[0x3b4];
    unsigned char unknown_3dd8_[0xec];
    unsigned char unknown_3ec4_[0xd98];
    Struct_020a9eb8_8 unknown_4c5c_;
    Struct_020a9eb8_9 unknown_5a04_;
    Struct_020a9eb8 unknown_5e08_;
    unsigned char unknown_68de_[2];
    unsigned char unknown_68e0_[0x7c];
    Struct_020a9eb8_10 unknown_695c_;
    unsigned char unknown_6978_[0x2c4];
    unsigned char unknown_6c3c_[0x110];
    Struct_020a9eb8_11 unknown_6d4c_;
    unsigned char unknown_6f5c_[4];
};

struct Struct_020a9eb8_14 {
    unsigned char unknown_0_[0x84];
    Struct_020a9eb8_13 unknown_84_;
};

struct Struct_020a9eb8_15 {
    unsigned char unknown_0_;
    Struct_020a9eb8_14* unknown_4_;
};

extern "C" int func_01ff85b8(void* arg0, int arg1);
extern "C" Struct_020a95a4_2* func_02012fe4(void);
extern "C" Struct_ov031_0224e6e0* func_0202ae18(void);
extern "C" Struct_020a99d0_3* func_0205ec34(void);
extern "C" int func_0202c540(Struct_ov031_0224e6e0* arg0);
extern "C" int func_0202c508(Struct_ov031_0224e6e0* arg0);
extern "C" int func_02075acc(int arg0, void* arg1, unsigned int arg2, int arg3);
extern "C" void func_020830cc(Struct_020a95a4_5* arg0, Struct_020a95a4_7* arg1);
extern "C" void func_020a0c0c(void);
extern "C" void func_020a0cc4(unsigned int arg0);

extern "C" Struct_020a95a4_3* func_02094d6c(void);
extern "C" int func_020100a8(GameState* arg0);
extern "C" int func_0202b7d8(int* arg0);
extern "C" int func_0202ba00(int* arg0);
extern "C" int func_0206dfb0(int arg0, unsigned char* arg1, int arg2);
extern "C" Struct_020a95a4_5* func_02053c6c(unsigned char* arg0);
extern "C" unsigned short* func_0207c5f8(unsigned char* arg0, unsigned int arg1);
extern "C" unsigned char* func_0207c60c(void* arg0, unsigned int arg1);
extern "C" short func_0207c620(unsigned char* arg0, unsigned int arg1);
extern "C" unsigned char func_0207c694(unsigned char* arg0, unsigned int arg1);
extern "C" unsigned short* func_020120a0(char* arg0, unsigned int arg1);
extern "C" unsigned char func_0209ca98(char* arg0);
extern "C" unsigned char func_0205ea18(unsigned char* arg0);
extern "C" int func_0201079c(char* arg0);
extern "C" int func_020107d0(char* arg0);
extern "C" int func_02010804(char* arg0);
extern "C" int func_0201081c(char* arg0);
extern "C" void func_020ac4f8(int arg0);
extern "C" int func_0201b588(int arg0);
extern "C" void* func_02012d88(AllocatorUnion* arg0, unsigned int arg1);
extern "C" void func_02012da4(AllocatorUnion* arg0, void* arg1);
extern "C" int func_02011494(char* arg0, void* arg1);
extern "C" void func_020a99d0(Struct_020a99d0_3* arg0, Struct_020a99d0_3* arg1);
extern "C" int func_020ac7b4(int arg0);
extern "C" void func_ov017_021d0d58(void);
extern "C" Struct_020fdd44* func_02027ca4(void);
extern "C" Struct_020fdd44* func_02028bd0(Struct_020fdd44* arg0, int arg1);
extern "C" Struct_0203dce4_2* func_0203cf4c(void);
extern "C" int func_0203e524(Struct_0203dce4_2* arg0, Struct_02028460_3* arg1, Struct_0203e524* arg2);
extern "C" Struct_02087574_2* func_02087574(Struct_02087574* arg0, int arg1);

extern char data_020f1bf0[];
extern AllocatorUnion data_02114e20;
extern Global02109bf4 data_02109bf4;
extern unsigned char g_sePlayer[];

static inline int inline_020a9eb8(void* arg0, unsigned int arg1) {
    return func_01ff85b8((unsigned char*)arg0 + 4, arg1 - 4);
}

// USA: func_020a9eb8
extern "C" ARM int func_020a9eb8(Struct_020a9eb8_15* arg0, Struct_020a9eb8_13* arg1, unsigned int arg2, int arg3) {
    GameState* var0;
    Struct_020a99d0_3* var1;
    Struct_020a95a4_3* var2;
    Struct_020a95a4_8* var3;
    bool var4;
    unsigned short var5;
#if defined(jpn)
    char* var21;
#else
    int var6;
#endif
    int var7;
    int var8;
    int var9;
    int var10;
    int var11;
    Struct_020a95a4_3* var12;
    Struct_ov031_0224e6e0* var13;
    int var14;
    int var15;
    var0 = GameState::GetInstance();
    Struct_020a95a4_2* var16 = func_02012fe4();
    Struct_ov031_0224e6e0* var17 = func_0202ae18();
    var1 = func_0205ec34();
    var2 = func_02094d6c();
    var3 = static_cast<Struct_020a95a4_8*>(func_02010828(var0));
    reinterpret_cast<Struct_020a9eb8_2*>(var0)->unknown_5cc8_ = 1;

    var4 = false;
    var5 = 0;
    if ((arg2 & 1) || (arg2 & 8)) {
        var4 = true;
        if (func_0202b7d8(&var17->unknown_0_)) {
            if (func_0202c540(var17)) {
                var4 = false;
            }
        }
        if (arg2 & 8) {
            var4 = true;
        }
        if (var4) {
            if (func_0206dfb0((int)var1, var1->unknown_8c_, 0x113c)) {
                var5 = var3->unknown_2c94_;
            }
            var3->unknown_2c94_ = var16->unknown_0_;
            if (arg2 & 8) {
                var3->unknown_2c94_ = 0x6d;
            }
        }
    }

    Struct_020a9eb8_2* var18 = reinterpret_cast<Struct_020a9eb8_2*>(GameState::GetInstance());
    Struct_020a9eb8_4 var19;
    strcpy(var19.unknown_4_.unknown_4_, data_020f1bf0);
    var14 = arg2 & 4;
    float var20;
    if (var14) {
        var20 = var18->unknown_3e4_;
    } else {
        var20 = reinterpret_cast<GameState*>(var18)->GetDayTimer();
    }
    var19.unknown_4_.unknown_c_ = var20;
    if (!var14) {
        var18->unknown_3e4_ = var20;
    }
    var19.unknown_4_.unknown_0_ = arg3 != 0;
    var19.unknown_4_.unknown_1_ = 1;
    var19.unknown_0_ = inline_020a9eb8(&var19, sizeof(var19));
    func_02075acc(0x10, &var19, sizeof(var19), 0);
    func_020ac7b4(0);

#if defined(jpn)
    var21 = (char*)arg1 - 0x84;
#else
    char* var21 = (char*)arg1 - 0x84;
#endif
#if !defined(jpn)
    var6 = 0;
    if (arg3 == 0 && (arg2 & 0x10)) {
        var6 = 1;
    }
#endif

    {
        Struct_020a95a4_6* var22;
        Struct_020a95a4_2* var23;
        GameState* var24 = GameState::GetInstance();
        Struct_020a95a4_8* var25 = static_cast<Struct_020a95a4_8*>(func_02010828(var24));
        var13 = func_0202ae18();
        var23 = func_02012fe4();
        GetGameResources();
        var12 = func_02094d6c();
        func_020a0cc4(sizeof(Struct_020a95a4_6));
        var22 = (Struct_020a95a4_6*)func_02012d88(&data_02114e20, sizeof(Struct_020a95a4_6));
        if (var22 != NULL) {
            memset(var22, 0, sizeof(Struct_020a95a4_6));
            Struct_020a9eb8_2::Struct_020a9eb8_3 var26;
            unsigned char var27[4];
            var15 = func_02011494((char*)var24, var27);
            memcpy(var22->unknown_0_, var25->unknown_f80_, var25->unknown_2c8c_ * sizeof(Struct_020a95a4_7));
            for (var11 = 0; var11 < var15; var11++) {
                var10 = var11 + var25->unknown_2c8c_;
                GameObject* var28 = func_0200ff1c(var24, var27[var11]);
                if (var28 != NULL) {
                    Struct_020a95a4_5* var29 = func_02053c6c((unsigned char*)var28);
                    if (var29 != NULL) {
                        func_020830cc(var29, &var22->unknown_0_[var10]);
                    }
                }
            }
            var22->unknown_1d0c_ = var25->unknown_2c8c_;
            for (var9 = 0; var9 < var15; var9++) {
                GameObject* var30 = func_0200ff1c(var24, var27[var9]);
                if (var30 != NULL) {
                    memcpy(&var22->unknown_1d12_[var9], func_02053c6c((unsigned char*)var30)->unknown_454_, 0x10);
                }
            }
            memcpy(var22->unknown_1d0d_, var27, 4);
            var22->unknown_1d11_ = var15;
            if (func_020100a8(var24) != 0 || func_0202c540(var13) != 0) {
                var22->unknown_1d0d_[0] = 0;
                var22->unknown_1d11_ = 1;
            }
            memcpy(var22->unknown_1d5c_, var25->unknown_0_, sizeof(var25->unknown_0_));
            var8 = 0;
            for (var7 = 0; var7 < 8; var7++) {
                unsigned short* var31 = func_0207c5f8(var25->unknown_1d4_, var7);
                unsigned char* var32 = func_0207c60c(var25->unknown_1d4_, var7);
                short var33 = func_0207c620(var25->unknown_1d4_, var7);
                memcpy(&var22->unknown_1f30_[var8], var31, var33 * 2);
                memcpy(&var22->unknown_2710_[var8], var32, var33);
                var8 += var33;
                var22->unknown_2b00_[var7] = func_0207c694(var25->unknown_1d4_, var7);
            }
            memcpy(var22->unknown_2b08_, var25->unknown_e04_, sizeof(var25->unknown_e04_));
            var22->unknown_2c30_ = var25->unknown_f6c_;
            var22->unknown_2c34_ = var25->unknown_f68_;
            var22->unknown_2c38_ = var25->unknown_f70_;
            var22->unknown_2c3c_ = var25->unknown_f74_;
            var22->unknown_2c40_ = 0;
            memcpy(var22->unknown_2c44_, var25->unknown_2c8d_, sizeof(var25->unknown_2c8d_));
            Struct_020a9eb8_2* var34 = reinterpret_cast<Struct_020a9eb8_2*>(var24);
            if (var4) {
                var22->unknown_2c4c_ = var25->unknown_2c94_;
                var34->unknown_7e74_ = var25->unknown_2c94_;
                if (func_0202c508(var13)) {
                    func_ov017_021d0d58();
                }
            } else {
                var22->unknown_2c4c_ = var34->unknown_7e74_;
            }
            save->zero2 = 0;
            unsigned short* words = GetField0x74deForValidIndex_020120a0((char*)gs2, GetField0x3acValue_020100a8(gs2));
            save->words[0] = words[0];
            save->words[1] = words[1];
            save->words[2] = words[2];
            save->words[3] = words[3];
            save->globalByte = GetField0xcc0209ca98((char*)&data_02109bf4);
            save->globalByte2 = GetByteFieldAt0xcc_0205ea18(g_sePlayer);
            save->byteF7d = battle2->byteF7d;
            save->byte63dc = view2->byte63dc;
            GameStateSaveView::Bytes6* namePtr = &name;
            *namePtr = view2->name74fe;
            save->name = *namePtr;
#if defined(jpn)
            Struct_020a95a4* var37 = &var23->unknown_840_;
#endif
            if (func_0202c540(var13)) {
#if !defined(jpn)
                Struct_020a95a4* var37 = &var23->unknown_840_;
#endif
                var22->unknown_2c80_ = var37->unknown_1b50_;
                var22->unknown_2c84_ = var37->unknown_1b54_;
                var22->unknown_2c5c_ = var23->unknown_27aa_;
                var22->unknown_2c5e_ = var23->unknown_27a8_;
                var22->unknown_2c60_ = var23->unknown_2798_;
                var22->unknown_2c6c_ = var23->unknown_27a4_;
                var22->unknown_2c74_ = var23->unknown_27ac_;
                var22->unknown_2c70_ = var23->unknown_27b0_;
                var22->unknown_2c75_ = var23->unknown_27d2_;
                var22->unknown_2c76_ = var23->unknown_27d4_;
                var22->unknown_2c77_ = var23->unknown_27d1_;
            } else {
#if !defined(jpn)
                Struct_020a95a4* var37 = &var23->unknown_840_;
#endif
                var22->unknown_2c80_ = var37->unknown_1b48_;
                var22->unknown_2c84_ = var37->unknown_1b4c_;
                var37->unknown_1b50_ = var22->unknown_2c80_;
                var37->unknown_1b54_ = var22->unknown_2c84_;
                var22->unknown_2c5c_ = var23->unknown_2786_;
                var22->unknown_2c5e_ = var23->unknown_2784_;
                var22->unknown_2c60_ = var23->unknown_2774_;
                var22->unknown_2c6c_ = var23->unknown_2780_;
                var22->unknown_2c74_ = var23->unknown_2788_;
                var22->unknown_2c70_ = var23->unknown_2794_;
                var23->unknown_27aa_ = var22->unknown_2c5c_;
                var23->unknown_27a8_ = var22->unknown_2c5e_;
                var23->unknown_2798_ = var22->unknown_2c60_;
                var23->unknown_27a4_ = var22->unknown_2c6c_;
                var23->unknown_27ac_ = var22->unknown_2c74_;
                var23->unknown_27b0_ = var22->unknown_2c70_;
                var22->unknown_2c75_ = var23->unknown_27b4_;
                var22->unknown_2c76_ = var23->unknown_27b6_;
                var22->unknown_2c77_ = var23->unknown_27d0_;
                var23->unknown_27d2_ = var22->unknown_2c75_;
                var23->unknown_27d4_ = var22->unknown_2c76_;
                var23->unknown_27d1_ = var22->unknown_2c77_;
            }
            memcpy(var22->unknown_2c88_, var12->unknown_4a8_, sizeof(var12->unknown_4a8_));
#if !defined(jpn)
            var22->unknown_2ca2_ = var6;
#endif
            func_02075acc((char*)&arg1->unknown_4_ - var21, var22, sizeof(Struct_020a95a4_6), 0);
            func_02012da4(&data_02114e20, var22);
        }
        func_020a0c0c();
        if (func_0206dfb0((int)var1, var1->unknown_8c_, 0x113c)) {
            var3->unknown_2c94_ = var5;
        }
    }

    {
        GameState* var38 = GameState::GetInstance();
        func_0202ae18();
        if (var14) {
            func_02075acc((char*)&arg1->unknown_2cac_ - var21 + 0x1fb, var1->unknown_1eb_, sizeof(var1->unknown_1eb_), 0);
        } else {
            Struct_020a9eb8_6 var39;
            var39.unknown_0_ = func_0201079c((char*)var38);
            var39.unknown_4_ = func_020107d0((char*)var38);
            var39.unknown_8_ = func_02010804((char*)var38);
            var39.unknown_c_ = func_0201081c((char*)var38);
            func_020a99d0(&var39.unknown_10_, var1);
            func_02075acc((char*)&arg1->unknown_2cac_ - var21, &var39, sizeof(var39), 0);
        }
    }

    if (!var14) {
        Struct_020a9eb8_2* var40 = reinterpret_cast<Struct_020a9eb8_2*>(GameState::GetInstance());
        Struct_020a9eb8_7* var41 = (Struct_020a9eb8_7*)func_02012d88(&data_02114e20, sizeof(Struct_020a9eb8_7));
        if (var41 != NULL) {
            var41->unknown_0_ = var40->unknown_5cda_;
            memcpy(var41->unknown_4_, var40->unknown_5cdc_, sizeof(var41->unknown_4_));
            func_02075acc((char*)&arg1->unknown_33c0_ - var21, var41, sizeof(Struct_020a9eb8_7), 0);
            func_02012da4(&data_02114e20, var41);
        }
        int var42 = (char*)arg1->unknown_3ec4_ - var21;
        Struct_020a95a4* var43 = &func_02012fe4()->unknown_840_;
        func_02075acc(var42, var43->unknown_0_, sizeof(var43->unknown_0_), 0);
        func_020a0cc4(sizeof(Struct_020a9eb8_8));
        Struct_020a9eb8_8* var44 = (Struct_020a9eb8_8*)func_02012d88(&data_02114e20, sizeof(Struct_020a9eb8_8));
        if (var44 != NULL) {
            VectorizedInvertedMemcpy(var43->unknown_d98_, var44->unknown_0_, sizeof(var43->unknown_d98_));
            var44->unknown_d98_ = var43->unknown_1b38_;
            var44->unknown_d9c_ = var43->unknown_1b34_;
            var44->unknown_da0_ = var43->unknown_1b44_;
            var44->unknown_da4_ = var43->unknown_1b3c_;
            var44->unknown_da6_ = var43->unknown_1b61_;
            var44->unknown_da7_ = 0;
            func_02075acc(var42 + sizeof(var43->unknown_0_), var44, sizeof(Struct_020a9eb8_8), 0);
            func_02012da4(&data_02114e20, var44);
        }
        func_020a0c0c();
        Struct_020a9eb8_2* var45 = reinterpret_cast<Struct_020a9eb8_2*>(GameState::GetInstance());
        Struct_020a9eb8_9 var46;
        var46.unknown_400_ = var45->unknown_5f7c_;
        memcpy(var46.unknown_0_, var45->unknown_5f80_, sizeof(var46.unknown_0_));
        memcpy(var46.unknown_200_, var45->unknown_6180_, sizeof(var46.unknown_200_));
        func_02075acc((char*)&arg1->unknown_5a04_ - var21, &var46, sizeof(var46), 0);
        func_02075acc((char*)arg1->unknown_6c3c_ - var21, reinterpret_cast<Struct_020a9eb8_2*>(GameState::GetInstance())->unknown_5e6c_, 0x110, 0);
    }
    func_02075acc((char*)arg1->unknown_2ff0_ - var21, var2->unknown_0_, sizeof(var2->unknown_0_), 0);
    func_02075acc((char*)arg1->unknown_3090_ - var21, func_02094d6c()->unknown_178_, 0x330, 0);
    func_02075acc((char*)arg1->unknown_3554_ - var21, reinterpret_cast<Struct_020a9eb8_2*>(var0)->unknown_75f0_, 0x4d0, 0);
    func_02075acc((char*)arg1->unknown_3a24_ - var21, reinterpret_cast<Struct_020a9eb8_2*>(var0)->unknown_7ac0_, 0x3b4, 0);

    Struct_ov031_0224e6e0* var47 = func_0202ae18();
    int var48 = func_0202ba00(&var47->unknown_0_);
    int var49 = var47->unknown_100d_;
    int var50 = 0;
    if ((var48 == 5 && var49 > 1) || var48 == 6) {
        var50 = 1;
    }
    func_020ac4f8(var50);

    func_02075acc((char*)arg1->unknown_3dd8_ - var21, reinterpret_cast<Struct_020a9eb8_2*>(GameState::GetInstance())->unknown_7504_, 0xec, 0);

    {
        int var51;
        int var52;
        var51 = (char*)&arg1->unknown_5e08_ - var21;
#if defined(jpn)
        Struct_020a95a4_2* var54;
        GameState* var53 = GameState::GetInstance();
        var54 = func_02012fe4();
#else
        GameState* var53 = GameState::GetInstance();
        Struct_020a95a4_2* var54 = func_02012fe4();
#endif
        Struct_020a9eb8 var55;
        if (arg3) {
            var51 += 0x8000;
        }
        VectorizedInvertedMemcpy(&reinterpret_cast<Struct_020a9eb8_2*>(var53)->unknown_64f4_, &var55, sizeof(var55));
        if (!func_0201b588(var54->unknown_0_)) {
            TreasureMapMetadata* var56 = var55.unknown_2_;
            for (var52 = 0; var52 < var55.unknown_0_; var52++) {
                var56->ClearInitialByteUnknownBit();
                var56++;
            }
        }
        func_02075acc(var51, &var55, sizeof(var55), 0);
    }

    unsigned char* var57 = reinterpret_cast<Struct_020a9eb8_2*>(GameState::GetInstance())->unknown_569c_;
    func_02075acc((char*)arg1->unknown_68e0_ - var21, var57, 0x7c, 0);

    if (arg3) {
        Struct_020a9eb8_10 var58;
        GameObject* var59 = GameState::GetInstance()->GetUnknownGameObject();
        if (var59 != NULL) {
            var58.unknown_0_ = var59->obj3D_.GetField06();
            var58.unknown_4_ = var59->obj3D_.position_;
            var58.unknown_2_ = var59->obj3D_.rotation_.y;
        }
        Struct_020a95a4_2* var60 = func_02012fe4();
        Struct_020fdd44* var61 = func_02028bd0(func_02027ca4(), var60->unknown_0_);
        if (var61 == NULL) {
            var58.unknown_12_ = 0;
            var58.unknown_10_ = 0;
        } else {
            var58.unknown_12_ = var61->unknown_4_;
            var58.unknown_10_ = var61->unknown_2_4_;
        }
        var58.unknown_14_ = data_02109bf4.unknown_c8_2_;
        var58.unknown_15_ = func_0203e524(func_0203cf4c(), (Struct_02028460_3*)&var59->obj3D_.position_, &var58.unknown_16_);
        func_02075acc((char*)&arg1->unknown_695c_ - var21, &var58, sizeof(var58), 0);
    }

    unsigned char* var62 = reinterpret_cast<Struct_020a9eb8_2*>(GameState::GetInstance())->unknown_71fc_;
    func_02075acc((char*)arg1->unknown_6978_ - var21, var62, 0x2c4, 0);

    if (arg3) {
        if (arg3) {
            GameState* var63 = GameState::GetInstance();
            Struct_020a9eb8_2* var64 = reinterpret_cast<Struct_020a9eb8_2*>(var63);
            GetGameResources();
            Struct_020a9eb8_11 var65;
            VectorizedInvertedMemcpy(var64->unknown_6fcc_, var65.unknown_0_, sizeof(var65.unknown_0_));
            VectorizedInvertedMemcpy(var64->unknown_5cd0_, var65.unknown_204_, sizeof(var65.unknown_204_));
            var65.unknown_200_ = var64->unknown_71cc_;
            if (var63->GetGrottoStruct()->unknown_0[3]) {
                var65.unknown_200_ |= 1;
            }
            func_02075acc((char*)&arg1->unknown_6d4c_ - var21, &var65, sizeof(var65), 0);
        }
    } else if ((arg2 & 0x10) && arg3 == 0) {
        int var66;
        int var67;
        Struct_020a95a4_8* var68 = static_cast<Struct_020a95a4_8*>(func_02010828(GameState::GetInstance()));
        Struct_020a9eb8_12 var69;
        memset(&var69, 0, sizeof(var69));
        var67 = 0;
        for (var66 = 0; var66 < var68->unknown_2c8c_; var66++) {
            Struct_02087574_2* var70 = func_02087574((Struct_02087574*)var68, var68->unknown_f80_[var66].unknown_0_0_);
            if (var70 != NULL) {
                memcpy(&var69.unknown_4_[var67], var70, sizeof(Struct_02087574_2));
                var67++;
            }
        }
        if (var67) {
            var69.unknown_0_ = 1;
            var69.unknown_2_ = var67;
        }
        func_02075acc((char*)&arg1->unknown_6d4c_ - var21, &var69, sizeof(var69), 0);
    }

    Struct_020a9eb8_14* var71 = arg0->unknown_4_;
    if (var71 != NULL) {
        arg1->unknown_0_ = inline_020a9eb8(&var71->unknown_84_, sizeof(var71->unknown_84_));
        func_02075acc((char*)&arg1->unknown_0_ - var21, arg1, sizeof(arg1->unknown_0_), 0);
    }
    return 1;
}
