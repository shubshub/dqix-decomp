#include <globaldefs.h>

// USA: func_02049390
extern "C" ARM void func_02049390(unsigned char* obj, unsigned char value) {
    unsigned char* p = *(unsigned char**)(obj + 0x13c);
    if (p != 0 && value != 0xff) {
        p[0x1c] = value;
    }
}
