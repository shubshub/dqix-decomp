#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"
struct Obj021db3a4;
struct Params021db3a4;
void* GameState_GetParty(GameState*);
struct ArrayContainsByteStruct;
int ArrayContainsByte_02086ef0(ArrayContainsByteStruct*, int);
extern "C" float func_ov024_021db358(GameObject*);
extern "C" void func_ov000_0215a8d4(unsigned char*, int);
extern "C" short func_ov000_0215a16c(void*, int, int, short*);
extern "C" unsigned short func_ov024_021e9b24(Struct_ov024_021db3a4*, int, Struct_ov024_021db3a4_3*, int);
extern "C" unsigned long long func_ov024_021e4b14(Struct_ov024_021db3a4*, short, int, Struct_ov024_021db3a4_3*, int);
extern "C" void* func_ov000_0215e958(void*);
extern "C" void func_ov000_0215a88c(void*, void*, int);
extern "C" void func_ov000_02159eac(void*, void*, int);
extern "C" void func_ov000_0215ccbc(void*, void*, GameObject*, short, short, short, unsigned long long, unsigned char);
struct Struct_ov024_021db3a4_4 { char unknown_0_[0x1c]; unsigned char unknown_1c_0_:7; unsigned char unknown_1c_7_:1; };
struct Struct_ov024_021db3a4 { char unknown_0_[0xc]; Struct_ov024_021db3a4_4* unknown_c_; void* unknown_10_; int unknown_14_; };
struct Struct_ov024_021db3a4_2 { unsigned int unknown_0_0_:12; unsigned int unknown_1_4_:20; };
struct Struct_ov024_021db3a4_3 { char unknown_0_[4]; Struct_ov024_021db3a4_2 unknown_4_; };
// USA: func_ov024_021db3a4
extern "C" ARM void* func_ov024_021db3a4(Obj021db3a4* obj, short arg, int id, Params021db3a4* params, int amount, int unused, unsigned char enabled) {
    GameObject* c = GetCombatantByID((int)obj->context, id);
    if (!c) return 0;
    unsigned short code = params->field4.code;
    if (code == 0x21 || code == 0x310) amount = c->currentStats_->primaryStats.maxHP;
    void* list = GameState_GetParty(GameState::GetInstance());
    if (params->field4.code == 0x20 && ArrayContainsByte_02086ef0((ArrayContainsByteStruct*)list, arg) && func_ov024_021db358(c) <= 0.08f && enabled && amount > 0)
        IncrementByteCounterCapped0x63_0215a8d4((unsigned char*)obj->context, 7);
    short applied = 0;
    short hp = ApplyHPDelta0215a16c(obj->context, id, amount, &applied);
    int failed = 0;
    if (applied <= 0) failed = 1;
    unsigned short selection = func_ov024_021e9b24(obj, id, params, failed);
    union { struct { int low; int high; }; unsigned long long value; } effects;
    effects.low = 0;
    effects.high = 0;
    effects.value = func_ov024_021e4b14(obj, arg, id, params, amount);
    void* entry = func_ov000_0215e958(obj->context);
    if (!entry) return 0;
    if (applied > 0) obj->count++;
    else if (effects.value != 0) obj->count++;
    if (failed) {
        if (effects.value == 0) AddEntryAndIncrementCount0215a88c(obj->context, entry, selection);
        else AddEntryAndIncrementCount0215a88c(obj->context, entry, 0);
    } else {
        func_ov000_02159eac(arg0->unknown_10_, &var7, 0x25);
        func_ov000_0215a88c(arg0->unknown_10_, var8, var6);
    }
    unsigned short var9 = var0->currentStats_->primaryStats.currMP;
    unsigned char var10;
    if (arg0->unknown_c_->unknown_1c_7_) var10 = 1; else var10 = 0;
    func_ov000_0215ccbc(arg0->unknown_10_, var8, var0, -var3, var4, var9, var7.unknown1_0_, var10);
    return var8;
}
