#include <globaldefs.h>
#include "Combat/SearchEntry.h"

struct SearchStruct;
extern "C" int LinkSession_IsHostOrSolo(struct SearchStruct* session);
unsigned short WH_GetBitmap(void);

// Host or solo: the wh library's connected-aid bitmap. Guest: the copy the host shares in its record (slot 0).
// Main, originally GetEntryField0x4OrFieldA0202bc8c (USA 0x0202bc8c, EUR 0x0202bc9c, JPN 0x0202b83c)
ARM unsigned short LinkSession_GetConnectedAids(struct SearchStruct* session) {
    if (LinkSession_IsHostOrSolo(session)) {
        return WH_GetBitmap();
    }
    return LinkSession_GetReceivedRecord(session, 0)->mask;
}
