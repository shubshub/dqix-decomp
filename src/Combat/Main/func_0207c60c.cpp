#include <globaldefs.h>

// USA: func_0207c60c
extern "C" ARM void* func_0207c60c(void* base, unsigned int index) {
    if (index > 7) {
        return 0;
    }
    return ((void**)((char*)base + 0xbf0))[index];
}
