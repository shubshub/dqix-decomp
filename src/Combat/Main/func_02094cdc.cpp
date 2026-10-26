#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct_0201afd0_5 {
    void* ptr;
};

// USA: func_02094cdc
extern "C" ARM void func_02094cdc(struct Struct_0201afd0_5* obj, int count, SafeAllocator* alloc) {
    obj->ptr = alloc->Allocate(count * 20);
}
