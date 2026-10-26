#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct Struct_ov024_021da670_7;
extern "C" int func_ov024_021da9b0(struct Struct_ov024_021da670_7* obj);
extern "C" unsigned short func_ov024_021da644(int idx, int a, int b);

struct Struct_ov024_021ddc80_4 { char pad[0x10]; int unused; };

// USA: func_ov024_021e9464
extern "C" ARM int func_ov024_021e9464(struct Struct_ov024_021ddc80_4* ctx, int id, int mode) {
    GameObject* c = GetCombatantByID(ctx->unused, id);
    if (!c) return 0;
    int var1 = func_ov024_021da9b0((struct Struct_ov024_021da670_7*)c);
    if (mode != 0) {
        return var1 ? 0x6e : 0x1e;
    }
    if (var1) return 0x6f;
#if defined(jpn)
    return 0x1b;
#else
    return func_ov024_021da644(id, 0x26d, 0x1b);
#endif
}
