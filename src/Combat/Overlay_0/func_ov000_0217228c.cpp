#include <globaldefs.h>
#include "GameState/GameState.h"

unsigned char GameState_GetPartyOrder(char* obj, void* dst);
unsigned char GameState_GetOwnPartyOrder(char* obj, void* dst);
extern "C" void __clear(void* dst, int count);
extern "C" void* func_ov000_02161318(void* obj, int index);
extern "C" int func_ov000_0217f5dc(void* entry);

struct Struct_ov000_0217228c {
    unsigned char unknown_0_[0x6c];
    unsigned char unknown_6c_[4];
    signed char unknown_70_[4];
    unsigned char unknown_74_[5];
    unsigned char unknown_79_;
};

// USA: func_ov000_0217228c
extern "C" ARM void func_ov000_0217228c(struct Party0217228c* self) {
    GameState* state = GameState::GetInstance();
    unsigned char orderBuf[4];
    int count = GameState_GetPartyOrder((char*)state, orderBuf);
    unsigned char used[4];
    __clear(used, 4);
    for (int i = 0; i < count; i++) {
        self->order[i] = orderBuf[i];
        used[orderBuf[i]] = 1;
    }
    for (; var2 < 4; var2++) {
        for (int var5 = 0; var5 < 4; var5++) {
            if (var3[var5] == 0) {
                arg0->unknown_6c_[var2] = var5;
                var3[var5] = 1;
                break;
            }
        }
    }
#if defined(jpn)
    signed char var6[4];
#else
    unsigned char var6[4];
#endif
    unsigned char active = 0;
    int numMembers = GameState_GetOwnPartyOrder((char*)state, memberBuf);
    for (int k = 0; k < 4; k++) {
#if defined(jpn)
        if (var9 < var8) {
            arg0->unknown_70_[var9] = var6[var9];
        } else {
            arg0->unknown_70_[var9] = -1;
        }
#else
        arg0->unknown_70_[var9] = -1;
        if (var9 < var8) {
            arg0->unknown_70_[var9] = var6[var9];
        }
#endif
        void* var10 = func_ov000_02161318(arg0, arg0->unknown_70_[var9]);
        if (var10 != NULL && func_ov000_0217f5dc(var10) != 0) {
            var7++;
        }
    }
    arg0->unknown_79_ = var7;
}
