#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct_ov028_021d977c {
    char pad[0x44];
    class SafeAllocator allocator;
};

extern "C" ARM void func_ov028_021d9494(struct Struct_ov028_021d977c* obj);

// USA: func_ov028_021d977c
extern "C" ARM struct Struct_ov028_021d977c* func_ov028_021d977c(struct Struct_ov028_021d977c* obj) {
    obj->allocator.ResetAllocatorPointer();
    func_ov028_021d9494(obj);
    return obj;
}
