#if defined(jpn)
enum {Enum_ov023_021e3db0_296=0x124, Enum_ov023_021e3db0_304=0x12c, Enum_ov023_021e3db0_1252=0x4e0};
#else
enum {Enum_ov023_021e3db0_296=0x128, Enum_ov023_021e3db0_304=0x130, Enum_ov023_021e3db0_1252=0x4e4};
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"

struct GameResources;
void SetBrightness(GameResources*, int, int);
int IsBrightnessTransitionActive(GameResources*);

extern "C" void func_ov023_021e5020(void* arg0);
extern "C" void func_ov023_021e4c18(void* arg0);
extern "C" void func_ov023_021e463c(void* arg0, int arg1);
extern "C" void func_ov023_021e447c(void* arg0);
extern "C" void func_ov023_021e456c(void* arg0);
extern "C" void func_ov023_021e3e98(void* arg0);
extern "C" void func_ov005_02154de8(void* arg0);

struct Struct_ov023_021e3db0 {
    void* unknown_0_;
    char unknown_4_[Enum_ov023_021e3db0_296 - 0x4];
    void* unknown_128_;
    void* unknown_12c_;
    char unknown_130_[Enum_ov023_021e3db0_1252 - Enum_ov023_021e3db0_304];
    unsigned char unknown_4e4_;
};

// USA: func_ov023_021e3db0
extern "C" ARM void func_ov023_021e3db0(struct Obj021e3db0* obj) {
    int val = (int)GameState::GetInstance()->GetResources();

    if (arg0->unknown_128_ != 0) {
        func_ov023_021e5020(arg0->unknown_128_);
    }
    if (arg0->unknown_12c_ != 0) {
        func_ov023_021e5020(arg0->unknown_12c_);
    }

    if (arg0->unknown_4e4_ == 0) {
        if (arg0->unknown_128_ != 0 && *((unsigned char*)arg0->unknown_128_ + 0xc12) != 0) {
            return;
        }
        SetBrightness((GameResources*)var0, 0, 15);
        arg0->unknown_4e4_++;
    } else if (arg0->unknown_4e4_ == 1) {
        if (!IsBrightnessTransitionActive((GameResources*)var0)) {
            arg0->unknown_4e4_++;
        }
    } else if (arg0->unknown_4e4_ == 2) {
        func_ov023_021e4c18(arg0);
        int var1 = GameState::GetInstance()->GetTickCount();
        func_ov023_021e463c(arg0, var1);
        func_ov023_021e447c(arg0);
        func_ov023_021e456c(arg0);
        func_ov023_021e3e98(arg0);
    }

    if (arg0->unknown_0_ == 0) {
        return;
    }
    func_ov005_02154de8(arg0->unknown_0_);
}
