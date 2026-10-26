#include <globaldefs.h>
#include "NitroSDK/Memory/SignedAllocator.h"

extern SignedAllocatorList data_0210f3d8;
extern SignedAllocatorList data_0210f3cc;

struct Struct_020bc79c {
    void* unknown_0_;                  /* 0x0 */
    SignedAllocatorList* unknown_4_;  /* 0x4 */
    void* peer;                      /* 0x8 */
    char pad[0x2c - 0xc];
    unsigned char unknown_2c_;          /* 0x2c */
};

// USA: func_020bc79c
extern "C" ARM void func_020bc79c(struct Struct_020bc79c* obj) {
    if (obj->unknown_0_ != NULL) {
        *(void**)obj->unknown_0_ = NULL;
        obj->unknown_0_ = NULL;
    }
    SignedAllocatorList* owner = obj->unknown_4_;
    owner->Remove((SignedAllocatorHeader*)obj);
    obj->unknown_4_ = NULL;
    if (obj->peer != NULL) {
        ((SignedAllocatorList*)((char*)owner + 0xc))->InsertAtEnd((SignedAllocatorHeader*)obj->peer);
        *(void**)((char*)obj->peer + 0xc) = NULL;
        obj->peer = NULL;
    }
    data_0210f3d8.Remove((SignedAllocatorHeader*)obj);
    data_0210f3cc.InsertAtEnd((SignedAllocatorHeader*)obj);
    obj->unknown_2c_ = 0;
}
