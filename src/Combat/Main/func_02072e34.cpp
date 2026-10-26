#include <globaldefs.h>

struct Struct_02072e34 {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
};

// USA: func_02072e34
extern "C" ARM void func_02072e34(int n, struct Struct_02072e34* out) {
    int base = n * 12;
    out->f0 = n;
    out->f4 = base + 19;
    out->f8 = base + 20;
    out->fc = base + 21;
    out->f10 = base + 22;
    out->f14 = base + 23;
    out->f18 = base + 25;
    out->f1c = base + 27;
    out->f20 = base + 28;
    out->f24 = base + 29;
    out->f28 = -1;
}
