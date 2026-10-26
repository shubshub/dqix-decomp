#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" unsigned int DebugMenu_Init(void*);

struct Trans_0218b5a0
{
    SafeAllocator unk_0;
    char menu[0x80];
    unsigned int unk_94;
};

// USA: func_ov016_0218b5a0  (semantic: Trans_0218b5a0)
extern "C" ARM unsigned int func_ov016_0218b5a0(Trans_0218b5a0* self) {
    self->unk_0.ResetAllocatorPointer();
    DebugMenu_Init(self->menu);
    self->unk_94 = 1;
    return 1;
}
