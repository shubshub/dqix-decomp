#include <globaldefs.h>
#include "World/ZoneWarpScript.h"

// Main, originally WarpScript_Opcode_70_0201d4ec (USA 0x0201d4ec, EUR 0x0201d4fc, JPN 0x0201d278)
extern "C" ARM int ZoneFeaturesScript_SetClearColor(Script::Parameter* params, int) {
    int red = params[0].ToInt();
    int green = params[1].ToInt();
    int blue = params[2].ToInt();
    data_020fdc20.warp->color_7e_ = red | (green << 5) | (blue << 10);
    return 1;
}
