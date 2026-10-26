#include <globaldefs.h>

struct Struct_0208bf78_5;

struct Struct_0208dadc {
    char pad[0x14];
    int unknown_14_;
};

extern "C" struct Struct_0208dadc* func_0208d994(struct Struct_0208bf78_5* l, int key);

// USA: func_0208dadc
extern "C" ARM int func_0208dadc(struct Struct_0208bf78_5* l, int key) {
    struct Struct_0208dadc* e = func_0208d994(l, key);
    return e ? e->unknown_14_ : 0;
}
