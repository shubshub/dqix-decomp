#include <globaldefs.h>

// USA: func_ov000_0216f718
extern "C" ARM void func_ov000_0216f718(void* obj, int val) {
    *(int*)((char*)obj + 0x230) = val;
}
