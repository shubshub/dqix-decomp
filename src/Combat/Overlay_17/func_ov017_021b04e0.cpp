#if defined(jpn)
enum { Enum_ov017_021b04e0_2384 = 0x8b8 };
#else
enum { Enum_ov017_021b04e0_2384 = 0x950 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov017_021b04e0 {
    char pad0[0xa];
    unsigned char unknown_a_;
    char pad1[0x21 - 0xb];
    unsigned char unknown_21_;
    unsigned char unknown_22_;
};

extern "C" void func_ov017_021d0b30(int a, int b, int c);
extern "C" void* func_ov017_021b0fe0(int a, int b);
extern "C" void func_ov017_021d1118(int a, int b, int c, int d);
extern "C" void func_ov017_021d1014(int a, int b, int c);
extern "C" int func_02053c6c(unsigned char* obj);
extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" int func_0205e488(void* obj);

// USA: func_ov017_021b04e0
extern "C" ARM unsigned char func_ov017_021b04e0(struct Struct_ov017_021b04e0* self) {
    GameState* bs = GameState::GetInstance();
    unsigned char state = self->unknown_21_;
    if (state == 0) {
        unsigned char* ptr = (unsigned char*)GameState_GetParty(bs);
        unsigned char idx = self->unknown_22_;
        if (ptr[0xf7c] == idx) {
            func_ov017_021d0b30(4, 0, 0);
            return 0xb;
        }
        unsigned char slot = (ptr + idx)[0xf78];
        self->unknown_22_ = idx + 1;
        GameObject* combatant = func_0200ff1c(bs, slot);
        if (combatant == NULL) {
            return self->unknown_a_;
        }
        int field150 = func_02053c6c((unsigned char*)combatant);
        int v = *(int*)((char*)field150 + Enum_ov017_021b04e0_2384) & 0xff;
        func_ov017_021b0fe0(slot, v);
        func_ov017_021d1118(-1, 5, 1, 1);
        func_ov017_021d1014(-1, 1, 1);
        self->unknown_21_ = self->unknown_21_ + 1;
    } else if (state == 1) {
        void* data = LinkMessageQueue_GetInstance();
        if (func_0205e488(data) != 0) {
            self->unknown_21_ = 0;
        }
    }
    return self->unknown_a_;
}
