#include <globaldefs.h>

struct Struct_020c20d4 { int x; int y; int z; };
struct Struct_020c20d4_2 { int m[3][3]; int t[3]; };

extern "C" void Vector3fix_CrossProduct(int* a, int* b, int* out);
extern "C" void Vector3fix_Normalize(struct Struct_020c20d4* out, struct Struct_020c20d4* in);
extern "C" int Vector3fix_InnerProduct(struct Struct_020c20d4* a, struct Struct_020c20d4* b);

// USA: func_020c20d4
extern "C" ARM void Mat4x3_WriteViewMatrix(struct Struct_020c20d4* eye, struct Struct_020c20d4* up, struct Struct_020c20d4* target, struct Struct_020c20d4_2* out) {
    struct Struct_020c20d4 forward;
    forward.x = eye->x - target->x;
    forward.y = eye->y - target->y;
    forward.z = eye->z - target->z;
    Vector3fix_Normalize(&forward, &forward);

    struct Struct_020c20d4 right;
    Vector3fix_CrossProduct((int*)up, (int*)&forward, (int*)&right);
    Vector3fix_Normalize(&right, &right);

    struct Struct_020c20d4 var2;
    Vector3fix_CrossProduct((int*)&forward, (int*)&right, (int*)&var2);

    out->m[0][0] = right.x;
    out->m[0][1] = var2.x;
    out->m[0][2] = forward.x;
    out->m[1][0] = right.y;
    out->m[1][1] = var2.y;
    out->m[1][2] = forward.y;
    out->m[2][0] = right.z;
    out->m[2][1] = var2.z;
    out->m[2][2] = forward.z;

    out->t[0] = -Vector3fix_InnerProduct(eye, &right);
    out->t[1] = -Vector3fix_InnerProduct(eye, &var2);
    out->t[2] = -Vector3fix_InnerProduct(eye, &forward);
}
