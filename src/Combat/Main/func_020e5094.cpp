#include <globaldefs.h>
#include "Resource/KeyTable.h"
#include "Memory/SafeAllocator.h"

extern "C" void KeyTable_Destroy(Struct020dfc40* p);
extern "C" void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);

struct Struct_02153694 {
    Struct020dfc40 inner;
};

extern Struct_02153694 data_02153694[2];
extern SafeAllocator data_02153680;
extern int g_mainAllocator;

// USA: func_020e5094
extern "C" ARM void func_020e5094(void) {
    int i;
    for (i = 0; i < 2; i++) {
        KeyTable_Destroy(&data_02153694[i].inner);
    }
    void* p = data_02153680.GetSignedAllocator();
    if (p != NULL) {
        AllocatorUnion_Free((AllocatorUnion*)&g_mainAllocator, p);
        data_02153680.Destroy();
    }
}
