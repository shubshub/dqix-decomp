#include <globaldefs.h>

struct Struct_020ca7d0 {
    unsigned int x, y, z;
};

struct Struct_020ca7d0_2 {
    Struct_020ca7d0 a, b, c;
};

// USA: func_020ca7d0
extern "C" THUMB void func_020ca7d0(Struct_020ca7d0_2* obj) {
    Struct_020ca7d0 zero;
    zero.x = 0;
    zero.y = 0;
    zero.z = 0;
    obj->a = zero;
    obj->b = zero;
    obj->c = zero;
}
