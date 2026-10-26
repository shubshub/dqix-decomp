#include <globaldefs.h>

extern "C" void func_0209953c(unsigned short errorCode);

// A ZoneRecord (ZoneRecords_GetInstance's array of 4)
struct Obj02028c14 {
    unsigned short zoneId;
    unsigned short slotIndexAndFlags : 4;
    unsigned short searchedLootables : 12;
};

enum { kMaxLootables = 0xc };

// Main, originally SetFlagBit02028c14 (USA 0x02028c14, EUR 0x02028c24, JPN 0x02028464)
extern "C" ARM void ZoneRecord_SetLootableSearched(struct Obj02028c14* record, int lootableIndex) {
    if (lootableIndex >= kMaxLootables) {
        func_0209953c(4);
        return;
    }
    record->searchedLootables |= 1 << lootableIndex;
}
