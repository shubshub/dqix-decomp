#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/CharacterCreationUI.h"
#include "Resource/Keyboard.h"
#include "Combat/ResourceScriptEntry.h"
#include "Filesystem/BackgroundLoader.h"
#include "NitroSDK/ColorEffects.h"
#include "NitroSDK/Graphics.h"
#include "Resource/Brightness.h"
#include "Sound/SePlayer.h"
#include "Util/Random.h"
#include "std_library_functions.h"
#include "Input/Input.h"

#define REG_BLDCNT_SUB 0x04001050

enum
{
    Vocation_Count = 13, // experience, levels and the spell table's rows are indexed by vocation
    SpellTable_SpellsPerVocation = 20,
    EquipmentFromAppearance_Count = 7,
    BackgroundMap_Columns = 32, // Background_FillRect clips to a 32 x 25 tile map
    BackgroundMap_Rows = 25,
};

struct PackedStats0218742c {
    unsigned int first : 10;
    unsigned int second : 10;
    unsigned int third : 10;
    unsigned int reserved : 2;
    void SetFirst(int value) { first = value; }
};
struct ItemRecord { char bytes[32]; };
struct PartyMemberAppearance {
    short models[10];
    unsigned char unk_14[4];
    short width;
    short height;
};
struct PartyMemberData {
    PackedStats0218742c stats[4];
    char unk_10[0x5c];
    unsigned short unk_6c;
    unsigned short unk_6e;
    unsigned short unk_70;
    unsigned short unk_72;
    char unk_74[0xc4];
    int experience[Vocation_Count];
    unsigned short levels[Vocation_Count];
    char unk_186[0xe];
    ItemRecord equipment[11];
    char unk_2f4[0x194];
    PartyMemberAppearance appearance;
    char unk_4a4[0xc6];
    unsigned char bareBodyColor;
#if defined(jpn)
    char unk_56b[0x34d];
#else
    char unk_56b[0x3e5];
#endif
    int unknown_950_;
};
struct AppearanceEquipment {
    unsigned char appearanceSlot;
    unsigned char equipmentSlot;
    unsigned char padding[5];
};
struct Snapshot0218742c { char field_0[0x14c]; PackedStats0218742c stats[5]; char field_160[0xdc]; };
struct SpellTableEntry { unsigned short spell; unsigned short level; };
struct SpellTable {
    char unk_0[0x10c];
    SpellTableEntry spells[Vocation_Count][SpellTable_SpellsPerVocation];
    char unk_51c[0x34];
};
struct Keyboard {
    KeyboardKey* key_;
    char unk_4[0x1a];
    unsigned char page_;
    char unk_1f;
    unsigned char shift_;
    void SetPage(unsigned char value) { page_ = value; }
    void SetShift(unsigned char value) { shift_ = value; }
};
struct CharacterCreation {
#if defined(jpn)
    char unk_0[0xa8];
#else
    char unk_0[0xc0];
    Keyboard* keyboard;
    void* keyboardLayout;
#endif
    unsigned char itemTable[0x18];
#if defined(jpn)
    char unk_c0[0xfc - 0xc0];
#else
    char unk_e0[0x138 - 0xe0];
#endif
    CreationTileMap layers[6];
    CreationWindow windows[2];
    char unk_370[0xc59 - 0x370];
    unsigned char step;
    char unk_c5a[0xd84 - 0xc5a];
    signed char selection;
    unsigned char windowInput;
    char unk_d86[2];
    PartyMemberData* characterData;
    char unk_d8c[0xd95 - 0xd8c];
    unsigned char mode;
    char unk_d96[0xd9c - 0xd96];
    unsigned int flags;
    signed char furthestState[2];
    unsigned char vocation;
    unsigned char sex;
    char unk_da4[0xda8 - 0xda4];
    unsigned char eyeColor[2];
};

// windows[1]'s Yes/No menu, in the order CharacterCreationUI_WriteYesNoText writes texts 0x465a ("Yes") and 0x465b ("No").
enum ConfirmChoice
{
    ConfirmChoice_Yes = 0,
    ConfirmChoice_No = 1,
};

#if !defined(jpn)
// CharacterCreationUI_HandleNameEntry's steps (usa): Start skips the keyboard's setup.
enum NameEntryStep
{
    NameEntryStep_Setup = 0,
    NameEntryStep_Start = 1,
};
#endif

