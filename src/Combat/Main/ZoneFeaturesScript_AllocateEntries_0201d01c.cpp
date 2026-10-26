#include <globaldefs.h>
#include "World/ZoneWarpScript.h"

// Main, originally WarpScript_Opcode_6a_0201d01c (USA 0x0201d01c, EUR 0x0201d02c, JPN 0x0201cda8)
extern "C" ARM int ZoneFeaturesScript_AllocateEntries(Script::Parameter* params, int) {
    data_020fdc20.warp->AllocateOpcode6aEntries(params->ToInt(), data_020fdc20.allocator);
    return 1;
}
