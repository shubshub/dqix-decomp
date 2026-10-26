#include <globaldefs.h>

struct Struct_02082cdc_2 {
    unsigned int a : 10;
    unsigned int b : 10;
    unsigned int c : 10;
    unsigned int hi : 2;
};

struct Struct_02082cdc {
    struct Struct_02082cdc_2 w[3];
};

// USA: func_02082cdc
extern "C" ARM void func_02082cdc(struct Struct_02082cdc* p) {
    p->w[0].a = 0; p->w[0].b = 0; p->w[0].c = 0;
    p->w[1].a = 0; p->w[1].b = 0; p->w[1].c = 0;
    p->w[2].a = 0; p->w[2].b = 0; p->w[2].c = 0;
}
