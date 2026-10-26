#include <globaldefs.h>

struct Struct_ov015_02190d7c_2 { char pad[0x1a8]; int values[32]; int count; };

// USA: func_ov015_021931cc
extern "C" ARM int func_ov015_021931cc(struct Struct_ov015_02190d7c_2* o) {
    int n = o->count;
    if (n <= 0)
        return -1;
    n = n - 1;
    o->count = n;
    int v = o->values[n];
    o->values[n] = -1;
    return v;
}
