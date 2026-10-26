#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"
#include "Resource/Brightness.h"
struct ObjectStatePrefix;

struct ArrayContainsByteStruct;
struct Struct_ov000_02163a7c;
struct S_10088;
struct Bytes02033b88;
struct Entry_0205d6a0 { char storage[4]; };
struct Struct_ov023_021d9988;
struct TableA68 { char storage[4]; };
struct Struct_ov023_021eeaac_2 {
    int state, task; char pad8[9]; signed char member;
    unsigned char loaded[4]; char pad16[2]; int actorId;
#if defined(jpn)
    char unknown_1c_[0x118-0x1c]; char entries[0x2498-0x118]; unsigned char count;
#else
    char unknown1_1c_[0x118-0x1c]; char entries[0x2788-0x118]; unsigned char count;
#endif

    char unknown_2789_[4]; unsigned char unknown_278d_;
};
struct Struct_ov023_021f03a0 { unsigned char id, unknown_1_, type, flag; int experience; };
struct BattleInfo { char pad0[0x25]; unsigned char unknown_25_; };
struct Struct_ov023_021f03a0_2 { char pad0[0x11b]; unsigned char state; char unknown_11c_[2]; unsigned char count; char unknown_11f_; void* entries; };
struct LoadedEntry { char storage[0x54]; };
struct Struct_ov000_02160da0 {
    char pad0[0x30]; SafeAllocator allocator;
#if defined(jpn)
    char unknown_44_[0x218-0x30-sizeof(SafeAllocator)]; void* battle; BattleInfo* info;
#else
    char unknown1_44_[0x29c-0x30-sizeof(SafeAllocator)]; void* battle; BattleInfo* info;
#endif

#if defined(jpn)
    char unknown_220_[0xb94-0x220]; char unknown_c18_[4]; char unknown_b98_[0xe28-0xb98]; int state;
#else
    char unknown_2a4_[0xc18-0x2a4]; char unknown_c18_[4]; char unknown_c1c_[0xeac-0xc1c]; int state;
#endif

#if defined(jpn)
    char unknown_e2c_[0x371c-0xe2c]; char entry[0x38a4-0x371c]; Entry_0205d6a0 entries;
#else
    char unknown_eb0_[0x3760-0xeb0]; char entry[0x38e8-0x3760]; Entry_0205d6a0 entries;
#endif

#if defined(jpn)
    char unknown_38a8_[0x5778-0x38a8]; Struct_ov023_021f03a0_2* result;
#else
    char unknown_38ec_[0x5588-0x38ec]; Struct_ov023_021f03a0_2* result;
#endif

#if defined(jpn)
    char unknown_577c_[0x5948-0x577c]; int experience[4]; int unknown_5768_; unsigned char unknown_576c_;
#else
    char unknown_558c_[0x5758-0x558c]; int experience[4]; int unknown_5768_; unsigned char unknown_576c_;
#endif

#if defined(jpn)
    char unknown_595d_[3]; LoadedEntry loaded[4]; char unknown_5ab0_[0x5af4-0x5ab0]; TableA68 strings;
#else
    char unknown_576d_[3]; LoadedEntry loaded[4]; char unknown_58c0_[0x5904-0x58c0]; TableA68 strings;
#endif

};
struct MessageController {
#if defined(jpn)
    char pad0[0x10]; void* actor; char unknown_14_[0x868-0x14]; int unknown_998_;
#else
    char pad0[0x10]; void* actor; char unknown1_14_[0x998-0x14]; int unknown_998_;
#endif

#if defined(jpn)
    char unknown_86c_[0x17de - 0x86c]; unsigned char unknown_19ae_, unknown_19af_;
#else
    char unknown_99c_[0x19ae - 0x99c]; unsigned char unknown_19ae_, unknown_19af_;
#endif

#if defined(jpn)
    char unknown_17e0_[2]; unsigned char unknown_19b2_; char unknown_17e3_[0x17fb-0x17e3]; unsigned char field19ca;
#else
    char unknown_19b0_[2]; unsigned char unknown_19b2_; char unknown_19b3_[0x19ca-0x19b3]; unsigned char field19ca;
#endif

};
struct Struct_020391ac { char pad0[0xc1]; unsigned char unknown_c1_; unsigned char low : 4; unsigned char visible : 1; unsigned char high : 3; };
extern "C" Struct_ov023_021eeaac_2* _ZZ21inline_ov023_021f4c04vE1s;
extern "C" MessageController* MessageSystem_GetInstance();
extern "C" void* LinkSession_GetInstance();
extern "C" int func_02086ef0(ArrayContainsByteStruct*, int);
extern "C" void func_ov023_021ed988(char*, int);
extern "C" void func_ov000_02163b90(Struct_ov000_02160da0*, int);
extern "C" void func_ov000_021626a0(Struct_ov000_02160da0*, int, int);
extern "C" void func_ov000_02163a7c(Struct_ov000_02163a7c*);
extern "C" void func_ov000_021639b4(Struct_ov000_02160da0*);
extern "C" void func_ov000_02167dd8(unsigned char*);
extern "C" int func_ov000_02153e40(void*, short*, int, int);
extern "C" void func_02048cf0(GameObject*, int);
extern "C" void func_ov000_0216e3c4(void*);
extern "C" unsigned char* func_ov000_02163524(void*);
extern "C" int func_020a35e0(unsigned char*, unsigned char);
extern "C" void func_020d7334(unsigned char*, int);
extern "C" int func_02010088(S_10088*);
extern "C" void GameObject_ForceMotionState(Bytes02033b88*, int);
extern "C" void GameObject_UnfreezeAnimation(ObjectStatePrefix*);
extern "C" GameObject* func_0200fea4(GameState*, int);
extern "C" GameObject* func_0200ff1c(GameState*, int);
extern "C" GameObject* func_0200ff58(GameState*, int);
extern "C" void Window_ClosePane(Entry_0205d6a0*, int);
extern "C" void func_ov000_02160fa8(void*, int);
extern "C" void func_ov023_021d8a40(Struct_ov023_021f03a0_2*);
extern "C" void func_ov023_021d8cb4(void*, void*);
extern "C" void func_ov023_021d9988(Struct_ov023_021d9988*, void*, unsigned int);
extern "C" void func_02046380(MessageController*);
extern "C" void func_ov023_021d8ddc(Struct_ov023_021f03a0_2*, int*);
extern "C" int GameState_GetPartyOrderEntry(void*, unsigned int);
extern "C" void NameText_InitFromPartyMember(void*, int);
extern "C" char* func_02072a68(TableA68*, int);
#if !defined(jpn)
extern "C" void func_0204500c(MessageController*, char*, int, int);
#endif
extern "C" Struct_ov023_021f03a0* func_ov023_021f0360(void*, int);
extern "C" int ResourceScriptEntry_LoadLevel(LoadedEntry*, void*, unsigned int, unsigned char, int);
extern "C" int func_ov023_021f4438(Struct_ov000_02160da0*);
extern "C" int func_ov023_021f4fc8();
extern "C" void func_ov023_021eefac(Struct_ov023_021eeaac_2*);

