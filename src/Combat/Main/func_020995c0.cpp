#include <globaldefs.h>
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "Resource/Script.h"

struct Variant02030b0c;
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);

struct Struct_020995c0 {
    void* mem;
    int pad4;
    int count;
};
extern struct Struct_020995c0* data_02109924;
extern AllocatorUnion g_mainAllocator;

// USA: func_020995c0
extern "C" ARM int func_020995c0(struct Variant02030b0c* p) {
    int v = ((Script::Parameter*)p)->ToInt();
    struct Struct_020995c0* obj = data_02109924;
    void* mem = AllocatorUnion_AllocateRounded(&g_mainAllocator, v << 4);
    obj->mem = mem;
    obj->count = v;
    return 1;
}
