#include <globaldefs.h>
extern "C" int Vector3fix_HeadingToward(struct Vec3*, struct Vec3*);

struct Obj02033834;
void GameObject_SetFacing(struct Obj02033834*, int);

// USA: func_020338b0
ARM void ComputeAndDispatch020338b0(unsigned char* obj, int a) {
    int value = Vector3fix_HeadingToward((struct Vec3*)(a), (struct Vec3*)(obj + 0x44));
    GameObject_SetFacing((struct Obj02033834*)obj, value);
}
