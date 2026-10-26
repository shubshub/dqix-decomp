#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"
#include "Util/Random.h"

struct Struct_ov024_021dd828;
struct Struct_ov024_021e2bd0;
extern "C" int func_020883ac(unsigned char* obj);
extern "C" int func_ov024_021e9320(struct Struct_ov024_021dd828* ctx, int id, int mode);
extern "C" int func_ov024_021eb4b0(int a0, int flags, int mask);
extern "C" void func_020883cc(unsigned char* obj);
extern "C" void* func_ov024_021e8ca0(struct Struct_ov024_021e2bd0* obj, int id);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, unsigned long long arg4, int g);

struct Struct_ov024_021e386c_3 {
    char pad0[0x14];
    int unknown_14_;
    char pad18[0x4a - 0x18];
    unsigned char unknown_4a_;
};
struct Struct_ov024_021e386c_4 {
    unsigned int enemy : 7;
    unsigned int party : 7;
    unsigned int rest : 18;
};
struct Struct_ov024_021e386c_5 {
    char pad0[0x14];
    struct Struct_ov024_021e386c_4 unknown_14_;
};
struct Struct_ov024_021e386c { char pad[0x1c]; unsigned char unk : 7; unsigned char flag : 1; };
struct Struct_ov024_021e386c_2 {
    char pad0[0xc];
    struct Struct_ov024_021e386c* action;
    void* ctx;
};

static inline struct Struct_ov024_021e386c_3* inline_ov000_0215a908_5(GameObject* c) {
    return (struct Struct_ov024_021e386c_3*)c->currentStats_;
}

static inline int inline_ov024_021ddf5c(int id) {
    return id >= 0 && id <= 3;
}

// USA: func_ov024_021e386c
extern "C" ARM unsigned long long func_ov024_021e386c(struct Struct_ov024_021e386c_2* obj, int actorId, int id, struct Struct_ov024_021e386c_5* skill, int amount) {
    if (amount <= 0) return 0;
    GameObject* c = GetCombatantByID((int)obj->ctx, id);
    if (!c) return 0;
    if (inline_ov000_0215a908_5(c)->unknown_4a_ == 0) return 0;
    if (!func_020883ac((unsigned char*)inline_ov000_0215a908_5(c))) return 0;
    int roll = NextRandomMax((struct Random*)obj->ctx, 100);
    float var2 = 100.0f;
    if (!obj->action->flag) {
        if (inline_ov024_021ddf5c(actorId)) var2 = skill->unknown_14_.party;
        else var2 = skill->unknown_14_.enemy;
        var2 = var2 * (inline_ov000_0215a908_5(c)->unknown_4a_ / 100.0f);
    }
    if (roll >= var2) return 0;
    int sel = func_ov024_021e9320((struct Struct_ov024_021dd828*)obj, id, 1);
    union { struct { int lo; int hi; }; unsigned long long v; } words;
    words.lo = 0;
    words.hi = 0;
    if (func_ov024_021eb4b0((int)obj, inline_ov000_0215a908_5(c)->unknown_14_, 0x20)) {
        func_ov000_02159eac(obj->ctx, &words, 0x2b);
    }
    func_020883cc((unsigned char*)inline_ov000_0215a908_5(c));
    func_ov000_02159eac(obj->ctx, &words, 0x17);
    void* entry = func_ov024_021e8ca0((struct Struct_ov024_021e2bd0*)obj, sel);
    if (entry) {
        func_ov000_0215cd44(obj->ctx, entry, c, 0, 0, 0);
    }
    return words.v;
}
