#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "Util/Random.h"

extern "C" int func_ov000_0215eb1c(int a0, short* buf, int count, int flag);
extern "C" int func_ov024_021ed890(struct Random** arg0, int* arg1, short* table);

struct Struct_ov024_021eee68 { int field0; };
struct Struct_ov024_021fee9c { short v[8]; };
extern struct Struct_ov024_021fee9c data_ov024_021fee9c;

// USA: func_ov024_021eee68
extern "C" ARM int func_ov024_021eee68(struct Struct_ov024_021eee68* obj, int unused1, int arg2, int* outCount, short* arg4) {
    struct Struct_ov024_021fee9c buf = data_ov024_021fee9c;
    int count = func_ov000_0215eb1c(obj->field0, buf.v, 8, 1);
    if (count <= 0) return 0;

    *outCount = 0;
    for (int i = 0; i < count; i++) {
        GameObject* c = GetCombatantByID(obj->field0, buf.v[i]);
        if (!c) continue;
        if (c->currentStats_->primaryStats.defense >= 0xffff) continue;
        if (c->currentStats_->defenseBuff >= 2) continue;
        int idx = *outCount;
        *outCount = idx + 1;
        arg4[idx] = buf.v[i];
    }

    if (*outCount <= 0) return 0;
    func_ov024_021ed890((struct Random**)obj, outCount, arg4);
    return 1;
}
