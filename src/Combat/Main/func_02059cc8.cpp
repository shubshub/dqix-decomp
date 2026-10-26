#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_02059cc8
extern "C" ARM void func_02059cc8(unsigned char* obj) {
    memset(obj, 0, 0xd4);
    *(short*)(obj + 0xb2) = -1;
    *(short*)(obj + 0xb4) = -1;
    obj[0xcc] = (obj[0xcc] | 4) & ~8;
}
