#include <globaldefs.h>

// USA: func_0201075c
ARM void SetField0x5729Value_0201075c(char* gameState, unsigned char value) {
#if defined(jpn)
    *(unsigned char*)(gameState + 0x54c9) = value;
#else
    *(unsigned char*)(gameState + 0x5729) = value;
#endif
}
