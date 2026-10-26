#include <globaldefs.h>

extern "C" void func_ov031_02227804(void);
extern "C" ARM void *func_ov031_0223e218(void *a, void *b, void *c, int d);

// USA: func_ov031_022277e4
extern "C" ARM void *func_ov031_022277e4(void) {
    return func_ov031_0223e218(0, (void*)func_ov031_02227804, 0, 0x78);
}
