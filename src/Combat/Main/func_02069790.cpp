#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_02069790
extern "C" ARM int func_02069790(void** dst) {
    void* d = *dst;
    unsigned short v = 0xff0d;
    memcpy(d, &v, 2);
    return 2;
}
