#include <globaldefs.h>

struct Struct_020891b0 {
    unsigned char pad[0x3c];
    unsigned char bit0 : 1;
};

// USA: func_020891b0
extern "C" ARM void func_020891b0(struct Struct_020891b0* obj) {
    if (obj->bit0) {
        obj->bit0 = 0;
    } else {
        obj->bit0 = 1;
    }
}
