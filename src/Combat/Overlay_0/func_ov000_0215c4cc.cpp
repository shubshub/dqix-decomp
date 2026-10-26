#include <globaldefs.h>
#include <GameState/GameState.h>
#include <std_library_functions.h>

struct Struct_ov000_0215767c_7 { short code; char pad[0x26]; };
struct Struct_ov000_0215767c_5;
struct Struct_ov000_0215767c_6 { char pad0[0x1c]; short index; char pad1[2]; short combatant; unsigned short hp; unsigned short mp; char pad2[0xa]; Struct_ov000_0215767c_6* next; };
struct Struct_ov000_0215767c_4 { char pad0[0xe]; short combatant; char pad1[7]; unsigned char active; char pad2[8]; Struct_ov000_0215767c_4* next; };
struct Struct_ov000_021584e8 { char payload[0x20]; Struct_ov000_021584e8* next; };
struct Struct_ov000_0215a908 { char pad0[0x8e00]; unsigned char unknown_8e00_; unsigned char unknown_8e01_; unsigned char unknown_8e02_; char pad1[0x21]; int unknown_8e24_; };
struct Struct_ov000_0215a908_2 { char pad[0x2e]; short id; };
struct S_10088;
extern "C" int func_ov000_0215eb1c(Struct_ov000_0215a908*, short*, int, int);
extern "C" GameObject* func_0200fea4(GameState*, int);
extern "C" int func_ov000_02155154(GameObject*);
extern "C" int func_02010088(S_10088*);
extern "C" int func_ov000_02153c0c(GameObject*);
extern "C" void func_020488cc(unsigned char*, int);
extern "C" void func_02088e64(unsigned char*);
extern "C" void* func_ov000_0215e9d8(void*);
extern "C" void func_ov000_02160030(void*);
extern "C" void* func_ov000_0215e918(void*);
extern "C" void* func_ov000_0215e938(void*);
extern "C" void func_ov000_02157cdc(void*);
extern "C" Struct_ov000_021584e8* func_ov000_0215e958(Struct_ov000_0215a908*);
extern "C" void func_ov000_0215ccbc(int, Struct_ov000_021584e8*, GameObject*, short, short, short, unsigned long long, unsigned char);
extern "C" void func_ov000_0215a88c(void*, void*, int);
extern "C" void func_ov000_0215ffc4(void*, void*, int);
extern "C" void func_ov000_02160068(Struct_ov000_0215767c_7*, Struct_ov000_0215767c_6*);
extern "C" void func_ov000_021600cc(Struct_ov000_0215767c_5*, Struct_ov000_0215767c_4*);
extern short data_ov000_02182c24[8];
static inline short inline_ov000_0215a908(GameObject* combatant) { SDK_NULL_ASSERT(combatant); return ((Struct_ov000_0215a908_2*)combatant->currentStats_)->id; }
static inline short inline_ov000_0215a908_2(GameObject* combatant) { SDK_NULL_ASSERT(combatant); return combatant->currentStats_->primaryStats.currHP; }
static inline short inline_ov000_0215a908_3(GameObject* combatant) { SDK_NULL_ASSERT(combatant); return combatant->currentStats_->primaryStats.currMP; }
static inline short inline_ov000_0215c4cc(short* arg0, int index) { SDK_NULL_ASSERT(arg0); return arg0[index]; }

// USA: func_ov000_0215c4cc
extern "C" ARM void func_ov000_0215c4cc(Struct_ov000_0215a908* events) {
    short var0[8];
    unsigned short* source = (unsigned short*)data_ov000_02182c24;
    int var2 = 8;
    unsigned short* destination = (unsigned short*)var0;
    do { *destination = *source++; destination++; } while (--var2);
    int count = func_ov000_0215eb1c(events, var0, 8, 1);
    for (int i = 0; i < count; i++) {
        short combatantId = inline_ov000_0215c4cc(var0, i);
        GameObject* combatant = func_0200fea4(GameState::GetInstance(), combatantId);
        if (!combatant || !func_ov000_02155154(combatant)) continue;
        short var8 = inline_ov000_0215a908(combatant);
        GameObject* other = GameState::GetInstance()->GetCombatantByIndex(var8);
        if (other && !func_02010088((S_10088*)other) && !func_ov000_02153c0c(other)) continue;
        func_020488cc((unsigned char*)combatant, 1);
        func_02088e64((unsigned char*)combatant->currentStats_);
        Struct_ov000_0215767c_7* action = (Struct_ov000_0215767c_7*)func_ov000_0215e9d8(events);
        if (!action) continue;
        func_ov000_02160030(action);
        Struct_ov000_0215767c_6* var11 = (Struct_ov000_0215767c_6*)func_ov000_0215e918(events);
        if (!var11) continue;
        memset(var11, 0, 0x30);
        var11->index = -1;
        var11->next = 0;
        Struct_ov000_0215767c_4* target = (Struct_ov000_0215767c_4*)func_ov000_0215e938(events);
        if (!target) continue;
        func_ov000_02157cdc(target);
        Struct_ov000_021584e8* entry = func_ov000_0215e958(events);
        if (!entry) continue;
        memset(entry, 0, 0x20);
        entry->next = 0;
        action->code = 0x3ab;
        var11->combatant = var0[i];
        var11->hp = combatant->currentStats_->primaryStats.currHP;
        var11->mp = combatant->currentStats_->primaryStats.currMP;
        func_ov000_0215ccbc((int)events, entry, combatant, 0, inline_ov000_0215a908_2(combatant), inline_ov000_0215a908_3(combatant), 0, 0);
        func_ov000_0215a88c(events, entry, 0x164);
        target->combatant = var0[i];
        target->active = 1;
        func_ov000_0215ffc4(target, entry, 0);
        events->unknown_8e02_++;
        func_ov000_02160068(action, var11);
        func_ov000_021600cc((Struct_ov000_0215767c_5*)action, target);
        events->unknown_8e24_++;
        events->unknown_8e00_++;
        events->unknown_8e01_++;
        events->unknown_8e02_++;
    }
}
