#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

extern "C" char* func_020da150(SafeAllocator* allocator, const char* src);

struct Struct_020def98 {
    void* name;
    void* desc;
    unsigned char data[0x18];
};
struct Struct_020df618 {
    unsigned short counter : 15;
    unsigned short flag : 1;
};

// USA: func_020df618
extern "C" ARM int func_020df618(SafeAllocator* allocator, void* b, Struct_020def98* dst, void** e, int unused, Struct_020def98* src) {
    memcpy(dst, src, sizeof(Struct_020def98));
    dst->desc = (src->desc != NULL) ? func_020da150(allocator, (const char*)src->desc) : NULL;
    dst->name = NULL;
    if (src->name != NULL && *e != NULL) {
        dst->name = *e;
        *e = (char*)dst->name + 0x20;
        memcpy(dst->name, src->name, 0x20);
        ((Struct_020df618*)((char*)b + 2))->counter++;
    }
    return 1;
}
