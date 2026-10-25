#include <globaldefs.h>
#include "Resource/ItemTable.h"

struct Element020de650 {
    unsigned int v[8];
};

typedef int (*KeyFunc020de650)(struct Element020de650*);

// USA: func_020de650
ARM struct Element020de650* BinarySearchByComparator020de650(struct ItemTable* c, int key, KeyFunc020de650 fn) {
    struct Element020de650* base;
    int count;
    int low;
    int high;
    int mid;
    struct Element020de650* elem;
    int result;

    base = c->entries;
    if (base == NULL || fn == NULL) return NULL;
    count = c->count;
    if (count == 0) return NULL;
    high = count - 1;
    low = 0;
    while (low <= high) {
        mid = low + ((high - low + 1) >> 1);
        elem = base + mid;
        result = fn(elem);
        if (result == key) return elem;
        if (result > key) high = mid - 1;
        else low = mid + 1;
    }
    return NULL;
}
