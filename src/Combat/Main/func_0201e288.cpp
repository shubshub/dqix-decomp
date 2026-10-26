#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "World/ZoneFeatures.h"

struct Struct_0201e288 {
    char  pad[0x30];
    void* ptr;
    int   idx;
    int   count;
};

// USA: func_0201e288
ARM void ZoneFeatures::func_0201e288(int count, SafeAllocator* alloc) {
    struct Struct_0201e288* obj = (struct Struct_0201e288*)this;
    obj->ptr = alloc->Allocate(count * 0x10);
    obj->idx = 0;
    obj->count = count;
}
