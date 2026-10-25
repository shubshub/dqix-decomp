#include <globaldefs.h>
#include "Graphics/Background.h"
#include "std_library_functions.h"

// Main, originally ClearBuffer0204b010 (USA 0x0204b010, EUR 0x0204b020, JPN 0x0204be30)
ARM void Background_ClearMap(BackgroundGraphics* layer, void* map) {
    if (map == NULL) map = layer->map_;
    if (map == NULL) return;
    memset(map, 0, Background_mapSizes[layer->mapType_][layer->mapSize_]);
}
