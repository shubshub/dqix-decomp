#include <globaldefs.h>

// Main, originally GetField5cb8Value_02010804 (USA 0x02010804, EUR 0x02010814, JPN 0x02010660)
extern "C" ARM int GameState_GetStoryStep(char* gameState) {
#if defined(jpn)
    return *(int*)(gameState + 0x5a58);
#else
    return *(int*)(gameState + 0x5cb8);
#endif
}
