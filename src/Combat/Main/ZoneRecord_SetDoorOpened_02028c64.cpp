#include <globaldefs.h>

void InsertShortIntoTable021098f4_0209953c(unsigned short);

struct Obj02028c64 {
    char pad[4];
    unsigned short flags;
};

// Main, originally SetFlagBit02028c64 (USA 0x02028c64, EUR 0x02028c74, JPN 0x020284b4)
ARM void ZoneRecord_SetDoorOpened(struct Obj02028c64* obj, int index) {
    if (index < 0x10) {
        obj->flags |= 1 << index;
        return;
    }
    InsertShortIntoTable021098f4_0209953c(5);
}
