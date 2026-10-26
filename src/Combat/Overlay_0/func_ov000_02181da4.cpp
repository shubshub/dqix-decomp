#include <globaldefs.h>

extern "C" int func_ov000_021818e0(int mode, int idx, void* obj, int* out);

// USA: func_ov000_02181da4
extern "C" ARM int func_ov000_02181da4(int unused, void* obj, int* out) {
    return func_ov000_021818e0(1, 3, obj, out);
}
