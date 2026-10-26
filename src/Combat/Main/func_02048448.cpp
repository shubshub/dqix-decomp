#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_02053c6c(unsigned char* obj);
extern "C" int func_02083b00(unsigned char* obj, int index);

struct Struct_02048448 {
    char pad[0x6];
    unsigned short value;
};

struct Struct_02048448_2 {
    char pad[0x4];
    short combatantId;
    char pad2[0x130 - 0x6];
    struct Struct_02048448* threshold;
};

// USA: func_02048448
extern "C" ARM int func_02048448(struct Struct_02048448_2* s, int val) {
    GameState* bs = GameState::GetInstance();
    GameObject* combatant = func_0200ff1c(bs, s->combatantId);
    if (combatant != NULL) {
        unsigned char* ptr = (unsigned char*)func_02053c6c((unsigned char*)combatant);
        if (ptr != NULL) {
            if (func_02083b00(ptr, 0x106)) {
                val = (int)(0.75f + 0.75f * (float)val);
                if (val <= 0) {
                    val = 0;
                }
            }
        }
    }
    return val <= s->threshold->value ? 1 : 0;
}
