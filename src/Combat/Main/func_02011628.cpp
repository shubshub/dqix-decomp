#include <globaldefs.h>

// USA: func_02011628
extern "C" ARM unsigned short func_02011628(void* obj) {
    unsigned char* base = (unsigned char*)obj;
#if defined(jpn)
    return *(unsigned short*)(base + 0x617a);
#else
    return *(unsigned short*)(base + 0x63da);
#endif
}
