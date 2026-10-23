#include "Input/Input.h"

#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/CharacterCreationUI.h"
#include "Resource/GridCursor.h"
#include "Resource/Keyboard.h"
#include "Sound/SePlayer.h"
#include "Graphics/CharacterModel.h"

struct Struct_0205bef8;
struct Struct_0205ba68;
struct Struct_0205bb84;
struct Node0205bacc;
void GridCursor_Init(Struct_0205bef8*);
void GridCursor_SetDimensions(Struct_0205ba68*, int, int, int);
void GridCursor_SetCount(Node0205bacc*, int);
int GridCursor_GetCount(void*);
int GridCursor_GetSelectedIndex(Struct_0205bb84*);
int KeyTable_Get(Container020e0310*, int);
extern "C" int func_02001aec(const void*, const void*, unsigned int);
extern "C" int CharacterCreationUI_GetTouchedInput(CharacterCreationUI*, int, int);
extern "C" int CharacterCreationUI_PressNameKey(CharacterCreationUI*, unsigned char);
extern "C" void func_ov009_0218ad0c(void*);
extern "C" void func_ov009_0218b200(CharacterCreationUI*, int);
extern "C" void CharacterCreationUI_PickRandomName(CharacterCreationUI*);
extern "C" void GridCursor_SetSelectedIndex(CreationNavigation*, int);
extern "C" int GridCursor_Update(CreationNavigation*, unsigned int);
extern "C" void CharacterCreationUI_SetupSlotNavigation(CharacterCreationUI*);
extern "C" void CharacterCreationUI_MoveCursorToSlot(CharacterCreationUI*, int);
extern "C" void CharacterCreationUI_ApplyChoice(CharacterCreationUI*, int);
extern "C" int CharacterCreationUI_SlotToStyleIndex(CharacterCreationUI*, int, int);

struct PartyMemberAppearance {
    short unknown0[2];
    short face;
    short hairStyle;
    short unknown8[6];
    unsigned char female : 1;
    unsigned char skinColor : 3;
    unsigned char eyeColor : 4;
    unsigned char hairColor : 4;
    unsigned char unknown15 : 4;
    short unknown16, width, height;
};
struct PartyMemberData { char unknown0[0x488]; PartyMemberAppearance appearance; };

// The row of tab icons at the top of the touchscreen, one per tab from Gender to NameEntry: icon N is the
// 16 x 16 square at x = 0x78 + N * 16, y = 8 (where CharacterCreationUI_PlaceSprites puts their sprites).

// A jpn name: up to 5 two-byte characters (CharacterCreationUI_PressNameKey stops adding at 5, and names[sex] holds 10 bytes
// and a NUL). An empty name is text 0x4272, which CharacterCreationUI_PickRandomName copies in before a random name.
enum JpnName
{
    JpnName_MaxLength = 5,
    JpnName_Size = JpnName_MaxLength * 2,
    JpnName_EmptyText = 0x4272,
};

#define RESET_NAVIGATION(columns, rows, count, index) \
    CreationNavigation* navigation = &self->navigation; \
    GridCursor_Init((Struct_0205bef8*)navigation); \
    GridCursor_SetDimensions((Struct_0205ba68*)navigation, columns, rows, GridCursorOrder_RowMajor); \
    GridCursor_SetCount((Node0205bacc*)navigation, count); \
    navigation->pageCount = 1; \
    GridCursor_SetSelectedIndex(navigation, index); \
    navigation->wrapRows = 0

#define MOVE_CURSOR_TO_TAB_ICON(icon) \
    self->cursorX = (icon) * CreationTabIcon_Size + CreationTabIcon_FirstX; \
    self->cursorY = CreationTabIcon_Y; \
    self->cursorWidth = CreationTabIcon_Size; \
    self->cursorHeight = CreationTabIcon_Size

static inline unsigned char GetSkinColor(CharacterCreationUI* self) { return self->skinColor[self->sex]; }
static inline unsigned char GetEyeColor(CharacterCreationUI* self) { return self->eyeColor[self->sex]; }
static inline unsigned char GetHairColor(CharacterCreationUI* self) { return self->hairColor[self->sex]; }

