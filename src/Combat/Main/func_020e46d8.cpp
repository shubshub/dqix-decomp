#include <globaldefs.h>

extern "C" int sprintf(int, int);

struct Struct_020e46d8 {
    int field0;
    int field4;
};

// USA: func_020e46d8
extern "C" ARM int func_020e46d8(int a, struct Struct_020e46d8* b) {
    if (b->field0 != 0) {
        return a + sprintf(a, b->field0);
    }
    return a;
}
