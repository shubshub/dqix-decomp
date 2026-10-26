#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_ov025_021ed324
extern "C" ARM void func_ov025_021ed324(void* obj, const char* src) {
    if (src == 0) {
        *((char*)obj + 0x16c) = 0;
        return;
    }
    strcpy((char*)obj + 0x16c, src);
}
