#include <globaldefs.h>

struct Struct_020d1344 {
    unsigned char pad[5];
    unsigned char bit0 : 1;
};

// USA: func_020d1344
extern "C" ARM int func_020d1344() {
    volatile struct Struct_020d1344* p = (struct Struct_020d1344*)0x27ffc30;
    return p->bit0;
}
