#include <globaldefs.h>
#include "World/ZoneChest.h"

extern "C" void* ZoneFeatures_GetFirstOfType(unsigned char*, unsigned int);

// ZoneFeatures::Opcode6aEntry::maybeType of a door
enum { kDoorFeatureType = 2 };

// ZoneFeatures::Opcode6aEntry type2 flag (DoorFlag) the header doesn't name yet: the door stays visible once open
enum { kDoorFlag_StaysVisible = 0x80 };

// BmdjSceneElement::flags bits: the element is a door's (Zone3D_DrawSceneElements then draws it with its alpha), and it stays
// visible after turning open (BmdjSceneElement_Update stops it instead of fading it out)
enum {
    kElementFlag_Door = 0x8,
    kElementFlag_StaysVisible = 0x10,
};

// Main, originally UpdateEntryFlagsForNodeList_02018ab8 (USA 0x02018ab8, EUR 0x02018ac8, JPN 0x02018858)
extern "C" ARM void Zone3D_MarkDoorElements(Zone3D* zone) {
    ZoneFeatures::Opcode6aEntry* door;
    BmdjSceneElement* element;
    int staysVisible;

    door = (ZoneFeatures::Opcode6aEntry*)ZoneFeatures_GetFirstOfType((unsigned char*)&zone->substruct_6c_, kDoorFeatureType);
    while (door != NULL) {
        element = Zone3D_FindDoorElement(zone, door);
        staysVisible = (door->unk_2c.type2.flags & kDoorFlag_StaysVisible) != 0;
        if (element != NULL) {
            element->flags |= kElementFlag_Door;
            if (staysVisible) element->flags |= kElementFlag_StaysVisible;
        }
        door = door->pNext;
    }
}
