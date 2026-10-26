#include <globaldefs.h>
extern "C" void ItemTable_LoadInPlace(void*, void*, void*);
#include "std_library_functions.h"


struct Struct_020deeb8 {
    unsigned char pad[0xc];
    int unknown_c_;
    int unknown_10_;
};

// USA: func_020deeb8
extern "C" ARM int func_020deeb8(int a, Struct_020deeb8* b, int c, int d, int e) {
    ItemTable_LoadInPlace((void*)(a), (void*)(d), (void*)(e));
    memset(b, 0, 0xc);
    b->unknown_c_ = c;
    b->unknown_10_ = 0;
    return 1;
}
