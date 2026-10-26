#include <globaldefs.h>

// USA: func_02010810
extern "C" ARM void func_02010810(char* gameState, int value) {
#if defined(jpn)
    *(int*)(gameState + 0x5a5c) = value;
#else
    *(int*)(gameState + 0x5cbc) = value;
#endif
}
