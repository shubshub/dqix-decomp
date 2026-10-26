#include <globaldefs.h>
#include "World/ZoneFeatures.h"

// USA: func_0201e4b0
// Main, originally ZoneFeatures::CreateOpcode66Entry_0201e4b0 (USA 0x0201e4b0, EUR 0x0201e4c0, JPN 0x0201e23c)
ARM void ZoneFeatures::CreateOpcode66Entry(const Opcode66Entry& source) {
    int index = arraySize66_;
    Opcode66Entry* dst;
    if (index >= arrayCapacity66_) {
        return;
    }
    dst = &entries66_[index];
    COPY_ARRAY(dst->unk_0, source.unk_0);
    COPY_ARRAY(dst->unk_18, source.unk_18);
    dst->unk_20 = source.unk_20;
    arraySize66_++;
}
