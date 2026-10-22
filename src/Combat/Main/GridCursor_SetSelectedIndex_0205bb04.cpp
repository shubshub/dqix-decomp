#include <globaldefs.h>

struct SelfBB04 {
    int f0;
    char pad4[4];
    int f8;
    int fc;
    char pad10[4];
    int f14;
    char pad18[0x24 - 0x18];
    int* f24;
    int* f28;
    int* f2c;
};

// USA: func_0205bb04  (semantic: ComputeDivisions0205bb04)
extern "C" ARM void func_0205bb04(struct SelfBB04* self, int value) {
    if (value < 0) return;
    if (value >= self->f0) return;
    int product = self->fc * self->f8;
    if (product == 0) return;
    self->f14 = value / product;
    value = value % product;
    *self->f2c = value % *self->f24;
    *self->f28 = value / *self->f24;
}
