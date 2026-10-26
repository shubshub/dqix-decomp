#include <globaldefs.h>

extern "C" int func_ov000_021819c8(void* a, int b, int* out, int flag);

// USA: func_ov000_02181fec
extern "C" ARM int func_ov000_02181fec(void* unused, void* a, int* out) {
    return func_ov000_021819c8(a, 0, out, 0);
}
