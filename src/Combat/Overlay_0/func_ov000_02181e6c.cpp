#include <globaldefs.h>

extern "C" int func_ov000_021818e0(int mode, int idx, void* obj, int* out);

// USA: func_ov000_02181e6c
extern "C" ARM int func_ov000_02181e6c(int unused, void* obj, int* out) {
    return func_ov000_021818e0(0, 2, obj, out);
}
