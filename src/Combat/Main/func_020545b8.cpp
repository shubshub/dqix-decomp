#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct_020545b8 {
    char pad0[4];
    SafeAllocator allocs[10];
    char pad1[0x460];
    SafeAllocator unknown_52c_;
    SafeAllocator unknown_540_;
    SafeAllocator unknown_554_;
    char pad2[0x70];
    SafeAllocator unknown_5d8_;
};

// USA: func_020545b8
extern "C" ARM void func_020545b8(struct Struct_020545b8* obj) {
    int i;
    for (i = 0; i < 10; i++) {
        if (obj->allocs[i].GetSignedAllocator()) {
            obj->allocs[i].Destroy();
        }
    }
    SafeAllocator* arr[4] = { &obj->unknown_52c_, &obj->unknown_540_, &obj->unknown_554_, &obj->unknown_5d8_ };
    int j;
    for (j = 0; j < 4; j++) {
        SafeAllocator* p = arr[j];
        if (p->GetSignedAllocator()) {
            p->Destroy();
        }
    }
}
