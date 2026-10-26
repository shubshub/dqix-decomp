#include <globaldefs.h>

extern "C" int fix32_Divide(unsigned int, unsigned int);
extern "C" void Camera_SetOrbit(void*, int, int, int);

// USA: func_0202e808
extern "C" ARM void func_0202e808(void* obj, int arg1) {
    int* p = (int*)obj;
    int m = fix32_Divide(arg1, p[0x1e]);
    p[0x1d] = (int)(((long long)p[0x1d] * m + 0x800) >> 12);
    p[0x1e] = arg1;
    Camera_SetOrbit(obj, p[0x1c], p[0x1d], arg1);
}
