#include <globaldefs.h>

#include "World/ZoneResourceInitialization.h"
#include <globaldefs.h>

// Main, originally func_02014a24 (USA 0x02014a24, EUR 0x02014a34, JPN 0x020147f0)
extern "C" ARM int Zone3D_SetUpScriptNode(Zone3D *zone, void *data) {
    Struct_02014a24_2 *node   = static_cast<Struct_02014a24_2 *>(data);
    int count                = node->elementCount;
    SafeAllocator *allocator = zone->pAllocator_68_;
    node->trackers           = static_cast<Struct02012ff0 *>(allocator->Allocate(count * sizeof(Struct02012ff0)));
    if (node->trackers == NULL) return 0;

    for (int index = 0; index < count; index++) {
        Src02015134 *source =
            static_cast<Src02015134 *>(BmdjScriptState_GetResourceRecord(reinterpret_cast<unsigned char *>(&node->records), index));
        Struct02012ff0 *trackers = node->trackers;
        BmdjElementResource_Init(trackers + index);
        if (source != NULL) {
            if (reinterpret_cast<char *>(source->id)[3] == 'A') {
                Zone3D_LoadElementTerrainMesh(zone, trackers + index, source);
            } else if (static_cast<unsigned char>(source->pad[2]) & 0x10) {
                Zone3D_LoadElementObject(zone, trackers + index, source);
            } else {
                Zone3D_LoadElementModel(zone, node, trackers + index, source);
            }
        }
    }
    Zone3D_BuildSceneElements(zone, node, allocator);
    return 1;
}
