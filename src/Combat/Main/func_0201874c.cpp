#include <globaldefs.h>
#include "World/ZoneChest.h"
#include <Graphics/Vector.h>

struct Struct_020fdd44 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
};
Entry_02028bd0* ZoneRecords_GetInstance();
Entry_02028bd0* ZoneRecords_Find(Entry_02028bd0*, int);

// USA: func_0201874c
extern "C" ARM void func_0201874c(Zone3D* owner, ZoneFeatures::Opcode6aEntry* parameter) {
    BmdjSceneElement* entry = Zone3D_FindDoorElement(owner, parameter);
    if (!entry) return;
    entry->flags &= ~BmdjElementFlag_Open;
    entry->flags &= ~BmdjElementFlag_Hidden;
    for (int i = 0; i < owner->terrainElementCount_; i++) {
        BmdjSceneElement* linked = owner->terrainElements_[i];
        if (linked->parent == entry) {
            linked->flags &= ~BmdjElementFlag_Open;
            break;
        }
    }
    if (parameter->unk_2c.type2.flags & DoorFlag_Slides) {
        Vector3fix target;
        Vector3fix offset;
        Vector3fixMultiplyScalar(&entry->direction, parameter->unk_2c.type2.slideDistance, &offset);
        Vector3fix_Add(&entry->position, &offset, &target);
        entry->direction.x = -entry->direction.x;
        entry->direction.y = -entry->direction.y;
        entry->direction.z = -entry->direction.z;
        entry->destination = target;
        entry->movementSpeed = 0x266;
    } else {
        if (parameter->unk_2c.type2.flags & DoorFlag_TurnBackward) entry->destinationAngle = 128.68f + entry->angle;
        else entry->destinationAngle = entry->angle - 128.68f;
        entry->rotationSpeed = 0x199;
        entry->state = 0x1f;
        entry->flags |= 0x80;
    }
    parameter->unk_2c.type2.flags &= ~DoorFlag_Open;
    owner->unk_830[0] = 0xf;
    if (!(parameter->unk_2c.type2.flags & 8)) {
        int index = Zone3D_GetDoorIndex(owner, parameter);
        Entry_02028bd0* table = ZoneRecords_GetInstance();
        Entry_02028bd0* saved = ZoneRecords_Find(table, owner->currentZoneID_);
        if (saved) saved->activeMask &= ~(1 << index);
    }
}
