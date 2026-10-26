#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct Struct_02087860;
struct Struct_020878b4;
struct Struct_ov024_021db7c0_2;
struct Struct_ov024_021db7c0_3;

extern "C" unsigned long long func_ov024_021e4b14(struct Struct_ov024_021db7c0_2* obj, int a, int id, struct Struct_ov024_021db7c0_3* info, int d);
extern "C" int func_02087860(Struct_02087860*, unsigned char);
extern "C" int func_020878b4(struct Struct_020878b4* p, int delta);
void UpdateCombatantDefense(int unused, int combatantId);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" unsigned short func_ov024_021e95d4(struct Struct_ov024_021db7c0_2* obj, int id, struct Struct_ov024_021db7c0_3* info, unsigned char arg3, signed char arg4, int changed, unsigned char flag);
extern "C" void func_ov024_021e8bf0(void* work, void* fieldC, unsigned short* sel);
extern "C" void func_ov000_0215a88c(void* objRaw, void* arg1, int c);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, unsigned long long arg4, int g);

struct Struct_ov024_021db7c0 {
    unsigned char pad : 7;
    unsigned char flag : 1;
};

struct Struct_ov024_021db7c0_2 {
    char pad0[0xc];
    void* unknown_c_;
    void* unknown_10_;
    char unknown_14_[0x73 - 0x14];
    unsigned char unknown_73_;
    char unknown_74_;
    unsigned char unknown_75_;
};

struct Struct_ov024_021db7c0_3 {
    char pad0[0x30];
    short unknown_30_;
};

static inline int IsPartyMember(int id) {
    return id >= 0 && id <= 3;
}

// USA: func_ov024_021db7c0
extern "C" ARM void* func_ov024_021db7c0(struct Struct_ov024_021db7c0_2* obj, short a, int id, struct Struct_ov024_021db7c0_3* info, int unused4, int arg5, unsigned char arg6) {
    GameObject* c = GetCombatantByID((int)obj->unknown_10_, id);
    if (!c) return 0;
    unsigned long long res = 0;
    int var2 = 0;
    int var3 = 0;
    int delta = info->unknown_30_;
    int result = 0;
    if (delta < -2) delta = -2;
    if (delta > 2) delta = 2;
    if (delta < 0) var3 = 1;
    if (arg6) {
        res = func_ov024_021e4b14(obj, a, id, info, 1);
        if (func_02087860((struct Struct_02087860*)c->currentStats_, var3)) {
            result = func_020878b4((struct Struct_020878b4*)c->currentStats_, (signed char)delta);
            UpdateCombatantDefense((int)obj->unknown_10_, id);
            var2 = 1;
        } else {
            obj->unknown_75_ = 0;
        }
    } else {
        obj->unknown_75_ = 0;
    }
    void* entry = func_ov000_0215e958(obj->unknown_10_);
    if (!entry) return 0;
    unsigned short sel = func_ov024_021e95d4(obj, id, info, var3, result, var2, arg6);
    if (res != 0 && !var2) {
        sel = 0;
    }
    if (IsPartyMember(id) && var2) {
        if (!var3) obj->unknown_73_ = 1;
    }
    func_ov024_021e8bf0(obj, obj->unknown_c_, &sel);
    func_ov000_0215a88c(obj->unknown_10_, entry, sel);
    struct Struct_ov024_021db7c0* var8 = (struct Struct_ov024_021db7c0*)((char*)obj->unknown_c_ + 0x1c);
    func_ov000_0215cd44(obj->unknown_10_, entry, c, 0, res, var8->flag != 0);
    return entry;
}
