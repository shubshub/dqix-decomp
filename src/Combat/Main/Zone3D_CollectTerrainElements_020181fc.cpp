#include <globaldefs.h>
#include "World/Zone3D.h"

// BmdjElementResource::kind of a terrain mesh (Zone3D_SetUpScriptNode's Zone3D_LoadElementTerrainMesh sets it up)
enum { kElementResource_Terrain = 1 };

// A grotto floor's terrain elements: its 16 x 16 tiles (grottoTileMapData_420_), then the up stairs
// (Zone3D_CollectTerrainPolygons)
enum { kGrottoTileCount = 16 * 16 };

// Main, originally CollectMatchingElems020181fc (USA 0x020181fc, EUR 0x0201820c, JPN 0x02017f9c)
ARM void Zone3D_CollectTerrainElements(void* zoneBytes) {
    Zone3D* zone = (Zone3D*)zoneBytes;
    zone->terrainElementCount_ = 0;
    if (zone->isInMainGrottoFloor_23b8_) {
        zone->terrainElementCount_ = kGrottoTileCount + 1;
        return;
    }

    BmdjScriptNode* node = zone->firstBMDJStruct_41c_;
    while (node != NULL) {
        int count = node->scriptState.elementCount;
        for (int i = 0; i < count; i++) {
            BmdjSceneElement* element = &node->elements[i];
            BmdjElementResource* resource = element->resource;
            if (resource != NULL && *(short*)resource == kElementResource_Terrain) {
                zone->terrainElementCount_++;
            }
        }
        node = node->next;
    }

    SafeAllocator* allocator = zone->pAllocator_68_;
    BmdjSceneElement** terrainElements = (BmdjSceneElement**)allocator->Allocate((unsigned int)zone->terrainElementCount_ * 4);
    zone->terrainElements_ = terrainElements;

    int terrainIndex = 0;
    node = zone->firstBMDJStruct_41c_;
    while (node != NULL) {
        int count = node->scriptState.elementCount;
        for (int i = 0; i < count; i++) {
            BmdjSceneElement* element = &node->elements[i];
            BmdjElementResource* resource = element->resource;
            if (resource != NULL && *(short*)resource == kElementResource_Terrain) {
                zone->terrainElements_[terrainIndex] = element;
                terrainIndex++;
            }
        }
        node = node->next;
    }
}
