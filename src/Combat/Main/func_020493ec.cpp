#include <globaldefs.h>

// USA: func_020493ec
extern "C" ARM int func_020493ec(unsigned char* obj) {
    unsigned char* p = *(unsigned char**)(obj + 0x13c);
    return p != 0 ? p[0x1e] : 0xff;
}
