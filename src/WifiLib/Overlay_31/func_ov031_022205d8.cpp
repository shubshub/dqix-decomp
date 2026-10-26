#include <globaldefs.h>

extern "C" void OS_GetMacAddress(void* dst);

// USA: func_ov031_022205d8
extern "C" THUMB int func_ov031_022205d8(void* dst) {
    OS_GetMacAddress(dst);
    return 1;
}
