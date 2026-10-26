#include <globaldefs.h>

// USA: func_02012028
extern "C" ARM void func_02012028(void* gameState, unsigned char value) {
#if defined(jpn)
    ((unsigned char*)gameState + 0x7000)[0xc9c] = value;
#else
    ((unsigned char*)gameState + 0x7000)[0xf70] = value;
#endif
}
