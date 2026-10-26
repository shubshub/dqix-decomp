#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct_02109d94_4 {
    char pad[8];
    SafeAllocator* alloc;
};
extern struct Struct_02109d94_4 data_02109d94;

struct Struct_020a14fc {
    void* items;              // 0x0
    unsigned short capacity;  // 0x4
    unsigned short used;      // 0x6
    char pad[4];               // 0x8
    void* unknown_c_;               // 0xc
};

// USA: func_020a14fc
extern "C" ARM void func_020a14fc(struct Struct_020a14fc* obj, void* flag, int count) {
    int var0;
    if (flag == NULL || count == 0) return;

    obj->items = data_02109d94.alloc->Allocate(count * 0xc);
    obj->capacity = (unsigned short)count;
    obj->used = 0;

    var0 = (obj->capacity - 1) / 8 + 1;
    obj->unknown_c_ = data_02109d94.alloc->Allocate(var0);
}
