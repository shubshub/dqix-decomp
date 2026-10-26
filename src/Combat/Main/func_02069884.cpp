#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_02069884
extern "C" ARM int func_02069884(void** dst) {
    void* d = *dst;
    unsigned short v = 0xff1d;
    memcpy(d, &v, 2);
    return 2;
}
