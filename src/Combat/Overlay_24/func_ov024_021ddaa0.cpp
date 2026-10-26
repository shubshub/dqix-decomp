#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct Struct_02087e18;
struct Struct_02087e6c;

extern "C" int func_02087e18(Struct_02087e18*, unsigned char);
extern "C" int func_02087e6c(struct Struct_02087e6c* obj, int delta);
extern "C" unsigned short func_ov024_021da644(int idx, int a, int b);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov000_0215a88c(void* objRaw, void* arg1, int c);
extern "C" void func_ov024_021e8bf0(void* work, void* fieldC, unsigned short* sel);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct Struct_ov024_021ddaa0_2 {
    unsigned int a : 10;
    unsigned int b : 10;
    unsigned int c : 10;
    unsigned int hi : 2;
};

struct Struct_ov024_021ddaa0_3 {
    unsigned char pad : 7;
    unsigned char flag : 1;
};

struct Struct_ov024_021ddaa0_4 {
    char pad0[0xc];
    void* unknown_c_;
    void* unknown_10_;
};

struct Struct_ov024_021ddaa0 {
    char pad0[0x20];
    struct Struct_ov024_021ddaa0_2 f20;
    struct Struct_ov024_021ddaa0_2 f24;
    char pad28[0x30 - 0x28];
    short unknown_30_;
};

// USA: func_ov024_021ddaa0
extern "C" ARM void* func_ov024_021ddaa0(struct Struct_ov024_021ddaa0_4* obj, int unused, int id, struct Struct_ov024_021ddaa0* info, int unused4, int arg5, unsigned char arg6) {
    GameObject* c = GetCombatantByID((int)obj->unknown_10_, id);
    if (!c) return 0;
    int var1 = 0;
    int result = 0;
    if (arg6) {
        int delta = info->unknown_30_;
        if (delta < -2) delta = -2;
        if (delta > 2) delta = 2;
        int var4 = 0;
        if (delta < 0) var4 = 1;
        if (func_02087e18((struct Struct_02087e18*)c->currentStats_, var4)) {
            result = func_02087e6c((struct Struct_02087e6c*)c->currentStats_, (signed char)delta);
            var1 = 1;
        }
    }
    unsigned short sel = 0;
    if (var1) {
        if (info->unknown_30_ > 0) {
            switch (result) {
                case 2: sel = 0x1b0; break;
                case 0: sel = 0x1af; break;
                default: sel = 0x1b1; break;
            }
        } else {
            switch (result) {
                case 0: sel = 0x1af; break;
                default: sel = 0x1ae; break;
            }
        }
    } else {
        sel = func_ov024_021da644(id, info->f24.b, info->f24.c);
    }
    int extra = func_ov024_021da644(id, info->f20.c, info->f24.a);
    void* entry = func_ov000_0215e958(obj->unknown_10_);
    if (!entry) return 0;
    if (extra) {
        func_ov000_0215a88c(obj->unknown_10_, entry, extra);
    }
    func_ov024_021e8bf0(obj, obj->unknown_c_, &sel);
    func_ov000_0215a88c(obj->unknown_10_, entry, sel);
    struct Struct_ov024_021ddaa0_3* var8 = (struct Struct_ov024_021ddaa0_3*)((char*)obj->unknown_c_ + 0x1c);
    func_ov000_0215cd44(obj->unknown_10_, entry, c, 0, 0, 0, var8->flag != 0);
    return entry;
}
