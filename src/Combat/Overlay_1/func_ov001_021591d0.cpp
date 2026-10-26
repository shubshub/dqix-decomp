#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void* func_ov001_02158e4c(void** ctx);

// USA: func_ov001_021591d0
extern "C" ARM void func_ov001_021591d0(void** ctx, int a1, int a2, int a3, int a4) {
    unsigned int* entry = (unsigned int*)func_ov001_02158e4c(ctx);
    if (entry != 0) {
        entry[0] = 0x10;
        memcpy((char*)entry + 0x4, &a1, 0xc);
        entry[7] = a4;
    }
}
