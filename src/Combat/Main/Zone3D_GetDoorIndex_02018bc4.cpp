#include <globaldefs.h>
#include "World/ZoneChest.h"

// Main, originally FindMatchingElementIndex02018bc4 (USA 0x02018bc4, EUR 0x02018bd4, JPN 0x02018964)
ARM int Zone3D_GetDoorIndex(Zone3D* zone, ZoneFeatures::Opcode6aEntry* target) {
    ZoneFeatures::Opcode6aEntry* entry = GetElementStride0x74_0201e664(&zone->substruct_6c_, 0);
    int count = zone->substruct_6c_.arraySize6a_;
    int matches = 0;
    int i;
    for (i = 0; i < count; i++) {
        if (entry->maybeType == 2) {
            if (entry == target) return matches;
            matches++;
        }
        entry++;
    }
    return -1;
}
