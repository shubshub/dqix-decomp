#include <globaldefs.h>
#include "Resource/GameResources.h"

struct Struct_ov017_0218f064_6;
struct Struct_ov017_021a11b4 {
    short combatantId;
    unsigned short slotIndex;
};

// USA: func_ov017_021a11b4
extern "C" ARM void* func_ov017_021a11b4(Struct_ov017_0218f064_6* arg0) {
    GameResources* resources = (GameResources*)arg0;
    for (int slot = 0; slot < 4; ++slot) {
        Struct_ov017_021a11b4* header = (Struct_ov017_021a11b4*)resources->substruct_array_12c8[slot].unknown_0;
        if (header->combatantId < 0) return &resources->substruct_array_12c8[slot];
    }
    return NULL;
}
