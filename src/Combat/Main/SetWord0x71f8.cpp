#include <globaldefs.h>

// USA: func_0201206c
ARM void SetWord0x71f8_0201206c(void* gameState, int value) {
#if defined(jpn)
    *(int*)((unsigned char*)gameState + 0x6000 + 0xfb8) = value;
#else
    *(int*)((unsigned char*)gameState + 0x7000 + 0x1f8) = value;
#endif
}
