#include <globaldefs.h>

// USA: func_ov000_0216f720
extern "C" ARM void func_ov000_0216f720(void* obj, int val) {
    *(int*)((char*)obj + 0x234) = val;
}
