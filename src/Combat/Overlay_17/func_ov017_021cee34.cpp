#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov017_021cee34_396 = 0x180 };
#else
enum { Enum_ov017_021cee34_396 = 0x18c };
#endif

#include "GameState/GameState.h"

struct Struct_ov017_021cee34 {
    unsigned char header[4];
    int combatantId;
    unsigned int mask;
    int enabled;
};

struct Struct_ov017_021cee34_2 {
    unsigned char unknown_0_[Enum_ov017_021cee34_396];
    unsigned int flags;
};

// USA: func_ov017_021cee34
extern "C" ARM void func_ov017_021cee34(void* unused, Struct_ov017_021cee34* args, GameState* battleStruct) {
    int enabled = args->enabled;
    unsigned int mask = args->mask;
    int id = args->combatantId;
    GameObject* combatant = func_0200ff1c(battleStruct, id);
    if (combatant == NULL) return;
    Struct_ov017_021cee34_2* status = (Struct_ov017_021cee34_2*)combatant;
    if (enabled) {
        status->flags |= mask;
    } else {
        status->flags &= ~mask;
    }
}
