#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"


struct GameState {
    static GameState* GetInstance();
};
struct GameObject;
struct ArrayContainsByteStruct;
struct TableA68 { char storage[4]; };
struct Struct_ov023_021d9988;
struct Struct_ov023_021f03a0 { unsigned char id, unknown_1_, type, flag; unsigned int experience; };
struct Struct_ov023_021f03a0_2 { char pad0[0x11b]; unsigned char state; char unknown_11c_[2]; unsigned char count; char unknown_11f_; void* entries; };
struct LevelStats {
    unsigned int unknown_0_;
    unsigned short level : 7;
    unsigned short unknown_4_7_ : 9;
    char pad6[0x14 - 6];
};
struct LoadedEntry { LevelStats base, gained, extra, bonus; int tail; };
struct CombatStats {
    char pad0[0x138]; unsigned int unknown_138_[0xd];
    char pad16c[0x16c - 0x16c]; unsigned short levels[0x1fc];
    unsigned short skillPoints;
#if defined(jpn)
    char unknown_566_[0x8b8 - 0x566]; int index;
#else
    char unknown1_566_[0x950 - 0x566]; int index;
#endif
};
#if defined(jpn)
struct Struct_ov000_02160da0 {
    char pad0[0x30]; SafeAllocator allocator;
    char unknown_44_[0xe28 - 0x30 - sizeof(SafeAllocator)]; int state;
    char unknown_e2c_[0x371c - 0xe2c]; char entry[0x5778 - 0x371c];
    Struct_ov023_021f03a0_2* result;
    char unknown_577c_[0x5960 - 0x577c]; LoadedEntry loaded[4];
    char unknown_5ab0_[0x5af4 - 0x5ab0]; TableA68 strings;
};
#else
struct Struct_ov000_02160da0 {
    char pad0[0x30]; SafeAllocator allocator;
    char unknown_44_[0xeac - 0x30 - sizeof(SafeAllocator)]; int state;
    char unknown_eb0_[0x3760 - 0xeb0]; char entry[0x5588 - 0x3760];
    Struct_ov023_021f03a0_2* result;
    char unknown_558c_[0x5770 - 0x558c]; LoadedEntry loaded[4];
    char unknown_58c0_[0x5904 - 0x58c0]; TableA68 strings;
};
#endif
struct Struct_ov023_021f0a5c {
    int state, task; char pad8[0x18 - 8]; int id;
    unsigned char unknown_1c_[4][0x14];
    unsigned char unknown_6c_[4];
    char unknown_70_[0xe5 - 0x70]; signed char outcome;
    char unknown_e6_[0xf0 - 0xe6]; char unknown_f0_[0x118 - 0xf0];
#if defined(jpn)
    char entries[0x2498 - 0x118]; unsigned char count;
#else
    char entries[0x2788 - 0x118]; unsigned char count;
#endif
    char unknown_2789_[4]; unsigned char unknown_278d_;
};
#if defined(jpn)
struct MessageController {
    char pad0[0x10]; void* actor; char unknown_14_[0x868 - 0x14]; int unknown_868_;
    char unknown_86c_[0x17e2 - 0x86c]; unsigned char unknown_17e2_;
    char unknown_17e3_[0x17fb - 0x17e3]; unsigned char field19ca;
};
#else
struct MessageController {
    char pad0[0x10]; void* actor; char unknown_14_[0x998 - 0x14]; int unknown_998_;
    char unknown_99c_[0x19b2 - 0x99c]; unsigned char unknown_19b2_;
    char unknown_19b3_[0x19ca - 0x19b3]; unsigned char field19ca;
};
#endif

extern "C" Struct_ov023_021f0a5c* _ZZ21inline_ov023_021f4c04vE1s;
extern char g_bgmPlayer[];

