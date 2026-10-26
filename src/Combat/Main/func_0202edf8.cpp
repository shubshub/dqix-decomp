#include <globaldefs.h>

extern "C" void Camera_SetOrbitFromPosition(void* obj);
struct Struct_0202ed7c;
extern "C" int func_020a0d6c(struct Struct_0202ed7c*, int*, int*, int, int, int);

// USA: func_0202edf8
extern "C" ARM void func_0202edf8(char* obj, int a, int b, int c, int d) {
    Camera_SetOrbitFromPosition(obj);
    func_020a0d6c((struct Struct_0202ed7c*)(obj + 0x1bc), (int*)(obj + 0x70), (int*)a, b, c, d);
}