// Overlay 9, originally func_ov009_02188ee8 (USA/EUR 0x02188ee8, JPN 0x02189e04)
extern "C" ARM int CharacterCreationUI_HandleInput(CharacterCreationUI* self)
{
    self->flags &= ~CreationFlag_ConfirmTouched;
    self->flags &= ~CreationFlag_BackTouched;
    int input = CreationInput_None;
    int choice = CreationInput_None;
    int touchX, touchY;
    g_touchInput.GetTouchPoint(&touchX, &touchY);
    int touched = 0;
    if (g_touchInput.pressed_) {
        touched = 1;
        choice = CharacterCreationUI_GetTouchedInput(self, touchX, touchY);
        self->touchedChoice = choice;
        if ((unsigned int)(choice - CreationInput_Back) <= CreationInput_Confirm - CreationInput_Back) {
            if (choice == CreationInput_Confirm) self->flags |= CreationFlag_ConfirmTouched;
            else if (choice == CreationInput_Back) self->flags |= CreationFlag_BackTouched;
            input = choice;
            SePlayer_Play(&g_sePlayer, SoundEffect_Select, 0);
        } else if (choice >= CreationInput_FirstTabIcon && choice <= CreationInput_LastTabIcon) {
            input = choice;
            if (choice - CreationInput_TabIcon <= self->furthestState[self->sex] && choice - CreationInput_TabIcon != self->state)
                SePlayer_Play(&g_sePlayer, SoundEffect_Select, 0);
        } else if (choice >= 0) {
            GridCursor_SetSelectedIndex(&self->navigation, choice);
            if (self->state == CreationTab_NameEntry) {
                CharacterCreationUI_PressNameKey(self, (unsigned char)choice);
                if (self->flags & CreationFlag_KeyboardOk) {
                    self->flags &= ~CreationFlag_KeyboardOk;
                    input = CreationInput_Confirm;
                }
                self->flags |= CreationFlag_RefreshSummary;
            }
            arg0->unknown_c54_ = arg0->unknown_c4c_;
            arg0->unknown_c56_ = arg0->unknown_c4e_;
        }
    } else if (g_touchInput.isRepeatValid_ && g_touchInput.currentReading_.isHeld) touched = 1;
    else if (g_touchInput.released_) touched = 1;
    if (!touched) {
        unsigned int ticks = GameState::GetInstance()->GetTickCount();
        if (!ticks) ticks = 1;
        int previousRow = self->navigation.row;
        if (GridCursor_Update(&self->navigation, ticks))
            choice = GridCursor_GetSelectedIndex((Struct_0205bb84*)&self->navigation);
        if (self->state == CreationTab_NameEntry) {
            int rows = self->navigation.rows;
            int cellCount = GridCursor_GetCount(&self->navigation);
            if (rows == 1 && cellCount == CreationTabIcon_Count) {
                if (choice >= self->furthestState[self->sex]) {
                    GridCursor_SetSelectedIndex(&self->navigation, self->furthestState[self->sex] - CreationTab_Gender);
                    choice = self->furthestState[self->sex] - CreationTab_Gender;
                }
                if (g_keyManager.TestKeysPressed(KEY_DOWN)) {
                    RESET_NAVIGATION(KeyboardGrid_Columns, KeyboardGrid_Rows, KeyboardGrid_Cells, self->keyboardChoice);
                    GridCursor_SetSelectedIndex(&self->navigation, self->navigation.column);
                    self->keyboardChoice = GridCursor_GetSelectedIndex((Struct_0205bb84*)&self->navigation);
                    self->flags |= CreationFlag_RedrawPanel;
                    CharacterCreationUI_MoveCursorToSlot(self, GridCursor_GetSelectedIndex((Struct_0205bb84*)&self->navigation));
                    return CreationInput_None;
                }
                if (choice >= 0) { MOVE_CURSOR_TO_TAB_ICON(choice); }
                if (g_keyManager.TestKeysPressed(KEY_A)) {
                    input = GridCursor_GetSelectedIndex((Struct_0205bb84*)&self->navigation) + CreationInput_FirstTabIcon;
                    if (input - CreationInput_TabIcon <= self->furthestState[self->sex] && input - CreationInput_TabIcon != self->state)
                        SePlayer_Play(&g_sePlayer, SoundEffect_Select, 0);
                } else if (g_keyManager.TestKeysPressed(KEY_B)) {
                    if (func_02001aec(self->names[self->sex], (const void*)KeyTable_Get(&self->texts, JpnName_EmptyText), JpnName_Size) == 0)
                        input = CreationInput_Back;
                    else {
                        func_ov009_0218b200(self, 0);
                        self->flags |= (CreationFlag_RefreshName | CreationFlag_RefreshSummary);
                    }
                }
                return input;
            } else if (rows == KeyboardGrid_Rows) {
                if (g_keyManager.TestKeysPressed(KEY_UP) && previousRow == 0) {
                    RESET_NAVIGATION(CreationTabIcon_Count, 1, CreationTabIcon_Count, self->state - CreationTab_Gender);
                    navigation->wrapColumns = 0;
                    MOVE_CURSOR_TO_TAB_ICON(self->state - CreationTab_Gender);
                    self->flags |= CreationFlag_RedrawPanel;
                    return CreationInput_None;
                }
                if (g_keyManager.TestKeysPressed(KEY_START)) {
                    func_ov009_0218ad0c(self);
                } else if (g_keyManager.TestKeysPressed(KEY_SELECT)) {
                    CharacterCreationUI_PickRandomName(self);
                    self->flags |= (CreationFlag_RefreshName | CreationFlag_RefreshSummary);
                } else if (g_keyManager.TestKeysPressed(KEY_A)) {
                    if (CharacterCreationUI_PressNameKey(self, self->keyboardChoice) && self->nameLengths[self->sex] == JpnName_MaxLength) {
                        choice = KeyboardGrid_Cells - 1;
                        GridCursor_SetSelectedIndex(&self->navigation, choice);
                    }
                    if (!(self->flags & CreationFlag_KeyboardOk)) self->flags |= (CreationFlag_RefreshName | CreationFlag_RedrawPanel | CreationFlag_RefreshSummary);
                    else {
                        func_ov009_0218ad0c(self);
                        self->flags &= ~CreationFlag_KeyboardOk;
                    }
                } else if (g_keyManager.TestKeysPressed(KEY_B)) {
                    if (func_02001aec(self->names[self->sex], (const void*)KeyTable_Get(&self->texts, JpnName_EmptyText), JpnName_Size) == 0)
                        input = CreationInput_Back;
                    else {
                        func_ov009_0218b200(self, 0);
                        self->flags |= (CreationFlag_RefreshName | CreationFlag_RefreshSummary);
                    }
                }
            }
        } else if (self->state != CreationTab_NameEntry) {
            int rows = self->navigation.rows;
            int cellCount = GridCursor_GetCount(&self->navigation);
            if (rows == 1 && cellCount == CreationTabIcon_Count) {
                if (choice >= self->furthestState[self->sex]) {
                    GridCursor_SetSelectedIndex(&self->navigation, self->furthestState[self->sex] - CreationTab_Gender);
                    choice = self->furthestState[self->sex] - CreationTab_Gender;
                }
                if (g_keyManager.TestKeysPressed(KEY_DOWN)) {
                    CharacterCreationUI_SetupSlotNavigation(self);
                    self->flags |= CreationFlag_RedrawPanel;
                    CharacterCreationUI_MoveCursorToSlot(self, GridCursor_GetSelectedIndex((Struct_0205bb84*)&self->navigation));
                    return CreationInput_None;
                }
                if (choice >= 0) { MOVE_CURSOR_TO_TAB_ICON(choice); }
                if (g_keyManager.TestKeysPressed(KEY_A)) {
                    input = GridCursor_GetSelectedIndex((Struct_0205bb84*)&self->navigation) + CreationInput_FirstTabIcon;
                    if (input - CreationInput_TabIcon <= self->furthestState[self->sex] && input - CreationInput_TabIcon != self->state)
                        SePlayer_Play(&g_sePlayer, SoundEffect_Select, 0);
                } else if (g_keyManager.TestKeysPressed(KEY_B)) input = CreationInput_Back;
                return input;
            }
            if (g_keyManager.TestKeysPressed(KEY_UP) && previousRow == 0) {
                RESET_NAVIGATION(CreationTabIcon_Count, 1, CreationTabIcon_Count, self->state - CreationTab_Gender);
                navigation->wrapColumns = 0;
                MOVE_CURSOR_TO_TAB_ICON(self->state - CreationTab_Gender);
                self->flags |= CreationFlag_RedrawPanel;
                return CreationInput_None;
            }
            if (g_keyManager.TestKeysPressed(KEY_A)) {
                input = CreationInput_Confirm;
                SePlayer_Play(&g_sePlayer, SoundEffect_Select, 0);
            } else if (g_keyManager.TestKeysPressed(KEY_B)) input = CreationInput_Back;
        }
    }
    self->flags &= ~CreationFlag_ChoiceChanged;
    if (choice >= 0 && !(choice >= CreationInput_FirstTabIcon && choice <= CreationInput_LastTabIcon)) {
        switch (self->state) {
        case CreationTab_Gender: if (self->sex != choice) self->flags |= CreationFlag_ChoiceChanged; self->sex = choice; break;
        case CreationTab_BodyType: if (self->bodyType[self->sex] != choice) self->flags |= CreationFlag_ChoiceChanged; self->bodyType[self->sex] = choice; break;
        case CreationTab_HairStyle: if (self->hairStyle[self->sex] != choice) self->flags |= CreationFlag_ChoiceChanged; self->hairStyle[self->sex] = choice; break;
        case CreationTab_HairColor: if (self->hairColor[self->sex] != choice) self->flags |= CreationFlag_ChoiceChanged; self->hairColor[self->sex] = choice; break;
        case CreationTab_Face: if (self->faceStyle[self->sex] != choice) self->flags |= CreationFlag_ChoiceChanged; self->faceStyle[self->sex] = choice; break;
        case CreationTab_SkinColor: if (self->skinColor[self->sex] != choice) self->flags |= CreationFlag_ChoiceChanged; self->skinColor[self->sex] = choice; break;
        case CreationTab_EyeColor: if (self->eyeColor[self->sex] != choice) self->flags |= CreationFlag_ChoiceChanged; self->eyeColor[self->sex] = choice; break;
        case CreationTab_NameEntry: if (self->keyboardChoice != choice) self->flags |= CreationFlag_ChoiceChanged; self->keyboardChoice = choice; break;
        }
    }
    if (self->flags & CreationFlag_ChoiceChanged) {
        if (self->state != CreationTab_NameEntry || !touched) SePlayer_Play(&g_sePlayer, SoundEffect_Cursor, 0);
        CharacterCreationUI_ApplyChoice(self, choice);
        if (self->state == CreationTab_Gender) {
            PartyMemberAppearance* appearance = &((PartyMemberData*)self->characterData)->appearance;
            self->flags |= (CreationFlag_ResetAngleOnSwap | CreationFlag_RescaleOnSwap);
            unsigned char skinColor = GetSkinColor(self);
            appearance->skinColor = skinColor;
            unsigned char eyeColor = GetEyeColor(self);
            appearance->eyeColor = eyeColor;
            unsigned char hairColor = GetHairColor(self);
            appearance->hairColor = hairColor;
            appearance->face = CharacterCreationUI_SlotToStyleIndex(self, CreationTab_Face, self->faceStyle[self->sex]) + AppearanceModel_FirstFace;
            appearance->hairStyle = CharacterCreationUI_SlotToStyleIndex(self, CreationTab_HairStyle, self->hairStyle[self->sex]) + AppearanceModel_FirstHairStyle;
        }
        if (!touched) CharacterCreationUI_MoveCursorToSlot(self, choice);
        self->flags |= (0x4000 | CreationFlag_RedrawPanel | CreationFlag_RefreshSummary);
    }
    return input;
}
#undef RESET_NAVIGATION
#undef MOVE_CURSOR_TO_TAB_ICON

