#include <globaldefs.h>

struct Struct_ov001_02157964_3 { int c, d, e; };
struct Struct_ov001_0215942c { int pad; struct Struct_ov001_02157964_3 t; };

extern "C" void func_ov001_02157964(void*, struct Struct_ov001_02157964_3);

// USA: func_ov001_0215942c
extern "C" ARM int func_ov001_0215942c(struct Struct_ov001_0215942c* a, void* b) {
    func_ov001_02157964((char*)b + 0x11c, a->t);
    return 0;
}
