#include <globaldefs.h>
extern "C" struct Struct_02097628* func_02097668(struct Struct_02097628_2*, int);

struct Struct_02097628 { struct Struct_02097628* next; char pad[0x16]; short key; };

// USA: func_02097628
extern "C" ARM void func_02097628(void* c) {
    struct Struct_02097628* p = *(struct Struct_02097628**)c = func_02097668((struct Struct_02097628_2*)(c), (int)(-1));
    if (p == 0) return;
    while (p != 0) {
        struct Struct_02097628* next = func_02097668((struct Struct_02097628_2*)(c), (int)(p->key));
        p->next = next;
        p = next;
    }
}
