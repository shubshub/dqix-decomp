#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

#if defined(jpn)
#define func_0205ec34 func_0205ff20
#endif

struct GameState {
    static GameState* GetInstance();
};
struct GameObject;
struct Struct_02048150;
struct Struct_02072a68_2 { char unknown_0_[4]; };
struct Struct_ov023_021d9988;
struct Struct_ov023_021f03a0 { unsigned char unknown_0_, unknown_1_, unknown_2_, unknown_3_; unsigned int unknown_4_; };
struct Struct_ov023_021f03a0_2 { char unknown_0_[0x11b]; unsigned char unknown_11b_; char unknown_11c_[2]; unsigned char unknown_11e_; char unknown_11f_; void* unknown_120_; };
struct Struct_ov023_021f0a5c_2 {
    unsigned int unknown_0_;
    unsigned short unknown_4_0_ : 7;
    unsigned short unknown_4_7_ : 9;
    char unknown_6_[0x14 - 6];
};
struct Struct_ov023_021f0a5c_3 { Struct_ov023_021f0a5c_2 unknown_0_, unknown_14_, unknown_28_, unknown_3c_; int unknown_50_; };
struct Struct_ov000_0215d63c_2 {
    char unknown_0_[0x138]; unsigned int unknown_138_[0xd];
    char unknown_16c_[0x16c - 0x16c]; unsigned short unknown1_16c_[0x1fc];
    unsigned short unknown_564_;
#if defined(jpn)
    char unknown_566_[0x8b8 - 0x566]; int unknown_950_;
#else
    char unknown1_566_[0x950 - 0x566]; int unknown_950_;
#endif
};
#if defined(jpn)
struct Struct_ov000_02160da0 {
    char unknown_0_[0x30]; SafeAllocator unknown_30_;
    char unknown_44_[0xe28 - 0x30 - sizeof(SafeAllocator)]; int unknown_eac_;
    char unknown_e2c_[0x371c - 0xe2c]; char unknown_3760_[0x5778 - 0x371c];
    Struct_ov023_021f03a0_2* unknown_5588_;
    char unknown_577c_[0x5960 - 0x577c]; Struct_ov023_021f0a5c_3 unknown_5770_[4];
    char unknown_5ab0_[0x5af4 - 0x5ab0]; Struct_02072a68_2 unknown_5904_;
};
#else
struct Struct_ov000_02160da0 {
    char unknown_0_[0x30]; SafeAllocator unknown_30_;
    char unknown_44_[0xeac - 0x30 - sizeof(SafeAllocator)]; int unknown_eac_;
    char unknown_eb0_[0x3760 - 0xeb0]; char unknown_3760_[0x5588 - 0x3760];
    Struct_ov023_021f03a0_2* unknown_5588_;
    char unknown_558c_[0x5770 - 0x558c]; Struct_ov023_021f0a5c_3 unknown_5770_[4];
    char unknown_58c0_[0x5904 - 0x58c0]; Struct_02072a68_2 unknown_5904_;
};
#endif
struct Struct_ov023_021f0a5c {
    int unknown_0_, unknown_4_; char unknown_8_[0x18 - 8]; int unknown_18_;
    unsigned char unknown_1c_[4][0x14];
    unsigned char unknown_6c_[4];
    char unknown_70_[0xe5 - 0x70]; signed char unknown_e5_;
    char unknown_e6_[0xf0 - 0xe6]; char unknown_f0_[0x118 - 0xf0];
#if defined(jpn)
    char unknown_118_[0x2498 - 0x118]; unsigned char unknown_2788_;
#else
    char unknown_118_[0x2788 - 0x118]; unsigned char unknown_2788_;
#endif
    char unknown_2789_[4]; unsigned char unknown_278d_;
};
#if defined(jpn)
struct Struct_02092e0c {
    char unknown_0_[0x10]; void* unknown_10_; char unknown_14_[0x868 - 0x14]; int unknown_868_;
    char unknown_86c_[0x17e2 - 0x86c]; unsigned char unknown_17e2_;
    char unknown_17e3_[0x17fb - 0x17e3]; unsigned char unknown_19ca_;
};
#else
struct Struct_02092e0c {
    char unknown_0_[0x10]; void* unknown_10_; char unknown_14_[0x998 - 0x14]; int unknown_998_;
    char unknown_99c_[0x19b2 - 0x99c]; unsigned char unknown_19b2_;
    char unknown_19b3_[0x19ca - 0x19b3]; unsigned char unknown_19ca_;
};
#endif

extern "C" Struct_ov023_021f0a5c* _ZZ21inline_ov023_021f4c04vE1s;
extern char data_02109bf4[];

