#if defined(jpn)
#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"
#include <std_library_functions.h>

struct Struct_0204b010;
struct Struct_0204b8d0;
struct Struct_0204b9b8;
enum Enum_ov023_021da274 {
    Enum_ov023_021da274_0 = 0,
    Enum_ov023_021da274_1 = 1,
    Enum_ov023_021da274_255 = 0xff
};
extern "C" void func_0204b010(Struct_0204b010*, void*);
extern "C" void func_0204b8d0(Struct_0204b8d0*, unsigned int, int, int, short, short, short, short, unsigned short);
extern "C" void func_0204b04c(void*, void*);
extern "C" void func_0204b9b8(Struct_0204b9b8*, int, int, int, int, unsigned int);

extern "C" ARM void func_ov023_021da274(Struct_ov009_021842a0* arg0) {
    if (arg0->unknown_d9c_ & 0x1000) {
        func_0204b010((Struct_0204b010*)&arg0->unknown_158_[0], NULL);
        int var0 = arg0->unknown_c58_;
        if (var0 >= 1 && var0 <= 8) {
            short var1 = (short)((var0 - 1) * 2);
            short var2 = var1 + 5;
            func_0204b8d0((Struct_0204b8d0*)&arg0->unknown_158_[0], 0, 0, var1, 15, var2, 10, 2, 0xffff);
        }
        func_0204b04c(&arg0->unknown_158_[0], NULL);
    }
    if (arg0->unknown_d9c_ & 0x2000) {
        func_0204b010((Struct_0204b010*)&arg0->unknown_158_[3], NULL);
        int var3 = arg0->unknown_c58_;
        if (var3 == 1) {
            unsigned int var4 = 0;
            short var5, var6;
            if (arg0->unknown_da3_ == Enum_ov023_021da274_0) {
                var5 = 7;
                var6 = 5;
            } else if (arg0->unknown_da3_ == Enum_ov023_021da274_1) {
                var4 = 1;
                var5 = 7;
                var6 = 11;
            }
            func_0204b8d0((Struct_0204b8d0*)&arg0->unknown_158_[3], var4, 0, 0, var5, var6, 18, 6, 0xffff);
        } else if (var3 == 2) {
            unsigned int var7 = ((unsigned char*)((int)arg0 + (int)offsetof(Struct_ov009_021842a0, unknown_da4_)))[arg0->unknown_da3_];
            func_0204b8d0((Struct_0204b8d0*)&arg0->unknown_158_[3], var7, 0, 0, (short)(var7 * 5 + 4), 5, 4, 9, 0xffff);
        } else if (var3 == 5) {
            func_0204b8d0((Struct_0204b8d0*)&arg0->unknown_158_[3], 0, 0, 0, 4, 5, 24, 9, 0xffff);
            int var8 = ((unsigned char*)((int)arg0 + (int)offsetof(Struct_ov009_021842a0, unknown_da6_)))[arg0->unknown_da3_];
            func_0204b9b8((Struct_0204b9b8*)&arg0->unknown_158_[3], (short)(var8 % 5 * 5 + 4), (short)((var8 / 5 + 1) * 5), 4, 4, 2);
        } else if (var3 == 3) {
            func_0204b8d0((Struct_0204b8d0*)&arg0->unknown_158_[3], 0, 0, 0, 4, 5, 24, 9, 0xffff);
            Enum_ov023_021da274 var9 = (Enum_ov023_021da274)arg0->unknown_da3_;
            int var10 = ((unsigned char*)((int)arg0 + (int)offsetof(Struct_ov009_021842a0, unknown_dac_)))[var9];
            func_0204b9b8((Struct_0204b9b8*)&arg0->unknown_158_[3], (short)(var10 % 5 * 5 + 4), (short)((var10 / 5 + 1) * 5), 4, 4, 2);
        } else if (var3 == 8) {
            if (arg0->unknown_d9c_ & 0x400000) {
                func_0204b8d0((Struct_0204b8d0*)&arg0->unknown_158_[3], 3, 0, 0, 0, 14, 32, 10, 0xffff);
            } else {
                if (arg0->unknown_d8e_ != arg0->unknown_d8d_) {
                    func_0204b8d0((Struct_0204b8d0*)&arg0->unknown_158_[2], (unsigned char)arg0->unknown_d8d_, 0, 0, 0, 0, 32, 24, 0xffff);
                }
                editor->previousKeyboardPage = editor->keyboardPage;
                func_0204b9b8((PaletteWindow*)&editor->tileMaps[2], 2, 7, 28, 12, 1);
                if (editor->navigation.rows != 1) {
                    short row = editor->keyboardChoice / 11;
                    short column = editor->keyboardChoice % 11;
                    short x = column * 2 + 3;
                    if (column >= 5) x += 1;
                    if (column == 10) x += 2;
                    short y = row * 2 + 7;
                    if (column == 10) {
                        bool highlight = true;
                        if (editor->mode == CreationMode_NewGame && row == 4) highlight = false;
                        if (highlight) {
                            int width = 3;
                            if (row == 5) width = 4;
                            func_0204b9b8((PaletteWindow*)&editor->tileMaps[2], x, y, width, 2, 0);
                        }
                    } else {
                        func_0204b9b8((Struct_0204b9b8*)&arg0->unknown_158_[2], var13, var14, 2, 2, 0);
                    }
                }
            }
            func_0204b04c(&editor->tileMaps[2], NULL);
        } else if (page == 9) {
            unsigned int id = 0;
            if (editor->mode == CreationMode_NewGame) id = 1;
            DispatchEntry0204b8d0((Obj0204b8d0*)&editor->tileMaps[3], id, 0, 0, 0, 14, 32, 10, 0xffff);
            DispatchEntry0204b8d0((Obj0204b8d0*)&editor->tileMaps[3], 2, 0, 0, 24, 9, 8, 7, 0xffff);
            func_0204b9b8((PaletteWindow*)&editor->tileMaps[2], 2, 7, 28, 12, 1);
            func_0204b04c(&editor->tileMaps[2], NULL);
        }
        func_0204b04c(&arg0->unknown_158_[3], NULL);
    }
}
#else
#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_0204b010;
struct Struct_0204b8d0;
struct Struct_02000c9c_8;
struct Struct_0204b9b8;

