#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_020d9dc4
extern "C" ARM void func_020d9dc4(char* dst, char* src) {
    memcpy(dst + 0x10, src, strlen(src));
}
