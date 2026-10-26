#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Combat/MapDisplay.h"

struct ClearTarget0205a234;
struct Struct_020e2490;

extern "C" void Sprite_Init(Struct0205a198* s);
extern "C" void func_0205a234(ClearTarget0205a234* t);
extern "C" void func_020e2490(Struct_020e2490* mgr, int arg1, int arg2, void* arg3, SafeAllocator* alloc, int count, unsigned char flag);

struct Struct_ov003_02158a84 {
    SafeAllocator unknown_0_;
    SafeAllocator unknown_14_;
    SafeAllocator alloc28;
    SafeAllocator alloc3c;
    SafeAllocator unknown_50_;
    char unknown_64_[0xec - 0x64];
    Struct0205a198* entries;
    ClearTarget0205a234* unknown_f0_;
    char unknown_f4_[0x570 - 0xf4];
    Struct_020e2490* entryManager;
};

// USA: func_ov003_02158a84
extern "C" ARM void func_ov003_02158a84(Struct_ov003_02158a84* self, SafeAllocator* alloc) {
    if (alloc == NULL) {
        return;
    }
    self->unknown_0_.CreateTypeA(alloc->Allocate(0x4000), 0x4000);
    self->unknown_14_.CreateTypeA(alloc->Allocate(0x7000), 0x7000);
    self->alloc28.CreateTypeA(alloc->Allocate(0x8000), 0x8000);
    self->alloc3c.CreateTypeA(alloc->Allocate(0x800), 0x800);
    self->unknown_50_.CreateTypeA(alloc->Allocate(0x200), 0x200);
    self->entries = (Struct0205a198*)alloc->Allocate(0x230);
    for (int i = 0; i < 14; i++) {
        Sprite_Init(&self->entries[i]);
    }
    self->unknown_f0_ = (ClearTarget0205a234*)alloc->Allocate(8);
    func_0205a234(self->unknown_f0_);
    self->unknown_50_.Reset();
    self->entryManager = (Struct_020e2490*)self->unknown_50_.Allocate(0x24);
#if defined(jpn)
    func_020e2490(self->entryManager, 0, 1, self->unknown_f0_, &self->unknown_50_, 3, 0x40);
#else
    func_020e2490(self->entryManager, 0, 1, self->unknown_f0_, &self->unknown_50_, 4, 0x40);
#endif
}
