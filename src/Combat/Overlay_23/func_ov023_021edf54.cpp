#include <globaldefs.h>
#include <std_library_functions.h>
#include "GameState/GameState.h"
#include <Filesystem/BackgroundLoader.h>
#include "Resource/GameResources.h"

struct Struct_0202c1a4;
struct Struct_02010088;
struct Struct_ov023_021edf54;
struct Struct_020e385c;
struct Struct_020a0858;
struct Struct_020a0300;

struct Struct_ov023_021ed7e0 {
    unsigned int unknown_0_0_ : 10;
    unsigned int unknown_1_2_ : 1;
    unsigned int unknown_1_3_ : 7;
    unsigned int unknown_2_2_ : 7;
    unsigned int unknown_3_1_ : 7;
};

struct Struct_ov023_021edf54_17 { int unknown_0_[6]; };
struct Struct_ov023_021edf54_18 { int unknown_0_[9]; };
struct Struct_ov023_021edf54_22 { int unknown_0_[22]; };
struct Struct_ov023_021edf54_23 { int unknown_0_[41]; };
struct Struct_ov023_021edf54_24 { int unknown_0_[13]; };
struct Struct_ov023_021edf54_25 { int unknown_0_[88]; };
struct Struct_ov023_021edf54_26 { int unknown_0_[39]; };
struct Struct_ov023_021edf54_27 { short unknown_0_[13]; };
struct Struct_ov023_021edf54_28 { short unknown_0_[8]; };
struct Struct_ov023_021edf54_29 { short unknown_0_[14]; };
struct Struct_ov023_021edf54_30 { short unknown_0_[96]; };
struct Struct_ov023_021edf54_31 { char unknown_0_[13]; };
struct Struct_ov023_021edf54_32 { char unknown_0_[27]; };
struct Struct_ov023_021edf54_2 { char unknown_0_[384]; };
struct Struct_ov023_021edf54_3 { char unknown_0_[36]; };
struct Struct_ov023_021edf54_4 { char unknown_0_[9]; };
struct Struct_ov023_021edf54_5 { char unknown_0_[24]; };

#if defined(jpn)
struct Struct_ov023_021edf54_6 { char unknown_0_[231]; };
enum { Enum_ov023_021edf54_48 = 0xc, Enum_ov023_021edf54_0 = -0xc, Enum_ov023_021edf54_0_2 = -0x84, Enum_ov023_021edf54_0_3 = 0x1f0,
       Enum_ov023_021edf54_0_4 = -0x220, Enum_ov023_021edf54_0_5 = -0x1d0 };
#else
enum { Enum_ov023_021edf54_48 = 0x30, Enum_ov023_021edf54_0 = 0, Enum_ov023_021edf54_0_2 = 0, Enum_ov023_021edf54_0_3 = 0,
       Enum_ov023_021edf54_0_4 = 0, Enum_ov023_021edf54_0_5 = 0 };
#endif

struct Struct_ov023_021edf54_7 {
    Struct_ov023_021edf54_17 unknown_0_;
    Struct_ov023_021edf54_18 unknown_18_;
    Struct_ov023_021edf54_22 unknown_3c_;
    Struct_ov023_021edf54_23 unknown_94_;
    Struct_ov023_021edf54_24 unknown_138_;
    Struct_ov023_021edf54_27 unknown_16c_;
    Struct_ov023_021edf54_31 unknown_186_;
    Struct_ov023_021edf54_25 unknown_194_;
    Struct_ov023_021edf54_25 unknown_2f4_;
    Struct_ov023_021edf54_28 unknown_454_;
    Struct_ov023_021edf54_32 unknown_464_;
    unsigned long long unknown_480_;
    Struct_ov023_021edf54_29 unknown_488_;
    Struct_ov023_021edf54_30 unknown_4a4_;
    unsigned short unknown_564_;
    unsigned short unknown_566_;
    short unknown_568_;
    unsigned char unknown_56a_;
    unsigned char unknown_56b_;
    unsigned char unknown_56c_;
    unsigned char unknown_56d_;
    unsigned char unknown_56e_;
#if defined(jpn)
    Struct_ov023_021edf54_6 unknown_56f_;
#else
    unsigned char unknown1_56f_;
    Struct_ov023_021edf54_2 unknown_570_;
#endif
    Struct_ov023_021edf54_25 unknown_6f0_;
    Struct_ov023_021edf54_26 unknown_850_;
    Struct_ov023_021edf54_3 unknown_8ec_;
    Struct_ov023_021edf54_4 unknown_910_;
    Struct_ov023_021edf54_17 unknown_91c_;
    Struct_ov023_021edf54_5 unknown_934_;
    int unknown_94c_;
    int unknown_950_;
    unsigned short unknown_954_;
    short unknown_956_;
    short unknown_958_;
    short unknown_95a_;
    short unknown_95c_;
    short unknown_95e_;
    unsigned short unknown_960_;
    unsigned short unknown_962_;

};

