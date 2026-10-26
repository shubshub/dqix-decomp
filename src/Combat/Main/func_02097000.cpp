#include <globaldefs.h>

struct Struct_02097000 { char pad[0x30]; };
struct Struct_02097000_2 { unsigned short count; char pad[6]; struct Struct_02097000* nodes; };
typedef void (*Type_02097000)(struct Struct_02097000_2*, struct Struct_02097000*);

// USA: func_02097000
extern "C" ARM int func_02097000(struct Struct_02097000_2* c, Type_02097000 fn) {
    int n;
    struct Struct_02097000* p;
    int i;
    p = c->nodes;
    if (p == NULL || (n = c->count) == 0 || fn == NULL) return 0;
    for (i = 0; i < n; p++) {
        fn(c, p);
        i++;
    }
    return 1;
}
