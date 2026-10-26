#include <globaldefs.h>
#if defined(jpn)
enum { kPartyMemberDataStride = 0x8cc };
#else
enum { kPartyMemberDataStride = 0x964 };
#endif
enum { kPartyMemberDataOffset = 0x474, kObjectIndexOffset = 0x568 };

// Main, originally FindSlotWithNegShort02010954 (USA 0x02010954, EUR 0x02010964, JPN 0x020107b0)
ARM void* GameState_FindFreePartyMemberData(char* gameState) {
    int i;
    for (i = 0; i < 4; i++) {
        if (*(short*)(gameState + i * kPartyMemberDataStride + (kPartyMemberDataOffset + kObjectIndexOffset)) < 0) {
            return gameState + kPartyMemberDataOffset + i * kPartyMemberDataStride;
        }
    }
    return NULL;
}
