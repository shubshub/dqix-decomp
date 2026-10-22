#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
#include <World/Object3D.h>
#include <GameState/GameState.h>

struct Struct_01ff8b48_26 {
    unsigned short unknown_0_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
};

struct Struct_01ff8b48_13 {
    int unknown_0_[0x18 / 4];
};

struct Struct_ov003_021594c4 {
    int unknown_0_[0x20 / 4];
};

struct Struct_02081870_2 {
    int unknown_0_[0xbc / 4];
};

struct Struct_ov006_02158478 {
    int unknown_0_[0xe0 / 4];
};

struct Struct_ov009_02186e00_2 {
    int unknown_0_[0x40 / 4];
};

struct Struct_ov008_021842a0_2 {
    SafeAllocator unknown_0_;
    SafeAllocator unknown_14_;
    SafeAllocator unknown_28_;
    SafeAllocator unknown_3c_;
    SafeAllocator unknown_50_;
    SafeAllocator unknown_64_;
    SafeAllocator unknown_78_;
    SafeAllocator unknown_8c_;
    Struct_01ff8b48_13 unknown_a0_;
    char* unknown_b8_;
    char unknown_bc_[0x14];
    Struct_ov003_021594c4 unknown_d0_[3];
    Struct_02081870_2 unknown_130_;
    Struct_ov006_02158478 unknown_1ec_[6];
    void* unknown_72c_;
    void* unknown_730_;
    void* unknown_734_;
    void* unknown_738_;
    void* unknown_73c_;
    void* unknown_740_;
    unsigned char unknown_744_[8];
    unsigned char unknown_74c_;
    Struct_ov009_02186e00_2 unknown_750_;
    Object3D unknown_790_;
    char unknown_83c_[0x2c8];
    void* unknown_b04_;
    void* unknown_b08_;
    void* unknown_b0c_;
    signed char unknown_b10_;
    unsigned char unknown_b11_;
    unsigned char unknown_b12_;
    unsigned char unknown_b13_;
    short unknown_b14_;
    short unknown_b16_;
    int unknown_b18_;
    int unknown_b1c_;
    int unknown_b20_;
    int unknown_b24_;
    unsigned char unknown_b28_;
    unsigned char unknown_b29_;
    unsigned char unknown_b2a_;
    int unknown_b2c_;
    const void* unknown_b30_;
    void* unknown_b34_;
    void* unknown_b38_;
    void* unknown_b3c_;
    Struct_01ff8b48_26 unknown_b40_[2];
};

typedef void (Struct_ov008_021842a0_2::*Type_02000c9c_12)(unsigned int ticks);

struct Struct_ov008_0218b340 {
    Type_02000c9c_12 unknown_0_[15];
};

extern StateTable data_ov008_0218b340;
extern StateFunction __ptmf_null;

struct Struct_ov008_02184754;
struct Struct_0209ff6c;

extern "C" void func_ov008_021870e4(Struct_ov008_02184754* arg0, unsigned int arg1);
extern "C" void func_0209ff6c(Struct_0209ff6c* arg0);

extern "C" {
void func_ov008_02188ef0(Struct_ov008_021842a0_2* arg0);
unsigned char func_0205d0e0(Struct_02081870_2* arg0, int arg1);
void func_ov008_02186e4c(Struct_ov008_021842a0_2* arg0, unsigned int arg1);
void func_ov008_0218747c(Struct_ov008_021842a0_2* arg0, int arg1);
void func_ov023_021eb43c(void* arg0);
}

// USA: func_ov008_02184754
extern "C" ARM int func_ov008_02184754(Struct_ov008_021842a0_2* arg0)
{
    func_ov008_02188ef0(self);
    unsigned int ticks = GameState::GetInstance()->GetTickCount();
    if (ticks == 0)
        ticks = 1;
    func_0205d0e0(&self->window_, ticks);
    func_ov008_02186e4c(self, ticks);
    self->model_.AdvanceEffects();
    ClearFlagIfDone_021870e4_021870e4((Obj021870e4*)self, ticks);
    func_ov008_0218747c(self, 0);
    func_ov008_0218747c(self, 1);
    StateTable table = data_ov008_0218b340;
    table.states[14] = __ptmf_null;
    if (table.states[self->state_] == NULL)
        return 0;
    (arg0->*var1.unknown_0_[arg0->unknown_b10_])(var0);
    if (arg0->unknown_b04_ != NULL)
        func_0209ff6c((Struct_0209ff6c*)arg0->unknown_b04_);
    if (arg0->unknown_b08_ != NULL)
        func_ov023_021eb43c(arg0->unknown_b08_);
    if (arg0->unknown_b10_ == 14)
        return 1;
    return 0;
}
