#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" unsigned int DebugMenu_Init(void*);

struct Struct_ov016_0218b5a0
{
    SafeAllocator unk_0;
    char menu[0x80];
    unsigned int unknown_94_;
};

// USA: func_ov016_0218b5a0
extern "C" ARM unsigned int func_ov016_0218b5a0(Struct_ov016_0218b5a0* self) {
    self->unk_0.ResetAllocatorPointer();
    DebugMenu_Init(self->menu);
    self->unknown_94_ = 1;
    return 1;
}
