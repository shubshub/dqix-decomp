#include <globaldefs.h>
#include "World/ZoneChest.h"


extern "C" void* Scenario_GetInstance();

// ZoneFeatures::Opcode6aEntry type2 flags (DoorFlag) the header doesn't name yet: a door to another zone
// (func_ov017_02198f84), and one shown already open (Zone3D_OpenDoor skips the turn)
enum {
    kDoorFlag_Exit = 0x8,
    kDoorFlag_OpenInstantly = 0x100,
};

// The door mask has one bit per door index (Zone3D_GetDoorIndex), as the zone record and pendingType2Mask_ keep it
enum { kDoorMaskBits = 16 };

// Main, originally UpdateFlaggedType2Entries02018c74 (USA 0x02018c74, EUR 0x02018c84, JPN 0x02018a14)
extern "C" ARM void Zone3D_OpenDoorsByMask(Zone3D* zone, unsigned int doorMask) {
    Scenario_GetInstance();
    int i;
    for (i = 0; i < kDoorMaskBits; i++) {
        if (doorMask & (1 << i)) {
            ZoneFeatures::Opcode6aEntry* door = Zone3D_GetDoor(zone, i);
            if (door) {
                if (!(door->unk_2c.type2.flags & kDoorFlag_Exit)) {
                    door->unk_2c.type2.flags = door->unk_2c.type2.flags | (kDoorFlag_OpenInstantly | DoorFlag_Open);
                }
                Zone3D_OpenDoor(zone, door, 0, 0, 0);
            }
        }
    }
    zone->unknown_281e_ = 0;
}
