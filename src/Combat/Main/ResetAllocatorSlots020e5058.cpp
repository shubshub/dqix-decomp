#include <globaldefs.h>
#include "Resource/KeyTable.h"
#include "Memory/SafeAllocator.h"

void KeyTable_Reset(Struct020dfc40* p);

struct Slot020e5058 {
    Struct020dfc40 inner;
};

extern Slot020e5058 data_02153694[2];
extern SafeAllocator data_02153680;

// USA: func_020e5058
ARM void ResetAllocatorSlots020e5058(void) {
    int i;
    for (i = 0; i < 2; i++) {
        KeyTable_Reset(&data_02153694[i].inner);
    }
    data_02153680.ResetAllocatorPointer();
}