struct Struct_0205d81c; struct Struct_0205c570; struct Obj_0205da38;
struct Entry_0205d6a0; struct Obj0204b010; struct Cont0205d1e0; struct Cont0205d228;
struct Cont0205d274; struct Obj0205d2bc; struct Container020dedd0; struct Ctx0209a810;
void* GetDataPtr02114e04_020d6c00();
extern "C" void CharacterCreationUI_OpenYesNoWindow(CharacterCreation*);
void SetElementFieldC2_0205deb4(Struct_0205d81c*, int, int);
int Window_GetSelectedIndex(Struct_0205c570*);
int Window_IsSelectionTouched(Obj_0205da38*, int);
void ResetEntryList0205d6a0(Entry_0205d6a0*, int);
void Background_ClearMap(Obj0204b010*, void*);
extern "C" void Background_FillRect(void*, int, int, int, int, int, int);
extern "C" void Background_FlushMap(void*, int);
extern "C" void Background_TransferMap(void*, int);
void Window_ClearLayers(Cont0205d1e0*);
void Window_DrawPanes(Cont0205d228*);
void Window_FlushLayers(Cont0205d274*);
void Window_TransferLayers(Obj0205d2bc*);
void CharacterCreationUI_SwitchTab(unsigned char*, int);
extern "C" void func_02086404(Snapshot0218742c*);
void PartyMember_SetVocation(unsigned char*, int);
extern "C" int sprintf(char*, const char*, ...);
extern "C" void func_0208247c(void*);
void* LoadFileIntoMemory(const char*, void*, unsigned int*);
extern "C" void PartyMember_ApplyLevelStats(void*, void*, void*);
void* FindElementByKey020dedd0(Container020dedd0*, int);
extern "C" void func_02083e28(void*, int);
void ResetAndCopyShorts0x1c_020863c4(unsigned char*);
void ClearField00209a804(int*);
void SpellTable_Load(Ctx0209a810*, void*);
void PartyMember_LearnSpell(unsigned char*, int);
extern "C" void func_020830cc(void*, Snapshot0218742c*);
extern "C" void func_02086778(void*, Snapshot0218742c*, unsigned char, unsigned char);
extern "C" KeyboardKey* Keyboard_FindKeyByText(Keyboard*, const char*);
extern unsigned char CharacterCreationUI_bareBodyColors[];
extern char CharacterCreationUI_levelFileFormat[];
extern char data_0211e33c[] __attribute__((aligned(4)));
extern AppearanceEquipment CharacterCreationUI_equipmentFromAppearance[];
extern char CharacterCreationUI_firstKeyText[];

inline Struct_ov009_0218742c_7* inline_ov009_0218742c_4(Struct_ov009_0218742c* arg0) { return arg0->unknown_14c_; }

