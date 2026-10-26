#include <globaldefs.h>
#include "World/BmdjScriptNode.h"
#include "std_library_functions.h"

// Main, originally Reset02013490 (USA 0x02013490, EUR 0x020134a0, JPN 0x02013258)
extern "C" ARM void GrottoTileMapRecord_Reset(GrottoTileMapRecord* record) {
    record->node = NULL;
    record->angle = 0;
    record->info.unknown_0_ = 0;
    memset(record->info.directionBitmasks, 0, sizeof(record->info.directionBitmasks));
    memset(record->info.tilename, 0, sizeof(record->info.tilename));
    Mat3x3_WriteIdentity(&record->rotation);
    record->position.x = 0;
    record->position.y = 0;
    record->position.z = 0;
}
