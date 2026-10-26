#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct020dfc40;
struct InitStruct02174408;
struct Obj02081ee4;
struct Sub02081ee4;
struct BackgroundGraphics;

struct Struct_ov003_02174114 {
#if defined(jpn)
    char unknown_0_[0x28];
    int unknown_5c_;
    char unknown_2c_[0x868 - 0x2c];
#else
    char unknown1_0_[0x5c];
    int unknown_5c_;
    char unknown_60_[0x998 - 0x60];
#endif
    int unknown_998_;
    int unknown_99c_;
};

struct Struct_ov003_02174114_2 {
    char unknown_0_[0x56b];
    unsigned char unknown_56b_0_ : 4;
    unsigned char unknown_56b_4_ : 4;
};

struct Struct_ov003_02174114_3 {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
    char unknown_c_[0x24 - 0xc];
    char unknown_24_[0x34 - 0x24];
    unsigned char unknown_34_;
    unsigned char unknown_35_;
    char unknown_36_[2];
    int unknown_38_;
#if defined(jpn)
    char unknown_3c_[0x7d8 - 0x3c - 0x84];
#else
    char unknown1_3c_[0x7d8 - 0x3c];
#endif
    char unknown_7d8_[0x830 - 0x7d8];
    int unknown_830_;
    char unknown_834_[0x88c - 0x834];
    char unknown_88c_[0x898 - 0x88c];
    char unknown_898_[0x89c - 0x898];
    int unknown_89c_;
    char unknown_8a0_[0x8e0 - 0x8a0];
    char unknown_8e0_[0xfe0 - 0x8e0];
    int unknown_fe0_;
    int unknown_fe4_;
    int unknown_fe8_;
    int unknown_fec_;
    int unknown_ff0_;
    int unknown_ff4_;
    int unknown_ff8_;
    short unknown_ffc_;
    short unknown_ffe_;
    short unknown_1000_[10];
    short unknown_1014_;
    short unknown_1016_;
    int unknown_1018_;
    int unknown_101c_[5];
    int unknown_1030_;
    short unknown_1034_[4];
    unsigned char unknown_103c_;
    unsigned char unknown_103d_;
    unsigned char unknown_103e_;
    unsigned char unknown_103f_;
    unsigned char unknown_1040_;
    unsigned char unknown_1041_;
    unsigned char unknown_1042_;
    signed char unknown_1043_;
    signed char unknown_1044_;
    char unknown_1045_;
    short unknown_1046_;
    short unknown_1048_;
    char unknown_104a_;
    unsigned char unknown_104b_;
    unsigned char unknown_104c_;
    char unknown_104d_;
    unsigned char unknown_104e_;
    unsigned char unknown_104f_;
};

Global020421a0 *MessageSystem_GetInstance(void);
#if defined(jpn)
extern "C" void func_0204500c(Struct_ov003_02174114 *, int, int);
#else
extern "C" void func_0204500c(Struct_ov003_02174114 *, int, int, int);
#endif
void KeyTable_Reset(Struct020dfc40 *);
extern "C" void func_02074af4(void *);
extern "C" void func_ov023_021dc134(void *, int, int);
void SpriteContext_Init(char *);
void InitObj02174408(InitStruct02174408 *);
void InitWithSub02081ee4(Obj02081ee4 *, Sub02081ee4 *);
void Background_Init(BackgroundGraphics *);
extern "C" void WindowPane_Init(void *);
unsigned char GameState_GetOwnPartyOrder(char *, void *);
GameObject *GetCombatantWithFlag0x100_0200ff1c(GameState *, int);

#if defined(jpn)
#define FIGHTER_OFF_02174114 0x144
#else
#define FIGHTER_OFF_02174114 0x150
#endif

