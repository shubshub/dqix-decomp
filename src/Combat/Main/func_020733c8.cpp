#include <globaldefs.h>

struct Struct_020733c8 {
    char pad[8];
    int f8;
};

// USA: func_020733c8
extern "C" ARM void func_020733c8(struct Struct_020733c8* obj) {
    if (obj != NULL) {
        obj->f8 = 0;
    }
}
