#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_02053c6c(unsigned char* obj);
extern "C" void PartyMember_SetVocation(unsigned char* obj, int index);
extern "C" int GameState_GetProtagonistIndex(GameState* battle);
extern "C" void func_020897b4(int a, int b, int c, int d, int e, int f, int g, int h, int i);
extern "C" void func_020e3b8c(char* mgr, int index, int p3, int p4, int p5, int p6, int p7, unsigned char p8);

struct Struct_ov017_021cc830 {
    unsigned char tag;
    unsigned char pad0[3];
    unsigned short id : 3;
    unsigned short value : 8;
    unsigned short slot : 4;
    unsigned short unknown_5_7_ : 1;
    unsigned short field6;
    unsigned int field8;
    unsigned char fieldc;
    unsigned char unknown_d_;
    unsigned char unknown_e_;
};

// USA: func_ov017_021cc830
extern "C" ARM void func_ov017_021cc830(void* unused0, struct Struct_ov017_021cc830* evt, GameState* battle, char* mgr) {
    GameObject* c = func_0200ff1c(battle, evt->id);
    if (c == NULL) return;
    unsigned char* work = (unsigned char*)func_02053c6c((unsigned char*)c);
    if (work == NULL) return;

    int slot = evt->slot;
    PartyMember_SetVocation(work, slot);
    *(unsigned short*)(work + slot * 2 + 0x16c) = evt->value;
    *(work + slot + 0x186) = evt->fieldc;

    if (evt->unknown_5_7_) {
        if (evt->unknown_d_ != 0) {
            unsigned short saved = *(unsigned short*)(work + 0x564);
            func_020897b4(evt->id, evt->value, slot, 0, evt->unknown_e_, 0, 0, 0, 0);
            if (GameState_GetProtagonistIndex(battle) == evt->id) {
                *(unsigned short*)(work + 0x564) = saved;
            }
        } else {
            int flags = 0;
            flags |= 3;
            if (evt->unknown_e_ == 0) flags |= 4;
            func_020e3b8c(mgr, evt->id, evt->value, slot, 0, flags, evt->field8, evt->unknown_e_);
            return;
        }
    }
    *(unsigned int*)(work + slot * 4 + 0x138) = evt->field8;
}
