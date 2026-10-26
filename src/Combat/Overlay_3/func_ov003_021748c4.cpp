#include <globaldefs.h>
#if defined(jpn)
enum { kRegion103a = 0xfb6 };
enum { kRegion874 = 0x7f0 };
enum { Enum_ov003_021748c4_4166 = 0xfc2 };
enum { Enum_ov003_021748c4_1968 = 0x72c };
#else
enum { kRegion103a = 0x103a };
enum { kRegion874 = 0x874 };
enum { Enum_ov003_021748c4_4166 = 0x1046 };
enum { Enum_ov003_021748c4_1968 = 0x7b0 };
#endif

#include "Memory/SafeAllocator.h"

extern "C" void* GlobalFlags_GetInstance(void);
extern "C" void FlagWord_SetBits(unsigned int* p, unsigned int mask);

extern "C" void func_ov023_021dc9e8(void* a, void* b, int key, void* c, int flags);
extern "C" void func_ov023_021dc134(void* a, int key, int flag);
extern "C" void func_ov023_021dbfd0(void* a, void* b);

// USA: func_ov003_021748c4
extern "C" ARM void func_ov003_021748c4(unsigned char* self) {
    FlagWord_SetBits((unsigned int*)GlobalFlags_GetInstance(), 1);
    unsigned char* field4 = *(unsigned char**)(self + 0x4);
    unsigned short flags = *(unsigned short*)(self + Enum_ov003_021748c4_4166);
    if (flags & 0x800) {
        return;
    }
    SafeAllocator* alloc = (SafeAllocator*)(field4 + 0x28);
    if (flags & 0x80) {
        alloc->Reset();
        short key = *(short*)(self + kRegion103a);
        func_ov023_021dc9e8(self + 0x3c, alloc, key, self + kRegion874, 0x450);
#if !defined(jpn)
        *(unsigned short*)(self + Enum_ov003_021748c4_4166) |= 0x800;
#endif
    } else {
        alloc->Reset();
        short key = *(short*)(self + kRegion103a);
        func_ov023_021dc134(self + 0x3c, key, 0);
        *(unsigned short*)(self + Enum_ov003_021748c4_1968) |= 0x450;
        func_ov023_021dbfd0(self + 0x3c, alloc);
        *(void**)(self + 0x84) = self + kRegion874;
        *(unsigned short*)(self + Enum_ov003_021748c4_4166) |= 0x880;
    }
}
