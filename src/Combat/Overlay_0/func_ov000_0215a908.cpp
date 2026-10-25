#include <globaldefs.h>
#include <GameState/GameState.h>
#include <std_library_functions.h>

struct Struct_ov000_0215767c_7 { short unknown_0_; char unknown_2_[0x26]; };
struct Struct_ov000_0215767c_5;
struct Struct_ov000_0215767c_6 { char unknown_0_[0x1c]; short unknown_1c_; char unknown_1e_[2]; short unknown_20_; unsigned short unknown_22_; unsigned short unknown_24_; char unknown_26_[0xa]; Struct_ov000_0215767c_6* unknown_30_; };
struct Struct_ov000_0215767c_4 { char unknown_0_[0xc]; short unknown_c_; short unknown_e_; char unknown_10_[7]; unsigned char unknown_17_; char unknown_18_[8]; Struct_ov000_0215767c_4* unknown_20_; };
struct Struct_ov000_021584e8 { char unknown_0_[0x20]; Struct_ov000_021584e8* unknown_20_; };
struct Struct_ov000_0215a908 {
    char unknown_0_[0x6060];
    Struct_ov000_0215767c_7 unknown_6060_[20];
    Struct_ov000_0215767c_6 unknown_6380_[20];
    Struct_ov000_0215767c_4 unknown_6790_[20];
    Struct_ov000_021584e8 unknown_6a60_[20];
    char unknown_6d30_[0x20db];
    unsigned char unknown_8e0b_;
    unsigned char unknown_8e0c_;
    unsigned char unknown_8e0d_;
    unsigned char unknown_8e0e_;
};
struct Struct_ov000_0215a908_2 { char unknown_0_[0x2e]; short unknown_2e_; };
struct Struct_ov000_0215a908_3 { char unknown_0_[8]; short unknown_8_; };
struct Struct_ov000_0215a908_4 { char unknown_0_[0x144]; Struct_ov000_0215a908_3* unknown_144_; char unknown_148_[0x39]; unsigned char unknown_181_; unsigned char unknown_182_; };
struct Struct_02010088;
struct Struct_02048150;
extern "C" GameObject* func_0200fea4(GameState*, int);
extern "C" int func_ov000_02155154(GameObject*);
extern "C" int func_02010088(Struct_02010088*);
extern "C" int func_ov000_02153c0c(GameObject*);
extern "C" void func_02088e64(unsigned char*);
extern "C" void func_ov000_02160030(void*);
extern "C" void func_ov000_02157cdc(void*);
extern "C" void func_ov000_0215ccbc(int, Struct_ov000_021584e8*, GameObject*, short, short, short, unsigned long long, unsigned char);
extern "C" void func_ov000_0215a88c(void*, void*, int);
extern "C" void func_ov000_0215ffc4(void*, void*, int);
extern "C" void func_ov000_02160068(Struct_ov000_0215767c_7*, Struct_ov000_0215767c_6*);
extern "C" void func_ov000_021600cc(Struct_ov000_0215767c_5*, Struct_ov000_0215767c_4*);
extern "C" int func_02086ef0(Struct_02048150*, int);
extern "C" void func_ov000_0215a8d4(unsigned char*, int);
static inline short inline_ov000_0215a908(GameObject* arg0) { return ((Struct_ov000_0215a908_2*)arg0->currentStats_)->unknown_2e_; }
static inline short inline_ov000_0215a908_2(GameObject* arg0) { SDK_NULL_ASSERT(arg0); return arg0->currentStats_->primaryStats.currHP; }
static inline short inline_ov000_0215a908_3(GameObject* arg0) { SDK_NULL_ASSERT(arg0); return arg0->currentStats_->primaryStats.currMP; }
static inline Struct_ov000_0215767c_5* inline_ov000_0215a908_4(Struct_ov000_0215767c_7* arg0) { Struct_ov000_0215767c_5* var0 = (Struct_ov000_0215767c_5*)arg0; return var0; }

// USA: func_ov000_0215a908
extern "C" ARM void func_ov000_0215a908(Struct_ov000_0215a908* arg0, int arg1) {
    if (arg0->unknown_8e0b_ >= 20 || arg0->unknown_8e0c_ >= 20 || arg0->unknown_8e0d_ >= 20 || arg0->unknown_8e0e_ >= 20) return;
    Struct_ov000_0215767c_6* var0;
    Struct_ov000_0215767c_4* var1;
    GameObject* var2 = func_0200fea4(GameState::GetInstance(), arg1);
    if (!var2 || !func_ov000_02155154(var2)) return;
    short var3 = inline_ov000_0215a908(var2);
    GameObject* var4 = GameState::GetInstance()->GetCombatantByIndex(var3);
    if (!var4 || func_02010088((Struct_02010088*)var4) || func_ov000_02153c0c(var4)) {
        func_02088e64((unsigned char*)var2->currentStats_);
        ((Struct_ov000_0215a908_4*)var2)->unknown_182_ = 0;
        return;
    }
    ((CombatantEventState*)combatant)->active = 1;
    ((CombatantEventState*)combatant)->pending = 0;
    Obj02160068* action = &events->actions[events->actionCount];
    InitStruct02160030(action);
    summary = &events->summaries[events->summaryCount];
    memset(summary, 0, 0x30);
    summary->index = -1;
    summary->next = 0;
    target = &events->targets[events->targetCount];
    ResetStruct02157cdc(target);
    OutStruct0215ccbc* entry = &events->entries[events->entryCount];
    memset(entry, 0, 0x20);
    entry->next = 0;
    action->code = 0x399;
    summary->combatant = id;
    summary->hp = combatant->currentStats_->primaryStats.currHP;
    summary->mp = combatant->currentStats_->primaryStats.currMP;
    PopulateEntry_0215ccbc((int)events, entry, combatant, 0, GetHP(combatant), GetMP(combatant), 0, 0);
    AddEntryAndIncrementCount0215a88c(events, entry, 0x212);
    target->target = id;
    target->active = 1;
    target->source = ((CombatSource*)combatant->currentStats_)->id;
    AppendToChainAndIncCount0215ffc4(target, entry, 0);
    AppendNode02160068(action, summary);
    AppendNode021600cc(AsTargetAction(action), target);
    ActionResource* resource = ((CombatantEventState*)combatant)->resource;
    if (ArrayContainsByte_02086ef0((ArrayContainsByteStruct*)GameState_GetParty(GameState::GetInstance()), target->source) && resource && resource->id == 0x143) IncrementByteCounterCapped0x63_0215a8d4((unsigned char*)events, 9);
    events->actionCount++;
    events->summaryCount++;
    events->targetCount++;
    events->entryCount++;
}
