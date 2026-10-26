#include <globaldefs.h>

// USA: func_0207c5f8
extern "C" ARM void* func_0207c5f8(unsigned char* obj, unsigned int index) {
    if (index > 7) {
        return NULL;
    }
    return *(void**)(obj + index * 4 + 0xbd0);
}
