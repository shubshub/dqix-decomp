#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov026_021d8ba0_6;
struct Struct_ov000_02176038;

struct Struct_ov026_021d8ba0 {
    unsigned char b[4];
    signed char c;
    unsigned short d;
    unsigned short e;
};

struct Roster {
    char pad0[0xf78];
    signed char ids[4];
    unsigned char count;
};

struct PartyState {
    char pad0[0x8];
    unsigned short netId;
};

struct Container_021dae60 {
    char pad0[0xb8];
};

struct Struct_ov000_02160da0 {
#if defined(jpn)
    char pad0[0x21c];
#else
    char pad0[0x2a0];
#endif

    PartyState* party;
    char unknown_2a4_[0xc08];
    int state;
#if defined(jpn)
    char unknown_e2c_[0x28f0];
#else
    char unknown_eb0_[0x28b0];
#endif

    Container_021dae60 list;
#if defined(jpn)
    char unknown_37d4_[0x1f14];
#else
    char unknown_3818_[0x1cdc];
#endif

    int unknown_54f4_[4];
#if defined(jpn)
    char unknown_56f8_[0xec];
#else
    char unknown_5504_[0xf0];
#endif

    int unknown_55f4_;
    char unknown_55f8_[0x2137];
    unsigned char unknown_772f_;
    char unknown_7730_[0x4];
    int unknown_7734_;
    unsigned int savedField;
};

extern "C" Struct_ov026_021d8ba0_6* func_ov026_021dae60(Container_021dae60* c, int id);
extern "C" int func_ov000_02160fd4(void* work, int mask);
extern "C" void func_ov000_02160fa8(void* work, int mask);
extern "C" void* GlobalFlags_GetInstance();
extern "C" void FlagWord_SetBits(unsigned int* field, unsigned int bits);
extern "C" void func_ov000_02176038(Struct_ov000_02176038* obj);

extern "C" {
void* memset(void*, int, unsigned int);
void func_ov000_0217fcc4(Container_021dae60*, int);
void func_ov000_0217f518(Struct_ov026_021d8ba0_6*);
void func_ov000_02162c14(Struct_ov000_02160da0*, int, Struct_ov026_021d8ba0*);
void func_ov017_021c6814(unsigned short, unsigned short, Struct_ov026_021d8ba0*, unsigned char, int, int);
}

// USA: func_ov026_021dbf04
extern "C" ARM void func_ov026_021dbf04(Struct_ov000_02160da0* self) {
    Struct_ov026_021d8ba0 cmd;

    int state = self->state;
    if (state == 0) {
        self->state = 0;
    } else if (state != 0 && state != 1 && state != 2) {
        self->state = 3;
    }

    func_ov000_0217fcc4(&self->list, -1);
    self->unknown_772f_ = 0;
    memset(self->unknown_54f4_, 0, sizeof(self->unknown_54f4_));

    Roster* roster = (Roster*)GameState_GetParty(GameState::GetInstance());
    for (int i = 0; i < roster->count; i++) {
        int id = roster->ids[i];
        Struct_ov026_021d8ba0_6* slot = func_ov026_021dae60(&self->list, id);
        if (slot != NULL) {
            func_ov000_0217f518(slot);
            func_ov000_02162c14(self, id, &cmd);
            func_ov017_021c6814(self->party->netId, id, &cmd, 0, -1, 0);
        }
    }

    int var6 = func_ov000_02160fd4(self, 0x2000000);
    self->unknown_55f4_ = self->unknown_7734_;
    if (var6) {
        func_ov000_02160fa8(self, 0x2000000);
    }
    FlagWord_SetBits((unsigned int*)GlobalFlags_GetInstance(), self->savedField);
    func_ov000_02176038((Struct_ov000_02176038*)&self->list);
}
