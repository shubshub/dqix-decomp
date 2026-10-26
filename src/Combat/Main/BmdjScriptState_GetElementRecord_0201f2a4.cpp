#include "Util/ElementIndexTable.h"
#include <globaldefs.h>

// Main, originally GetElementByIndexStride0x20_0201f2a4 (USA 0x0201f2a4, EUR 0x0201f2b4, JPN 0x0201f030)
ARM struct Element_1f2a4* BmdjScriptState_GetElementRecord(struct Manager_1f2a4* state, int index) {
    if (index < 0 || state->count <= index) {
        return 0;
    }
    return &state->elements[index];
}