struct Struct_ov023_021edf54_8 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    int unknown_4_;
    char unknown_8_[Enum_ov023_021edf54_48];
    Struct_ov023_021edf54_7 unknown_38_;
};

struct Struct_ov023_021edf54_9 {
    char unknown_0_[0x10];
    unsigned char unknown_10_;
    char unknown_11_[0xf4 - 0x11];
    char unknown_f4_[0x24];
    Struct_ov023_021edf54_8 unknown_118_[4];
    unsigned char unknown_2798_;
    char unknown_2799_[4];
    unsigned char unknown_279d_;
};

struct Struct_ov023_021edf54_10 {
    Struct_ov023_021edf54_9* unknown_0_;
};

struct Struct_ov023_021edf54_11 {
    char unknown_0_[0x134];
    const char* unknown_134_;
    char unknown_138_[0x150 + Enum_ov023_021edf54_0 - 0x138];
    Struct_ov023_021edf54_7* unknown_150_;
};

struct Struct_ov023_021edf54_12 {
    unsigned short unknown_0_0_ : 3;
    unsigned short unknown_0_3_ : 11;
    unsigned short unknown_1_6_ : 2;
    unsigned short unknown_2_;
    short unknown_4_;
    unsigned char unknown_6_;
    char unknown_7_[3];
};

struct Struct_ov023_021edf54_13 {
    unsigned char unknown_0_;
    unsigned char unknown_1_0_ : 6;
    unsigned char unknown_1_6_ : 2;
    char unknown_2_[0x4e - 2];
    unsigned short unknown_4e_;
};

struct Struct_ov023_021edf54_14 {
    char unknown_0_[0x81b0];
    Struct_ov023_021edf54_13 unknown_81b0_;
    char unknown_8200_[0x8d66 - 0x8200];
    Struct_ov023_021edf54_12 unknown_8d66_[17];
    char unknown_8e10_[0x8e15 - 0x8e10];
    unsigned char unknown_8e15_;
    char unknown_8e16_[0x8e20 - 0x8e16];
    int unknown_8e20_;
    char unknown_8e24_[0x8e28 - 0x8e24];
    int unknown_8e28_;
    int unknown_8e2c_;
    int unknown_8e30_;
    unsigned int unknown_8e34_;
    char unknown_8e38_[0x8e3c - 0x8e38];
    float unknown_8e3c_;
    float unknown_8e40_;

    unsigned char inline_ov023_021edf54() const { return unknown_8e15_; }
    int inline_ov023_021edf54_2() const { return unknown_8e28_; }
    int inline_ov023_021edf54_3() const { return unknown_8e2c_; }
};

struct Struct_ov023_021edf54_15 {
    char unknown_0_[8];
    unsigned short unknown_8_;
    char unknown_a_[2];
    int unknown_c_;
    char unknown_10_[0x25 - 0x10];
    unsigned char unknown_25_;
    char unknown_26_[0x2a - 0x26];
    signed char unknown_2a_;
};

struct Struct_ov023_021edf54_16 {
    char unknown_0_[0x29c + Enum_ov023_021edf54_0_2];
    Struct_ov023_021edf54_14* unknown_29c_;
    Struct_ov023_021edf54_15* unknown_2a0_;
    char unknown_2a4_[0xeac - 0x2a4];
    int unknown_eac_;
    char unknown_eb0_[0x5758 - 0xeb0 + Enum_ov023_021edf54_0_3 - Enum_ov023_021edf54_0_2];
    int unknown_5758_[4];
    int unknown_5768_;
    char unknown_576c_[0x58c0 - 0x576c];
    int unknown_58c0_;
    int unknown_58c4_;
    unsigned char unknown_58c8_;
    unsigned char unknown_58c9_;
    unsigned short unknown_58ca_;
    unsigned short unknown_58cc_;
    char unknown_58ce_[0x58d0 - 0x58ce];
    char unknown_58d0_[0x5900 - 0x58d0];
    unsigned char unknown_5900_;
    signed char unknown_5901_;
    char unknown_5902_[0x6e24 - 0x5902];
    int unknown_6e24_;
    unsigned short unknown_6e28_;
};

