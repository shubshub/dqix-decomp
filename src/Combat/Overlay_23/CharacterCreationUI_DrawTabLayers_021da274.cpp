#include "Resource/CreationEnums.h"
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
void Background_ClearMap(Obj0204b010*, void*);
void Background_DrawScreen(Obj0204b8d0*, unsigned int, int, int, short, short, short, short, unsigned short);
extern "C" void Background_FlushMap(void*, void*);
extern "C" void func_0204b9b8(PaletteWindow*, int, int, int, int, unsigned int);

// Overlay 23, originally func_ov023_021da274 (USA/EUR 0x021da274, JPN 0x021daa30)
extern "C" ARM void CharacterCreationUI_DrawTabLayers(CharacterCreationUI* editor) {
    if (editor->flags & CreationFlag_RedrawTabHighlight) {
        Background_ClearMap((Obj0204b010*)&editor->layers[1], NULL);
        int page = editor->state;
        if (page >= 1 && page <= 8) {
            short row = (short)((page - 1) * 2);
            short bottom = row + 5;
            Background_DrawScreen((Obj0204b8d0*)&editor->layers[1], 0, 0, row, 15, bottom, 10, 2, 0xffff);
        }
        Background_FlushMap(&editor->layers[1], NULL);
    }
    if (editor->flags & CreationFlag_RedrawPanel) {
        Background_ClearMap((Obj0204b010*)&editor->layers[4], NULL);
        int page = editor->state;
        if (page == 1) {
            unsigned int id = 0;
            short x, y;
            if (editor->sex == CreationMale) {
                x = 7;
                y = 5;
            } else if (editor->sex == CreationFemale) {
                id = 1;
                x = 7;
                y = 11;
            }
            Background_DrawScreen((Obj0204b8d0*)&editor->layers[4], id, 0, 0, x, y, 18, 6, 0xffff);
        } else if (page == 2) {
            unsigned int slot = ((unsigned char*)((int)editor + (int)offsetof(CharacterCreationUI, bodyType)))[editor->sex];
            Background_DrawScreen((Obj0204b8d0*)&editor->layers[4], slot, 0, 0, (short)(slot * 5 + 4), 5, 4, 9, 0xffff);
        } else if (page == 5) {
            Background_DrawScreen((Obj0204b8d0*)&editor->layers[4], 0, 0, 0, 4, 5, 24, 9, 0xffff);
            int value = ((unsigned char*)((int)editor + (int)offsetof(CharacterCreationUI, faceStyle)))[editor->sex];
            func_0204b9b8((PaletteWindow*)&editor->layers[4], (short)(value % 5 * 5 + 4), (short)((value / 5 + 1) * 5), 4, 4, 2);
        } else if (page == 3) {
            Background_DrawScreen((Obj0204b8d0*)&editor->layers[4], 0, 0, 0, 4, 5, 24, 9, 0xffff);
            CreationSex sex = (CreationSex)editor->sex;
            int value = ((unsigned char*)((int)editor + (int)offsetof(CharacterCreationUI, hairStyle)))[sex];
            func_0204b9b8((PaletteWindow*)&editor->layers[4], (short)(value % 5 * 5 + 4), (short)((value / 5 + 1) * 5), 4, 4, 2);
        } else if (page == 8) {
            if (editor->flags & CreationFlag_NameRejected) {
                Background_DrawScreen((Obj0204b8d0*)&editor->layers[4], 3, 0, 0, 0, 14, 32, 10, 0xffff);
            } else {
                if (editor->previousKeyboardPage != editor->keyboardPage) {
                    Background_DrawScreen((Obj0204b8d0*)&editor->layers[3], (unsigned char)editor->keyboardPage, 0, 0, 0, 0, 32, 24, 0xffff);
                }
                editor->previousKeyboardPage = editor->keyboardPage;
                func_0204b9b8((PaletteWindow*)&editor->layers[3], 2, 7, 28, 12, 1);
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
                            func_0204b9b8((PaletteWindow*)&editor->layers[3], x, y, width, 2, 0);
                        }
                    } else {
                        func_0204b9b8((PaletteWindow*)&editor->layers[3], x, y, 2, 2, 0);
                    }
                }
            }
            Background_FlushMap(&editor->layers[3], NULL);
        } else if (page == 9) {
            unsigned int id = 0;
            if (editor->mode == CreationMode_NewGame) id = 1;
            Background_DrawScreen((Obj0204b8d0*)&editor->layers[4], id, 0, 0, 0, 14, 32, 10, 0xffff);
            Background_DrawScreen((Obj0204b8d0*)&editor->layers[4], 2, 0, 0, 24, 9, 8, 7, 0xffff);
            func_0204b9b8((PaletteWindow*)&editor->layers[3], 2, 7, 28, 12, 1);
            Background_FlushMap(&editor->layers[3], NULL);
        }
        Background_FlushMap(&editor->layers[4], NULL);
    }
}
#else
#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_0204b010;
struct Struct_0204b8d0;
struct Struct_02000c9c_8;
struct Struct_0204b9b8;

