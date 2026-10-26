#include <globaldefs.h>

struct Struct_0203cec4 {
    char pad[0x5c];
    unsigned int flags;
};

// USA: func_0203cec4
extern "C" ARM void func_0203cec4(struct Struct_0203cec4* obj, int enable) {
    if (enable) {
        obj->flags |= 0x8;
    } else {
        obj->flags &= ~0x8;
    }
}
