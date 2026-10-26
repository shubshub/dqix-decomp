#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "std_library_functions.h"

extern "C" int func_ov000_0215eb1c(int battle, unsigned short* table, int count, int flag);
struct Struct_ov024_021f1330;
extern "C" int func_ov024_021f1440(struct Struct_ov024_021f1330* obj);
extern "C" GameObject* func_ov000_021536f8(int unused, int id);
extern "C" int func_ov024_021eda60(GameObject* combatant);

struct Struct_ov024_021f166c { int field0; };

struct Struct_ov024_021f166c_2 {
    signed int unknown_0_0_ : 3;
    signed int unknown_0_3_ : 3;
    signed int unknown_0_6_ : 3;
    signed int unknown_1_1_ : 3;
    signed int unknown_1_4_ : 3;
    signed int unknown_1_7_ : 3;
    signed int unknown_2_2_ : 3;
    signed int unknown_2_5_ : 3;
};

extern unsigned short data_ov024_021fef6c;

// USA: func_ov024_021f166c
extern "C" ARM int func_ov024_021f166c(struct Struct_ov024_021f166c* obj, short id, int arg2, int* outCount, void* arg4) {
    GameObject* c0 = func_ov000_021536f8(obj->field0, id);
    if (!c0) return 0;
    if (!func_ov024_021f1440((struct Struct_ov024_021f1330*)c0)) return 0;

    unsigned short buf[8];
    unsigned short* d = buf;
    unsigned short* s = &data_ov024_021fef6c;
    int n = 8;
    do {
        unsigned short* var5 = d++;
        *var5 = *s++;
    } while (--n);

    int count = func_ov000_0215eb1c(obj->field0, buf, 8, 1);
    if (count <= 0) return 0;

    for (int i = 0; i < count; i++) {
        GameObject* c = GetCombatantByID(obj->field0, *(short*)&buf[i]);
        if (!c) continue;
        if (func_ov024_021eda60(c)) continue;
        struct Struct_ov024_021f166c_2* var9 = (struct Struct_ov024_021f166c_2*)((char*)c->currentStats_ + 0x58);
        if (var9->unknown_2_5_ < 2) break;
    }
    if (*outCount <= 0) return 0;

    *outCount = count;
    memcpy(arg4, buf, 0x10);
    return 1;
}
