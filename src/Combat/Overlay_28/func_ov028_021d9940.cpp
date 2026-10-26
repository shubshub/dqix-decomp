#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct_ov028_021d9940 {
    char pad0[4];
    void* field4;
    unsigned short field8;
    unsigned short fielda;
};

extern "C" void func_ov028_021d987c(void*);

// USA: func_ov028_021d9940
extern "C" ARM void func_ov028_021d9940(Struct_ov028_021d9940* obj, SafeAllocator* allocator, unsigned int count) {
    obj->field4 = allocator->Allocate(count * 0xc);
    for (unsigned short i = 0; i < count; i++) {
        func_ov028_021d987c((char*)obj->field4 + i * 0xc);
    }
    obj->field8 = 0;
    obj->fielda = (unsigned short)count;
}
