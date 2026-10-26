#include <globaldefs.h>

// USA: func_ov025_021e8cf0
extern "C" ARM void* func_ov025_021e8cf0(char* base, int idx) {
    if (idx < 0 || idx >= 0x10) {
        return NULL;
    }
    return base + 0x1dc + idx * 4;
}
