#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "Util/Random.h"

extern "C" int func_ov000_0215eb1c(int a0, short* buf, int count, int flag);
extern "C" int func_ov024_021eda60(GameObject* combatant);
struct Struct_020885b4;
extern "C" int func_020885b4(struct Struct_020885b4* obj);
struct Struct_02088514;
extern "C" int func_02088514(struct Struct_02088514* obj);
extern "C" int func_ov024_021ed890(struct Random** arg0, int* arg1, short* table);

struct Struct_ov024_021ee8b4 { int field0; };
struct Struct_ov024_021fecbc { short v[8]; };
extern struct Struct_ov024_021fecbc data_ov024_021fecbc;

// USA: func_ov024_021ee8b4
extern "C" ARM int func_ov024_021ee8b4(struct Struct_ov024_021ee8b4* obj, int unused1, int arg2, int* outCount, short* arg4) {
    struct Struct_ov024_021fecbc buf = data_ov024_021fecbc;
    int count = func_ov000_0215eb1c(obj->field0, buf.v, 8, 1);
    if (count <= 0) return 0;
    *outCount = 0;
    for (int i = 0; i < count; i++) {
        GameObject* c = GetCombatantByID(obj->field0, buf.v[i]);
        if (!c) continue;
        if (func_ov024_021eda60(c)) continue;
        if (!func_020885b4((struct Struct_020885b4*)c->currentStats_) &&
            !func_02088514((struct Struct_02088514*)c->currentStats_)) continue;
        int idx = *outCount;
        *outCount = idx + 1;
        arg4[idx] = buf.v[i];
    }
    if (*outCount <= 0) return 0;
    func_ov024_021ed890((struct Random**)obj, outCount, arg4);
    return 1;
}
