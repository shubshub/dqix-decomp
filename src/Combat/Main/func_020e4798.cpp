#include <globaldefs.h>

extern "C" int sprintf(int, int);

struct Struct_020e4798 {
    int field0;
    int field4;
};

// USA: func_020e4798
extern "C" ARM int func_020e4798(int a, struct Struct_020e4798* b) {
    if (b->field4 != 0) {
        return a + sprintf(a, b->field4);
    }
    return a;
}
