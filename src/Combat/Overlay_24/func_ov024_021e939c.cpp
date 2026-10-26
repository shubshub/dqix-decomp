#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"

extern "C" int func_020885b4(struct Struct_020885b4* obj);
extern "C" int func_02088514(struct Struct_02088514* obj);
extern "C" unsigned short func_ov024_021da644(int idx, int a, int b);

struct Struct_ov024_021dbaf4_4 {
    char pad[0x10];
    int field10;
};

// USA: func_ov024_021e939c
extern "C" ARM int func_ov024_021e939c(struct Struct_ov024_021dbaf4_4* ctx, int id, int flag1, int flag2) {
    GameObject* combatant = GetCombatantByID(ctx->field10, id);
    if (combatant == NULL) {
        return 0;
    }
    int var1 = func_02088514((struct Struct_02088514*)combatant->currentStats_);
    int var2 = func_020885b4((struct Struct_020885b4*)combatant->currentStats_);
    if (flag1 != 0) {
        if (flag2 != 0) {
            return var1 != 0 ? 0x10c : 0x10a;
        }
        if (var1 != 0) {
            return 0x10b;
        }
        #if defined(jpn)
        return 0x1b;
#else
        return func_ov024_021da644(id, 0x26d, 0x1b);
#endif
    }
    if (flag2 != 0) {
        return var2 != 0 ? 0x53 : 0x3f;
    }
    if (var1 != 0) {
        return 0x10b;
    }
    if (var2 != 0) {
        return 0x52;
    }
    #if defined(jpn)
        return 0x1b;
#else
        return func_ov024_021da644(id, 0x26d, 0x1b);
#endif
}
