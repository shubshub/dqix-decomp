#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void* func_ov017_0219bf74(void);

struct Struct_ov003_0217bd38 {
    SafeAllocator* field0;
    SafeAllocator unknown_4_;
    SafeAllocator unknown_18_;
    SafeAllocator unknown_2c_;
};

// USA: func_ov003_0217bd38
extern "C" ARM void func_ov003_0217bd38(Struct_ov003_0217bd38* self) {
    self->field0 = (SafeAllocator*)func_ov017_0219bf74();
    void* p1 = self->field0->Allocate(0x32000);
    self->unknown_4_.CreateTypeA(p1, 0x32000);
    self->unknown_4_.Reset();
    void* p2 = self->field0->Allocate(0x6800);
    self->unknown_18_.CreateTypeA(p2, 0x6800);
    self->unknown_18_.Reset();
    void* p3 = self->field0->Allocate(0x6800);
    self->unknown_2c_.CreateTypeA(p3, 0x6800);
    self->unknown_2c_.Reset();
}
