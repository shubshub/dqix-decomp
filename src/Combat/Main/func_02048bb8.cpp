#include <globaldefs.h>

// USA: func_02048bb8
extern "C" ARM void func_02048bb8(unsigned char* obj) {
    int* p = *(int**)(obj + 0x13c);
    if (p != 0) {
        p[8] |= 0x80;
    }
}
