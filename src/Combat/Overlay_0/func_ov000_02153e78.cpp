#include <globaldefs.h>
#include "GameState/GameState.h"

struct S_10088;
extern "C" int func_02010088(struct S_10088* obj);
extern "C" int func_ov000_02153c0c(GameObject* combatant);
extern "C" GameObject* func_0200fea4(GameState* battleStruct, int combatantId);

struct Struct_ov000_02153e78 {
    char pad0[0x17c];
    unsigned char unknown_17c_;
};

struct Struct_ov000_02153e78_2 {
    char pad0[2];
    unsigned char memberIds[8];
    unsigned char memberCount : 4;
    char unknown_b_[0x18 - 0xb];
};

struct Struct_ov000_02153e78_3 {
    char pad0[0x81b1];
    unsigned char : 4;
    unsigned char groupCount : 2;
    char unknown_81b2_[0x81b4 - 0x81b2];
    struct Struct_ov000_02153e78_2 groups[1];
};

// USA: func_ov000_02153e78
extern "C" ARM int func_ov000_02153e78(struct Struct_ov000_02153e78_3* battle, short* out, int max, int arg3, int flags) {
    GameState* bs = GameState::GetInstance();
    int found = 0;
    struct Struct_ov000_02153e78_2* groups = battle->groups;
    int g;
    for (g = 0; g < battle->groupCount; g++) {
        unsigned char* ids = groups[g].memberIds;
        int i;
        for (i = 0; i < groups[g].memberCount; i++) {
            GameObject* c = func_0200fea4(bs, ids[i] + 0xc0);
            if (c == NULL) continue;
            if (arg3 != ((struct Struct_ov000_02153e78*)c)->unknown_17c_) continue;
            if (!(flags & 0x10) && func_ov000_02153c0c(c)) continue;
            if ((flags & 1) && func_02010088((struct S_10088*)c)) continue;
            out[found] = ids[i] + 0xc0;
            found++;
            if (found == max) return found;
        }
    }
    return found;
}
