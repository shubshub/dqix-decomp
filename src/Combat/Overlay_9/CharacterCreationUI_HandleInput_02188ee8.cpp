#include "Input/Input.h"

#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/CharacterCreationUI.h"

struct Struct_0205bef8;
struct Struct_0205ba68;
struct Struct_0205bb84;
struct Node0205bacc;
struct Obj0205eaa0;
void Init0205bef8(Struct_0205bef8*);
void SetupPointerTable0205ba68(Struct_0205ba68*, int, int, int);
void SetField0AndPropagate0205bacc(Node0205bacc*, int);
int GetField0_0205bafc(void*);
int GridCursor_GetSelectedIndex(Struct_0205bb84*);
void DispatchWithShortB4_0205eaa0(Obj0205eaa0*, int, int);
int GetFieldByKey020e0434(Container020e0310*, int);
extern "C" int func_02001aec(const void*, const void*, unsigned int);
extern "C" int func_ov009_0218a8b4(Struct_ov009_021842a0*, int, int);
extern "C" int func_ov009_0218aab0(Struct_ov009_021842a0*, unsigned char);
extern "C" void func_ov009_0218ad0c(void*);
extern "C" void func_ov009_0218b200(CharacterCreationUI*, int);
extern "C" void func_ov009_0218b850(CharacterCreationUI*);
extern "C" void func_0205bb04(CreationNavigation*, int);
extern "C" int func_0205bf58(CreationNavigation*, unsigned int);
extern "C" void CharacterCreationUI_SetupSlotNavigation(CharacterCreationUI*);
extern "C" void CharacterCreationUI_MoveCursorToSlot(CharacterCreationUI*, int);
extern "C" void CharacterCreationUI_ApplyChoice(CharacterCreationUI*, int);
extern "C" int CharacterCreationUI_SlotToStyleIndex(CharacterCreationUI*, int, int);

struct Struct_ov009_02187b34 {
    short unknown_0_[10];
    unsigned char unknown_14_0_ : 1;
    unsigned char unknown_14_1_ : 3;
    unsigned char unknown_14_4_ : 4;
    unsigned char unknown_15_0_ : 4;
    unsigned char unknown_15_4_ : 4;
    short unknown_16_, unknown_18_, unknown_1a_;
};
struct Struct_ov005_0215840c_2 { char unknown_0_[0x488]; Struct_ov009_02187b34 unknown_488_; };
extern Struct_02108760 data_02108760;

#define RESET_NAVIGATION(columns, rows, total, selected) \
    Struct_ov009_02188c2c* navigation = &arg0->unknown_bec_; \
    func_0205bef8((Struct_0205bef8*)navigation); \
    func_0205ba68((Struct_0205ba68*)navigation, columns, rows, 1); \
    func_0205bacc((Struct_0205bacc*)navigation, total); \
    navigation->unknown_4_ = 1; \
    func_0205bb04(navigation, selected); \
    navigation->unknown_3d_ = 0

#define MOVE_CURSOR_TO_TAB_ICON(selected) \
    self->cursorX = ((selected) << 4) + 0x78; \
    self->cursorY = 8; \
    self->cursorWidth = 16; \
    self->cursorHeight = 16