MessageController* GetGlobalField0x1c020421a0();
extern "C" void func_02046380(MessageController*);
char* FindEntryByKey_02072a68(TableA68*, int);
void* GetPtrField0x2a04_02010828(GameState*);
int ArrayContainsByte_02086ef0(ArrayContainsByteStruct*, int);
struct Reset_021eefac;
void ResetFields_021eefac(Reset_021eefac*);
BattleResultEntry* FindByByteAt118_021f0360(void*, int);
extern "C" int func_02082490(LoadedEntry*, void*, unsigned int, unsigned char, unsigned int);
GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState*, int);
CombatStats* GetFieldAt0x150_02053c6c(unsigned char*);
extern "C" void PartyMember_ApplyLevelStats(CombatStats*, LevelStats*, LevelStats*);
extern "C" void func_02083e28(CombatStats*, int);
extern "C" unsigned char func_0209aa54(void*, GameObject*, unsigned char*, int);
struct Struct_ov023_021edf54;
extern "C" int func_ov023_021eea98(Struct_ov023_021edf54*);
extern "C" void func_ov023_021d8b6c(void*);
extern "C" void func_ov023_021d8af8(Struct_ov023_021f03a0_2*);
extern "C" void func_ov023_021d8a40(Struct_ov023_021f03a0_2*);
extern "C" void func_ov023_021d8cb4(void*, void*);
extern "C" void func_ov023_021d9988(Struct_ov023_021d9988*, void*, unsigned int);
extern "C" void func_ov023_021d8e4c(Struct_ov023_021f03a0_2*, int, Struct_ov023_021f0a5c_2*, Struct_ov023_021f0a5c_2*);
struct Struct_020465c0;
extern "C" void func_020465c0(Struct_020465c0*, int, int);
extern "C" void func_020e4bf4(void*, int);
#if defined(jpn)
extern "C" void func_0204500c(Struct_02092e0c*, char*, int);
#else
extern "C" void func_0204500c(Struct_02092e0c*, char*, int, int);
#endif
extern "C" void func_0209c6d8(void*, int);
extern "C" void func_ov017_021ce704(int);
extern "C" void func_ov017_021cc730(int, int, int, int);
extern "C" void func_ov017_021c9e00(int, int, int, int);
extern "C" int func_ov023_021f4fc8();
extern "C" int func_ov023_021f5228(int);
extern "C" void* func_0205ec34();
extern "C" int func_0206dfb0(int, unsigned char*, int);
extern "C" int func_0209ca2c(void*);

static inline int inline_ov023_021f0a5c(Struct_ov000_0215d63c_2* arg0) { return arg0->unknown1_16c_[arg0->unknown_950_]; }

