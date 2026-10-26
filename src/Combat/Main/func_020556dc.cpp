#include <globaldefs.h>
extern "C" void func_02056d10(struct Struct_020556dc*);
#include "Memory/SafeAllocator.h"


// USA: func_020556dc
extern "C" ARM bool func_020556dc(void** out, SafeAllocator* alloc) {
    void* p;
    if (alloc == NULL) return false;
    p = alloc->Allocate(0x170);
    *out = p;
    if (p == NULL) return false;
    func_02056d10((struct Struct_020556dc*)(p));
    return true;
}
