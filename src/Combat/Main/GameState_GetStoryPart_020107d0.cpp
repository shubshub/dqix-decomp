#include <globaldefs.h>

// Main, originally GetField5cb4Value_020107d0 (USA 0x020107d0, EUR 0x020107e0, JPN 0x0201062c)
extern "C" ARM int GameState_GetStoryPart(char* gameState) {
#if defined(jpn)
    return *(int*)(gameState + 0x5a54);
#else
    return *(int*)(gameState + 0x5cb4);
#endif
}
