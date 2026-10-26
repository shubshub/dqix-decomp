#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"

extern AllocatorUnion g_mainAllocator;
extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);

struct Struct_ov015_0218eef0;
extern "C" void func_ov015_0218eef0(struct Struct_ov015_0218eef0* s);

struct Struct_ov015_0218f0c4 {
    unsigned int unknown_0_;
    void* f04;
    SafeAllocator* f08;
    unsigned int f0c;
    unsigned int f10;
    void* f14;
    unsigned int f18;
    unsigned char f1c;
    unsigned char unknown_1d_[3];
    void* f20;
    void* f24;
    void* f28;
};

// USA: func_ov015_0218f0c4
extern "C" ARM void func_ov015_0218f0c4(void* p) {
    Struct_ov015_0218f0c4* s = (Struct_ov015_0218f0c4*)p;

    if (s->f08 != 0) {
        if (s->f1c == 0 || s->f1c == 1) {
            SafeAllocator* arr = s->f08;
            for (int i = 0; i < 10; i++, arr = (SafeAllocator*)((char*)arr + 0x14)) {
                void* signedAlloc = arr->GetSignedAllocator();
                arr->Destroy();
                AllocatorUnion_Free(&g_mainAllocator, signedAlloc);
            }
        } else {
            void* signedAlloc = s->f08->GetSignedAllocator();
            s->f08->Destroy();
            AllocatorUnion_Free(&g_mainAllocator, signedAlloc);
        }
        AllocatorUnion_Free(&g_mainAllocator, s->f08);
    }

    if (s->f20 != 0) AllocatorUnion_Free(&g_mainAllocator, s->f20);
    if (s->f14 != 0) AllocatorUnion_Free(&g_mainAllocator, s->f14);
    if (s->f24 != 0) AllocatorUnion_Free(&g_mainAllocator, s->f24);
    if (s->f28 != 0) AllocatorUnion_Free(&g_mainAllocator, s->f28);

    if (s->f04 != 0) {
        *((unsigned char*)s->f04 + 4) = 0;
    }

    func_ov015_0218eef0((struct Struct_ov015_0218eef0*)s);
}
