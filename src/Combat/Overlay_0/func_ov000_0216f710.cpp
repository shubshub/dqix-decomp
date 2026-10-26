#include <globaldefs.h>

// USA: func_ov000_0216f710
extern "C" ARM void func_ov000_0216f710(void* obj, int val) {
    *(int*)((char*)obj + 0x22c) = val;
}
