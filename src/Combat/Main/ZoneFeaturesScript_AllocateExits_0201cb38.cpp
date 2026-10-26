#include <globaldefs.h>
#include "World/ZoneWarpScript.h"

// Main, originally WarpScript_Opcode_68_0201cb38 (USA 0x0201cb38, EUR 0x0201cb48, JPN 0x0201c8c4)
extern "C" ARM int ZoneFeaturesScript_AllocateExits(Script::Parameter* params, int) {
    data_020fdc20.warp->AllocateExits(params->ToInt(), data_020fdc20.allocator);
    return 1;
}
