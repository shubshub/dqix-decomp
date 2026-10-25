#include <globaldefs.h>
#include "Graphics/Background.h"
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

// Main, originally AllocateAndClearBuffer0204b12c (USA 0x0204b12c, EUR 0x0204b13c, JPN 0x0204bf4c)
ARM void Background_AllocateMap(struct BackgroundGraphics* layer, SafeAllocator* alloc) {
    unsigned int size;
    unsigned short* map;
    if (alloc == NULL) return;
    size = Background_mapSizes[layer->mapType_][layer->mapSize_];
    map = (unsigned short*)alloc->Allocate(size);
    layer->map_ = map;
    memset(map, 0, size);
}
