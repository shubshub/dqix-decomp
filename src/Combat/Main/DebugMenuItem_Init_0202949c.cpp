#include <globaldefs.h>
#include "std_library_functions.h"

// Local copy of func_02029988's DebugMenuItem
struct DebugMenuItem {
    int type;
    char text[0x30];
    DebugMenuItem* next;
    int disabled;
};

// Main, originally Init0202949c (USA 0x0202949c, EUR 0x020294ac, JPN 0x02029054)
ARM void DebugMenuItem_Init(char* itemPtr) {
    DebugMenuItem* item = (DebugMenuItem*)itemPtr;
    item->text[0] = 0;
    memset(item->text, 0, sizeof(item->text));
    item->type = 0;
    item->next = 0;
    item->disabled = 0;
}
