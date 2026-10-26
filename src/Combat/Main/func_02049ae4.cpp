#include <globaldefs.h>

// USA: func_02049ae4
extern "C" ARM void func_02049ae4(unsigned char* obj) {
    int* p = *(int**)(obj + 0x13c);
    if (p != 0) {
        p[8] &= ~0x4;
    }
}
