#include "Input/Input.h"

#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/CharacterCreationUI.h"

struct Struct_0205bef8;
struct Struct_0205ba68;
struct Struct_0205bb84;
struct Node0205bacc;
struct SePlayer;
void GridCursor_Init(Struct_0205bef8*);
void GridCursor_SetDimensions(Struct_0205ba68*, int, int, int);
void GridCursor_SetCount(Node0205bacc*, int);
int GetField0_0205bafc(void*);
int GridCursor_GetSelectedIndex(Struct_0205bb84*);
void SePlayer_Play(SePlayer*, int, int);
int GetFieldByKey020e0434(Container020e0310*, int);
extern "C" int func_02001aec(const void*, const void*, unsigned int);
extern "C" int func_ov009_0218a8b4(CharacterCreationUI*, int, int);
extern "C" int func_ov009_0218aab0(CharacterCreationUI*, unsigned char);
extern "C" void func_ov009_0218ad0c(void*);
extern "C" void func_ov009_0218b200(CharacterCreationUI*, int);
extern "C" void func_ov009_0218b850(CharacterCreationUI*);
extern "C" void GridCursor_SetSelectedIndex(CreationNavigation*, int);
extern "C" int func_0205bf58(CreationNavigation*, unsigned int);
extern "C" void CharacterCreationUI_SetupSlotNavigation(CharacterCreationUI*);
extern "C" void CharacterCreationUI_MoveCursorToSlot(CharacterCreationUI*, int);
extern "C" void CharacterCreationUI_ApplyChoice(CharacterCreationUI*, int);
extern "C" int CharacterCreationUI_SlotToStyleIndex(CharacterCreationUI*, int, int);

struct PartyMemberAppearance {
    short models[10];
    unsigned char female : 1;
    unsigned char eyeColor : 3;
    unsigned char skinColor : 4;
    unsigned char hairColor : 4;
    unsigned char unused : 4;
    short field16, width, height;
};
struct PartyMemberData { char unknown0[0x488]; PartyMemberAppearance appearance; };
extern SePlayer g_sePlayer;

#define RESET_NAVIGATION(columns, rows, total, selected) \
    CreationNavigation* navigation = &self->navigation; \
    GridCursor_Init((Struct_0205bef8*)navigation); \
    GridCursor_SetDimensions((Struct_0205ba68*)navigation, columns, rows, 1); \
    GridCursor_SetCount((Node0205bacc*)navigation, total); \
    navigation->field4 = 1; \
    GridCursor_SetSelectedIndex(navigation, selected); \
    navigation->flags3d = 0

#define MOVE_CURSOR_TO_TAB_ICON(selected) \
    self->cursorX = ((selected) << 4) + 0x78; \
    self->cursorY = 8; \
    self->cursorWidth = 16; \
    self->cursorHeight = 16

static inline unsigned char GetEyeColor(CharacterCreationUI* self) { return self->eyeColor[self->sex]; }
static inline unsigned char GetSkinColor(CharacterCreationUI* self) { return self->skinColor[self->sex]; }
static inline unsigned char GetHairColor(CharacterCreationUI* self) { return self->hairColor[self->sex]; }

