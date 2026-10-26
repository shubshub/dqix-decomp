#include <globaldefs.h>

struct DebugMenu;
typedef void (*DebugMenuCallback)(DebugMenu* menu);

// Local copy of func_02029988's DebugMenu, as far as this function reads it.
struct DebugMenu {
    char padding0[0x6c];
    unsigned char state;
    unsigned char flags;
    unsigned char activated;
    unsigned char repeating;
    unsigned char paging;
    unsigned char touching;
    unsigned char touchEnabled;
    unsigned char touchList;
    unsigned char touchBar;
    char padding75[3];
    DebugMenuCallback onOpen;
};

// DebugMenu::state: func_02029634 takes input only in Open; func_02029988 draws it and turns Opening into Open.
enum {
    DebugMenuState_Open = 0,
    DebugMenuState_Opening = 2,
};

extern "C" void DebugMenu_UpdateLayout(DebugMenu* menu);

// Main, originally Deactivate0202a8cc (USA 0x0202a8cc, EUR 0x0202a8dc, JPN 0x0202a484)
ARM void DebugMenu_Open(char* menuBytes, int notify) {
    DebugMenu* menu = (DebugMenu*)menuBytes;
    if (menu->state == DebugMenuState_Open) return;
    menu->state = DebugMenuState_Opening;
    DebugMenu_UpdateLayout(menu);
    menu->touching = 0;
    menu->touchList = 0;
    menu->touchBar = 0;
    if (notify != 0 && menu->onOpen != NULL) {
        menu->onOpen(menu);
    }
}
