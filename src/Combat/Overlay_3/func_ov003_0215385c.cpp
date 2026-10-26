#include <globaldefs.h>

// USA: func_ov003_0215385c
extern "C" ARM void func_ov003_0215385c(void* obj) {
    unsigned char v = *((unsigned char*)obj + 0x5a);
    if (v == 0) {
        v = 0;
        *((unsigned char*)obj + 0x5a) = v;
        *((unsigned char*)obj + 0x5b) = v;
    }
}