// Overlay 9, originally func_ov009_02188ee8 (USA/EUR 0x02188ee8, JPN 0x02189e04)
extern "C" ARM int CharacterCreationUI_HandleInput(CharacterCreationUI* self)
{
    self->flags &= ~CreationFlag_ConfirmTouched;
    self->flags &= ~CreationFlag_BackTouched;
    int result = CreationInput_None;
    int choice = -1;
    int x, y;
    g_touchInput.GetTouchPoint(&x, &y);
    int touched = 0;
    if (g_touchInput.pressed_) {
        touched = 1;
        choice = func_ov009_0218a8b4(self, x, y);
        self->touchedChoice = choice;
        if ((unsigned int)(choice + 3) <= 1) {
            if (choice == CreationInput_Confirm) self->flags |= CreationFlag_ConfirmTouched;
            else if (choice == CreationInput_Back) self->flags |= CreationFlag_BackTouched;
            result = choice;
            SePlayer_Play(&g_sePlayer, 1, 0);
        } else if (choice >= CreationInput_FirstTabIcon && choice <= CreationInput_LastTabIcon) {
            result = choice;
            if (choice - CreationInput_TabIcon <= self->furthestState[self->sex] && choice - CreationInput_TabIcon != self->state)
                SePlayer_Play(&g_sePlayer, 1, 0);
        } else if (choice >= 0) {
            GridCursor_SetSelectedIndex(&self->navigation, choice);
            if (self->state == CreationTab_NameEntry) {
                func_ov009_0218aab0(self, (unsigned char)choice);
                if (self->flags & 0x200000) {
                    self->flags &= ~0x200000;
                    result = CreationInput_Confirm;
                }
                self->flags |= 0x100;
            }
            self->lastCursorX = self->cursorX;
            self->lastCursorY = self->cursorY;
        }
    } else if (g_touchInput.isRepeatValid_ && g_touchInput.currentReading_.isHeld) touched = 1;
    else if (g_touchInput.released_) touched = 1;
    if (!touched) {
        unsigned int ticks = GameState::GetInstance()->GetTickCount();
        if (!ticks) ticks = 1;
        int previous = self->navigation.row;
        if (func_0205bf58(&self->navigation, ticks))
            choice = GridCursor_GetSelectedIndex((Struct_0205bb84*)&self->navigation);
        if (self->state == CreationTab_NameEntry) {
            int rows = self->navigation.rows;
            int count = GetField0_0205bafc(&self->navigation);
            if (rows == 1 && count == 8) {
                if (choice >= self->furthestState[self->sex]) {
                    GridCursor_SetSelectedIndex(&self->navigation, self->furthestState[self->sex] - 1);
                    choice = self->furthestState[self->sex] - 1;
                }
                if (g_keyManager.TestKeysPressed(0x80)) {
                    RESET_NAVIGATION(11, 6, 66, self->keyboardChoice);
                    GridCursor_SetSelectedIndex(&self->navigation, self->navigation.column);
                    self->keyboardChoice = GridCursor_GetSelectedIndex((Struct_0205bb84*)&self->navigation);
                    self->flags |= 0x2000;
                    CharacterCreationUI_MoveCursorToSlot(self, GridCursor_GetSelectedIndex((Struct_0205bb84*)&self->navigation));
                    return CreationInput_None;
                }
                if (choice >= 0) { MOVE_CURSOR_TO_TAB_ICON(choice); }
                if (g_keyManager.TestKeysPressed(1)) {
                    result = GridCursor_GetSelectedIndex((Struct_0205bb84*)&self->navigation) + CreationInput_FirstTabIcon;
                    if (result - CreationInput_TabIcon <= self->furthestState[self->sex] && result - CreationInput_TabIcon != self->state)
                        SePlayer_Play(&g_sePlayer, 1, 0);
                } else if (g_keyManager.TestKeysPressed(2)) {
                    if (func_02001aec(self->names[self->sex], (const void*)GetFieldByKey020e0434(&self->texts, 0x4272), 10) == 0)
                        result = CreationInput_Back;
                    else {
                        func_ov009_0218b200(self, 0);
                        self->flags |= 0x8100;
                    }
                }
                return result;
            } else if (rows == 6) {
                if (g_keyManager.TestKeysPressed(0x40) && previous == 0) {
                    RESET_NAVIGATION(8, 1, 8, self->state - 1);
                    navigation->flags3c = 0;
                    MOVE_CURSOR_TO_TAB_ICON(self->state - 1);
                    self->flags |= 0x2000;
                    return CreationInput_None;
                }
                if (g_keyManager.TestKeysPressed(8)) {
                    func_ov009_0218ad0c(self);
                } else if (g_keyManager.TestKeysPressed(4)) {
                    func_ov009_0218b850(self);
                    self->flags |= 0x8100;
                } else if (g_keyManager.TestKeysPressed(1)) {
                    if (func_ov009_0218aab0(self, self->keyboardChoice) && self->nameFlags[self->sex] == 5) {
                        choice = 65;
                        GridCursor_SetSelectedIndex(&self->navigation, choice);
                    }
                    if (!(self->flags & 0x200000)) self->flags |= 0xa100;
                    else {
                        func_ov009_0218ad0c(self);
                        self->flags &= ~0x200000;
                    }
                } else if (g_keyManager.TestKeysPressed(2)) {
                    if (func_02001aec(self->names[self->sex], (const void*)GetFieldByKey020e0434(&self->texts, 0x4272), 10) == 0)
                        result = CreationInput_Back;
                    else {
                        func_ov009_0218b200(self, 0);
                        self->flags |= 0x8100;
                    }
                }
            }
        } else if (self->state != CreationTab_NameEntry) {
            int rows = self->navigation.rows;
            int count = GetField0_0205bafc(&self->navigation);
            if (rows == 1 && count == 8) {
                if (choice >= self->furthestState[self->sex]) {
                    GridCursor_SetSelectedIndex(&self->navigation, self->furthestState[self->sex] - 1);
                    choice = self->furthestState[self->sex] - 1;
                }
                if (g_keyManager.TestKeysPressed(0x80)) {
                    CharacterCreationUI_SetupSlotNavigation(self);
                    self->flags |= 0x2000;
                    CharacterCreationUI_MoveCursorToSlot(self, GridCursor_GetSelectedIndex((Struct_0205bb84*)&self->navigation));
                    return CreationInput_None;
                }
                if (choice >= 0) { MOVE_CURSOR_TO_TAB_ICON(choice); }
                if (g_keyManager.TestKeysPressed(1)) {
                    result = GridCursor_GetSelectedIndex((Struct_0205bb84*)&self->navigation) + CreationInput_FirstTabIcon;
                    if (result - CreationInput_TabIcon <= self->furthestState[self->sex] && result - CreationInput_TabIcon != self->state)
                        SePlayer_Play(&g_sePlayer, 1, 0);
                } else if (g_keyManager.TestKeysPressed(2)) result = CreationInput_Back;
                return result;
            }
            if (g_keyManager.TestKeysPressed(0x40) && previous == 0) {
                RESET_NAVIGATION(8, 1, 8, self->state - 1);
                navigation->flags3c = 0;
                MOVE_CURSOR_TO_TAB_ICON(self->state - 1);
                self->flags |= 0x2000;
                return CreationInput_None;
            }
            if (g_keyManager.TestKeysPressed(1)) {
                result = CreationInput_Confirm;
                SePlayer_Play(&g_sePlayer, 1, 0);
            } else if (g_keyManager.TestKeysPressed(2)) result = CreationInput_Back;
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
        case CreationTab_EyeColor: if (self->eyeColor[self->sex] != choice) self->flags |= CreationFlag_ChoiceChanged; self->eyeColor[self->sex] = choice; break;
        case CreationTab_SkinColor: if (self->skinColor[self->sex] != choice) self->flags |= CreationFlag_ChoiceChanged; self->skinColor[self->sex] = choice; break;
        case CreationTab_NameEntry: if (self->keyboardChoice != choice) self->flags |= CreationFlag_ChoiceChanged; self->keyboardChoice = choice; break;
        }
    }
    if (self->flags & CreationFlag_ChoiceChanged) {
        if (self->state != CreationTab_NameEntry || !touched) SePlayer_Play(&g_sePlayer, 2, 0);
        CharacterCreationUI_ApplyChoice(self, choice);
        if (self->state == CreationTab_Gender) {
            PartyMemberAppearance* appearance = &((PartyMemberData*)self->characterData)->appearance;
            self->flags |= 0x60000;
            unsigned char eyeColor = GetEyeColor(self);
            appearance->eyeColor = eyeColor;
            unsigned char skinColor = GetSkinColor(self);
            appearance->skinColor = skinColor;
            unsigned char hairColor = GetHairColor(self);
            appearance->hairColor = hairColor;
            appearance->models[2] = CharacterCreationUI_SlotToStyleIndex(self, 5, self->faceStyle[self->sex]) + 0x233c;
            appearance->models[3] = CharacterCreationUI_SlotToStyleIndex(self, 3, self->hairStyle[self->sex]) + 0x2328;
        }
        if (!touched) CharacterCreationUI_MoveCursorToSlot(self, choice);
        self->flags |= 0x6100;
    }
    return result;
}
#undef RESET_NAVIGATION
#undef MOVE_CURSOR_TO_TAB_ICON

