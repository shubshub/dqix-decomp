#include <globaldefs.h>

// USA: func_020535e0
extern "C" ARM int func_020535e0(int* obj) {
#if defined(jpn)
    return obj[0x5d] >= 0;
#else
    return obj[0x60] >= 0;
#endif
}
