#include <globaldefs.h>
#include "std_library_functions.h"

struct GridCursor;

struct TextWorkspace {
#if defined(jpn)
    char unknown0[0x28];
#else
    char unknown0[0x5c];
#endif
    char* textBuffer;
};
struct Struct_ov000_021787b8_2 {
    char unknown0[0xa0];
    short width;
    short height;
    short tileX;
    short tileY;
    short unknown_a8_;
    short unknown_aa_;
    short unknown_ac_;
    short unknown_ae_;
    unsigned char unknown_b0_;
    unsigned char elementId;
    char unknown_b2_[0xa];
};
struct Struct_ov000_021787b8_3 {
    int count;
    int pages;
    char unknown8[0x48];
};
struct Struct_ov000_021787b8_4 {
    char unknown0[0x188];
    Struct_ov000_021787b8_2 panel;
    Struct_ov000_021787b8_3 groups;
};

extern "C" TextWorkspace* MessageSystem_GetInstance();
extern "C" void GridCursor_SetDimensions(struct GridCursor* s, int a, int b, int mode);
extern "C" void GridCursor_SetCount(struct GridCursor* s, int val);
extern "C" void GridCursor_SetSelectedIndex(void* s, int n);
extern "C" int func_ov000_0217538c(void* objRaw);
extern "C" int func_ov000_021753d8(void* objRaw, int targetIndex);
extern "C" void func_ov000_0217ab8c(void* obj, int a, int b);
extern "C" void func_ov000_02178938(void* obj, void* in, int b, void* buf);
#if defined(jpn)
extern "C" void Window_OpenPane(void* a, void* b, int c, int d, int e, int f, int g);
#else
extern "C" void Window_OpenPane(void* a, void* b, int c, int d, int e, int f, int g, int h);
#endif

struct Struct_ov000_021787b8 {
    char pad0[0x1d];
    signed char position;
    char pad1e[0x44 - 0x1e];
    int x;
    int y;
};

// USA: func_ov000_021787b8
extern "C" ARM void func_ov000_021787b8(Struct_ov000_021787b8_4* menu, struct Struct_ov000_021787b8* in, int mode, int arg3) {
    if (in == 0) {
        return;
    }
    int x = in->x;
    int y = in->y;
    int groupCount = func_ov000_0217538c(menu);
    int group = func_ov000_021753d8(menu, in->position);
    func_ov000_0217ab8c(in, mode, arg3);
    Struct_ov000_021787b8_2* panel = &menu->panel;
#if defined(jpn)
    panel->width = 1;
#else
    panel->width = 0x10;
#endif
    panel->height = 1;
    panel->tileX = (x >> 3) + 0xe;
#if defined(jpn)
    panel->tileY = (y >> 3) + 1;
#else
    panel->tileY = y >> 3;
#endif
    panel->unknown_a8_ = 0xc;
    panel->unknown_aa_ = 6;
    panel->unknown_ac_ = 0xa;
    panel->unknown_ae_ = 0x10;
    panel->elementId = 0xe;
    GridCursor_SetDimensions((struct GridCursor*)&menu->groups, 1, groupCount, 0);
    menu->groups.pages = 1;
    GridCursor_SetCount((struct GridCursor*)&menu->groups, groupCount);
    GridCursor_SetSelectedIndex(&menu->groups, group);
    char* text = MessageSystem_GetInstance()->textBuffer;
#if defined(jpn)
    memset(text, 0, 0x800);
#else
    memset(text, 0, 0x960);
#endif
    func_ov000_02178938(menu, in, arg3, text);
#if defined(jpn)
    Window_OpenPane(panel, text, 0, 1, 0, 1, 0);
#else
    Window_OpenPane(panel, text, 0, 1, 0, 1, 0, 0);
#endif
}
