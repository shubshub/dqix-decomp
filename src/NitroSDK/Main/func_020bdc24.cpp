#include <globaldefs.h>
#include "NitroSDK/Memory/HMRFAllocator.h"

extern "C" void func_020bdbe0(SignedAllocatorList* list);

struct Struct_020bdc24 {
    HMRFAllocator* allocator;
    SignedAllocatorList list;
};

// USA: func_020bdc24
extern "C" ARM int func_020bdc24(void* objPtr) {
    struct Struct_020bdc24* obj = (struct Struct_020bdc24*)objPtr;
    void* p = obj->allocator->Allocate(0x14, 4);
    if (p == NULL) return 0;
    func_020bdbe0((SignedAllocatorList*)p);
    obj->list.InsertAtEnd((SignedAllocatorHeader*)p);
    return 1;
}
