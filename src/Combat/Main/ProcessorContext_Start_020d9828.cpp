#include <globaldefs.h>
#include "NitroSDK/ProcessorContext.h"

// Main, originally Forward020d9828 (USA 0x020d9828, EUR 0x020d9838, JPN 0x020db234)
extern "C" ARM void ProcessorContext_Start(ProcessorContext* context) {
    MarkContextReadyAndSwitch(context);
}
