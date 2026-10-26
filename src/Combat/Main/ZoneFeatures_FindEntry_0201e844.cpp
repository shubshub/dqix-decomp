#include <globaldefs.h>
#include "World/ZoneFeatures.h"

// Main, originally FindNodeById_0201e844 (USA 0x0201e844, EUR 0x0201e854, JPN 0x0201e5d0)
extern "C" ARM ZoneFeatures::Opcode6aEntry* ZoneFeatures_FindEntry(void* features, int type, int id) {
    ZoneFeatures::Opcode6aEntry* node;
    if (id < 0) {
        return 0;
    }
    node = ((ZoneFeatures*)features)->entries6aByType_[type];
    while (node != 0) {
        if (node->unk_0 == id) {
            return node;
        }
        node = node->pNext;
    }
    return node;
}
