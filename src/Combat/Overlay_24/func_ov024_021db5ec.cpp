#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" int func_0208776c(void* obj, int dir);
struct Struct_020877c0;
extern "C" int func_020877c0(struct Struct_020877c0* p, int delta);
void UpdateCombatantAttack(int unused, int combatantId);
extern "C" void func_ov000_0215a88c(void* objRaw, void* arg1, int c);

struct Struct_ov024_021db5ec {
    char pad0[0x30];
    short stage;
};
struct Struct_ov024_021db5ec_2 { char pad[0x1c]; unsigned char unk : 7; unsigned char flag : 1; };
struct Struct_ov024_021db5ec_3 {
    char pad0[0xc];
    struct Struct_ov024_021db5ec_2* action;
    void* ctx;
    char unknown_14_[0x72 - 0x14];
    unsigned char unknown_72_;
    char unknown_73_[2];
    unsigned char unknown_75_;
};

extern "C" unsigned long long func_ov024_021e4b14(struct Struct_ov024_021db5ec_3* self, short arg, int id, struct Struct_ov024_021db5ec* params, int d);
extern "C" int func_ov024_021e94c4(struct Struct_ov024_021db5ec_3* ctx, int id, struct Struct_ov024_021db5ec* params, unsigned char mode, signed char value, unsigned char arg5, unsigned char arg6);
extern "C" void* func_ov000_0215e958(void* ctx);
extern "C" void func_ov024_021e8bf0(struct Struct_ov024_021db5ec_3* obj, struct Struct_ov024_021db5ec_2* action, unsigned short* sel);
extern "C" void func_ov000_0215cd44(void* ctx, void* entry, GameObject* c, int arg3, unsigned long long words, unsigned char flag);

// USA: func_ov024_021db5ec
extern "C" ARM void* func_ov024_021db5ec(struct Struct_ov024_021db5ec_3* obj, short arg, int id, struct Struct_ov024_021db5ec* params, int unused, int arg5, unsigned char enabled) {
    GameObject* c = GetCombatantByID((int)obj->ctx, id);
    if (!c) return 0;
    unsigned long long res = 0;
    bool var2 = false;
    int var3 = 0;
    int stage = params->stage;
    int result = 0;
    if (stage < -2) stage = -2;
    if (stage > 2) stage = 2;
    if (stage < 0) var3 = 1;
    if (enabled != 0) {
        res = func_ov024_021e4b14(obj, arg, id, params, 1);
        if (func_0208776c(c->currentStats_, (unsigned char)var3)) {
            result = func_020877c0((struct Struct_020877c0*)c->currentStats_, (signed char)stage);
            UpdateCombatantAttack((int)obj->ctx, id);
            var2 = true;
        } else {
            obj->unknown_75_ = 0;
        }
    } else {
        obj->unknown_75_ = 0;
    }
    void* entry = func_ov000_0215e958(obj->ctx);
    if (!entry) return 0;
    unsigned short sel = func_ov024_021e94c4(obj, id, params, var3, (signed char)result, var2, enabled);
    if (res != 0 && !var2) {
        sel = 0;
    }
    int inRange = (id >= 0 && id <= 3);
    if (inRange && var2) {
        if (var3 == 0) obj->unknown_72_ = 1;
    }
    func_ov024_021e8bf0(obj, obj->action, &sel);
    func_ov000_0215a88c(obj->ctx, entry, sel);
    func_ov000_0215cd44(obj->ctx, entry, c, 0, res, obj->action->flag != 0);
    return entry;
}
