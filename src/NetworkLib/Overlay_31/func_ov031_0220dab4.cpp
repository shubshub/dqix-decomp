#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"
#include "NitroSDK/Timing.h"

extern int data_ov031_0224e53c;
extern "C" int func_ov031_0220db28(void);

// USA: func_ov031_0220dab4
extern "C" ARM void func_ov031_0220dab4(void) {
    int state = DisableIRQInterrupts();
    CancelAlarm((Alarm*)((char*)data_ov031_0224e53c + 0x22cc));
    if (*(int*)((char*)data_ov031_0224e53c + 0x2260) == 9) {
        SetTimeout((Alarm*)((char*)data_ov031_0224e53c + 0x22cc), 0x22f5341, (Alarm::PFNCompletion)&func_ov031_0220db28, NULL);
    }
    SetIRQInterruptState(state);
}
