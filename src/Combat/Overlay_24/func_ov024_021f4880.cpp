#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "Util/Random.h"

extern "C" int func_ov000_0215eb1c(int battle, short* table, int count, int flag);

struct Struct_020885b4;
extern "C" int func_020885b4(struct Struct_020885b4* obj);
struct Struct_02088514;
extern "C" int func_02088514(struct Struct_02088514* obj);
extern "C" int func_ov024_021ed890(struct Random** arg0, int* arg1, short* table);

struct Struct_ov024_021fec7c { short v[8]; };
extern struct Struct_ov024_021fec7c data_ov024_021fec7c;

// USA: func_ov024_021f4880
extern "C" ARM int func_ov024_021f4880(int* a0, int a1, int a2, int* outCount, short* arg4) {
    struct Struct_ov024_021fec7c buf = data_ov024_021fec7c;

    int count = func_ov000_0215eb1c(*a0, buf.v, 8, 1);
    if (count <= 0) return 0;

    *outCount = 0;
    for (int i = 0; i < count; i++) {
        GameObject* member = GetCombatantByID(*a0, buf.v[i]);
        if (member && (func_020885b4((struct Struct_020885b4*)member->currentStats_) ||
                       func_02088514((struct Struct_02088514*)member->currentStats_))) {
            int idx = *outCount;
            *outCount = idx + 1;
            arg4[idx] = buf.v[i];
        }
    }
    if (*outCount > 0) {
        func_ov024_021ed890((struct Random**)a0, outCount, arg4);
        return 1;
    }
    return 0;
}
