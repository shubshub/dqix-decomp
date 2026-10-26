#include <globaldefs.h>
#include "std_library_functions.h"


extern "C" void HaltSystem(void);

// USA: func_ov025_021e2114
extern "C" ARM void func_ov025_021e2114(unsigned char* dst, void* src, int count) {
    if (count > 0xc) {
        HaltSystem();
    }
    memcpy(dst+8, src, count);
    dst[0x14] = (unsigned char)count;
}