void ClearBuffer0204b010(struct Obj0204b010*, void*);
unsigned char NormalizeField5_0200fb08(struct Struct0200fb08*);
void DispatchEntry0204b8d0(struct Obj0204b8d0*, unsigned int, int, int, short, short, short, short, unsigned short);
extern "C" void func_0204b04c(void* obj, void* p);
extern "C" void func_0204b9b8(PaletteWindow* obj, int x, int y, int width, int height, unsigned palette);
extern "C" void Keyboard_GetKeySize(int id, short* w, short* h);

extern const unsigned char data_ov023_021fd530[];
extern unsigned char data_ov023_021fd532[];

struct Struct_ov023_021da274 {
    short unknown_0_;
    short unknown_2_;
    char unknown_4_[0xe - 4];
    unsigned char unknown_e_;
};

struct Struct_ov023_021da274_2 {
    Struct_ov023_021da274* unknown_0_;
    char unknown_4_[0x1e - 4];
    unsigned char unknown_1e_;
    char unknown_1f_;
    unsigned char unknown_20_;
};

struct Struct_02000c9c_65 {
    char unknown_0_[0x20];
};

struct Struct_ov023_021da274_3 {
    char unknown_0_[0xc0];
    Struct_ov023_021da274_2* unknown_c0_;
    char unknown_c4_[0x158 - 0xc4];
    Struct_02000c9c_65 unknown_158_;
    char unknown_178_[0x198 - 0x178];
    Struct_02000c9c_65 unknown_198_;
    Struct_02000c9c_65 unknown_1b8_;
    char unknown_1d8_[0xc58 - 0x1d8];
    signed char unknown_c58_;
    char unknown_c59_[0xd95 - 0xc59];
    unsigned char unknown_d95_;
    char unknown_d96_[0xd9c - 0xd96];
    unsigned int unknown_d9c_;
    char unknown_da0_[3];
    unsigned char unknown_da3_;
    unsigned char unknown_da4_[2];
    unsigned char unknown_da6_[6];
    unsigned char unknown_dac_[8];
};

#define WIN(w) ((struct Struct_0204b8d0*)&(w))

