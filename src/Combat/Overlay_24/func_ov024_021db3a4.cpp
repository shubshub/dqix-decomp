#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"
struct Struct_ov024_021db3a4;
struct Struct_ov024_021db3a4_3;
extern "C" void* GameState_GetParty(GameState*);
struct ArrayContainsByteStruct;
extern "C" int func_02086ef0(ArrayContainsByteStruct*, int);
extern "C" float func_ov024_021db358(GameObject*);
extern "C" void func_ov000_0215a8d4(unsigned char*, int);
extern "C" short func_ov000_0215a16c(void*, int, int, short*);
extern "C" unsigned short func_ov024_021e9b24(Struct_ov024_021db3a4*, int, Struct_ov024_021db3a4_3*, int);
extern "C" unsigned long long func_ov024_021e4b14(Struct_ov024_021db3a4*, short, int, Struct_ov024_021db3a4_3*, int);
extern "C" void* func_ov000_0215e958(void*);
extern "C" void func_ov000_0215a88c(void*, void*, int);
extern "C" void func_ov000_02159eac(void*, void*, int);
extern "C" void func_ov000_0215ccbc(void*, void*, GameObject*, short, short, short, unsigned long long, unsigned char);
struct Struct_ov024_021db3a4_4 { char pad[0x1c]; unsigned char unused:7; unsigned char flag:1; };
struct Struct_ov024_021db3a4 { char pad[0xc]; Struct_ov024_021db3a4_4* action; void* context; int count; };
struct Struct_ov024_021db3a4_2 { unsigned int code:12; unsigned int rest:20; };
struct Struct_ov024_021db3a4_3 { char pad[4]; Struct_ov024_021db3a4_2 field4; };
// USA: func_ov024_021db3a4
extern "C" ARM void* func_ov024_021db3a4(Struct_ov024_021db3a4* obj, short arg, int id, Struct_ov024_021db3a4_3* params, int amount, int unused, unsigned char enabled) {
    GameObject* c = GetCombatantByID((int)obj->context, id);
    if (!c) return 0;
    unsigned short code = params->field4.code;
    if (code == 0x21 || code == 0x310) amount = c->currentStats_->primaryStats.maxHP;
    void* list = GameState_GetParty(GameState::GetInstance());
    if (params->field4.code == 0x20 && func_02086ef0((ArrayContainsByteStruct*)list, arg) && func_ov024_021db358(c) <= 0.08f && enabled && amount > 0)
        func_ov000_0215a8d4((unsigned char*)obj->context, 7);
    short var3 = 0;
    short hp = func_ov000_0215a16c(obj->context, id, amount, &var3);
    int failed = 0;
    if (var3 <= 0) failed = 1;
    unsigned short selection = func_ov024_021e9b24(obj, id, params, failed);
    union { struct { int low; int high; }; unsigned long long value; } effects;
    effects.low = 0;
    effects.high = 0;
    effects.value = func_ov024_021e4b14(obj, arg, id, params, amount);
    void* entry = func_ov000_0215e958(obj->context);
    if (!entry) return 0;
    if (var3 > 0) obj->count++;
    else if (effects.value != 0) obj->count++;
    if (failed) {
        if (effects.value == 0) func_ov000_0215a88c(obj->context, entry, selection);
        else func_ov000_0215a88c(obj->context, entry, 0);
    } else {
        func_ov000_02159eac(obj->context, &effects, 0x25);
        func_ov000_0215a88c(obj->context, entry, selection);
    }
    unsigned short mp = c->currentStats_->primaryStats.currMP;
    unsigned char flag;
    if (obj->action->flag) flag = 1; else flag = 0;
    func_ov000_0215ccbc(obj->context, entry, c, -var3, hp, mp, effects.value, flag);
    return entry;
}
