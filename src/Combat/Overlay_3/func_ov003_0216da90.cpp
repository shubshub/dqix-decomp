#include <globaldefs.h>

#if defined(jpn)
#define func_ov003_0216da90 func_ov003_0216d478
#endif
#include "GameState/GameState.h"

struct Struct_0205de24_2;
struct Struct_0205c570;
struct Struct_0205d81c;
struct Struct_0205ba68;
struct Struct_0205bacc;
struct Struct_0201099c_3;
struct Struct_02000c9c_8;

struct Struct_ov003_0216da90_2
{
    int unknown_0_;
    int unknown_4_;
    char unknown_8_[0x40 - 0x8];
};

struct Struct_ov003_0216da90_3
{
    short unknown_0_;
    short unknown_2_;
    short unknown_4_;
    short unknown_6_;

    void inline_ov003_0216da90(short arg0, short arg1)
    {
        unknown_0_ = arg0;
        unknown_2_ = arg1;
    }

    void inline_ov003_0216da90_2(short arg0, short arg1)
    {
        unknown_4_ = arg0;
        unknown_6_ = arg1;
    }
};

struct Struct_ov003_0216da90_4
{
    int unknown_0_;
    Struct_ov003_0216da90_2 unknown_4_;
    char unknown_44_[0x54 - 0x44];
    Struct_ov003_0216da90_2 unknown_54_;
    unsigned char unknown_94_;
    unsigned char unknown_95_;
    char unknown_96_[0xa0 - 0x96];
    Struct_ov003_0216da90_3 unknown_a0_;
    Struct_ov003_0216da90_3 unknown_a8_;
    char unknown_b0_;
    unsigned char unknown_b1_;
    char unknown_b2_[3];
    unsigned char unknown_b5_;
};

struct Struct_ov003_0216da90
{
    char unknown_0_[0x10];
    int unknown_10_;
#if defined(jpn)
    char unknown_14_[0x1150 - 0x14];
#else
    char unknown1_14_[0x12c0 - 0x14];
#endif
    Struct_ov003_0216da90_4* unknown_12c0_;
    char unknown_12c4_[0x1324 - 0x12c4];
    char unknown_1324_[4];
};

extern "C" void __clear(void* arg0, int arg1);
extern "C" void func_0205de24(Struct_0205de24_2* arg0, unsigned char arg1, unsigned char arg2);
extern "C" void func_0205cef8(void* arg0);
extern "C" unsigned char func_0200fb08(Struct_02000c9c_8* arg0);
extern "C" int func_0205d794(Struct_0205c570* arg0);
extern "C" void func_02041c08(char* arg0, int arg1, int arg2, int arg3, int arg4, int arg5);
extern "C" const char* func_020e0434(Struct_0201099c_3* arg0, int arg1);
extern "C" void func_02042058(char* arg0, const char* arg1);
#if defined(jpn)
extern "C" void func_0205d304(void* arg0, void* arg1, int arg2, int arg3, int arg4, int arg5, int arg6);
#else
extern "C" void func_0205d304(void* arg0, void* arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7);
#endif
Window0216da90* FindElementByC40205d81c(Struct_0205d81c* s, int key);
void GridCursor_SetDimensions(Struct_0205ba68* s, int a, int b, int mode);
void GridCursor_SetCount(Node0205bacc* s, int val);

extern short data_ov003_0217f560[];

// USA: func_ov003_0216da90
extern "C" ARM void func_ov003_0216da90(Struct_ov003_0216da90* arg0)
{
    func_0205de24((Struct_0205de24_2*)arg0->unknown_12c0_, 0, 1);
    arg0->unknown_12c0_->unknown_b1_ = 0;
#if defined(jpn)
    arg0->unknown_12c0_->unknown_a0_.inline_ov003_0216da90(0xc, 7);
    arg0->unknown_12c0_->unknown_a0_.inline_ov003_0216da90_2(0x11, 1);
#endif
    arg0->unknown_12c0_->unknown_a8_.inline_ov003_0216da90(0xd, 5);
    arg0->unknown_12c0_->unknown_a8_.inline_ov003_0216da90_2(0xa, 0xc);
    arg0->unknown_12c0_->unknown_b5_ = 1;
    func_0205cef8(arg0->unknown_12c0_);

#if !defined(jpn)
    short var0 = data_ov003_0217f560[func_0200fb08((Struct_02000c9c_8*)GameState::GetInstance())];
    arg0->unknown_12c0_->unknown_a0_.inline_ov003_0216da90(var0, 7);
    arg0->unknown_12c0_->unknown_a0_.inline_ov003_0216da90_2(0x1f - var0, 1);
#endif

    char var1[0x100];
    char var2[0x40];
    __clear(var1, 0x100);
    __clear(var2, 0x40);
    if (arg0->unknown_10_ == 2)
        func_02041c08(var1, func_0205d794((Struct_0205c570*)arg0->unknown_12c0_), 8, 5, 5, 5);
    func_02042058(var1, func_020e0434((Struct_0201099c_3*)arg0->unknown_1324_, 0x5c));
#if defined(jpn)
    func_0205d304(arg0->unknown_12c0_, var1, 0, 0, 0, 1, 0);
#else
    func_0205d304(arg0->unknown_12c0_, var1, 0, 0, 0, 1, 0, 0);
#endif

#if !defined(jpn)
    Struct_ov003_0216da90_4* var3 = func_0205d81c((Struct_0205d81c*)arg0->unknown_12c0_, 0);
    if (var3)
        var3->unknown_a8_.inline_ov003_0216da90_2(0x1f - var3->unknown_a8_.unknown_0_, var3->unknown_a8_.unknown_6_);
#endif

    Window0216da90* window = self->window;
    window->tableA.field4 = 1;
    window->tableB.field4 = 1;
    GridCursor_SetDimensions((Struct_0205ba68*)&window->tableA, 1, 4, 0);
    GridCursor_SetDimensions((Struct_0205ba68*)&window->tableB, 1, 4, 0);
    GridCursor_SetCount((Node0205bacc*)&window->tableA, 4);
    GridCursor_SetCount((Node0205bacc*)&window->tableB, 4);
    window->activeA = 1;
    window->activeB = 1;
}
