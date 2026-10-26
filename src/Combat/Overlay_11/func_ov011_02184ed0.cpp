#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct TaggedNumber02184c30 {
    int type;
    union { int i; float f; } value;
};

extern "C" int func_ov011_02184c30(struct TaggedNumber02184c30* v);
extern "C" ARM void* func_ov017_021b2164(void);
extern "C" ARM void* func_ov011_021845f4(void);
extern "C" ARM void* func_ov011_021842c8(unsigned char* node, unsigned int id);
extern "C" ARM void func_ov011_021842a0(void* obj);

struct Struct_ov011_02184354;
extern "C" int func_ov011_02184354(Struct_ov011_02184354* obj, int val);

struct Struct_ov011_02184ed0 {
    int id;
    SafeAllocator allocator;
};

// USA: func_ov011_02184ed0
extern "C" ARM int func_ov011_02184ed0(struct TaggedNumber02184c30* params, int count, Struct_ov011_02184ed0* heap) {
    unsigned int var0;
    int id;
    unsigned char* var2;
    Struct_ov011_02184ed0* parent;
    void* buffer;

    var0 = func_ov011_02184c30(&params[0]);
    id = func_ov011_02184c30(&params[1]);
    func_ov017_021b2164();
    var2 = (unsigned char*)func_ov011_021845f4();
    parent = (Struct_ov011_02184ed0*)func_ov011_021842c8(var2, var0);
    if (parent == 0)
        return 0;
    if (func_ov011_021842c8(var2, id) != 0)
        return 0;

    heap = (Struct_ov011_02184ed0*)parent->allocator.Allocate(0x20);
    if (heap == 0)
        return 0;

    func_ov011_021842a0(heap);
    heap->id = id;
    if (count >= 3)
        var0 = func_ov011_02184c30(&params[2]);
    else
        var0 = parent->allocator.GetMaxPossibleAllocation();
    if (var0 == 0)
        return 0;

    buffer = parent->allocator.Allocate(var0);
    if (buffer == 0)
        return 0;

    heap->allocator.CreateTypeB(buffer, var0, 4);
    func_ov011_02184354((Struct_ov011_02184354*)parent, (int)heap);
    return 1;
}
