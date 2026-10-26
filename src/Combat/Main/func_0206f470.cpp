#include <globaldefs.h>
#include "Resource/MonsterDefinition.h"

// USA: func_0206f470
extern "C" ARM void* func_0206f470(struct Struct_0206f01c_2* base, int key, Type_0206f470 arg2) {
    MonsterDefinition* arr;
    int count;
    int low;
    int high;
    int var4;
    int r;

    arr = base->arr;
    if (arr == NULL || arg2 == NULL) {
        return NULL;
    }
    count = base->header.count;
    if (count == 0) {
        return NULL;
    }
    low = 0;
    high = count - 1;
    while (low <= high) {
        var4 = low + ((high - low + 1) >> 1);
        r = arg2(&arr[var4]);
        if (r == key) {
            return &arr[var4];
        }
        if (r > key) {
            high = var4 - 1;
        } else {
            low = var4 + 1;
        }
    }
    return NULL;
}
