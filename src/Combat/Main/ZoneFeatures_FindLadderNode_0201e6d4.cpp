#include <globaldefs.h>
#include "World/ZoneFeatures.h"

// Main, originally FindNodeKind9ById_0201e6d4 (USA 0x0201e6d4, EUR 0x0201e6e4, JPN 0x0201e460)
ARM ZoneFeatures::Opcode6aEntry* ZoneFeatures_FindLadderNode(ZoneFeatures* owner, int id) {
    ZoneFeatures::Opcode6aEntry* node;
    if (id < 0) {
        return 0;
    }
    node = owner->entries6aByType_[9];
    while (node != 0) {
        if (node->maybeType == 9 && node->unk_2c.type9.unk_0 == id) {
            return node;
        }
        node = node->pNext;
    }
    return 0;
}
