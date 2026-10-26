#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern void* data_ov001_021658b8[8];

// USA: func_ov001_0215aa14
extern "C" ARM void func_ov001_0215aa14(SafeAllocator* obj) {
    int i;
    for (i = 0; i < 8; i++) {
        data_ov001_021658b8[i] = NULL;
    }
    if (obj != NULL) {
        obj->GetMaxPossibleAllocation();
        data_ov001_021658b8[0] = obj;
    }
}
