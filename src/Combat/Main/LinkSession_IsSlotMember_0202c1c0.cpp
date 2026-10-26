#include <globaldefs.h>

// The link session (data_020fefec), as far as this function reads it.
struct SearchStruct {
    char padding0[0x100c];
    unsigned char memberMask;  // aid bits of the joined members
};

extern "C" signed char LinkSession_FindAidOfSlot(struct SearchStruct* session, int slot);

// Main, originally TestBitBySignedByteIndex_0202c1c0 (USA 0x0202c1c0, EUR 0x0202c1d0, JPN 0x0202bd70)
extern "C" ARM int LinkSession_IsSlotMember(struct SearchStruct* session, int slot) {
    int aid = LinkSession_FindAidOfSlot(session, slot);
    if (aid < 0) return 0;
    return session->memberMask & (1 << aid);
}
