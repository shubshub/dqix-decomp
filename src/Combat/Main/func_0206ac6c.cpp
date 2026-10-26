#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_0206ac6c
extern "C" ARM int func_0206ac6c(void* base, void* src) {
    unsigned short value;
    memcpy(&value, src, 2);
    return (value & 0xff00) == 0xff00;
}
