#include <globaldefs.h>
#include "Resource/ItemTable.h"

struct Element020de650 {
    unsigned int v[8];
};

typedef int (*KeyFunc020de650)(struct Element020de650*);

// USA: BinarySearchByComparator020de650
extern "C" ARM struct Element020de650* BinarySearchByComparator020de650(struct ItemTable* c, int key, KeyFunc020de650 fn) {
    struct Element020de650* base;
    int count;
    int low;
    int high;
    int var4;
    struct Element020de650* elem;
    int result;

    base = c->entries;
    if (base == NULL || fn == NULL) return NULL;
    count = c->count;
    if (count == 0) return NULL;
    high = count - 1;
    low = 0;
    while (low <= high) {
        var4 = low + ((high - low + 1) >> 1);
        elem = base + var4;
        result = fn(elem);
        if (result == key) return elem;
        if (result > key) high = var4 - 1;
        else low = var4 + 1;
    }
    return NULL;
}
