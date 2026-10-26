#include <globaldefs.h>
#include "NitroSDK/Memory/SignedAllocator.h"

struct Struct_020bc2f0_2;
extern "C" void func_020bc6fc(struct Struct_020bc2f0_2* obj);
extern "C" void func_020bc6a8(SignedAllocatorHeader* arg0);

extern SignedAllocatorList data_0210f3cc;
extern SignedAllocatorList data_0210f3d8;

// USA: func_020bc734
extern "C" ARM SignedAllocatorHeader* func_020bc734(int target) {
    SignedAllocatorHeader* e = data_0210f3cc.ElementAfter(NULL);
    if (e == NULL) {
        e = data_0210f3d8.ElementAfter(NULL);
        if (target < *((unsigned char*)e + 0x3d)) {
            return NULL;
        }
        func_020bc6fc((struct Struct_020bc2f0_2*)e);
    }
    data_0210f3cc.Remove(e);
    *((unsigned char*)e + 0x3d) = target;
    func_020bc6a8(e);
    return e;
}
