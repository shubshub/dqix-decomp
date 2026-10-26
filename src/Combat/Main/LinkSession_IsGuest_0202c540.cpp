#include <globaldefs.h>

unsigned short WH_GetCurrentAid(void);

// The link session (data_020fefec), as far as this function reads it.
struct SearchStruct { int state; };

// 1 in a session as a guest (wireless aid other than 0); 0 with no session or as the host.
// Main, originally func_0202c540 (USA 0x0202c540, EUR 0x0202c550, JPN 0x0202c0cc)
extern "C" ARM int LinkSession_IsGuest(SearchStruct* session) {
    int active = session->state != 0;
    if (active) {
        return WH_GetCurrentAid() != 0;
    }
    return 0;
}
