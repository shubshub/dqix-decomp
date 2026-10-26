#include <globaldefs.h>

struct Struct_0200da70 {
    unsigned int key;
    unsigned int unknown_4_;
    int pad8;
};

// USA: func_0200da70
extern "C" ARM void* func_0200da70(struct Struct_0200da70* arr, int count, unsigned int target) {
    int lo = 0;
    int hi = count - 1;
    if (hi < 0) goto notfound;
    do {
        int var2 = (lo + hi) >> 1;
        struct Struct_0200da70* e = &arr[var2];
        if (target < e->key) {
            hi = var2 - 1;
        } else {
            unsigned int end = e->key + (e->unknown_4_ & ~1);
            if (target > end) {
                lo = var2 + 1;
            } else {
                return e;
            }
        }
    } while (lo <= hi);
notfound:
    return 0;
}
