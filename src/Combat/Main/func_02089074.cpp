#include <globaldefs.h>

struct Struct_02089074 {
    unsigned int pad20 : 20;
    unsigned int f20 : 1;
    unsigned int unknown_2_5_ : 1;
    unsigned int unknown_2_6_ : 10;
};

// USA: func_02089074
extern "C" ARM void func_02089074(unsigned char* obj) {
    struct Struct_02089074* b;
    obj[0x7a] = 3;
    obj[0x9d] = 0;
    *(int*)(obj + 0x18) |= 0x40;
    b = (struct Struct_02089074*)(obj + 0x14);
    b->f20 = 0;
    b->unknown_2_5_ = 0;
}
