#include <globaldefs.h>

typedef int (*Type_020df850_2)(void *elem);

struct Struct_020dfb48 {
    int a;
    int b;
};

struct Struct_020df850_5 {
    unsigned short count;
    unsigned short pad2;
    int pad4;
    struct Struct_020dfb48 *arr;
};

// USA: func_020dfb48
extern "C" ARM void *func_020dfb48(struct Struct_020df850_5 *base, int key, Type_020df850_2 arg2) {
    struct Struct_020dfb48 *arr;
    int count;
    int low;
    int high;
    int var4;
    int r;

    arr = base->arr;
    if (arr == NULL || arg2 == NULL) return NULL;
    count = base->count;
    if (count == 0) return NULL;
    low = 0;
    high = count - 1;
    while (low <= high) {
        var4 = low + ((high - low + 1) >> 1);
        r = arg2(&arr[var4]);
        if (r == key) return &arr[var4];
        if (r > key) high = var4 - 1;
        else low = var4 + 1;
    }
    return NULL;
}
