#include <globaldefs.h>

// USA: func_0204a0f8
extern "C" ARM int func_0204a0f8(unsigned char* obj) {
    int* p = *(int**)(obj + 0x13c);
    if (p != 0) {
        return (p[8] & 0x400) != 0;
    }
    return 0;
}
