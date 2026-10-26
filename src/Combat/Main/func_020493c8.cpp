#include <globaldefs.h>

// USA: func_020493c8
extern "C" ARM int func_020493c8(unsigned char* obj) {
    unsigned char* p = *(unsigned char**)(obj + 0x13c);
    return p != 0 ? p[0x1d] : 0xff;
}
