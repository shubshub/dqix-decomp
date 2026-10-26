#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct Struct_ov024_021dd534 {
    unsigned int a : 10;
    unsigned int b : 10;
    unsigned int c : 10;
    unsigned int hi : 2;
};

struct Struct_ov024_021dd534_2 {
    char pad[0x20];
    struct Struct_ov024_021dd534 f20;
    struct Struct_ov024_021dd534 f24;
    char pad28[8];
    short code;
};

struct Struct_ov024_021dd534_3 { unsigned short unknown_0_0_ : 6; unsigned short code : 3; unsigned short rest : 7; };

struct Struct_ov024_021dd534_4 {
    char pad0[0x14];
    int flags;
    char pad18[0xa];
    struct Struct_ov024_021dd534_3 f22;
};

struct Struct_ov024_021dd534_5 { unsigned char pad : 7; unsigned char flag : 1; };

struct Struct_ov024_021dd534_6 {
    char pad0[0xc];
    void* fc;
    void* f10;
    char unknown_14_[0x61];
    unsigned char unknown_75_;
};

extern "C" int func_02088840(unsigned char* obj);
extern "C" void func_02088854(unsigned char* obj);
extern "C" int func_ov024_021e9198(struct Struct_ov024_021dd534_6* ctx, int id, short code, int mode);
extern "C" unsigned short func_ov024_021da644(int idx, int a, int b);
extern "C" int func_ov024_021eb4b0(int a0, int flags, int mask);
extern "C" void func_ov000_02159eac(void* world, unsigned long long* bits, int bit);
extern "C" void* func_ov000_0215e958(void* world);
extern "C" void func_ov024_021e8bf0(struct Struct_ov024_021dd534_6* obj, void* fieldC, unsigned short* sel);
extern "C" void func_ov000_0215a88c(void* world, void* entry, int msg);
extern "C" void func_ov000_0215cd44(void* world, void* entry, GameObject* c, int d, unsigned long long bits, int flag);

// USA: func_ov024_021dd534
extern "C" ARM void* func_ov024_021dd534(struct Struct_ov024_021dd534_6* obj, int unused, int id, struct Struct_ov024_021dd534_2* range, int arg4, int arg5, unsigned char arg6) {
    GameObject* c = GetCombatantByID((int)obj->f10, id);
    if (!c) return 0;
    unsigned short sel = 0;
    unsigned long long bits = 0;
    int code = range->code;
    if (func_02088840((unsigned char*)c->currentStats_) && arg6) {
        sel = func_ov024_021e9198(obj, id, code, 1);
        if (sel == 0) {
            sel = func_ov024_021da644(id, range->f20.c, range->f24.a);
        }
        if (func_ov024_021eb4b0((int)obj, ((struct Struct_ov024_021dd534_4*)c->currentStats_)->flags, 0x40)) {
            func_ov000_02159eac(obj->f10, &bits, 0x2b);
        }
        func_02088854((unsigned char*)c->currentStats_);
        ((struct Struct_ov024_021dd534_4*)c->currentStats_)->f22.code = (unsigned char)code;
    } else {
        sel = func_ov024_021e9198(obj, id, code, 0);
        if (sel == 0) {
            sel = func_ov024_021da644(id, range->f24.b, range->f24.c);
        }
        obj->unknown_75_ = 0;
    }
    void* entry = func_ov000_0215e958(obj->f10);
    if (!entry) return 0;
    func_ov024_021e8bf0(obj, obj->fc, &sel);
    func_ov000_0215a88c(obj->f10, entry, sel);
    struct Struct_ov024_021dd534_5* var5 = (struct Struct_ov024_021dd534_5*)((char*)obj->fc + 0x1c);
    func_ov000_0215cd44(obj->f10, entry, c, 0, bits, var5->flag != 0);
    return entry;
}
