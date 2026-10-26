#include <globaldefs.h>

struct Struct_02047a3c_2 {
    char pad0;
    unsigned char unknown_1_;
    char pad2[6];
};

struct Struct_02047a3c {
    char pad0[8];
    struct Struct_02047a3c_2* elements;
    char pad1[0x84 - 0xc];
    unsigned char enabled : 1;
    unsigned char unknown_84_1_ : 7;
};

// USA: func_02047a3c
extern "C" ARM int func_02047a3c(struct Struct_02047a3c* obj, int index) {
    if (obj->enabled) {
        return obj->elements[index].unknown_1_;
    }
    return 0;
}
