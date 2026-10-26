#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct020dfc40;
struct Struct_ov003_02174114_4;
struct Struct_02081ee4;
struct Struct_02081ee4_2;
struct BackgroundGraphics;

struct Global020421a0 {
#if defined(jpn)
    char unk_0[0x28];
    int unknown_5c_;
    char unknown_2c_[0x868 - 0x2c];
#else
    char unk_0[0x5c];
    int unknown_5c_;
    char unknown_60_[0x998 - 0x60];
#endif
    int unknown_998_;
    int unknown_99c_;
};

struct Struct_ov003_02174114_2 {
    char unk_0[0x56b];
    unsigned char unknown_56b_0_ : 4;
    unsigned char unknown_56b_4_ : 4;
};

struct Struct_ov003_02174114_3 {
    int unk_0;
    int unknown_4_;
    int unknown_8_;
    char s0c_[0x24 - 0xc];
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
    char s7d8_[0x830 - 0x7d8];
    int unknown_830_;
    char unknown_834_[0x88c - 0x834];
    char unknown_88c_[0x898 - 0x88c];
    char unknown_898_[0x89c - 0x898];
    int unknown_89c_;
    char lists_[0x8e0 - 0x8a0];
    char slots_[0xfe0 - 0x8e0];
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
    int count_;
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

extern "C" Global020421a0 *MessageSystem_GetInstance(void);
#if defined(jpn)
extern "C" void func_0204500c(Global020421a0 *, int, int);
#else
extern "C" void func_0204500c(Global020421a0 *, int, int, int);
#endif
extern "C" void KeyTable_Reset(Struct020dfc40 *);
extern "C" void func_02074af4(void *);
extern "C" void func_ov023_021dc134(void *, int, int);
extern "C" void SpriteContext_Init(char *);
extern "C" void func_ov003_02174408(Struct_ov003_02174114_4 *);
extern "C" void func_02081ee4(Struct_02081ee4 *, Struct_02081ee4_2 *);
extern "C" void Background_Init(BackgroundGraphics *);
extern "C" void WindowPane_Init(void *);
extern "C" unsigned char GameState_GetOwnPartyOrder(char *, void *);
extern "C" GameObject *func_0200ff1c(GameState *, int);

#if defined(jpn)
#define FIGHTER_OFF_02174114 0x144
#else
#define FIGHTER_OFF_02174114 0x150
#endif

// USA: func_ov003_02174114
extern "C" ARM void func_ov003_02174114(Struct_ov003_02174114_3 *self) {
    Global020421a0 *g = MessageSystem_GetInstance();
    int p             = g->unknown_5c_;
    self->unknown_ff0_       = g->unknown_99c_;
#if defined(jpn)
    func_0204500c(g, p, 0);
#else
    func_0204500c(g, p, 0, 0xe3);
#endif
    g->unknown_998_ = 1;
    g->unknown_99c_ = self->unknown_ff0_;

    self->unknown_4_ = 0;
    self->unknown_8_ = 0;
    KeyTable_Reset((Struct020dfc40 *) (self->s0c_));
    self->unknown_34_ = 0;
    self->unknown_35_ = 0;
    func_02074af4(self->unknown_24_);
    volatile unsigned int *reg = (volatile unsigned int *) 0x4000000;
    unsigned int v             = *reg;
    self->unknown_38_             = (v & 0x1f00u) >> 8;
    v                          = *reg;
    *reg                       = (v & ~0x1f00u) | 0x100u;
    func_ov023_021dc134((char *) self + 0x3c, -1, 0);
    SpriteContext_Init(self->s7d8_);
    self->unknown_830_ = 0;
    func_ov003_02174408((Struct_ov003_02174114_4 *) self->unknown_834_);
    func_02081ee4((Struct_02081ee4 *) self->unknown_88c_, (Struct_02081ee4_2 *) self->unknown_898_);
    self->unknown_89c_ = 0;
    for (int i = 0; i < 2; i++)
        Background_Init((BackgroundGraphics *) (self->lists_ + i * 32));
    for (int j = 0; j < 8; j++)
        WindowPane_Init(self->slots_ + j * 0xe0);

    self->unknown_fe0_     = 0;
    self->unknown_fe4_     = 0;
    self->unknown_fe8_     = 0;
#if defined(jpn)
    self->unknown_fec_     = 0;
#else
    self->unknown_fec_     = -1;
#endif
    self->unknown_ff4_     = 0;
    self->unknown_ff8_     = 0;
    self->unknown_ffc_     = -1;
    self->unknown_ffe_     = -1;
    self->unknown_1000_[0] = -1;
    self->unknown_1000_[1] = -1;
    self->unknown_1000_[2] = -1;
    self->unknown_1000_[3] = -1;
    self->unknown_1000_[4] = -1;
    self->unknown_1000_[5] = -1;
    self->unknown_1000_[6] = -1;
    self->unknown_1000_[7] = -1;
    self->unknown_1000_[8] = -1;
    self->unknown_1000_[9] = -1;
    self->unknown_1014_    = 0;
    self->unknown_1016_    = 0;
    self->unknown_1018_    = 0;
    for (int k = 0; k < 5; k++)
        self->unknown_101c_[k] = -1;
    self->count_    = 0;
    self->unknown_1034_[0] = -1;
    self->unknown_1034_[1] = -1;
    self->unknown_1034_[2] = -1;
    self->unknown_1034_[3] = -1;
    self->unknown_103c_    = 1;
    self->unknown_103d_    = 0;
    self->unknown_103e_    = 0;
    self->unknown_103f_    = 0;
    self->unknown_1040_    = 0;
    self->unknown_1041_    = 0;
    self->unknown_1042_    = 0;
    self->unknown_1043_    = -1;
    self->unknown_1044_    = -1;
    self->unknown_1046_    = 0;
    self->unknown_1048_    = -1;
    self->unknown_104c_    = 0;
    self->unknown_104b_    = 0;
    self->unknown_104e_    = 0;
    self->unknown_104f_    = 0;

    GameState *gs = GameState::GetInstance();
    unsigned char buf[8];
    int n = GameState_GetOwnPartyOrder((char *) gs, buf);
    for (int m = 0; m < n; m++)
        self->unknown_101c_[m] = buf[m];
    self->count_ = n;

    int r = 0;
    while (r < self->count_) {
        GameObject *c = func_0200ff1c(gs, self->unknown_101c_[r]);
        if (c) {
            Struct_ov003_02174114_2 *f = *(Struct_ov003_02174114_2 **) ((char *) c + FIGHTER_OFF_02174114);
            bool var14         = f ? (f->unknown_56b_0_ != 0) : false;
            if (var14) {
                int s = r;
                while (s < self->count_) {
                    self->unknown_101c_[s] = self->unknown_101c_[s + 1];
                    s++;
                    self->unknown_101c_[s] = -1;
                }
                self->count_--;
            }
        }
        r++;
    }
}
