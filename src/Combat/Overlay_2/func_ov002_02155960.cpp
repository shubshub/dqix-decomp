#include <globaldefs.h>
#include <GameState/GameState.h>
#include "Input/Input.h"

#if defined(jpn)
#define RG(u, j) (j)
#define func_0205ec34 func_0205ff20
#else
#define RG(u, j) (u)
#endif

struct Struct_ov002_02155960_2;
struct Struct_ov002_02155960_3;
struct Struct_0201079c;
struct Struct_0201079c_2;

struct Struct_ov002_02155960_4 {
    unsigned char unknown_0_[0xc5];
    unsigned char unknown_c5_;
};

struct Struct_ov002_02155960_5 {
    unsigned char unknown_0_[RG(0x998, 0x868)];
    int unknown_998_;
    int unknown_99c_;
    int unknown_9a0_;
};

struct Struct_ov002_02155960_6 {
    unsigned int unknown_0_;
    unsigned char unknown_4_[0xba4];
    unsigned char unknown_ba8_[RG(0x130, 0xa0)];
};

class Struct_ov002_02155960_7 {
public:
    unsigned int unknown_0_;
    union {
        Struct_0201079c* unknown_0_;
        Struct_0201079c_2* unknown1_0_;
    } unknown_4_;
    unsigned char unknown_8_[RG(0x48, 0x30)];
    unsigned char unknown_50_[RG(0x864, 0x7e0)];
    unsigned char unknown_8b4_[RG(0x614, 0x608)];
    Struct_ov002_02155960_6 unknown_ec8_;
    int unknown_1ba0_;
    unsigned char unknown_1ba4_[0x14];
    int unknown_1bb8_;
    int unknown_1bbc_;
    int unknown_1bc0_;
    int unknown_1bc4_;
    int unknown_1bc8_;
    int unknown_1bcc_;
    unsigned char unknown_1bd0_[0x44];
    unsigned short unknown_1c14_;
    unsigned char unknown_1c16_[0x1a];
    unsigned char unknown_1c30_;
    unsigned char unknown_1c31_[RG(0x92, 0x8e)];
    unsigned char unknown_1cc3_;
    unsigned char unknown_1cc4_;
    unsigned char unknown_1cc5_[RG(0x7a3, 0x70f)];
    void* unknown_2468_;
    unsigned char unknown_246c_[0x10];
    unsigned int unknown_247c_;
    unsigned char unknown_2480_[5];
    unsigned char unknown_2485_;
    unsigned char unknown_2486_;
    unsigned char unknown_2487_;
};

typedef void (Struct_ov002_02155960_7::*Type_ov002_02155960)();
struct Struct_ov002_02155960 {
    unsigned char unknown_0_[0x34];
};

extern "C" int func_ov017_021959b4();
extern "C" void func_ov002_02155024(unsigned char*);
extern "C" int func_020421a0();
extern "C" void func_ov023_021e7404(void*, int);
extern "C" void func_ov002_02156178(unsigned char*);
extern "C" void func_ov023_021eb43c(void*);
extern "C" int func_ov002_02154c30(void*);
extern "C" void func_ov002_0215b648(unsigned char*);
extern "C" void func_ov002_02156bc8(Struct_ov002_02155960_7*);
extern "C" void func_ov002_02156c7c(Struct_ov002_02155960_7*);
extern "C" void func_ov002_021561b0(Struct_ov002_02155960_7*);
extern "C" Struct_ov002_02155960_4* func_0205d8c4(Struct_ov002_02155960_2*);
extern "C" int func_0204c7cc(unsigned char*);
extern "C" void func_0205bc24(void*, int);
extern "C" int func_020e28dc(Struct_0201079c*);
extern "C" void func_020e263c(Struct_0201079c_2*, int);
extern "C" int func_0205d0e0(Struct_ov002_02155960_2*, int);
extern "C" int func_ov002_02161b48(char*, int);
extern "C" void* func_0205ec34();
extern "C" int func_020649b0(void*, int, void*);
extern "C" void func_0206f81c(void*);
extern "C" void func_ov023_021dca88(void*);
extern "C" void func_ov002_0215aa14(char*);
extern "C" int func_0201079c(char*);
extern "C" void func_0205def8(Struct_ov002_02155960_3*, int, int);
extern "C" void func_0205deb4(Struct_ov002_02155960_2*, int, int);
extern "C" void func_ov002_0215bba8(Struct_ov002_02155960_7*);
extern unsigned int data_ov002_0216d3a8;
extern BattleHandler __ptmf_null;
extern BattleHandler data_ov002_0216cd74[RG(44, 47)];

static inline Struct_ov002_02155960_6* inline_ov002_02155960(Struct_ov002_02155960_7* arg0) { SDK_NULL_ASSERT(arg0); return &arg0->unknown_ec8_; }

