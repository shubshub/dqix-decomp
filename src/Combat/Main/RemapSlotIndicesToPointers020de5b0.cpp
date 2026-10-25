#include <globaldefs.h>

struct Elem020de5b0 { unsigned int idx; char pad[0x20 - 0x4]; };
struct Container020de5b0 { unsigned short count; char pad2[0xc - 0x2]; struct Elem020de5b0* arr; };
struct ItemTable;
int ApplyField0x16FromKeyTable020de5fc(struct ItemTable* container);

// USA: func_020de5b0
ARM int RemapSlotIndicesToPointers020de5b0(struct Container020de5b0* c) {
    struct Elem020de5b0* base2 = c->arr + c->count;
    struct Elem020de5b0* p = c->arr;
    unsigned short count = c->count;
    int i;
    for (i = 0; i < count; i++, p++) {
        unsigned int nv = 0;
        int v = (int)p->idx;
        if (v != -1) nv = (unsigned int)(base2 + v);
        p->idx = nv;
    }
    ApplyField0x16FromKeyTable020de5fc((struct ItemTable*)c);
    return 1;
}
