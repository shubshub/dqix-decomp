#include <globaldefs.h>

// USA: func_020118fc
extern "C" ARM void func_020118fc(void* gameState) {
    unsigned char* bytes = (unsigned char*)gameState;
#if defined(jpn)
    *(unsigned char*)(bytes + 0x61ec) = 0;
#else
    *(unsigned char*)(bytes + 0x646c) = 0;
#endif
#if defined(jpn)
    *(unsigned char*)(bytes + 0x61ed) = 0;
#else
    *(unsigned char*)(bytes + 0x646d) = 0;
#endif
#if defined(jpn)
    *(unsigned char*)(bytes + 0x61f0) = 0;
#else
    *(unsigned char*)(bytes + 0x6470) = 0;
#endif
#if defined(jpn)
    *(unsigned char*)(bytes + 0x61f1) = 0;
#else
    *(unsigned char*)(bytes + 0x6471) = 0;
#endif
#if defined(jpn)
    *(unsigned short*)(bytes + 0x61f2) = 0;
#else
    *(unsigned short*)(bytes + 0x6472) = 0;
#endif
#if defined(jpn)
    *(int*)(bytes + 0x61f8) = -1;
#else
    *(int*)(bytes + 0x6478) = -1;
#endif
#if defined(jpn)
    *(unsigned char*)(bytes + 0x61fc) = 0;
#else
    *(unsigned char*)(bytes + 0x647c) = 0;
#endif
#if defined(jpn)
    *(unsigned short*)(bytes + 0x61fe) = 0;
#else
    *(unsigned short*)(bytes + 0x647e) = 0;
#endif
}
