#include <globaldefs.h>
#include "NitroSDK/Memory/HMRFAllocator.h"

extern "C" int func_020bdc24(void* obj);

struct Struct_020bd914 {
    HMRFAllocator* allocator;   /* 0x00 */
    SignedAllocatorList list;   /* 0x04 */
};

// USA: func_020bdbf0
extern "C" ARM int func_020bdbf0(struct Struct_020bd914* obj, HMRFAllocator* allocator) {
    obj->list.Initialize(0xc);
    obj->allocator = allocator;
    return func_020bdc24(obj) != 0;
}
