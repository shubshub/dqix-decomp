#include <globaldefs.h>
#include "Graphics/Background.h"

// Main, originally func_0204b088 (USA 0x0204b088, EUR 0x0204b098, JPN 0x0204bea8)
extern "C" ARM void Background_TransferMap(BackgroundGraphics* layer, void* map) {
    if (!map) map = layer->map_;
    if (!map) return;
    unsigned int subScreen = layer->subScreen_;
    unsigned int bgNumber = layer->bgNumber_;
    unsigned int mapType = layer->mapType_;
    unsigned int mapSize = layer->mapSize_;
    unsigned int size = Background_mapSizes[mapType][mapSize];
    BackgroundLoadFunction load = Background_loadScreenFunctions[subScreen][bgNumber];
    layer = (BackgroundGraphics*)map;
    load(layer, 0, size);
}
