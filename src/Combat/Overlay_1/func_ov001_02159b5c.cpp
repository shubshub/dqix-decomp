#include <globaldefs.h>

struct Struct_ov001_02159b94 { int c, d, e; };
struct Struct_ov001_02159b5c_2 { int pad; struct Struct_ov001_02159b94 t; };
struct Struct_ov001_02159b5c { char pad[0x70]; int unknown_70_; };

extern int data_ov001_02165884;
extern "C" int func_ov001_02159b94(int a, int b, struct Struct_ov001_02159b94 t);

// USA: func_ov001_02159b5c
extern "C" ARM int func_ov001_02159b5c(struct Struct_ov001_02159b5c_2* a, struct Struct_ov001_02159b5c* b) {
    func_ov001_02159b94(data_ov001_02165884, b->unknown_70_, a->t);
    return 0;
}
