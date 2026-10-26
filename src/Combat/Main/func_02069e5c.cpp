#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_02069e5c
extern "C" ARM int func_02069e5c(void** dst) {
    void* d = *dst;
    unsigned short v = 0xff2d;
    memcpy(d, &v, 2);
    return 2;
}
