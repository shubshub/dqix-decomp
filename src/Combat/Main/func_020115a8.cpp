#include <globaldefs.h>

struct FieldBlock63d6_115a8 {
#if defined(jpn)
    char unk[0x6176];
#else
    char unk[0x63D6];
#endif
    unsigned char movieId;
};

// USA: func_020115a8
extern "C" ARM int func_020115a8(struct FieldBlock63d6_115a8* gameState) {
    return gameState->movieId;
}