#else
#include <globaldefs.h>
#include <GameState/GameState.h>
#include "Resource/CharacterCreationUI.h"
#include "Resource/GridCursor.h"
#include "Resource/Keyboard.h"
#include "Sound/SePlayer.h"
#include "Graphics/CharacterModel.h"

struct Struct_0205bef8;
struct Struct_0205ba68;
struct Struct_0205bb84;
struct Node0205bacc;
void GridCursor_Init(Struct_0205bef8*);
void GridCursor_SetDimensions(Struct_0205ba68*, int, int, int);
void GridCursor_SetCount(Node0205bacc*, int);
int GridCursor_GetCount(void*);
int GridCursor_GetSelectedIndex(Struct_0205bb84*);

// The keyboard's fields this file touches, as CharacterCreationUI_HandleNameEntry names them.
struct Keyboard {
    KeyboardKey* key_;
    char unknown4[0x14];
    int repeatTimer_;
    short repeatDir_;
};
struct PartyMemberAppearance {
    short unknown0[2];
    short face;
    short hairStyle;
    short unknown8[6];
    unsigned char female : 1;
    unsigned char skinColor : 3;
    unsigned char eyeColor : 4;
    unsigned char hairColor : 4;
    unsigned char unknown15 : 4;
    short unknown16, width, height;
};
struct PartyMemberData { char unknown0[0x488]; PartyMemberAppearance appearance; };
extern "C" int CharacterCreationUI_GetTouchedInput(CharacterCreationUI*, int, int);
extern "C" void GridCursor_SetSelectedIndex(CreationNavigation*, int);
extern "C" int GridCursor_Update(CreationNavigation*, unsigned int);
extern "C" void CharacterCreationUI_SetupSlotNavigation(CharacterCreationUI*);
extern "C" void CharacterCreationUI_MoveCursorToSlot(CharacterCreationUI*, int);
extern "C" void CharacterCreationUI_ApplyChoice(CharacterCreationUI*, int);
extern "C" int CharacterCreationUI_SlotToStyleIndex(CharacterCreationUI*, int, int);

