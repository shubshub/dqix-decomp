#include "Input/Input.h"

#if defined(jpn)
#include <globaldefs.h>
#include <std_library_functions.h>
#include "Resource/CharacterCreationUI.h"
#include "Sound/SePlayer.h"

struct PartyMemberData { char unknown[0x3c]; char name[1]; };
extern "C" void CharacterCreationUI_SetupSlotNavigation(CharacterCreationUI*);
extern "C" void CharacterCreationUI_LoadSlotLayout(void*);
extern "C" void CharacterCreationUI_MoveCursorToSlot(CharacterCreationUI*, int);
extern "C" int func_ov009_02185c58(void*);
extern "C" int CharacterCreationUI_HandleInput(CharacterCreationUI*);
extern "C" void func_ov009_0218ad0c(void*);
void CharacterCreationUI_SwitchTab(unsigned char*, int);
extern char CharacterCreationUI_nameFill[];
extern const char g_stringFormat[];

extern "C" ARM void CharacterCreationUI_HandleNameEntry(CharacterCreationUI* self)
{
    if (self->step == 0) {
        self->keyboardChoice = 0;
        CharacterCreationUI_SetupSlotNavigation(self);
        CharacterCreationUI_LoadSlotLayout(self);
        CharacterCreationUI_MoveCursorToSlot(self, self->keyboardChoice);
        self->flags |= CreationFlag_StylusRotation;
        self->keyboardPage = self->previousKeyboardPage = 0;
        self->flags &= ~CreationFlag_NameAccepted;
        if (self->nameFlags[self->sex] != 0 && self->names[self->sex][8] == 0) {
            for (int character = 1; character < 5; character++) {
                if (self->names[self->sex][character * 2] == 0) {
                    for (int fill = character; fill < 5; fill++)
                        memcpy(&self->names[self->sex][fill * 2], CharacterCreationUI_nameFill, 2);
                }
            }
            self->flags |= CreationFlag_RefreshName;
        }
        self->step++;
    } else if (self->step == 1) {
        if (self->flags & CreationFlag_TabLoading)
            return;
        if (!func_ov009_02185c58(arg0->unknown_dc_))
            return;
        int result = CharacterCreationUI_HandleInput(self);
        if (result == CreationInput_Confirm) {
            func_ov009_0218ad0c(self);
        } else if (result == CreationInput_Back) {
            CharacterCreationUI_SwitchTab((unsigned char*)self, CreationTab_SkinColor);
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
            PartyMemberData* member = (PartyMemberData*)self->characterData;
            sprintf(member->name, g_stringFormat, self->names[self->sex]);
            CharacterCreationUI_SwitchTab((unsigned char*)self, CreationTab_Confirm);
        }
    } else if (self->step == 2) {
        if (g_keyManager.TestKeysPressed(KEY_A | KEY_X) || g_touchInput.pressed_ != 0) {
            SePlayer_Play(&g_sePlayer, SoundEffect_Select, 0);
            self->flags = (self->flags & ~CreationFlag_NameRejected) | CreationFlag_RedrawPanel;
            self->step = 1;
        } else if (g_keyManager.TestKeysPressed(KEY_B)) {
            self->flags = (self->flags & ~CreationFlag_NameRejected) | CreationFlag_RedrawPanel;
            self->step = 1;
        }
    }
}

#else
#include <globaldefs.h>
#include <std_library_functions.h>
#include "GameState/GameState.h"
#include "Resource/CharacterCreationUI.h"
#include "Resource/GridCursor.h"
#include "Resource/Keyboard.h"
#include "Sound/SePlayer.h"

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

struct FontCharacter {
    const char* text_;
    signed char width_;
};

struct GridCursor {
    int count_;
    int unk_4;
    char unk_8[0x38];
};

struct Struct_ov005_0215840c_2 {
    char unknown_0_[0x3c];
    char unknown_3c_[1];
};

struct Struct_0205bef8;
struct Struct_0205ba68;
struct Struct_0205bacc;

extern "C" void Keyboard_ResetToKey(Keyboard* keyboard, const char* text);
FontCharacter* Font_FindCharacter(int character, int font);
extern "C" int Keyboard_Update(Keyboard* keyboard, int ticks);
extern "C" int CharacterCreationUI_HandleInput(void* self);
extern "C" void CharacterCreationUI_CheckName(void* self);
void CharacterCreationUI_SwitchTab(unsigned char* self, int state);
void CharacterCreationUI_RefreshNameText(char* self);
extern "C" KeyboardKey* Keyboard_FindKeyByAction(Keyboard* keyboard, int action);
void CharacterCreationUI_PickRandomName(void* self);
void GridCursor_Init(Struct_0205bef8* cursor);
void GridCursor_SetDimensions(Struct_0205ba68* cursor, int columns, int rows, int order);
void GridCursor_SetCount(Node0205bacc* cursor, int count);
extern "C" void GridCursor_SetSelectedIndex(GridCursor* cursor, int index);
void Keyboard_SelectKeyByAction(Keyboard* keyboard, int action);
extern "C" void Keyboard_GetKeySize(int sizeClass, short* width, short* height);

