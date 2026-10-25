#include <globaldefs.h>

void InsertShortIntoTable021098f4_0209953c(unsigned short);

struct Obj02028c14 {
    unsigned short pad0;
    unsigned short lowNibble : 4;
    unsigned short flags : 12;
};

// Main, originally SetFlagBit02028c14 (USA 0x02028c14, EUR 0x02028c24, JPN 0x02028464)
ARM void ZoneRecord_SetLootableSearched(struct Obj02028c14* obj, int index) {
    if (index >= 0xc) {
        InsertShortIntoTable021098f4_0209953c(4);
        return;
    }
    obj->flags |= 1 << index;
}
