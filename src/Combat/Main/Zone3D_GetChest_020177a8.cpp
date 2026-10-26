#include <globaldefs.h>
#include "World/Zone3D.h"

// Main, originally GetElementStride0x24_020177a8 (USA 0x020177a8, EUR 0x020177b8, JPN 0x02017548)
extern "C" ARM ZoneChestRenderRecord* Zone3D_GetChest(unsigned char* zoneBytes, int index) {
    Zone3D* zone = (Zone3D*)zoneBytes;
    if (index < 0 || zone->numChests_ <= index) {
        return NULL;
    }
    return &zone->chests_[index];
}
