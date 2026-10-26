#include <globaldefs.h>

// USA: func_02012060
ARM unsigned char GetByte0x63d5_02012060(void* gameState) {
#if defined(jpn)
    enum { regionalOffset0 = 0x175 };
#else
    enum { regionalOffset0 = 0x3d5 };
#endif
    return ((unsigned char*)gameState + 0x6000)[regionalOffset0];
}
