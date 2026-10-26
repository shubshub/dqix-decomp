#include <globaldefs.h>
extern "C" struct Struct_020976e0* func_02097720(struct Struct_020976e0_2*, int);

struct Struct_020976e0 { struct Struct_020976e0* next; char pad[0xa]; short key; };

// USA: func_020976e0
extern "C" ARM void func_020976e0(void* c) {
    struct Struct_020976e0* p = *(struct Struct_020976e0**)c = func_02097720((struct Struct_020976e0_2*)(c), (int)(-1));
    if (p == 0) return;
    while (p != 0) {
        struct Struct_020976e0* next = func_02097720((struct Struct_020976e0_2*)(c), (int)(p->key));
        p->next = next;
        p = next;
    }
}
