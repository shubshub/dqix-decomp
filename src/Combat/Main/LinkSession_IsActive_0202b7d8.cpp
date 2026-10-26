#include <globaldefs.h>

// The argument is always the link session (LinkSession_GetInstance); its first word is the session state.
// Main, originally CheckField0NonZero_0202b7d8 (USA 0x0202b7d8, EUR 0x0202b7e8, JPN 0x0202b388)
extern "C" ARM int LinkSession_IsActive(int* sessionState) {
    return sessionState[0] != 0;
}
