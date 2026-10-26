#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"

struct TaggedNumber02184c30 {
    int type;
    union { int i; float f; } value;
};

struct Struct_ov011_02184de4 {
    TaggedNumber02184c30 a;
    TaggedNumber02184c30 b;
};

extern "C" int func_ov011_02184c30(struct TaggedNumber02184c30* v);
extern "C" ARM void* func_ov017_021b2164(void);
extern "C" ARM void* func_ov011_021845f4(void);
extern "C" ARM void* func_ov011_021842c8(unsigned char* node, unsigned int id);
extern "C" ARM void func_ov011_021842a0(void* obj);
extern "C" ARM void* func_ov011_02184324(void* a, void* b);

// USA: func_ov011_02184de4
extern "C" ARM int func_ov011_02184de4(struct Struct_ov011_02184de4* obj) {
    void* var0 = GetGameResources();
    void* ctx = func_ov017_021b2164();
    ctx = func_ov011_021845f4();

    int tag0 = func_ov011_02184c30(&obj->a);
    void* var3;
    int tag8 = func_ov011_02184c30(&obj->b);

    void* n1 = func_ov011_021842c8((unsigned char*)ctx, tag8);
    if (n1 != 0) return 0;

    var3 = 0;
    switch (tag0) {
    case 0: var3 = (char*)var0 + 0x38; break;
    case 1: var3 = (char*)var0 + 0xc4; break;
    case 2: var3 = (char*)var0 + 0x9c; break;
    }
    if (var3 == 0) return 0;

    void* buf = ((SafeAllocator*)var3)->Allocate(0x20);
    if (buf == 0) return 0;

    func_ov011_021842a0(buf);
    *(int*)buf = tag8;

    unsigned int maxAlloc = ((SafeAllocator*)var3)->GetMaxPossibleAllocation();
    void* buf2 = ((SafeAllocator*)var3)->Allocate(maxAlloc);
    if (buf2 == 0) return 0;

    ((SafeAllocator*)((char*)buf + 4))->CreateTypeB(buf2, maxAlloc, 4);

    func_ov011_02184324(ctx, buf);
    return 1;
}
