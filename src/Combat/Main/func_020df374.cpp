#include <globaldefs.h>

#include "Memory/SafeAllocator.h"

struct Struct_020def98 {
    void* name;
    void* desc;
    unsigned int category : 4;
    unsigned int kind : 5;
    unsigned int flags : 23;
    unsigned char data[0x14];
};

struct Struct_020df374 {
    unsigned short count;
    unsigned short copiedNames : 15;
    unsigned short owned : 1;
    unsigned short capacity;
    unsigned short nameCapacity;
    int unknown_8_;
    Struct_020def98* entries;
};

extern "C" void __clear(void*, unsigned int);
extern "C" int func_020df618(SafeAllocator*, void*, Struct_020def98*, void**, int, Struct_020def98*);

// USA: func_020df374
extern "C" ARM int func_020df374(SafeAllocator* allocator, Struct_020df374* dest,
    Struct_020df374* source, const unsigned char* arg3, short arg4,
    const unsigned char* kinds, short arg6) {
    if (!allocator || !dest || !source || ((!arg3 || !arg4) && (!kinds || !arg6))) return 0;
    Struct_020def98* output = dest->entries;
    Struct_020def98* input = source->entries;
    if (!input) return 0;
    unsigned int var2 = 0;
    unsigned int var3[2];
    __clear(var3, 8);
    if (!arg3) var2 = -1;
    else {
        const unsigned char* category = arg3;
        for (int i = 0; i < arg4; i++) var2 |= 1 << *category++;
    }
    int var6;
    arg3 = kinds;
    if (!arg3) { var3[0] = -1; var3[1] = -1; }
    else for (var6 = 0; var6 < arg6; var6++) var3[var6 >> 5] |= 1 << (*arg3++ & 31);
    int var7 = source->count;
    int capacity;
    if (allocator && !output) {
        int var9;
        int nameCount;
        capacity = 0;
        nameCount = 0;
        for (var9 = 0; var9 < var7; var9++, input++) {
            if ((var2 & (1 << input->category)) && ((1 << (input->kind & 31)) & var3[0])) {
                capacity++;
                if (input->name) nameCount++;
            }
        }
        input = source->entries;
        output = (Struct_020def98*)allocator->Allocate((capacity + nameCount) * 32);
        dest->count = capacity;
        dest->copiedNames = (unsigned short)nameCount;
        dest->entries = output;
    }
    if (!output) return 0;
    int i;
    int copied;
    capacity = dest->count;
    dest->capacity = capacity;
    dest->nameCapacity = dest->copiedNames;
    void* names = allocator ? output + capacity : NULL;
    dest->copiedNames = 0;
    copied = 0;
    i = 0;
    for (; i < var7; i++, input++) {
        if ((var2 & (1 << input->category)) && ((1 << (input->kind & 31)) & var3[0])) {
            func_020df618(allocator, dest, output, &names, (int)source, input);
            if (copied >= capacity) break;
            output++;
            copied++;
        }
    }
    dest->count = copied;
    dest->owned = 0;
    return 1;
}
