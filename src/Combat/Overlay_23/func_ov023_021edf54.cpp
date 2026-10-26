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
int func_ov023_021f5340(void* dispatch);
void* LinkSession_GetInstance();
int func_ov000_0215e9fc(World_021edf54* world, short* out, int max, unsigned int flags);
int func_ov000_0215ec1c(World_021edf54* world, short* out, int max, int flags);
int func_ov023_021f4098(Scene_021edf54* self, int id, int bonus);
void func_ov023_021f454c(Scene_021edf54* self);
void func_ov017_021cd218(unsigned short event, unsigned short value, unsigned short scaled, unsigned short bits, unsigned short kind, unsigned short id);
void func_ov017_021cd590(unsigned short event, int* experience, int a, int b);
void func_ov017_021cd35c(unsigned short event, char* drops, unsigned char count, signed char mask);
void _Z27EnqueueEventTag105_021cd4c8tta(unsigned short event, unsigned short item, signed char mask);
int LinkSession_IsGuest(void* mode);
int func_020abe84(void* unused, short* indices, Flags_021ed7e0* values, int count);
int func_ov023_021f5150(Scene_021edf54* self, BattleInfo_021edf54* info, int* experience, int* gold, int legacy);
}

Renderer_021edf54* MessageSystem_GetInstance();
void ClearSubstructFlag0x4_02049ae4(unsigned char* obj);
void SetFieldForListedCombatants021f50fc();
int LinkSession_IsActive(int* mode);
int LinkSession_GetOwnSlot(SearchStruct0202c1a4* mode);
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
unsigned short GameObject_GetPartyMemberLevel(void* obj);
int IsFlag10088Set_02010088(S_10088* obj);
int GetTableEntry138_021eea98(Obj021eea98* obj);
int GetFieldAt0x150_02053c6c(unsigned char* obj);
unsigned char GameState_GetPartyOrder(char* game, void* dst);
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
    mode = LinkSession_GetInstance();

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

    if (!LinkSession_IsActive((int*)mode) || self->info_->leader_ == LinkSession_GetOwnSlot((SearchStruct0202c1a4*)mode)) {
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
        if (resources->bossFlag_ != 0)
            SetCombatWorkFlags0x55f4_ov000_02160fa8(self, 0x2000000);
        if (LinkSession_IsGuest(mode) && self->info_->special_ != 0)
            renderer->active_ = 0;
        if (!GetCombatWorkFlags0x55f4_ov000_02160fd4(self, 0x2000))
            return self->endState_;
        if (!GetCombatWorkFlags0x55f4_ov000_02160fd4(self, 0x4000))
            return self->endState_;
        if (!GetCombatWorkFlags0x55f4_ov000_02160fd4(self, 0x8000))
            return self->endState_;
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

    Result_021edf54* result = _ZZ17GetGlobal021ffefcvE1s.work_->results_;
    for (int i = 0; i < 4; i++) {
        if (TestBitAt0x34_020a35e0((unsigned char*)self->info_, i)) {
            Combatant_021edf54* c = (Combatant_021edf54*)GetCombatantWithFlag0x100_0200ff1c(game, i);
            if (c != 0) {
                result->member_ = i;
                result->level_ = c->record_->level_;
                result->vocation_ = GameObject_GetPartyMemberLevel(c);
                result->flag_ = IsFlag10088Set_02010088((S_10088*)c);
                result->exp_ = self->experience_[i] + GetTableEntry138_021eea98((Obj021eea98*)c);
                Record_021edf54* src = (Record_021edf54*)GetFieldAt0x150_02053c6c((unsigned char*)c);
                result->record_.m000 = src->m000;
                result->record_.m018 = src->m018;
                result->record_.m03c = src->m03c;
                result->record_.m094 = src->m094;
                result->record_.m138 = src->m138;
                result->record_.m16c = src->m16c;
                result->record_.m186 = src->m186;
                result->record_.m194 = src->m194;
                result->record_.m2f4 = src->m2f4;
                result->record_.m454 = src->m454;
                result->record_.m464 = src->m464;
                result->record_.m480 = src->m480;
                result->record_.m488 = src->m488;
                result->record_.m4a4 = src->m4a4;
                result->record_.m564 = src->m564;
                result->record_.m566 = src->m566;
                result->record_.m568 = src->m568;
                result->record_.m56a = src->m56a;
                result->record_.m56b = src->m56b;
                result->record_.m56c = src->m56c;
                result->record_.m56d = src->m56d;
                result->record_.m56e = src->m56e;
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
    _ZZ17GetGlobal021ffefcvE1s.work_->regionResult_ = GameState_GetPartyOrder((char*)game, _ZZ17GetGlobal021ffefcvE1s.work_->region_);

    if (arg0->unknown_2a0_->unknown_25_ == 0)
        _ZZ21inline_ov023_021f4c04vE1s.unknown_0_->unknown_10_ = func_ov023_021f5150(arg0, arg0->unknown_2a0_, arg0->unknown_5758_, &arg0->unknown_5768_, 0) ? 1 : 0;

    if (LinkSession_IsGuest(mode) && self->info_->type_ == 0x13)
        SetEntryBitUnlessMatching020e39d4(GetData02153660_020e3808(), 0, 1, 0x71e8);
    return 2;
}