#if defined(jpn)
extern "C" void func_0204500c(MessageController*,char*,int);
#endif
// USA: func_ov023_021f03a0
extern "C" ARM int func_ov023_021f03a0(Struct_ov000_02160da0* work) {
    int i;
    char text[256];
#if defined(jpn)

#else
    char actorName[12];
#endif

    char filename[40];
    short ids[12];
    GameState* game = GameState::GetInstance();
    Struct_ov023_021eeaac_2* state = _ZZ21inline_ov023_021f4c04vE1s;
    MessageController* messages = MessageSystem_GetInstance();
    LinkSession_GetInstance();
    GameResources* resources = GetGameResources();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    func_02086ef0((ArrayContainsByteStruct*)GameState_GetParty(game), state->actorId);
    if (state->state == 0) {
        if (work->unknown_576c_) func_ov023_021ed988((char*)work, 0);
        func_ov000_02163b90(work, 1);
        func_ov000_021626a0(work, 4, 0);
        func_ov000_02163a7c((Struct_ov000_02163a7c*)work);
        func_ov000_021639b4(work);
        ClearFlags04(resources, 0x400);
        func_ov000_02167dd8((unsigned char*)work);
        void* battle = work->battle;
        int count;
        GameState* var12 = GameState::GetInstance();
        count = func_ov000_02153e40(battle, ids, 12, 0);
        for (i = 0; i < count; i++) {
            GameObject* actor = var12->GetCombatantByIndex(ids[i]);
            if (actor) func_02048cf0(actor, 0);
        }
        func_ov000_0216e3c4(work->unknown_c18_);
        unsigned char* field = func_ov000_02163524(work);
        GameState* var15 = GameState::GetInstance();
        for (int i = 0; i < 4; i++) {
            if (func_020a35e0((unsigned char*)work->info, i)) {
                if (field) func_020d7334(field, i);
                GameObject* actor = var15->GetCombatantByIndex(i);
                if (actor && !func_02010088((S_10088*)actor)) {
                    ((Struct_020391ac*)actor)->unknown_c1_ &= ~0xf0;
                    GameObject_ForceMotionState((Bytes02033b88*)actor, 0);
                    actor->obj3D_.SkipAnimationTransition();
                    GameObject_UnfreezeAnimation((ObjectStatePrefix*)actor);
                    actor->obj3D_.MakeVisible();
                }
            }
        }
        for (int i = 0; i < 8; i++) {
            GameObject* actor = func_0200fea4(var15, i + 0xc0);
            if (actor && ((Struct_020391ac*)actor)->visible) actor->obj3D_.MakeVisible();
        }
        Window_ClosePane(&work->entries, 1);
        func_ov000_02160fa8(work, 0x40000);
        work->allocator.Reset();
        work->result = (Struct_ov023_021f03a0_2*)work->allocator.Allocate(0x12c);
        func_ov023_021d8a40(work->result);
        func_ov023_021d8cb4(work->result, work->entry);
        Struct_ov023_021eeaac_2* global = _ZZ21inline_ov023_021f4c04vE1s;
        unsigned char var21 = global->count;
        Struct_ov023_021f03a0_2* result = work->result;
        result->entries = global->entries;
        result->count = var21;
        func_ov023_021d9988((Struct_ov023_021d9988*)work->result, _ZZ21inline_ov023_021f4c04vE1s->unknown_2789_, _ZZ21inline_ov023_021f4c04vE1s->unknown_278d_);
        state->state++;
    } else if (state->state == 1) {
        if (work->result->state != 0xff) goto done;
#if defined(jpn)

#else
        func_02046380(messages);
#endif

        func_ov023_021d8ddc(work->result, work->experience);
        BaseCombatStats* stats = 0;
        if (work->info->unknown_25_) {
            for (int i = 0; i < 4 && !stats; i++) {
                int id = GameState_GetPartyOrderEntry(game, (unsigned char)i);
                if (work->experience[id]) {
                    GameObject* actor = func_0200ff1c(game, id);
#if defined(jpn)

#else
#if defined(jpn)

#else
                    NameText_InitFromPartyMember(actorName, id);
#endif

#endif

                    stats = actor->baseStats_;
                }
            }
        } else {
            for (int i = 0; i < 4; i++) {
                int id = GameState_GetPartyOrderEntry(game, (unsigned char)i);
                GameObject* actor = func_0200ff1c(game, id);
                if (actor && func_020a35e0((unsigned char*)work->info, id) && !func_02010088((S_10088*)actor)) {
#if defined(jpn)

#else
#if defined(jpn)

#else
                    NameText_InitFromPartyMember(actorName, id);
#endif

#endif

                    stats = actor->baseStats_;
                    break;
                }
            }
        }
        int count = 0;
        for (int i = 0; i < 4; i++) if (work->experience[i]) count++;
        if (!stats) {
            for (int i = 0; i < 4; i++) {
#if defined(jpn)
                GameObject* actor = func_0200ff1c(game, i);
                if (actor && func_020a35e0((unsigned char*)work->info, i) && !func_0200ff58(game, i))
                    stats = actor->baseStats_;
#else
                if (func_0200ff1c(game, i) && func_020a35e0((unsigned char*)work->info, i) && !func_0200ff58(game, i))
                    NameText_InitFromPartyMember(actorName, i);
#endif

            }
        }
#if defined(jpn)
        if (count > 1) sprintf(text, func_02072a68(&work->strings, 0x1a), stats);
        else sprintf(text, func_02072a68(&work->strings, 0x19), stats);
#else
        messages->actor = actorName;
        int messageId = 0x19;
        if (count > 1) messageId = 0x1a;
        sprintf(text, func_02072a68(&work->strings, messageId));
#endif

        strcat(text, func_02072a68(&work->strings, 0x22));
#if defined(jpn)
        func_0204500c(messages, text, 1);
#else
        func_0204500c(messages, text, 1, 0xe3);
#endif

        messages->unknown_19b2_ = 0;
        messages->unknown_998_ = 1;
        state->state++;
    } else if (state->state == 2) {
        Struct_ov023_021f03a0* entry = func_ov023_021f0360(_ZZ21inline_ov023_021f4c04vE1s, state->member);
        if (!entry) {
            state->member++;
            if (state->member >= 4) state->state = 4;
            return work->state;
        }
        sprintf(filename, func_02072a68(&work->strings, 0), entry->unknown_1_);
        state->task = loader->QueueLoadFile(filename, 0);
        state->state++;
    } else if (state->state == 3) {
        if (!loader->GetTaskStatus(state->task)) return work->state;
        unsigned int length;
        void* file;
        int member = state->member;
        loader->GetLoadedFileByID(state->task, &file, &length);
        loader->RemoveTask(state->task);
        Struct_ov023_021f03a0* entry = func_ov023_021f0360(_ZZ21inline_ov023_021f4c04vE1s, member);
        if (file && ResourceScriptEntry_LoadLevel(&work->loaded[member], file, length, entry->type, entry->experience)) {
            if (!entry->flag) state->loaded[member] = 1;
        }
        state->member++;
        if (state->member < 4) {
            state->state = 2;
            return work->state;
        }
        state->state++;
    } else if (state->state == 4) {
        int loaded = 0;
        for (int i = 0; i < 4; i++) if (state->loaded[i]) { loaded = 1; break; }
        int pending = func_ov023_021f4438(work);
        if (!loaded && !pending && !work->unknown_5768_) {
            messages->unknown_19ae_ = 0;
            messages->field19ca = 0;
            messages->unknown_19af_ = 0;
        }
        if (func_ov023_021f4fc8()) {
            func_ov023_021eefac(state);
            return 7;
        }
    }
done:
    return work->state;
}
