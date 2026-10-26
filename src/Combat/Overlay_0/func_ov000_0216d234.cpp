#include <globaldefs.h>

struct Struct_ov000_0216d234 { int x; int y; int z; };
struct Struct_ov000_0216d234_2 { Struct_ov000_0216d234 right; Struct_ov000_0216d234 up; Struct_ov000_0216d234 forward; Struct_ov000_0216d234 pos; };

extern "C" void Vector3fix_CrossProduct(int*, int*, int*);

// USA: func_ov000_0216d234
extern "C" ARM void func_ov000_0216d234(int* forward, int* position, struct Struct_ov000_0216d234_2* dest) {
    int up[3];
    up[0] = 0;
    up[1] = 0x1000;
    up[2] = 0;
    int out[3];
    Vector3fix_CrossProduct(forward, up, out);
    dest->right.x = out[0];
    dest->right.y = out[1];
    dest->right.z = out[2];
    dest->up.x = up[0];
    dest->up.y = up[1];
    dest->up.z = up[2];
    dest->forward.x = forward[0];
    dest->forward.y = forward[1];
    dest->forward.z = forward[2];
    dest->pos.x = position[0];
    dest->pos.y = position[1];
    dest->pos.z = position[2];
}
