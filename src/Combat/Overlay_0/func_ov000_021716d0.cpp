#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_0201099c_3;
struct Struct_0203c108_3;

struct Struct_ov000_021716d0 {
    char unknown_0_[4];
    unsigned int unknown_4_0_ : 12;
    unsigned int unknown_5_4_ : 20;
    unsigned int unknown_8_0_ : 8;
    unsigned int unknown_9_0_ : 24;
    char unknown_c_[0x2c - 0xc];
    unsigned int unknown_2c_0_ : 10;
    unsigned int unknown_2d_2_ : 4;
    unsigned int unknown_2d_6_ : 18;
    char unknown_30_[2];
    short unknown_32_;
};

struct Struct_ov000_021716d0_2 {
    char unknown_0_[6];
    short unknown_6_;
    signed char unknown_8_[8];
    signed char unknown_10_;
    char unknown_11_[0x15 - 0x11];
    unsigned char unknown_15_;
    short unknown_16_;
    char unknown_18_[0x1e - 0x18];
    unsigned short unknown_1e_;
};

struct Struct_ov000_021716d0_3 {
    char unknown_0_[0xf6c];
    int unknown_f6c_;
};

struct Struct_ov000_021716d0_4 {
    char unknown_0_[4];
    struct Struct_0201099c_3* unknown_4_;
    Struct_ov000_021716d0_2 unknown_8_;
    char unknown_28_[0x4c - 0x28];
    int unknown_4c_;
    char unknown_50_[LOW_REGION(0x1e4, 0x1a4) - 0x50];
    Struct_ov000_021716d0* unknown_1a4_[1];
};

int KeyTable_Get(struct Container020e0310* c, int key);
void CachedTextLabel_SetText(struct Obj0203c108* obj, char* text);
int IsFlag0x18Bit0x200Set_ov000_02153a8c(GameObject* obj);
int AdjustValueByFieldFlag_020dd290(void* obj, unsigned int value);
extern "C" int func_ov000_02171210(void* a, void* b);
extern "C" int* func_ov000_02170cf8(void* obj, int id);
extern "C" void __clear(void* dst, int size);
#if !defined(jpn)
extern "C" void func_020e4864(int arg0, char* arg1, int arg2, int arg3, int arg4, int arg5);
#endif
extern "C" void func_0206819c(const char* arg0, char* arg1, int arg2);

// USA: func_ov000_021716d0
extern "C" ARM void func_ov000_021716d0(MenuEntry_021716d0* self) {
    MenuState_021716d0* state = &self->state;
    int sel = state->selected;
    if (self->spells[sel] == NULL) {
        state->depth++;
        state->stack[self->state.depth] = 0xe;
        state->field15 = 0;
        CachedTextLabel_SetText((struct Obj0203c108*)self->message, (char*)KeyTable_Get(self->strings, 5));
        return;
    }

    GameState* var2 = GameState::GetInstance();
    GameObject* var3 = func_0200ff1c(var2, arg0->unknown_4c_);
    int var4 = arg0->unknown_1a4_[var1]->unknown_8_0_;
    int var5 = arg0->unknown_8_.unknown_6_;
    if (var3 != NULL && func_ov000_02153a8c(var3)) {
        var4 = 0;
    } else if (arg0->unknown_1a4_[var1]->unknown_8_0_ >= 0xff) {
        var4 = 1;
    } else {
        var4 = func_020dd290(var3, var4);
    }
    if (self->spells[sel]->kind == 6) {
        PartyInfo_021716d0* party = (PartyInfo_021716d0*)GameState_GetParty(gs);
        have = party->gold;
        cost = self->spells[sel]->goldCost;
    }
    if (var5 < var4) {
        var0->unknown_10_++;
        var0->unknown_8_[arg0->unknown_8_.unknown_10_] = 0x1a;
        return;
    }

    var0->unknown_1e_ = arg0->unknown_1a4_[var1]->unknown_4_0_;
    var0->unknown_10_++;
    var0->unknown_8_[var0->unknown_10_] = func_ov000_02171210(arg0->unknown_1a4_[var1], arg0);
    int* var7 = func_ov000_02170cf8(arg0, var0->unknown_1e_);
    if (var7 == NULL) return;

#if defined(jpn)
    CachedTextLabel_SetText((struct Obj0203c108*)self->message, (char*)*entry);
#else
    char text[0x80];
    __clear(text, 0x80);
    char upper[0x80];
    __clear(upper, 0x80);
    func_020e4864(*entry, text, 1, 0, 0, 0);
    CopyTextAndUppercaseIfFlagged0206819c(text, upper, 0);
    CachedTextLabel_SetText((struct Obj0203c108*)self->message, upper);
#endif
}
