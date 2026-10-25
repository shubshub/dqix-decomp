#include "Input/Input.h"

#if defined(jpn)
#include <globaldefs.h>
#include <std_library_functions.h>
#include "Resource/CharacterCreationUI.h"
#include "Sound/SePlayer.h"
#include "GameState/PartyMember.h"

extern "C" void CharacterCreationUI_SetupSlotNavigation(CharacterCreationUI*);
extern "C" void CharacterCreationUI_LoadSlotLayout(void*);
extern "C" void CharacterCreationUI_MoveCursorToSlot(CharacterCreationUI*, int);
extern "C" int func_ov009_02185c58(void*);
extern "C" int CharacterCreationUI_HandleInput(CharacterCreationUI*);
extern "C" void func_ov009_0218ad0c(void*);
void CharacterCreationUI_SwitchTab(unsigned char*, int);
extern char CharacterCreationUI_nameFill[];
extern const char g_stringFormat[];

enum NameEntryStep { NameEntryStep_Setup, NameEntryStep_Input, NameEntryStep_NameRejected };

extern "C" ARM void CharacterCreationUI_HandleNameEntry(CharacterCreationUI* self)
{
    if (self->step == NameEntryStep_Setup) {
        self->keyboardChoice = 0;
        CharacterCreationUI_SetupSlotNavigation(self);
        CharacterCreationUI_LoadSlotLayout(self);
        CharacterCreationUI_MoveCursorToSlot(self, self->keyboardChoice);
        self->flags |= CreationFlag_StylusRotation;
        self->keyboardPage = self->previousKeyboardPage = 0;
        self->flags &= ~CreationFlag_NameAccepted;
        if (self->nameLengths[self->sex] != 0 && self->names[self->sex][8] == 0) {
            for (int character = 1; character < 5; character++) {
                if (self->names[self->sex][character * 2] == 0) {
                    for (int fill = character; fill < 5; fill++)
                        memcpy(&self->names[self->sex][fill * 2], CharacterCreationUI_nameFill, 2);
                }
            }
            self->flags |= CreationFlag_RefreshName;
        }
        self->step++;
    } else if (self->step == NameEntryStep_Input) {
        if (self->flags & CreationFlag_TabLoading)
            return;
        if (!func_ov009_02185c58(&self->nameFilter))
            return;
        int result = CharacterCreationUI_HandleInput(self);
        if (result == CreationInput_Confirm) {
            func_ov009_0218ad0c(self);
        } else if (result == CreationInput_Back) {
            CharacterCreationUI_SwitchTab((unsigned char*)self, CreationTab_EyeColor);
        } else if (result >= CreationInput_FirstTabIcon && result <= CreationInput_LastTabIcon) {
            result -= CreationInput_TabIcon;
            if (result <= self->furthestState[self->sex] && result != self->state)
                CharacterCreationUI_SwitchTab((unsigned char*)self, (unsigned char)result);
        }
        if (self->flags & CreationFlag_NameRejected) {
            self->flags |= CreationFlag_RedrawPanel;
            self->step++;
        }
        if (self->flags & CreationFlag_NameAccepted) {
            if (result == CreationInput_Confirm)
                self->flags |= CreationFlag_HideButtons;
            PartyMemberData* member = self->characterData;
            sprintf(member->name_, g_stringFormat, self->names[self->sex]);
            CharacterCreationUI_SwitchTab((unsigned char*)self, CreationTab_Confirm);
        }
    } else if (self->step == NameEntryStep_NameRejected) {
        if (g_keyManager.TestKeysPressed(KEY_A | KEY_X) || g_touchInput.pressed_ != 0) {
            SePlayer_Play(&g_sePlayer, SoundEffect_Select, 0);
            self->flags = (self->flags & ~CreationFlag_NameRejected) | CreationFlag_RedrawPanel;
            self->step = NameEntryStep_Input;
        } else if (g_keyManager.TestKeysPressed(KEY_B)) {
            self->flags = (self->flags & ~CreationFlag_NameRejected) | CreationFlag_RedrawPanel;
            self->step = NameEntryStep_Input;
        }
    }
}

#else
#include <globaldefs.h>
#include <std_library_functions.h>
#include "GameState/GameState.h"
#include "Resource/CharacterCreationUI.h"
#include "Resource/Font.h"
#include "Resource/GridCursor.h"
#include "Resource/Keyboard.h"
#include "Sound/SePlayer.h"
#include "GameState/PartyMember.h"

struct KeyboardKey {
    short x_;
    short y_;
    const char* text_;
    const char* shiftedText_;
    unsigned char pages_;
    unsigned char action_;
    unsigned char sizeClass_;
    unsigned char disabled_;
    short id_;
    char unk_12[2];
};

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
    unsigned char wrap_;
    unsigned char allowAlt_;
    unsigned char allowCancel_;
    unsigned char autoRepeat_;
    char unk_25[3];

    void inline_ov009_02186e00(char* arg0, int arg1)
    {
        text_ = text;
        textSize_ = size;
    }
};

struct GridCursor;

