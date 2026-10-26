#include <globaldefs.h>

struct IndexList_0202a9ac;
struct IndexNode_0202a9ac;
extern "C" struct IndexNode_0202a9ac* DebugMenu_GetItem(struct IndexList_0202a9ac* list, int index);

// A debug menu item (func_02029988's DebugMenuItem); an item of type DebugMenuItem_Submenu is itself a DebugMenu.
struct ListNode0202a944 {
    int type;
    char text[0x30];
    struct ListNode0202a944* next;
    char padding38[0x4];
    unsigned char index;
    char padding3d[0xB];
    void* parent;
};

// A debug menu (func_02029988's DebugMenu): its item list and item count.
struct ListHead0202a944 {
    char padding0[0x44];
    struct ListNode0202a944* items;
    char padding48[0x12];
    unsigned short count;
};

// func_02029634 opens an item of this type as a menu (DebugMenu_Open) instead of choosing it.
enum { DebugMenuItem_Submenu = 1 };

// Main, originally AppendNodeToList0202a944 (USA 0x0202a944, EUR 0x0202a954, JPN 0x0202a4fc)
extern "C" ARM void DebugMenu_AddItem(struct ListHead0202a944* menu, struct ListNode0202a944* item) {
    item->next = 0;
    if (menu->count == 0) {
        menu->items = item;
        item->index = 0;
        menu->count = 1;
    } else {
        struct ListNode0202a944* last = (struct ListNode0202a944*)DebugMenu_GetItem((struct IndexList_0202a9ac*)menu, menu->count - 1);
        if (last != 0) {
            last->next = item;
            item->index = (unsigned char)menu->count;
            menu->count = menu->count + 1;
        }
    }
    if (item->type == DebugMenuItem_Submenu) {
        item->parent = menu;
    }
}
