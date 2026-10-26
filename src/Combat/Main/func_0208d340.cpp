#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

int IsSubBrightnessTransitionActive(GameResources*);

struct Struct_02074bf4;
extern "C" void func_02074bf4(struct Struct_02074bf4*);

struct Struct_0208ba54;
extern "C" void func_0208ba54(struct Struct_0208ba54*);

struct GameResources;
void SetSubBrightness(GameResources*, int, int);
extern "C" void func_020dc2d0(int);

struct Struct_0208d340 {
    char pad0[0xb8];
    int fb8;
    char pad2[0xd5 - 0xbc];
    unsigned char unknown_d5_;
    char pad3[0xda - 0xd6];
    unsigned short unknown_da_;
};

// USA: func_0208d340
extern "C" ARM void func_0208d340(struct Struct_0208d340* obj) {
    int val = (int)GameState::GetInstance()->GetResources();

    if (obj->unknown_d5_ == 0) {
        if (!(obj->unknown_da_ & 0x10)) {
            SetSubBrightness((GameResources*)val, -16, 8);
        }
        obj->unknown_d5_ = obj->unknown_d5_ + 1;
        return;
    }
    if (obj->unknown_d5_ == 1) {
        if (IsSubBrightnessTransitionActive((GameResources*)val) == 0) {
            obj->unknown_d5_ = obj->unknown_d5_ + 1;
        }
        return;
    }
    if (obj->unknown_d5_ == 2) {
        obj->unknown_da_ = obj->unknown_da_ & ~4;
        func_02074bf4((struct Struct_02074bf4*)((char*)obj + 0x2c));
        func_020dc2d0(0);
        obj->unknown_d5_ = obj->unknown_d5_ + 1;
        return;
    }
    if (obj->unknown_d5_ != 3) return;

    int* reg = (int*)0x4001000;
    *reg = (*reg & ~0x1f00) | (obj->fb8 << 8);
    *(short*)((char*)reg + 0x50) = 0;
    obj->unknown_d5_ = obj->unknown_d5_ + 1;
    func_0208ba54((struct Struct_0208ba54*)obj);
    ClearFlags00((GameResources*)((int)GameState::GetInstance()->GetResources()), 0x6000);
}
