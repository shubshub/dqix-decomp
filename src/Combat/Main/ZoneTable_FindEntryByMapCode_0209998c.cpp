#include "Combat/Main/ElementLookup.h"
#include "std_library_functions.h"
#include <globaldefs.h>

// Main, originally FindElementByName0209998c (USA 0x0209998c, EUR 0x0209999c, JPN 0x0209b6c0)
extern "C" ARM struct Elem0209998c *ZoneTable_FindEntryByMapCode(struct List0209998c *list, const char *name) {
    int i;
    for (i = 0; i < list->count; i++) {
        struct Elem0209998c *elem = &list->data[i];
        if (strcmp(elem->unknown_5_, name) == 0) return elem;
    }
    return NULL;
}
