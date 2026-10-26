#include <globaldefs.h>
#include "Graphics/GlyphMetrics.h"
#include "std_library_functions.h"

// Local copies of func_02029988's DebugMenuItem and DebugMenu
struct DebugMenuItem {
    int type;
    char text[0x30];
    DebugMenuItem* next;
    char padding_38[8];
    int value;
    char padding_44[8];
    unsigned short flags;
};

struct DebugMenu {
    int type;
    char text[0x40];
    DebugMenuItem* items;
    char padding_48[8];
    short x;
    short y;
    short width;
    short height;
    short shownHeight;
    unsigned short count;
    short first;
    short last;
    short selected;
    unsigned short visibleCount;
    short visibleFirst;
    short visibleLast;
};

enum { kScreenHeight = 192 };

// "%c", "%d"
extern char data_020ef772[];
extern char data_020ef775[];
extern "C" int Font_GetTextWidth(const char*, int);
#if defined(jpn)
extern "C" void func_02028ce4(const char*, int*, int*);
#endif

static inline int inline_0202a6c4(int arg0, int arg1, unsigned int arg2, unsigned int arg3) {
    return arg3 - (arg2 - (arg0 - arg1));
}

// Main, originally func_0202a6c4 (USA 0x0202a6c4, EUR 0x0202a6d4, JPN 0x0202a27c)
extern "C" ARM void DebugMenu_UpdateLayout(DebugMenu* menu) {
    char valueText[16];
    int width = strlen(menu->text);
    if (data_020ef74c.displayMode >= 3 && data_020ef74c.displayMode <= 6) {
        int measured;
        #if defined(jpn)
        int var3;
        func_02028ce4(arg0->unknown_4_, &var2, &var3);
#else
        if (menu->text != NULL) measured = Font_GetTextWidth(menu->text, 1);
#endif
        var2 /= data_020ef74c.unknown_8_;
        var1 = var2;
    }
    DebugMenuItem* item = menu->items;
    int index = 0;
    while (item != NULL) {
        int length;
        if (data_020ef74c.displayMode >= 3 && data_020ef74c.displayMode <= 6) {
            int measured;
            #if defined(jpn)
            int height;
            func_02028ce4(item->text, &measured, &height);
#else
            if (item->text != NULL) measured = Font_GetTextWidth(item->text, 1);
#endif
            measured /= data_020ef74c.columnWidth;
            length = measured;
            if (menu->first >= 0 && menu->first <= menu->last &&
                menu->first <= index && index <= menu->last)
                length += 2;
            if (item->type == 2) length += 6;
            if (item->type == 3) {
                length += 4;
                if (item->flags & 0x80)
                    sprintf(valueText, data_020ef772, item->value + 0x40);
                else
                    sprintf(valueText, data_020ef775, item->value);
                length += strlen(valueText) * 2;
            }
        } else {
            length = strlen(item->text);
            if (menu->first >= 0 && menu->first <= menu->last &&
                menu->first <= index && index <= menu->last)
                length++;
            if (item->type == 2) length += 3;
        }
        if (width < length) width = length;
        item = item->next;
        ++index;
    }
    menu->width = (width + 3) * data_020ef74c.columnWidth;
    menu->height = (menu->count + 3) * data_020ef74c.rowHeight;
    if (menu->x + menu->height > kScreenHeight)
        menu->height = kScreenHeight - menu->x - data_020ef74c.rowHeight;
    menu->visibleCount = menu->height / data_020ef74c.rowHeight - 2;
    short first = menu->first;
    int remaining = VisibleSelectionRemainder(menu->last, first, menu->count, menu->visibleCount);
    menu->visibleFirst = first;
    menu->visibleLast = first + remaining;
}
