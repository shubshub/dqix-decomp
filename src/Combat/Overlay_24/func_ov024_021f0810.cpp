#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "std_library_functions.h"

extern "C" int func_ov000_0215e9fc(int battle, unsigned short* table, int count, int flag);
extern "C" int func_020882f8(unsigned char* obj);
extern "C" int func_ov024_021eda60(GameObject* combatant);

extern unsigned short data_ov024_021feaac;

// USA: func_ov024_021f0810
extern "C" ARM int func_ov024_021f0810(int* a0, int a1, int a2, int* outCount, void* arg4) {
    unsigned short buf[4];
    unsigned short* d = buf;
    unsigned short* s = &data_ov024_021feaac;
    int n = 4;
    do {
        unsigned short* var4 = d++;
        *var4 = *s++;
    } while (--n);

    int count = func_ov000_0215e9fc(*a0, buf, 4, 1);
    if (count <= 0) return 0;

    int found = 0;
    for (int i = 0; i < count; i++) {
        GameObject* c = GetCombatantByID(*a0, *(short*)&buf[i]);
        if (c && !func_020882f8((unsigned char*)c->currentStats_) && !func_ov024_021eda60(c)) {
            int var9 = *((unsigned char*)c->currentStats_ + 0x47);
            if (var9 > 0) found++;
        }
    }
    if (found * 3 < count * 2) return 0;

    *outCount = count;
    memcpy(arg4, buf, 8);
    return 1;
}
