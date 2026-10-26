#include <globaldefs.h>

struct Struct_02108d5c {
    unsigned char active;
    unsigned char pad[0xB];
    int unknown_c_;
    int unknown_10_;
};

// USA: func_02070508
extern "C" ARM void func_02070508(struct Struct_02108d5c *obj) {
    obj->active = 0;
    obj->unknown_c_ = 0;
    obj->unknown_10_ = 0;
}
