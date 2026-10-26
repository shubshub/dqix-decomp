#include <globaldefs.h>

// USA: func_02049ee8
extern "C" ARM int func_02049ee8(unsigned char* obj) {
    unsigned char* p = *(unsigned char**)(obj + 0x13c);
    return p != 0 ? p[0x56] : 0;
}
