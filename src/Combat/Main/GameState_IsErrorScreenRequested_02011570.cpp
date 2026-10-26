#include <globaldefs.h>

struct StateBits5ccc_11570 {
#if defined(jpn)
    char unk[0x5a6c];
#else
    char unk[0x5CCC];
#endif
    signed int returnToTitle : 1;
};

// Main, originally GetFlag0x5cccBit0_02011570 (USA 0x02011570, EUR 0x02011580, JPN 0x020112e0)
extern "C" ARM int GameState_IsErrorScreenRequested(struct StateBits5ccc_11570* gameState) {
    return gameState->returnToTitle;
}
