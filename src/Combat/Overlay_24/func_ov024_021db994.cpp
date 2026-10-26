#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct Struct_02087954;
extern "C" int func_02087954(struct Struct_02087954* p, int arg1);
extern "C" int func_020879a8(struct Struct_02087954* p, int delta);
void UpdateCombatantAgility(int a, int id);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void func_ov024_021e8bf0(void* work, void* fieldC, unsigned short* sel);
extern "C" void func_ov000_0215a88c(void* objRaw, void* arg1, int c);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct Struct_ov024_021db994 { unsigned char pad : 7; unsigned char flag : 1; };
struct Struct_ov024_021db994_2 {
    char pad0[0xc];
    void* unknown_c_;
    void* unknown_10_;
    int count;
    char pad18[0x75 - 0x18];
    unsigned char unknown_75_;
};
struct Struct_ov024_021db994_3 { char pad[0x30]; short unknown_30_; };

extern "C" int func_ov024_021e96e4(struct Struct_ov024_021db994_2* ctx, int id,
    struct Struct_ov024_021db994_3* params, int mode, signed char result,
    int arg5, unsigned char arg6);

// USA: func_ov024_021db994
extern "C" ARM void* func_ov024_021db994(struct Struct_ov024_021db994_2* obj, int unused, int id, struct Struct_ov024_021db994_3* params, int arg4, int arg5, unsigned char arg6) {
    GameObject* c = GetCombatantByID((int)obj->unknown_10_, id);
    if (!c) return 0;
    int changed = 0;
    int result = 0;
    int var3 = 0;
    int delta = params->unknown_30_;
    if (delta < -2) delta = -2;
    if (delta > 2) delta = 2;
    if (delta < 0) var3 = 1;
    if (arg6 != 0) {
        if (!func_02087954((struct Struct_02087954*)c->currentStats_, (unsigned char)var3)) {
            obj->unknown_75_ = 0;
        } else {
            result = func_020879a8((struct Struct_02087954*)c->currentStats_, (signed char)delta);
            UpdateCombatantAgility((int)obj->unknown_10_, id);
            changed = 1;
            obj->count++;
        }
    } else {
        obj->unknown_75_ = 0;
    }
    void* entry = func_ov000_0215e958(obj->unknown_10_);
    if (!entry) return 0;
    unsigned short sel = func_ov024_021e96e4(obj, id, params, (unsigned char)var3, (signed char)result, changed, arg6);
    func_ov024_021e8bf0(obj, obj->unknown_c_, &sel);
    func_ov000_0215a88c(obj->unknown_10_, entry, sel);
    struct Struct_ov024_021db994* var7 = (struct Struct_ov024_021db994*)((char*)obj->unknown_c_ + 0x1c);
    func_ov000_0215cd44(obj->unknown_10_, entry, c, 0, 0, 0, var7->flag != 0);
    return entry;
}
