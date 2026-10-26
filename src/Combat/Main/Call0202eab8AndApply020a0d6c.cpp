#include <globaldefs.h>

extern "C" void Camera_SetOrbitFromPosition(void* obj);
struct Vec3PairRecord020a0d6c;
int InitVec3PairRecordType1(struct Vec3PairRecord020a0d6c*, int*, int*, int, int, int);

// USA: func_0202edf8
ARM void Call0202eab8AndApply020a0d6c_0202edf8(char* obj, int a, int b, int c, int d) {
    Camera_SetOrbitFromPosition(obj);
    InitVec3PairRecordType1((struct Vec3PairRecord020a0d6c*)(obj + 0x1bc), (int*)(obj + 0x70), (int*)a, b, c, d);
}
