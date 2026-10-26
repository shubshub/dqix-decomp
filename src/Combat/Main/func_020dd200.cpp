#include <globaldefs.h>

#if defined(jpn)
enum { Enum_020dd200_336 = 0x144 };
#else
enum { Enum_020dd200_336 = 0x150 };
#endif

#include "GameState/GameState.h"

extern "C" int func_02083b00(unsigned char* obj, int index);

struct Struct_020ee710 { unsigned short a; unsigned short b; };
extern Struct_020ee710 data_020ee712[];
extern Struct_020ee710 data_020ee710[];

// USA: func_020dd200
extern "C" ARM int func_020dd200(int combatantId, int category) {
    int result = 0;
    GameState* battleStruct = GameState::GetInstance();
    GameObject* combatant = func_0200ff1c(battleStruct, combatantId);
    if (combatant == 0) {
        return result;
    }
    unsigned char idx = 0;
    while (data_020ee710[idx].a != 0xffff) {
        unsigned int var4 = data_020ee712[idx].a & 0xff;
        if (var4 == category) {
            if (func_02083b00(*(unsigned char**)((char*)combatant + Enum_020dd200_336), data_020ee710[idx].a) != 0) {
                result = 1;
            }
            break;
        }
        idx++;
    }
    return result;
}
