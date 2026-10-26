#include <globaldefs.h>

// USA: func_0201201c
extern "C" ARM int func_0201201c(void* gameState) {
    unsigned char* bytes = (unsigned char*)gameState;
#if defined(jpn)
    return *(int*)(bytes + 0x7c98);
#else
    return *(int*)(bytes + 0x7f6c);
#endif
}
