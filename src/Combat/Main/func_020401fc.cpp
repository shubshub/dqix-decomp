#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct_02040258;
extern "C" ARM void func_02040258(struct Struct_02040258* obj);

struct Struct_0203d028_6 {
    unsigned int count;
    unsigned char field4;
    unsigned char field5;
    unsigned char pad6[2];
    void* elements;
};

// USA: func_020401fc
extern "C" ARM void func_020401fc(struct Struct_0203d028_6* pool, unsigned int count, SafeAllocator* alloc) {
    unsigned int i;
    pool->field4 = 0;
    pool->count = count;
    pool->field5 = 0;
    pool->elements = alloc->Allocate(pool->count * 0x3c);
    for (i = 0; i < pool->count; i++) {
        func_02040258((struct Struct_02040258*)((char*)pool->elements + i * 0x3c));
    }
}
