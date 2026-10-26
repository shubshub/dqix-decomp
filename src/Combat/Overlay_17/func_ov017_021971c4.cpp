#if defined(jpn)
enum { Enum_ov017_021971c4_434 = 0x1a6, Enum_ov017_021971c4_17408 = 0x4200, Enum_ov017_021971c4_194 = 0x12 };
#else
enum { Enum_ov017_021971c4_434 = 0x1b2, Enum_ov017_021971c4_17408 = 0x4400, Enum_ov017_021971c4_194 = 0xc2 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* __clear(void* dst, int count);

struct U16Field0x6_020375f8;

extern "C" int func_ov017_02196fc8(GameObject* self, GameObject* other, int extra);

struct Party021971c4 {
    char pad[0xf78];
    unsigned char ids[4];
    unsigned char count;
};

// USA: func_ov017_021971c4
extern "C" ARM unsigned short func_ov017_021971c4(unsigned char* ov) {
    GameState* battleStruct = GameState::GetInstance();
    if (battleStruct == NULL) {
        return 0;
    }
    GameObject* combatant = battleStruct->GetLeader();
    if (combatant == NULL) {
        return 0;
    }
    struct Party021971c4* party = (struct Party021971c4*)GameState_GetParty(battleStruct);
    int flags[4];
    unsigned short result = 0;
    __clear(flags, 0x10);
    int i;
    for (i = 0; i < party->count; i++) {
        flags[party->ids[i]] = 1;
    }
    int j;
    for (j = 0; j < 4; j++) {
        if (flags[j] != 0) {
            continue;
        }
        GameObject* other = func_0200ff1c(battleStruct, j);
        if (other == NULL) {
            continue;
        }
        if (((Object3D*)((struct U16Field0x6_020375f8*)other))->GetField06() != ((Object3D*)((struct U16Field0x6_020375f8*)combatant))->GetField06()) {
            continue;
        }
        if (*((unsigned char*)other + 0xbe) != 2) {
            continue;
        }
        if (func_ov017_02196fc8(combatant, other, 0x1000)) {
            unsigned short v = *(unsigned short*)((unsigned char*)other + Enum_ov017_021971c4_434);
            if (*(unsigned short*)(ov + Enum_ov017_021971c4_17408 + Enum_ov017_021971c4_194) != v) {
                result = v;
                break;
            }
        }
    }
    return result;
}