// USA: func_ov002_02155960
extern "C" ARM int func_ov002_02155960(Struct_ov002_02155960_7* arg0, int arg1) {
    if (func_ov017_021959b4() != 0)
        func_ov002_02155024((unsigned char*)arg0);
    Struct_ov002_02155960_5* var0 = (Struct_ov002_02155960_5*)func_020421a0();
    arg0->unknown_1ba0_ = arg1;
    if (arg0->unknown_1cc3_ != 0)
        func_ov023_021e7404(arg0->unknown_8b4_, arg0->unknown_1ba0_);
    func_ov002_02156178((unsigned char*)arg0);
    if (arg0->unknown_2468_ != 0)
        func_ov023_021eb43c(arg0->unknown_2468_);
    if (arg0->unknown_1bb8_ != 0) {
        arg0->unknown_1cc4_ = 0;
        arg0->unknown_1cc4_ = func_ov002_02154c30(arg0->unknown_ec8_.unknown_ba8_);
        func_ov002_0215b648((unsigned char*)arg0);
        if ((arg0->unknown_247c_ & 0x20) == 0) {
            func_ov002_02156bc8(arg0);
            func_ov002_02156c7c(arg0);
        }
        func_ov002_021561b0(arg0);
        Struct_ov002_02155960_4* var1 = func_0205d8c4((Struct_ov002_02155960_2*)&arg0->unknown_ec8_);
        if (var1 != 0 && func_0204c7cc((unsigned char*)var1) != 0 && (var1->unknown_c5_ & 2) == 0)
            func_0205bc24(inline_ov002_02155960(arg0)->unknown_4_, -1);
        if (arg0->unknown_4_.unknown_0_ != 0 && func_020e28dc(arg0->unknown_4_.unknown_0_) != 0) {
            func_020e263c(arg0->unknown_4_.unknown1_0_, arg0->unknown_1ba0_);
        } else {
            arg0->unknown_1bc8_ = func_0205d0e0((Struct_ov002_02155960_2*)&arg0->unknown_ec8_, arg0->unknown_1ba0_);
        }
    }
    if (arg0->unknown_2485_ != 0) {
        if ((arg0->unknown_1bb8_ == 4 && arg0->unknown_1bc0_ == 1 && func_ov002_02161b48((char*)arg0, 1) != 0) ||
                g_keyManager.TestKeysPressed(0x800) != 0) {
            if (var0->unknown_998_ == 0)
                arg0->unknown_2487_ = 1;
        }
        if (arg0->unknown_2487_ == 1) {
            Struct_ov002_02155960 var2;
            if (func_020649b0(func_0205ec34(), 0x16, &var2) != 0)
                func_0206f81c(&var2);
            if (arg0->unknown_247c_ & 1)
                func_ov023_021dca88(arg0->unknown_50_);
            arg0->unknown_1bb8_ = RG(0x2b, 0x2e);
            arg0->unknown_1bbc_ = RG(0x2b, 0x2e);
            arg0->unknown_2487_ = 2;
        }
    }
    arg0->unknown_1bcc_ = 0;
    if (arg0->unknown_1bb8_ == RG(0x26, 0x29) && var0->unknown_998_ != 0 && var0->unknown_9a0_ == 5)
        return 0;
    if ((data_ov002_0216d3a8 & 1) == 0) {
        BattleHandler empty = __ptmf_null;
#if defined(jpn)
        data_ov002_0216cd74[6] = var3;
        data_ov002_0216cd74[9] = var3;
        data_ov002_0216cd74[19] = var3;
        data_ov002_0216cd74[20] = var3;
        data_ov002_0216cd74[23] = var3;
        data_ov002_0216cd74[27] = var3;
        data_ov002_0216cd74[28] = var3;
        data_ov002_0216cd74[30] = var3;
        data_ov002_0216cd74[33] = var3;
        data_ov002_0216cd74[34] = var3;
        data_ov002_0216cd74[35] = var3;
        data_ov002_0216cd74[43] = var3;
        data_ov002_0216cd74[44] = var3;
        data_ov002_0216cd74[46] = var3;
#else
        data_ov002_0216cd74[8] = var3;
        data_ov002_0216cd74[18] = var3;
        data_ov002_0216cd74[19] = var3;
        data_ov002_0216cd74[22] = var3;
        data_ov002_0216cd74[26] = var3;
        data_ov002_0216cd74[27] = var3;
        data_ov002_0216cd74[29] = var3;
        data_ov002_0216cd74[32] = var3;
        data_ov002_0216cd74[40] = var3;
        data_ov002_0216cd74[41] = var3;
        data_ov002_0216cd74[43] = var3;
#endif
        data_ov002_0216d3a8 |= 1;
    }
    if (data_ov002_0216cd74[arg0->unknown_1bb8_] == 0)
        return (arg0->unknown_247c_ & 1) == 0;
    (arg0->*data_ov002_0216cd74[arg0->unknown_1bb8_])();
    if (arg0->unknown_1bb8_ != 0 && arg0->unknown_1bb8_ != RG(0x1e, 0x1f) && arg0->unknown_1bb8_ != RG(0x2a, 0x2d) && arg0->unknown_1c30_ == 0 && arg0->unknown_1bc0_ == 1) {
        var0 = (Struct_ov002_02155960_5*)func_020421a0();
        if (g_keyManager.TestKeysPressed(0x800) != 0 && var0->unknown_998_ == 0) {
            if (arg0->unknown_1bb8_ == RG(0x21, 0x24))
                func_ov002_0215aa14((char*)arg0);
            if (arg0->unknown_1bb8_ == RG(0xf, 0x10)) {
                func_ov002_02155024((unsigned char*)arg0);
            } else {
                if (arg0->unknown_247c_ & 1)
                    func_ov023_021dca88(arg0->unknown_50_);
                arg0->unknown_1bb8_ = RG(0x2b, 0x2e);
                arg0->unknown_1c14_ = 0;
            }
        }
    }
    if (func_0201079c((char*)GameState::GetInstance()) == 1 || arg0->unknown_2485_ != 0) {
        func_0205def8((Struct_ov002_02155960_3*)&arg0->unknown_ec8_, 0, RG(0x29, 0x2c));
    }
    func_0205deb4((Struct_ov002_02155960_2*)&arg0->unknown_ec8_, RG(0x29, 0x2c), 0);
    func_0205deb4((Struct_ov002_02155960_2*)&arg0->unknown_ec8_, RG(0x28, 0x2b), 0);
    func_ov002_0215bba8(arg0);
    return 0;
}
