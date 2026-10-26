#include <globaldefs.h>
#include "std_library_functions.h"
#include "World/ZoneWarpScript.h"

// USA: func_0201c8d0
extern "C" ARM int func_0201c8d0(Script::Parameter* src, int numParams) {
    TileFeaturePlacementData elem;
    elem.unknown_0_ = src->ToInt();
    Script::Parameter* var1 = src + 1;
    src += 2;
    strcpy(elem.tilename, var1->ToString());
    int i;
    for (i = 0; i < 9; i++) {
        elem.directionBitmasks[i] = src->ToInt();
        src++;
    }
    data_020fdc20.warp->func_0201e3c4(elem);
    return 1;
}
