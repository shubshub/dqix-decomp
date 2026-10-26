#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct Struct_ov000_021584e8;
struct Struct_ov024_021e3f14_3 { int lo; int hi; };

struct Struct_ov024_021e04e0;
struct Struct_ov024_021da670_6;
struct Struct_ov024_021dd028_5;
extern "C" int func_ov024_021e05e4(struct Struct_ov024_021e04e0* obj);
extern "C" int func_ov024_021da998(struct Struct_ov024_021da670_6* obj);
extern "C" int func_ov024_021dd260(struct Struct_ov024_021dd028_5* obj);
extern "C" void func_020488cc(unsigned char* obj, int value);
extern "C" void func_02088e64(unsigned char* stats);
extern "C" void func_02087704(void* obj);
extern "C" void func_ov000_0215a88c(void* objRaw, void* arg1, int c);
extern "C" void func_ov000_0215ffc4(void* obj, void* node, int idx);
extern "C" struct Struct_ov000_021584e8* func_ov000_0215e958(void* ctx);
extern "C" void func_ov000_02159eac(void* ctx, struct Struct_ov024_021e3f14_3* words, int effect);
extern "C" void func_ov000_0215cd44(void* ctx, struct Struct_ov000_021584e8* entry, GameObject* c, int d,
    struct Struct_ov024_021e3f14_3 words, int g);

struct Struct_ov024_021e3f14 { char pad[0x24]; unsigned char stage; };
struct Struct_ov024_021e3f14_2 {
    char pad0[0xc];
    void* unknown_c_;
    void* ctx;
};

static inline int inline_ov024_021ddf5c(int id) {
    return id >= 0 && id <= 3;
}

// USA: func_ov024_021e3f14
extern "C" ARM unsigned long long func_ov024_021e3f14(struct Struct_ov024_021e3f14_2* obj, int unused, int id, int arg3, int amount) {
    if (amount <= 0) return 0;
    GameObject* c = GetCombatantByID((int)obj->ctx, id);
    if (!c) return 0;
    struct Struct_ov000_021584e8* entry = func_ov000_0215e958(obj->ctx);
    if (!entry) return 0;
    int added = 0;
    if (func_ov024_021e05e4((struct Struct_ov024_021e04e0*)c)) {
        if (!inline_ov024_021ddf5c(id)) func_020488cc((unsigned char*)c, 1);
        func_02088e64((unsigned char*)c->currentStats_);
        func_ov000_0215a88c(obj->ctx, entry, 0x164);
        added = 1;
    }
    struct Struct_ov024_021e3f14_3 words;
    words.lo = 0;
    words.hi = 0;
    if (func_ov024_021da998((struct Struct_ov024_021da670_6*)c) || func_ov024_021dd260((struct Struct_ov024_021dd028_5*)c)) {
        func_02087704(c->currentStats_);
        int msg = 0;
        unsigned char stage = ((struct Struct_ov024_021e3f14*)c->currentStats_)->stage;
        switch (stage) {
        case 0: msg = 0x17f; break;
        case 1: msg = 0x180; break;
        case 2: msg = 0x181; break;
        case 3: msg = 0x259; break;
        }
        if (stage == 3) func_ov000_02159eac(obj->ctx, &words, 8);
        func_ov000_0215a88c(obj->ctx, entry, msg);
        added = 1;
    }
    if (added) {
        func_ov000_0215cd44(obj->ctx, entry, c, 0, words, 0);
        func_ov000_0215ffc4(obj->unknown_c_, entry, 1);
        ((unsigned char*)obj->ctx)[0x8e02]++;
    }
    return 0;
}
