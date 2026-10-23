#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Combat/MapDisplay.h"

struct Struct_02043368;
struct Struct_020e2490;

void Sprite_Init(Struct0205a198* s);
void ClearField0And40205a234(ClearTarget0205a234* t);
void InitEntryManager020e2490(EntryManager020e2490* mgr, int arg1, int arg2, void* arg3, SafeAllocator* alloc, int count, unsigned char flag);

struct Struct_ov003_02158a84 {
    SafeAllocator unknown_0_;
    SafeAllocator unknown_14_;
    SafeAllocator unknown_28_;
    SafeAllocator unknown_3c_;
    SafeAllocator unknown_50_;
    char unknown_64_[0xec - 0x64];
    Struct_02043368_2* unknown_ec_;
    Struct_02043368* unknown_f0_;
    char unknown_f4_[0x570 - 0xf4];
    Struct_020e2490* unknown_570_;
};

// USA: func_ov003_02158a84
extern "C" ARM void func_ov003_02158a84(Struct_ov003_02158a84* arg0, SafeAllocator* arg1) {
    if (arg1 == NULL) {
        return;
    }
    self->alloc0.CreateTypeA(alloc->Allocate(0x4000), 0x4000);
    self->alloc14.CreateTypeA(alloc->Allocate(0x7000), 0x7000);
    self->alloc28.CreateTypeA(alloc->Allocate(0x8000), 0x8000);
    self->alloc3c.CreateTypeA(alloc->Allocate(0x800), 0x800);
    self->alloc50.CreateTypeA(alloc->Allocate(0x200), 0x200);
    self->entries = (Struct0205a198*)alloc->Allocate(0x230);
    for (int i = 0; i < 14; i++) {
        Sprite_Init(&self->entries[i]);
    }
    arg0->unknown_f0_ = (Struct_02043368*)arg1->Allocate(8);
    func_0205a234(arg0->unknown_f0_);
    arg0->unknown_50_.Reset();
    arg0->unknown_570_ = (Struct_020e2490*)arg0->unknown_50_.Allocate(0x24);
#if defined(jpn)
    func_020e2490(arg0->unknown_570_, 0, 1, arg0->unknown_f0_, &arg0->unknown_50_, 3, 0x40);
#else
    func_020e2490(arg0->unknown_570_, 0, 1, arg0->unknown_f0_, &arg0->unknown_50_, 4, 0x40);
#endif
}
