#include <globaldefs.h>
#include "Resource/KeyTable.h"
#include "Memory/SafeAllocator.h"

extern "C" void KeyTable_Reset(Struct020dfc40* p);

struct Struct_02153694 {
    Struct020dfc40 inner;
};

extern Struct_02153694 data_02153694[2];
extern SafeAllocator data_02153680;

// USA: func_020e5058
extern "C" ARM void func_020e5058(void) {
    int i;
    for (i = 0; i < 2; i++) {
        KeyTable_Reset(&data_02153694[i].inner);
    }
    data_02153680.ResetAllocatorPointer();
}
