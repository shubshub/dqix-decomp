#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov026_021d8ba0_6;
struct Struct_ov000_02176038;

struct Struct_ov026_021d8ba0 {
    unsigned char unknown_0_[4];
    signed char unknown_4_;
    unsigned short unknown_6_;
    unsigned short unknown_8_;
};

struct Struct_ov026_021d8ba0_5 {
    char unknown_0_[0xf78];
    signed char unknown_f78_[4];
    unsigned char unknown_f7c_;
};

struct Struct_ov000_0217e870_2 {
    char unknown_0_[0x8];
    unsigned short unknown_8_;
};

struct Struct_ov026_021d8ba0_4 {
    char unknown_0_[0xb8];
};

struct Struct_ov000_02160da0 {
#if defined(jpn)
    char unknown_0_[0x21c];
#else
    char unknown1_0_[0x2a0];
#endif

    Struct_ov000_0217e870_2* unknown_2a0_;
    char unknown_2a4_[0xc08];
    int unknown_eac_;
#if defined(jpn)
    char unknown_e2c_[0x28f0];
#else
    char unknown_eb0_[0x28b0];
#endif

    Struct_ov026_021d8ba0_4 unknown_3760_;
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
    unsigned int unknown_7738_;
};

SlotWork* FindSlotById_021dae60(Container_021dae60* c, int id);
int GetCombatWorkFlags0x55f4_ov000_02160fd4(void* work, int mask);
void SetCombatWorkFlags0x55f4_ov000_02160fa8(void* work, int mask);
void* GlobalFlags_GetInstance();
void FlagWord_SetBits(unsigned int* field, unsigned int bits);
void SetFlagAndCall02176038(Obj02176038* obj);

extern "C" {
void* memset(void*, int, unsigned int);
void func_ov000_0217fcc4(Struct_ov026_021d8ba0_4*, int);
void func_ov000_0217f518(Struct_ov026_021d8ba0_6*);
void func_ov000_02162c14(Struct_ov000_02160da0*, int, Struct_ov026_021d8ba0*);
void func_ov017_021c6814(unsigned short, unsigned short, Struct_ov026_021d8ba0*, unsigned char, int, int);
}

// USA: func_ov026_021dbf04
extern "C" ARM void func_ov026_021dbf04(Struct_ov000_02160da0* arg0) {
    Struct_ov026_021d8ba0 var0;

    int var1 = arg0->unknown_eac_;
    if (var1 == 0) {
        arg0->unknown_eac_ = 0;
    } else if (var1 != 0 && var1 != 1 && var1 != 2) {
        arg0->unknown_eac_ = 3;
    }

    func_ov000_0217fcc4(&arg0->unknown_3760_, -1);
    arg0->unknown_772f_ = 0;
    memset(arg0->unknown_54f4_, 0, sizeof(arg0->unknown_54f4_));

    Roster* roster = (Roster*)GameState_GetParty(GameState::GetInstance());
    for (int i = 0; i < roster->count; i++) {
        int id = roster->ids[i];
        SlotWork* slot = FindSlotById_021dae60(&self->list, id);
        if (slot != NULL) {
            func_ov000_0217f518(slot);
            func_ov000_02162c14(self, id, &cmd);
            func_ov017_021c6814(self->party->netId, id, &cmd, 0, -1, 0);
        }
    }

    int var6 = func_ov000_02160fd4(arg0, 0x2000000);
    arg0->unknown_55f4_ = arg0->unknown_7734_;
    if (var6) {
        func_ov000_02160fa8(arg0, 0x2000000);
    }
    FlagWord_SetBits((unsigned int*)GlobalFlags_GetInstance(), self->savedField);
    SetFlagAndCall02176038((Obj02176038*)&self->list);
}
