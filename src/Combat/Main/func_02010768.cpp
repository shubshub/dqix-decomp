#include <globaldefs.h>

// USA: func_02010768
extern "C" ARM void* func_02010768(void* gameState) {
#if defined(jpn)
    return (char*)gameState + 0x5a44;
#else
    return (char*)gameState + 0x5ca4;
#endif
}
