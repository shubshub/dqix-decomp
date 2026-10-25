#include <globaldefs.h>
void ItemTable_LoadInPlace(void*, void*, void*);
#include "std_library_functions.h"


struct Struct020deeb8 {
    unsigned char pad[0xc];
    int field_c;
    int field_10;
};

// USA: func_020deeb8
ARM int InitStruct020deeb8(int a, Struct020deeb8* b, int c, int d, int e) {
    ItemTable_LoadInPlace((void*)(a), (void*)(d), (void*)(e));
    memset(b, 0, 0xc);
    b->field_c = c;
    b->field_10 = 0;
    return 1;
}
