#include <globaldefs.h>

struct Elem_0205d81c;
struct Struct_0205d81c;
extern "C" struct Elem_0205d81c* func_0205d81c(struct Struct_0205d81c* s, int key);
extern "C" void func_02050400(unsigned char* obj, int value);

// USA: func_ov000_0217a9d0
extern "C" ARM void func_ov000_0217a9d0(int key, int b, int c, struct Struct_0205d81c* s) {
    struct Elem_0205d81c* elem = func_0205d81c(s, key);
    int v;
    if (elem == 0) return;
    v = 0;
    if (c < b) v = 1;
    func_02050400((unsigned char*)elem, v);
}
