#include <globaldefs.h>

// USA: func_02089124
extern "C" ARM void func_02089124(unsigned char* obj) {
    obj[0x79] = 5;
    obj[0x9c] = 0;
    ((unsigned int*)obj)[6] |= 0x400;
}
