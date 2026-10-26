#include <globaldefs.h>

struct SearchStruct;
signed char LinkSession_FindAidOfSlot(struct SearchStruct* session, int slot);
int LinkSession_GetConnectedAids(struct SearchStruct* session);

// Main, originally TestMaskBitBySignedByteIndex_0202bd34 (USA 0x0202bd34, EUR 0x0202bd44, JPN 0x0202b8e4)
ARM int LinkSession_IsSlotConnected(struct SearchStruct* session, int slot) {
    int aid = LinkSession_FindAidOfSlot(session, slot);
    if (aid < 0) return 0;
    return (LinkSession_GetConnectedAids((struct SearchStruct*)session) & (1 << aid)) != 0;
}