extern char CharacterCreationUI_firstKeyText[];
extern char CharacterCreationUI_widestCharacter[];
extern const char g_stringFormat[];

struct CharacterCreation {
    char unk_0[0xbc];
    KeyboardKey* savedKey_;
    Keyboard* keyboard_;
    char unk_c4[0xbec - 0xc4];
    GridCursor navigation_;
    char unk_c2c[0xc4c - 0xc2c];
    short cursorX_;
    short cursorY_;
    short cursorWidth_;
    short cursorHeight_;
    short lastCursorX_;
    short lastCursorY_;
    signed char state_;
    unsigned char step_;
    char unk_c5a[0xd88 - 0xc5a];
    PartyMemberData* characterData_;
    char unk_d8c[0xd9c - 0xd8c];
    unsigned int flags_;
    signed char furthestState_[2];
    unsigned char vocation_;
    unsigned char sex_;
    char unk_da4[0xdb0 - 0xda4];
    char** names_;
    unsigned char nameFill_;
    unsigned char keyboardResult_;
};

// Overlay 9, originally func_ov009_02186e00 (USA/EUR 0x02186e00, JPN 0x02187f2c)
extern "C" ARM void CharacterCreationUI_HandleNameEntry(CharacterCreation* self)
{
    if (arg0->unknown_c59_ == 0)
    {
        self->keyboard_->SetText(self->names_[self->sex_], CreationName_BufferSize);
        self->keyboard_->maxLength_ = CreationName_MaxLength;
        self->keyboard_->font_ = 0;
        self->keyboard_->wrap_ = 0;
        self->keyboard_->autoRepeat_ = 1;
        Keyboard_ResetToKey(self->keyboard_, CharacterCreationUI_firstKeyText);
        self->savedKey_ = self->keyboard_->key_;
        if (self->savedKey_ != NULL)
            self->keyboard_->key_ = self->savedKey_;
        self->savedKey_ = NULL;
        FontCharacter* widest = Font_FindCharacter((int)CharacterCreationUI_widestCharacter, 0);
        if (widest != NULL)
            self->keyboard_->widthLimit_ = widest->width_ * CreationName_MaxLength + (CreationName_MaxLength - 1);
        self->step_++;
    }
    else if (arg0->unknown_c59_ == 1)
    {
        self->keyboard_->repeatTimer_ = 0;
        self->keyboard_->repeatDir_ = 0;
        self->flags_ |= CreationFlag_StylusRotation;
        self->flags_ &= ~CreationFlag_NameAccepted;
        self->flags_ |= CreationFlag_RefreshName | CreationFlag_RefreshSummary;
        self->step_++;
    }
    else if (arg0->unknown_c59_ == 2)
    {
        if (self->flags_ & CreationFlag_TabLoading)
            return;
        self->keyboardResult_ = Keyboard_Update(self->keyboard_, GameState::GetInstance()->GetTickCount());
        int result = CharacterCreationUI_HandleInput(self);
        if (self->keyboardResult_ != KeyboardResult_None)
            result = CreationInput_None;
        int nameChecked = 0;
        if (result == CreationInput_Confirm)
        {
            nameChecked = 1;
            CharacterCreationUI_CheckName(self);
        }
        else if (result == CreationInput_Back)
        {
            CharacterCreationUI_SwitchTab((unsigned char*)self, CreationTab_SkinColor);
            return;
        }
        else if (result >= CreationInput_FirstTabIcon && result <= CreationInput_LastTabIcon)
        {
            result -= CreationInput_TabIcon;
            if (result <= self->furthestState_[self->sex_] && result != self->state_)
            {
                CharacterCreationUI_SwitchTab((unsigned char*)self, (unsigned char)result);
                return;
            }
        }

        self->flags_ |= CreationFlag_RedrawPanel;
        switch (self->keyboardResult_)
        {
        case KeyboardResult_CursorMoved:
            SePlayer_Play(&g_sePlayer, SoundEffect_Cursor, 0);
            break;
        case KeyboardResult_NothingToDelete:
            if (!g_keyManager.TestKeysPressed(KEY_A) && g_touchInput.pressed_ == 0)
                CharacterCreationUI_SwitchTab((unsigned char*)self, CreationTab_SkinColor);
            else
                SePlayer_Play(&g_sePlayer, SoundEffect_Select, 0);
            self->flags_ |= CreationFlag_RefreshName | CreationFlag_RefreshSummary;
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
            self->flags_ |= CreationFlag_RefreshName | CreationFlag_RefreshSummary;
            break;
        case KeyboardResult_TypedFull:
            SePlayer_Play(&g_sePlayer, SoundEffect_Select, 0);
            self->flags_ |= CreationFlag_RefreshName | CreationFlag_RefreshSummary;
            CharacterCreationUI_RefreshNameText((char*)self);
            if (g_keyManager.TestKeysPressed(KEY_A))
            {
                KeyboardKey* okKey = Keyboard_FindKeyByAction(self->keyboard_, KeyboardAction_Ok);
                if (okKey != NULL)
                    self->keyboard_->key_ = okKey;
            }
            break;
        case KeyboardResult_Ok:
            if (*self->names_[self->sex_] == 0)
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
            self->flags_ |= CreationFlag_RefreshName | CreationFlag_RefreshSummary;
            return;
        default:
            self->flags_ &= ~CreationFlag_RedrawPanel;
            if (g_keyManager.TestKeysPressed(KEY_SELECT) && result != CreationInput_Confirm)
            {
                if (arg0->unknown_c0_->unknown_0_ != NULL)
                {
                    CharacterCreationUI_PickRandomName(self);
                    self->flags_ |= CreationFlag_RefreshName | CreationFlag_RefreshSummary;
                    return;
                }
            }
            else if (g_keyManager.TestKeysPressed(KEY_UP | KEY_DOWN))
            {
                self->flags_ |= CreationFlag_RedrawPanel;
            }
            break;
        }

        if (self->keyboardResult_ != KeyboardResult_None && self->keyboardResult_ != KeyboardResult_Deleted)
        {
            GridCursor* navigation = &self->navigation_;
            GridCursor_Init((Struct_0205bef8*)navigation);
            GridCursor_SetDimensions((Struct_0205ba68*)navigation, KeyboardGrid_Columns, KeyboardGrid_Rows, GridCursorOrder_RowMajor);
            GridCursor_SetCount((Node0205bacc*)navigation, KeyboardGrid_Cells);
            navigation->unk_4 = 1;
            GridCursor_SetSelectedIndex(navigation, 0);
        }
        if (g_keyManager.TestKeysPressed(KEY_START) && !(self->flags_ & (CreationFlag_RefreshName | CreationFlag_RefreshSummary)) &&
            self->keyboard_->key_ != NULL && nameChecked == 0)
            CharacterCreationUI_CheckName(self);
        if (self->flags_ & CreationFlag_NameRejected)
        {
            self->flags_ |= CreationFlag_RedrawPanel | CreationFlag_HideButtons;
            self->step_++;
        }
        if (self->flags_ & CreationFlag_NameAccepted)
        {
            GridCursor* navigation = &self->navigation_;
            GridCursor_Init((Struct_0205bef8*)navigation);
            GridCursor_SetDimensions((Struct_0205ba68*)navigation, KeyboardGrid_Columns, KeyboardGrid_Rows, GridCursorOrder_RowMajor);
            GridCursor_SetCount((Node0205bacc*)navigation, KeyboardGrid_Cells);
            navigation->unk_4 = 1;
            GridCursor_SetSelectedIndex(navigation, 0);
            Keyboard_SelectKeyByAction(self->keyboard_, KeyboardAction_Ok);
            self->flags_ |= CreationFlag_HideButtons;
            sprintf(self->characterData_->name_, g_stringFormat, self->names_[self->sex_]);
            CharacterCreationUI_SwitchTab((unsigned char*)self, CreationTab_Confirm);
        }
    }
    else if (arg0->unknown_c59_ == 3)
    {
        if (g_keyManager.TestKeysPressed(KEY_A | KEY_X) || g_touchInput.pressed_ != 0)
        {
            SePlayer_Play(&g_sePlayer, SoundEffect_Select, 0);
            self->flags_ = (self->flags_ & ~(CreationFlag_NameRejected | CreationFlag_HideButtons)) | CreationFlag_RedrawPanel;
            self->step_ = 2;
        }
        else if (g_keyManager.TestKeysPressed(KEY_B))
        {
            self->flags_ = (self->flags_ & ~(CreationFlag_NameRejected | CreationFlag_HideButtons)) | CreationFlag_RedrawPanel;
            self->step_ = 2;
        }
    }

    Struct_ov003_0215f4e4_2* var10 = arg0->unknown_c0_->unknown_0_;
    if (var10 != NULL)
    {
        short width;
        short height;
        Keyboard_GetKeySize(key->sizeClass_, &width, &height);
        self->cursorX_ = key->x_;
        self->cursorY_ = key->y_;
        self->cursorWidth_ = width;
        self->cursorHeight_ = height;
    }
}

#endif
