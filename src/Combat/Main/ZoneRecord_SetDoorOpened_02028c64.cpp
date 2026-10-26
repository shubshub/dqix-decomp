#include <globaldefs.h>

extern "C" void func_0209953c(unsigned short errorCode);

// A ZoneRecord (ZoneRecords_GetInstance's array of 4)
struct Obj02028c64 {
    char pad[4];
    unsigned short openedDoors;
};

enum { kMaxDoors = 0x10 };

// Main, originally SetFlagBit02028c64 (USA 0x02028c64, EUR 0x02028c74, JPN 0x020284b4)
extern "C" ARM void ZoneRecord_SetDoorOpened(struct Obj02028c64* record, int doorIndex) {
    if (doorIndex < kMaxDoors) {
        record->openedDoors |= 1 << doorIndex;
        return;
    }
    func_0209953c(5);
}
