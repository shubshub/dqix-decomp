#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" void func_ov024_021ea85c(void* obj, int id, int a2);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, unsigned long long arg4, int g);

struct Struct_ov024_021e02b0 {
    unsigned char pad : 7;
    unsigned char flag : 1;
};

struct Struct_ov024_021e02b0_2 {
    char pad0[0xc];
    void* unknown_c_;
    void* unknown_10_;
    int unknown_14_;
    char pad18[0x44 - 0x18];
    short field0x44;
};

// USA: func_ov024_021e02b0
extern "C" ARM void* func_ov024_021e02b0(struct Struct_ov024_021e02b0_2* obj, int unused, int id, int arg3, int unused4, int arg5, unsigned char arg6) {
    GameObject* c = GetCombatantByID((int)obj->unknown_10_, id);
    if (!c) return 0;
    union { struct { int lo; int hi; }; unsigned long long v; } local;
    local.lo = 0;
    local.hi = 0;
    if (arg6) {
        func_ov024_021ea85c(obj, id, 0);
        func_ov000_02159eac(obj->unknown_10_, &local, 0x28);
        obj->unknown_14_++;
        if (obj->field0x44 < 0) {
            obj->field0x44 = id;
        }
    }
    void* entry = func_ov000_0215e958(obj->unknown_10_);
    if (!entry) return 0;
    struct Struct_ov024_021e02b0* var3 = (struct Struct_ov024_021e02b0*)((char*)obj->unknown_c_ + 0x1c);
    func_ov000_0215cd44(obj->unknown_10_, entry, c, 0, local.v, var3->flag != 0);
    return entry;
}
