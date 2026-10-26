#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct_0208d550_2 {
    void* entries;      /* 0x00 */
    short count;        /* 0x04 */
    short capacity;     /* 0x06 */
};

// USA: func_0208d8ec
extern "C" ARM void func_0208d8ec(struct Struct_0208d550_2* obj, SafeAllocator* alloc, int capacity) {
    if (alloc == NULL) return;
    if (capacity <= 0) return;
    obj->count = 0;
    obj->capacity = capacity;
    obj->entries = alloc->Allocate(capacity * 0x18);
}
