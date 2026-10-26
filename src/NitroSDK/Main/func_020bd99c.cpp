#include <globaldefs.h>
#include "NitroSDK/Memory/HMRFAllocator.h"

extern "C" void func_020bdc60();
extern "C" int func_020bdc24(void* objPtr);

struct Struct_020bd99c {
    HMRFAllocator* allocator;
    SignedAllocatorList list;
};

typedef void (*Type_020bd99c)(void*, int, int, int);

// USA: func_020bd99c
extern "C" ARM int func_020bd99c(struct Struct_020bd99c* obj) {
    SignedAllocatorList* var0;
    int var1 = 0;
    var0 = (SignedAllocatorList*)obj->list.ElementBefore(NULL);
    if (var0 != NULL) {
        do {
            SignedAllocatorHeader* entry = var0->ElementBefore(NULL);
            if (entry != NULL) {
                do {
                    Type_020bd99c cb = *(Type_020bd99c*)((char*)entry + 0xc);
                    if (cb != NULL) {
                        cb((char*)entry + 0x20, *(int*)((char*)entry + 8), *(int*)((char*)entry + 0x10), *(int*)((char*)entry + 0x14));
                        var1 = 1;
                    }
                    entry = var0->ElementBefore(entry);
                } while (entry != NULL);
            }
            obj->list.Remove((SignedAllocatorHeader*)var0);
            var0 = (SignedAllocatorList*)obj->list.ElementBefore(NULL);
        } while (var0 != NULL);
    }
    obj->allocator->Free(3);
    if (var1) {
        func_020bdc60();
    }
    return func_020bdc24(obj);
}
