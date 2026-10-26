#include <globaldefs.h>

// USA: func_02010750
ARM unsigned char GetField0x5729Value_02010750(char* gameState) {
#if defined(jpn)
    return *(unsigned char*)(gameState + 0x54c9);
#else
    return *(unsigned char*)(gameState + 0x5729);
#endif
}
