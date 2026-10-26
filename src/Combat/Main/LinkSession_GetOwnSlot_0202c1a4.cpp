#include <globaldefs.h>

// The link session (data_020fefec), as far as this function reads it.
struct SearchStruct0202c1a4 {
    char padding0[0x1038];
    signed char slotOfAid[16];
};

extern unsigned short WH_GetCurrentAid(void);

// Main, originally GetSearchStructCurrentArrEntry (USA 0x0202c1a4, EUR 0x0202c1b4, JPN 0x0202bd54)
ARM signed char LinkSession_GetOwnSlot(struct SearchStruct0202c1a4* session) {
    return session->slotOfAid[WH_GetCurrentAid()];
}
