#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_0207a014
extern "C" ARM char* func_0207a014(char* obj) {
    memset(obj, 0, 0xc);
    memset(obj + 0xc, 0, 0xc);
    memset(obj + 0x18, 0, 0xc);
    memset(obj + 0x24, 0, 0xc);
    return obj;
}
