#include <globaldefs.h>
#include "Graphics/Background.h"

#if defined(jpn)
enum { backgroundOffset = 0xe80, Enum_ov005_0215a620_15768 = 0x3d10, tileX = 24, tileWidth = 8 };
#else
enum { backgroundOffset = 0xe84, Enum_ov005_0215a620_15768 = 0x3d98, tileX = 22, tileWidth = 10 };
#endif

struct Struct_02000c9c_91;
extern "C" void Background_DrawScreen(struct BackgroundGraphics*, unsigned int, int, int, short, short, short, short, unsigned short);

struct BackgroundGraphics;
extern "C" void Background_UploadMap(struct BackgroundGraphics*, void*);

struct Struct_ov005_0215c530
{
    Struct_ov005_0215c530* next;
    char pad[4];
    short id;
};

struct Struct_ov005_0215c530_2
{
    short item;
    char pad[0x1c - 2];
};

struct Struct_02020cb8_8
{
    int unk[2];
};

struct Struct_ov005_0215a620_2
{
    char pad0[backgroundOffset - 0x244];
    BackgroundGraphics backgrounds[3];
    char beforeContainer[0x1000 - (backgroundOffset - 0x244) - sizeof(BackgroundGraphics) * 3];
    Struct_02020cb8_8 container;
    char pad1[0x179c - 0x1000 - sizeof(Struct_02020cb8_8)];
};

struct Struct_ov005_0215a620
{
    char pad0[0x244];
    Struct_ov005_0215a620_2 sub;
    Struct_ov005_0215c530* head;
    char pad1[0x2d90 - 0x19e4];
    Struct_ov005_0215c530_2 slots[24];
    char pad2[Enum_ov005_0215a620_15768 - 0x3030];
    short counts[8];
    char pad3[0x3db8 - 0x3da8];
    unsigned char state;
    unsigned char unknown_3db9_;
    char pad4[0x3dbb - 0x3dba];
    signed char selected;
    unsigned char tab;
    signed char page;
    char pad5;
    signed char unknown_3dbf_;
    char pad6[0x3dcc - 0x3dc0];
    unsigned int dirty;
    char unknown_3dd0_[0x3dd4 - 0x3dd0];
    unsigned char unknown_3dd4_[8];
    typedef unsigned char Type_02020cb8_2[8];
    Type_02020cb8_2& inline_ov005_0215a620() { return unknown_3dd4_; }
};

// USA: func_ov005_0215a620
extern "C" ARM void func_ov005_0215a620(Struct_ov005_0215a620* obj) {
    if ((obj->dirty & 0x800) == 0) return;

    unsigned char state = obj->state;
    if (!(state != 0 && state != 1)) {
        Background_DrawScreen(&obj->sub.backgrounds[0], 0, tileX, 22, tileX, 22, tileWidth, 2, 0xffff);
    } else {
        unsigned char mode = obj->tab;
        unsigned char* table = obj->inline_ov005_0215a620();
        unsigned char kind = table[mode];
        unsigned int j = 5;
        if (kind == 1) j = 4;
        else if (kind == 2) j = 2;
        else if (kind == 3) j = 3;
        Background_DrawScreen(&obj->sub.backgrounds[0], j, 0, 0, tileX, 22, tileWidth, 2, 0xffff);
    }
    Background_UploadMap((BackgroundGraphics*)&obj->sub.backgrounds[0], 0);
    obj->dirty &= ~0x800;
}
