#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Input/Input.h"

extern "C" int func_0205d0e0(void* arg0, int arg1);
extern "C" int func_ov023_021e2868(void* arg0);

struct Block16Words0216e124 { unsigned int w[16]; };
extern struct Block16Words0216e124 data_ov003_0217f5c0;
struct Pair0216e124 { unsigned int a; unsigned int b; };
extern struct Pair0216e124 __ptmf_null;
struct DispatchEntry0216e124 { unsigned int fn; unsigned int locator; };

struct Struct_ov003_0216e124_2 {
    char unknown_0_[1];
    signed char unknown_1_;
    char unknown_2_[0xc - 2];
    short unknown_c_;
    short unknown_e_;
    char unknown_10_[0x3c - 0x10];
    void* unknown_3c_;
    char unknown_40_[0xd4 - 0x40];
    void* unknown_d4_;
};

// USA: func_ov003_0216e124
extern "C" ARM int func_ov003_0216e124(struct Struct_ov003_0216e124_2* arg0) {
    unsigned int var0 = GameState::GetInstance()->GetTickCount();
    if (arg0->unknown_3c_ != 0) {
        func_0205d0e0(arg0->unknown_3c_, var0);
    }
    if (arg0->unknown_d4_ != 0) {
        arg0->unknown_c_ = (short)func_ov023_021e2868(arg0->unknown_d4_);
        if (g_touchInput.pressed_ != 0) {
            arg0->unknown_e_ = arg0->unknown_c_;
        } else {
            arg0->unknown_e_ = 0;
        }
    }

    struct Block16Words0216e124 buf;
    buf = data_ov003_0217f5c0;
    struct Pair0216e124* pr = &__ptmf_null;
    unsigned int tmp1 = pr->b;
    unsigned int tmp0 = pr->a;
    ((struct DispatchEntry0216e124*)&buf)[7].locator = tmp1;
    ((struct DispatchEntry0216e124*)&buf)[7].fn = tmp0;

    signed char var5 = arg0->unknown_1_;
    struct Struct_ov003_0216e124* var6 = (struct Struct_ov003_0216e124*)&var1;
    if (var6[var5].unknown_0_ == 0) return 0;
    struct Struct_ov003_0216e124* var7 = &var6[var5];
    void* var8 = (char*)arg0 + ((int)var7->unknown_4_ >> 1);
    void (*var9)(void*);
    if (var7->unknown_4_ & 1) {
        var9 = (void(*)(void*))(*(void**)((char*)*(void**)var8 + var7->unknown_0_));
    } else {
        var9 = (void(*)(void*))var7->unknown_0_;
    }
    var9(var8);
    return 1;
}
