#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_02067a9c
extern "C" ARM bool func_02067a9c(void* obj, void* src) {
    unsigned short v;
    memcpy(&v, src, 2);
    if (v >= 0xff01u && v <= 0xff0du) return 1;
    return 0;
}
