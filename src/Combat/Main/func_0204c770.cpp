#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_0204c770
extern "C" ARM void func_0204c770(char* obj, void* src) {
    memset(obj + 0xdb, 0, 4);
    if (src == NULL) return;
    memcpy(obj + 0xdb, src, 4);
}
