#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_02053f7c_3;
extern "C" unsigned int func_02053f7c(Struct_02053f7c_3*, unsigned short, int);

struct Struct_ov017_021cbeec {
    unsigned char pad0[4];
    signed char member;
    unsigned char pad5;
    unsigned short value;
};

// USA: func_ov017_021cbeec
extern "C" ARM void func_ov017_021cbeec(int unused0, Struct_ov017_021cbeec* evt, GameState* gameState, unsigned char* base) {
    unsigned int member = (unsigned int)gameState->GetPartyMemberByIndex(evt->member);
    if (member != 0) {
        func_02053f7c((Struct_02053f7c_3*)member, evt->value, 1);
    }
}
