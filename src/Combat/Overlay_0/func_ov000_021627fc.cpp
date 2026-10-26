#include <globaldefs.h>
#include "Resource/ActionDataTables.h"

extern "C" void* func_ov000_02160f20(void* obj);
extern "C" int func_ov000_02163690(int id);

extern "C" void* func_02079e2c(char* p, int key);

// USA: func_ov000_021627fc
extern "C" ARM int func_ov000_021627fc(void* obj) {
    void* slot = func_ov000_02160f20(obj);
    if (slot == 0) {
        return 0;
    }
    int id = *(unsigned short*)slot;
    if (func_ov000_02163690(id)) {
        id = 1;
    }
    ActionDataTables* table = func_020797dc();
    void* entry = func_02079e2c((char*)table, (short)id);
    if (entry == 0) {
        return 0;
    }
    unsigned int kind = *(unsigned int*)((char*)entry + 0x14) >> 0x1c;
    if (kind == 5) {
        return 1;
    }
    return kind == 2;
}
