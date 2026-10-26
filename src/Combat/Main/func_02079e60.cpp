#include <globaldefs.h>
#if defined(jpn)
enum { Enum_02079e60_60 = 52 };
#else
enum { Enum_02079e60_60 = 60 };
#endif


typedef int (*Type_02079e2c)(void*);

struct Struct_02079e2c {
    unsigned int count : 12;
    char* arr;
};

// USA: func_02079e60
extern "C" ARM void* func_02079e60(struct Struct_02079e2c* obj, int key, Type_02079e2c arg2) {
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
        r = arg2(arr + var4 * Enum_02079e60_60);
        if (r == key) {
            return arr + var4 * Enum_02079e60_60;
        }
        if (r > key) {
            hi = var4 - 1;
        } else {
            lo = var4 + 1;
        }
    }
    return 0;
}
