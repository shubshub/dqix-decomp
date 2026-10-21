#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_ov023_021dc520(void* obj);
extern "C" void func_ov023_021dd404(void* obj);
int DispatchByMode77c_021ddbb8(void* obj, int a, int b);
struct Obj021ddbf8;
int Check_021ddbf8(struct Obj021ddbf8* arg);
extern "C" void func_ov023_021dc354(void* obj);
void SetCombatModeFromCase020dc2d0(int mode);

struct Struct_ov023_021dda04 {
#if defined(jpn)
    char unknown_0_[0x6f0];
#else
    char unknown1_0_[0x774];
#endif
    unsigned short unknown_774_;
    unsigned char unknown_776_;
    unsigned char unknown_777_;
    char unknown_778_[0x77b - 0x778];
    signed char unknown_77b_;
};

// USA: func_ov023_021dda04  (semantic: AdvanceCombatStageState_021dda04)
extern "C" ARM void func_ov023_021dda04(struct Obj021dda04* obj) {
    GameState::GetInstance()->GetResources();

    if (arg0->unknown_777_ == 0) {
        func_ov023_021dc520(arg0);
        func_ov023_021dd404(arg0);
        if (!(arg0->unknown_774_ & 0x40)) {
            arg0->unknown_776_ = 3;
            return;
        }
        func_ov023_021ddbb8(arg0, ~0xf, 8);
        arg0->unknown_777_ = arg0->unknown_777_ + 1;
    }

    if (arg0->unknown_777_ == 1) {
        func_ov023_021dc520(arg0);
        func_ov023_021dd404(arg0);
        if (func_ov023_021ddbf8((struct Struct_ov023_021dd59c*)arg0) == 0) {
            arg0->unknown_777_ = arg0->unknown_777_ + 1;
        }
    }

    if (arg0->unknown_777_ != 2) return;

    func_ov023_021dc354(arg0);
    if (arg0->unknown_774_ & 0x200) {
        arg0->unknown_776_ = 3;
        return;
    }
    if (arg0->unknown_77b_ != 1) {
        func_020dc2d0(0);
    }
    arg0->unknown_776_ = 3;
}
