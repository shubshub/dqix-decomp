#include <globaldefs.h>

// A debug menu item (func_02029988's DebugMenuItem).
struct IndexNode_0202a9ac {
    int type;
    char text[0x30];
    struct IndexNode_0202a9ac* next;
};

// A debug menu (func_02029988's DebugMenu): its item list and item count.
struct IndexList_0202a9ac {
    char padding0[0x44];
    struct IndexNode_0202a9ac* items;
    char padding48[0x12];
    unsigned short count;
};

// Main, originally GetNodeAtIndex (USA 0x0202a9ac, EUR 0x0202a9bc, JPN 0x0202a564)
ARM struct IndexNode_0202a9ac* DebugMenu_GetItem(struct IndexList_0202a9ac* menu, int index) {
    struct IndexNode_0202a9ac* item;
    int i;
    if (index < 0 || menu->count <= index) {
        return 0;
    }
    item = menu->items;
    for (i = 0; i < index; i++) {
        if (item == 0) {
            return 0;
        }
        item = item->next;
    }
    return item;
}
