#include <globaldefs.h>

struct Vec3;
extern "C" void Vector3fix_Subtract(struct Vec3* a, struct Vec3* b, struct Vec3* out);

// USA: func_0202e9f4
extern "C" ARM void func_0202e9f4(void* obj, struct Vec3* v) {
    Vector3fix_Subtract((struct Vec3*)((char*)obj + 0x10), (struct Vec3*)((char*)obj + 0x4), v);
}
