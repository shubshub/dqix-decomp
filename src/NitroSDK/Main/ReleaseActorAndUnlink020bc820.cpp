#include <globaldefs.h>
#include "NitroSDK/Memory/SignedAllocator.h"

struct Obj020bd984;
void NNS_SndHeapDestroy(struct Obj020bd984* obj);

struct Child020bc820 {
    char pad0[8];
    void* backref;
};

struct ListEntry020bc820 {
    char pad0[0xc];
    SignedAllocatorList list;
    char pad2[0xc];
};
extern struct ListEntry020bc820 data_0210f824[];

struct Obj020bc820 {
    char pad0[8];
    struct Obj020bd984* alloc;
    struct Child020bc820* child;
    int index;
};

// USA: func_020bc820
ARM void ReleaseActorAndUnlink020bc820(struct Obj020bc820* obj) {
    struct Obj020bd984* a = obj->alloc;
    if (a == NULL) return;
    NNS_SndHeapDestroy(a);
    if (obj->child != NULL) {
        obj->child->backref = NULL;
        return;
    }
    data_0210f824[obj->index].list.Remove((SignedAllocatorHeader*)obj);
}
