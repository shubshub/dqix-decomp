#include <globaldefs.h>

struct Struct_ov023_021db08c { short id; char pad[6]; };

// USA: func_ov023_021db08c
extern "C" ARM void* func_ov023_021db08c(void* obj, int val) {
    int i;
    if (val < 0) return NULL;
    for (i = 0; i < *(unsigned short*)((char*)obj + 6); i++) {
        struct Struct_ov023_021db08c* list = *(struct Struct_ov023_021db08c**)obj;
        if (list[i].id == val) return &list[i];
    }
    return NULL;
}
