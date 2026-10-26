#include <globaldefs.h>
#include "Graphics/GlyphMetrics.h"

// Local copy of func_02029988's DebugMenu
struct DebugMenu {
    int type;
    char pad04[0x3c];
    int unknown40;
    void* items;
    int unknown48;
    int unknown4c;
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
    short unknown68;
    short unknown6a;
    unsigned char state;
    unsigned char flags;
    unsigned char activated;
    unsigned char repeating;
    unsigned char paging;
    unsigned char touching;
    unsigned char touchEnabled;
    unsigned char touchList;
    unsigned char touchBar;
    char pad75[3];
    int unknown78[2];
};

void DebugMenuItem_Init(char* item);

// Main, originally func_02029568 (USA 0x02029568, EUR 0x02029578, JPN 0x02029120)
extern "C" ARM void DebugMenu_Init(struct DebugMenu* menu) {
    DebugMenuItem_Init((char*)menu);
    menu->type = 1;
    menu->x = 0;
    menu->y = 0;
    menu->width = 0;
    menu->height = 0;
    menu->shownHeight = 0;
    menu->state = 1;
    menu->count = 0;
    menu->first = -1;
    menu->last = -1;
    menu->selected = -1;
    menu->flags = 0;
    menu->activated = 0;
    menu->items = 0;
    menu->unknown48 = 0;
    menu->visibleCount = 10;
    menu->visibleFirst = 0;
    menu->visibleLast = (short)(menu->visibleCount + menu->visibleFirst);
    menu->repeating = 0;
    menu->unknown6a = 0;
    menu->unknown68 = 0;
    data_020ef74c.unknown0 = 0x7d40;
    menu->touching = 0;
    menu->touchEnabled = 0;
    menu->touchList = 0;
    menu->touchBar = 0;
    menu->unknown40 = 0;
    menu->paging = 0;
    menu->unknown4c = 8;
    for (int i = 0; i < 2; i++) {
        menu->unknown78[i] = 0;
    }
}
