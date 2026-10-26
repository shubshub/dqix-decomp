#include <globaldefs.h>

// USA: func_ov002_0216364c
extern "C" ARM int func_ov002_0216364c(void* obj) {
    int* p = *(int**)((char*)obj + 0x130);
    return (*p & 1) != 0;
}
