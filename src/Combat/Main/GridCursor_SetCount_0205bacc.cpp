#include <globaldefs.h>

struct Struct_0205bb84;
int GridCursor_GetSelectedIndex(struct Struct_0205bb84* s);
extern "C" void func_0205bb04(void* s, int n);

struct Node0205bacc {
    int field0;
};

// USA: func_0205bacc
ARM void SetField0AndPropagate0205bacc(struct Node0205bacc* s, int val) {
    if (val < 0) return;
    s->field0 = val;
    if (GridCursor_GetSelectedIndex((struct Struct_0205bb84*)s) < val) return;
    func_0205bb04(s, val - 1);
}
