#include <globaldefs.h>

// Main, originally GetField5cb0Value_0201079c (USA 0x0201079c, EUR 0x020107ac, JPN 0x020105f8)
extern "C" ARM int GameState_GetStoryChapter(char* gameState) {
#if defined(jpn)
    return *(int*)(gameState + 0x5a50);
#else
    return *(int*)(gameState + 0x5cb0);
#endif
}
