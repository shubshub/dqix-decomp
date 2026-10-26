#include <globaldefs.h>

// The link session (data_020fefec), as far as this function reads it.
struct SearchStruct {
    char padding0[0x100e];
    unsigned char lostMask;  // aid bits of members whose console stopped answering (LinkSession_Update)
};
struct ByteSearchStruct;
extern "C" signed char LinkSession_FindAidOfSlot(struct SearchStruct* session, int slot);
extern "C" signed char LinkSession_FindPreviousAidOfSlot(struct ByteSearchStruct* session, int slot);

// Main, originally TestFlagBitAt0xe_0202c578 (USA 0x0202c578, EUR 0x0202c588, JPN 0x0202c104)
extern "C" ARM int LinkSession_IsSlotLost(struct SearchStruct* session, int slot) {
    int aid = LinkSession_FindAidOfSlot(session, slot);
    if (aid < 0) {
        aid = LinkSession_FindPreviousAidOfSlot((struct ByteSearchStruct*)session, slot);
        if (aid < 0) return 0;
    }
    return session->lostMask & (1 << aid);
}
