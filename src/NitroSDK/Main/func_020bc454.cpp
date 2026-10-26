#include <globaldefs.h>
#include "NitroSDK/Memory/SignedAllocator.h"

struct Struct_020bc084;
extern "C" void func_020bc084(struct Struct_020bc084** slot);

struct Struct_020bc2f0_2;
extern "C" void func_020bc6fc(struct Struct_020bc2f0_2* obj);

extern "C" void func_020bc658(SignedAllocatorList* list, SignedAllocatorHeader* arg1);
extern "C" SignedAllocatorHeader* func_020bc734(int priority);

struct Struct_020bc454 {
    void* field0;
};

struct Struct_0210f824_3 {
    SignedAllocatorList list;
    char unknown_c_[0x18 - 0xc];
    unsigned int capacity;
    char unknown_1c_[0x24 - 0x1c];
};
extern struct Struct_0210f824_3 data_0210f824[];

// USA: func_020bc454
extern "C" ARM void* func_020bc454(struct Struct_020bc454* obj, int index, int priority) {
    struct Struct_0210f824_3* c = &data_0210f824[index];

    if (obj->field0 != NULL) {
        func_020bc084((struct Struct_020bc084**)obj);
    }

    if (c->list.numElements >= c->capacity) {
        SignedAllocatorHeader* first = c->list.ElementAfter(NULL);
        if (first == NULL) {
            return NULL;
        }
        if (priority < *((unsigned char*)first + 0x3d)) {
            return NULL;
        }
        func_020bc6fc((struct Struct_020bc2f0_2*)first);
    }

    {
        SignedAllocatorHeader* e = func_020bc734(priority);
        if (e == NULL) {
            return NULL;
        }
        func_020bc658(&c->list, e);
        *(void**)e = obj;
        obj->field0 = e;
        return e;
    }
}
