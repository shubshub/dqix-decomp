#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" int func_ov000_0215eb1c(int a0, short* buf, int count, int flag);
extern "C" float func_ov024_021db358(GameObject* obj);

struct Struct_ov024_021f3d78 { int field0; };
struct Struct_ov024_021feefc { short v[8]; };
extern struct Struct_ov024_021feefc data_ov024_021feefc;

// USA: func_ov024_021f3d78
extern "C" ARM int func_ov024_021f3d78(struct Struct_ov024_021f3d78* obj, int id, int arg2, int* outFlag, short* arg4) {
    struct Struct_ov024_021feefc buf = data_ov024_021feefc;
    int count = func_ov000_0215eb1c(obj->field0, buf.v, 8, 1);
    if (count <= 0) return 0;
    *outFlag = 0;
    for (int i = 0; i < count; i++) {
        if (id == buf.v[i]) continue;
        GameObject* c = GetCombatantByID(obj->field0, buf.v[i]);
        if (!c) continue;
        if (func_ov024_021db358(c) > 0.08f) continue;
        int n = *outFlag;
        *outFlag = n + 1;
        arg4[n] = buf.v[i];
    }
    int result;
    if (*outFlag <= 0) {
        result = 0;
    } else {
        *outFlag = 1;
        arg4[0] = (short)id;
        result = 1;
    }
    return result;
}