// USA: func_ov023_021f0a5c
extern "C" ARM int func_ov023_021f0a5c(Struct_ov000_02160da0* arg0) {
    char var0[0x100];
    char var1[0x100];
    char var2[40];
    char var3[12];
    char var4[12];
    GameState* var5 = GameState::GetInstance();
    Struct_ov023_021f0a5c* var6 = _ZZ21inline_ov023_021f4c04vE1s;
    Struct_02092e0c* var7 = func_020421a0();
#if !defined(jpn)
    func_02046380(var7);
#endif
    BackgroundLoader* var8 = BackgroundLoader::GetInstance();
    char* var9 = func_02072a68(&arg0->unknown_5904_, 0x22);
    int var10 = func_02086ef0((Struct_02048150*)func_02010828(var5), var6->unknown_18_);
    if (var6->unknown_0_ == 0) {
        var6->unknown_18_++;
        if (var6->unknown_18_ >= 4) {
            func_ov023_021eefac((Struct_ov023_021eeaac_2*)var6);
            return 0xb;
        }
        Struct_ov023_021f03a0* var11 = func_ov023_021f0360(_ZZ21inline_ov023_021f4c04vE1s, var6->unknown_18_);
        if (!var11) return arg0->unknown_eac_;
        sprintf(var2, func_02072a68(&arg0->unknown_5904_, 0), var11->unknown_1_);
        var6->unknown_4_ = var8->QueueLoadFile(var2, 0);
        var6->unknown_0_++;
    } else if (var6->unknown_0_ == 1) {
        if (!var8->GetTaskStatus(var6->unknown_4_)) return arg0->unknown_eac_;
        unsigned int var12;
        void* var13;
        int var14 = var6->unknown_18_;
        var8->GetLoadedFileByID(var6->unknown_4_, &var13, &var12);
        var8->RemoveTask(var6->unknown_4_);
        int var15 = 0;
        Struct_ov023_021f03a0* var16 = func_ov023_021f0360(_ZZ21inline_ov023_021f4c04vE1s, var14);
        if (var13 && func_02082490(&arg0->unknown_5770_[var14], var13, var12, var16->unknown_2_, var16->unknown_4_)) {
            if (!var16->unknown_3_) var15 = 1;
        }
        LevelStats* extra = &work->loaded[id].extra;
        int type = entry->type;
        int level = type + extra->level;
        int retry = 0;
        if (learned) {
            if (inParty) {
                GameObject* actor = GetCombatantWithFlag0x100_0200ff1c(game, id);
                if (actor) {
                    CombatStats* stats = GetFieldAt0x150_02053c6c((unsigned char*)actor);
                    stats->levels[stats->index] = level;
                    unsigned short room = 0xa28 - stats->skillPoints;
                    if (room < extra->pct) extra->pct = room;
                    stats->skillPoints += extra->pct;
                    PartyMember_ApplyLevelStats(stats, &work->loaded[id].gained, &work->loaded[id].bonus);
                    func_02083e28(stats, 0);
                    state->learnedCount[id] = func_0209aa54(state->skillTable, actor, state->learned[id], type);
                }
            }
        } else {
            var6->unknown_0_ = 0;
            var20 = 1;
        }
        if (var10) {
            GameObject* var24 = func_0200ff1c(var5, var14);
            if (var24) {
                Struct_ov000_0215d63c_2* var25 = func_02053c6c((unsigned char*)var24);
                if (inline_ov023_021f0a5c(var25) >= 99) {
                    unsigned int var26 = arg0->unknown_5770_[var14].unknown_0_.unknown_0_;
                    if (var15) var26 = arg0->unknown_5770_[var14].unknown_14_.unknown_0_;
                    if (var26 != 0 && var26 <= func_ov023_021eea98((Struct_ov023_021edf54*)var24)) {
                        if (var25) var25->unknown_138_[var25->unknown_950_] = var26;
                        var16->unknown_4_ = var26;
                    }
                }
            }
        }
        if (var20) return arg0->unknown_eac_;
        var6->unknown_0_++;
    } else if (var6->unknown_0_ == 2) {
        if (arg0->unknown_5588_) {
            func_ov023_021d8b6c(arg0->unknown_5588_);
            func_ov023_021d8af8(arg0->unknown_5588_);
            arg0->unknown_5588_ = 0;
            return arg0->unknown_eac_;
        }
        arg0->unknown_30_.Reset();
        if (!var10) {
            var6->unknown_0_ = 4;
        } else {
            arg0->unknown_5588_ = (Struct_ov023_021f03a0_2*)arg0->unknown_30_.Allocate(0x12c);
            func_ov023_021d8a40(arg0->unknown_5588_);
            func_ov023_021d8cb4(arg0->unknown_5588_, arg0->unknown_3760_);
            Struct_ov023_021f0a5c* var27 = _ZZ21inline_ov023_021f4c04vE1s;
            unsigned char var28 = var27->unknown_2788_;
            Struct_ov023_021f03a0_2* var29 = arg0->unknown_5588_;
            var29->unknown_120_ = var27->unknown_118_;
            var29->unknown_11e_ = var28;
            func_ov023_021d9988((Struct_ov023_021d9988*)arg0->unknown_5588_, _ZZ21inline_ov023_021f4c04vE1s->unknown_2789_, _ZZ21inline_ov023_021f4c04vE1s->unknown_278d_);
            var6->unknown_0_++;
        }
    } else if (var6->unknown_0_ == 3) {
        if (arg0->unknown_5588_->unknown_11b_ == 0xff) var6->unknown_0_++;
    } else if (var6->unknown_0_ == 4) {
        int var30 = var6->unknown_18_;
        Struct_ov023_021f0a5c_2* var31;
        Struct_ov023_021f0a5c_2* var32;
        Struct_ov023_021f0a5c_2* var33;
        var33 = &arg0->unknown_5770_[var30].unknown_0_;
        var32 = &arg0->unknown_5770_[var30].unknown_28_;
        if (arg0->unknown_5588_) func_ov023_021d8e4c(arg0->unknown_5588_, var30, var33, var32);
#if defined(jpn)
        Struct_ov023_021f03a0* var34 = func_ov023_021f0360(_ZZ21inline_ov023_021f4c04vE1s, var30);
        if (var34) {
            var31 = &arg0->unknown_5770_[(unsigned int)var30].unknown_14_;
            char* var35 = (char*)(var34 + 1);
            if (var31->unknown_4_0_ - var33->unknown_4_0_ > 1) {
                sprintf(var0, func_02072a68(&arg0->unknown_5904_, 0x16), var35, var33->unknown_4_0_, var31->unknown_4_0_, var35);
            } else {
                sprintf(var0, func_02072a68(&arg0->unknown_5904_, 0xa), var35, var31->unknown_4_0_, var35);
            }
            strcat(var0, var9);
            func_0204500c(var7, var0, 1);
            var7->unknown_17e2_ = 0;
            var7->unknown_868_ = 1;
        }
#else
        if (func_ov023_021f0360(_ZZ21inline_ov023_021f4c04vE1s, var30)) {
            var31 = &arg0->unknown_5770_[(unsigned int)var30].unknown_14_;
            if (var31->unknown_4_0_ - var33->unknown_4_0_ > 1) {
                sprintf(var0, func_02072a68(&arg0->unknown_5904_, 0x16));
                func_020465c0((Struct_020465c0*)var7, 0, var33->unknown_4_0_);
                func_020465c0((Struct_020465c0*)var7, 1, var31->unknown_4_0_);
            } else {
                sprintf(var0, func_02072a68(&arg0->unknown_5904_, 0xa));
                func_020465c0((Struct_020465c0*)var7, 0, var31->unknown_4_0_);
            }
            strcat(var0, var9);
            func_020e4bf4(var3, var30);
            var7->unknown_10_ = var3;
            func_0204500c(var7, var0, 1, 0xe3);
            var7->unknown_19b2_ = 0;
            var7->unknown_998_ = 1;
        }
#endif
        if (var10) {
            func_0209c6d8(data_02109bf4, 0x35);
            func_ov017_021ce704(var30);
            func_ov017_021cc730(var30, 0, 0, 1);
            func_ov017_021c9e00(var30, 0, 0, 0);
            var6->unknown_0_++;
        } else {
            var6->unknown_0_ += 2;
        }
    } else if (var6->unknown_0_ == 5) {
        if (func_ov023_021f4fc8()) {
#if defined(jpn)
            Struct_ov023_021f03a0* var36 = func_ov023_021f0360(_ZZ21inline_ov023_021f4c04vE1s, var6->unknown_18_);
            if (var36) {
                sprintf(var1, func_02072a68(&arg0->unknown_5904_, 0x26), (char*)(var36 + 1));
                strcat(var1, var9);
                func_0204500c(var7, var1, 1);
                var7->unknown_17e2_ = 0;
                var7->unknown_868_ = 1;
            }
#else
            int var37 = var6->unknown_18_;
            if (func_ov023_021f0360(_ZZ21inline_ov023_021f4c04vE1s, var37)) {
                sprintf(var1, func_02072a68(&arg0->unknown_5904_, 0x26));
                strcat(var1, var9);
                func_020e4bf4(var4, var37);
                var7->unknown_10_ = var4;
                func_0204500c(var7, var1, 1, 0xe3);
                var7->unknown_19b2_ = 0;
                var7->unknown_998_ = 1;
            }
#endif
            var6->unknown_0_++;
        }
    } else if (var6->unknown_0_ == 6) {
        if (var10) {
            int var38 = var6->unknown_18_;
            Struct_ov023_021f0a5c_2* var39 = &arg0->unknown_5770_[var38].unknown_28_;
            unsigned short var40 = 0;
            GameObject* var41 = func_0200ff1c(var5, var38);
            if (var41) {
                Struct_ov000_0215d63c_2* var42 = func_02053c6c((unsigned char*)var41);
                if (var42) var40 = var42->unknown_564_;
            }
            func_02010828(var5);
            if (var6->unknown_6c_[var38]) {
                var6->unknown_e5_ = 10;
            } else if (var39->unknown_4_7_) {
                var6->unknown_e5_ = 12;
            } else if (var40 && func_ov023_021f5228(var38)) {
                var6->unknown_e5_ = 8;
                void* var43 = func_0205ec34();
                if (func_0206dfb0((int)var43, (unsigned char*)var43 + 0x8c, 0x119c)) var7->unknown_19ca_ = 0;
            }
        }
        var6->unknown_0_++;
    } else if (var6->unknown_0_ == 7) {
        if (func_0209ca2c(data_02109bf4)) return arg0->unknown_eac_;
        if (func_ov023_021f4fc8()) {
            signed char var44 = var6->unknown_e5_;
            func_ov023_021eefac((Struct_ov023_021eeaac_2*)var6);
            if (var44 >= 0) return var44;
        }
        return arg0->unknown_eac_;
    }
    return arg0->unknown_eac_;
}
