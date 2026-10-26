// USA: func_ov000_0217b8a4
#include <globaldefs.h>
#include "Input/Input.h"

struct Struct_0205c570;
struct Struct_0205bcdc;
struct Struct_0205def8;
struct Obj_0205da38;
struct SePlayer;
extern "C" int Window_GetSelectedIndex(Struct_0205c570*);
extern "C" int abs(int);
extern "C" void GridCursor_SelectIfValid(Struct_0205bcdc*, int);
extern "C" void GridCursor_SetSelectedIndex(void*, int);
extern "C" void func_0205def8(Struct_0205def8*, int, int);
extern "C" int Window_IsSelectionTouched(struct Obj_0205da38* obj, int key);
extern "C" void SePlayer_Play(SePlayer*, int, int);
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
    char list[0x1faa - 0x188];
#else
    char list[0x1d72 - 0x188];
#endif
    unsigned short flags;
};
struct Struct_ov000_02184294_6 {
#if defined(jpn)
    Struct_ov000_0217b8a4_4* context;
    int field_0;
    int unknown_4_;
#else
    int field_0;
    int unknown_4_;
    Struct_ov000_0217b8a4_4* context;
#endif
};
struct Struct_ov000_0217b8a4 {
    char unknown_0_[4];
    char selection[0x54 - 4];
    char controls[0x68 - 0x54];
    int row;
    char unknown_6c_[0xb8 - 0x6c];
    unsigned char state;
};
struct Struct_ov000_0217b8a4_2 { char unknown_0_[0x18]; short count; };
struct Struct_ov000_0217b8a4_3 {
    char unknown_0_[0x10];
    signed char unknown_10_[8];
    signed char depth;
    char unknown_19_[0x22 - 0x19];
    signed char cursor;
    char unknown_23_[0x2c - 0x23];
    short unknown_2c_;
    char pad_2e[0x38 - 0x2e];
    Struct_ov000_0217b8a4* window;
#if defined(jpn)
    char unknown_3c_[0x430 - 0x3c];
#else
    char unknown1_3c_[0x3f0 - 0x3c];
#endif
    Struct_ov000_0217b8a4_2* items[21];
    unsigned char unknown_444_;
};
extern Struct_ov000_02184294_6 data_ov000_02184294;
extern SePlayer g_sePlayer;

// USA: func_ov000_0217b8a4
extern "C" ARM int func_ov000_0217b8a4(Struct_ov000_0217b8a4_3* obj, int arg1, int arg2) {
    signed char row;
    data_ov000_02184294.context->flags |= 0x100;
    Struct_ov000_0217b8a4* window = obj->window;
    signed char previous = obj->cursor;
    signed char cursor = Window_GetSelectedIndex((Struct_0205c570*)obj->window);
    row = window->row;
    signed char var4 = cursor;
    signed char var5 = obj->cursor & 3;
    signed char var6 = cursor & 3;
    if ((signed char)abs(var6 - var5) == 1 && var5 < var6) {
        if (!obj->items[cursor]) cursor = row * 4;
    }
    while (!obj->items[cursor]) cursor--;
    while (obj->items[cursor]) {
        if (obj->items[cursor]->count > 0) break;
        cursor--;
    }
    if (var4 != cursor) {
        GridCursor_SelectIfValid((Struct_0205bcdc*)window->selection, cursor);
        GridCursor_SetSelectedIndex(window->controls, cursor);
    }
    obj->cursor = cursor;
    obj->unknown_2c_ = -1;
    Struct_ov000_0217b8a4_4* context = data_ov000_02184294.context;
    func_0205def8((Struct_0205def8*)context->list, 1, 0x24);
    if (previous != cursor) return -1;
    int flag = g_keyManager.TestKeysPressed(0x601);
    int active = (flag | Window_IsSelectionTouched((Obj_0205da38*)obj->window, 0x14)) != 0;
    if (active || obj->unknown_444_) {
        Struct_ov000_0217b8a4_2* item = obj->items[cursor];
        if (!item) return -1;
        short count = item->count;
        if (count <= 0) return -1;
        obj->unknown_2c_ = count;
        func_0205def8((Struct_0205def8*)context->list, 0, 0x24);
        SePlayer_Play(&g_sePlayer, 1, 0);
#if defined(jpn)
        func_ov000_02171e60(obj);
#else
        func_ov000_02171e60(obj);
#endif
        if (obj->unknown_10_[obj->depth] != 100) obj->window->state = 0x11;
        return obj->unknown_10_[obj->depth];
    }
    if (func_ov000_0217ab48(obj)) {
        func_ov000_0217629c(obj);
        obj->unknown_10_[obj->depth] = 0;
        obj->depth--;
        obj->cursor = -1;
        func_ov000_0217ab8c(obj, arg1, arg2);
        func_ov000_02176e3c(data_ov000_02184294.context, obj, obj->unknown_10_[obj->depth], data_ov000_02184294.unknown_4_, data_ov000_02184294.field_0, 0);
    }
    return -1;
}
