#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_0208e4bc
extern "C" ARM void func_0208e4bc(char* obj) {
    memset(obj, 0, 4);
    memset(obj + 0x10, 0, 0x20);
    *(int*)(obj + 4) = 0;
    *(short*)(obj + 8) = 0;
    obj[0xa] = 0;
    *(int*)(obj + 0xc) = 0;
}