void Background_ClearMap(struct Obj0204b010*, void*);
unsigned char NormalizeField5_0200fb08(struct Struct0200fb08*);
void Background_DrawScreen(struct Obj0204b8d0*, unsigned int, int, int, short, short, short, short, unsigned short);
extern "C" void Background_FlushMap(void* obj, void* p);
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

// USA: CharacterCreationUI_DrawTabLayers
extern "C" ARM void CharacterCreationUI_DrawTabLayers(Self021da274* self) {
    if (self->flags & CreationFlag_RedrawTabHighlight) {
        Background_ClearMap((struct Obj0204b010*)&self->win158, NULL);
        int page = self->page;
        if (page >= 1 && page <= 8) {
            int row = (short)((page - 1) * 2 + 1);
            short col = 0xf;
            short row2 = row + 5;
            short col2 = 0xa;
            if (NormalizeField5_0200fb08((struct Struct0200fb08*)GameState::GetInstance()) == 4) {
                col = 0xe;
                col2 = 0xd;
            }
            Background_DrawScreen(WIN(self->win158), 0, 0, row, col, row2, col2, 2, 0xffff);
        }
        Background_FlushMap(&self->win158, NULL);
    }

    if (self->flags & CreationFlag_RedrawPanel) {
        Background_ClearMap((struct Obj0204b010*)&self->win1b8, NULL);
        int page = self->page;
        if (page == 1) {
            unsigned int id = 0;
            short x;
            short y;
            if (self->sel == 0) {
                x = 7;
                y = 5;
            } else if (self->sel == 1) {
                id = 1;
                x = 7;
                y = 0xb;
            }
            Background_DrawScreen(WIN(self->win1b8), id, 0, 0, x, y, 0x12, 6, 0xffff);
        } else if (page == 2) {
            unsigned int slot = ((unsigned char*)((int)self + 0xda4))[self->sel];
            Background_DrawScreen(WIN(self->win1b8), slot, 0, 0, (short)(slot * 5 + 4), 5, 4, 9, 0xffff);
        } else if (page == 5) {
            Background_DrawScreen(WIN(self->win1b8), 0, 0, 0, 4, 5, 0x18, 9, 0xffff);
            int v = ((unsigned char*)((int)self + 0xda6))[self->sel];
            func_0204b9b8((PaletteWindow*)&self->win1b8, (short)(v % 5 * 5 + 4), (short)((v / 5 + 1) * 5), 4, 4, 2);
        } else if (page == 3) {
            Background_DrawScreen(WIN(self->win1b8), 0, 0, 0, 4, 5, 0x18, 9, 0xffff);
            int v = ((unsigned char*)((int)self + 0xdac))[self->sel];
            func_0204b9b8((PaletteWindow*)&self->win1b8, (short)(v % 5 * 5 + 4), (short)((v / 5 + 1) * 5), 4, 4, 2);
        } else if (page == 8) {
            int i;
            if (self->flags & CreationFlag_NameRejected) {
                Background_DrawScreen(WIN(self->win1b8), 3, 0, 0, 0, 0xe, 0x20, 0xa, 0xffff);
            } else {
                var30 = 0;
                unsigned char var31 = arg0->unknown_c0_->unknown_1e_;
                unsigned char var32 = arg0->unknown_c0_->unknown_20_;
                while (1) {
                    unsigned char bit = data_ov023_021fd532[i * 3];
                    if (bit == 0) break;
                    if (mask & bit) {
                        Background_DrawScreen(WIN(self->win198), (&data_ov023_021fd530[i * 3])[column], 0, 0, 0, 0, 0x20, 0x18, 0xffff);
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
            Background_FlushMap(&self->win198, NULL);
        } else if (page == 9) {
            unsigned int id = 0;
            if (self->hidden == 0) id = 1;
            Background_DrawScreen(WIN(self->win1b8), id, 0, 0, 0, 0xe, 0x20, 0xa, 0xffff);
            Background_DrawScreen(WIN(self->win1b8), 2, 0, 0, 0x18, 9, 8, 7, 0xffff);
            func_0204b9b8((PaletteWindow*)&self->win198, 2, 7, 0x1c, 0xc, 1);
            Background_FlushMap(&self->win198, NULL);
        }
        Background_FlushMap(&self->win1b8, NULL);
    }
}

#endif
