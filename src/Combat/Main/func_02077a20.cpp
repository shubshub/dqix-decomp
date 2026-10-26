#include <globaldefs.h>

struct Struct_02077a20 {
    char pad[8];
    short val;
};

struct Struct_02077788_2 {
    char pad[0x184];
    struct Struct_02077a20* inner;
};

// USA: func_02077a20
extern "C" ARM int func_02077a20(struct Struct_02077788_2* p) {
    struct Struct_02077a20* inner = p->inner;
    return inner != NULL ? inner->val : 0x1000;
}
