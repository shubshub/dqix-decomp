#include <globaldefs.h>

extern "C" void func_ov000_0216d560(void* work, int id);
extern "C" void Camera_Update(void* work);

// USA: func_ov000_0216d50c
extern "C" ARM void func_ov000_0216d50c(void* work) {
    int id = *(int*)((char*)work + 0x224);
    if (id >= 0) {
        func_ov000_0216d560(work, id);
    }
    Camera_Update(work);
}
