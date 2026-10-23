#include <globaldefs.h>
#include "std_library_functions.h"

int CheckFlagOrFallback020de6c8(void* obj, void* a, void* b);
extern "C" int func_020def98(void* b, void* a, void* local, void* e, short f);

struct DescA020de9a4 {
    unsigned short field0;
    char pad[0x14 - 2];
    unsigned char flag14;
};

// Main, originally func_020de9a4 (USA 0x020de9a4, EUR 0x020de9b4, JPN 0x020e0320)
extern "C" ARM int ItemTable_LoadIds(DescA020de9a4* a, void* b, void* c, void* d, void* e, unsigned short f) {
    memset(a, 0, 0x14);
    if (b == 0 || c == 0 || d == 0 || e == 0 || f == 0) {
        return 0;
    }
    char local[0x14];
    CheckFlagOrFallback020de6c8(local, c, d);
    int result = func_020def98(b, a, local, e, f);
    unsigned char flag;
    if (result != 0 && a->field0 > 1) {
        flag = 1;
    } else {
        flag = 0;
    }
    a->flag14 = flag;
    return result;
}