// The row of tab icons at the top of the touchscreen, one per tab from Gender to NameEntry: icon N is the
// 16 x 16 square at x = 0x78 + N * 16, y = 8 (where CharacterCreationUI_PlaceSprites puts their sprites).

#define RESET_NAVIGATION(columns, rows, count, index) \
    CreationNavigation* navigation = &self->navigation; \
    GridCursor_Init((Struct_0205bef8*)navigation); \
    GridCursor_SetDimensions((Struct_0205ba68*)navigation, columns, rows, GridCursorOrder_RowMajor); \
    GridCursor_SetCount((Node0205bacc*)navigation, count); \
    navigation->pageCount = 1; \
    GridCursor_SetSelectedIndex(navigation, index); \
    navigation->wrapRows = 0

#define MOVE_CURSOR_TO_TAB_ICON(icon) \
    self->cursorX = (icon) * CreationTabIcon_Size + CreationTabIcon_FirstX; \
    self->cursorY = CreationTabIcon_Y; \
    self->cursorWidth = CreationTabIcon_Size; \
    self->cursorHeight = CreationTabIcon_Size

static inline unsigned char GetSkinColor(CharacterCreationUI* self) { return self->skinColor[self->sex]; }
static inline unsigned char GetEyeColor(CharacterCreationUI* self) { return self->eyeColor[self->sex]; }
static inline unsigned char GetHairColor(CharacterCreationUI* self) { return self->hairColor[self->sex]; }

