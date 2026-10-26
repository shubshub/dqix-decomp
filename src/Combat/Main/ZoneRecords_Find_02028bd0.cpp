#include <globaldefs.h>
#if defined(jpn)
enum { Enum_02028bd0_790 = 0x312 };
#else
enum { Enum_02028bd0_790 = 0x316 };
#endif

// A ZoneRecord (ZoneRecords_GetInstance's array of 4)
struct Entry_02028bd0 {
    unsigned short zoneId;
    char unk[Enum_02028bd0_790];
};

enum { kZoneRecordCount = 4 };

// Main, originally FindInlineEntryById (USA 0x02028bd0, EUR 0x02028be0, JPN 0x02028420)
extern "C" ARM struct Entry_02028bd0* ZoneRecords_Find(struct Entry_02028bd0* records, int zoneId) {
    int i;
    if (zoneId < 0) {
        return 0;
    }
    for (i = 0; i < kZoneRecordCount; i++) {
        if (zoneId == records[i].zoneId) {
            return &records[i];
        }
    }
    return 0;
}
