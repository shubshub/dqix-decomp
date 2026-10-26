#include <globaldefs.h>

struct StateBits5ccc_1155c {
#if defined(jpn)
    char unk[0x5A6C];
#else
    char unk[0x5CCC];
#endif
    signed int flag : 1;
};

// Main, originally ClearFlag0x5cccBit0_0201155c (USA 0x0201155c, EUR 0x0201156c, JPN 0x020112cc)
ARM void GameState_ClearErrorScreenRequest(struct StateBits5ccc_1155c* state) {
    state->flag = 0;
}
