#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_0208baec { int x, y; float scale; unsigned short value; unsigned short unknown_e_; };
struct Struct_0208baec_2 { unsigned char field_0[0xc]; int x, y, width, height; unsigned short value; unsigned short unknown_1e_; unsigned short style; unsigned char flags; unsigned char unknown_23_[5]; };
struct Struct_0208bb78 {
    unsigned char field_0[0x60];
    Struct_0208baec_2 destination;
    unsigned char unknown_88_[0xb4 - 0x88];
    Struct_0208baec_2* entries;
    unsigned char field_b8[0xc8 - 0xb8];
    float angle;
    float unknown_cc_;
    unsigned char field_d0[2];
    short id;
    unsigned char action;
    unsigned char unknown_d5_[2];
    unsigned char unknown_d7_;
    unsigned char kind;
    signed char countdown;
    unsigned short flags;
};
typedef void (Struct_0208bb78::*Type_01ff8b48_6)();
struct Struct_020e8ce4 { Type_01ff8b48_6 actions[5]; };
#if defined(jpn)
extern Struct_020e8ce4 data_020e8e00;
#else
extern Struct_020e8ce4 data_020e8ce4;
#endif
extern Type_01ff8b48_6 __ptmf_null;
struct HeadNode02046b24;
struct Struct0200fb08;
struct Struct_02065990_3;
extern "C" int func_0208ca00(Struct_0208bb78*, int);
extern "C" void func_0208bf78(Struct_0208bb78*);
extern "C" void func_0208b788(int, float, Struct_0208baec*, int);
extern "C" int func_0208baec(int, Struct_0208baec_2*, Struct_0208baec*, int, float, int, unsigned char);
extern "C" unsigned char GameState_GetLanguage(Struct0200fb08*);
extern "C" int FieldTaskQueue_GetCurrentKind(HeadNode02046b24**);
extern "C" int* func_02094d6c();
extern "C" unsigned char func_020965ac(Struct_02065990_3*, unsigned char);
extern "C" int func_02096088(void*, int);

// USA: func_0208bb78
extern "C" ARM int func_0208bb78(Struct_0208bb78* self, int delta) {
    if (self->id < 0) return 1;
    if (!delta) delta = 1;
    int pivot = func_0208ca00(self, (signed char)delta);
    if (self->countdown) {
        self->countdown -= delta;
        if (self->countdown < 0) self->countdown = 0;
    }
    if (self->flags & 0x20) func_0208bf78(self);
    else {
#if defined(jpn)
        Struct_020e8ce4 actions = data_020e8e00;
#else
        Struct_020e8ce4 actions = data_020e8ce4;
#endif
        actions.actions[4] = __ptmf_null;
        if (!actions.actions[self->action]) return 1;
        (self->*actions.actions[self->action])();
    }
    GameState* state = GameState::GetInstance();
    GameResources* resources = state->GetResources();
    float scale;
    unsigned char slot;
    HeadNode02046b24** head = (HeadNode02046b24**)resources->fieldTaskQueue_;
    if (self->flags & 8) {
        int adjust = (self->flags & 0x100) != 0;
        Struct_0208baec values;
        func_0208b788(self->kind, self->unknown_cc_, &values, adjust);
        scale = values.scale;
        if (!self->kind) scale *= scale;
        slot = 0;
        if (adjust) slot = 1;
        if (self->flags & 0x100) {
            values.y -= 16;
#if defined(jpn)
            func_0208baec((int)&self->destination, &self->entries[slot], &values, 0x40, scale, pivot, 1);
#else
            func_0208baec((int)&self->destination, &self->entries[slot], &values, 0x20, scale, pivot, 1);
#endif
            Struct_0208baec second;
            memcpy(&second, &values, sizeof(second));
            second.y += 0x38;
#if !defined(jpn)
            if (GameState_GetLanguage((Struct0200fb08*)state) == 5) second.y += 16;
#endif
#if defined(jpn)
            func_0208baec((int)&self->destination, &self->entries[(unsigned char)(slot + 1)], &second, 0x60, scale, pivot, 1);
#else
            func_0208baec((int)&self->destination, &self->entries[(unsigned char)(slot + 1)], &second, 0x30, scale, pivot, 1);
#endif
        } else {
            int draw = 1;
            if (FieldTaskQueue_GetCurrentKind(head) == 0x2d) slot = draw;
            else if (self->kind == 1) draw = 0;
            if (draw) func_0208baec((int)&self->destination, &self->entries[slot], &values, 0x40, scale, pivot, 1);
        }
    }
    if (self->id != 9999 && self->id >= 0 && self->action != 0 && self->action != 3 && FieldTaskQueue_GetCurrentKind(head) != 0x2d) {
        int* global = func_02094d6c();
        int value = func_020965ac((Struct_02065990_3*)global, (unsigned char)self->id);
        if (func_02096088(global, value)) {
            Struct_0208baec values;
            func_0208b788(1, 1.0f, &values, 0);
            func_0208baec((int)&self->destination, &self->entries[1], &values, 0x20, values.scale, pivot, 2);
        }
    }
    return 0;
}
