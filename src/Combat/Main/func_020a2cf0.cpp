#include <globaldefs.h>

extern "C" void Camera_Init(void*);
extern "C" void Camera_AddKindFlags(unsigned int*, unsigned int);

struct Struct_0204a120_2 {
    char pad[0x218];
    int unknown_218_;
};

// USA: func_020a2cf0
extern "C" ARM void func_020a2cf0(struct Struct_0204a120_2* obj) {
    Camera_Init(obj);
    Camera_AddKindFlags((unsigned int*)obj, 2);
    obj->unknown_218_ = 0;
}
