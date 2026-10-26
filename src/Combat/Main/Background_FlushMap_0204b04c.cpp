#include <globaldefs.h>
#include "Graphics/Background.h"

void CleanInvalidateCacheRange(const void* addr, unsigned int size);

static inline unsigned int inline_0204b04c(unsigned int mapType, unsigned int mapSize) {
    return Background_mapSizes[mapType][mapSize];
}

// Main, originally func_0204b04c (USA 0x0204b04c, EUR 0x0204b05c, JPN 0x0204be6c)
extern "C" ARM void Background_FlushMap(BackgroundGraphics* layer, void* map) {
    if (map == NULL) map = layer->map_;
    if (map == NULL) return;
    CleanInvalidateCacheRange(map, inline_0204b04c(layer->mapType_, layer->mapSize_));
}
