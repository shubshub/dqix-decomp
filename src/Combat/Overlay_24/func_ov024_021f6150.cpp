#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "Util/Random.h"

struct Struct_ov024_021dd010 { char unk[0x14]; int flags; };
struct Struct_ov024_021dced0_2 { char unk[0x138]; struct Struct_ov024_021dd010* inner; };

extern "C" int func_ov000_0215e9fc(int battle, unsigned short* table, int count, int flag);
extern "C" int func_ov024_021dd010(struct Struct_ov024_021dced0_2* obj);
extern "C" int func_ov024_021ed890(struct Random** arg0, int* arg1, short* table);

extern unsigned short data_ov024_021feae4;

// USA: func_ov024_021f6150
extern "C" ARM int func_ov024_021f6150(int* a0, int a1, int a2, int* outCount, short* arg4) {
    unsigned short buf[4];
    unsigned short* s = &data_ov024_021feae4;
    unsigned short* d = buf;
    int n = 4;
    do {
        unsigned short* var4 = d++;
        *var4 = *s++;
    } while (--n);

    int count = func_ov000_0215e9fc(*a0, buf, 4, 1);
    if (count <= 0) return 0;

    *outCount = 0;
    for (int i = 0; i < count; i++) {
        GameObject* member = GetCombatantByID(*a0, *(short*)&buf[i]);
        if (!member) continue;
        if (func_ov024_021dd010((struct Struct_ov024_021dced0_2*)member)) continue;
        int idx = *outCount;
        *outCount = idx + 1;
        arg4[idx] = *((short*)buf + i);
    }
    if (*outCount > 0) {
        func_ov024_021ed890((struct Random**)a0, outCount, arg4);
        return 1;
    }
    return 0;
}
