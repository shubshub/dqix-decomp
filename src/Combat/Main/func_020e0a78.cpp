#include <globaldefs.h>

#include "Memory/SafeAllocator.h"

struct FlagWord02046708;

struct Struct_020e0a78 {
#if defined(jpn)
    unsigned char unknown0[0x6c0];
#else
    unsigned char unknown0[0x76c];
#endif
    SafeAllocator *allocator;
    void *unknown_770_;
    unsigned int size;
};

extern "C" void *GlobalFlags_GetInstance();
extern "C" int FlagWord_TestBits(FlagWord02046708 *flags, unsigned int mask);
extern "C" void VectorizedInvertedMemcpy(void *dst, void *src, unsigned int size);
extern "C" void func_020e0df8(void*, int, int, int);
extern "C" void func_020e0cfc(void*, int, int, int);
extern "C" void func_020e0b4c(void *obj, void *buf, int offset, int arg3);
extern "C" void func_020e0ec4(void *obj, void *buf, int offset, int arg3);
extern "C" void OS_WaitVBlankIntr();
void CleanInvalidateCacheRange(const void *addr, unsigned int size);
extern "C" int LoadToSubObjVRAM(void *dst, int mode, unsigned int size);

// JPN: func_020e26ac
// USA: func_020e0a78
extern "C" ARM int func_020e0a78(void *receiver) {
    Struct_020e0a78 *state = static_cast<Struct_020e0a78 *>(receiver);

    if (state->allocator == 0) {
        return 0;
    }
    if (FlagWord_TestBits(static_cast<FlagWord02046708 *>(GlobalFlags_GetInstance()), 0x41)) {
        return 0;
    }

    void *buf = state->allocator->Allocate(state->size);
    VectorizedInvertedMemcpy(state->unknown_770_, buf, state->size);
#if defined(jpn)
    func_020e0df8(receiver, (int)buf, 0, 0x720);
    func_020e0b4c(receiver, buf, 0x720, 0xfc0);
    func_020e0cfc(receiver, (int)buf, 0x1c60, 0x680);
    func_020e0ec4(receiver, buf, 0x16e0, 0x580);
#else
    func_020e0df8(receiver, (int)buf, 0, 0x700);
    func_020e0b4c(receiver, buf, 0x700, 0xfc0);
    func_020e0ec4(receiver, buf, 0x16c0, 0x9c0);
    func_020e0cfc(receiver, (int)buf, 0x2080, 0xd00);
#endif
    OS_WaitVBlankIntr();
    CleanInvalidateCacheRange(buf, state->size);
    LoadToSubObjVRAM(buf, 0, state->size);
    state->allocator->Free(buf);

    return 1;
}
