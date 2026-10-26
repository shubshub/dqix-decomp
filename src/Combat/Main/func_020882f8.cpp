#include <globaldefs.h>

// USA: func_020882f8
extern "C" ARM int func_020882f8(unsigned char* obj) {
    return (*(int*)(obj + 0x14) & 0x10) != 0;
}
