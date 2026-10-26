#include <globaldefs.h>
#include "std_library_functions.h"

// Local copy of func_02029988's DebugMenuItem (a DebugMenu starts with the same type and text)
struct DebugMenuItem {
    int type;
    char text[0x2f];
};

enum { kMaxTextLength = 0x2e };

#define IS_SJIS_LEAD_BYTE(c) (((c) >= 0x81 && (c) <= 0x9f) || ((c) >= 0xe0 && (c) <= 0xea))

// Main, originally func_020294cc (USA 0x020294cc, EUR 0x020294dc, JPN 0x02029084)
extern "C" ARM void DebugMenuItem_SetText(struct DebugMenuItem* item, unsigned char* text) {
    int length;
    int trailBytes;
    unsigned char* cursor;
    unsigned char c;
    int nextLength;

    if (text == 0) return;

    length = 0;
    cursor = text;
    while ((c = *cursor) != 0) {
        trailBytes = 0;
        if (IS_SJIS_LEAD_BYTE(c)) {
            c = *++cursor;
            trailBytes++;
            if (c == 0) break;
        }
        nextLength = length + (trailBytes + 1);
        cursor++;
        if ((unsigned int)nextLength > kMaxTextLength) break;
        length = nextLength;
    }
    memcpy(item->text, text, length);
    item->text[length] = 0;
}
