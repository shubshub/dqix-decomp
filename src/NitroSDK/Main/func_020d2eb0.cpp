#include <globaldefs.h>

struct Struct_020be53c {
    char pad[0x38];
    int field0x38;
};

// USA: func_020d2eb0
extern "C" ARM int func_020d2eb0(struct Struct_020be53c* p) {
    return p->field0x38;
}
