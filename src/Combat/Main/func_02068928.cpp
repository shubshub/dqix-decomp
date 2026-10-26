#include <globaldefs.h>

// USA: func_02068928
extern "C" ARM int func_02068928(int a, unsigned char* obj) {
    unsigned int* p = *(unsigned int**)(obj + 0x0);
    if (p != NULL) {
        return (p[2] << 4 >> 31) == 0;
    }
    return 0;
}
