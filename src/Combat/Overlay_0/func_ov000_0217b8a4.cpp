// USA: func_ov000_0217b8a4
#include <globaldefs.h>
#include "Input/Input.h"

struct Struct_0205c570;
struct Struct_0205bcdc;
struct Struct_0205def8;
struct Obj_0205da38;
struct SePlayer;
int Window_GetSelectedIndex(Struct_0205c570*);
extern "C" int abs(int);
void GridCursor_SelectIfValid(Struct_0205bcdc*, int);
extern "C" void GridCursor_SetSelectedIndex(void*, int);
void SetElementFlag0x20ByKey0205def8(Struct_0205def8*, int, int);
int Window_IsSelectionTouched(struct Obj_0205da38* obj, int key);
void SePlayer_Play(SePlayer*, int, int);
#if defined(jpn)
extern "C" void func_ov000_02171e60(void*);
#else
extern "C" void func_ov000_02171e60(void*);
#endif
extern "C" int func_ov000_0217ab48(void*);
extern "C" void func_ov000_0217629c(void*);
extern "C" void func_ov000_0217ab8c(void*, int, int);
extern "C" void func_ov000_02176e3c(void*, void*, int, int, int, int);
struct Struct_ov000_0217b8a4_4 {
    char unknown_0_[0x188];
#if defined(jpn)
    char unknown_188_[0x1faa - 0x188];
#else
    char unknown_188_[0x1d72 - 0x188];
#endif
    unsigned short unknown_1d72_;
};
struct Struct_ov000_02184294_6 {
#if defined(jpn)
    Struct_ov000_0217b8a4_4* unknown_8_;
    int unknown_0_;
    int unknown_4_;
#else
    int unknown_0_;
    int unknown_4_;
    Struct_ov000_0217b8a4_4* unknown_8_;
#endif
};
struct Struct_ov000_0217b8a4 {
    char unknown_0_[4];
    char unknown_4_[0x54 - 4];
    char unknown_54_[0x68 - 0x54];
    int unknown_68_;
    char unknown_6c_[0xb8 - 0x6c];
    unsigned char unknown_b8_;
};
struct Struct_ov000_0217b8a4_2 { char unknown_0_[0x18]; short unknown_18_; };
struct Struct_ov000_0217b8a4_3 {
    char unknown_0_[0x10];
    signed char unknown_10_[8];
    signed char unknown_18_;
    char unknown_19_[0x22 - 0x19];
    signed char unknown_22_;
    char unknown_23_[0x2c - 0x23];
    short unknown_2c_;
    char unknown_2e_[0x38 - 0x2e];
    Struct_ov000_0217b8a4* unknown_38_;
#if defined(jpn)
    char unknown_3c_[0x430 - 0x3c];
#else
    char unknown1_3c_[0x3f0 - 0x3c];
#endif
    Struct_ov000_0217b8a4_2* unknown_3f0_[21];
    unsigned char unknown_444_;
};
extern MenuGlobals0217b8a4 data_ov000_02184294;
extern SePlayer g_sePlayer;

// USA: func_ov000_0217b8a4
extern "C" ARM int func_ov000_0217b8a4(Menu0217b8a4* obj, int arg1, int arg2) {
    signed char row;
    data_ov000_02184294.context->flags |= 0x100;
    MenuWindow0217b8a4* window = obj->window;
    signed char previous = obj->cursor;
    signed char cursor = Window_GetSelectedIndex((Struct_0205c570*)obj->window);
    row = window->row;
    signed char originalCursor = cursor;
    signed char oldColumn = obj->cursor & 3;
    signed char newColumn = cursor & 3;
    if ((signed char)abs(newColumn - oldColumn) == 1 && oldColumn < newColumn) {
        if (!obj->items[cursor]) cursor = row * 4;
    }
    while (!arg0->unknown_3f0_[var3]) var3--;
    while (arg0->unknown_3f0_[var3]) {
        if (arg0->unknown_3f0_[var3]->unknown_18_ > 0) break;
        var3--;
    }
    if (originalCursor != cursor) {
        GridCursor_SelectIfValid((Struct_0205bcdc*)window->selection, cursor);
        GridCursor_SetSelectedIndex(window->controls, cursor);
    }
    obj->cursor = cursor;
    obj->selectedCount = -1;
    MenuContext0217b8a4* context = data_ov000_02184294.context;
    SetElementFlag0x20ByKey0205def8((Struct_0205def8*)context->list, 1, 0x24);
    if (previous != cursor) return -1;
    int flag = g_keyManager.TestKeysPressed(0x601);
    int active = (flag | Window_IsSelectionTouched((Obj_0205da38*)obj->window, 0x14)) != 0;
    if (active || obj->field_444) {
        MenuItem0217b8a4* item = obj->items[cursor];
        if (!item) return -1;
        short count = item->count;
        if (count <= 0) return -1;
        obj->selectedCount = count;
        SetElementFlag0x20ByKey0205def8((Struct_0205def8*)context->list, 0, 0x24);
        SePlayer_Play(&g_sePlayer, 1, 0);
#if defined(jpn)
        func_ov000_02171e60(arg0);
#else
        func_ov000_02171e60(arg0);
#endif
        if (arg0->unknown_10_[arg0->unknown_18_] != 100) arg0->unknown_38_->unknown_b8_ = 0x11;
        return arg0->unknown_10_[arg0->unknown_18_];
    }
    if (func_ov000_0217ab48(arg0)) {
        func_ov000_0217629c(arg0);
        arg0->unknown_10_[arg0->unknown_18_] = 0;
        arg0->unknown_18_--;
        arg0->unknown_22_ = -1;
        func_ov000_0217ab8c(arg0, arg1, arg2);
        func_ov000_02176e3c(data_ov000_02184294.unknown_8_, arg0, arg0->unknown_10_[arg0->unknown_18_], data_ov000_02184294.unknown_4_, data_ov000_02184294.unknown_0_, 0);
    }
    return -1;
}
