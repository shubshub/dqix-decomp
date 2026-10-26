#include <globaldefs.h>

// The link session (data_020fefec), as far as this function reads it.
struct ByteSearchStruct {
    char padding0[0x1048];
    signed char previousSlotOfAid[16];
};

// Returns the wireless aid that last held party slot `slot`, or -1.
// Main, originally FindSignedByteSlot_0202bcf8 (USA 0x0202bcf8, EUR 0x0202bd08, JPN 0x0202b8a8)
extern "C" ARM signed char LinkSession_FindPreviousAidOfSlot(struct ByteSearchStruct* session, int slot) {
    int aid;
    for (aid = 0; aid < 16; aid++) {
        if (session->previousSlotOfAid[aid] == slot) {
            break;
        }
    }
    if (aid == 16) {
        return -1;
    }
    return aid;
}
