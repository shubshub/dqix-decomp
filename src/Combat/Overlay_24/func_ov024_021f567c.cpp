#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "Util/Random.h"
#include "GameState/GameState.h"

extern "C" int func_ov000_0215e9fc(int a, short* buf, int max, int start);
extern "C" int func_ov024_021eda60(GameObject* combatant);
extern "C" int func_ov024_021ed890(struct Random** arg0, int* arg1, short* table);

struct Struct_ov024_021fec4c { short v[4]; };
extern struct Struct_ov024_021fec4c data_ov024_021fec4c;

// USA: func_ov024_021f567c
extern "C" ARM int func_ov024_021f567c(int* a0, int a1, int a2, int* outFlag, short* arg4) {
    struct Struct_ov024_021fec4c buf = data_ov024_021fec4c;
    int count = func_ov000_0215e9fc(*a0, buf.v, 4, 1);
    if (count <= 0) return 0;
    *outFlag = 0;
    for (int i = 0; i < count; i++) {
        GameObject* c = GetCombatantByID(*a0, buf.v[i]);
        if (!c) continue;
        void* inner = c->currentStats_;
        if (*(unsigned short*)((char*)inner + 2) == 0) continue;
        if (func_ov024_021eda60(c)) continue;
        int n = *outFlag;
        *outFlag = n + 1;
        arg4[n] = buf.v[i];
    }
    if (*outFlag > 0) {
        func_ov024_021ed890((struct Random**)a0, outFlag, arg4);
        return 1;
    }
    return 0;
}
