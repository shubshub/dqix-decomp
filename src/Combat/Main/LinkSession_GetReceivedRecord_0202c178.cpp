#include <globaldefs.h>
#include "Combat/SearchEntry.h"

struct SearchStruct;
signed char LinkSession_FindAidOfSlot(struct SearchStruct* session, int slot);

// The link session's receive buffer holds one record per wireless aid: a SearchEntry0202c178 header followed by
// five 0x14-byte message slots (func_0205e57c).
enum {
    kReceiveBufferOffset = 0xbc0,
    kRecordSize = 0x74,
};

// Main, originally GetEntryBySignedByteIndex_0202c178 (USA 0x0202c178, EUR 0x0202c188, JPN 0x0202bd28)
ARM SearchEntry0202c178* LinkSession_GetReceivedRecord(struct SearchStruct* session, int slot) {
    int aid = LinkSession_FindAidOfSlot(session, slot);
    if (aid < 0) return NULL;
    return (SearchEntry0202c178*)((char*)session + kReceiveBufferOffset + aid * kRecordSize);
}
