#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"

extern "C" int func_020882f8(unsigned char* obj);
extern "C" unsigned short func_ov024_021da644(int idx, int a, int b);

struct Struct_ov024_021dbd84_6 {
    char pad[0x10];
    int field10;
};

// USA: func_ov024_021e929c
extern "C" ARM int func_ov024_021e929c(struct Struct_ov024_021dbd84_6* ctx, int id, int flag) {
    GameObject* combatant = GetCombatantByID(ctx->field10, id);
    if (combatant == NULL) {
        return 0;
    }
    int var1 = func_020882f8((unsigned char*)combatant->currentStats_);
    if (flag != 0) {
        if (var1 != 0) {
            return func_ov024_021da644(id, 0x42, 0x42 + 0x13c);
        }
        return func_ov024_021da644(id, 0x41, 0x92);
    }
    if (var1 != 0) {
        return 0x43;
    }
    #if defined(jpn)
        return 0x1b;
#else
        return func_ov024_021da644(id, 0x26d, 0x1b);
#endif
}
