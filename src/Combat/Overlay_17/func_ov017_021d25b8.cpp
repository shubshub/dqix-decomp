#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov017_021d25b8_396 = 0x180 };
#else
enum { Enum_ov017_021d25b8_396 = 0x18c };
#endif

#include "GameState/GameState.h"

struct Struct_ov017_021d25b8 {
    unsigned char header[4];
    unsigned char partyIndex;
    unsigned char unknown_5_[3];
    int enabled;
};

struct Struct_ov017_021cee34_2 {
    unsigned char unknown_0_[Enum_ov017_021d25b8_396];
    unsigned int flags;
};

// USA: func_ov017_021d25b8
extern "C" ARM void func_ov017_021d25b8(int unused, Struct_ov017_021d25b8* event, GameState* battleStruct) {
    GameObject* combatant = battleStruct->GetPartyMemberByIndex(event->partyIndex);
    if (combatant == NULL) return;
    Struct_ov017_021cee34_2* status = (Struct_ov017_021cee34_2*)combatant;
    if (event->enabled != 0) status->flags |= 8;
    else status->flags &= ~8;
}
