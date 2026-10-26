#include <globaldefs.h>

unsigned short WH_GetCurrentAid(void);

// The link session (data_020fefec), as far as this function reads it.
struct SearchStruct { int state; };

// 1 with no session, or as the host (wireless aid 0); 0 as a guest.
// Main, originally func_0202c508 (USA 0x0202c508, EUR 0x0202c518, JPN 0x0202c094)
extern "C" ARM int LinkSession_IsHostOrSolo(SearchStruct* session) {
    int active = session->state != 0;
    if (active) {
        return WH_GetCurrentAid() == 0;
    }
    return 1;
}
