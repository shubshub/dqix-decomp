#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_020464a4
extern "C" ARM void func_020464a4(char* src, char* dst, int size) {
    if (src == NULL || dst == NULL) return;
    strncpy(dst, src, size - 1);
    dst[size - 1] = 0;
}
