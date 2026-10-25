#include "Resource/CreationEnums.h"

#if defined(jpn)
#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"
#include "Resource/Keyboard.h"
#include <std_library_functions.h>

struct BackgroundGraphics;
void Background_ClearMap(BackgroundGraphics*, void*);
void Background_DrawScreen(BackgroundGraphics*, unsigned int, int, int, short, short, short, short, unsigned short);
extern "C" void Background_FlushMap(void*, void*);
extern "C" void Background_SetRectPalette(BackgroundGraphics*, int, int, int, int, unsigned int);

// Overlay 23, originally func_ov023_021da274 (USA/EUR 0x021da274, JPN 0x021daa30)
extern "C" ARM void CharacterCreationUI_DrawTabLayers(CharacterCreationUI* editor) {
    if (editor->flags & CreationFlag_RedrawTabHighlight) {
        Background_ClearMap(&editor->layers[CreationLayer_TabHighlight], NULL);
        int tab = editor->state;
        if (tab >= CreationTab_Gender && tab <= CreationTab_NameEntry) {
            short row = (short)((tab - CreationTab_Gender) * 2);
            short bottom = row + 5;
            Background_DrawScreen(&editor->layers[CreationLayer_TabHighlight], 0, 0, row, 15, bottom, 10, 2, BackgroundPalette_Keep);
        }
        Background_FlushMap(&editor->layers[CreationLayer_TabHighlight], NULL);
    }
    if (editor->flags & CreationFlag_RedrawPanel) {
        Background_ClearMap(&editor->layers[CreationLayer_Selection], NULL);
        int tab = editor->state;
        if (tab == CreationTab_Gender) {
            unsigned int screen = 0;
            short x, y;
            if (editor->sex == CreationSex_Male) {
                x = 7;
                y = 5;
            } else if (editor->sex == CreationSex_Female) {
                screen = 1;
                x = 7;
                y = 11;
            }
            Background_DrawScreen(&editor->layers[CreationLayer_Selection], screen, 0, 0, x, y, 18, 6, BackgroundPalette_Keep);
        } else if (tab == CreationTab_BodyType) {
            unsigned int slot = ((unsigned char*)((int)editor + (int)offsetof(CharacterCreationUI, bodyType)))[editor->sex];
            Background_DrawScreen(&editor->layers[CreationLayer_Selection], slot, 0, 0, (short)(slot * 5 + 4), 5, 4, 9, BackgroundPalette_Keep);
        } else if (tab == CreationTab_Face) {
            Background_DrawScreen(&editor->layers[CreationLayer_Selection], 0, 0, 0, 4, 5, 24, 9, BackgroundPalette_Keep);
            int choice = ((unsigned char*)((int)editor + (int)offsetof(CharacterCreationUI, faceStyle)))[editor->sex];
            Background_SetRectPalette(&editor->layers[CreationLayer_Selection], (short)(choice % 5 * 5 + 4), (short)((choice / 5 + 1) * 5), 4, 4, 2);
        } else if (tab == CreationTab_HairStyle) {
            Background_DrawScreen(&editor->layers[CreationLayer_Selection], 0, 0, 0, 4, 5, 24, 9, BackgroundPalette_Keep);
            CreationSex sex = (CreationSex)editor->sex;
            int choice = ((unsigned char*)((int)editor + (int)offsetof(CharacterCreationUI, hairStyle)))[sex];
            Background_SetRectPalette(&editor->layers[CreationLayer_Selection], (short)(choice % 5 * 5 + 4), (short)((choice / 5 + 1) * 5), 4, 4, 2);
        } else if (tab == CreationTab_NameEntry) {
            if (editor->flags & CreationFlag_NameRejected) {
                Background_DrawScreen(&editor->layers[CreationLayer_Selection], 3, 0, 0, 0, 14, 32, 10, BackgroundPalette_Keep);
            } else {
                if (editor->previousKeyboardPage != editor->keyboardPage) {
                    Background_DrawScreen(&editor->layers[CreationLayer_Page], (unsigned char)editor->keyboardPage, 0, 0, 0, 0, 32, 24, BackgroundPalette_Keep);
                }
                editor->previousKeyboardPage = editor->keyboardPage;
                Background_SetRectPalette(&editor->layers[CreationLayer_Page], 2, 7, 28, 12, 1);
                if (editor->navigation.rows != 1) {
                    short row = editor->keyboardChoice / KeyboardGrid_Columns;
                    short column = editor->keyboardChoice % KeyboardGrid_Columns;
                    short x = column * 2 + 3;
                    if (column >= 5) x += 1;
                    if (column == KeyboardGrid_Columns - 1) x += 2;
                    short y = row * 2 + 7;
                    if (column == KeyboardGrid_Columns - 1) {
                        bool highlight = true;
                        if (editor->mode == CreationMode_NewGame && row == 4) highlight = false;
                        if (highlight) {
                            int width = 3;
                            if (row == KeyboardGrid_Rows - 1) width = 4;
                            Background_SetRectPalette(&editor->layers[CreationLayer_Page], x, y, width, 2, 0);
                        }
                    } else {
                        Background_SetRectPalette(&editor->layers[CreationLayer_Page], x, y, 2, 2, 0);
                    }
                }
            }
            Background_FlushMap(&editor->layers[CreationLayer_Page], NULL);
        } else if (tab == CreationTab_Confirm) {
            unsigned int screen = 0;
            if (editor->mode == CreationMode_NewGame) screen = 1;
            Background_DrawScreen(&editor->layers[CreationLayer_Selection], screen, 0, 0, 0, 14, 32, 10, BackgroundPalette_Keep);
            Background_DrawScreen(&editor->layers[CreationLayer_Selection], 2, 0, 0, 24, 9, 8, 7, BackgroundPalette_Keep);
            Background_SetRectPalette(&editor->layers[CreationLayer_Page], 2, 7, 28, 12, 1);
            Background_FlushMap(&editor->layers[CreationLayer_Page], NULL);
        }
        Background_FlushMap(&editor->layers[CreationLayer_Selection], NULL);
    }
}
#else
#include <globaldefs.h>
#include <std_library_functions.h>
#include "GameState/GameState.h"
#include "NitroSDK/OSLanguage.h"
#include "Resource/CharacterCreationUI.h"

