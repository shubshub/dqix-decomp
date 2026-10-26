#if defined(jpn)
enum { Enum_ov017_021b05c4_2384 = 0x8b8 };
#else
enum { Enum_ov017_021b05c4_2384 = 0x950 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov017_021b05c4 {
    char pad0[0xa];
    unsigned char unknown_a_;
    char pad1[0xc - 0xb];
    unsigned char unknown_c_;
    char pad2[0x1b - 0xd];
    unsigned char unknown_1b_[4];
    char pad3[0x23 - 0x1f];
    unsigned char unknown_23_;
    unsigned char unknown_24_;
    unsigned char unknown_25_;
};

extern "C" void func_ov017_021d0d58(void);
extern "C" int func_02053c6c(unsigned char* obj);
extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" int func_0205e488(void* obj);
extern "C" void* func_ov017_021b0fe0(int a, int b);

// USA: func_ov017_021b05c4
extern "C" ARM unsigned char func_ov017_021b05c4(struct Struct_ov017_021b05c4* self) {
    GameState* bs = GameState::GetInstance();
    if (self->unknown_23_ == 0) {
        if (self->unknown_24_ == 4) {
            func_ov017_021d0d58();
            self->unknown_25_ = 0;
            return 0xa;
        }
        int idx = -1;
        unsigned char* var2 = &self->unknown_24_;
        while (self->unknown_24_ < 4) {
            if (self->unknown_c_ != self->unknown_24_ && self->unknown_1b_[self->unknown_24_] != 3 && self->unknown_1b_[self->unknown_24_] != 0) {
                idx = self->unknown_24_;
                self->unknown_24_ = *var2 + 1;
                break;
            }
            self->unknown_24_ = *var2 + 1;
        }
        if (idx < 0) {
            return self->unknown_a_;
        }
        GameObject* combatant = func_0200ff1c(bs, idx);
        if (combatant == 0) {
            return self->unknown_a_;
        }
        int field150 = func_02053c6c((unsigned char*)combatant);
        int val = *(int*)((char*)field150 + Enum_ov017_021b05c4_2384) & 0xff;
        func_ov017_021b0fe0(idx, val);
        self->unknown_23_ = self->unknown_23_ + 1;
    } else if (self->unknown_23_ == 1) {
        void* data = LinkMessageQueue_GetInstance();
        if (func_0205e488(data) != 0) {
            self->unknown_23_ = 0;
        }
    }
    return self->unknown_a_;
}