struct Struct_ov023_021edf54_19 {
    char unknown_0_[0x42e2 + Enum_ov023_021edf54_0_4];
    unsigned char unknown_42e2_;
};

struct Struct_ov023_021edf54_20 {
    char unknown_0_[0x19b2 + Enum_ov023_021edf54_0_5];
    unsigned char unknown_19b2_;
};

struct Struct_ov023_021edf54_21 {
    char unknown_0_[0x68];
    char unknown_68_[0xb0 - 0x68];
};

extern "C" Struct_ov023_021edf54_10 _ZZ21inline_ov023_021f4c04vE1s;

extern "C" {
int func_ov023_021f5340(void* arg0);
void* func_0202ae18();
int func_ov000_0215e9fc(Struct_ov023_021edf54_14* arg0, short* arg1, int arg2, unsigned int arg3);
int func_ov000_0215ec1c(Struct_ov023_021edf54_14* arg0, short* arg1, int arg2, int arg3);
int func_ov023_021f4098(Struct_ov023_021edf54_16* arg0, int arg1, int arg2);
void func_ov023_021f454c(Struct_ov023_021edf54_16* arg0);
void func_ov017_021cd218(unsigned short arg0, unsigned short arg1, unsigned short arg2, unsigned short arg3, unsigned short arg4, unsigned short arg5);
void func_ov017_021cd590(unsigned short arg0, int* arg1, int arg2, int arg3);
void func_ov017_021cd35c(unsigned short arg0, char* arg1, unsigned char arg2, signed char arg3);
void func_ov017_021cd4c8(unsigned short arg0, unsigned short arg1, signed char arg2);
int func_0202c540(void* arg0);
int func_020abe84(void* arg0, short* arg1, Struct_ov023_021ed7e0* arg2, int arg3);
int func_ov023_021f5150(Struct_ov023_021edf54_16* arg0, Struct_ov023_021edf54_15* arg1, int* arg2, int* arg3, int arg4);
}

Renderer_021edf54* MessageSystem_GetInstance();
void ClearSubstructFlag0x4_02049ae4(unsigned char* obj);
void SetFieldForListedCombatants021f50fc();
int CheckField0NonZero_0202b7d8(int* mode);
int GetSearchStructCurrentArrEntry(SearchStruct0202c1a4* mode);
int TestBitAt0x34_020a35e0(unsigned char* info, unsigned char index);
int GameState_GetProtagonistIndex(GameState* game);
int LoadBattleBlock020ac4c0(void* dst);
void AddSaturateField0x48_020a0858(S_a0858* block, unsigned int amount);
void AddClamped24BitFieldAt0x24_020a0300(S_a0300* block, unsigned int amount);
int CopyInBattleField0x7540_020ac494(void* src);
void SetCombatWorkFlags0x55f4_ov000_02160fa8(void* self, int flag);
int GetCombatWorkFlags0x55f4_ov000_02160fd4(void* self, int flag);
void ClearFlagBits10to24_021ed7e0(Flags_021ed7e0* flags);
int CopyIndexedRegion0x75f0_020ac020(void* unused, short* indices, int* dest, int count);
unsigned short GetTableValue_0202053c(void* obj);
int IsFlag10088Set_02010088(S_10088* obj);
int GetTableEntry138_021eea98(Obj021eea98* obj);
int GetFieldAt0x150_02053c6c(unsigned char* obj);
unsigned char CopyOutRegion0x571d_020114ec(char* game, void* dst);
TagValueEntry020e385c* GetData02153660_020e3808();
void SetEntryBitUnlessMatching020e39d4(TagValueEntry020e385c* tags, int a, int b, int c);

static inline unsigned int inline_020417b0_2(float arg0, int arg1) {
    return arg1 * arg0;
}

static inline unsigned int inline_ov023_021edf54_4(float arg0, unsigned int arg1) {
    return arg1 * arg0;
}

