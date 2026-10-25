#include <globaldefs.h>

struct Entry_02028bd0;
extern struct Entry_02028bd0 data_020fdd44;

// Main, originally GetEntryTableBase_02027ca4 (USA 0x02027ca4, EUR 0x02027cb4, JPN 0x02027510)
ARM struct Entry_02028bd0* ZoneRecords_GetInstance(void) {
    return &data_020fdd44;
}
