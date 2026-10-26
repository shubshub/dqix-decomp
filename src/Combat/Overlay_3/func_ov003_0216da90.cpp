#include <globaldefs.h>

#if defined(jpn)
#define func_ov003_0216da90 func_ov003_0216d478
#endif
#include "GameState/GameState.h"

struct Struct0205de24;
struct Struct_0205c570;
struct Struct_0205d81c;
struct GridCursor;
struct Container020e0310;
struct Struct0200fb08;

struct Struct_ov003_0216da90_2
{
    int field0;
    int field4;
    char unk_8[0x40 - 0x8];
};

struct Struct_ov003_0216da90_3
{
    short x;
    short y;
    short width;
    short height;

    void inline_ov003_0216da90(short newX, short newY)
    {
        x = newX;
        y = newY;
    }

    void inline_ov003_0216da90_2(short arg0, short arg1)
    {
        width = arg0;
        height = arg1;
    }
};

struct Struct_ov003_0216da90_4
{
    int field0;
    Struct_ov003_0216da90_2 tableA;
    char unknown_44_[0x54 - 0x44];
    Struct_ov003_0216da90_2 tableB;
    unsigned char unknown_94_;
    unsigned char unknown_95_;
    char unknown_96_[0xa0 - 0x96];
    Struct_ov003_0216da90_3 frame;
    Struct_ov003_0216da90_3 body;
    char unk_b0;
    unsigned char unknown_b1_;
    char unknown_b2_[3];
    unsigned char unknown_b5_;
};

struct Struct_ov003_0216da90
{
    char unk_0[0x10];
    int mode;
#if defined(jpn)
    char unk_14[0x1150 - 0x14];
#else
    char unk_14[0x12c0 - 0x14];
#endif
    Struct_ov003_0216da90_4* window;
    char unknown_12c4_[0x1324 - 0x12c4];
    char texts_[4];
};

extern "C" void __clear(void* buf, int size);
extern "C" void func_0205de24(Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);
extern "C" void func_0205cef8(void* obj);
extern "C" unsigned char GameState_GetLanguage(Struct0200fb08* obj);
extern "C" int Window_GetSelectedIndex(Struct_0205c570* s);
extern "C" void Text_AppendFrameTag(char* text, int a, int b, int c, int d, int e);
extern "C" const char* KeyTable_Get(Container020e0310* c, int key);
extern "C" void Text_Append(char* text, const char* append);
#if defined(jpn)
extern "C" void Window_OpenPane(void* a, void* b, int c, int d, int e, int f, int g);
#else
extern "C" void Window_OpenPane(void* a, void* b, int c, int d, int e, int f, int g, int h);
#endif
extern "C" Struct_ov003_0216da90_4* func_0205d81c(Struct_0205d81c* s, int key);
extern "C" void GridCursor_SetDimensions(GridCursor* s, int a, int b, int mode);
extern "C" void GridCursor_SetCount(GridCursor* s, int val);

extern short data_ov003_0217f560[];

// USA: func_ov003_0216da90
extern "C" ARM void func_ov003_0216da90(Struct_ov003_0216da90* self)
{
    func_0205de24((Struct0205de24*)self->window, 0, 1);
    self->window->unknown_b1_ = 0;
#if defined(jpn)
    self->window->frame.inline_ov003_0216da90(0xc, 7);
    self->window->frame.inline_ov003_0216da90_2(0x11, 1);
#endif
    self->window->body.inline_ov003_0216da90(0xd, 5);
    self->window->body.inline_ov003_0216da90_2(0xa, 0xc);
    self->window->unknown_b5_ = 1;
    func_0205cef8(self->window);

#if !defined(jpn)
    short x = data_ov003_0217f560[GameState_GetLanguage((Struct0200fb08*)GameState::GetInstance())];
    self->window->frame.inline_ov003_0216da90(x, 7);
    self->window->frame.inline_ov003_0216da90_2(0x1f - x, 1);
#endif

    char text[0x100];
    char sub[0x40];
    __clear(text, 0x100);
    __clear(sub, 0x40);
    if (self->mode == 2)
        Text_AppendFrameTag(text, Window_GetSelectedIndex((Struct_0205c570*)self->window), 8, 5, 5, 5);
    Text_Append(text, KeyTable_Get((Container020e0310*)self->texts_, 0x5c));
#if defined(jpn)
    Window_OpenPane(self->window, text, 0, 0, 0, 1, 0);
#else
    Window_OpenPane(self->window, text, 0, 0, 0, 1, 0, 0);
#endif

#if !defined(jpn)
    Struct_ov003_0216da90_4* found = func_0205d81c((Struct_0205d81c*)self->window, 0);
    if (found)
        found->body.inline_ov003_0216da90_2(0x1f - found->body.x, found->body.height);
#endif

    Struct_ov003_0216da90_4* window = self->window;
    window->tableA.field4 = 1;
    window->tableB.field4 = 1;
    GridCursor_SetDimensions((GridCursor*)&window->tableA, 1, 4, 0);
    GridCursor_SetDimensions((GridCursor*)&window->tableB, 1, 4, 0);
    GridCursor_SetCount((GridCursor*)&window->tableA, 4);
    GridCursor_SetCount((GridCursor*)&window->tableB, 4);
    window->unknown_94_ = 1;
    window->unknown_95_ = 1;
}
