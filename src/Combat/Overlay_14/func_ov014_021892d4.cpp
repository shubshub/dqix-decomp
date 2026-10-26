#include <globaldefs.h>

typedef int (*Type_ov014_021892d4)(void*);

struct Struct_ov014_021892d4 {
    unsigned short count;
    char pad[0xc - 2];
    void** arr;
};

// USA: func_ov014_021892d4
extern "C" ARM void* func_ov014_021892d4(struct Struct_ov014_021892d4* list, int key, Type_ov014_021892d4 arg2) {
    void** arr = list->arr;
    if (arr == 0 || arg2 == 0) {
        return 0;
    }
    if (list->count == 0) {
        return 0;
    }
    int lo = 0;
    int hi = list->count - 1;
    while (lo <= hi) {
        int var3 = lo + ((hi - lo + 1) >> 1);
        void** elem = arr + var3;
        int val = arg2(elem);
        if (val == key) {
            return elem;
        }
        if (val > key) {
            hi = var3 - 1;
        } else {
            lo = var3 + 1;
        }
    }
    return 0;
}
