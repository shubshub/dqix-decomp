#include <globaldefs.h>

// GameState (this file's copy of the field it uses)
struct FieldBlock63d6_11590 {
#if defined(jpn)
    char unk[0x6176];
#else
    char unk[0x63D6];
#endif
    unsigned char movieId;  // the movie overlay 16 plays next (GameState_SetMovieId; 0: none)
};

// Main, originally IsByte0x63d6Set_02011590 (USA 0x02011590, EUR 0x020115a0, JPN 0x02011300)
ARM int GameState_HasMovieId(struct FieldBlock63d6_11590* gameState) {
    return gameState->movieId != 0;
}
