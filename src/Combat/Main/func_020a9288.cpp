#include <globaldefs.h>

typedef int (*Type_020a8fd0)(void*);

struct Struct_020a8fd0_2 {
    unsigned int count : 12;
    char* arr;
};

// USA: func_020a9288
extern "C" ARM void* func_020a9288(struct Struct_020a8fd0_2* obj, int key, Type_020a8fd0 arg2) {
    char* arr = obj->arr;
    int count;
    int lo, hi, var4, r;
    if (arr == 0 || arg2 == 0) {
        return 0;
    }
    count = obj->count;
    if (count == 0) {
        return 0;
    }
    lo = 0;
    hi = count - 1;
    while (lo <= hi) {
        var4 = lo + ((hi - lo + 1) >> 1);
        r = arg2(arr + var4 * 64);
        if (r == key) {
            return arr + var4 * 64;
        }
        if (r > key) {
            hi = var4 - 1;
        } else {
            lo = var4 + 1;
        }
    }
    return 0;
}
