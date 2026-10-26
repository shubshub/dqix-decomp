#include <globaldefs.h>

struct Struct_020deb08 {
    unsigned short a;
    unsigned short pad2;
    unsigned short b;
};

// USA: func_020deb08
extern "C" ARM short func_020deb08(struct Struct_020deb08* obj) {
    int a = obj->a;
    int b = obj->b;
    return a > b ? a : b;
}
