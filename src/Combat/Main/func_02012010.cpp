#include <globaldefs.h>

// USA: func_02012010
extern "C" ARM void func_02012010(void* gameState, int value) {
    unsigned char* bytes = (unsigned char*)gameState;
#if defined(jpn)
    *(int*)(bytes + 0x7c98) = value;
#else
    *(int*)(bytes + 0x7f6c) = value;
#endif
}
