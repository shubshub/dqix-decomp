#include <globaldefs.h>

// USA: func_0201081c
ARM int GetField5cbcValue_0201081c(char* gameState) {
#if defined(jpn)
    return *(int*)(gameState + 0x5a5c);
#else
    return *(int*)(gameState + 0x5cbc);
#endif
}
