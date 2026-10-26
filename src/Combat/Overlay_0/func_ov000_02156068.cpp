#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" GameObject* func_0200fea4(GameState* battleStruct, int combatantId);

struct Struct_ov000_02156068 {
    char pad[0xa];
    unsigned short unknown_a_0_ : 7;
    unsigned short nibble : 4;
    unsigned short bit11 : 1;
    unsigned short unknown_b_4_ : 1;
    unsigned short rest : 3;
};

// USA: func_ov000_02156068
extern "C" ARM int func_ov000_02156068(int unused0, int id, int a2, int a3) {
    int flag = (id >= 0 && id <= 3);
    if (flag) {
        return 0;
    }
    GameState* bs = GameState::GetInstance();
    GameObject* c = func_0200fea4(bs, id);
    if (c == NULL) {
        return 0;
    }
    struct Struct_ov000_02156068* inner = *(struct Struct_ov000_02156068**)((char*)c + 0x144);
    if (inner == NULL) {
        return 0;
    }
    if (a3 > 0) {
        if (a3 == 1) {
            if (inner->unknown_b_4_) return 1;
        } else {
            if (inner->bit11) return 1;
        }
    } else {
        if (inner->nibble == a2) return 1;
    }
    return 0;
}
