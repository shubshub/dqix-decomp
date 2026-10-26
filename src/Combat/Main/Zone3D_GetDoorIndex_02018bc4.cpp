#include <globaldefs.h>
#include "World/ZoneChest.h"

// ZoneFeatures::Opcode6aEntry::maybeType of a door
enum { kDoorFeatureType = 2 };

// Main, originally FindMatchingElementIndex02018bc4 (USA 0x02018bc4, EUR 0x02018bd4, JPN 0x02018964)
extern "C" ARM int Zone3D_GetDoorIndex(Zone3D* zone, ZoneFeatures::Opcode6aEntry* door) {
    ZoneFeatures::Opcode6aEntry* feature = ZoneFeatures_GetEntry(&zone->substruct_6c_, 0);
    int count = zone->substruct_6c_.arraySize6a_;
    int doorIndex = 0;
    int i;
    for (i = 0; i < count; i++) {
        if (feature->maybeType == kDoorFeatureType) {
            if (feature == door) return doorIndex;
            doorIndex++;
        }
        feature++;
    }
    return -1;
}
