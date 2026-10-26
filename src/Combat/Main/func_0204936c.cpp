#include <globaldefs.h>

// USA: func_0204936c
extern "C" ARM int func_0204936c(unsigned char* obj) {
    int* p = *(int**)(obj + 0x13c);
    if (p == 0) return 0;
    return (p[8] & 0x10) != 0;
}
