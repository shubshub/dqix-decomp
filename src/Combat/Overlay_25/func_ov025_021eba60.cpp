#include "Resource/ActionDataTables.h"
#include <globaldefs.h>

extern "C" void* func_ov000_02160130(void);
extern "C" void* func_ov000_02160f20(void* obj);
extern "C" void* func_02079e2c(char* p, int key);

// USA: func_ov025_021eba60
extern "C" ARM void func_ov025_021eba60(char* obj) {
    void* slot = func_ov000_02160f20(func_ov000_02160130());
    ActionDataTables* p = func_020797dc();
    short key = *(short*)slot;
    void* r = func_02079e2c((char*)p, key);
    if (r == 0) {
        return;
    }
    unsigned int val = *(unsigned int*)((char*)r + 0x14);
    val = val >> 0x1c;
    if (val == 2) {
        unsigned int v2 = *(unsigned int*)((char*)r + 8);
        v2 = v2 << 0x16;
        v2 = v2 >> 0x1e;
        if (v2 == 1) {
            unsigned int f = *(unsigned int*)(obj + 0x1c4);
            f |= 0x80;
            *(unsigned int*)(obj + 0x1c4) = f;
        }
    }
}
