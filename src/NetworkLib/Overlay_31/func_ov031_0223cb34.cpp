#include <globaldefs.h>

struct Struct_ov031_0223cb34 { unsigned short x, y; };
struct Struct_ov031_0223cb34_2 { unsigned short x, y, x2, y2; };

// USA: func_ov031_0223cb34
extern "C" ARM void func_ov031_0223cb34(Struct_ov031_0223cb34* a, Struct_ov031_0223cb34* b, Struct_ov031_0223cb34_2* out) {
    out->x = a->x;
    out->y = a->y;
    out->x2 = a->x + b->x;
    out->y2 = a->y + b->y;
}
