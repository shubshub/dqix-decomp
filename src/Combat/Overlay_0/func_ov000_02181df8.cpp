#include <globaldefs.h>

extern "C" int func_ov000_021818e0(int mode, int idx, void* obj, int* out);

// USA: func_ov000_02181df8
extern "C" ARM int func_ov000_02181df8(int unused, void* obj, int* out) {
    return func_ov000_021818e0(1, 6, obj, out);
}
