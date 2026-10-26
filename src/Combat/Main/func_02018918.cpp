#include <globaldefs.h>
#include "World/ZoneChest.h"
#include "Graphics/Vector.h"

struct Struct_020fdd44 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
    char unknown_6_[0x318 - 6];
};
Entry_02028bd0* ZoneRecords_GetInstance();
Entry_02028bd0* ZoneRecords_Find(Entry_02028bd0*, int);

// USA: func_02018918
extern "C" ARM void func_02018918(Zone3D* owner, ZoneFeatures::Opcode6aEntry* parameter) {
    BmdjSceneElement* entry = Zone3D_FindDoorElement(owner, parameter);
    if (entry) {
        entry->flags &= ~BmdjElementFlag_Open;
        entry->flags &= ~BmdjElementFlag_Hidden;
        for (int i = 0; i < owner->terrainElementCount_; ++i) {
            BmdjSceneElement* linked = owner->terrainElements_[i];
            if (linked->parent == entry) {
                linked->flags &= ~BmdjElementFlag_Open;
                break;
            }
        }
        if (parameter->unk_2c.type2.flags & DoorFlag_Slides) {
            short angle = fix32ReduceAngle0To2Pi((short)(parameter->angle + 0x1922));
            int cosine = fix32cos(angle);
            Vector3fix displacement;
            displacement.x = fix32sin(angle);
            displacement.y = 0;
            displacement.z = cosine;
            Vector3fix_Normalize(&displacement, &displacement);
            Vector3fixMultiplyScalar(&displacement, -parameter->unk_2c.type2.slideDistance, &displacement);
            Vector3fix direction;
            Vector3fix_Normalize(&displacement, &direction);
            entry->direction = direction;
            Vector3fix position;
            Vector3fix_Add(&entry->position, &displacement, &position);
            entry->position = position;
        }
        parameter->unk_2c.type2.flags &= ~DoorFlag_Open;
        owner->unk_830[0] = 15;
        if (!(parameter->unk_2c.type2.flags & 8)) {
            int index = Zone3D_GetDoorIndex(owner, parameter);
            Entry_02028bd0* saved = ZoneRecords_Find(ZoneRecords_GetInstance(), owner->currentZoneID_);
            if (saved) saved->activeMask &= ~(1 << index);
        }
    }
}
