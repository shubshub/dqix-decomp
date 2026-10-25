#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif

#include "std_library_functions.h"
#include "Combat/ResourceScriptEntry.h"

// What the caller's characterData points to; only the fields written here.
struct PartyMemberData {
    unsigned char unknown[IS_JPN ? 0x884 : 0x91c];
    ResourceScriptPackedTriple levelStats[3]; // the level entry's initial.value8, valueC, value10
    unsigned char unknownAfterLevelStats[0xc];
    unsigned char variants[0x16];             // the level entry's variants (100 each when none are passed)
};

// Main, originally func_02083cbc (USA 0x02083cbc, EUR 0x02083ccc, JPN 0x020845d4)
extern "C" ARM void PartyMember_ApplyLevelStats(void* member, void* levelEntry, void* variants) {
    ((PartyMemberData*)member)->levelStats[0].low = ((ResourceScriptEntry*)levelEntry)->initial.value8.low;
    ((PartyMemberData*)member)->levelStats[0].middle = ((ResourceScriptEntry*)levelEntry)->initial.value8.middle;
    ((PartyMemberData*)member)->levelStats[0].high = ((ResourceScriptEntry*)levelEntry)->initial.value8.high;
    ((PartyMemberData*)member)->levelStats[1].low = ((ResourceScriptEntry*)levelEntry)->initial.valueC.low;
    ((PartyMemberData*)member)->levelStats[1].middle = ((ResourceScriptEntry*)levelEntry)->initial.valueC.middle;
    ((PartyMemberData*)member)->levelStats[1].high = ((ResourceScriptEntry*)levelEntry)->initial.valueC.high;
    ((PartyMemberData*)member)->levelStats[2].low = ((ResourceScriptEntry*)levelEntry)->initial.value10.low;
    ((PartyMemberData*)member)->levelStats[2].middle = ((ResourceScriptEntry*)levelEntry)->initial.value10.middle;
    ((PartyMemberData*)member)->levelStats[2].high = ((ResourceScriptEntry*)levelEntry)->initial.value10.high;
    memset(((PartyMemberData*)member)->variants, 100, sizeof(((PartyMemberData*)member)->variants));
    if (variants != NULL) {
        for (int i = 0; i < 0x16; i++) {
            ((PartyMemberData*)member)->variants[i] = ((unsigned char*)variants)[i];
        }
    }
}
