#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_0205cf1c;
struct Struct_0205ba68;
struct Struct_0205bacc;
struct Struct_0205bcdc {
    int unknown_0_; int unknown_4_; char unknown_8_[0x40 - 8];
    unsigned char unknown_40_; unsigned char unknown_41_; char unknown_42_[0x50 - 0x42];
};
struct Struct_0205c53c {
    int unknown_0_;
    Struct_0205bcdc unknown_4_;
    Struct_0205bcdc unknown_54_;
};
struct Struct_ov023_021e6e60 {
#if defined(jpn)
    char unknown_0_[0x90]; Struct_0205c53c unknown_ac_;
#else
    char unknown1_0_[0xac]; Struct_0205c53c unknown_ac_;
#endif

#if defined(jpn)
    char unknown_134_[0x1341 - 0x134]; unsigned char unknown_1371_;
#else
    char unknown_150_[0x1371 - 0x150]; unsigned char unknown_1371_;
#endif

#if defined(jpn)
    char unknown_1342_[0x1368 - 0x1342]; unsigned char unknown_13a0_;
#else
    char unknown_1372_[0x13a0 - 0x1372]; unsigned char unknown_13a0_;
#endif

#if defined(jpn)
    char unknown_1369_[0x141c - 0x1369];
#else
    char unknown_13a1_[0x13c4 - 0x13a1];
#endif

    unsigned short unknown_13c4_0_ : 5; unsigned short unknown_13c4_5_ : 11;
#if defined(jpn)
    char unknown_141e_[0x142c - 0x141e];
#else
    char unknown_13c6_[0x13d4 - 0x13c6];
#endif

    int unknown_13d4_; int unknown_13d8_; int unknown_13dc_; int unknown_13e0_; int unknown_13e4_;
    int unknown_13e8_; int unknown_13ec_; int unknown_13f0_; int unknown_13f4_; int unknown_13f8_;
};
void ClearChannelAFlag0205cf10(void*);
void ClearFlagByte0205cf1c(Struct0205cf1c*);
void InitChannelPair0205c53c(Struct_0205c53c*);
void GridCursor_SetDimensions(Struct_0205ba68*, int, int, int);
void GridCursor_SetCount(Node0205bacc*, int);
void SetIndexIfValid0205bcdc(Struct_0205bcdc*, int);
extern "C" void GridCursor_SetSelectedIndex(Struct_0205bcdc*, int);

// USA: func_ov023_021e6e60
extern "C" ARM void func_ov023_021e6e60(Struct_ov023_021e6e60* arg0) {
    GameState::GetInstance();
    int var0;
    int var1;
    int var2;
    int var3 = 0;
    unsigned int var4;
    int var5;
    switch (arg0->unknown_1371_) {
    case 1: var2 = 1; var4 = 6; var0 = 1; var1 = 6; var5 = arg0->unknown_13d4_; break;
    case 2: var2 = 1; var4 = 4; var0 = 1; var1 = 4; var5 = arg0->unknown_13d8_; break;
#if defined(jpn)
    case 3: var2 = 3; var0 = 2; var1 = 8; var4 = 47; var5 = arg0->unknown_13dc_; break;
#else
    case 3: var0 = 2; var1 = 8; var2 = 12; var4 = 192; var5 = arg0->unknown_13dc_; break;
#endif

    case 4: var2 = 1; var1 = 8; var0 = 1; var4 = 8; var5 = arg0->unknown_13e0_; break;
    case 5:
        var0 = 1; var4 = arg0->unknown_13c4_0_; var2 = ((int)var4 - 1) / 9 + 1;
        var1 = 9;
        if (var4 < 9) var1 = var4;
        var5 = arg0->unknown_13e4_; break;
    case 6: var2 = 1; var4 = 2; var0 = 1; var1 = 2; var5 = arg0->unknown_13f8_; break;
    case 10: var2 = 1; var4 = 2; var0 = 1; var1 = 2; var5 = arg0->unknown_13e8_; break;
    case 11: var2 = 6; var0 = 1; var1 = 10; var4 = 60; var5 = arg0->unknown_13ec_; break;
    case 12:
        var0 = 2; var3 = 1; var4 = arg0->unknown_13c4_5_;
        var2 = ((int)var4 - 1) / 16 + 1;
        var1 = ((int)var4 - 1) / 2 + 1;
        if (var1 > 8) var1 = 8;
        var5 = arg0->unknown_13f0_; break;
    case 13: var0 = 1; var1 = 8; var2 = 1; var4 = 8; var5 = arg0->unknown_13f4_; break;
    default:
        func_0205cf10(&arg0->unknown_ac_);
        func_0205cf1c((Struct_0205cf1c*)&arg0->unknown_ac_);
        return;
    }
    InitChannelPair0205c53c(&self->channels_);
    GridCursor_SetDimensions((Struct_0205ba68*)&self->channels_.selection_, columns, rows, wrap);
    GridCursor_SetDimensions((Struct_0205ba68*)&self->channels_.scrolling_, columns, rows, wrap);
    GridCursor_SetCount((Node0205bacc*)&self->channels_.selection_, count);
    GridCursor_SetCount((Node0205bacc*)&self->channels_.scrolling_, count);
    self->channels_.selection_.pages_ = pages;
    self->channels_.scrolling_.pages_ = pages;
    SetIndexIfValid0205bcdc(&self->channels_.selection_, selected);
    GridCursor_SetSelectedIndex(&self->channels_.scrolling_, selected);
    self->channels_.scrolling_.firstFlag_ = 1;
    self->channels_.scrolling_.secondFlag_ = 1;
    self->dirty_ = 0;
}
