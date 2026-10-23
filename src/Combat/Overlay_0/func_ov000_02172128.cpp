#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Combat/MapDisplay.h"

void Sprite_Init(struct Struct0205a198*);
struct ClearTarget0205a234;
void ClearField0And40205a234(struct ClearTarget0205a234*);

struct Struct_ov000_02172128 {
    char unknown_0_[0x170];
    Struct_02043368_2* unknown_170_;
    Struct_02043368* unknown_174_;
#if defined(jpn)
    char unknown_178_[0x1b78 - 0x178];
#else
    char unknown1_178_[0x1a78 - 0x178];
#endif
    SafeAllocator unknown_1a78_[6];
    char unknown_1af0_[0x1af8 - 0x1af0];
    SafeAllocator unknown_1af8_;
};

// USA: func_ov000_02172128
extern "C" ARM void func_ov000_02172128(Struct_ov000_02172128* arg0, SafeAllocator* arg1) {
    arg0->unknown_1a78_[0].CreateTypeA(arg1->Allocate(0x400), 0x400);
#if defined(jpn)
    arg0->unknown_1a78_[1].CreateTypeA(arg1->Allocate(0x1000), 0x1000);
#else
    arg0->unknown_1a78_[1].CreateTypeA(arg1->Allocate(0x1400), 0x1400);
#endif
    arg0->unknown_1a78_[3].CreateTypeA(arg1->Allocate(0x2c00), 0x3000);
    arg0->unknown_1a78_[2].CreateTypeA(arg1->Allocate(0x7000), 0x7000);
    arg0->unknown_1a78_[1].Reset();
    arg0->unknown_1a78_[2].Reset();
#if defined(jpn)
    arg0->unknown_1a78_[4].CreateTypeA(arg1->Allocate(0x4000), 0x4000);
#else
    arg0->unknown_1a78_[4].CreateTypeA(arg1->Allocate(0x4266), 0x4266);
#endif
    arg0->unknown_1a78_[5].CreateTypeA(arg1->Allocate(0xc00), 0xc00);
#if defined(jpn)
    enum { Enum_ov000_02172128_40 = 0x20 };
#else
    enum { Enum_ov000_02172128_40 = 0x28 };
#endif
    self->entries = (Struct0205a198*)allocator->Allocate(kEntryCount * sizeof(Struct0205a198));
    for (unsigned char i = 0; i < kEntryCount; i++) {
        Sprite_Init(&self->entries[i]);
    }
    arg0->unknown_174_ = (Struct_02043368*)arg1->Allocate(8);
    func_0205a234(arg0->unknown_174_);
    unsigned int var1 = arg1->GetMaxPossibleAllocation();
    arg0->unknown_1af8_.CreateTypeA(arg1->Allocate(var1), var1);
}
