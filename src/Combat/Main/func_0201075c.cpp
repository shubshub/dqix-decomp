#include <globaldefs.h>

// USA: func_0201075c
extern "C" ARM void func_0201075c(char* gameState, unsigned char value) {
#if defined(jpn)
    *(unsigned char*)(gameState + 0x54c9) = value;
#else
    *(unsigned char*)(gameState + 0x5729) = value;
#endif
}
