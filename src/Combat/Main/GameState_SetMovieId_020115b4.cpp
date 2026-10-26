#include <globaldefs.h>

struct FieldBlock63d6_115b4 {
#if defined(jpn)
    char unk[0x6176];
#else
    char unk[0x63D6];
#endif
    unsigned char movieId;
};

// Main, originally SetByteField0x63d6_020115b4 (USA 0x020115b4, EUR 0x020115c4, JPN 0x02011324)
extern "C" ARM void GameState_SetMovieId(struct FieldBlock63d6_115b4* gameState, unsigned char movieId) {
    gameState->movieId = movieId;
}
