#include <globaldefs.h>
#include "World/ZoneChest.h"

extern "C" void* Zone3D_GetInstance(void);
struct Entry_02028bd0;
struct Entry_02028bd0* ZoneRecords_GetInstance(void);
struct Entry_02028bd0* ZoneRecords_Find(struct Entry_02028bd0* base, int key);

struct Obj02028c64;
void ZoneRecord_SetDoorOpened(struct Obj02028c64* obj, int index);

struct Rec021d19b0 {
    unsigned char pad0[4];
    unsigned short field4;
    unsigned short field6;
    unsigned int field8;
};

// USA: func_ov017_021d19b0
ARM void HandleType2OrEntry_021d19b0(int unused, struct Rec021d19b0* rec) {
    Zone3D* zone = (Zone3D*)Zone3D_GetInstance();
    if (rec->field4 == zone->currentZoneID_) {
        ZoneFeatures::Opcode6aEntry* e = Zone3D_GetDoor(zone, rec->field6);
        if (e == NULL)
            return;
        Zone3D_OpenDoor(zone, e, rec->field8, 0, 0);
    } else {
        struct Entry_02028bd0* table = ZoneRecords_GetInstance();
        struct Entry_02028bd0* entry = ZoneRecords_Find(table, rec->field4);
        if (entry == NULL)
            return;
        ZoneRecord_SetDoorOpened((struct Obj02028c64*)entry, rec->field6);
    }
}
