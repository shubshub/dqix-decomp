#include <globaldefs.h>
// USA: func_0207d9f4
extern "C" ARM void* func_0207d9f4(unsigned char *arr, int offset) {
    int i;
    for (i = 0; i < 4; i++) {
        unsigned char *p = arr + i * 12;
        if (*(signed char*)(p + offset + 8) == 1) return p;
    }
    return NULL;
}
