#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov000_0216258c_3 {
    char pad0[8];
    unsigned short maxHP;
    unsigned short maxMP;
    short unknown_c_;
    short unknown_e_;
};

struct Struct_ov000_0216258c {
    char pad[0x14];
    unsigned int flags;
};

struct Struct_ov000_0216258c_2 {
#if defined(jpn)
    char pad0[0x21c];
#else
    char pad0[0x2a0];
#endif
    unsigned char* unknown_2a0_;
#if defined(jpn)
    char unknown_220_[0x371c - 0x220];
#else
    char unknown_2a4_[0x3760 - 0x2a4];
#endif
    char unknown_3760_[1];
};

extern "C" int func_020a35e0(unsigned char* obj, unsigned char index);
extern "C" Struct_ov000_0216258c_3* func_ov000_02161318(void* obj, int index);
extern "C" void func_ov000_0217f518(Struct_ov000_0216258c_3* gauge);
extern "C" void func_ov000_02176134(Struct_ov000_0216258c_3* gauge, unsigned short val);
extern "C" void func_ov000_02176150(Struct_ov000_0216258c_3* gauge, unsigned short val);

// USA: func_ov000_0216258c
extern "C" ARM void func_ov000_0216258c(Struct_ov000_0216258c_2* self) {
    GameState* bs = GameState::GetInstance();
    for (int i = 0; i < 4; i++) {
        if (!func_020a35e0(self->unknown_2a0_, i & 0xff)) continue;
        GameObject* c = func_0200ff1c(bs, i);
        if (!c) continue;
        Struct_ov000_0216258c_3* gauge = func_ov000_02161318(self->unknown_3760_, i);
        if (!gauge) continue;
        if (gauge->unknown_c_ == 0 && !(((Struct_ov000_0216258c*)c->currentStats_)->flags & 1)) {
            func_ov000_0217f518(gauge);
        }
        unsigned short hp = c->currentStats_->primaryStats.currHP;
        func_ov000_02176134(gauge, hp);
        gauge->unknown_c_ = hp;
        unsigned short mp = c->currentStats_->primaryStats.currMP;
        func_ov000_02176150(gauge, mp);
        gauge->unknown_e_ = mp;
        gauge->maxHP = c->baseStats_->primaryStats.maxHP;
        gauge->maxMP = c->baseStats_->primaryStats.maxMP;
    }
}
