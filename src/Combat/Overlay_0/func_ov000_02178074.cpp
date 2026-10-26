#include "Combat/TryApplyElemFields.h"
#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_0205d81c;
struct StructA0205d5d0;

struct Elem_0205d81c {
    char pad[0xc2];
    short unknown_c2_;
};

struct Panel_02178074 {
    char unknown_0_[0x58];
    int pageCount;
    char unknown_5c_[0x44];
    short width;
    short height;
    short tileX;
    short tileY;
    short unknown_a8_;
    short unknown_aa_;
    short unknown_ac_;
    short unknown_ae_;
    char unknown_b0_;
    unsigned char unknown_b1_;
};

struct Struct_ov000_02178074_2 {
    char pad[0x188];
    struct Panel_02178074 panel;
};

struct Struct_ov000_02178074_3 {
    char pad[0x44];
    int x;
    int y;
};

struct TextWorkspace {
#if defined(jpn)
    char unknown0[0x28];
#else
    char unknown0[0x5c];
#endif
    char* textBuffer;
};

extern "C" TextWorkspace* MessageSystem_GetInstance();
extern "C" struct Elem_0205d81c* func_0205d81c(struct Struct_0205d81c* s, int key);
extern "C" void func_ov000_021781f8(struct Struct_ov000_02178074_2* obj, struct Struct_ov000_02178074_3* in);
extern "C" void func_ov000_0217c638(struct Struct_ov000_02178074_2* obj, int a, int b);
extern "C" void func_ov000_0217831c(struct Struct_ov000_02178074_2* obj, void* textBuffer);
extern "C" void func_ov000_02176210(struct Panel_02178074* panel, int slot, int key);
#if defined(jpn)
extern "C" void Window_OpenPane(struct Panel_02178074* panel, void* textBuffer, int a, int b, int c, int d, int e);
#else
extern "C" void Window_OpenPane(struct Panel_02178074* panel, void* textBuffer, int a, int b, int c, int d, int e, int f);
#endif

// USA: func_ov000_02178074
extern "C" ARM void func_ov000_02178074(struct Struct_ov000_02178074_2* obj, struct Struct_ov000_02178074_3* in, int arg2, int arg3) {
    if (in == 0) {
        return;
    }
    int x = in->x;
    int y = in->y;
    func_ov000_021781f8(obj, in);
    func_ov000_0217c638(obj, arg2, arg3);
    struct Panel_02178074* panel = &obj->panel;
#if defined(jpn)
    panel->width = 0x10;
#else
    panel->width = 0x12;
#endif
    panel->height = 9;
#if defined(jpn)
    panel->tileX = (x >> 3) + 9;
#else
    panel->tileX = (x >> 3) + 0xe;
#endif
    panel->tileY = y >> 3;
    panel->unknown_a8_ = 0xc;
    panel->unknown_aa_ = 8;
    panel->unknown_ac_ = 0xa;
    panel->unknown_ae_ = 0xc;
    panel->unknown_b1_ = 7;
#if defined(jpn)
    char* textBuffer;
#endif
    int pageCount = panel->pageCount;
#if defined(jpn)
    textBuffer = MessageSystem_GetInstance()->textBuffer;
#else
    char* textBuffer = MessageSystem_GetInstance()->textBuffer;
#endif
#if defined(jpn)
    memset(textBuffer, 0, 0x800);
#else
    memset(textBuffer, 0, 0x960);
#endif
    func_ov000_0217831c(obj, textBuffer);
    int multiplePages = (pageCount > 1) ? 1 : 0;
#if defined(jpn)
    Window_OpenPane(&obj->panel, textBuffer, 0, 0, multiplePages, 1, 0);
#else
    Window_OpenPane(panel, textBuffer, 0, 0, multiplePages, 1, 0, 0);
#endif
    struct Elem_0205d81c* elem = func_0205d81c((struct Struct_0205d81c*)panel, 0x21);
    if (elem != 0) {
        elem->unknown_c2_ = 0;
    }
#if defined(jpn)
    func_ov000_02176210(&obj->panel, 7, 0x21);
#else
    func_ov000_02176210(panel, 7, 0x21);
#endif
#if defined(jpn)
    Window_SetPaneText((struct StructA0205d5d0*)&obj->panel, 7, (int)textBuffer, 1);
#else
    Window_SetPaneText((struct StructA0205d5d0*)panel, 7, (int)textBuffer, 1, 0);
#endif
}
