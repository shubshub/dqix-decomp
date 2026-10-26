#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_020698fc
extern "C" ARM int func_020698fc(void** dst) {
    void* d = *dst;
    unsigned short v = 0xff1f;
    memcpy(d, &v, 2);
    return 2;
}