struct Struct0200fb08;

void Background_ClearMap(struct BackgroundGraphics*, void*);
unsigned char GameState_GetLanguage(struct Struct0200fb08*);
void Background_DrawScreen(struct BackgroundGraphics*, unsigned int, int, int, short, short, short, short, unsigned short);
extern "C" void Background_FlushMap(void* obj, void* p);
extern "C" void Background_SetRectPalette(BackgroundGraphics* layer, int x, int y, int width, int height, unsigned palette);
extern "C" void Keyboard_GetKeySize(int id, short* w, short* h);

// The name tab's page screen for each keyboard page, 3 bytes each: the screen, the screen while shifted, then
// the KeyboardPage bits it is for (CharacterCreationUI_keyboardPageMasks); a 0 mask ends it. In the ROM: Lowercase 0 / 1,
// Uppercase 1 / 0, Accents 2 / 0, Symbols 3 / 0 (screens cm_name_small, _capital, _europe, _symbol).
extern const unsigned char CharacterCreationUI_keyboardPageScreens[];
extern unsigned char CharacterCreationUI_keyboardPageMasks[];

// One key, with CharacterCreationUI_HandleNameEntry's field names.
struct KeyboardKey {
    short x_;
    short y_;
    const char* text_;
    const char* shiftedText_;
    unsigned char pages_;
    unsigned char action_;
    unsigned char sizeClass_;
};

// The keyboard, with CharacterCreationUI_HandleNameEntry's field names.
struct Keyboard {
    KeyboardKey* key_;
    void* layout_;
    char* text_;
    int widthLimit_;
    int textSize_;
    int maxLength_;
    int repeatTimer_;
    short repeatDir_;
    unsigned char page_;
    unsigned char font_;
    unsigned char shift_;
};

