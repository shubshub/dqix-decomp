#include <globaldefs.h>
#include "World/ZoneChest.h"


extern "C" void* Scenario_GetInstance();

// Main, originally UpdateFlaggedType2Entries02018c74 (USA 0x02018c74, EUR 0x02018c84, JPN 0x02018a14)
ARM void Zone3D_OpenDoorsByMask(Zone3D* zone, unsigned int flags) {
    Scenario_GetInstance();
    int i;
    for (i = 0; i < 16; i++) {
        if (flags & (1 << i)) {
            ZoneFeatures::Opcode6aEntry* record = FindNthType2Entry02018c20(zone, i);
            if (record) {
                if (!(record->unk_2c.type2.flags & 8)) {
                    record->unk_2c.type2.flags = record->unk_2c.type2.flags | 0x101;
                }
                Zone3D_OpenDoor(zone, record, 0, 0, 0);
            }
        }
    }
    zone->unknown_281e_ = 0;
}
