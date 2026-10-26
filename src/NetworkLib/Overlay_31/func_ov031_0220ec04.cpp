#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"
#include "NitroSDK/WirelessScanDescriptor.h"

extern "C" int func_ov031_0220d60c(void);

// USA: func_ov031_0220ec04
extern "C" ARM Struct_ov031_0220ec04_3* func_ov031_0220ec04(int arg) {
    int state = DisableIRQInterrupts();
    int base = func_ov031_0220d60c();
    if (base == 0) {
        SetIRQInterruptState(state);
        return 0;
    }
    Struct_ov031_0220ec04_2* node = func_ov031_0220ee50(arg);
    if (node == 0) {
        SetIRQInterruptState(state);
        return 0;
    }
    SetIRQInterruptState(state);
    return &node->descriptor;
}
