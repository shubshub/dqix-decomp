#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" int func_0208830c(unsigned char* obj);
extern "C" void func_02088338(unsigned char* obj);
struct Struct_ov024_021dbd84_6;
extern "C" int func_ov024_021e929c(struct Struct_ov024_021dbd84_6* ctx, int id, int flag);
struct Struct_ov024_021da670_6;
extern "C" int func_ov024_021da998(struct Struct_ov024_021da670_6* obj);
extern "C" int func_ov024_021eb4b0(int a0, int flags, int mask);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);
extern "C" void* func_ov024_021e8cfc(void* obj, void* c, int kind, int arg3);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov024_021e8bf0(void* unused0, void* obj, unsigned short* sel);
extern "C" void func_ov000_0215a88c(void* objRaw, void* arg1, int c);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, unsigned long long arg4, int g);

struct Struct_ov024_021dbd84_7 {
    unsigned int a : 10;
    unsigned int b : 10;
    unsigned int c : 10;
    unsigned int hi : 2;
};
struct Struct_ov024_021dbd84 { unsigned char pad : 7; unsigned char flag : 1; };
struct Struct_ov024_021dbd84_2 {
    char pad0[0xc];
    void* unknown_c_;
    void* unknown_10_;
    int unknown_14_;
    char pad18[0x75 - 0x18];
    unsigned char unknown_75_;
};
struct Struct_ov024_021dbd84_3 { unsigned int unknown_0_0_ : 12; unsigned int rest : 20; };
struct Struct_ov024_021dbd84_4 {
    char pad0[4];
    struct Struct_ov024_021dbd84_3 field4;
    char pad1[0x20 - 8];
    struct Struct_ov024_021dbd84_7 f20;
    struct Struct_ov024_021dbd84_7 f24;
};
struct Struct_ov024_021dbd84_5 { char pad[0x14]; int flags; };

// USA: func_ov024_021dbd84
extern "C" ARM void* func_ov024_021dbd84(struct Struct_ov024_021dbd84_2* obj, int unused, int id, struct Struct_ov024_021dbd84_4* range, int arg4, int arg5, unsigned char arg6) {
    GameObject* c = GetCombatantByID((int)obj->unknown_10_, id);
    if (!c) return 0;
    int special = 0;
    union { struct { int lo; int hi; }; unsigned long long v; } local;
    int clear = func_0208830c((unsigned char*)c->currentStats_);
    if (clear && arg6) special = 1;
    local.lo = 0;
    local.hi = 0;
    unsigned short sel = func_ov024_021e929c((struct Struct_ov024_021dbd84_6*)obj, id, special);
    int flagA = func_ov024_021da998((struct Struct_ov024_021da670_6*)c);
    if (special) {
        if (range->field4.unknown_0_0_ == 0x233) sel = range->f20.c;
        if (func_ov024_021eb4b0((int)obj, ((struct Struct_ov024_021dbd84_5*)c->currentStats_)->flags, 0x10)) {
            func_ov000_02159eac(obj->unknown_10_, &local, 0x2b);
        }
        func_02088338((unsigned char*)c->currentStats_);
        func_ov000_02159eac(obj->unknown_10_, &local, 0xe);
        obj->unknown_14_++;
        if (flagA) func_ov024_021e8cfc(obj, c, 0, 0);
    } else {
        obj->unknown_75_ = 0;
    }
    void* entry = func_ov000_0215e958(obj->unknown_10_);
    if (!entry) return 0;
    func_ov024_021e8bf0(obj, obj->unknown_c_, &sel);
    func_ov000_0215a88c(obj->unknown_10_, entry, sel);
    struct Struct_ov024_021dbd84* var7 = (struct Struct_ov024_021dbd84*)((char*)obj->unknown_c_ + 0x1c);
    func_ov000_0215cd44(obj->unknown_10_, entry, c, 0, local.v, var7->flag != 0);
    return entry;
}
