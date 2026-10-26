#include <globaldefs.h>

extern "C" void Camera_Init(void*);
void Camera_AddKindFlags(unsigned int*, unsigned int);

struct Struct020A2CF0 {
    char pad[0x218];
    int field218;
};

// USA: func_020a2cf0
ARM void ResetState020a2cf0(struct Struct020A2CF0* obj) {
    Camera_Init(obj);
    Camera_AddKindFlags((unsigned int*)obj, 2);
    obj->field218 = 0;
}
