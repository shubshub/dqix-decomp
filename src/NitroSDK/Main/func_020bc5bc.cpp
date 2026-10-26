#include <globaldefs.h>
#include "NitroSDK/Memory/SignedAllocator.h"

extern "C" void func_020bd99c(void*);

struct Struct_0210f824_4 {
    char pad0[0xc];
    SignedAllocatorList list;  /* 0xc */
    char pad2[0xc];
};
extern struct Struct_0210f824_4 data_0210f824[];

struct Struct_020bc5bc {
    char pad0[8];
    void* field8;                 /* 0x8 */
    struct Struct_020bc5bc* fieldC;  /* 0xc */
};

// USA: func_020bc5bc
extern "C" ARM void* func_020bc5bc(int index, struct Struct_020bc5bc* node) {
    Struct_020bc5bc* e = (Struct_020bc5bc*)data_0210f824[index].list.ElementAfter(NULL);
    if (e == NULL) return NULL;
    data_0210f824[index].list.Remove((SignedAllocatorHeader*)e);
    e->fieldC = node;
    node->field8 = e;
    func_020bd99c(e->field8);
    return e->field8;
}
