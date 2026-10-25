#if defined(jpn)
#include <globaldefs.h>
#include "std_library_functions.h"
#include "Resource/CharacterCreationUI.h"
#include "Combat/TryApplyElemFields.h"

int KeyTable_Get(Container020e0310*, int);
int Text_AppendPaletteTag(char*, int);
extern "C" int func_02042158(char*, int);
int Text_Append(char*, const char*);
int STD_GetStringLength(const char*);
int STD_CompareString(const char*, const char*);
extern "C" int memcmp(const void*, const void*, unsigned int);
extern "C" const char data_ov023_021fcd20[];

// Overlay 23, originally func_ov023_021d9a6c (USA/EUR 0x021d9a6c, JPN 0x021da264)
extern "C" ARM void CharacterCreationUI_RefreshSummary(char* storage) {
    CharacterCreationUI* editor = (CharacterCreationUI*)storage;
    unsigned int flags = editor->flags;
    if (!(flags & CreationFlag_RefreshSummary)) return;
    if (editor->state >= CreationTab_Close) {
        editor->flags = flags & ~CreationFlag_RefreshSummary;
        return;
    }

    unsigned char sex = editor->sex;
    short femaleOffset = (short)(sex * CreationText_FemaleOffset);
    short keys[CreationTab_NameEntry - CreationTab_Gender];
    keys[0] = (short)(femaleOffset + CreationText_Gender);
    keys[1] = (short)(editor->bodyType[sex] + CreationText_BodyType);
    keys[2] = (short)(femaleOffset + CreationText_HairStyle + editor->hairStyle[sex]);
    keys[3] = (short)(editor->hairColor[sex] + CreationText_HairColor);
    keys[4] = (short)(femaleOffset + CreationText_Face + editor->faceStyle[sex]);
    keys[5] = (short)(editor->skinColor[sex] + CreationText_SkinColor);
    keys[6] = (short)(editor->eyeColor[sex] + CreationText_EyeColor);
    memset(editor->textBuffer, 0, 0x800);

    for (int row = 0; row < editor->furthestState[editor->sex]; row++) {
        if (row == editor->state - CreationTab_Gender)
            Text_AppendPaletteTag(editor->textBuffer, 14);
        else
            Text_AppendPaletteTag(editor->textBuffer, 15);
        if (row < CreationTab_NameEntry - CreationTab_Gender) {
            short key = keys[row];
            func_02042158(editor->textBuffer, (10 - STD_GetStringLength((const char*)KeyTable_Get(&editor->texts, key))) * 5);
            Text_Append(editor->textBuffer, (const char*)KeyTable_Get(&editor->texts, key));
            Text_Append(editor->textBuffer, (const char*)KeyTable_Get(&editor->texts, CreationText_NewLine));
        } else if (row == CreationTab_NameEntry - CreationTab_Gender) {
            if (STD_CompareString(editor->names[editor->sex], (const char*)KeyTable_Get(&editor->texts, CreationText_BlankName)) == 0) {
                Text_Append(editor->textBuffer, (const char*)KeyTable_Get(&editor->texts, CreationText_WidthTag));
            } else {
                char name[11] = {};
                memcpy(name, editor->names[editor->sex], sizeof(name));
                char character[3] = {};
                for (int n = 1; n < 5; n++) {
                    memcpy(character, &name[n * 2], 2);
                    if (memcmp(character, data_ov023_021fcd20, 2) == 0) {
                        memset(&name[n * 2], 0, sizeof(name) - n * 2);
                        break;
                    }
                }
                func_02042158(editor->textBuffer, (10 - STD_GetStringLength(name)) * 5);
                Text_Append(editor->textBuffer, name);
            }
        }
    }
    Window_SetPaneText((StructA0205d5d0*)&editor->windows[0], 0, (int)editor->textBuffer, 0);
    editor->flags &= ~CreationFlag_RefreshSummary;
}
#else
#include <globaldefs.h>
#include "std_library_functions.h"
#include "Resource/CharacterCreationUI.h"
#include "Combat/TryApplyElemFields.h"

extern int KeyTable_Get(Container020e0310*, int);
extern int Text_AppendPaletteTag(char*, int);
extern int AppendXTag_02041a28(char*, int);
extern int Text_Append(char*, const char*);
extern "C" int Font_GetTextWidth(void*, int);

// Overlay 23, originally func_ov023_021d9a6c (USA/EUR 0x021d9a6c, JPN 0x021da264)
extern "C" ARM void CharacterCreationUI_RefreshSummary(char* storage) {
    CharacterCreationUI* editor = (CharacterCreationUI*)storage;
    int flags = editor->flags;
    if (!(flags & CreationFlag_RefreshSummary)) return;

    if (editor->state >= CreationTab_Close) {
        editor->flags = flags & ~CreationFlag_RefreshSummary;
        return;
    }

    unsigned char sex = editor->sex;
    char* text = editor->textBuffer;
    short femaleOffset = (short)(sex * CreationText_FemaleOffset);

    short keys[CreationTab_NameEntry - CreationTab_Gender];
    keys[0] = (short)(femaleOffset + CreationText_Gender);
    keys[1] = (short)(editor->bodyType[sex] + CreationText_BodyType);
    keys[2] = (short)(femaleOffset + CreationText_HairStyle + editor->hairStyle[sex]);
    keys[3] = (short)(editor->hairColor[sex] + CreationText_HairColor);
    keys[4] = (short)(femaleOffset + CreationText_Face + editor->faceStyle[sex]);
    keys[5] = (short)(editor->skinColor[sex] + CreationText_SkinColor);
    keys[6] = (short)(editor->eyeColor[sex] + CreationText_EyeColor);

    memset(text, 0, 0x960);

    int row;
    for (row = 0; row < editor->furthestState[editor->sex]; row++) {
        signed char tab = editor->state;
        int palette = 15;
        if (row == tab - CreationTab_Gender) palette = 14;
        Text_AppendPaletteTag(text, palette);

        if (row < CreationTab_NameEntry - CreationTab_Gender) {
            short key = keys[row];
            AppendXTag_02041a28(text, 0x32 - Font_GetTextWidth((void*)KeyTable_Get(&editor->texts, key), 0));
            Text_Append(text, (const char*)KeyTable_Get(&editor->texts, key));
            Text_Append(text, (const char*)KeyTable_Get(&editor->texts, CreationText_NewLine));
        } else if (row == CreationTab_NameEntry - CreationTab_Gender) {
            char* name = editor->names[editor->sex];
            if (*(signed char*)name != 0) {
                AppendXTag_02041a28(text, 0x32 - Font_GetTextWidth(name, 0));
                Text_Append(text, name);
            } else {
                Text_Append(text, (const char*)KeyTable_Get(&editor->texts, CreationText_WidthTag));
            }
        }
    }

    Window_SetPaneText((StructA0205d5d0*)&editor->windows[0], 0, (int)text, 0, 0);
    editor->flags &= ~CreationFlag_RefreshSummary;
}

#endif
