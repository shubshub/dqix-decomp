#include <globaldefs.h>
#include "Resource/KeyTable.h"
#include "Memory/SafeAllocator.h"

void ResetAndDetach020dfc6c(Struct020dfc40* p);
void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);

struct Slot020e5058 {
    Struct020dfc40 inner;
};

extern Slot020e5058 data_02153694[2];
extern SafeAllocator data_02153680;
extern int g_mainAllocator;

// USA: func_020e5094
ARM void ResetSlotsAndDestroySafeAllocator020e5094(void) {
    int i;
    for (i = 0; i < 2; i++) {
        ResetAndDetach020dfc6c(&data_02153694[i].inner);
    }
    void* p = data_02153680.GetSignedAllocator();
    if (p != NULL) {
        AllocatorUnion_Free((AllocatorUnion*)&g_mainAllocator, p);
        data_02153680.Destroy();
    }
}
