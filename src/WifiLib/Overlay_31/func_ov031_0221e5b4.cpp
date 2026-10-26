#include <globaldefs.h>


extern "C" ARM int func_ov031_022071d8(int unused, int mode);

// USA: func_ov031_0221e5b4
extern "C" THUMB int func_ov031_0221e5b4(int unused, int mode) {
    return func_ov031_022071d8(unused, mode);
}
