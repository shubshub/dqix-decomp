#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct_020546c8_11 {
    int field0;
    int field4;
    int field8;
};

// USA: func_02054eb4
extern "C" ARM bool func_02054eb4(struct Struct_020546c8_11** out, SafeAllocator* alloc) {
    struct Struct_020546c8_11* p;
    if (alloc == NULL) return false;
    p = (struct Struct_020546c8_11*)alloc->Allocate(0xc);
    *out = p;
    if (p == NULL) return false;
    p->field0 = 0;
    p->field4 = 0;
    p->field8 = 0;
    return true;
}
