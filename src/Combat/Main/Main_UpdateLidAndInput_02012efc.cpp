#include <globaldefs.h>
#include "Input/Input.h"

extern "C" void Main_HandleLid(void);
extern "C" void InputLock_ReleaseIfElapsed(void);

// Main, originally InitCombatSubsystems02012efc (USA 0x02012efc, EUR 0x02012f0c, JPN 0x02012cc4)
extern "C" ARM void Main_UpdateLidAndInput(void) {
    Main_HandleLid();
    InputLock_ReleaseIfElapsed();
    g_keyManager.RefreshKeys();
    g_touchInput.RefreshState();
}
