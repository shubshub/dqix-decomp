#include <globaldefs.h>

// A ZoneRecord (ZoneRecords_GetInstance's array of 4)
struct Element0x318_02028bac {
#if defined(jpn)
    unsigned char data[0x314];
#else
    unsigned char data[0x318];
#endif
};

enum { kZoneRecordCount = 4 };

// Main, originally GetElementStride0x318 (USA 0x02028bac, EUR 0x02028bbc, JPN 0x020283fc)
extern "C" ARM struct Element0x318_02028bac* ZoneRecords_GetAt(struct Element0x318_02028bac* records, int index) {
    if (index < 0 || index >= kZoneRecordCount) {
        return NULL;
    }
    return &records[index];
}
