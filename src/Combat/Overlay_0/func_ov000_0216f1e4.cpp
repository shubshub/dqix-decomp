#include <globaldefs.h>
#include "NitroSDK/Matrix.h"

// USA: func_ov000_0216f1e4
extern "C" ARM void func_ov000_0216f1e4(void* obj, int* arg1, int a, int b) {
    *(Vector3i*)((char*)obj + 0x264) = *(Vector3i*)arg1;
    *(int*)((char*)obj + 0x270) = a;
    *(int*)((char*)obj + 0x274) = b;
}
