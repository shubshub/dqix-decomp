#include <globaldefs.h>

// USA: func_020999d8
extern "C" ARM void* func_020999d8(unsigned char* obj, unsigned int index) {
    if (*(unsigned int*)(obj + 4) <= index) {
        return NULL;
    }
    return *(unsigned char**)obj + index * 0x10;
}
