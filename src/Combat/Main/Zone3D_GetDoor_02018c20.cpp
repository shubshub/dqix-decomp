#include <globaldefs.h>
#include "World/ZoneChest.h"

// ZoneFeatures::Opcode6aEntry::maybeType of a door
enum { kDoorFeatureType = 2 };

// Main, originally FindNthType2Entry02018c20 (USA 0x02018c20, EUR 0x02018c30, JPN 0x020189c0)
ARM ZoneFeatures::Opcode6aEntry* Zone3D_GetDoor(Zone3D* zone, int doorIndex) {
    ZoneFeatures::Opcode6aEntry* feature = ZoneFeatures_GetEntry(&zone->substruct_6c_, 0);
    int count = zone->substruct_6c_.arraySize6a_;
    int i;
    for (i = 0; i < count; i++) {
        if (feature->maybeType == kDoorFeatureType) {
            if (doorIndex == 0) return feature;
            doorIndex--;
        }
        feature++;
    }
    return NULL;
}
