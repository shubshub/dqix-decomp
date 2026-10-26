#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_0207c5f8(unsigned char* obj, unsigned int index);

struct Struct_02054000;
extern "C" void* func_02054000(struct Struct_02054000* p);

extern short data_020e8a34[];

// USA: func_0207c984
extern "C" ARM int func_0207c984(unsigned char* obj, int combatantId, int arg2, short* arg3, short* outCount) {
    GameObject* combatant = func_0200ff1c(GameState::GetInstance(), combatantId);
    if (combatant == 0) {
        return 1;
    }

    void* sub = func_02054000((struct Struct_02054000*)combatant);
    short special = -1;
    if (sub != 0) {
        unsigned int packed = *(unsigned int*)((char*)sub + 0x8);
        unsigned int bits = (packed << 23) >> 27;
        if (bits <= 11) {
            special = *(short*)((char*)sub + 0x18);
        }
    }

    short count = 0;
    short target = data_020e8a34[arg2];
    if (special > 0) {
        if ((short)(special - special % 100) == target) {
            arg3[count++] = special;
        }
    }

    short* arr = (short*)func_0207c5f8(obj, 0);
    short i;
    for (i = 0; i < 0x110; i++) {
        short v = arr[i];
        if (v != special) {
            if ((short)(v - v % 100) == target) {
                arg3[count] = v;
                count = count + 1;
            }
        }
    }

    *outCount = count;
    return 0;
}
