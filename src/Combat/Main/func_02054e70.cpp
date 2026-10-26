#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct_020546c8_12 {
    int f0;
    int f4;
    int f8;
};

// USA: func_02054e70
extern "C" ARM int func_02054e70(struct Struct_020546c8_12** out, SafeAllocator* alloc) {
    struct Struct_020546c8_12* p;
    if (alloc == NULL) return 0;
    p = (struct Struct_020546c8_12*)alloc->Allocate(0xc);
    *out = p;
    if (p == NULL) return 0;
    p->f0 = 0;
    p->f4 = 0;
    p->f8 = 0;
    return 1;
}
