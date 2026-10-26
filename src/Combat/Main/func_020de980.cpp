#include <globaldefs.h>

extern "C" int ItemTable_LoadIds(void* a, void* b, void* c, int d, void* e, int flag);

// USA: func_020de980
extern "C" ARM int func_020de980(void* a, void* b, void* c, int d, int e) {
    return ItemTable_LoadIds(a, b, c, d, &e, 1);
}
