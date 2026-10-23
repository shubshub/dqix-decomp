#include <globaldefs.h>
#include "GameState/GameState.h"

int GetFieldAt0x150_02053c6c(unsigned char* obj);
void PartyMember_SetVocation(unsigned char* obj, int index);
int GetField0x3acValue_020100a8(GameState* battle);
extern "C" void func_020897b4(int a, int b, int c, int d, int e, int f, int g, int h, int i);
void InitAndRequeueEntry020e3b8c(char* mgr, int index, int p3, int p4, int p5, int p6, int p7, unsigned char p8);

struct Struct_ov017_021cc830 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[3];
    unsigned short unknown_4_0_ : 3;
    unsigned short unknown_4_3_ : 8;
    unsigned short unknown_5_3_ : 4;
    unsigned short unknown_5_7_ : 1;
    unsigned short unknown_6_;
    unsigned int unknown_8_;
    unsigned char unknown_c_;
    unsigned char unknown_d_;
    unsigned char unknown_e_;
};

// USA: func_ov017_021cc830
extern "C" ARM void func_ov017_021cc830(void* arg0, struct Struct_ov017_021cc830* arg1, GameState* arg2, char* arg3) {
    GameObject* var0 = func_0200ff1c(arg2, arg1->unknown_4_0_);
    if (var0 == NULL) return;
    unsigned char* var1 = (unsigned char*)func_02053c6c((unsigned char*)var0);
    if (var1 == NULL) return;

    int slot = evt->slot;
    PartyMember_SetVocation(work, slot);
    *(unsigned short*)(work + slot * 2 + 0x16c) = evt->value;
    *(work + slot + 0x186) = evt->fieldc;

    if (arg1->unknown_5_7_) {
        if (arg1->unknown_d_ != 0) {
            unsigned short var3 = *(unsigned short*)(var1 + 0x564);
            func_020897b4(arg1->unknown_4_0_, arg1->unknown_4_3_, var2, 0, arg1->unknown_e_, 0, 0, 0, 0);
            if (func_020100a8(arg2) == arg1->unknown_4_0_) {
                *(unsigned short*)(var1 + 0x564) = var3;
            }
        } else {
            int var4 = 0;
            var4 |= 3;
            if (arg1->unknown_e_ == 0) var4 |= 4;
            func_020e3b8c(arg3, arg1->unknown_4_0_, arg1->unknown_4_3_, var2, 0, var4, arg1->unknown_8_, arg1->unknown_e_);
            return;
        }
    }
    *(unsigned int*)(var1 + var2 * 4 + 0x138) = arg1->unknown_8_;
}
