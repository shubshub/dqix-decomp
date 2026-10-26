#include <globaldefs.h>

// USA: func_ov001_02158d8c
extern "C" ARM void* func_ov001_02158d8c(void** ctx) {
    unsigned int* entry = (unsigned int*)ctx[0];
    int i = 0;
    while (i < (int)ctx[1]) {
        if (entry[0] == 0) {
            entry[0x12] = 0;
            return entry;
        }
        i++;
        entry += 0x13;
    }
    return NULL;
}
