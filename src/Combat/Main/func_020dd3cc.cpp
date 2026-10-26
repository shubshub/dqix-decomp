#include <globaldefs.h>
#if defined(jpn)
enum { Enum_020dd3cc_336 = 0x144, Enum_020dd3cc_2384 = 0x8b8 };
#else
enum { Enum_020dd3cc_336 = 0x150, Enum_020dd3cc_2384 = 0x950 };
#endif
#include "GameState/GameState.h"

extern "C" int func_02083b00(unsigned char* obj, int index);
extern "C" int func_020dd11c(unsigned int a, unsigned int b);
extern "C" int func_020dd300(int mask);
extern unsigned short data_020f29f4[];

// USA: func_020dd3cc
extern "C" ARM int func_020dd3cc(int combatantId) {
    GameState* gameState = GameState::GetInstance();
    GameObject* combatant = func_0200ff1c(gameState, combatantId);
    if (combatant == 0) {
        return 0;
    }
    unsigned int result = 0;
    for (unsigned short i = 0; i <= 0xb; i++) {
        if (func_02083b00(*(unsigned char**)((char*)combatant + Enum_020dd3cc_336), data_020f29f4[i])) {
            result |= 1u << i;
        }
    }
    unsigned char* obj = *(unsigned char**)((char*)combatant + Enum_020dd3cc_336);
    unsigned char a = (unsigned char)*(int*)(obj + Enum_020dd3cc_2384);
    for (unsigned char j = 0; j < 4; j++) {
        unsigned int v = func_020dd11c(a, j);
        if (v == 0) {
            continue;
        }
        if (v >= 1 && v <= 12) {
            result |= 1u << (unsigned char)(v - 1);
        }
    }
    for (unsigned int k = 0; k <= 0xb; k++) {
        unsigned int bit = 1u << k;
        if (result & bit) {
            unsigned int ret = func_020dd300(bit);
            if (ret == 0) {
                result &= ~bit;
            }
        }
    }
    return result;
}
