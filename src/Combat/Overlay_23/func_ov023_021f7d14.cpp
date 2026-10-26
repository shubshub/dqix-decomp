#include <globaldefs.h>
#include "Graphics/Vector.h"

#if defined(jpn)
enum { Enum_ov023_021f7d14_80 = 0x4c, Enum_ov023_021f7d14_78 = 0x4e, BUFFER_OFFSET = 0x24 };
#else
enum { Enum_ov023_021f7d14_80 = 0x50, Enum_ov023_021f7d14_82 = 0x52, BUFFER_OFFSET = 0x28 };
#endif

struct BackgroundGraphics;
extern "C" int Background_SetScroll(struct BackgroundGraphics*, int, int);

struct Struct_ov023_021f7d14 { fix32_t x; fix32_t y; };

struct Struct_ov023_021f7d14_2 {
    unsigned char unknown0[BUFFER_OFFSET];
    unsigned char displayState[Enum_ov023_021f7d14_80 - BUFFER_OFFSET];
    short x;
    short y;
};

// USA: func_ov023_021f7d14
extern "C" ARM int func_ov023_021f7d14(char* element, struct Struct_ov023_021f7d14* position) {
    Struct_ov023_021f7d14_2* display = (Struct_ov023_021f7d14_2*)element;
    display->x = (short)(position->x >> 12);
    display->y = (short)(position->y >> 12);
    return Background_SetScroll((BackgroundGraphics*)display->displayState, display->x, display->y);
}
