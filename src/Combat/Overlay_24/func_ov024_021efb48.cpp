#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "Util/Random.h"

extern "C" int func_ov000_0215ec80(int battle, short* buf, int max, int group, int extra);
extern "C" int func_ov024_021eda60(GameObject* combatant);

struct Struct_ov024_021efb48 {
    unsigned char b0;
    unsigned char lo : 4;
    unsigned char groupCount : 2;
};
struct Struct_ov024_021efb48_2 { int field0; };
struct Struct_ov024_021fea1c_5 { short v[3]; };
struct Struct_ov024_021fed7c { short v[8]; };
extern struct Struct_ov024_021fea1c_5 data_ov024_021fea1c[4];
extern struct Struct_ov024_021fed7c data_ov024_021fed7c;

// USA: func_ov024_021efb48
extern "C" ARM int func_ov024_021efb48(struct Struct_ov024_021efb48_2* obj, int unused1, int arg2, int* outCount, short* arg4) {
    struct Struct_ov024_021efb48* group = (struct Struct_ov024_021efb48*)(obj->field0 + 0x81b0);
    if (!group) return 0;

    struct Struct_ov024_021fea1c_5 var1 = data_ov024_021fea1c[2];
    short var2 = 0;
    for (int g = 0; g < group->groupCount; g++) {
        struct Struct_ov024_021fed7c buf = data_ov024_021fed7c;
        int count = func_ov000_0215ec80(obj->field0, buf.v, 8, g & 0xff, 1);
        if (count <= 0) continue;
        short matched = 0;
        for (int i = 0; i < count; i++) {
            GameObject* c = GetCombatantByID(obj->field0, buf.v[i]);
            if (!c) continue;
            if (c->currentStats_->primaryStats.agility >= 999) continue;
            if (c->currentStats_->agilityBuff >= 2) continue;
            if (!func_ov024_021eda60(c)) matched++;
        }
        if (matched > 0) var1.v[var2++] = g;
    }
    if (var2 <= 0) return 0;

    int pick = NextRandomMax((struct Random*)obj->field0, var2);
    *outCount = func_ov000_0215ec80(obj->field0, arg4, 8, var1.v[pick] & 0xff, 1);
    return 1;
}
