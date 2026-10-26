#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"
#include "Util/Random.h"

struct Struct_ov024_021e4604;

extern "C" int func_ov000_02156068(void* obj, int id, int a2, int a3);
extern "C" int func_ov024_021e47dc(struct Struct_ov024_021e4604* obj);
extern "C" void func_02088b34(unsigned char* stats);
extern "C" void func_ov000_0215a004(void* a0, int arg1, int id2, int flags, void* buf, int extra, int flag, int mode);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);

struct Struct_ov024_021e4604_2 {
    char pad0[0x1c];
    unsigned char unknown_1c_0_ : 7;
    unsigned char flag : 1;
};

struct Struct_ov024_021e4604_3 {
    char pad0[0xc];
    struct Struct_ov024_021e4604_2* ctl;
    void* unknown_10_;
};

struct Struct_ov024_021e4604_4 {
    char pad0[0x48];
    unsigned char unknown_48_;
};

static inline unsigned short inline_ov024_021dc540(GameObject* c) { SDK_NULL_ASSERT(c); return c->currentStats_->primaryStats.currHP; }

// USA: func_ov024_021e4604
extern "C" ARM unsigned long long func_ov024_021e4604(struct Struct_ov024_021e4604_3* obj, int arg1, int id, int extra) {
    GameObject* c = GetCombatantByID((int)obj->unknown_10_, id);
    if (!func_ov000_02156068(obj->unknown_10_, id, 0, 1)) {
        if ((int)((struct Struct_ov024_021e4604_4*)c->currentStats_)->unknown_48_ <= 0) return 0;
    }
    int roll = NextRandomMax((struct Random*)obj->unknown_10_, 100);
    float var2 = 12.5f;
    if (!func_ov000_02156068(obj->unknown_10_, id, 0, 1)) {
        var2 = var2 * ((int)((struct Struct_ov024_021e4604_4*)c->currentStats_)->unknown_48_ / 100.0f);
    }
    if (obj->ctl->flag) var2 = 100.0f;
    if (roll >= var2) return 0;
    union { struct { int lo; int hi; }; unsigned long long v; } local;
    local.lo = 0;
    local.hi = 0;
    if (func_ov024_021e47dc((struct Struct_ov024_021e4604*)c)) {
        func_02088b34((unsigned char*)c->currentStats_);
        func_ov000_0215a004(obj->unknown_10_, arg1, id, inline_ov024_021dc540(c) - 1, &local, extra, obj->ctl->flag != 0, 0);
        func_ov000_02159eac(obj->unknown_10_, &local, 0x29);
    } else {
        func_ov000_0215a004(obj->unknown_10_, arg1, id, 0xffff, &local, extra, obj->ctl->flag != 0, 8);
        local.lo = 0;
        local.hi = 0;
        func_ov000_02159eac(obj->unknown_10_, &local, 0xd);
    }
    return local.v;
}