static inline unsigned char inline_ov009_02188ee8(Struct_ov009_021842a0* arg0) { return arg0->unknown_daa_[arg0->unknown_da3_]; }
static inline unsigned char inline_ov009_02188ee8_2(Struct_ov009_021842a0* arg0) { return arg0->unknown_da8_[arg0->unknown_da3_]; }
static inline unsigned char inline_ov009_02188ee8_3(Struct_ov009_021842a0* arg0) { return arg0->unknown_dae_[arg0->unknown_da3_]; }

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
            DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
        } else if (choice >= CreationInput_FirstTabIcon && choice <= CreationInput_LastTabIcon) {
            result = choice;
            if (choice - CreationInput_TabIcon <= self->furthestState[self->sex] && choice - CreationInput_TabIcon != self->state)
                DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
        } else if (choice >= 0) {
            func_0205bb04(&self->navigation, choice);
            if (self->state == CreationTab_NameEntry) {
                func_ov009_0218aab0(self, (unsigned char)choice);
                if (self->flags & 0x200000) {
                    self->flags &= ~0x200000;
                    result = CreationInput_Confirm;
                }
                arg0->unknown_d9c_ |= 0x100;
            }
            arg0->unknown_c54_ = arg0->unknown_c4c_;
            arg0->unknown_c56_ = arg0->unknown_c4e_;
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
                    func_0205bb04(&self->navigation, self->furthestState[self->sex] - 1);
                    choice = self->furthestState[self->sex] - 1;
                }
                if (g_keyManager.TestKeysPressed(0x80)) {
                    RESET_NAVIGATION(11, 6, 66, self->keyboardChoice);
                    func_0205bb04(&self->navigation, self->navigation.column);
                    self->keyboardChoice = GridCursor_GetSelectedIndex((Struct_0205bb84*)&self->navigation);
                    self->flags |= 0x2000;
                    CharacterCreationUI_MoveCursorToSlot(self, GridCursor_GetSelectedIndex((Struct_0205bb84*)&self->navigation));
                    return CreationInput_None;
                }
                if (choice >= 0) { MOVE_CURSOR_TO_TAB_ICON(choice); }
                if (g_keyManager.TestKeysPressed(1)) {
                    result = GridCursor_GetSelectedIndex((Struct_0205bb84*)&self->navigation) + CreationInput_FirstTabIcon;
                    if (result - CreationInput_TabIcon <= self->furthestState[self->sex] && result - CreationInput_TabIcon != self->state)
                        DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
                } else if (g_keyManager.TestKeysPressed(2)) {
                    if (func_02001aec(self->names[self->sex], (const void*)GetFieldByKey020e0434(&self->texts, 0x4272), 10) == 0)
                        result = CreationInput_Back;
                    else {
                        func_ov009_0218b200(arg0, 0);
                        arg0->unknown_d9c_ |= 0x8100;
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
                    func_ov009_0218ad0c(arg0);
                } else if (g_keyManager.TestKeysPressed(4)) {
                    func_ov009_0218b850(arg0);
                    arg0->unknown_d9c_ |= 0x8100;
                } else if (g_keyManager.TestKeysPressed(1)) {
                    if (func_ov009_0218aab0(arg0, arg0->unknown1_d8c_) && arg0->unknown_d8a_[arg0->unknown_da3_] == 5) {
                        var1 = 65;
                        func_0205bb04(&arg0->unknown_bec_, var1);
                    }
                    if (!(arg0->unknown_d9c_ & 0x200000)) arg0->unknown_d9c_ |= 0xa100;
                    else {
                        func_ov009_0218ad0c(arg0);
                        arg0->unknown_d9c_ &= ~0x200000;
                    }
                } else if (g_keyManager.TestKeysPressed(2)) {
                    if (func_02001aec(self->names[self->sex], (const void*)GetFieldByKey020e0434(&self->texts, 0x4272), 10) == 0)
                        result = CreationInput_Back;
                    else {
                        func_ov009_0218b200(arg0, 0);
                        arg0->unknown_d9c_ |= 0x8100;
                    }
                }
            }
        } else if (self->state != CreationTab_NameEntry) {
            int rows = self->navigation.rows;
            int count = GetField0_0205bafc(&self->navigation);
            if (rows == 1 && count == 8) {
                if (choice >= self->furthestState[self->sex]) {
                    func_0205bb04(&self->navigation, self->furthestState[self->sex] - 1);
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
                        DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
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
                DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
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
        if (self->state != CreationTab_NameEntry || !touched) DispatchWithShortB4_0205eaa0(&data_02108760, 2, 0);
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
    return var0;
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
struct Obj0205eaa0;
void Init0205bef8(Struct_0205bef8*);
void SetupPointerTable0205ba68(Struct_0205ba68*, int, int, int);
void SetField0AndPropagate0205bacc(Node0205bacc*, int);
int GetField0_0205bafc(void*);
int GridCursor_GetSelectedIndex(Struct_0205bb84*);
void DispatchWithShortB4_0205eaa0(Obj0205eaa0*, int, int);

struct Struct_02000c9c_93 {
    char unknown_0_[0x24];
    unsigned short unknown_24_;
    char unknown_26_[0x2e];
    unsigned char unknown_54_;
    unsigned char unknown_55_;
    char unknown_56_[9];
    unsigned char unknown_5f_;
};
struct Struct_ov009_02188ee8 {
    int unknown_0_, unknown_4_, unknown_8_, unknown_c_, unknown_10_, unknown_14_, unknown_18_, unknown_1c_;
    char unknown_20_[0x18];
    unsigned short unknown_38_;
    char unknown_3a_[2];
    unsigned char unknown_3c_, unknown_3d_;
    char unknown_3e_[2];
};
struct Struct_ov009_02188ee8_2 { void* unknown_0_; char unknown_4_[0x14]; int unknown_18_; unsigned short unknown_1c_; };
struct Struct_ov009_02187b34 {
    short unknown_0_[10];
    unsigned char unknown_14_0_ : 1;
    unsigned char unknown_14_1_ : 3;
    unsigned char unknown_14_4_ : 4;
    unsigned char unknown_15_0_ : 4;
    unsigned char unknown_15_4_ : 4;
    short unknown_16_, unknown_18_, unknown_1a_;
};
struct Struct_ov005_0215840c_2 { char unknown_0_[0x488]; Struct_ov009_02187b34 unknown_488_; };
struct Struct_ov009_02188ee8_3 { char unknown_0_[0x800]; Struct_ov009_02188ee8 unknown_800_; };
struct Struct_ov009_021842a0_2 {
    char unknown_0_[0xbc];
    void* unknown_bc_;
    Struct_ov009_02188ee8_2* unknown_c0_;
    char unknown_c4_[0x3ec - 0xc4];
    Struct_ov009_02188ee8_3 unknown_3ec_;
    char unknown_c2c_[0x20];
    short unknown_c4c_, unknown_c4e_, unknown_c50_, unknown_c52_, unknown_c54_, unknown_c56_;
    signed char unknown_c58_;
    char unknown_c59_[0xd88 - 0xc59];
    Struct_ov005_0215840c_2* unknown_d88_;
    int unknown_d8c_;
    char unknown_d90_[0xc];
    unsigned int unknown_d9c_;
    signed char unknown_da0_[3];
    unsigned char unknown_da3_;
    unsigned char unknown_da4_[2], unknown_da6_[2], unknown_da8_[2], unknown_daa_[2], unknown_dac_[2], unknown_dae_[2];
    char unknown_db0_[5];
    unsigned char unknown_db5_;
};
extern Obj0205eaa0 data_02108760;
extern "C" int func_ov009_02189854(CharacterCreation*, int, int);
extern "C" void func_0205bb04(Navigation*, int);
extern "C" int func_0205bf58(Navigation*, unsigned int);
extern "C" void CharacterCreationUI_SetupSlotNavigation(CharacterCreation*);
extern "C" void CharacterCreationUI_MoveCursorToSlot(CharacterCreation*, int);
extern "C" void CharacterCreationUI_ApplyChoice(CharacterCreation*, int);
extern "C" int CharacterCreationUI_SlotToStyleIndex(CharacterCreation*, int, int);

#define RESET_NAVIGATION(columns, rows, total, selected) \
    Struct_ov009_02188ee8_3* controls = &arg0->unknown_3ec_; \
    func_0205bef8((Struct_0205bef8*)&controls->unknown_800_); \
    func_0205ba68((Struct_0205ba68*)&controls->unknown_800_, columns, rows, 1); \
    func_0205bacc((Struct_0205bacc*)&controls->unknown_800_, total); \
    controls->unknown_800_.unknown_4_ = 1; \
    func_0205bb04(&controls->unknown_800_, selected); \
    controls->unknown_800_.unknown_3d_ = 0

#define MOVE_CURSOR_TO_TAB_ICON(selected) \
    self->cursorX = ((selected) << 4) + 0x78; \
    self->cursorY = 8; \
    self->cursorWidth = 16; \
    self->cursorHeight = 16

static inline unsigned char inline_ov009_02188ee8(Struct_ov009_021842a0_2* arg0) { return arg0->unknown_daa_[arg0->unknown_da3_]; }
static inline unsigned char inline_ov009_02188ee8_2(Struct_ov009_021842a0_2* arg0) { return arg0->unknown_da8_[arg0->unknown_da3_]; }
static inline unsigned char inline_ov009_02188ee8_3(Struct_ov009_021842a0_2* arg0) { return arg0->unknown_dae_[arg0->unknown_da3_]; }

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
            DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
        } else if (choice >= CreationInput_FirstTabIcon && choice <= CreationInput_LastTabIcon) {
            result = choice;
            if (choice - CreationInput_TabIcon <= self->maxSteps[self->gender] && choice - CreationInput_TabIcon != self->state)
                DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
        } else if (choice >= 0) {
            func_0205bb04(&self->controls.navigation, choice);
            if (self->state == CreationTab_NameEntry) {
                if (self->flags & 0x200000) {
                    self->flags &= ~0x200000;
                    result = CreationInput_Confirm;
                }
                arg0->unknown_d9c_ |= 0x100;
            }
            arg0->unknown_c54_ = arg0->unknown_c4c_;
            arg0->unknown_c56_ = arg0->unknown_c4e_;
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
                    func_0205bb04(&self->controls.navigation, self->maxSteps[self->gender] - 1);
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
                        DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
                }
                return var15;
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
                    func_0205bb04(&self->controls.navigation, self->maxSteps[self->gender] - 1);
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
                        DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
                } else if (g_keyManager.TestKeysPressed(2)) result = CreationInput_Back;
                if (result == CreationInput_TabIcon + CreationTab_NameEntry) SetupPointerTable0205ba68((Struct_0205ba68*)&self->controls.navigation, 11, 6, 0);
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
                DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
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
        if (self->state != CreationTab_NameEntry || !touched) DispatchWithShortB4_0205eaa0(&data_02108760, 2, 0);
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
        SetupPointerTable0205ba68((Struct_0205ba68*)&self->controls.navigation, 11, 6, 0);
    return result;
}

#endif
