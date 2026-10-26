#include <globaldefs.h>
#if defined(jpn)
enum { kPartyMemberDataStride = 0x8cc };
#else
enum { kPartyMemberDataStride = 0x964 };
#endif
enum { kPartyMemberDataOffset = 0x474, kObjectIndexOffset = 0x568 };


// Main, originally FindRecordByShortField020108f0 (USA 0x020108f0, EUR 0x02010900, JPN 0x0201074c)
extern "C" ARM void* GameState_FindPartyMemberData(void* gameState, int objectIndex) {
    if (objectIndex < 0 || objectIndex >= 4) {
        return NULL;
    }
    for (int i = 0; i < 4; i++) {
        int offset = i * kPartyMemberDataStride;
        short boundIndex = *(short*)((char*)gameState + offset + (kPartyMemberDataOffset + kObjectIndexOffset));
        if (objectIndex == boundIndex) {
            return (char*)gameState + kPartyMemberDataOffset + offset;
        }
    }
    return NULL;
}
