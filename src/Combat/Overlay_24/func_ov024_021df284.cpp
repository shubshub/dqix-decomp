#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct Struct_02087b3c;
extern "C" int func_02087b3c(struct Struct_02087b3c* p, int arg1);
struct Struct_02087b90;
extern "C" int func_02087b90(struct Struct_02087b90* p, int delta);
void UpdateCombatantMagicalMight(int unused, int combatantId);
extern "C" unsigned short func_ov024_021da644(int idx, int a, int b);
extern "C" void func_ov000_0215a88c(void* objRaw, void* arg1, int c);

struct Struct_ov024_021df284 {
    char pad0[0x24];
    unsigned int : 10;
    unsigned int unknown_25_2_ : 10;
    unsigned int unknown_26_4_ : 10;
    unsigned int : 2;
    char pad28[0x8];
    short stage;
};
struct Struct_ov024_021df284_2 { char pad[0x1c]; unsigned char unk : 7; unsigned char flag : 1; };
struct Struct_ov024_021df284_3 {
    char pad0[0xc];
    struct Struct_ov024_021df284_2* action;
    void* ctx;
    int count;
};

extern "C" unsigned long long func_ov024_021e4b14(struct Struct_ov024_021df284_3* self, short arg, int id, struct Struct_ov024_021df284* params, int d);
extern "C" int func_ov024_021e9904(struct Struct_ov024_021df284_3* ctx, int id, struct Struct_ov024_021df284* params, unsigned char arg3, signed char stage);
extern "C" void* func_ov000_0215e958(void* ctx);
extern "C" void func_ov024_021e8bf0(struct Struct_ov024_021df284_3* obj, struct Struct_ov024_021df284_2* action, unsigned short* sel);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

// USA: func_ov024_021df284
extern "C" ARM void* func_ov024_021df284(struct Struct_ov024_021df284_3* obj, short arg, int id, struct Struct_ov024_021df284* params, int unused, int arg5, unsigned char enabled) {
    GameObject* c = GetCombatantByID((int)obj->ctx, id);
    if (!c) return 0;
    bool var1 = false;
    int var2 = 0;
    unsigned long long res = 0;
    unsigned short sel = 0;
    if (enabled != 0) {
        res = func_ov024_021e4b14(obj, arg, id, params, 1);
        int stage = params->stage;
        if (stage < -2) stage = -2;
        if (stage > 2) stage = 2;
        if (stage < 0) var2 = 1;
        if (func_02087b3c((struct Struct_02087b3c*)c->currentStats_, (unsigned char)var2)) {
            int result = func_02087b90((struct Struct_02087b90*)c->currentStats_, (signed char)stage);
            UpdateCombatantMagicalMight((int)obj->ctx, id);
            var1 = true;
            sel = func_ov024_021e9904(obj, id, params, var2, (signed char)result);
            obj->count++;
        }
    }
    if (!var1 && res == 0) {
        sel = func_ov024_021da644(id, params->unknown_25_2_, params->unknown_26_4_);
    }
    if (res != 0 && !var1) {
        sel = 0;
    }
    void* entry = func_ov000_0215e958(obj->ctx);
    if (!entry) return 0;
    func_ov024_021e8bf0(obj, obj->action, &sel);
    func_ov000_0215a88c(obj->ctx, entry, sel);
    func_ov000_0215cd44(obj->ctx, entry, c, 0, 0, 0, obj->action->flag != 0);
    return entry;
}
