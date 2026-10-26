#include <globaldefs.h>

// USA: func_ov000_0216f700
extern "C" ARM void func_ov000_0216f700(void* obj, int val) {
    *(int*)((char*)obj + 0x21c) = val;
}
