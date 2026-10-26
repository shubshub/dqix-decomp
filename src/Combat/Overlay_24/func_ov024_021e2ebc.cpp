#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"
#include "Util/Random.h"

struct Struct_020877c0;
extern "C" int func_0208776c(void* obj, int dir);
extern "C" int func_020877c0(struct Struct_020877c0* p, int delta);
void UpdateCombatantAttack(int a, int id);
struct Struct_ov024_021e2bd0;
extern "C" void* func_ov024_021e8ca0(struct Struct_ov024_021e2bd0* obj, int id);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct Struct_ov024_021e2ebc { unsigned char pad : 7; unsigned char flag : 1; };
struct Struct_ov024_021e2ebc_2 { char pad0[0xc]; void* unknown_c_; void* unknown_10_; };
struct Struct_ov024_021e2ebc_3 { char pad[0x32]; short unknown_32_; };

extern "C" int func_ov024_021e94c4(struct Struct_ov024_021e2ebc_2* ctx, int id,
    struct Struct_ov024_021e2ebc_3* params, unsigned char mode, signed char value,
    unsigned char arg5, unsigned char arg6);

// USA: func_ov024_021e2ebc
extern "C" ARM unsigned long long func_ov024_021e2ebc(struct Struct_ov024_021e2ebc_2* obj, int unused, int id, struct Struct_ov024_021e2ebc_3* params, int enabled) {
    if (enabled <= 0) return 0;
    GameObject* c = GetCombatantByID((int)obj->unknown_10_, id);
    if (!c) return 0;
    int var1 = NextRandomMax((struct Random*)obj->unknown_10_, 100);
    int delta = params->unknown_32_;
    if (delta < -2) delta = -2;
    if (delta > 2) delta = 2;
    int var3 = 0;
    if (delta < 0) {
        if (*((unsigned char*)c->currentStats_ + 0x4f) == 0) return 0;
        struct Struct_ov024_021e2ebc* var4 = (struct Struct_ov024_021e2ebc*)((char*)obj->unknown_c_ + 0x1c);
        if (!var4->flag) {
            float limit = *((unsigned char*)c->currentStats_ + 0x4f);
            if ((float)var1 >= limit) return 0;
        }
        var3 = 1;
    }
    int changed = 0;
    int result = 0;
    if (func_0208776c(c->currentStats_, (unsigned char)var3)) {
        result = func_020877c0((struct Struct_020877c0*)c->currentStats_, (signed char)delta);
        UpdateCombatantAttack((int)obj->unknown_10_, id);
        changed = 1;
    }
    if (changed) {
        int sel = func_ov024_021e94c4(obj, id, params, var3, (signed char)result, 1, 1);
        void* entry = func_ov024_021e8ca0((struct Struct_ov024_021e2bd0*)obj, sel);
        if (entry) {
            func_ov000_0215cd44(obj->unknown_10_, entry, c, 0, 0, 0, 0);
        }
    }
    return 0;
}