// Overlay 23, originally func_ov023_021da274 (USA/EUR 0x021da274, JPN 0x021daa30)
extern "C" ARM void CharacterCreationUI_DrawTabLayers(CharacterCreationUI* editor) {
    if (editor->flags & CreationFlag_RedrawTabHighlight) {
        Background_ClearMap((struct BackgroundGraphics*)&editor->layers[CreationLayer_TabHighlight], NULL);
        int tab = editor->state;
        if (tab >= CreationTab_Gender && tab <= CreationTab_NameEntry) {
            int row = (short)((tab - CreationTab_Gender) * 2 + 1);
            short col = 0xf;
            short row2 = row + 5;
            short col2 = 0xa;
            if (GameState_GetLanguage((struct Struct0200fb08*)GameState::GetInstance()) == OSLanguage_Italian) {
                col = 0xe;
                col2 = 0xd;
            }
            Background_DrawScreen((struct BackgroundGraphics*)&editor->layers[CreationLayer_TabHighlight], 0, 0, row, col, row2, col2, 2, BackgroundPalette_Keep);
        }
        Background_FlushMap(&editor->layers[CreationLayer_TabHighlight], NULL);
    }

    if (editor->flags & CreationFlag_RedrawPanel) {
        Background_ClearMap((struct BackgroundGraphics*)&editor->layers[CreationLayer_Selection], NULL);
        int tab = editor->state;
        if (tab == CreationTab_Gender) {
            unsigned int screen = 0;
            short x;
            short y;
            if (editor->sex == CreationSex_Male) {
                x = 7;
                y = 5;
            } else if (editor->sex == CreationSex_Female) {
                screen = 1;
                x = 7;
                y = 0xb;
            }
            Background_DrawScreen((struct BackgroundGraphics*)&editor->layers[CreationLayer_Selection], screen, 0, 0, x, y, 0x12, 6, BackgroundPalette_Keep);
        } else if (tab == CreationTab_BodyType) {
            unsigned int slot = ((unsigned char*)((int)editor + (int)offsetof(CharacterCreationUI, bodyType)))[editor->sex];
            Background_DrawScreen((struct BackgroundGraphics*)&editor->layers[CreationLayer_Selection], slot, 0, 0, (short)(slot * 5 + 4), 5, 4, 9, BackgroundPalette_Keep);
        } else if (tab == CreationTab_Face) {
            Background_DrawScreen((struct BackgroundGraphics*)&editor->layers[CreationLayer_Selection], 0, 0, 0, 4, 5, 0x18, 9, BackgroundPalette_Keep);
            int choice = ((unsigned char*)((int)editor + (int)offsetof(CharacterCreationUI, faceStyle)))[editor->sex];
            Background_SetRectPalette(&editor->layers[CreationLayer_Selection], (short)(choice % 5 * 5 + 4), (short)((choice / 5 + 1) * 5), 4, 4, 2);
        } else if (tab == CreationTab_HairStyle) {
            Background_DrawScreen((struct BackgroundGraphics*)&editor->layers[CreationLayer_Selection], 0, 0, 0, 4, 5, 0x18, 9, BackgroundPalette_Keep);
            int choice = ((unsigned char*)((int)editor + (int)offsetof(CharacterCreationUI, hairStyle)))[editor->sex];
            Background_SetRectPalette(&editor->layers[CreationLayer_Selection], (short)(choice % 5 * 5 + 4), (short)((choice / 5 + 1) * 5), 4, 4, 2);
        } else if (tab == CreationTab_NameEntry) {
            int i;
            if (editor->flags & CreationFlag_NameRejected) {
                Background_DrawScreen((struct BackgroundGraphics*)&editor->layers[CreationLayer_Selection], 3, 0, 0, 0, 0xe, 0x20, 0xa, BackgroundPalette_Keep);
            } else {
                i = 0;
                unsigned char page = editor->keyboard->page_;
                unsigned char shift = editor->keyboard->shift_;
                while (1) {
                    unsigned char pages = CharacterCreationUI_keyboardPageMasks[i * 3];
                    if (pages == 0) break;
                    if (page & pages) {
                        Background_DrawScreen((struct BackgroundGraphics*)&editor->layers[CreationLayer_Page], (&CharacterCreationUI_keyboardPageScreens[i * 3])[shift], 0, 0, 0, 0, 0x20, 0x18, BackgroundPalette_Keep);
                        break;
                    }
                    var30++;
                }
                Background_SetRectPalette(&editor->layers[CreationLayer_Page], 2, 7, 0x1c, 0xc, 1);
                KeyboardKey* key = editor->keyboard->key_;
                if (key != NULL) {
                    short x = key->x_;
                    short y = key->y_;
                    short height;
                    short width;
                    Keyboard_GetKeySize(key->sizeClass_, &width, &height);
                    Background_SetRectPalette(&editor->layers[CreationLayer_Page], x >> 3, y >> 3, width >> 3, height >> 3, 0);
                }
            }
            Background_FlushMap(&editor->layers[CreationLayer_Page], NULL);
        } else if (tab == CreationTab_Confirm) {
            unsigned int screen = 0;
            if (editor->mode == CreationMode_NewGame) screen = 1;
            Background_DrawScreen((struct BackgroundGraphics*)&editor->layers[CreationLayer_Selection], screen, 0, 0, 0, 0xe, 0x20, 0xa, BackgroundPalette_Keep);
            Background_DrawScreen((struct BackgroundGraphics*)&editor->layers[CreationLayer_Selection], 2, 0, 0, 0x18, 9, 8, 7, BackgroundPalette_Keep);
            Background_SetRectPalette(&editor->layers[CreationLayer_Page], 2, 7, 0x1c, 0xc, 1);
            Background_FlushMap(&editor->layers[CreationLayer_Page], NULL);
        }
        Background_FlushMap(&editor->layers[CreationLayer_Selection], NULL);
    }
}

#endif
