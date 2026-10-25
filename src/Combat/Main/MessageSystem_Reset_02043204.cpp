#include <globaldefs.h>
#include "Resource/MessageUpdate.h"

extern "C" void MessageSystem_Stop(char* obj);

// Main, originally ReinitController02043204 (USA 0x02043204, EUR 0x02043214, JPN 0x02043978)
ARM void MessageSystem_Reset(char* obj) {
    MessageSystem* window = (MessageSystem*)obj;
    InitCombatSlots02043040(window);
    MessageSystem_Stop(obj);
    ResetControllerState020430b0(window);
}