extern "C" void Keyboard_ResetToKey(Keyboard* keyboard, const char* text);
FontCharacter* Font_FindCharacter(int character, int font);
extern "C" int Keyboard_Update(Keyboard* keyboard, int ticks);
extern "C" int CharacterCreationUI_HandleInput(void* self);
extern "C" void CharacterCreationUI_CheckName(void* self);
void CharacterCreationUI_SwitchTab(unsigned char* self, int state);
void CharacterCreationUI_RefreshNameText(char* self);
extern "C" KeyboardKey* Keyboard_FindKeyByAction(Keyboard* keyboard, int action);
void CharacterCreationUI_PickRandomName(void* self);
void GridCursor_Init(GridCursor* cursor);
void GridCursor_SetDimensions(GridCursor* cursor, int columns, int rows, int order);
void GridCursor_SetCount(GridCursor* cursor, int count);
extern "C" void GridCursor_SetSelectedIndex(GridCursor* cursor, int index);
void Keyboard_SelectKeyByAction(Keyboard* keyboard, int action);
extern "C" void Keyboard_GetKeySize(int sizeClass, short* width, short* height);

extern char CharacterCreationUI_firstKeyText[];
extern char CharacterCreationUI_widestCharacter[];
extern const char g_stringFormat[];

enum NameEntryStep { NameEntryStep_Setup, NameEntryStep_Start, NameEntryStep_Input, NameEntryStep_NameRejected };
const unsigned int CreationFlag_RefreshInfoWindow = CreationFlag_RefreshName | CreationFlag_RefreshSummary;

// The menu cursor over the keyboard's 11 x 6 grid, back on its first cell. Keeps its own local: passing
// &self->navigation straight to the calls compiles differently.
#define RESET_KEYBOARD_NAVIGATION(self)                                                                    \
    {                                                                                                      \
        GridCursor* navigation = &(self)->navigation;                                                     \
        GridCursor_Init((GridCursor*)navigation);                                                     \
        GridCursor_SetDimensions((GridCursor*)navigation, KeyboardGrid_Columns, KeyboardGrid_Rows,    \
                                 GridCursorOrder_RowMajor);                                                \
        GridCursor_SetCount((GridCursor*)navigation, KeyboardGrid_Cells);                                \
        navigation->pageCount = 1;                                                                             \
        GridCursor_SetSelectedIndex(navigation, 0);                                                        \
    }

