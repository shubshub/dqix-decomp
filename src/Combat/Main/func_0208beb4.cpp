#include <globaldefs.h>

// USA: func_0208beb4
extern "C" ARM void func_0208beb4(unsigned char* obj) {
    if (obj[0xd4] != 3) {
        *(unsigned short*)(obj + 0xda) |= 2;
    }
}
