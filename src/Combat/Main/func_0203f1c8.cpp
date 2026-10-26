#include <globaldefs.h>

// USA: func_0203f1c8
extern "C" ARM void* func_0203f1c8(unsigned char* obj, unsigned int index) {
    if (*(unsigned int*)(obj + 0x18) <= index) {
        return NULL;
    }
    return *(unsigned char**)(obj + 0x1c) + index * 0x14;
}
