#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct_020286fc {
    char pad[0x10];
};

struct Struct_0201a300_6 {
    unsigned char count;           // 0x0
    char pad[3];                   // 0x1..0x3
    struct Struct_020286fc* buffer;   // 0x4
};

struct Struct_02027d94;
extern "C" void func_02027d94(struct Struct_02027d94* obj);

// USA: func_020286fc
extern "C" ARM void func_020286fc(struct Struct_0201a300_6* obj, SafeAllocator* alloc, int count) {
    int i;
    obj->buffer = (struct Struct_020286fc*)alloc->Allocate(count * 16);
    if (obj->buffer == NULL) {
        obj->count = 0;
        return;
    }
    obj->count = count;
    for (i = 0; i < obj->count; i++) {
        func_02027d94((struct Struct_02027d94*)(obj->buffer + i));
    }
}
