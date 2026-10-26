#include <globaldefs.h>

// USA: func_02089174
extern "C" ARM void func_02089174(unsigned char* obj) {
    obj[0x7c] = 3;
    obj[0x9f] = 0;
    ((int*)obj)[6] |= 0x800;
}
