#include <globaldefs.h>

// USA: func_02011600
extern "C" ARM void func_02011600(void* obj) {
    unsigned char* base = (unsigned char*)obj;
#if defined(jpn)
    *(unsigned short*)(base + 0x6178) = 0;
#else
    *(unsigned short*)(base + 0x63d8) = 0;
#endif
}