#else
#include <globaldefs.h>
#include <GameState/GameState.h>
#include "Resource/CharacterCreationUI.h"

struct Struct_0205bef8;
struct Struct_0205ba68;
struct Struct_0205bb84;
struct Node0205bacc;
struct SePlayer;
void GridCursor_Init(Struct_0205bef8*);
void GridCursor_SetDimensions(Struct_0205ba68*, int, int, int);
void GridCursor_SetCount(Node0205bacc*, int);
int GetField0_0205bafc(void*);
int GridCursor_GetSelectedIndex(Struct_0205bb84*);
void SePlayer_Play(SePlayer*, int, int);

struct TouchState {
    char pad0[0x24];
    unsigned short pressure;
    char pad26[0x2e];
    unsigned char repeating;
    unsigned char pressed;
    char pad56[9];
    unsigned char held;
};
struct Navigation {
    int field0, field4, field8, rows, field10, field14, field18, selection;
    char pad20[0x18];
    unsigned short count;
    char pad3a[2];
    unsigned char field3c, field3d;
    char pad3e[2];
};
struct ChoiceList { void* entries; char pad4[0x14]; int selection; unsigned short counter; };
struct PartyMemberAppearance {
    short models[10];
    unsigned char female : 1;
    unsigned char eyeColor : 3;
    unsigned char skinColor : 4;
    unsigned char hairColor : 4;
    unsigned char unused : 4;
    short field16, width, height;
};
struct PartyMemberData { char pad0[0x488]; PartyMemberAppearance appearance; };
struct CharacterControls { char pad0[0x800]; Navigation navigation; };
struct CharacterCreation {
    char pad0[0xbc];
    void* savedEntries;
    ChoiceList* list;
    char padc4[0x3ec - 0xc4];
    CharacterControls controls;
    char grid[0x20];
    short cursorX, cursorY, cursorWidth, cursorHeight, lastX, lastY;
    signed char state;
    char padc59[0xd88 - 0xc59];
    PartyMemberData* member;
    int touchedChoice;
    char padd90[0xc];
    unsigned int flags;
    signed char maxSteps[3];
    unsigned char gender;
    unsigned char body[2], face[2], skin[2], eyes[2], hair[2], hairColor[2];
    char paddb0[5];
    unsigned char blocked;
};
extern SePlayer g_sePlayer;
extern "C" int func_ov009_02189854(CharacterCreation*, int, int);
extern "C" void GridCursor_SetSelectedIndex(Navigation*, int);
extern "C" int func_0205bf58(Navigation*, unsigned int);
extern "C" void CharacterCreationUI_SetupSlotNavigation(CharacterCreation*);
extern "C" void CharacterCreationUI_MoveCursorToSlot(CharacterCreation*, int);
extern "C" void CharacterCreationUI_ApplyChoice(CharacterCreation*, int);
extern "C" int CharacterCreationUI_SlotToStyleIndex(CharacterCreation*, int, int);

