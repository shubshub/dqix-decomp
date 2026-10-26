#include <globaldefs.h>

extern "C" int func_ov000_021819c8(int, int, int*, int);

// USA: func_ov000_02182004
extern "C" ARM int func_ov000_02182004(int unused, int a, int* out, int arg3) {
    return func_ov000_021819c8(a, 1, out, 0);
}
