#include <globaldefs.h>

struct Struct_ov000_02182e6c { short key; short a; short b; short c; };
struct Struct_ov024_021fea1c { int unknown_0_; int x1; };
extern Struct_ov000_02182e6c data_ov000_02182e6c[];

// USA: func_ov000_0215fb54
extern "C" ARM int func_ov000_0215fb54(int unused, int key, Struct_ov024_021fea1c* out) {
    Struct_ov000_02182e6c* p = data_ov000_02182e6c;
    while (p->key != -1) {
        if (p->key == key) {
            out->unknown_0_ = p->a;
            out->x1 = p->b;
            return p->c;
        }
        p++;
    }
    return -1;
}