// USA: func_ov023_021da274
extern "C" ARM void func_ov023_021da274(Struct_ov023_021da274_3* arg0) {
    if (arg0->unknown_d9c_ & 0x1000) {
        func_0204b010((struct Struct_0204b010*)&arg0->unknown_158_, NULL);
        int var18 = arg0->unknown_c58_;
        if (var18 >= 1 && var18 <= 8) {
            int var19 = (short)((var18 - 1) * 2 + 1);
            short var20 = 0xf;
            short var21 = var19 + 5;
            short var22 = 0xa;
            if (func_0200fb08((struct Struct_02000c9c_8*)GameState::GetInstance()) == 4) {
                var20 = 0xe;
                var22 = 0xd;
            }
            func_0204b8d0(WIN(arg0->unknown_158_), 0, 0, var19, var20, var21, var22, 2, 0xffff);
        }
        func_0204b04c(&arg0->unknown_158_, NULL);
    }

    if (arg0->unknown_d9c_ & 0x2000) {
        func_0204b010((struct Struct_0204b010*)&arg0->unknown_1b8_, NULL);
        int var23 = arg0->unknown_c58_;
        if (var23 == 1) {
            unsigned int var24 = 0;
            short var25;
            short var26;
            if (arg0->unknown_da3_ == 0) {
                var25 = 7;
                var26 = 5;
            } else if (arg0->unknown_da3_ == 1) {
                var24 = 1;
                var25 = 7;
                var26 = 0xb;
            }
            func_0204b8d0(WIN(arg0->unknown_1b8_), var24, 0, 0, var25, var26, 0x12, 6, 0xffff);
        } else if (var23 == 2) {
            unsigned int var27 = ((unsigned char*)((int)arg0 + 0xda4))[arg0->unknown_da3_];
            func_0204b8d0(WIN(arg0->unknown_1b8_), var27, 0, 0, (short)(var27 * 5 + 4), 5, 4, 9, 0xffff);
        } else if (var23 == 5) {
            func_0204b8d0(WIN(arg0->unknown_1b8_), 0, 0, 0, 4, 5, 0x18, 9, 0xffff);
            int var28 = ((unsigned char*)((int)arg0 + 0xda6))[arg0->unknown_da3_];
            func_0204b9b8((Struct_0204b9b8*)&arg0->unknown_1b8_, (short)(var28 % 5 * 5 + 4), (short)((var28 / 5 + 1) * 5), 4, 4, 2);
        } else if (var23 == 3) {
            func_0204b8d0(WIN(arg0->unknown_1b8_), 0, 0, 0, 4, 5, 0x18, 9, 0xffff);
            int var29 = ((unsigned char*)((int)arg0 + 0xdac))[arg0->unknown_da3_];
            func_0204b9b8((Struct_0204b9b8*)&arg0->unknown_1b8_, (short)(var29 % 5 * 5 + 4), (short)((var29 / 5 + 1) * 5), 4, 4, 2);
        } else if (var23 == 8) {
            int var30;
            if (arg0->unknown_d9c_ & 0x400000) {
                func_0204b8d0(WIN(arg0->unknown_1b8_), 3, 0, 0, 0, 0xe, 0x20, 0xa, 0xffff);
            } else {
                var30 = 0;
                unsigned char var31 = arg0->unknown_c0_->unknown_1e_;
                unsigned char var32 = arg0->unknown_c0_->unknown_20_;
                while (1) {
                    unsigned char var33 = data_ov023_021fd532[var30 * 3];
                    if (var33 == 0) break;
                    if (var31 & var33) {
                        func_0204b8d0(WIN(arg0->unknown_198_), (&data_ov023_021fd530[var30 * 3])[var32], 0, 0, 0, 0, 0x20, 0x18, 0xffff);
                        break;
                    }
                    var30++;
                }
                func_0204b9b8((PaletteWindow*)&self->win198, 2, 7, 0x1c, 0xc, 1);
                Marker021da274* marker = self->info->marker;
                if (marker != NULL) {
                    short x = marker->x;
                    short y = marker->y;
                    short h;
                    short w;
                    Keyboard_GetKeySize(marker->kind, &w, &h);
                    func_0204b9b8((PaletteWindow*)&self->win198, x >> 3, y >> 3, w >> 3, h >> 3, 0);
                }
            }
            func_0204b04c(&arg0->unknown_198_, NULL);
        } else if (var23 == 9) {
            unsigned int var39 = 0;
            if (arg0->unknown_d95_ == 0) var39 = 1;
            func_0204b8d0(WIN(arg0->unknown_1b8_), var39, 0, 0, 0, 0xe, 0x20, 0xa, 0xffff);
            func_0204b8d0(WIN(arg0->unknown_1b8_), 2, 0, 0, 0x18, 9, 8, 7, 0xffff);
            func_0204b9b8((Struct_0204b9b8*)&arg0->unknown_198_, 2, 7, 0x1c, 0xc, 1);
            func_0204b04c(&arg0->unknown_198_, NULL);
        }
        func_0204b04c(&arg0->unknown_1b8_, NULL);
    }
}

#endif
