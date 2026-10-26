#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_ov023_021dc520(void* obj);
extern "C" void func_ov023_021dd404(void* obj);
extern "C" int func_ov023_021ddbb8(void* obj, int a, int b);
struct Struct_ov023_021dd59c;
extern "C" int func_ov023_021ddbf8(struct Struct_ov023_021dd59c* arg);
extern "C" void func_ov023_021dc354(void* obj);
extern "C" void func_020dc2d0(int mode);

struct Struct_ov023_021dda04 {
#if defined(jpn)
    char pad0[0x6f0];
#else
    char pad0[0x774];
#endif
    unsigned short field774;
    unsigned char unknown_776_;
    unsigned char unknown_777_;
    char unknown_778_[0x77b - 0x778];
    signed char unknown_77b_;
};

// USA: func_ov023_021dda04
extern "C" ARM void func_ov023_021dda04(struct Struct_ov023_021dda04* obj) {
    GameState::GetInstance()->GetResources();

    if (obj->unknown_777_ == 0) {
        func_ov023_021dc520(obj);
        func_ov023_021dd404(obj);
        if (!(obj->field774 & 0x40)) {
            obj->unknown_776_ = 3;
            return;
        }
        func_ov023_021ddbb8(obj, ~0xf, 8);
        obj->unknown_777_ = obj->unknown_777_ + 1;
    }

    if (obj->unknown_777_ == 1) {
        func_ov023_021dc520(obj);
        func_ov023_021dd404(obj);
        if (func_ov023_021ddbf8((struct Struct_ov023_021dd59c*)obj) == 0) {
            obj->unknown_777_ = obj->unknown_777_ + 1;
        }
    }

    if (obj->unknown_777_ != 2) return;

    func_ov023_021dc354(obj);
    if (obj->field774 & 0x200) {
        obj->unknown_776_ = 3;
        return;
    }
    if (obj->unknown_77b_ != 1) {
        func_020dc2d0(0);
    }
    obj->unknown_776_ = 3;
}
