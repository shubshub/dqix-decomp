#include <globaldefs.h>

// The link session (data_020fefec), as far as this function reads it.
struct SearchStruct {
    char padding0[0x1038];
    signed char slotOfAid[16];
};

// Returns the wireless aid that holds party slot `slot`, or -1.
// Main, originally FindSignedByteIndex_0202bcbc (USA 0x0202bcbc, EUR 0x0202bccc, JPN 0x0202b86c)
ARM signed char LinkSession_FindAidOfSlot(struct SearchStruct* session, int slot) {
    int aid;
    for (aid = 0; aid < 16; aid++) {
        if (session->slotOfAid[aid] == slot) {
            break;
        }
    }
    if (aid == 16) {
        return -1;
    }
    return aid;
}
