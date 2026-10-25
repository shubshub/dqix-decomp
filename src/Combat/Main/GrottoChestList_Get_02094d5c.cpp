#include <globaldefs.h>

struct GetElement02094d5cElem { char pad[0x14]; };
struct GetElement02094d5cList { struct GetElement02094d5cElem* elems; };

// Main, originally GetElement02094d5c (USA 0x02094d5c, EUR 0x02094d6c, JPN 0x020969ac)
ARM struct GetElement02094d5cElem* GrottoChestList_Get(struct GetElement02094d5cList* list, int index) {
    return list->elems + index;
}
