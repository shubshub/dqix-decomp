#if defined(jpn)
#define R(j,u) (j)
#define data_ov009_0218ab9c data_ov009_0218bb04
#define func_ov009_02188454 func_ov009_02189214
#define func_ov009_02188604 func_ov009_021893c4
#else
#define R(j,u) (u)
#endif
#if defined(jpn)
extern "C" int func_ov009_02185c58(void*);
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_0205d81c;
struct Struct_ov009_02184a18;

struct Struct_ov006_02158478 {
    char unknown_0_[0xc5];
    unsigned char unknown_c5_;
};

struct Struct_ov009_02184a18_2 {
    char unknown_0_[4];
    int unknown_4_[0x14];
    int unknown_54_[0x10];
    unsigned char unknown_94_[4];
};

struct Struct_02081870_2 {
    Struct_ov009_02184a18_2 unknown_0_;
    char unknown_98_[0xbc - 0x98];
};

extern "C" void func_020a20d8(void* arg0);
extern "C" Struct_ov006_02158478* func_0205d8c4(Struct_0205d81c* arg0);
extern "C" int func_0204c7cc(unsigned char* arg0);
extern "C" void func_0205bc24(void* arg0, int arg1);
extern "C" int func_0205d0e0(Struct_02081870_2* arg0, unsigned int arg1);
extern "C" void func_ov023_021e5020(void* arg0);
extern "C" void func_ov009_02188604(void* arg0, unsigned int arg1);
extern "C" void func_ov009_02188454(void* arg0);
extern "C" void func_ov009_021885b8(Struct_ov009_02184a18* arg0);
extern "C" void func_ov009_02184d70(void* arg0);

struct Struct_ov009_021842a0_2 {
    char unknown_0_[R(0x1bc, 0x1f8)];
    Struct_02081870_2 unknown_1f8_[2];
    char unknown_370_[0x7f8 - 0x370];
    void* unknown_7f8_;
    void* unknown_7fc_;
    char unknown_800_[0x878 - 0x800];
    Object3D unknown_878_;
    char unknown_924_[0x2c8];
    char unknown_bec_[0xc58 - 0xbec];
    signed char unknown_c58_;
    unsigned char unknown_c59_;
    char unknown_c5a_[0xcd8 - 0xc5a];
    Object3D unknown_cd8_;
    unsigned char unknown_d84_;
    unsigned char unknown_d85_;
    char unknown_d86_[0xd9c - 0xd86];
    unsigned int unknown_d9c_;

    void inline_ov009_021842a0();
};

typedef void (Struct_ov009_021842a0_2::*Type_02000c9c_2)();

struct Struct_ov008_0218b340 {
    Type_02000c9c_2 unknown_0_[13];
};

extern const StateTable data_ov009_0218ab9c;
extern const StateFunc __ptmf_null;

// USA: func_ov009_02184a18
extern "C" ARM int func_ov009_02184a18(Struct_ov009_021842a0_2* arg0)
{
    unsigned int ticks = GameState::GetInstance()->GetTickCount();
    if (ticks == 0)
        ticks = 1;
    if (self->state_ != 0)
        AdvanceActor020a20d8(self->camera_);
    if (self->state_ == 9 && self->step_ == 2) //Does not run at startup
    {
        Struct_ov006_02158478* var1 = func_0205d8c4((Struct_0205d81c*)&arg0->unknown_1f8_[1]);
        if (var1 != NULL && func_0204c7cc((unsigned char*)var1) != 0 && !(var1->unknown_c5_ & 2))
            func_0205bc24(&arg0->unknown_1f8_[1].unknown_0_.unknown_4_, -1);
    }
    func_0205d0e0(&arg0->unknown_1f8_[0], var0);
    arg0->unknown_d85_ = func_0205d0e0(&arg0->unknown_1f8_[1], var0);
    if (arg0->unknown_d9c_ & 0x200)
    {
        arg0->unknown_878_.AdvanceEffects();
        arg0->unknown_cd8_.AdvanceEffects();
    }
    if (arg0->unknown_7f8_ != NULL)
        func_ov023_021e5020(arg0->unknown_7f8_);
    if (arg0->unknown_7fc_ != NULL)
        func_ov023_021e5020(arg0->unknown_7fc_);
    func_ov009_02188604(arg0, var0);
    func_ov009_02188454(arg0);
    func_ov009_021885b8((Struct_ov009_02184a18*)arg0);

    StateTable table = data_ov009_0218ab9c;
    table.states[12] = __ptmf_null;
    if (table.states[self->state_] == 0)
        return 0;
    (arg0->*var2.unknown_0_[arg0->unknown_c58_])();
    func_ov009_02184d70(arg0);
#if defined(jpn)
    func_ov009_02185c58((char*)arg0 + 0xdc);
#endif
    return arg0->unknown_c58_ == 12;
}
