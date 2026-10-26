#include <globaldefs.h>
#include <GameState/GameState.h>
#include <std_library_functions.h>

struct Struct_ov000_0215767c_7 { short code; char pad[0x26]; };
struct Struct_ov000_0215767c_5;
struct Struct_ov000_0215767c_6 { char pad0[0x1c]; short index; char pad1[2]; short combatant; unsigned short hp; unsigned short mp; char pad2[0xa]; Struct_ov000_0215767c_6* next; };
struct Struct_ov000_0215767c_4 { char pad0[0xc]; short source; short target; char pad1[7]; unsigned char active; char pad2[8]; Struct_ov000_0215767c_4* next; };
struct Struct_ov000_021584e8 { char payload[0x20]; Struct_ov000_021584e8* next; };
struct Struct_ov000_0215a908 {
    char pad0[0x6060];
    Struct_ov000_0215767c_7 actions[20];
    Struct_ov000_0215767c_6 unknown_6380_[20];
    Struct_ov000_0215767c_4 targets[20];
    Struct_ov000_021584e8 entries[20];
    char pad1[0x20db];
    unsigned char unknown_8e0b_;
    unsigned char unknown_8e0c_;
    unsigned char unknown_8e0d_;
    unsigned char unknown_8e0e_;
};
struct Struct_ov000_0215a908_2 { char pad[0x2e]; short id; };
struct Struct_ov000_0215a908_3 { char pad[8]; short id; };
struct Struct_ov000_0215a908_4 { char pad0[0x144]; Struct_ov000_0215a908_3* resource; char pad1[0x39]; unsigned char active; unsigned char pending; };
struct S_10088;
struct ArrayContainsByteStruct;
extern "C" GameObject* func_0200fea4(GameState*, int);
extern "C" int func_ov000_02155154(GameObject*);
extern "C" int func_02010088(S_10088*);
extern "C" int func_ov000_02153c0c(GameObject*);
extern "C" void func_02088e64(unsigned char*);
extern "C" void func_ov000_02160030(void*);
extern "C" void func_ov000_02157cdc(void*);
extern "C" void func_ov000_0215ccbc(int, Struct_ov000_021584e8*, GameObject*, short, short, short, unsigned long long, unsigned char);
extern "C" void func_ov000_0215a88c(void*, void*, int);
extern "C" void func_ov000_0215ffc4(void*, void*, int);
extern "C" void func_ov000_02160068(Struct_ov000_0215767c_7*, Struct_ov000_0215767c_6*);
extern "C" void func_ov000_021600cc(Struct_ov000_0215767c_5*, Struct_ov000_0215767c_4*);
extern "C" int func_02086ef0(ArrayContainsByteStruct*, int);
extern "C" void func_ov000_0215a8d4(unsigned char*, int);
static inline short inline_ov000_0215a908(GameObject* combatant) { return ((Struct_ov000_0215a908_2*)combatant->currentStats_)->id; }
static inline short inline_ov000_0215a908_2(GameObject* combatant) { SDK_NULL_ASSERT(combatant); return combatant->currentStats_->primaryStats.currHP; }
static inline short inline_ov000_0215a908_3(GameObject* combatant) { SDK_NULL_ASSERT(combatant); return combatant->currentStats_->primaryStats.currMP; }
static inline Struct_ov000_0215767c_5* inline_ov000_0215a908_4(Struct_ov000_0215767c_7* action) { Struct_ov000_0215767c_5* value = (Struct_ov000_0215767c_5*)action; return value; }

// USA: func_ov000_0215a908
extern "C" ARM void func_ov000_0215a908(Struct_ov000_0215a908* events, int id) {
    if (events->unknown_8e0b_ >= 20 || events->unknown_8e0c_ >= 20 || events->unknown_8e0d_ >= 20 || events->unknown_8e0e_ >= 20) return;
    Struct_ov000_0215767c_6* var0;
    Struct_ov000_0215767c_4* target;
    GameObject* combatant = func_0200fea4(GameState::GetInstance(), id);
    if (!combatant || !func_ov000_02155154(combatant)) return;
    short source = inline_ov000_0215a908(combatant);
    GameObject* other = GameState::GetInstance()->GetCombatantByIndex(source);
    if (!other || func_02010088((S_10088*)other) || func_ov000_02153c0c(other)) {
        func_02088e64((unsigned char*)combatant->currentStats_);
        ((Struct_ov000_0215a908_4*)combatant)->pending = 0;
        return;
    }
    ((Struct_ov000_0215a908_4*)combatant)->active = 1;
    ((Struct_ov000_0215a908_4*)combatant)->pending = 0;
    Struct_ov000_0215767c_7* action = &events->actions[events->unknown_8e0b_];
    func_ov000_02160030(action);
    var0 = &events->unknown_6380_[events->unknown_8e0c_];
    memset(var0, 0, 0x30);
    var0->index = -1;
    var0->next = 0;
    target = &events->targets[events->unknown_8e0d_];
    func_ov000_02157cdc(target);
    Struct_ov000_021584e8* entry = &events->entries[events->unknown_8e0e_];
    memset(entry, 0, 0x20);
    entry->next = 0;
    action->code = 0x399;
    var0->combatant = id;
    var0->hp = combatant->currentStats_->primaryStats.currHP;
    var0->mp = combatant->currentStats_->primaryStats.currMP;
    func_ov000_0215ccbc((int)events, entry, combatant, 0, inline_ov000_0215a908_2(combatant), inline_ov000_0215a908_3(combatant), 0, 0);
    func_ov000_0215a88c(events, entry, 0x212);
    target->target = id;
    target->active = 1;
    target->source = ((Struct_ov000_0215a908_2*)combatant->currentStats_)->id;
    func_ov000_0215ffc4(target, entry, 0);
    func_ov000_02160068(action, var0);
    func_ov000_021600cc(inline_ov000_0215a908_4(action), target);
    Struct_ov000_0215a908_3* resource = ((Struct_ov000_0215a908_4*)combatant)->resource;
    if (func_02086ef0((ArrayContainsByteStruct*)GameState_GetParty(GameState::GetInstance()), target->source) && resource && resource->id == 0x143) func_ov000_0215a8d4((unsigned char*)events, 9);
    events->unknown_8e0b_++;
    events->unknown_8e0c_++;
    events->unknown_8e0d_++;
    events->unknown_8e0e_++;
}
