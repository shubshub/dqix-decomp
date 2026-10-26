#include <globaldefs.h>
#include "GameState/GameState.h"

struct S_10088;
extern "C" int func_02010088(struct S_10088* obj);
extern "C" int func_ov000_02153c0c(GameObject* combatant);

struct Struct_ov000_0215ec80 {
    unsigned short field_0x0;
    unsigned char ids[8];
    unsigned char total : 4;
    unsigned char matched : 4;
    unsigned char pad[0x18 - 0xb];
};

struct Struct_ov000_0215ec80_2 {
    unsigned char pad[0x81b4];
    struct Struct_ov000_0215ec80 groups[1];
};

// USA: func_ov000_0215ec80
extern "C" ARM int func_ov000_0215ec80(struct Struct_ov000_0215ec80_2* obj, short* out, int maxCount, int arg3, int flags) {
    int count = 0;
    int i;
    for (i = 0; i < obj->groups[arg3].total; i++) {
        short id = (short)(obj->groups[arg3].ids[i] + 0xc0);
        GameObject* c = GameState::GetInstance()->GetCombatantByIndex(id);
        if (c == NULL) continue;
        if (func_ov000_02153c0c(c)) continue;
        if ((flags & 1) && func_02010088((struct S_10088*)c)) continue;
        out[count++] = id;
        if (count == maxCount) return count;
    }
    return count;
}
