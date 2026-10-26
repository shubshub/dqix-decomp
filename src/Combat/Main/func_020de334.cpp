#include <globaldefs.h>

struct Struct_020de334 {
    unsigned int pad[2];
    unsigned int unknown_8_0_ : 4;
    unsigned int value : 5;
};

// USA: func_020de334
extern "C" ARM int func_020de334(struct Struct_020de334* obj, int a1, int a2, int value) {
    return obj->value == value;
}
