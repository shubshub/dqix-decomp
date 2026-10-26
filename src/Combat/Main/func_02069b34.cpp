#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_02069b34
extern "C" ARM int func_02069b34(void** dst) {
    void* d = *dst;
    unsigned short v = 0xff06;
    memcpy(d, &v, 2);
    return 2;
}
