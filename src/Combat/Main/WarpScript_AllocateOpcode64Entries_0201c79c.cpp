#include "World/ZoneWarpScript.h"
#include <globaldefs.h>

// Main, originally WarpScript_Opcode_64_0201c79c (USA 0x0201c79c, EUR 0x0201c7ac, JPN 0x0201c528)
extern "C" ARM int WarpScript_AllocateOpcode64Entries(Script::Parameter* params, int) {
    int count = params->ToInt();
    data_020fdc20.warp->AllocateOpcode64Entries(count, data_020fdc20.allocator);
    return 1;
}
