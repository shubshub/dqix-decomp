#include <globaldefs.h>

struct Struct_0205c508 {
    int field0;
    unsigned char pad4[4];
    int field8;
    int fieldc;
    unsigned char pad10[4];
    int field14;
};

// USA: func_0205c508
extern "C" ARM void func_0205c508(struct Struct_0205c508* s, int* out1, int* out2) {
    int a = s->field8 * s->fieldc;
    int b = a * s->field14;
    *out1 = b;
    *out2 = b + a;
    if (s->field0 < *out2) {
        *out2 = s->field0;
    }
}