#define RESET_NAVIGATION(columns, rows, total, selected) \
    CharacterControls* controls = &self->controls; \
    GridCursor_Init((Struct_0205bef8*)&controls->navigation); \
    GridCursor_SetDimensions((Struct_0205ba68*)&controls->navigation, columns, rows, 1); \
    GridCursor_SetCount((Node0205bacc*)&controls->navigation, total); \
    controls->navigation.field4 = 1; \
    GridCursor_SetSelectedIndex(&controls->navigation, selected); \
    controls->navigation.field3d = 0

#define MOVE_CURSOR_TO_TAB_ICON(selected) \
    self->cursorX = ((selected) << 4) + 0x78; \
    self->cursorY = 8; \
    self->cursorWidth = 16; \
    self->cursorHeight = 16

static inline unsigned char GetEyeColor(CharacterCreation* self) { return self->eyes[self->gender]; }
static inline unsigned char GetSkinColor(CharacterCreation* self) { return self->skin[self->gender]; }
static inline unsigned char GetHairColor(CharacterCreation* self) { return self->hairColor[self->gender]; }

// Overlay 9, originally func_ov009_02188ee8 (USA/EUR 0x02188ee8, JPN 0x02189e04)
extern "C" ARM int CharacterCreationUI_HandleInput(CharacterCreation* self) {
    self->flags &= ~(CreationFlag_ConfirmTouched | CreationFlag_BackTouched);
    int result = CreationInput_None;
    int choice = -1;
    int x, y;
    g_touchInput.GetTouchPoint(&x, &y);
    int touched = 0;
    if (g_touchInput.pressed_) {
        touched = 1;
        choice = func_ov009_02189854(self, x, y);
        self->touchedChoice = choice;
        if ((unsigned int)(choice + 3) <= 1) {
            if (choice == CreationInput_Confirm) self->flags |= CreationFlag_ConfirmTouched;
            else if (choice == CreationInput_Back) self->flags |= CreationFlag_BackTouched;
            result = choice;
            SePlayer_Play(&g_sePlayer, 1, 0);
        } else if (choice >= CreationInput_FirstTabIcon && choice <= CreationInput_LastTabIcon) {
            result = choice;
            if (choice - CreationInput_TabIcon <= self->maxSteps[self->gender] && choice - CreationInput_TabIcon != self->state)
                SePlayer_Play(&g_sePlayer, 1, 0);
        } else if (choice >= 0) {
            GridCursor_SetSelectedIndex(&self->controls.navigation, choice);
            if (self->state == CreationTab_NameEntry) {
                if (self->flags & 0x200000) {
                    self->flags &= ~0x200000;
                    result = CreationInput_Confirm;
                }
                self->flags |= 0x100;
            }
            self->lastX = self->cursorX;
            self->lastY = self->cursorY;
        }
    } else if (g_touchInput.isRepeatValid_ && g_touchInput.currentReading_.isHeld) touched = 1;
    else if (g_touchInput.released_) touched = 1;
    if (!touched) {
        unsigned int ticks = GameState::GetInstance()->GetTickCount();
        if (!ticks) ticks = 1;
        int previous = self->controls.navigation.selection;
        if (func_0205bf58(&self->controls.navigation, ticks)) choice = GridCursor_GetSelectedIndex((Struct_0205bb84*)&self->controls.navigation);
        if (self->state == CreationTab_NameEntry) {
            int rows = self->controls.navigation.rows;
            int count = GetField0_0205bafc(&self->controls.navigation);
            if (rows == 1 && count == 8) {
                if (choice >= self->maxSteps[self->gender]) {
                    GridCursor_SetSelectedIndex(&self->controls.navigation, self->maxSteps[self->gender] - 1);
                    choice = self->maxSteps[self->gender] - 1;
                }
                if (g_keyManager.TestKeysPressed(0x80)) {
                    RESET_NAVIGATION(11, 6, 66, 0);
                    self->flags |= 0x2000;
                    if (self->savedEntries) self->list->entries = self->savedEntries;
                    self->list->selection = 0;
                    self->list->counter = 0;
                    return CreationInput_None;
                }
                if (choice >= 0) { MOVE_CURSOR_TO_TAB_ICON(choice); }
                if (g_keyManager.TestKeysPressed(1)) {
                    result = GridCursor_GetSelectedIndex((Struct_0205bb84*)&self->controls.navigation) + CreationInput_FirstTabIcon;
                    if (result - CreationInput_TabIcon <= self->maxSteps[self->gender] && result - CreationInput_TabIcon != self->state)
                        SePlayer_Play(&g_sePlayer, 1, 0);
                }
                return result;
            }
            if (!self->blocked && g_keyManager.TestKeysPressed(0x40)) {
                self->savedEntries = self->list->entries;
                self->list->entries = 0;
                RESET_NAVIGATION(8, 1, 8, self->state - 1);
                controls->navigation.field3c = 0;
                MOVE_CURSOR_TO_TAB_ICON(self->state - 1);
            }
        } else if (self->state != CreationTab_NameEntry) {
            int rows = self->controls.navigation.rows;
            int count = GetField0_0205bafc(&self->controls.navigation);
            if (rows == 1 && count == 8) {
                if (choice >= self->maxSteps[self->gender]) {
                    GridCursor_SetSelectedIndex(&self->controls.navigation, self->maxSteps[self->gender] - 1);
                    choice = self->maxSteps[self->gender] - 1;
                }
                if (g_keyManager.TestKeysPressed(0x80)) {
                    CharacterCreationUI_SetupSlotNavigation(self);
                    self->flags |= 0x2000;
                    CharacterCreationUI_MoveCursorToSlot(self, GridCursor_GetSelectedIndex((Struct_0205bb84*)&self->controls.navigation));
                    return CreationInput_None;
                }
                if (choice >= 0) { MOVE_CURSOR_TO_TAB_ICON(choice); }
                if (g_keyManager.TestKeysPressed(1)) {
                    result = GridCursor_GetSelectedIndex((Struct_0205bb84*)&self->controls.navigation) + CreationInput_FirstTabIcon;
                    if (result - CreationInput_TabIcon <= self->maxSteps[self->gender] && result - CreationInput_TabIcon != self->state)
                        SePlayer_Play(&g_sePlayer, 1, 0);
                } else if (g_keyManager.TestKeysPressed(2)) result = CreationInput_Back;
                if (result == CreationInput_TabIcon + CreationTab_NameEntry) GridCursor_SetDimensions((Struct_0205ba68*)&self->controls.navigation, 11, 6, 0);
                return result;
            }
            if (g_keyManager.TestKeysPressed(0x40) && previous == 0) {
                RESET_NAVIGATION(8, 1, 8, self->state - 1);
                controls->navigation.field3c = 0;
                MOVE_CURSOR_TO_TAB_ICON(self->state - 1);
                self->flags |= 0x2000;
                return CreationInput_None;
            }
            if (g_keyManager.TestKeysPressed(1)) {
                result = CreationInput_Confirm;
                SePlayer_Play(&g_sePlayer, 1, 0);
            } else if (g_keyManager.TestKeysPressed(2)) result = CreationInput_Back;
        }
    }
    self->flags &= ~CreationFlag_ChoiceChanged;
    if (choice >= 0 && !(choice >= CreationInput_FirstTabIcon && choice <= CreationInput_LastTabIcon)) {
        unsigned char* genderValue = &self->gender;
        switch (self->state) {
        case CreationTab_NameEntry: break;
        case CreationTab_Gender: { if (*genderValue != choice) self->flags |= CreationFlag_ChoiceChanged; *genderValue = choice; break; }
        case CreationTab_BodyType: { unsigned char* values = self->body; int gender = self->gender; unsigned char prior = values[gender]; if (prior != choice) self->flags |= CreationFlag_ChoiceChanged; values[gender] = choice; break; }
        case CreationTab_HairStyle: { unsigned char* values = self->hair; int gender = self->gender; unsigned char prior = values[gender]; if (prior != choice) self->flags |= CreationFlag_ChoiceChanged; values[gender] = choice; break; }
        case CreationTab_HairColor: { unsigned char* values = self->hairColor; int gender = self->gender; unsigned char prior = values[gender]; if (prior != choice) self->flags |= CreationFlag_ChoiceChanged; values[gender] = choice; break; }
        case CreationTab_Face: { unsigned char* values = self->face; int gender = self->gender; unsigned char prior = values[gender]; if (prior != choice) self->flags |= CreationFlag_ChoiceChanged; values[gender] = choice; break; }
        case CreationTab_EyeColor: { unsigned char* values = self->eyes; int gender = self->gender; unsigned char prior = values[gender]; if (prior != choice) self->flags |= CreationFlag_ChoiceChanged; values[gender] = choice; break; }
        case CreationTab_SkinColor: { unsigned char* values = self->skin; int gender = self->gender; unsigned char prior = values[gender]; if (prior != choice) self->flags |= CreationFlag_ChoiceChanged; values[gender] = choice; break; }
        }
    }
    if (self->flags & CreationFlag_ChoiceChanged) {
        if (self->state != CreationTab_NameEntry || !touched) SePlayer_Play(&g_sePlayer, 2, 0);
        CharacterCreationUI_ApplyChoice(self, choice);
        if (self->state == CreationTab_Gender) {
            PartyMemberAppearance* appearance = &self->member->appearance;
            self->flags |= 0x60000;
            unsigned char eyeColor = GetEyeColor(self);
            appearance->eyeColor = eyeColor;
            unsigned char skinColor = GetSkinColor(self);
            appearance->skinColor = skinColor;
            unsigned char hairColor = GetHairColor(self);
            appearance->hairColor = hairColor;
            appearance->models[2] = CharacterCreationUI_SlotToStyleIndex(self, 5, self->face[self->gender]) + 0x233c;
            appearance->models[3] = CharacterCreationUI_SlotToStyleIndex(self, 3, self->hair[self->gender]) + 0x2328;
        }
        if (!touched) CharacterCreationUI_MoveCursorToSlot(self, choice);
        self->flags |= 0x6100;
    }
    if (result == CreationInput_TabIcon + CreationTab_NameEntry && result - CreationInput_TabIcon <= self->maxSteps[self->gender] && result - CreationInput_TabIcon != self->state)
        GridCursor_SetDimensions((Struct_0205ba68*)&self->controls.navigation, 11, 6, 0);
    return result;
}

#endif
