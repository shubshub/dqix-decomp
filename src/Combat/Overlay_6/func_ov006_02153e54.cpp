#include <globaldefs.h>

struct Struct_ov006_02153e54 {
    short f0;
    unsigned short f2;
};

// USA: func_ov006_02153e54
extern "C" ARM void func_ov006_02153e54(struct Struct_ov006_02153e54* s) {
    s->f0 = -1;
    s->f2 &= ~1;
    s->f2 &= ~2;
    s->f2 &= 0xffff0003;
}
