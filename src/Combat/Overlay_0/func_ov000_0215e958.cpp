#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_ov000_0215e958
extern "C" ARM void* func_ov000_0215e958(char* obj) {
    int idx = *(unsigned char*)(obj + 0x8e02);
    if (idx >= 0x168) {
        return 0;
    }
    char* e = obj + 0x21e0 + idx * 0x24;
    memset(e, 0, 0x20);
    *(int*)(e + 0x20) = 0;
    return obj + 0x21e0 + *(unsigned char*)(obj + 0x8e02) * 0x24;
}
