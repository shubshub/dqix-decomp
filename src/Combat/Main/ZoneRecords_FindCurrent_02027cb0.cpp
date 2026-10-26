#include <globaldefs.h>

// Points at Zone3D, whose first field is currentZoneID_
extern "C" unsigned short* Zone3D_GetInstance(void);

struct Entry_02028bd0;
extern struct Entry_02028bd0 data_020fdd44;
struct Entry_02028bd0* ZoneRecords_Find(struct Entry_02028bd0* records, int zoneId);

// Main, originally FindEntryByCurrentId02027cb0 (USA 0x02027cb0, EUR 0x02027cc0, JPN 0x0202751c)
ARM struct Entry_02028bd0* ZoneRecords_FindCurrent(void) {
    return ZoneRecords_Find(&data_020fdd44, *Zone3D_GetInstance());
}
