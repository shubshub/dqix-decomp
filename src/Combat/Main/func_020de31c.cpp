#include <globaldefs.h>

struct Struct_020de31c {
    unsigned int pad[2];
    unsigned int value : 4;
};

// USA: func_020de31c
extern "C" ARM int func_020de31c(struct Struct_020de31c* obj, int value) {
    return obj->value == value;
}
