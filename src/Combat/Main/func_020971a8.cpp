#include <globaldefs.h>

struct Struct_02097054_6 { char pad[0x30]; };
struct Struct_02097054_5 { unsigned short count; char pad[6]; struct Struct_02097054_6* base; };
typedef int (*Type_020971a8)(struct Struct_02097054_6*);

// USA: func_020971a8
extern "C" ARM struct Struct_02097054_6* func_020971a8(struct Struct_02097054_5* c, int key, Type_020971a8 arg2) {
    struct Struct_02097054_6* base = c->base;
    int lo, hi, var3, r, count;
    struct Struct_02097054_6* elem;
    if (base == NULL || arg2 == NULL) return NULL;
    count = c->count;
    if (count == 0) return NULL;
    hi = count - 1;
    lo = 0;
    while (lo <= hi) {
        var3 = lo + ((hi - lo + 1) >> 1);
        elem = base + var3;
        r = arg2(elem);
        if (r == key) return elem;
        if (r > key) hi = var3 - 1;
        else lo = var3 + 1;
    }
    return NULL;
}
