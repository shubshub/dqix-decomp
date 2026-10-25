#include <globaldefs.h>
#include "Graphics/Background.h"

#if defined(jpn)
enum { Enum_ov005_0215a620_3716 = 0xe80, Enum_ov005_0215a620_15768 = 0x3d10, Enum_ov005_0215a620_22 = 24, Enum_ov005_0215a620_10 = 8 };
#else
enum { Enum_ov005_0215a620_3716 = 0xe84, Enum_ov005_0215a620_15768 = 0x3d98, Enum_ov005_0215a620_22 = 22, Enum_ov005_0215a620_10 = 10 };
#endif

struct BackgroundResourceEntry;
void Background_DrawScreen(struct BackgroundGraphics*, unsigned int, int, int, short, short, short, short, unsigned short);

struct BackgroundGraphics;
void Background_UploadMap(struct BackgroundGraphics*, void*);

struct Struct_ov005_0215c530
{
    Struct_ov005_0215c530* unknown_0_;
    char unknown_4_[4];
    short unknown_8_;
};

struct Struct_ov005_0215c530_2
{
    short unknown_0_;
    char unknown_2_[0x1c - 2];
};

struct Struct_02020cb8_8
{
    int unknown_0_[2];
};

struct Struct_ov005_0215a620_2
{
    char pad0[backgroundOffset - 0x244];
    BackgroundGraphics backgrounds[3];
    char beforeContainer[0x1000 - (backgroundOffset - 0x244) - sizeof(BackgroundGraphics) * 3];
    Container0215c530 container;
    char pad1[0x179c - 0x1000 - sizeof(Container0215c530)];
};

struct Struct_ov005_0215a620
{
    char unknown_0_[0x244];
    Struct_ov005_0215a620_2 unknown_244_;
    Struct_ov005_0215c530* unknown_19e0_;
    char unknown_19e4_[0x2d90 - 0x19e4];
    Struct_ov005_0215c530_2 unknown_2d90_[24];
    char unknown_3030_[Enum_ov005_0215a620_15768 - 0x3030];
    short unknown_3d98_[8];
    char unknown_3da8_[0x3db8 - 0x3da8];
    unsigned char unknown_3db8_;
    unsigned char unknown_3db9_;
    char unknown_3dba_[0x3dbb - 0x3dba];
    signed char unknown_3dbb_;
    unsigned char unknown_3dbc_;
    signed char unknown_3dbd_;
    char unknown_3dbe_;
    signed char unknown_3dbf_;
    char unknown_3dc0_[0x3dcc - 0x3dc0];
    unsigned int unknown_3dcc_;
    char unknown_3dd0_[0x3dd4 - 0x3dd0];
    unsigned char unknown_3dd4_[8];
    typedef unsigned char Type_02020cb8_2[8];
    Type_02020cb8_2& inline_ov005_0215a620() { return unknown_3dd4_; }
};

// USA: func_ov005_0215a620
extern "C" ARM void func_ov005_0215a620(Struct_ov005_0215a620* arg0) {
    if ((arg0->unknown_3dcc_ & 0x800) == 0) return;

    unsigned char state = obj->state;
    if (!(state != 0 && state != 1)) {
        Background_DrawScreen(&obj->sub.backgrounds[0], 0, tileX, 22, tileX, 22, tileWidth, 2, 0xffff);
    } else {
        unsigned char mode = obj->tab;
        unsigned char* table = obj->GetModeTable();
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
