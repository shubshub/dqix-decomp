#include <globaldefs.h>

struct Struct_020de5b0_3 { unsigned int idx; char pad[0x20 - 0x4]; };
struct Struct_020de5b0 { unsigned short count; char pad2[0xc - 0x2]; struct Struct_020de5b0_3* arr; };
struct ItemTable;
extern "C" int ApplyField0x16FromKeyTable020de5fc(struct ItemTable* container);

// USA: func_020de5b0
extern "C" ARM int func_020de5b0(struct Struct_020de5b0* c) {
    struct Struct_020de5b0_3* base2 = c->arr + c->count;
    struct Struct_020de5b0_3* p = c->arr;
    unsigned short count = c->count;
    int i;
    for (i = 0; i < count; i++, p++) {
        unsigned int var4 = 0;
        int v = (int)p->idx;
        if (v != -1) var4 = (unsigned int)(base2 + v);
        p->idx = var4;
    }
    ApplyField0x16FromKeyTable020de5fc((struct ItemTable*)c);
    return 1;
}
