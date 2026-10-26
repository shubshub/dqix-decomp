#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"

extern "C" GameObject* func_ov000_021536f8(int unused, int id);
extern "C" int func_ov000_0215e9fc(int battle, short* buf, int max, int flag);
extern "C" int func_ov000_0215eb1c(int battle, short* buf, int max, int flag);
struct Struct_ov024_021f0b84;
extern "C" int func_ov024_021f0d0c(struct Struct_ov024_021f0b84* obj);
struct Struct_ov024_021ed9dc { int field0; };
extern "C" int func_ov024_021ed9dc(struct Struct_ov024_021ed9dc* holder, int id);

struct Struct_ov024_021feebc { short v[8]; };
extern struct Struct_ov024_021feebc data_ov024_021feebc;

// USA: func_ov024_021f0e90
extern "C" ARM int func_ov024_021f0e90(struct Struct_ov024_021ed9dc* holder, int id, int unused, int* outCount, short* arg4) {
    GameObject* self = func_ov000_021536f8(holder->field0, id);
    if (!self) return 0;
    if (!func_ov024_021f0d0c((struct Struct_ov024_021f0b84*)self)) return 0;

    int found = 0;
    struct Struct_ov024_021feebc buf = data_ov024_021feebc;
    int count = func_ov000_0215e9fc(holder->field0, buf.v, 4, 1);
    if (count <= 0) return 0;
    for (int i = 0; i < count; i++) {
        if (func_ov024_021ed9dc(holder, buf.v[i])) {
            found = 1;
            break;
        }
    }
    if (!found) return 0;

    memset(buf.v, -1, sizeof(buf));
    count = func_ov000_0215eb1c(holder->field0, buf.v, 8, 1);
    if (count <= 0) return 0;

    *outCount = 0;
    for (int i = 0; i < count; i++) {
        GameObject* c = GetCombatantByID(holder->field0, buf.v[i]);
        if (!c) continue;
        if (c->currentStats_->unknown_5a_2_ >= 2) continue;
        int idx = *outCount;
        *outCount = idx + 1;
        arg4[idx] = buf.v[i];
    }
    if (*outCount <= 0) return 0;

    *outCount = count;
    memcpy(arg4, buf.v, sizeof(buf));
    return 1;
}