extern "C" MessageController* MessageSystem_GetInstance();
extern "C" void func_02046380(MessageController*);
extern "C" char* func_02072a68(TableA68*, int);
extern "C" void* GameState_GetParty(GameState*);
extern "C" int func_02086ef0(ArrayContainsByteStruct*, int);
struct Struct_ov023_021eeaac_2;
extern "C" void func_ov023_021eefac(Struct_ov023_021eeaac_2*);
extern "C" Struct_ov023_021f03a0* func_ov023_021f0360(void*, int);
extern "C" int ResourceScriptEntry_LoadLevel(LoadedEntry*, void*, unsigned int, unsigned char, unsigned int);
extern "C" GameObject* func_0200ff1c(GameState*, int);
extern "C" CombatStats* func_02053c6c(unsigned char*);
extern "C" void PartyMember_ApplyLevelStats(CombatStats*, LevelStats*, LevelStats*);
extern "C" void PartyMember_RecalculateStats(CombatStats*, int);
extern "C" unsigned char func_0209aa54(void*, GameObject*, unsigned char*, int);
struct Struct_ov023_021edf54;
extern "C" int func_ov023_021eea98(Struct_ov023_021edf54*);
extern "C" void func_ov023_021d8b6c(void*);
extern "C" void func_ov023_021d8af8(Struct_ov023_021f03a0_2*);
extern "C" void func_ov023_021d8a40(Struct_ov023_021f03a0_2*);
extern "C" void func_ov023_021d8cb4(void*, void*);
extern "C" void func_ov023_021d9988(Struct_ov023_021d9988*, void*, unsigned int);
extern "C" void func_ov023_021d8e4c(Struct_ov023_021f03a0_2*, int, LevelStats*, LevelStats*);
struct StoreStruct;
extern "C" void func_020465c0(StoreStruct*, int, int);
extern "C" void NameText_InitFromPartyMember(void*, int);
#if defined(jpn)
extern "C" void func_0204500c(MessageController*, char*, int);
#else
extern "C" void func_0204500c(MessageController*, char*, int, int);
#endif
extern "C" void func_0209c6d8(void*, int);
extern "C" void func_ov017_021ce704(int);
extern "C" void func_ov017_021cc730(int, int, int, int);
extern "C" void func_ov017_021c9e00(int, int, int, int);
extern "C" int func_ov023_021f4fc8();
extern "C" int func_ov023_021f5228(int);
extern "C" void* Scenario_GetInstance();
extern "C" int Scenario_TestFlag(int, unsigned char*, int);
extern "C" int func_0209ca2c(void*);

static inline int inline_ov023_021f0a5c(CombatStats* stats) { return stats->levels[stats->index]; }

