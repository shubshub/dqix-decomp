#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct_020263e4 {
#if defined(jpn)
    char pad[0x6c0];
#else
    char pad[0x76c];
#endif
    SafeAllocator* alloc;
    void* data;
    int unknown_774_;
};

// USA: func_020263e4
extern "C" ARM void func_020263e4(struct Struct_020263e4* obj) {
    if (obj->alloc != NULL && obj->data != NULL) {
        obj->alloc->Free(obj->data);
    }
    obj->alloc = NULL;
    obj->data = NULL;
    obj->unknown_774_ = 0;
}
