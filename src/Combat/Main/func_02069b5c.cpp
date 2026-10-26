#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_02069b5c
extern "C" ARM int func_02069b5c(void** dst) {
    void* d = *dst;
    unsigned short v = 0xff07;
    memcpy(d, &v, 2);
    return 2;
}