// USA: func_ov003_02174114
extern "C" ARM void func_ov003_02174114(Battle02174114 *self) {
    Global020421a0 *g = MessageSystem_GetInstance();
    int p             = g->p5c_;
    self->fff0_       = g->f99c_;
#if defined(jpn)
    func_0204500c(var0, var1, 0);
#else
    func_0204500c(var0, var1, 0, 0xe3);
#endif
    var0->unknown_998_ = 1;
    var0->unknown_99c_ = arg0->unknown_ff0_;

    self->f4_ = 0;
    self->f8_ = 0;
    KeyTable_Reset((Struct020dfc40 *) (self->s0c_));
    self->b34_ = 0;
    self->b35_ = 0;
    func_02074af4(self->s24_);
    volatile unsigned int *reg = (volatile unsigned int *) 0x4000000;
    unsigned int v             = *reg;
    self->dispcnt_             = (v & 0x1f00u) >> 8;
    v                          = *reg;
    *reg                       = (v & ~0x1f00u) | 0x100u;
    func_ov023_021dc134((char *) self + 0x3c, -1, 0);
    SpriteContext_Init(self->s7d8_);
    self->f830_ = 0;
    InitObj02174408((InitStruct02174408 *) self->s834_);
    InitWithSub02081ee4((Obj02081ee4 *) self->s88c_, (Sub02081ee4 *) self->s898_);
    self->f89c_ = 0;
    for (int i = 0; i < 2; i++)
        Background_Init((BackgroundGraphics *) (self->lists_ + i * 32));
    for (int j = 0; j < 8; j++)
        WindowPane_Init(self->slots_ + j * 0xe0);

    arg0->unknown_fe0_     = 0;
    arg0->unknown_fe4_     = 0;
    arg0->unknown_fe8_     = 0;
#if defined(jpn)
    arg0->unknown_fec_     = 0;
#else
    arg0->unknown_fec_     = -1;
#endif
    arg0->unknown_ff4_     = 0;
    arg0->unknown_ff8_     = 0;
    arg0->unknown_ffc_     = -1;
    arg0->unknown_ffe_     = -1;
    arg0->unknown_1000_[0] = -1;
    arg0->unknown_1000_[1] = -1;
    arg0->unknown_1000_[2] = -1;
    arg0->unknown_1000_[3] = -1;
    arg0->unknown_1000_[4] = -1;
    arg0->unknown_1000_[5] = -1;
    arg0->unknown_1000_[6] = -1;
    arg0->unknown_1000_[7] = -1;
    arg0->unknown_1000_[8] = -1;
    arg0->unknown_1000_[9] = -1;
    arg0->unknown_1014_    = 0;
    arg0->unknown_1016_    = 0;
    arg0->unknown_1018_    = 0;
    for (int var6 = 0; var6 < 5; var6++)
        arg0->unknown_101c_[var6] = -1;
    arg0->unknown_1030_    = 0;
    arg0->unknown_1034_[0] = -1;
    arg0->unknown_1034_[1] = -1;
    arg0->unknown_1034_[2] = -1;
    arg0->unknown_1034_[3] = -1;
    arg0->unknown_103c_    = 1;
    arg0->unknown_103d_    = 0;
    arg0->unknown_103e_    = 0;
    arg0->unknown_103f_    = 0;
    arg0->unknown_1040_    = 0;
    arg0->unknown_1041_    = 0;
    arg0->unknown_1042_    = 0;
    arg0->unknown_1043_    = -1;
    arg0->unknown_1044_    = -1;
    arg0->unknown_1046_    = 0;
    arg0->unknown_1048_    = -1;
    arg0->unknown_104c_    = 0;
    arg0->unknown_104b_    = 0;
    arg0->unknown_104e_    = 0;
    arg0->unknown_104f_    = 0;

    GameState *gs = GameState::GetInstance();
    unsigned char buf[8];
    int n = GameState_GetOwnPartyOrder((char *) gs, buf);
    for (int m = 0; m < n; m++)
        self->ids_[m] = buf[m];
    self->count_ = n;

    int var11 = 0;
    while (var11 < arg0->unknown_1030_) {
        GameObject *var12 = func_0200ff1c(var7, arg0->unknown_101c_[var11]);
        if (var12) {
            Struct_ov003_02174114_2 *var13 = *(Struct_ov003_02174114_2 **) ((char *) var12 + FIGHTER_OFF_02174114);
            bool var14         = var13 ? (var13->unknown_56b_0_ != 0) : false;
            if (var14) {
                int var15 = var11;
                while (var15 < arg0->unknown_1030_) {
                    arg0->unknown_101c_[var15] = arg0->unknown_101c_[var15 + 1];
                    var15++;
                    arg0->unknown_101c_[var15] = -1;
                }
                arg0->unknown_1030_--;
            }
        }
        var11++;
    }
}
