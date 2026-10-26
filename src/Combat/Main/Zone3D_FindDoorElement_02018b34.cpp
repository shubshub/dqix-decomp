#include <globaldefs.h>
#include "World/ZoneChest.h"

// ZoneFeatures::Opcode6aEntry::maybeType of a door
enum { kDoorFeatureType = 2 };

// Main, originally FindEntryByNodeIdAndKey_02018b34 (USA 0x02018b34, EUR 0x02018b44, JPN 0x020188d4)
ARM BmdjSceneElement* Zone3D_FindDoorElement(Zone3D* zone, ZoneFeatures::Opcode6aEntry* door) {
    BmdjScriptNode* node;
    BmdjSceneElement* result;
    int count;
    int i;
    if (door->maybeType != kDoorFeatureType) return NULL;
    if (zone->unknown_424_ != 0) return NULL;
    node = zone->firstBMDJStruct_41c_;
    while (node != NULL) {
        if (node->unknown0 == door->unk_2c.type2.nodeId) break;
        node = node->next;
    }
    result = NULL;
    if (node == NULL) return result;
    count = node->scriptState.elementCount;
    for (i = 0; i < count; i++) {
        if (door->unk_2c.type2.elementId == node->elements[i].id) {
            result = &node->elements[i];
            break;
        }
    }
    return result;
}
