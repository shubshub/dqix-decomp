#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_020865ec
extern "C" ARM void func_020865ec(char* obj) {
    memset(obj, 0, 0x14);
    *(char*)(obj + 0x10) = -1;
}
