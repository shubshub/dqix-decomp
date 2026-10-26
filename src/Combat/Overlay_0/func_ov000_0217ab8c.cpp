#include <globaldefs.h>
#include "GameState/GameState.h"

struct Sub {
    int p0;
    int field4;
    char p8[0xc];
    int value;
    char unknown_18_[0x38];
};
struct Window {
    char p0[4];
    Sub a;
    Sub b;
};
struct Struct_ov000_0217ab8c {
    char p0[0xc];
    short s0c;
    char unknown_e_[2];
    signed char unknown_10_[8];
    signed char unknown_18_;
    signed char unknown_19_;
    signed char unknown_1a_;
    signed char unknown_1b_;
    signed char unknown_1c_;
    signed char unknown_1d_;
    short unknown_1e_;
    signed char v20;
    signed char unknown_21_;
    signed char unknown_22_;
    signed char unknown_23_;
    unsigned char unknown_24_;
    char unknown_25_[0x30 - 0x25];
    signed char* list;
    signed char count;
    char unknown_35_[3];
    Window* window;
    char unknown_3c_[0x4c - 0x3c];
    int member;
#if defined(jpn)
    char unknown_50_[0xc6 - 0x50];
#else
    char unknown1_50_[0x86 - 0x50];
#endif
    signed char total;
    char unknown_87_[0x442 - 0x87];
    signed char unknown_442_;
    char unknown_443_;
    unsigned char unknown_444_;
};
struct Struct_ov000_0217ab8c_2 {
#if defined(jpn)
    char p[0x1faa];
#else
    char p[0x1d72];
#endif
    unsigned short flags;
};
struct Struct_ov000_02184294_2 {
#if defined(jpn)
    Struct_ov000_0217ab8c_2* root;
    int field0;
    int field4;
#else
    int field0;
    int field4;
    Struct_ov000_0217ab8c_2* root;
#endif
};
struct Struct_0207d300;
struct GridCursor;

extern Struct_ov000_02184294_2 data_ov000_02184294;

struct S02171698;
extern "C" int func_ov000_02171698(S02171698*);
struct S021719c0;
extern "C" int func_ov000_021719c0(S021719c0*);
extern "C" GameObject* func_0200ff1c(GameState*, int);
extern "C" int func_02053c6c(unsigned char*);
extern "C" int func_02083960(Struct_0207d300*);
extern "C" void func_0205cf10(void*);
struct Struct_0205cf1c;
extern "C" void func_0205cf1c(Struct_0205cf1c*);
extern "C" void func_0205cef8(void*);
extern "C" void func_0205cf04(void*);
extern "C" void GridCursor_SetDimensions(GridCursor*, int, int, int);
extern "C" void GridCursor_SetCount(GridCursor*, int);
struct Struct_0205bcdc;
extern "C" void GridCursor_SelectIfValid(Struct_0205bcdc*, int);
extern "C" void GridCursor_SetSelectedIndex(Sub*, int);

// USA: func_ov000_0217ab8c
extern "C" ARM void func_ov000_0217ab8c(Struct_ov000_0217ab8c* self, int arg1, int arg2) {
    int step, visible, pages, total, selected;
    Window* w;
    if (self->member < 0 || !(self->unknown_24_ & 1) || self->s0c == 0 || (w = self->window) == 0) {
        return;
    }
    switch (self->unknown_10_[self->unknown_18_]) {
    case 13:
        selected = self->unknown_1c_;
        step = 2;
        visible = 3;
        pages = 1;
        total = 6;
        break;
    case 14:
        visible = 1;
        step = arg2;
        pages = visible;
        total = arg2;
        selected = self->unknown_1d_;
        break;
    case 15:
        if (func_ov000_02171698((S02171698*)self) >= 4) {
            step = 1;
            visible = 4;
            pages = (func_ov000_02171698((S02171698*)self) + 3) / 4;
        } else {
            step = 1;
            visible = func_ov000_02171698((S02171698*)self);
            pages = step;
        }
        self->unknown_19_ = w->b.value;
        total = func_ov000_02171698((S02171698*)self);
        selected = self->v20;
        if (selected < 0 || total <= selected) {
            selected = 0;
            self->v20 = 0;
        }
        break;
    case 16:
        if (func_ov000_021719c0((S021719c0*)self) >= 4) {
            step = 1;
            visible = 4;
            pages = (func_ov000_021719c0((S021719c0*)self) + 3) / 4;
        } else {
            step = 1;
            visible = func_ov000_021719c0((S021719c0*)self);
            pages = step;
        }
        self->unknown_1a_ = w->b.value;
        total = func_ov000_021719c0((S021719c0*)self);
        selected = self->unknown_1e_;
        if (selected < 0 || total <= selected) {
            selected = 0;
            self->unknown_1e_ = 0;
        }
        break;
    case 17: {
        GameState* gs = GameState::GetInstance();
        GameObject* unit = func_0200ff1c(gs, self->member);
        int field = func_02053c6c((unsigned char*)unit);
        if (field != 0) {
            int n = func_02083960((Struct_0207d300*)field);
            pages = (self->total - n + 3) / 4 + (n + 3) / 4;
            self->unknown_1b_ = w->b.value;
            total = pages * 4;
            selected = self->unknown_22_;
            step = 1;
            visible = 4;
        }
        break;
    }
    case 18:
    case 19:
    case 20:
        if (self->unknown_444_ != 0) {
            for (int i = 0; i < self->count; i++) {
                if (self->unknown_442_ == self->list[i]) {
                    self->unknown_21_ = i;
                    break;
                }
            }
            self->unknown_442_ = -1;
            self->unknown_444_ = 0;
        }
        visible = self->count;
        step = 1;
        pages = step;
        total = visible;
        selected = self->unknown_21_;
        break;
    case 21:
        step = 1;
        visible = step;
        pages = step;
        total = step;
        selected = self->unknown_23_;
        break;
    default:
        func_0205cf10(w);
        func_0205cf1c((Struct_0205cf1c*)self->window);
        return;
    }
    func_0205cef8(self->window);
    func_0205cf04(self->window);
    GridCursor_SetDimensions((GridCursor*)&w->a, step, visible, 0);
    GridCursor_SetDimensions((GridCursor*)&w->b, step, visible, 0);
    GridCursor_SetCount((GridCursor*)&w->a, total);
    GridCursor_SetCount((GridCursor*)&w->b, total);
    w->a.field4 = pages;
    w->b.field4 = pages;
    GridCursor_SelectIfValid((Struct_0205bcdc*)&w->a, selected);
    GridCursor_SetSelectedIndex(&w->b, selected);
    data_ov000_02184294.root->flags &= ~0x100;
}
