#include <globaldefs.h>

// USA: func_ov000_0215e9d8
extern "C" ARM void* func_ov000_0215e9d8(void* work) {
    int n = *(int*)((char*)work + 0x8e24);
    if (n >= 0x48) return (void*)0;
    return (char*)work + 0x821c + n * 0x28;
}
