#include <globaldefs.h>

struct FieldBlock63d6_115c0 {
#if defined(jpn)
    char unk[0x6176];
#else
    char unk[0x63D6];
#endif
    unsigned char movieId;
};

// Main, originally ClearByte0x63d6_020115c0 (USA 0x020115c0, EUR 0x020115d0, JPN 0x02011330)
ARM void GameState_ClearMovieId(struct FieldBlock63d6_115c0* gameState) {
    gameState->movieId = 0;
}
