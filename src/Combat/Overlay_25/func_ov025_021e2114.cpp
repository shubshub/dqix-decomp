#include <globaldefs.h>
#include "std_library_functions.h"


extern "C" void HaltSystem(void);

// USA: func_ov025_021e2114
ARM void CopyBytesAndSetLen_021e2114(unsigned char* dst, void* src, int count) {
    if (count > 0xc) {
        HaltSystem();
    }
    memcpy(arg0+8, arg1, arg2);
    arg0[0x14] = (unsigned char)arg2;
}
