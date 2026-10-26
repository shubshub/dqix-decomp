#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" int func_ov000_0215e9fc(int a, short* buf, int max, int start);

struct Struct_ov024_021eff3c { int field0; };
struct Struct_ov024_021feacc { short v[4]; };
extern struct Struct_ov024_021feacc data_ov024_021feacc;

// USA: func_ov024_021eff3c
extern "C" ARM int func_ov024_021eff3c(struct Struct_ov024_021eff3c* obj, int unused1, int arg2, int* outCount, void* arg4) {
    struct Struct_ov024_021feacc buf = data_ov024_021feacc;
    int count = func_ov000_0215e9fc(obj->field0, buf.v, 4, 1);
    if (count <= 0) return 0;
    int found = 0;
    for (int i = 0; i < count; i++) {
        GameObject* c = GetCombatantByID(obj->field0, buf.v[i]);
        if (c && c->currentStats_->primaryStats.agility != 0 && c->currentStats_->agilityBuff > -2) {
            found = 1;
            break;
        }
    }
    if (!found) return 0;
    *outCount = count;
    memcpy(arg4, buf.v, 8);
    return 1;
}
