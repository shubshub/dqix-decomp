#include <globaldefs.h>

extern char data_02107800;

// USA: func_020421b0
extern "C" ARM void* func_020421b0(int idx) {
    return (void*)(*(int*)(&data_02107800 + 0x4) + (idx << 5));
}
