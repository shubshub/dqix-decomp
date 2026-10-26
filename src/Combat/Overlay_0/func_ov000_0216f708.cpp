#include <globaldefs.h>

// USA: func_ov000_0216f708
extern "C" ARM void func_ov000_0216f708(void* obj, int val) {
    *(int*)((char*)obj + 0x228) = val;
}
