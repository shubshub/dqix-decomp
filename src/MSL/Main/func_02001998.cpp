#include <globaldefs.h>

// USA: func_02001998
extern "C" ARM int func_02001998(void* p, unsigned char v) {
    if (!p) return 0;
    *(unsigned char*)p = v;
    return 1;
}
