#include <globaldefs.h>

struct Struct_ov023_021e2450 { short key; char pad[18]; };

// USA: func_ov023_021e2450
extern "C" ARM void* func_ov023_021e2450(void* obj, int val) {
    struct Struct_ov023_021e2450* list = *(struct Struct_ov023_021e2450**)((char*)obj + 0xc);
    unsigned short count;
    unsigned short i;
    if (list == NULL) return NULL;
    count = *(unsigned short*)((char*)obj + 0x16);
    if (count == 0) return NULL;
    for (i = 0; i < count; i++) {
        short key = list[i].key;
        if (key == val) return &list[i];
    }
    return NULL;
}
