#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "Util/Random.h"
#include "std_library_functions.h"

extern "C" GameObject* func_ov000_021536f8(int unused, int id);
struct Struct_ov024_021f0b84;
extern "C" int func_ov024_021f0d0c(struct Struct_ov024_021f0b84* obj);
extern "C" int func_ov000_0215e9fc(int battle, short* table, int count, int flag);
extern "C" int func_ov000_0215eb1c(int battle, short* table, int count, int flag);
struct Struct_ov024_021ed9dc;
extern "C" int func_ov024_021ed9dc(struct Struct_ov024_021ed9dc* holder, int id);
extern "C" int func_ov024_021ed890(struct Random** arg0, int* arg1, short* table);

struct Struct_ov024_021f0b84_2 { int field0; };
struct Struct_ov024_021fee7c { short v[8]; };
extern struct Struct_ov024_021fee7c data_ov024_021fee7c;

// USA: func_ov024_021f0b84
extern "C" ARM int func_ov024_021f0b84(struct Struct_ov024_021f0b84_2* obj, int id, int unused, int* outCount, short* arg4) {
    GameObject* c = func_ov000_021536f8(obj->field0, id);
    if (!c) return 0;
    if (!func_ov024_021f0d0c((struct Struct_ov024_021f0b84*)c)) return 0;

    int found = 0;
    struct Struct_ov024_021fee7c buf = data_ov024_021fee7c;
    int count = func_ov000_0215e9fc(obj->field0, buf.v, 4, 1);
    if (count <= 0) return 0;
    for (int i = 0; i < count; i++) {
        if (func_ov024_021ed9dc((struct Struct_ov024_021ed9dc*)obj, buf.v[i])) {
            found = 1;
            break;
        }
    }
    if (!found) return 0;

    memset(buf.v, -1, sizeof(buf));
    count = func_ov000_0215eb1c(obj->field0, buf.v, 8, 1);
    if (count <= 0) return 0;

    *outCount = 0;
    for (int i = 0; i < count; i++) {
        GameObject* t = GetCombatantByID(obj->field0, buf.v[i]);
        if (!t) continue;
        if (t->currentStats_->unknown_5a_2_ >= 2) continue;
        int idx = *outCount;
        *outCount = idx + 1;
        arg4[idx] = buf.v[i];
    }
    if (*outCount <= 0) return 0;
    func_ov024_021ed890((struct Random**)obj, outCount, arg4);
    return 1;
}
