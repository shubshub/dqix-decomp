#include <globaldefs.h>
#include "World/ZoneFeatures.h"

// USA: func_0201e2d8
// Main, originally ZoneFeatures::GetOpcode64Entry_0201e2d8 (USA 0x0201e2d8, EUR 0x0201e2e8, JPN 0x0201e064)
ARM ZoneFeatures::Opcode64Entry* ZoneFeatures::GetOpcode64Entry(int index) {
    if (index < 0 || arraySize64_ <= index) {
        return NULL;
    }
    return &entries64_[index];
}
