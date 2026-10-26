#include <globaldefs.h>

// USA: func_0204a01c
extern "C" ARM int func_0204a01c(unsigned char* obj) {
    int* p = *(int**)(obj + 0x13c);
    if (p != 0) {
        return p[0x1a];
    }
    return 0;
}