// Overlay 9, originally func_ov009_0218742c (USA/EUR 0x0218742c, JPN 0x021881fc)
extern "C" ARM void CharacterCreationUI_HandleConfirm(CharacterCreation* self) {
    GameState* gameState = GameState::GetInstance();
    GetDataPtr02114e04_020d6c00();
    unsigned int step = self->step;
    if (step == ConfirmStep_Open) {
        CharacterCreationUI_OpenYesNoWindow(self);
        SetElementFieldC2_0205deb4((Struct_0205d81c*)&self->windows[1], 3, 2);
        SePlayer_Play(&g_sePlayer, 5, 0);
        ++self->step;
    } else if (step == ConfirmStep_Show) {
        self->flags |= CreationFlag_RedrawPanel;
        ColorEffect_ConfigureBrightnessAdjust(REG_BLDCNT_SUB, BLEND_TARGET_BG0, Brightness_Black / 2);
        self->flags &= ~CreationFlag_HideButtons;
        ++self->step;
    } else if (step == ConfirmStep_Input) {
        self->selection = Window_GetSelectedIndex((Struct_0205c570*)&self->windows[1]);
        int declined = 0;
        int touched = Window_IsSelectionTouched((Obj_0205da38*)&self->windows[1], 0x14);
        int pressedA = g_keyManager.TestKeysPressed(KEY_A);
        int pressedX = g_keyManager.TestKeysPressed(KEY_X);
        if (touched | (pressedA | pressedX)) {
            SePlayer_Play(&g_sePlayer, SoundEffect_Select, 0);
            switch (self->selection) {
            case ConfirmChoice_Yes: ++self->step; break;
            case ConfirmChoice_No: declined = 1; break;
            }
        } else if (g_keyManager.TestKeysPressed(KEY_B)) declined = 1;
        if (self->step == ConfirmStep_Accept) {
            ResetEntryList0205d6a0((Entry_0205d6a0*)&self->windows[1], 0);
            SetElementFieldC2_0205deb4((Struct_0205d81c*)&self->windows[1], 3, 2);
#if defined(jpn)
            self->flags &= ~CreationFlag_ConfirmTouched;
            self->flags &= ~CreationFlag_BackTouched;
#else
            self->flags &= ~(CreationFlag_BackTouched | CreationFlag_ConfirmTouched);
#endif
        } else if (declined) {
            ResetEntryList0205d6a0((Entry_0205d6a0*)&self->windows[1], 0);
#if defined(jpn)
            self->flags &= ~CreationFlag_ConfirmTouched;
            self->flags &= ~CreationFlag_BackTouched;
#else
            self->flags &= ~(CreationFlag_BackTouched | CreationFlag_ConfirmTouched);
#endif
            self->step = ConfirmStep_Decline;
        }
    } else if (step == ConfirmStep_Accept) {
        Background_ClearMap((Obj0204b010*)&self->layers[4], 0);
        Background_FillRect(&self->layers[4], 0, 0, 0, BackgroundMap_Columns, BackgroundMap_Rows, 0);
        Background_FlushMap(&self->layers[4], 0);
        Background_TransferMap(&self->layers[4], 0);
        if (self->mode == CreationMode_NewGame) {
            PartyMemberData* member = self->characterData;
            member->bareBodyColor = CharacterCreationUI_bareBodyColors[self->eyeColor[self->sex]];
            gameState->characterCreated_ = 1;
            ColorEffect_ConfigureBrightnessAdjust(REG_BLDCNT_SUB, BLEND_TARGET_BG0, Brightness_Normal);
            SetElementFieldC2_0205deb4((Struct_0205d81c*)&self->windows[1], 3, 0);
            Window_ClearLayers((Cont0205d1e0*)&self->windows[1]);
            Window_DrawPanes((Cont0205d228*)&self->windows[1]);
            Window_FlushLayers((Cont0205d274*)&self->windows[1]);
            Window_TransferLayers((Obj0205d2bc*)&self->windows[1]);
            CharacterCreationUI_SwitchTab((unsigned char*)self, CreationTab_NewGameFinish);
#if defined(jpn)
        } else if (self->mode == CreationMode_PartyMemberCreation) {
            void* members = GetPtrField0x2a04_02010828(gameState);
            Snapshot0218742c snapshot;
            func_02086404(&snapshot);
            PartyMember_SetVocation((unsigned char*)self->characterData, self->vocation);
            self->characterData->experience[self->vocation] = 0;
            self->characterData->levels[self->vocation] = 1;
            self->characterData->bareBodyColor = NextRandomMax(GetBTRandom(), 16);
            char filename[32];
            int memberVocation = self->characterData->vocation;
            sprintf(filename, CharacterCreationUI_levelFileFormat, memberVocation);
            ResourceScriptEntry levelStats;
            Clear0x54Bytes0208247c(&levelStats);
            BackgroundLoader::AddLockGlobal();
            unsigned int fileSize;
            void* file = LoadFileIntoMemory(filename, data_0211e33c, &fileSize);
            if (file) func_02082490(&levelStats, file, fileSize, self->characterData->levels[self->vocation], 0);
            PartyMember_ApplyLevelStats(self->characterData, &levelStats, levelStats.variants);
            BackgroundLoader::RemoveLockGlobal();
            short* models = self->characterData->appearance.models;
            for (int i = 0; i < EquipmentFromAppearance_Count; ++i) {
                void* item = FindElementByKey020dedd0((Container020dedd0*)self->itemTable, models[CharacterCreationUI_equipmentFromAppearance[i].appearanceSlot]);
                if (item) memcpy(&self->characterData->equipment[CharacterCreationUI_equipmentFromAppearance[i].equipmentSlot], item, sizeof(ItemRecord));
            }
            func_02083e28(self->characterData, 0);
            ResetAndCopyShorts0x1c_020863c4((unsigned char*)self->characterData);
            PackedStats0218742c* stats = SnapshotStats(&snapshot);
            PartyMemberData* member = self->characterData;
            stats[0].first = member->stats[0].first;
            stats[0].second = member->stats[0].second;
            stats[0].third = member->stats[0].third;
            stats[1].first = member->stats[1].first;
            stats[1].second = member->stats[1].second;
            stats[1].third = member->stats[1].third;
            stats[2].first = member->stats[2].first;
            stats[2].second = member->unk_6c;
            stats[2].third = member->unk_6e;
            stats[3].SetFirst(member->unk_6c);
            stats[3].second = member->unk_6e;
            stats[3].third = member->unk_70;
            stats[4].first = member->unk_72;
            stats[4].second = member->stats[3].first;
            int loadContext;
            ClearField00209a804(&loadContext);
            SpellTable spellTable;
            SpellTable_Load((Ctx0209a810*)&loadContext, &spellTable);
            unsigned char vocation = self->characterData->vocation;
            unsigned char level = self->characterData->levels[self->characterData->vocation];
            SpellTableEntry* spells = spellTable.spells[vocation];
            for (int i = 0; i < SpellTable_SpellsPerVocation; ++i) {
                if (level >= spells[i].level && spells[i].level != 0)
                    PartyMember_LearnSpell((unsigned char*)self->characterData, spells[i].spell);
            }
            func_020830cc(self->characterData, &snapshot);
            func_02086778(members, &snapshot, 0, 0);
            self->flags |= CreationFlag_MemberCreated;
            CharacterCreationUI_SwitchTab((unsigned char*)self, CreationTab_Close);
        }
#else
        } else if (self->mode == CreationMode_PartyMemberCreation) {
            PartyMemberData* member = self->characterData;
            void* members = GetPtrField0x2a04_02010828(gameState);
            Snapshot0218742c snapshot;
            func_02086404(&snapshot);
            PartyMember_SetVocation((unsigned char*)member, self->vocation);
            member->experience[self->vocation] = 0;
            member->levels[self->vocation] = 1;
            member->bareBodyColor = NextRandomMax(GetBTRandom(), 16);
            char filename[32];
            int memberVocation = member->vocation;
            sprintf(filename, CharacterCreationUI_levelFileFormat, memberVocation);
            ResourceScriptEntry levelStats;
            Clear0x54Bytes0208247c(&levelStats);
            BackgroundLoader::AddLockGlobal();
            unsigned int fileSize;
            void* file = LoadFileIntoMemory(filename, data_0211e33c, &fileSize);
            if (file) func_02082490(&levelStats, file, fileSize, member->levels[self->vocation], 0);
            PartyMember_ApplyLevelStats(member, &levelStats, levelStats.variants);
            BackgroundLoader::RemoveLockGlobal();
            short* models = member->appearance.models;
            for (int i = 0; i < EquipmentFromAppearance_Count; ++i) {
                void* item = FindElementByKey020dedd0((Container020dedd0*)self->itemTable, models[CharacterCreationUI_equipmentFromAppearance[i].appearanceSlot]);
                if (item) memcpy(&member->equipment[CharacterCreationUI_equipmentFromAppearance[i].equipmentSlot], item, sizeof(ItemRecord));
            }
            func_02083e28(member, 0);
            ResetAndCopyShorts0x1c_020863c4((unsigned char*)member);
            PackedStats0218742c* stats = SnapshotStats(&snapshot);
            stats[0].first = member->stats[0].first;
            stats[0].second = member->stats[0].second;
            stats[0].third = member->stats[0].third;
            stats[1].first = member->stats[1].first;
            stats[1].second = member->stats[1].second;
            stats[1].third = member->stats[1].third;
            stats[2].first = member->stats[2].first;
            stats[2].second = member->unk_6c;
            stats[2].third = member->unk_6e;
            stats[3].SetFirst(member->unk_6c);
            stats[3].second = member->unk_6e;
            stats[3].third = member->unk_70;
            stats[4].first = member->unk_72;
            stats[4].second = member->stats[3].first;
            int loadContext;
            ClearField00209a804(&loadContext);
            SpellTable spellTable;
            SpellTable_Load((Ctx0209a810*)&loadContext, &spellTable);
            unsigned char vocation = member->vocation;
            unsigned char level = member->levels[member->vocation];
            SpellTableEntry* spells = spellTable.spells[vocation];
            for (int i = 0; i < SpellTable_SpellsPerVocation; ++i) {
                if (level >= spells[i].level && spells[i].level != 0)
                    PartyMember_LearnSpell((unsigned char*)member, spells[i].spell);
            }
            func_020830cc(member, &snapshot);
            func_02086778(members, &snapshot, 0, 0);
            self->flags |= CreationFlag_MemberCreated;
            CharacterCreationUI_SwitchTab((unsigned char*)self, CreationTab_Close);
        }
#endif
    } else if (step == ConfirmStep_Decline) {
        Background_ClearMap((Obj0204b010*)&self->layers[4], 0);
        Background_FillRect(&self->layers[4], 0, 0, 0, BackgroundMap_Columns, BackgroundMap_Rows, 0);
        Background_FlushMap(&self->layers[4], 0);
        Background_TransferMap(&self->layers[4], 0);
        ColorEffect_ConfigureBrightnessAdjust(REG_BLDCNT_SUB, BLEND_TARGET_BG0, Brightness_Normal);
        SetElementFieldC2_0205deb4((Struct_0205d81c*)&self->windows[1], 3, 0);
        SetElementFieldC2_0205deb4((Struct_0205d81c*)&self->windows[1], 2, 0);
#if defined(jpn)
        CharacterCreationUI_SwitchTab((unsigned char*)self, CreationTab_NameEntry);
#else
        KeyboardKey* firstKey = Keyboard_FindKeyByText(self->keyboard, CharacterCreationUI_firstKeyText);
        if (firstKey) self->keyboard->key_ = firstKey;
        self->keyboard->SetPage(KeyboardPage_Lowercase);
        self->keyboard->SetShift(0);
        CharacterCreationUI_SwitchTab((unsigned char*)self, CreationTab_NameEntry);
        self->step = NameEntryStep_Start;
#endif
    }
}
