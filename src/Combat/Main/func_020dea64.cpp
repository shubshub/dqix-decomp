#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int ItemTable_LoadInPlace(void* obj, void* a, void* b);
extern "C" int func_020df374(void* p0, void* p1, void* p2, void* p3, int p4, int p5, int p6);

struct Struct_020dea64 {
    unsigned short field0;
    char pad[0x14 - 2];
    unsigned char unknown_14_;
};

// USA: func_020dea64
extern "C" ARM int func_020dea64(Struct_020dea64* a, void* b, void* c, void* d, void* e, short f) {
    memset(a, 0, 0x14);
    if (b == 0 || c == 0 || d == 0 || e == 0 || f == 0) {
        return 0;
    }
    char local[0x14];
    ItemTable_LoadInPlace(local, c, d);
    int result = func_020df374(b, a, local, e, f, 0, 0);
    unsigned char flag;
    if (result != 0 && a->field0 > 1) {
        flag = 1;
    } else {
        flag = 0;
    }
    a->unknown_14_ = flag;
    return result;
}
