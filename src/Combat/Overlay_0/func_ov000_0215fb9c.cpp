#include <globaldefs.h>

struct Struct_ov024_021fea1c { int unknown_0_; int x1; };
extern "C" int func_ov000_0215fb54(int unused, int key, struct Struct_ov024_021fea1c* out);

// USA: func_ov000_0215fb9c
extern "C" ARM int func_ov000_0215fb9c(int unused, short key) {
    struct Struct_ov024_021fea1c out;
    int result = func_ov000_0215fb54(unused, key, &out);
    if (result > 0 || key == 0xf2 || key == 0x1da) {
        return 1;
    }
    return 0;
}
