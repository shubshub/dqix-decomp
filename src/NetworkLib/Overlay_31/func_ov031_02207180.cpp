#include <globaldefs.h>

extern "C" void* func_ov031_0220713c(void*, void*);
extern void* data_ov031_0224e22c;

// USA: func_ov031_02207180
extern "C" ARM int func_ov031_02207180(void* v) {
    if ((int)v <= 0) goto ret1;
    if (func_ov031_0220713c(&data_ov031_0224e22c, v) != 0) goto ret0;
ret1:
    return 1;
ret0:
    return 0;
}
