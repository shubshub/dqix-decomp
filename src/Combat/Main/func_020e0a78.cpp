#include <globaldefs.h>

#include "Memory/SafeAllocator.h"

struct Struct_02012de8;

struct Struct_020e0a78 {
#if defined(jpn)
    unsigned char unknown_0_[0x6c0];
#else
    unsigned char unknown1_0_[0x76c];
#endif
    SafeAllocator *unknown_76c_;
    void *unknown_770_;
    unsigned int unknown_774_;
};

void *GlobalFlags_GetInstance();
int FlagWord_TestBits(FlagWord02046708 *flags, unsigned int mask);
extern "C" void VectorizedInvertedMemcpy(void *dst, void *src, unsigned int size);
void SetupWeightedEntriesAndSubmit_020e0df8(void*, int, int, int);
void SetupWeightedEntriesAndSubmitPair020e0cfc(void*, int, int, int);
extern "C" void func_020e0b4c(void *obj, void *buf, int offset, int dead_r3);
extern "C" void func_020e0ec4(void *obj, void *buf, int offset, int dead_r3);
void OS_WaitVBlankIntr();
void CleanInvalidateCacheRange(const void *addr, unsigned int size);
extern "C" int LoadToSubObjVRAM(void *dst, int mode, unsigned int size);

// JPN: func_020e26ac
// USA: func_020e0a78
extern "C" ARM int func_020e0a78(void *arg0) {
    Struct_020e0a78 *var0 = static_cast<Struct_020e0a78 *>(arg0);

    if (var0->unknown_76c_ == 0) {
        return 0;
    }
    if (FlagWord_TestBits(static_cast<FlagWord02046708 *>(GlobalFlags_GetInstance()), 0x41)) {
        return 0;
    }

    void *var1 = var0->unknown_76c_->Allocate(var0->unknown_774_);
    VectorizedInvertedMemcpy(var0->unknown_770_, var1, var0->unknown_774_);
#if defined(jpn)
    func_020e0df8(arg0, (int)var1, 0, 0x720);
    func_020e0b4c(arg0, var1, 0x720, 0xfc0);
    func_020e0cfc(arg0, (int)var1, 0x1c60, 0x680);
    func_020e0ec4(arg0, var1, 0x16e0, 0x580);
#else
    func_020e0df8(arg0, (int)var1, 0, 0x700);
    func_020e0b4c(arg0, var1, 0x700, 0xfc0);
    func_020e0ec4(arg0, var1, 0x16c0, 0x9c0);
    func_020e0cfc(arg0, (int)var1, 0x2080, 0xd00);
#endif
    OS_WaitVBlankIntr();
    CleanInvalidateCacheRange(buf, state->size);
    LoadToSubObjVRAM(buf, 0, state->size);
    state->allocator->Free(buf);

    return 1;
}
