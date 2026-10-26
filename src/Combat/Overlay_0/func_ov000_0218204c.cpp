#include <globaldefs.h>

extern "C" int func_ov000_021819c8(int, int, int*, int);

// USA: func_ov000_0218204c
extern "C" ARM int func_ov000_0218204c(int unused, int a, int* out, int arg3) {
    return func_ov000_021819c8(a, 0, out, 1);
}
