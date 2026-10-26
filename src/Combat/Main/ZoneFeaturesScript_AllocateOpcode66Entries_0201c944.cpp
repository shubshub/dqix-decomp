#include <globaldefs.h>
#include "World/ZoneWarpScript.h"

// Main, originally WarpScript_Opcode_66_0201c944 (USA 0x0201c944, EUR 0x0201c954, JPN 0x0201c6d0)
extern "C" ARM int ZoneFeaturesScript_AllocateOpcode66Entries(Script::Parameter* params, int) {
    int count = params->ToInt();
    data_020fdc20.warp->AllocateOpcode66Entries(count, data_020fdc20.allocator);
    return 1;
}
