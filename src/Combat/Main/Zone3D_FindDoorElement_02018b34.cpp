#include <globaldefs.h>
#include "World/ZoneChest.h"

// Main, originally FindEntryByNodeIdAndKey_02018b34 (USA 0x02018b34, EUR 0x02018b44, JPN 0x020188d4)
ARM BmdjSceneElement* Zone3D_FindDoorElement(Zone3D* zone, ZoneFeatures::Opcode6aEntry* parameter) {
    BmdjScriptNode* node;
    BmdjSceneElement* result;
    int count;
    int i;
    if (parameter->maybeType != 2) return NULL;
    if (zone->unknown_424_ != 0) return NULL;
    node = zone->firstBMDJStruct_41c_;
    while (node != NULL) {
        if (node->unknown0 == parameter->unk_2c.type2.nodeId) break;
        node = node->next;
    }
    result = NULL;
    if (node == NULL) return result;
    count = node->scriptState.elementCount;
    for (i = 0; i < count; i++) {
        if (parameter->unk_2c.type2.elementId == node->elements[i].id) {
            result = &node->elements[i];
            break;
        }
    }
    return result;
}
