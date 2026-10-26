#include <globaldefs.h>
#include "NitroSDK/Memory/SignedAllocator.h"

struct Obj020bd984;
extern "C" void NNS_SndHeapDestroy(struct Obj020bd984* obj);

struct Struct_020bc820_2 {
    char pad0[8];
    void* unknown_8_;
};

struct Struct_0210f824_5 {
    char pad0[0xc];
    SignedAllocatorList list;
    char pad2[0xc];
};
extern struct Struct_0210f824_5 data_0210f824[];

struct Struct_020bc820 {
    char pad0[8];
    struct Obj020bd984* alloc;
    struct Struct_020bc820_2* child;
    int index;
};

// USA: func_020bc820
extern "C" ARM void func_020bc820(struct Struct_020bc820* obj) {
    struct Obj020bd984* a = obj->alloc;
    if (a == NULL) return;
    NNS_SndHeapDestroy(a);
    if (obj->child != NULL) {
        obj->child->unknown_8_ = NULL;
        return;
    }
    data_0210f824[obj->index].list.Remove((SignedAllocatorHeader*)obj);
}
