#include <globaldefs.h>

// USA: func_02011634
extern "C" ARM void func_02011634(void* obj) {
    unsigned char* base = (unsigned char*)obj;
#if defined(jpn)
    *(unsigned short*)(base + 0x617a) = 0;
#else
    *(unsigned short*)(base + 0x63da) = 0;
#endif
}
