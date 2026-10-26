#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_0205cf1c;
struct GridCursor;
struct Struct_0205bcdc {
    int count_; int pages_; char pad8[0x40 - 8];
    unsigned char unknown_40_; unsigned char unknown_41_; char unknown_42_[0x50 - 0x42];
};
struct Struct_0205c53c {
    int unknown_0_;
    Struct_0205bcdc selection_;
    Struct_0205bcdc scrolling_;
};
struct Struct_ov023_021e6e60 {
#if defined(jpn)
    char pad0[0x90]; Struct_0205c53c channels_;
#else
    char pad0[0xac]; Struct_0205c53c channels_;
#endif

#if defined(jpn)
    char unknown_134_[0x1341 - 0x134]; unsigned char mode_;
#else
    char unknown_150_[0x1371 - 0x150]; unsigned char mode_;
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
extern "C" void func_0205cf10(void*);
extern "C" void func_0205cf1c(Struct_0205cf1c*);
extern "C" void func_0205c53c(Struct_0205c53c*);
extern "C" void GridCursor_SetDimensions(GridCursor*, int, int, int);
extern "C" void GridCursor_SetCount(GridCursor*, int);
extern "C" void GridCursor_SelectIfValid(Struct_0205bcdc*, int);
extern "C" void GridCursor_SetSelectedIndex(Struct_0205bcdc*, int);

// USA: func_ov023_021e6e60
extern "C" ARM void func_ov023_021e6e60(Struct_ov023_021e6e60* self) {
    GameState::GetInstance();
    int columns;
    int rows;
    int pages;
    int wrap = 0;
    unsigned int count;
    int selected;
    switch (self->mode_) {
    case 1: pages = 1; count = 6; columns = 1; rows = 6; selected = self->unknown_13d4_; break;
    case 2: pages = 1; count = 4; columns = 1; rows = 4; selected = self->unknown_13d8_; break;
#if defined(jpn)
    case 3: pages = 3; columns = 2; rows = 8; count = 47; selected = self->unknown_13dc_; break;
#else
    case 3: columns = 2; rows = 8; pages = 12; count = 192; selected = self->unknown_13dc_; break;
#endif

    case 4: pages = 1; rows = 8; columns = 1; count = 8; selected = self->unknown_13e0_; break;
    case 5:
        columns = 1; count = self->unknown_13c4_0_; pages = ((int)count - 1) / 9 + 1;
        rows = 9;
        if (count < 9) rows = count;
        selected = self->unknown_13e4_; break;
    case 6: pages = 1; count = 2; columns = 1; rows = 2; selected = self->unknown_13f8_; break;
    case 10: pages = 1; count = 2; columns = 1; rows = 2; selected = self->unknown_13e8_; break;
    case 11: pages = 6; columns = 1; rows = 10; count = 60; selected = self->unknown_13ec_; break;
    case 12:
        columns = 2; wrap = 1; count = self->unknown_13c4_5_;
        pages = ((int)count - 1) / 16 + 1;
        rows = ((int)count - 1) / 2 + 1;
        if (rows > 8) rows = 8;
        selected = self->unknown_13f0_; break;
    case 13: columns = 1; rows = 8; pages = 1; count = 8; selected = self->unknown_13f4_; break;
    default:
        func_0205cf10(&self->channels_);
        func_0205cf1c((Struct_0205cf1c*)&self->channels_);
        return;
    }
    func_0205c53c(&self->channels_);
    GridCursor_SetDimensions((GridCursor*)&self->channels_.selection_, columns, rows, wrap);
    GridCursor_SetDimensions((GridCursor*)&self->channels_.scrolling_, columns, rows, wrap);
    GridCursor_SetCount((GridCursor*)&self->channels_.selection_, count);
    GridCursor_SetCount((GridCursor*)&self->channels_.scrolling_, count);
    self->channels_.selection_.pages_ = pages;
    self->channels_.scrolling_.pages_ = pages;
    GridCursor_SelectIfValid(&self->channels_.selection_, selected);
    GridCursor_SetSelectedIndex(&self->channels_.scrolling_, selected);
    self->channels_.scrolling_.unknown_40_ = 1;
    self->channels_.scrolling_.unknown_41_ = 1;
    self->unknown_13a0_ = 0;
}