// Overlay 9, originally func_ov009_02186e00 (USA/EUR 0x02186e00, JPN 0x02187f2c)
extern "C" ARM void CharacterCreationUI_HandleNameEntry(CharacterCreationUI* self)
{
    if (self->step == NameEntryStep_Setup)
    {
        self->keyboard->SetText(self->names[self->sex], CreationName_BufferSize);
        self->keyboard->maxLength_ = CreationName_MaxLength;
        self->keyboard->font_ = 0;
        self->keyboard->wrap_ = 0;
        self->keyboard->autoRepeat_ = 1;
        Keyboard_ResetToKey(self->keyboard, CharacterCreationUI_firstKeyText);
        self->savedKey = self->keyboard->key_;
        if (self->savedKey != NULL)
            self->keyboard->key_ = self->savedKey;
        self->savedKey = NULL;
        FontCharacter* widest = Font_FindCharacter((int)CharacterCreationUI_widestCharacter, 0);
        if (widest != NULL)
            self->keyboard->widthLimit_ = widest->width_ * CreationName_MaxLength + (CreationName_MaxLength - 1);
        self->step++;
    }
    else if (self->step == NameEntryStep_Start)
    {
        self->keyboard->repeatTimer_ = 0;
        self->keyboard->repeatDir_ = 0;
        self->flags |= CreationFlag_StylusRotation;
        self->flags &= ~CreationFlag_NameAccepted;
        self->flags |= CreationFlag_RefreshInfoWindow;
        self->step++;
    }
    else if (self->step == NameEntryStep_Input)
    {
        if (self->flags & CreationFlag_TabLoading)
            return;
        self->keyboardResult = Keyboard_Update(self->keyboard, GameState::GetInstance()->GetTickCount());
        int result = CharacterCreationUI_HandleInput(self);
        if (self->keyboardResult != KeyboardResult_None)
            result = CreationInput_None;
        int nameChecked = 0;
        if (result == CreationInput_Confirm)
        {
            nameChecked = 1;
            CharacterCreationUI_CheckName(self);
        }
        else if (result == CreationInput_Back)
        {
            CharacterCreationUI_SwitchTab((unsigned char*)self, CreationTab_EyeColor);
            return;
        }
        else if (result >= CreationInput_FirstTabIcon && result <= CreationInput_LastTabIcon)
        {
            result -= CreationInput_TabIcon;
            if (result <= self->furthestState[self->sex] && result != self->state)
            {
                CharacterCreationUI_SwitchTab((unsigned char*)self, (unsigned char)result);
                return;
            }
        }

        self->flags |= CreationFlag_RedrawPanel;
        switch (self->keyboardResult)
        {
        case KeyboardResult_CursorMoved:
            SePlayer_Play(&g_sePlayer, SoundEffect_Cursor, 0);
            break;
        case KeyboardResult_NothingToDelete:
            if (!g_keyManager.TestKeysPressed(KEY_A) && g_touchInput.pressed_ == 0)
                CharacterCreationUI_SwitchTab((unsigned char*)self, CreationTab_EyeColor);
            else
                SePlayer_Play(&g_sePlayer, SoundEffect_Select, 0);
            self->flags |= CreationFlag_RefreshInfoWindow;
            break;
        case KeyboardResult_Typed:
        case KeyboardResult_CapsToggled:
        case KeyboardResult_Shifted:
        case KeyboardResult_LettersPage:
        case KeyboardResult_AccentsPage:
        case KeyboardResult_Deleted:
        case KeyboardResult_SymbolsPage:
            //When a Key is Pressed on the Keyboard
            if (!g_keyManager.TestKeysPressed(KEY_B))
                SePlayer_Play(&g_sePlayer, SoundEffect_Select, 0);
            self->flags |= CreationFlag_RefreshInfoWindow;
            break;
        case KeyboardResult_TypedFull:
            SePlayer_Play(&g_sePlayer, SoundEffect_Select, 0);
            self->flags |= CreationFlag_RefreshInfoWindow;
            CharacterCreationUI_RefreshNameText((char*)self);
            if (g_keyManager.TestKeysPressed(KEY_A))
            {
                KeyboardKey* okKey = Keyboard_FindKeyByAction(self->keyboard, KeyboardAction_Ok);
                if (okKey != NULL)
                    self->keyboard->key_ = okKey;
            }
            break;
        case KeyboardResult_Ok:
            if (*self->names[self->sex] == 0)
                SePlayer_Play(&g_sePlayer, SoundEffect_Select, 0);
            if (nameChecked == 0)
            {
                nameChecked = 1;
                SePlayer_Play(&g_sePlayer, SoundEffect_Select, 0);
                CharacterCreationUI_CheckName(self);
            }
            break;
        case KeyboardResult_KeyDisabled:
            SePlayer_Play(&g_sePlayer, SoundEffect_Select, 0);
            break;
        case KeyboardResult_RandomName:
            SePlayer_Play(&g_sePlayer, SoundEffect_Select, 0);
            CharacterCreationUI_PickRandomName(self);
            self->flags |= CreationFlag_RefreshInfoWindow;
            return;
        default:
            self->flags &= ~CreationFlag_RedrawPanel;
            if (g_keyManager.TestKeysPressed(KEY_SELECT) && result != CreationInput_Confirm)
            {
                if (self->keyboard->key_ != NULL)
                {
                    CharacterCreationUI_PickRandomName(self);
                    self->flags |= CreationFlag_RefreshInfoWindow;
                    return;
                }
            }
            else if (g_keyManager.TestKeysPressed(KEY_UP | KEY_DOWN))
            {
                self->flags |= CreationFlag_RedrawPanel;
            }
            break;
        }

        if (self->keyboardResult != KeyboardResult_None && self->keyboardResult != KeyboardResult_Deleted)
        {
            RESET_KEYBOARD_NAVIGATION(self);
        }
        if (g_keyManager.TestKeysPressed(KEY_START) && !(self->flags & CreationFlag_RefreshInfoWindow) &&
            self->keyboard->key_ != NULL && nameChecked == 0)
            CharacterCreationUI_CheckName(self);
        if (self->flags & CreationFlag_NameRejected)
        {
            self->flags |= CreationFlag_RedrawPanel | CreationFlag_HideButtons;
            self->step++;
        }
        if (self->flags & CreationFlag_NameAccepted)
        {
            RESET_KEYBOARD_NAVIGATION(self);
            Keyboard_SelectKeyByAction(self->keyboard, KeyboardAction_Ok);
            self->flags |= CreationFlag_HideButtons;
            sprintf(self->characterData->name_, g_stringFormat, self->names[self->sex]);
            CharacterCreationUI_SwitchTab((unsigned char*)self, CreationTab_Confirm);
        }
    }
    else if (self->step == NameEntryStep_NameRejected)
    {
        if (g_keyManager.TestKeysPressed(KEY_A | KEY_X) || g_touchInput.pressed_ != 0)
        {
            SePlayer_Play(&g_sePlayer, SoundEffect_Select, 0);
            self->flags = (self->flags & ~(CreationFlag_NameRejected | CreationFlag_HideButtons)) | CreationFlag_RedrawPanel;
            self->step = NameEntryStep_Input;
        }
        else if (g_keyManager.TestKeysPressed(KEY_B))
        {
            self->flags = (self->flags & ~(CreationFlag_NameRejected | CreationFlag_HideButtons)) | CreationFlag_RedrawPanel;
            self->step = NameEntryStep_Input;
        }
    }

    KeyboardKey* key = self->keyboard->key_;
    if (key != NULL)
    {
        short width;
        short height;
        Keyboard_GetKeySize(key->sizeClass_, &width, &height);
        self->cursorX = key->x_;
        self->cursorY = key->y_;
        self->cursorWidth = width;
        self->cursorHeight = height;
    }
}

#endif