// USA: func_ov023_021edf54
extern "C" ARM int func_ov023_021edf54(Struct_ov023_021edf54_16* arg0) {
    void* var0;
    int var1[8];
    int var2[4];
    short var3[0x10];
    short var4[4];
    GameState* var5 = GameState::GetInstance();
    if (!func_ov023_021f5340(_ZZ21inline_ov023_021f4c04vE1s.unknown_0_->unknown_f4_))
        return arg0->unknown_eac_;
    if (BackgroundLoader::GetInstance()->GetNumQueuedTasks() > 0)
        return arg0->unknown_eac_;

    Resources_021edf54* resources = (Resources_021edf54*)GetGameResources();
    Renderer_021edf54* renderer = MessageSystem_GetInstance();
    mode = func_0202ae18();

    Struct_ov023_021edf54_14* var8 = arg0->unknown_29c_;
    if (var8 != 0) {
        int var9;
        int var10;
        GameState* var11 = GameState::GetInstance();
        var10 = 0;
        var10 += func_ov000_0215e9fc(var8, var3, 0x10, var10);
        var10 += func_ov000_0215ec1c(var8, var3 + var10, 0x10 - var10, 0);
        for (var9 = 0; var9 < var10; var9++) {
            GameObject* var12 = var11->GetCombatantByIndex(var3[var9]);
            if (var12 != 0)
                func_02049ae4((unsigned char*)var12);
        }
    }
    func_ov023_021f50fc();

    if (!func_0202b7d8((int*)var0) || arg0->unknown_2a0_->unknown_2a_ == func_0202c1a4((Struct_0202c1a4*)var0)) {
        {
            int var13 = arg0->unknown_29c_->inline_ov023_021edf54_2();
            float var14 = arg0->unknown_29c_->unknown_8e3c_;
            arg0->unknown_58c0_ = (unsigned int)(var13 * var14);
        }
        {
            int var15 = arg0->unknown_29c_->inline_ov023_021edf54_3();
            float var16 = arg0->unknown_29c_->unknown_8e40_;
            arg0->unknown_58c4_ = (unsigned int)(var15 * var16);
        }
        arg0->unknown_58cc_ = arg0->unknown_29c_->unknown_8e20_;

        int var17 = func_ov000_0215e9fc(arg0->unknown_29c_, var4, 4, 1);
        arg0->unknown_58c8_ = 0;
        for (int var18 = 0; var18 < var17; var18++)
            arg0->unknown_58c8_ |= 1 << var4[var18];

        int var19 = 0;
        for (int var20 = 0; var20 < 4; var20++) {
            if (func_020a35e0((unsigned char*)arg0->unknown_2a0_, var20))
                arg0->unknown_5758_[var20] = func_ov023_021f4098(arg0, var20, var19);
        }

        Struct_ov023_021edf54_14* var21 = arg0->unknown_29c_;
        int var22 = var21->unknown_8e30_;
        int var23;
        int var24;
        int var25;
        int var26;
        Struct_ov023_021edf54_12* var27 = var21->unknown_8d66_;
        if (var22 == 0) {
            Struct_ov023_021edf54_13* var28 = &var21->unknown_81b0_;
            unsigned char var29 = var21->inline_ov023_021edf54();
            int var30 = 0;
            if (var28->unknown_0_ <= var29)
                var30 = 1;
            if (var28->unknown_1_6_ > 1) {
                if (var30 == 0)
                    arg0->unknown_58c9_ = 5;
                else
                    arg0->unknown_58c9_ = 8;
                arg0->unknown_58ca_ = 0;
            } else if (var28->unknown_0_ > 1) {
                if (var30 == 0)
                    arg0->unknown_58c9_ = 4;
                else
                    arg0->unknown_58c9_ = 7;
                arg0->unknown_58ca_ = var28->unknown_4e_;
            } else {
                if (var30 == 0)
                    arg0->unknown_58c9_ = 3;
                else
                    arg0->unknown_58c9_ = 6;
                arg0->unknown_58ca_ = var28->unknown_4e_;
            }
        } else {
            var23 = 0;
            var24 = 0;
            for (var25 = 0; var25 < var22; var25++) {
                var23 += var27[var25].unknown_0_3_;
                for (var26 = 0; var26 < var24; var26++) {
                    if (var27[var25].unknown_2_ == var1[var26])
                        break;
                }
                if (var26 == var24)
                    var1[var24++] = var27[var25].unknown_2_;
            }
            if (var23 == 1) {
                arg0->unknown_58c9_ = 0;
                arg0->unknown_58ca_ = var27[0].unknown_2_;
            } else if (var24 > 1) {
                arg0->unknown_58c9_ = 2;
                arg0->unknown_58ca_ = 0;
            } else {
                arg0->unknown_58c9_ = 1;
                arg0->unknown_58ca_ = var27[0].unknown_2_;
            }
        }

        func_ov023_021f454c(arg0);
        func_ov017_021cd218(arg0->unknown_2a0_->unknown_8_, arg0->unknown_58c4_, arg0->unknown_58cc_, arg0->unknown_58c8_, arg0->unknown_58c9_, arg0->unknown_58ca_);
        if (arg0->unknown_2a0_->unknown_25_ == 0) {
            func_ov017_021cd590(arg0->unknown_2a0_->unknown_8_, arg0->unknown_5758_, 0, 0);
            func_ov017_021cd35c(arg0->unknown_2a0_->unknown_8_, arg0->unknown_58d0_, arg0->unknown_5900_, arg0->unknown_5901_);
            if (arg0->unknown_6e24_ != 0)
                func_ov017_021cd4c8(arg0->unknown_2a0_->unknown_8_, arg0->unknown_6e28_, arg0->unknown_5901_);
            if (arg0->unknown_29c_->unknown_8e34_ != 0) {
                unsigned int var31 = inline_ov023_021edf54_4(arg0->unknown_29c_->unknown_8e3c_, arg0->unknown_29c_->unknown_8e34_);
                GameState* var32 = GameState::GetInstance();
                for (int var33 = 0; var33 < 4; var33++) {
                    if (func_020a35e0((unsigned char*)arg0->unknown_2a0_, var33))
                        var2[var33] = func_ov023_021f4098(arg0, var33, var31);
                }
                func_ov017_021cd590(self->info_->event_, gained, 0, 1);
                int leader = GameState_GetProtagonistIndex(state);
                BattleBlock_021edf54 block;
                LoadBattleBlock020ac4c0(&block);
                AddSaturateField0x48_020a0858((S_a0858*)&block, gained[leader]);
                AddClamped24BitFieldAt0x24_020a0300((S_a0300*)block.sub68_, gained[leader]);
                CopyInBattleField0x7540_020ac494(&block);
            }
        }
    } else {
        if (var6->unknown_42e2_ != 0)
            func_ov000_02160fa8(arg0, 0x2000000);
        if (func_0202c540(var0) && arg0->unknown_2a0_->unknown_25_ != 0)
            var7->unknown_19b2_ = 0;
        if (!func_ov000_02160fd4(arg0, 0x2000))
            return arg0->unknown_eac_;
        if (!func_ov000_02160fd4(arg0, 0x4000))
            return arg0->unknown_eac_;
        if (!func_ov000_02160fd4(arg0, 0x8000))
            return arg0->unknown_eac_;
    }

    Struct_ov023_021edf54_12* var36;
    int var37;
    Struct_ov023_021edf54_12* var38;
    int var39;
    Struct_ov023_021edf54_14* var40 = arg0->unknown_29c_;
    var39 = var40->unknown_8e30_;
    var38 = var40->unknown_8d66_;
    for (var37 = 0; var37 < var39; var37++) {
        var36 = &var38[var37];
        Struct_ov023_021ed7e0 var41;
        func_ov023_021ed7e0(&var41);
        short var42 = var36->unknown_4_;
        if (func_020ac020(0, &var42, (int*)&var41, 1)) {
            unsigned int var43 = var41.unknown_0_0_ + var36->unknown_0_3_;
            if (var43 > 999)
                var43 = 999;
            var41.unknown_0_0_ = var43;
            if (var36->unknown_6_ != 0)
                var41.unknown_1_2_ = var36->unknown_6_;
            func_020abe84(0, &var42, &var41, 1);
        }
    }

    Struct_ov023_021edf54_8* var44 = _ZZ21inline_ov023_021f4c04vE1s.unknown_0_->unknown_118_;
    for (int var45 = 0; var45 < 4; var45++) {
        if (func_020a35e0((unsigned char*)arg0->unknown_2a0_, var45)) {
            Struct_ov023_021edf54_11* var46 = (Struct_ov023_021edf54_11*)func_0200ff1c(var5, var45);
            if (var46 != 0) {
                var44->unknown_0_ = var45;
                var44->unknown_1_ = var46->unknown_150_->unknown_950_;
                var44->unknown_2_ = func_0202053c(var46);
                var44->unknown_3_ = func_02010088((Struct_02010088*)var46);
                var44->unknown_4_ = arg0->unknown_5758_[var45] + func_ov023_021eea98((Struct_ov023_021edf54*)var46);
                Struct_ov023_021edf54_7* var47 = (Struct_ov023_021edf54_7*)func_02053c6c((unsigned char*)var46);
                var44->unknown_38_.unknown_0_ = var47->unknown_0_;
                var44->unknown_38_.unknown_18_ = var47->unknown_18_;
                var44->unknown_38_.unknown_3c_ = var47->unknown_3c_;
                var44->unknown_38_.unknown_94_ = var47->unknown_94_;
                var44->unknown_38_.unknown_138_ = var47->unknown_138_;
                var44->unknown_38_.unknown_16c_ = var47->unknown_16c_;
                var44->unknown_38_.unknown_186_ = var47->unknown_186_;
                var44->unknown_38_.unknown_194_ = var47->unknown_194_;
                var44->unknown_38_.unknown_2f4_ = var47->unknown_2f4_;
                var44->unknown_38_.unknown_454_ = var47->unknown_454_;
                var44->unknown_38_.unknown_464_ = var47->unknown_464_;
                var44->unknown_38_.unknown_480_ = var47->unknown_480_;
                var44->unknown_38_.unknown_488_ = var47->unknown_488_;
                var44->unknown_38_.unknown_4a4_ = var47->unknown_4a4_;
                var44->unknown_38_.unknown_564_ = var47->unknown_564_;
                var44->unknown_38_.unknown_566_ = var47->unknown_566_;
                var44->unknown_38_.unknown_568_ = var47->unknown_568_;
                var44->unknown_38_.unknown_56a_ = var47->unknown_56a_;
                var44->unknown_38_.unknown_56b_ = var47->unknown_56b_;
                var44->unknown_38_.unknown_56c_ = var47->unknown_56c_;
                var44->unknown_38_.unknown_56d_ = var47->unknown_56d_;
                var44->unknown_38_.unknown_56e_ = var47->unknown_56e_;
#if defined(jpn)
                var44->unknown_38_.unknown_56f_ = var47->unknown_56f_;
#else
                var44->unknown_38_.unknown1_56f_ = var47->unknown1_56f_;
                var44->unknown_38_.unknown_570_ = var47->unknown_570_;
#endif
                var44->unknown_38_.unknown_6f0_ = var47->unknown_6f0_;
                var44->unknown_38_.unknown_850_ = var47->unknown_850_;
                var44->unknown_38_.unknown_8ec_ = var47->unknown_8ec_;
                var44->unknown_38_.unknown_910_ = var47->unknown_910_;
                var44->unknown_38_.unknown_91c_ = var47->unknown_91c_;
                var44->unknown_38_.unknown_934_ = var47->unknown_934_;
                var44->unknown_38_.unknown_94c_ = var47->unknown_94c_;
                var44->unknown_38_.unknown_950_ = var47->unknown_950_;
                var44->unknown_38_.unknown_954_ = var47->unknown_954_;
                var44->unknown_38_.unknown_956_ = var47->unknown_956_;
                var44->unknown_38_.unknown_958_ = var47->unknown_958_;
                var44->unknown_38_.unknown_95a_ = var47->unknown_95a_;
                var44->unknown_38_.unknown_95c_ = var47->unknown_95c_;
                var44->unknown_38_.unknown_95e_ = var47->unknown_95e_;
                var44->unknown_38_.unknown_960_ = var47->unknown_960_;
                var44->unknown_38_.unknown_962_ = var47->unknown_962_;
                strcpy(var44->unknown_8_, var46->unknown_134_);
                var44++;
                _ZZ21inline_ov023_021f4c04vE1s.unknown_0_->unknown_2798_++;
            }
        }
    }
    _ZZ21inline_ov023_021f4c04vE1s.unknown_0_->unknown_279d_ = func_020114ec((char*)var5, _ZZ21inline_ov023_021f4c04vE1s.unknown_0_->unknown_2799_);

    if (arg0->unknown_2a0_->unknown_25_ == 0)
        _ZZ21inline_ov023_021f4c04vE1s.unknown_0_->unknown_10_ = func_ov023_021f5150(arg0, arg0->unknown_2a0_, arg0->unknown_5758_, &arg0->unknown_5768_, 0) ? 1 : 0;

    if (func_0202c540(var0) && arg0->unknown_2a0_->unknown_c_ == 0x13)
        func_020e39d4(func_020e3808(), 0, 1, 0x71e8);
    return 2;
}
