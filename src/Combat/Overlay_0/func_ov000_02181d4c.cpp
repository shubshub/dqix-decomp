#include <globaldefs.h>

extern "C" int func_ov000_021818e0(int mode, int idx, void* obj, int* out);

// USA: func_ov000_02181d4c
extern "C" ARM int func_ov000_02181d4c(int unused, void* obj, int* out) {
    return func_ov000_021818e0(1, 0, obj, out);
}
