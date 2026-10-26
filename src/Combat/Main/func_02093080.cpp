#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_0200fb40(void* obj);
extern "C" void func_02092d60(void* s, int b);

struct Struct_02093080 {
    char unk0[0x34];
    unsigned char field34;
    unsigned char unknown_35_;
};

// USA: func_02093080
extern "C" ARM void func_02093080(struct Struct_02093080* s) {
    GameState* bs = GameState::GetInstance();
    unsigned char state = s->unknown_35_;
    if (state == 0) {
        func_0200fb40(bs);
        func_02092d60(s, 1);
        s->unknown_35_++;
        return;
    }
    if (state == 1) {
        s->field34 = 2;
        s->unknown_35_ = 0;
    }
}
