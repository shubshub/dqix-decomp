#include <globaldefs.h>

struct Struct_02097240;

extern "C" short func_02097240(struct Struct_02097240* obj);

struct Struct_02097430 { char pad[0x20]; };

struct Struct_02097430_2 {
    unsigned int pad0;
    unsigned int count : 12;
    unsigned int rest : 20;
    struct Struct_02097430* base;
};

extern "C" {
// USA: func_02097430
extern "C" ARM struct Struct_02097430* func_02097430(struct Struct_02097430_2* c, int key) {
    int count;
    struct Struct_02097430* res;
    int var2;
    int r;
    int hi;
    int lo;
    struct Struct_02097430* base;
    if (c->base == NULL || (int)func_02097240 == 0) {
        res = NULL;
        goto out;
    }
    count = c->count;
    if (count == 0) {
        res = NULL;
        goto out;
    }
    hi = count - 1;
    lo = 0;
    base = c->base;
    while (lo <= hi) {
        var2 = lo + ((hi - lo + 1) >> 1);
        res = base + var2;
        r = func_02097240((struct Struct_02097240*)res);
        if (r == key) goto out;
        if (r > key) hi = var2 - 1;
        else lo = var2 + 1;
    }
    res = NULL;
out:
    return res;
}
}
