#include <globaldefs.h>
#include "GameState/GameState.h"

int IsSubBrightnessTransitionActive(GameResources*);
struct GameResources;
void SetSubBrightness(GameResources*, int, int);
struct Struct_02074bf4;
extern "C" void func_02074e54(struct Struct_02074bf4*);
extern "C" void* GlobalFlags_GetInstance(void);
struct FlagWord020466f4;
extern "C" void FlagWord_ClearBits(struct FlagWord020466f4* word, unsigned int mask);
extern "C" void func_020dc2d0(int);

struct Struct_ov003_0215445c {
    char pad0[0x38];
    char pad1[0x58 - 0x38];
    unsigned char unknown_58_;
    char pad2[0x5a - 0x59];
    unsigned char unknown_5a_;
    unsigned char unknown_5b_;
};

// USA: func_ov003_0215445c
extern "C" ARM void func_ov003_0215445c(struct Struct_ov003_0215445c* self) {
    int w = (int)GameState::GetInstance()->GetResources();

    if (self->unknown_58_ == 0) {
        self->unknown_5a_ = 3;
        return;
    }
    if (self->unknown_5b_ == 0) {
        SetSubBrightness((GameResources*)w, -16, 1);
        self->unknown_5b_ = self->unknown_5b_ + 1;
        return;
    }
    if (self->unknown_5b_ != 1) return;
    if (IsSubBrightnessTransitionActive((GameResources*)w) != 0) return;

    func_02074e54((struct Struct_02074bf4*)((char*)self + 0x38));
    FlagWord_ClearBits((struct FlagWord020466f4*)GlobalFlags_GetInstance(), 1);
    func_020dc2d0(0);
    self->unknown_5a_ = 3;
    self->unknown_5b_ = 0;
}
