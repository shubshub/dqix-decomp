#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern SafeAllocator* data_ov001_021658b8[8];

// USA: func_ov001_0215aa5c
extern "C" ARM void func_ov001_0215aa5c(void) {
    for (int i = 0; i < 8; i++) {
        SafeAllocator* alloc = data_ov001_021658b8[i];
        if (alloc == NULL) continue;
        if (alloc->GetSignedAllocator() == NULL) continue;
        data_ov001_021658b8[i]->Destroy();
        data_ov001_021658b8[i] = NULL;
    }
}
