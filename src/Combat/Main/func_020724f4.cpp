#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct_020724f4 {
    void* ptr;
    unsigned short count;
    unsigned short pad;
};

// USA: func_020724f4
extern "C" ARM void func_020724f4(Struct_020724f4* obj, SafeAllocator* alloc, unsigned int count) {
    if (obj->ptr != NULL) {
        return;
    }
    obj->pad = 0;
    obj->count = count;
    obj->ptr = alloc->Allocate(count * 0x2c);
    for (unsigned short i = 0; i < count; i++) {
        *(short*)((char*)obj->ptr + i * 0x2c) = -1;
    }
}
