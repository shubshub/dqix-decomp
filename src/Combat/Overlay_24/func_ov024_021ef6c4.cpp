#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "std_library_functions.h"

extern "C" int func_ov000_0215e9fc(int a, short* buf, int max, int start);
extern "C" int func_ov024_021eda60(GameObject* combatant);

struct Struct_ov024_021ef6c4 { int field0; };
struct Struct_ov024_021feab4 { short v[4]; };
extern struct Struct_ov024_021feab4 data_ov024_021feab4;

struct Struct_ov024_021ef6c4_2 { signed int unknown_0_0_ : 3; signed int unknown_0_3_ : 3; signed int rest : 26; };

// USA: func_ov024_021ef6c4
extern "C" ARM int func_ov024_021ef6c4(struct Struct_ov024_021ef6c4* obj, int unused1, int arg2, int* outCount, short* arg4) {
    struct Struct_ov024_021feab4 buf = data_ov024_021feab4;

    int count = func_ov000_0215e9fc(obj->field0, buf.v, 4, 1);
    if (count <= 0) return 0;

    int matchCount = 0;
    for (int i = 0; i < count; i++) {
        GameObject* c = GetCombatantByID(obj->field0, buf.v[i]);
        if (!c) continue;
        if (*(unsigned short*)((char*)c->currentStats_ + 0xa) == 0) continue;
        struct Struct_ov024_021ef6c4_2* bits = (struct Struct_ov024_021ef6c4_2*)((char*)c->currentStats_ + 0x58);
        if (bits->unknown_0_3_ <= -2) continue;
        if (func_ov024_021eda60(c)) continue;
        int byteVal = *(unsigned char*)((char*)c->currentStats_ + 0x50);
        if (byteVal > 0) matchCount++;
    }

    if (matchCount * 3 < count * 2) return 0;

    *outCount = count;
    memcpy(arg4, buf.v, 8);
    return 1;
}
