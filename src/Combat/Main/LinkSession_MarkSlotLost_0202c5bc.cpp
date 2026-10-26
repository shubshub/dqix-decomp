#include <globaldefs.h>

struct SearchStruct;
struct ByteSearchStruct;
extern "C" signed char LinkSession_FindAidOfSlot(struct SearchStruct* obj, int value);
extern "C" signed char LinkSession_FindPreviousAidOfSlot(struct ByteSearchStruct* obj, int value);

// Main, originally SetFlagBitAt0xe_0202c5bc (USA 0x0202c5bc, EUR 0x0202c5cc, JPN 0x0202c148)
extern "C" ARM void LinkSession_MarkSlotLost(struct SearchStruct* obj, int value) {
    int idx = LinkSession_FindAidOfSlot(obj, value);
    if (idx < 0) {
        idx = LinkSession_FindPreviousAidOfSlot((struct ByteSearchStruct*)obj, value);
        if (idx < 0) return;
    }
    *((unsigned char*)obj + 0x100e) |= (1 << idx);
}
