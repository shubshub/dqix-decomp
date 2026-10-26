#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"

struct Container020e0310;
struct Obj0203c108;

struct Struct_ov000_021716d0 {
    char pad0[4];
    unsigned int id : 12;
    unsigned int unknown_5_4_ : 20;
    unsigned int unknown_8_0_ : 8;
    unsigned int unknown_9_0_ : 24;
    char unknown_c_[0x2c - 0xc];
    unsigned int pad2c : 10;
    unsigned int kind : 4;
    unsigned int unknown_2d_6_ : 18;
    char unknown_30_[2];
    short unknown_32_;
};

struct Struct_ov000_021716d0_2 {
    char pad0[6];
    short mp;
    signed char unknown_8_[8];
    signed char depth;
    char unknown_11_[0x15 - 0x11];
    unsigned char unknown_15_;
    short selected;
    char pad18[0x1e - 0x18];
    unsigned short unknown_1e_;
};

struct PartyInfo_021716d0 {
    char pad0[0xf6c];
    int unknown_f6c_;
};

struct Struct_ov000_021716d0_4 {
    char pad0[4];
    struct Container020e0310* strings;
    Struct_ov000_021716d0_2 state;
    char pad28[0x4c - 0x28];
    int memberIndex;
    char message[LOW_REGION(0x1e4, 0x1a4) - 0x50];
    Struct_ov000_021716d0* spells[1];
};

extern "C" int KeyTable_Get(struct Container020e0310* c, int key);
extern "C" void CachedTextLabel_SetText(struct Obj0203c108* obj, char* text);
extern "C" int func_ov000_02153a8c(GameObject* obj);
extern "C" int func_020dd290(void* obj, unsigned int value);
extern "C" int func_ov000_02171210(void* a, void* b);
extern "C" int* func_ov000_02170cf8(void* obj, int id);
extern "C" void __clear(void* dst, int size);
#if !defined(jpn)
extern "C" void func_020e4864(int a, char* b, int c, int d, int e, int f);
#endif
extern "C" void func_0206819c(const char* src, char* dst, int flag);

// USA: func_ov000_021716d0
extern "C" ARM void func_ov000_021716d0(Struct_ov000_021716d0_4* self) {
    Struct_ov000_021716d0_2* state = &self->state;
    int sel = state->selected;
    if (self->spells[sel] == NULL) {
        state->depth++;
        state->unknown_8_[self->state.depth] = 0xe;
        state->unknown_15_ = 0;
        CachedTextLabel_SetText((struct Obj0203c108*)self->message, (char*)KeyTable_Get(self->strings, 5));
        return;
    }

    GameState* gs = GameState::GetInstance();
    GameObject* actor = func_0200ff1c(gs, self->memberIndex);
    int var4 = self->spells[sel]->unknown_8_0_;
    int var5 = self->state.mp;
    if (actor != NULL && func_ov000_02153a8c(actor)) {
        var4 = 0;
    } else if (self->spells[sel]->unknown_8_0_ >= 0xff) {
        var4 = 1;
    } else {
        var4 = func_020dd290(actor, var4);
    }
    if (self->spells[sel]->kind == 6) {
        PartyInfo_021716d0* party = (PartyInfo_021716d0*)GameState_GetParty(gs);
        var5 = party->unknown_f6c_;
        var4 = self->spells[sel]->unknown_32_;
    }
    if (var5 < var4) {
        state->depth++;
        state->unknown_8_[self->state.depth] = 0x1a;
        return;
    }

    state->unknown_1e_ = self->spells[sel]->id;
    state->depth++;
    state->unknown_8_[state->depth] = func_ov000_02171210(self->spells[sel], self);
    int* entry = func_ov000_02170cf8(self, state->unknown_1e_);
    if (entry == NULL) return;

#if defined(jpn)
    CachedTextLabel_SetText((struct Obj0203c108*)self->message, (char*)*entry);
#else
    char text[0x80];
    __clear(text, 0x80);
    char upper[0x80];
    __clear(upper, 0x80);
    func_020e4864(*entry, text, 1, 0, 0, 0);
    func_0206819c(text, upper, 0);
    CachedTextLabel_SetText((struct Obj0203c108*)self->message, upper);
#endif
}
