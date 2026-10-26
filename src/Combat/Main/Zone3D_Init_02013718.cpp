#include <globaldefs.h>
#include "World/Zone3D.h"

extern "C" void Zone3D_Reset(void* obj);

// Main, originally InitStruct02013718 (USA 0x02013718, EUR 0x02013728, JPN 0x020134e0)
ARM void Zone3D_Init(char* obj, int allocator, int vramState) {
    Zone3D* zone = (Zone3D*)obj;
    Zone3D_Reset(obj);
    zone->pAllocator_4c_ = (SafeAllocator*)allocator;
    zone->vramState_ = (void*)vramState;
    zone->textureImageMemory_ = 0;
    zone->texturePaletteMemory_ = 0;
    zone->unknown_474_ = 0;
    zone->terrainElementCount_ = 0;
}