// USA: func_ov023_021f0a5c
extern "C" ARM int func_ov023_021f0a5c(Struct_ov000_02160da0* work) {
    char text[0x100];
    char text2[0x100];
    char filename[40];
    char actorName[12];
    char actorName2[12];
    GameState* game = GameState::GetInstance();
    Struct_ov023_021f0a5c* state = _ZZ21inline_ov023_021f4c04vE1s;
    MessageController* messages = MessageSystem_GetInstance();
#if !defined(jpn)
    func_02046380(messages);
#endif
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    char* suffix = func_02072a68(&work->strings, 0x22);
    int inParty = func_02086ef0((ArrayContainsByteStruct*)GameState_GetParty(game), state->id);
    if (state->state == 0) {
        state->id++;
        if (state->id >= 4) {
            func_ov023_021eefac((Struct_ov023_021eeaac_2*)state);
            return 0xb;
        }
        Struct_ov023_021f03a0* entry = func_ov023_021f0360(_ZZ21inline_ov023_021f4c04vE1s, state->id);
        if (!entry) return work->state;
        sprintf(filename, func_02072a68(&work->strings, 0), entry->unknown_1_);
        state->task = loader->QueueLoadFile(filename, 0);
        state->state++;
    } else if (state->state == 1) {
        if (!loader->GetTaskStatus(state->task)) return work->state;
        unsigned int length;
        void* file;
        int id = state->id;
        loader->GetLoadedFileByID(state->task, &file, &length);
        loader->RemoveTask(state->task);
        int var15 = 0;
        Struct_ov023_021f03a0* entry = func_ov023_021f0360(_ZZ21inline_ov023_021f4c04vE1s, id);
        if (file && ResourceScriptEntry_LoadLevel(&work->loaded[id], file, length, entry->type, entry->experience)) {
            if (!entry->flag) var15 = 1;
        }
        LevelStats* extra = &work->loaded[id].extra;
        int type = entry->type;
        int level = type + extra->level;
        int var20 = 0;
        if (var15) {
            if (inParty) {
                GameObject* actor = func_0200ff1c(game, id);
                if (actor) {
                    CombatStats* stats = func_02053c6c((unsigned char*)actor);
                    stats->levels[stats->index] = level;
                    unsigned short var23 = 0xa28 - stats->skillPoints;
                    if (var23 < extra->unknown_4_7_) extra->unknown_4_7_ = var23;
                    stats->skillPoints += extra->unknown_4_7_;
                    PartyMember_ApplyLevelStats(stats, &work->loaded[id].gained, &work->loaded[id].bonus);
                    PartyMember_RecalculateStats(stats, 0);
                    state->unknown_6c_[id] = func_0209aa54(state->unknown_f0_, actor, state->unknown_1c_[id], type);
                }
            }
        } else {
            state->state = 0;
            var20 = 1;
        }
        if (inParty) {
            GameObject* actor = func_0200ff1c(game, id);
            if (actor) {
                CombatStats* stats = func_02053c6c((unsigned char*)actor);
                if (inline_ov023_021f0a5c(stats) >= 99) {
                    unsigned int var26 = work->loaded[id].base.unknown_0_;
                    if (var15) var26 = work->loaded[id].gained.unknown_0_;
                    if (var26 != 0 && var26 <= func_ov023_021eea98((Struct_ov023_021edf54*)actor)) {
                        if (stats) stats->unknown_138_[stats->index] = var26;
                        entry->experience = var26;
                    }
                }
            }
        }
        if (var20) return work->state;
        state->state++;
    } else if (state->state == 2) {
        if (work->result) {
            func_ov023_021d8b6c(work->result);
            func_ov023_021d8af8(work->result);
            work->result = 0;
            return work->state;
        }
        work->allocator.Reset();
        if (!inParty) {
            state->state = 4;
        } else {
            work->result = (Struct_ov023_021f03a0_2*)work->allocator.Allocate(0x12c);
            func_ov023_021d8a40(work->result);
            func_ov023_021d8cb4(work->result, work->entry);
            Struct_ov023_021f0a5c* global = _ZZ21inline_ov023_021f4c04vE1s;
            unsigned char var28 = global->count;
            Struct_ov023_021f03a0_2* result = work->result;
            result->entries = global->entries;
            result->count = var28;
            func_ov023_021d9988((Struct_ov023_021d9988*)work->result, _ZZ21inline_ov023_021f4c04vE1s->unknown_2789_, _ZZ21inline_ov023_021f4c04vE1s->unknown_278d_);
            state->state++;
        }
    } else if (state->state == 3) {
        if (work->result->state == 0xff) state->state++;
    } else if (state->state == 4) {
        int id = state->id;
        LevelStats* gained;
        LevelStats* extra;
        LevelStats* base;
        base = &work->loaded[id].base;
        extra = &work->loaded[id].extra;
        if (work->result) func_ov023_021d8e4c(work->result, id, base, extra);
#if defined(jpn)
        Struct_ov023_021f03a0* found = func_ov023_021f0360(_ZZ21inline_ov023_021f4c04vE1s, id);
        if (found) {
            gained = &work->loaded[(unsigned int)id].gained;
            char* name = (char*)(found + 1);
            if (gained->level - base->level > 1) {
                sprintf(text, func_02072a68(&work->strings, 0x16), name, base->level, gained->level, name);
            } else {
                sprintf(text, func_02072a68(&work->strings, 0xa), name, gained->level, name);
            }
            strcat(text, suffix);
            func_0204500c(messages, text, 1);
            messages->unknown_17e2_ = 0;
            messages->unknown_868_ = 1;
        }
#else
        if (func_ov023_021f0360(_ZZ21inline_ov023_021f4c04vE1s, id)) {
            gained = &work->loaded[(unsigned int)id].gained;
            if (gained->level - base->level > 1) {
                sprintf(text, func_02072a68(&work->strings, 0x16));
                func_020465c0((StoreStruct*)messages, 0, base->level);
                func_020465c0((StoreStruct*)messages, 1, gained->level);
            } else {
                sprintf(text, func_02072a68(&work->strings, 0xa));
                func_020465c0((StoreStruct*)messages, 0, gained->level);
            }
            strcat(text, suffix);
            NameText_InitFromPartyMember(actorName, id);
            messages->actor = actorName;
            func_0204500c(messages, text, 1, 0xe3);
            messages->unknown_19b2_ = 0;
            messages->unknown_998_ = 1;
        }
#endif
        if (inParty) {
            func_0209c6d8(g_bgmPlayer, 0x35);
            func_ov017_021ce704(id);
            func_ov017_021cc730(id, 0, 0, 1);
            func_ov017_021c9e00(id, 0, 0, 0);
            state->state++;
        } else {
            state->state += 2;
        }
    } else if (state->state == 5) {
        if (func_ov023_021f4fc8()) {
#if defined(jpn)
            Struct_ov023_021f03a0* found = func_ov023_021f0360(_ZZ21inline_ov023_021f4c04vE1s, state->id);
            if (found) {
                sprintf(text2, func_02072a68(&work->strings, 0x26), (char*)(found + 1));
                strcat(text2, suffix);
                func_0204500c(messages, text2, 1);
                messages->unknown_17e2_ = 0;
                messages->unknown_868_ = 1;
            }
#else
            int id = state->id;
            if (func_ov023_021f0360(_ZZ21inline_ov023_021f4c04vE1s, id)) {
                sprintf(text2, func_02072a68(&work->strings, 0x26));
                strcat(text2, suffix);
                NameText_InitFromPartyMember(actorName2, id);
                messages->actor = actorName2;
                func_0204500c(messages, text2, 1, 0xe3);
                messages->unknown_19b2_ = 0;
                messages->unknown_998_ = 1;
            }
#endif
            state->state++;
        }
    } else if (state->state == 6) {
        if (inParty) {
            int id = state->id;
            LevelStats* extra = &work->loaded[id].extra;
            unsigned short points = 0;
            GameObject* actor = func_0200ff1c(game, id);
            if (actor) {
                CombatStats* stats = func_02053c6c((unsigned char*)actor);
                if (stats) points = stats->skillPoints;
            }
            GameState_GetParty(game);
            if (state->unknown_6c_[id]) {
                state->outcome = 10;
            } else if (extra->unknown_4_7_) {
                state->outcome = 12;
            } else if (points && func_ov023_021f5228(id)) {
                state->outcome = 8;
                void* base = Scenario_GetInstance();
                if (Scenario_TestFlag((int)base, (unsigned char*)base + 0x8c, 0x119c)) messages->field19ca = 0;
            }
        }
        state->state++;
    } else if (state->state == 7) {
        if (func_0209ca2c(g_bgmPlayer)) return work->state;
        if (func_ov023_021f4fc8()) {
            signed char outcome = state->outcome;
            func_ov023_021eefac((Struct_ov023_021eeaac_2*)state);
            if (outcome >= 0) return outcome;
        }
        return work->state;
    }
    return work->state;
}
