#include <globaldefs.h>

// The argument is always the link session (LinkSession_GetInstance); its first word is the session state.
// Main, originally GetFieldAt0x0_0202ba00 (USA 0x0202ba00, EUR 0x0202ba10, JPN 0x0202b5b0)
ARM int LinkSession_GetState(int* sessionState) {
    return *sessionState;
}
