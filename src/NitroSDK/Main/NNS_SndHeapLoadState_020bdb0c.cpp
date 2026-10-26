#include <globaldefs.h>
#include "NitroSDK/Memory/HMRFAllocator.h"

extern "C" void func_020bdc60();
extern "C" int func_020bd99c(void* obj);
extern "C" int func_020bdc24(void* objPtr);

struct Obj020bdb0c {
    HMRFAllocator* allocator;
    SignedAllocatorList list;
};

typedef void (*Type_020bdb0c)(void*, int, int, int);

// Main, originally func_020bdb0c (USA 0x020bdb0c, EUR 0x020bdb1c, JPN 0x020bf5d8)
extern "C" ARM void NNS_SndHeapLoadState(struct Obj020bdb0c* obj, int arg1) {
    SignedAllocatorList* var0;
    int var1;
    SignedAllocatorHeader* entry;
    entry = NULL;
    var1 = 0;
    if (arg1 == 0) {
        func_020bd99c(obj);
        return;
    }
    if (arg1 < obj->list.numElements) {
        do {
            var0 = (SignedAllocatorList*)obj->list.ElementBefore(NULL);
            entry = var0->ElementBefore(entry);
            if (entry != NULL) {
                do {
                    Type_020bdb0c cb = *(Type_020bdb0c*)((char*)entry + 0xc);
                    if (cb != NULL) {
                        cb((char*)entry + 0x20, *(int*)((char*)entry + 8), *(int*)((char*)entry + 0x10), *(int*)((char*)entry + 0x14));
                        var1 = 1;
                    }
                    entry = var0->ElementBefore(entry);
                } while (entry != NULL);
            }
            obj->list.Remove((SignedAllocatorHeader*)var0);
        } while (arg1 < obj->list.numElements);
    }
    obj->allocator->RestoreState(arg1);
    if (var1) {
        func_020bdc60();
    }
    obj->allocator->SaveCurrentState(obj->list.numElements);
    func_020bdc24(obj);
}
