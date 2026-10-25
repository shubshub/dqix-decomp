#include <globaldefs.h>
#include "Resource/ItemTable.h"

struct Element020de650 {
    unsigned int v[8];
};

typedef int (*KeyFunc020de650)(struct Element020de650*);

int GetField0x18Short_020de56c(void*);
struct Element020de650* BinarySearchByComparator020de650(struct ItemTable* c, int key, KeyFunc020de650 fn);

// Main, originally FindElementByKey020dedd0 (USA 0x020dedd0, EUR 0x020dede0, JPN 0x020e0868)
ARM struct Element020de650* ItemTable_Find(struct ItemTable* c, int key) {
    int i;
    struct Element020de650* elem;
    unsigned short count;
    if (key < 0) {
        return NULL;
    }
    if (c->useBinarySearch != 0) {
        return BinarySearchByComparator020de650(c, key, (KeyFunc020de650)GetField0x18Short_020de56c);
    }
    elem = c->entries;
    if (elem == NULL || (KeyFunc020de650)GetField0x18Short_020de56c == NULL) {
        elem = NULL;
        goto done;
    }
    count = c->count;
    if (count == 0) {
        elem = NULL;
        goto done;
    }
    for (i = 0; i < count; i++, elem++) {
        if (key == GetField0x18Short_020de56c(elem)) {
            goto done;
        }
    }
    elem = NULL;
done:
    return elem;
}
