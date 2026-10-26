#include <globaldefs.h>
#if defined(jpn)
enum { kPartyOffset = 0x27a4 };
#else
enum { kPartyOffset = 0x2a04 };
#endif


struct Region02010834 {
    unsigned char pad[0xf78];
    unsigned char memberIds[4];
    unsigned char memberCount;
};

struct Base02010834 {
    unsigned char pad[kPartyOffset];
    struct Region02010834 party;
};

// Main, originally CopyCountedBytesToIntArray02010834 (USA 0x02010834, EUR 0x02010844, JPN 0x02010690)
ARM void GameState_GetPartyMemberIds(struct Base02010834* gameState, int memberIndex, int* outIds, int* outCount) {
    int valid;
    unsigned char i;
    struct Region02010834* party;
    if (memberIndex >= 0 && memberIndex <= 3) {
        valid = 1;
    } else {
        valid = 0;
    }
    if (valid == 0) {
        return;
    }
    party = &gameState->party;
    for (i = 0; i < party->memberCount; i++) {
        outIds[i] = party->memberIds[i];
    }
    *outCount = party->memberCount;
}
