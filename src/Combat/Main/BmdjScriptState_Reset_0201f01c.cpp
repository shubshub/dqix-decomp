#include <globaldefs.h>
#include "World/BmdjScriptNode.h"

// Main, originally ResetTrackerState_0201f01c (USA 0x0201f01c, EUR 0x0201f02c, JPN 0x0201eda8)
extern "C" ARM void BmdjScriptState_Reset(BmdjScriptState* state) {
    state->unknown0 = 0;
    state->unknown4 = 0;
    state->unknown8 = 0;
    state->unknownC = 0;
    state->elementCount = 0;
    state->unknown14 = 0;
    state->unknown_38_ = 0;
}
