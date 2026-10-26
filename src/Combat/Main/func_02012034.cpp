#include <globaldefs.h>

// USA: func_02012034
extern "C" ARM unsigned char func_02012034(void* gameState) {
#if defined(jpn)
    return ((unsigned char*)gameState + 0x7000)[0xc9c];
#else
    return ((unsigned char*)gameState + 0x7000)[0xf70];
#endif
}
