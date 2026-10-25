#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"


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

extern "C" ResultState* _ZZ17GetGlobal021ffefcvE1s;
extern char g_bgmPlayer[];

MessageController* MessageSystem_GetInstance();
extern "C" void func_02046380(MessageController*);
char* FindEntryByKey_02072a68(TableA68*, int);
void* GameState_GetParty(GameState*);
int ArrayContainsByte_02086ef0(ArrayContainsByteStruct*, int);
struct Reset_021eefac;
void ResetFields_021eefac(Reset_021eefac*);
BattleResultEntry* FindByByteAt118_021f0360(void*, int);
extern "C" int ResourceScriptEntry_LoadLevel(LoadedEntry*, void*, unsigned int, unsigned char, unsigned int);
GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState*, int);
CombatStats* GetFieldAt0x150_02053c6c(unsigned char*);
extern "C" void PartyMember_ApplyLevelStats(CombatStats*, LevelStats*, LevelStats*);
extern "C" void PartyMember_RecalculateStats(CombatStats*, int);
extern "C" unsigned char func_0209aa54(void*, GameObject*, unsigned char*, int);
struct Obj021eea98;
int GetTableEntry138_021eea98(Obj021eea98*);
void InitCombatEntry_021d8b6c(void*);
extern "C" void func_ov023_021d8af8(BattleEntry*);
extern "C" void func_ov023_021d8a40(BattleEntry*);
void CopyEntryFields_021d8cb4(void*, void*);
void CopyAndStoreLen_021d9988(Obj021d9988*, void*, unsigned int);
extern "C" void func_ov023_021d8e4c(BattleEntry*, int, LevelStats*, LevelStats*);
struct StoreStruct;
void StoreInArray0x8b0_020465c0(StoreStruct*, int, int);
void NameText_InitFromPartyMember(void*, int);
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
int CheckThresholdOverAny_021f5228(int);
extern "C" void* Scenario_GetInstance();
int Scenario_TestFlag(int, unsigned char*, int);
int IsAnimationActive0209ca2c(void*);

static inline int inline_ov023_021f0a5c(Struct_ov000_0215d63c_2* arg0) { return arg0->unknown1_16c_[arg0->unknown_950_]; }

// USA: func_ov023_021f0a5c
extern "C" ARM int func_ov023_021f0a5c(BattleWork* work) {
    char text[0x100];
    char text2[0x100];
    char filename[40];
    char actorName[12];
    char actorName2[12];
    GameState* game = GameState::GetInstance();
    ResultState* state = _ZZ17GetGlobal021ffefcvE1s;
    MessageController* messages = MessageSystem_GetInstance();
#if !defined(jpn)
    func_02046380(var7);
#endif
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    char* suffix = FindEntryByKey_02072a68(&work->strings, 0x22);
    int inParty = ArrayContainsByte_02086ef0((ArrayContainsByteStruct*)GameState_GetParty(game), state->id);
    if (state->state == 0) {
        state->id++;
        if (state->id >= 4) {
            ResetFields_021eefac((Reset_021eefac*)state);
            return 0xb;
        }
        BattleResultEntry* entry = FindByByteAt118_021f0360(_ZZ17GetGlobal021ffefcvE1s, state->id);
        if (!entry) return work->state;
        sprintf(filename, FindEntryByKey_02072a68(&work->strings, 0), entry->fileId);
        state->task = loader->QueueLoadFile(filename, 0);
        state->state++;
    } else if (state->state == 1) {
        if (!loader->GetTaskStatus(state->task)) return work->state;
        unsigned int length;
        void* file;
        int id = state->id;
        loader->GetLoadedFileByID(state->task, &file, &length);
        loader->RemoveTask(state->task);
        int learned = 0;
        BattleResultEntry* entry = FindByByteAt118_021f0360(_ZZ17GetGlobal021ffefcvE1s, id);
        if (file && ResourceScriptEntry_LoadLevel(&work->loaded[id], file, length, entry->type, entry->experience)) {
            if (!entry->flag) learned = 1;
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
                    PartyMember_RecalculateStats(stats, 0);
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
            strcat(text, suffix);
            NameText_InitFromPartyMember(actorName, id);
            messages->actor = actorName;
            func_0204500c(messages, text, 1, 0xe3);
            messages->field19b2 = 0;
            messages->field998 = 1;
        }
#endif
        if (inParty) {
            ResetAndDispatchActorContext0209c6d8(g_bgmPlayer, 0x35);
            func_ov017_021ce704(id);
            func_ov017_021cc730(id, 0, 0, 1);
            func_ov017_021c9e00(id, 0, 0, 0);
            state->state++;
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
            int id = state->id;
            if (FindByByteAt118_021f0360(_ZZ17GetGlobal021ffefcvE1s, id)) {
                sprintf(text2, FindEntryByKey_02072a68(&work->strings, 0x26));
                strcat(text2, suffix);
                NameText_InitFromPartyMember(actorName2, id);
                messages->actor = actorName2;
                func_0204500c(messages, text2, 1, 0xe3);
                messages->field19b2 = 0;
                messages->field998 = 1;
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
            GameState_GetParty(game);
            if (state->learnedCount[id]) {
                state->outcome = 10;
            } else if (extra->pct) {
                state->outcome = 12;
            } else if (points && CheckThresholdOverAny_021f5228(id)) {
                state->outcome = 8;
                void* base = Scenario_GetInstance();
                if (Scenario_TestFlag((int)base, (unsigned char*)base + 0x8c, 0x119c)) messages->field19ca = 0;
            }
        }
        state->state++;
    } else if (state->state == 7) {
        if (IsAnimationActive0209ca2c(g_bgmPlayer)) return work->state;
        if (func_ov023_021f4fc8()) {
            signed char var44 = var6->unknown_e5_;
            func_ov023_021eefac((Struct_ov023_021eeaac_2*)var6);
            if (var44 >= 0) return var44;
        }
        return arg0->unknown_eac_;
    }
    return arg0->unknown_eac_;
}