// Overlay 9, originally func_ov009_02188ee8 (USA/EUR 0x02188ee8, JPN 0x02189e04)
extern "C" ARM int CharacterCreationUI_HandleInput(CharacterCreationUI* self) {
    self->flags &= ~(CreationFlag_ConfirmTouched | CreationFlag_BackTouched);
    int input = CreationInput_None;
    int choice = CreationInput_None;
    int touchX, touchY;
    g_touchInput.GetTouchPoint(&touchX, &touchY);
    int touched = 0;
    if (g_touchInput.pressed_) {
        touched = 1;
        choice = CharacterCreationUI_GetTouchedInput(self, touchX, touchY);
        self->touchedChoice = choice;
        if ((unsigned int)(choice - CreationInput_Back) <= CreationInput_Confirm - CreationInput_Back) {
            if (choice == CreationInput_Confirm) self->flags |= CreationFlag_ConfirmTouched;
            else if (choice == CreationInput_Back) self->flags |= CreationFlag_BackTouched;
            input = choice;
            SePlayer_Play(&g_sePlayer, SoundEffect_Select, 0);
        } else if (choice >= CreationInput_FirstTabIcon && choice <= CreationInput_LastTabIcon) {
            input = choice;
            if (choice - CreationInput_TabIcon <= self->furthestState[self->sex] && choice - CreationInput_TabIcon != self->state)
                SePlayer_Play(&g_sePlayer, SoundEffect_Select, 0);
        } else if (choice >= 0) {
            GridCursor_SetSelectedIndex(&self->navigation, choice);
            if (self->state == CreationTab_NameEntry) {
                if (self->flags & CreationFlag_KeyboardOk) {
                    self->flags &= ~CreationFlag_KeyboardOk;
                    input = CreationInput_Confirm;
                }
                self->flags |= CreationFlag_RefreshSummary;
            }
            self->lastCursorX = self->cursorX;
            self->lastCursorY = self->cursorY;
        }
    } else if (g_touchInput.isRepeatValid_ && g_touchInput.currentReading_.isHeld) touched = 1;
    else if (g_touchInput.released_) touched = 1;
    if (!touched) {
        unsigned int ticks = GameState::GetInstance()->GetTickCount();
        if (!ticks) ticks = 1;
        int previousRow = self->navigation.row;
        if (GridCursor_Update(&self->navigation, ticks)) choice = GridCursor_GetSelectedIndex((Struct_0205bb84*)&self->navigation);
        if (self->state == CreationTab_NameEntry) {
            int rows = self->navigation.rows;
            int cellCount = GridCursor_GetCount(&self->navigation);
            if (rows == 1 && cellCount == CreationTabIcon_Count) {
                if (choice >= self->furthestState[self->sex]) {
                    GridCursor_SetSelectedIndex(&self->navigation, self->furthestState[self->sex] - CreationTab_Gender);
                    choice = self->furthestState[self->sex] - CreationTab_Gender;
                }
                if (g_keyManager.TestKeysPressed(KEY_DOWN)) {
                    RESET_NAVIGATION(KeyboardGrid_Columns, KeyboardGrid_Rows, KeyboardGrid_Cells, 0);
                    self->flags |= CreationFlag_RedrawPanel;
                    if (self->savedKey) self->keyboard->key_ = self->savedKey;
                    self->keyboard->repeatTimer_ = 0;
                    self->keyboard->repeatDir_ = 0;
                    return CreationInput_None;
                }
                if (choice >= 0) { MOVE_CURSOR_TO_TAB_ICON(choice); }
                if (g_keyManager.TestKeysPressed(KEY_A)) {
                    input = GridCursor_GetSelectedIndex((Struct_0205bb84*)&self->navigation) + CreationInput_FirstTabIcon;
                    if (input - CreationInput_TabIcon <= self->furthestState[self->sex] && input - CreationInput_TabIcon != self->state)
                        SePlayer_Play(&g_sePlayer, SoundEffect_Select, 0);
                }
                return input;
            }
            if (self->keyboardResult == KeyboardResult_None && g_keyManager.TestKeysPressed(KEY_UP)) {
                self->savedKey = self->keyboard->key_;
                self->keyboard->key_ = 0;
                RESET_NAVIGATION(CreationTabIcon_Count, 1, CreationTabIcon_Count, self->state - CreationTab_Gender);
                navigation->wrapColumns = 0;
                MOVE_CURSOR_TO_TAB_ICON(self->state - CreationTab_Gender);
            }
        } else if (self->state != CreationTab_NameEntry) {
            int rows = self->navigation.rows;
            int cellCount = GridCursor_GetCount(&self->navigation);
            if (rows == 1 && cellCount == CreationTabIcon_Count) {
                if (choice >= self->furthestState[self->sex]) {
                    GridCursor_SetSelectedIndex(&self->navigation, self->furthestState[self->sex] - CreationTab_Gender);
                    choice = self->furthestState[self->sex] - CreationTab_Gender;
                }
                if (g_keyManager.TestKeysPressed(KEY_DOWN)) {
                    CharacterCreationUI_SetupSlotNavigation(self);
                    self->flags |= CreationFlag_RedrawPanel;
                    CharacterCreationUI_MoveCursorToSlot(self, GridCursor_GetSelectedIndex((Struct_0205bb84*)&self->navigation));
                    return CreationInput_None;
                }
                if (choice >= 0) { MOVE_CURSOR_TO_TAB_ICON(choice); }
                if (g_keyManager.TestKeysPressed(KEY_A)) {
                    input = GridCursor_GetSelectedIndex((Struct_0205bb84*)&self->navigation) + CreationInput_FirstTabIcon;
                    if (input - CreationInput_TabIcon <= self->furthestState[self->sex] && input - CreationInput_TabIcon != self->state)
                        SePlayer_Play(&g_sePlayer, SoundEffect_Select, 0);
                } else if (g_keyManager.TestKeysPressed(KEY_B)) input = CreationInput_Back;
                if (input == CreationInput_TabIcon + CreationTab_NameEntry) GridCursor_SetDimensions((Struct_0205ba68*)&self->navigation, KeyboardGrid_Columns, KeyboardGrid_Rows, GridCursorOrder_ColumnMajor);
                return input;
            }
            if (g_keyManager.TestKeysPressed(KEY_UP) && previousRow == 0) {
                RESET_NAVIGATION(CreationTabIcon_Count, 1, CreationTabIcon_Count, self->state - CreationTab_Gender);
                navigation->wrapColumns = 0;
                MOVE_CURSOR_TO_TAB_ICON(self->state - CreationTab_Gender);
                self->flags |= CreationFlag_RedrawPanel;
                return CreationInput_None;
            }
            if (g_keyManager.TestKeysPressed(KEY_A)) {
                input = CreationInput_Confirm;
                SePlayer_Play(&g_sePlayer, SoundEffect_Select, 0);
            } else if (g_keyManager.TestKeysPressed(KEY_B)) input = CreationInput_Back;
        }
    }
    self->flags &= ~CreationFlag_ChoiceChanged;
    if (choice >= 0 && !(choice >= CreationInput_FirstTabIcon && choice <= CreationInput_LastTabIcon)) {
        unsigned char* sexChoice = &self->sex;
        switch (self->state) {
        case CreationTab_NameEntry: break;
        case CreationTab_Gender: { if (*sexChoice != choice) self->flags |= CreationFlag_ChoiceChanged; *sexChoice = choice; break; }
        case CreationTab_BodyType: { unsigned char* choices = self->bodyType; int sex = self->sex; unsigned char previousChoice = choices[sex]; if (previousChoice != choice) self->flags |= CreationFlag_ChoiceChanged; choices[sex] = choice; break; }
        case CreationTab_HairStyle: { unsigned char* choices = self->hairStyle; int sex = self->sex; unsigned char previousChoice = choices[sex]; if (previousChoice != choice) self->flags |= CreationFlag_ChoiceChanged; choices[sex] = choice; break; }
        case CreationTab_HairColor: { unsigned char* choices = self->hairColor; int sex = self->sex; unsigned char previousChoice = choices[sex]; if (previousChoice != choice) self->flags |= CreationFlag_ChoiceChanged; choices[sex] = choice; break; }
        case CreationTab_Face: { unsigned char* choices = self->faceStyle; int sex = self->sex; unsigned char previousChoice = choices[sex]; if (previousChoice != choice) self->flags |= CreationFlag_ChoiceChanged; choices[sex] = choice; break; }
        case CreationTab_SkinColor: { unsigned char* choices = self->skinColor; int sex = self->sex; unsigned char previousChoice = choices[sex]; if (previousChoice != choice) self->flags |= CreationFlag_ChoiceChanged; choices[sex] = choice; break; }
        case CreationTab_EyeColor: { unsigned char* choices = self->eyeColor; int sex = self->sex; unsigned char previousChoice = choices[sex]; if (previousChoice != choice) self->flags |= CreationFlag_ChoiceChanged; choices[sex] = choice; break; }
        }
    }
    if (self->flags & CreationFlag_ChoiceChanged) {
        if (self->state != CreationTab_NameEntry || !touched) SePlayer_Play(&g_sePlayer, SoundEffect_Cursor, 0);
        CharacterCreationUI_ApplyChoice(self, choice);
        if (self->state == CreationTab_Gender) {
            PartyMemberAppearance* appearance = &((PartyMemberData*)self->characterData)->appearance;
            self->flags |= (CreationFlag_ResetAngleOnSwap | CreationFlag_RescaleOnSwap);
            unsigned char skinColor = GetSkinColor(self);
            appearance->skinColor = skinColor;
            unsigned char eyeColor = GetEyeColor(self);
            appearance->eyeColor = eyeColor;
            unsigned char hairColor = GetHairColor(self);
            appearance->hairColor = hairColor;
            appearance->face = CharacterCreationUI_SlotToStyleIndex(self, CreationTab_Face, self->faceStyle[self->sex]) + AppearanceModel_FirstFace;
            appearance->hairStyle = CharacterCreationUI_SlotToStyleIndex(self, CreationTab_HairStyle, self->hairStyle[self->sex]) + AppearanceModel_FirstHairStyle;
        }
        if (!touched) CharacterCreationUI_MoveCursorToSlot(self, choice);
        self->flags |= (0x4000 | CreationFlag_RedrawPanel | CreationFlag_RefreshSummary);
    }
    if (input == CreationInput_TabIcon + CreationTab_NameEntry && input - CreationInput_TabIcon <= self->furthestState[self->sex] && input - CreationInput_TabIcon != self->state)
        GridCursor_SetDimensions((Struct_0205ba68*)&self->navigation, KeyboardGrid_Columns, KeyboardGrid_Rows, GridCursorOrder_ColumnMajor);
    return input;
}

#endif
