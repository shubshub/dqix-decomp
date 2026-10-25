#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/CharacterCreationUI.h"
#include "Resource/Keyboard.h"
#include "Combat/ResourceScriptEntry.h"
#include "Filesystem/BackgroundLoader.h"
#include "NitroSDK/ColorEffects.h"
#include "NitroSDK/Graphics.h"
#include "NitroSDK/HWRegisters.h"
#include "Resource/Brightness.h"
#include "Sound/SePlayer.h"
#include "Util/Random.h"
#include "std_library_functions.h"
#include "Input/Input.h"
#include "GameState/PartyMember.h"
#include "Resource/SpellTable.h"


enum
{
    EquipmentFromAppearance_Count = 7,
};

struct ItemRecord { char bytes[32]; };
struct AppearanceEquipment {
    unsigned char appearanceSlot;
    unsigned char equipmentSlot;
    unsigned char padding[5];
};
// The party list's 0x23c-byte member record: PartyMemberRecord_Init clears it, PartyMember_WriteRecord packs a
// member into it and Party_AddMemberRecord appends it to the party.
struct PartyMemberRecord { char field_0[0x14c]; PackedStats0218742c stats[5]; char field_160[0xdc]; };
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
    void SetPage(unsigned char value) { page_ = value; }
    void SetShift(unsigned char value) { shift_ = value; }
};
// The header's CharacterCreationUI up to eyeColor, with characterData typed and selection signed.
struct CharacterCreation {
#if defined(jpn)
    SafeAllocator allocators[8];
#else
    SafeAllocator allocators[9];
#endif
    SafeAllocator* modelAllocator;
    SafeAllocator* previewAllocators;
#if !defined(jpn)
    KeyboardKey* savedKey;
    Keyboard* keyboard;
    void* keyboardLayout;
#endif
    unsigned char itemTable[0x18];
    Container020e0310 texts;
    unsigned char unknownBeforeTextBuffer[0x10];
    char* textBuffer;
#if defined(jpn)
    unsigned char nameFilter[0x20];
#else
    unsigned char nameFilter[0x3c];
#endif
    BackgroundGraphics layers[6];
    CreationWindow windows[2];
    unsigned char window0Panes[1][0xe0];
    unsigned char window1Panes[4][0xe0];
    void* windowBuffers[2];
    SpriteContext0205ac40* mainSpriteContext;
    B174Outer* mainSprites;
    Container0205a3d0* mainSpriteEntries;
    SpriteContext0205ac40* subSpriteContext;
    B174Outer* subSprites;
    Container0205a3d0* subSpriteEntries;
    void* characterModels[2];
    void* character;
    void* nextCharacter;
    unsigned int unknown800;
    int targetAngle;
    unsigned char wingsVramState[0x70];
    Object3D wings;
    unsigned char camera[0x2c8];
    GridCursor navigation;
    CreationSlotLayout grid;
    short cursorX, cursorY;
    short cursorWidth, cursorHeight;
    short lastCursorX, lastCursorY;
    signed char state;
    unsigned char step;
    unsigned char unknownAfterStep[2];
    int modelTasks[3];
    unsigned char finishEffectVramState[0x70];
    Object3D finishEffect;
    signed char selection;
    unsigned char windowInput;
    unsigned char unknownAfterWindowInput[2];
    PartyMemberData* characterData;
    int touchedChoice;
    int resourceTask;
    unsigned char resourceStep;
    unsigned char mode;
    short waitTimer;
    short dimTimer;
    unsigned char unknownBeforeFlags[2];
    unsigned int flags;
    signed char furthestState[2];
    unsigned char vocation;
    unsigned char sex;
    unsigned char bodyType[2];
    unsigned char faceStyle[2];
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
struct Entry_0205d6a0; struct BackgroundGraphics; struct Cont0205d1e0; struct Cont0205d228;
struct Cont0205d274; struct Obj0205d2bc; struct ItemTable; struct Ctx0209a810;
void* GlobalFlags_GetInstance();
extern "C" void CharacterCreationUI_OpenYesNoWindow(CharacterCreation*);
void Window_SetPanePalette(Struct_0205d81c*, int, int);
int Window_GetSelectedIndex(Struct_0205c570*);
int Window_IsSelectionTouched(Obj_0205da38*, int);
void Window_ClosePane(Entry_0205d6a0*, int);
void Background_ClearMap(BackgroundGraphics*, void*);
extern "C" void Background_FillRect(void*, int, int, int, int, int, int);
extern "C" void Background_FlushMap(void*, int);
extern "C" void Background_TransferMap(void*, int);
void Window_ClearLayers(Cont0205d1e0*);
void Window_DrawPanes(Cont0205d228*);
void Window_FlushLayers(Cont0205d274*);
void Window_TransferLayers(Obj0205d2bc*);
void CharacterCreationUI_SwitchTab(unsigned char*, int);
extern "C" void PartyMemberRecord_Init(PartyMemberRecord*);
void PartyMember_SetVocation(unsigned char*, int);
extern "C" int sprintf(char*, const char*, ...);
void ResourceScriptEntry_Init(void*);
void* LoadFileIntoMemory(const char*, void*, unsigned int*);
extern "C" void PartyMember_ApplyLevelStats(void*, void*, void*);
void* ItemTable_Find(ItemTable*, int);
extern "C" void PartyMember_RecalculateStats(void*, int);
void PartyMember_RestoreHpMp(unsigned char*);
void ClearField00209a804(int*);
void SpellTable_Load(Ctx0209a810*, void*);
void PartyMember_LearnSpell(unsigned char*, int);
extern "C" void PartyMember_WriteRecord(void*, PartyMemberRecord*);
extern "C" void Party_AddMemberRecord(void*, PartyMemberRecord*, unsigned char, unsigned char);
extern "C" KeyboardKey* Keyboard_FindKeyByText(Keyboard*, const char*);
extern unsigned char CharacterCreationUI_bareBodyColors[];
extern char CharacterCreationUI_levelFileFormat[];
extern char g_fileLoadBuffer[] __attribute__((aligned(4)));
extern AppearanceEquipment CharacterCreationUI_equipmentFromAppearance[];
extern char CharacterCreationUI_firstKeyText[];

inline PackedStats0218742c* SnapshotStats(PartyMemberRecord* record) { return record->stats; }

// Overlay 9, originally func_ov009_0218742c (USA/EUR 0x0218742c, JPN 0x021881fc)
extern "C" ARM void CharacterCreationUI_HandleConfirm(CharacterCreation* self) {
    GameState* gameState = GameState::GetInstance();
    GlobalFlags_GetInstance();
    unsigned int step = self->step;
    if (step == ConfirmStep_Open) {
        CharacterCreationUI_OpenYesNoWindow(self);
        Window_SetPanePalette((Struct_0205d81c*)&self->windows[1], 3, 2);
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
            Window_ClosePane((Entry_0205d6a0*)&self->windows[1], 0);
            Window_SetPanePalette((Struct_0205d81c*)&self->windows[1], 3, 2);
#if defined(jpn)
            self->flags &= ~CreationFlag_ConfirmTouched;
            self->flags &= ~CreationFlag_BackTouched;
#else
            self->flags &= ~(CreationFlag_BackTouched | CreationFlag_ConfirmTouched);
#endif
        } else if (declined) {
            Window_ClosePane((Entry_0205d6a0*)&self->windows[1], 0);
#if defined(jpn)
            self->flags &= ~CreationFlag_ConfirmTouched;
            self->flags &= ~CreationFlag_BackTouched;
#else
            self->flags &= ~(CreationFlag_BackTouched | CreationFlag_ConfirmTouched);
#endif
            self->step = ConfirmStep_Decline;
        }
    } else if (step == ConfirmStep_Accept) {
        Background_ClearMap((BackgroundGraphics*)&self->layers[4], 0);
        Background_FillRect(&self->layers[4], 0, 0, 0, BackgroundMap_Columns, BackgroundMap_Rows, 0);
        Background_FlushMap(&self->layers[4], 0);
        Background_TransferMap(&self->layers[4], 0);
        if (self->mode == CreationMode_NewGame) {
            PartyMemberData* member = self->characterData;
            member->bareBodyColor_ = CharacterCreationUI_bareBodyColors[self->eyeColor[self->sex]];
            gameState->characterCreated_ = 1;
            ColorEffect_ConfigureBrightnessAdjust(REG_BLDCNT_SUB, BLEND_TARGET_BG0, Brightness_Normal);
            Window_SetPanePalette((Struct_0205d81c*)&self->windows[1], 3, 0);
            Window_ClearLayers((Cont0205d1e0*)&self->windows[1]);
            Window_DrawPanes((Cont0205d228*)&self->windows[1]);
            Window_FlushLayers((Cont0205d274*)&self->windows[1]);
            Window_TransferLayers((Obj0205d2bc*)&self->windows[1]);
            CharacterCreationUI_SwitchTab((unsigned char*)self, CreationTab_NewGameFinish);
#if defined(jpn)
        } else if (self->mode == CreationMode_PartyMemberCreation) {
            void* members = GameState_GetParty(gameState);
            PartyMemberRecord record;
            PartyMemberRecord_Init(&record);
            PartyMember_SetVocation((unsigned char*)self->characterData, self->vocation);
            self->characterData->experience_[self->vocation] = 0;
            self->characterData->levels_[self->vocation] = 1;
            self->characterData->bareBodyColor_ = NextRandomMax(GetBTRandom(), 16);
            char filename[32];
            int memberVocation = self->characterData->vocation_;
            sprintf(filename, CharacterCreationUI_levelFileFormat, memberVocation);
            ResourceScriptEntry levelStats;
            ResourceScriptEntry_Init(&levelStats);
            BackgroundLoader::AddLockGlobal();
            unsigned int fileSize;
            void* file = LoadFileIntoMemory(filename, g_fileLoadBuffer, &fileSize);
            if (file) ResourceScriptEntry_LoadLevel(&levelStats, file, fileSize, self->characterData->levels_[self->vocation], 0);
            PartyMember_ApplyLevelStats(self->characterData, &levelStats, levelStats.variants);
            BackgroundLoader::RemoveLockGlobal();
            short* models = &self->characterData->appearance_.body_;
            for (int i = 0; i < EquipmentFromAppearance_Count; ++i) {
                void* item = ItemTable_Find((ItemTable*)self->itemTable, models[CharacterCreationUI_equipmentFromAppearance[i].appearanceSlot]);
                if (item) memcpy(&self->characterData->equipment_[CharacterCreationUI_equipmentFromAppearance[i].equipmentSlot], item, sizeof(ItemRecord));
            }
            PartyMember_RecalculateStats(self->characterData, 0);
            PartyMember_RestoreHpMp((unsigned char*)self->characterData);
            PackedStats0218742c* stats = SnapshotStats(&record);
            PartyMemberData* member = self->characterData;
            stats[0].first = member->stats_[0].first;
            stats[0].second = member->stats_[0].second;
            stats[0].third = member->stats_[0].third;
            stats[1].first = member->stats_[1].first;
            stats[1].second = member->stats_[1].second;
            stats[1].third = member->stats_[1].third;
            stats[2].first = member->stats_[2].first;
            stats[2].second = member->maxHp_;
            stats[2].third = member->maxMp_;
            stats[3].SetFirst(member->maxHp_);
            stats[3].second = member->maxMp_;
            stats[3].third = member->attack_;
            stats[4].first = member->defence_;
            stats[4].second = member->stats_[3].first;
            int loadContext;
            ClearField00209a804(&loadContext);
            SpellTable spellTable;
            SpellTable_Load((Ctx0209a810*)&loadContext, &spellTable);
            unsigned char vocation = self->characterData->vocation_;
            unsigned char level = self->characterData->levels_[self->characterData->vocation_];
            SpellTableEntry* spells = spellTable.spells[vocation];
            for (int i = 0; i < SpellTable_SpellsPerVocation; ++i) {
                if (level >= spells[i].level && spells[i].level != 0)
                    PartyMember_LearnSpell((unsigned char*)self->characterData, spells[i].spell);
            }
            PartyMember_WriteRecord(self->characterData, &record);
            Party_AddMemberRecord(members, &record, 0, 0);
            self->flags |= CreationFlag_MemberCreated;
            CharacterCreationUI_SwitchTab((unsigned char*)self, CreationTab_Close);
        }
#else
        } else if (self->mode == CreationMode_PartyMemberCreation) {
            PartyMemberData* member = self->characterData;
            void* members = GameState_GetParty(gameState);
            PartyMemberRecord record;
            PartyMemberRecord_Init(&record);
            PartyMember_SetVocation((unsigned char*)member, self->vocation);
            member->experience_[self->vocation] = 0;
            member->levels_[self->vocation] = 1;
            member->bareBodyColor_ = NextRandomMax(GetBTRandom(), 16);
            char filename[32];
            int memberVocation = member->vocation_;
            sprintf(filename, CharacterCreationUI_levelFileFormat, memberVocation);
            ResourceScriptEntry levelStats;
            ResourceScriptEntry_Init(&levelStats);
            BackgroundLoader::AddLockGlobal();
            unsigned int fileSize;
            void* file = LoadFileIntoMemory(filename, g_fileLoadBuffer, &fileSize);
            if (file) ResourceScriptEntry_LoadLevel(&levelStats, file, fileSize, member->levels_[self->vocation], 0);
            PartyMember_ApplyLevelStats(member, &levelStats, levelStats.variants);
            BackgroundLoader::RemoveLockGlobal();
            short* models = &member->appearance_.body_;
            for (int i = 0; i < EquipmentFromAppearance_Count; ++i) {
                void* item = ItemTable_Find((ItemTable*)self->itemTable, models[CharacterCreationUI_equipmentFromAppearance[i].appearanceSlot]);
                if (item) memcpy(&member->equipment_[CharacterCreationUI_equipmentFromAppearance[i].equipmentSlot], item, sizeof(ItemRecord));
            }
            PartyMember_RecalculateStats(member, 0);
            PartyMember_RestoreHpMp((unsigned char*)member);
            PackedStats0218742c* stats = SnapshotStats(&record);
            stats[0].first = member->stats_[0].first;
            stats[0].second = member->stats_[0].second;
            stats[0].third = member->stats_[0].third;
            stats[1].first = member->stats_[1].first;
            stats[1].second = member->stats_[1].second;
            stats[1].third = member->stats_[1].third;
            stats[2].first = member->stats_[2].first;
            stats[2].second = member->maxHp_;
            stats[2].third = member->maxMp_;
            stats[3].SetFirst(member->maxHp_);
            stats[3].second = member->maxMp_;
            stats[3].third = member->attack_;
            stats[4].first = member->defence_;
            stats[4].second = member->stats_[3].first;
            int loadContext;
            ClearField00209a804(&loadContext);
            SpellTable spellTable;
            SpellTable_Load((Ctx0209a810*)&loadContext, &spellTable);
            unsigned char vocation = member->vocation_;
            unsigned char level = member->levels_[member->vocation_];
            SpellTableEntry* spells = spellTable.spells[vocation];
            for (int i = 0; i < SpellTable_SpellsPerVocation; ++i) {
                if (level >= spells[i].level && spells[i].level != 0)
                    PartyMember_LearnSpell((unsigned char*)member, spells[i].spell);
            }
            PartyMember_WriteRecord(member, &record);
            Party_AddMemberRecord(members, &record, 0, 0);
            self->flags |= CreationFlag_MemberCreated;
            CharacterCreationUI_SwitchTab((unsigned char*)self, CreationTab_Close);
        }
#endif
    } else if (step == ConfirmStep_Decline) {
        Background_ClearMap((BackgroundGraphics*)&self->layers[4], 0);
        Background_FillRect(&self->layers[4], 0, 0, 0, BackgroundMap_Columns, BackgroundMap_Rows, 0);
        Background_FlushMap(&self->layers[4], 0);
        Background_TransferMap(&self->layers[4], 0);
        ColorEffect_ConfigureBrightnessAdjust(REG_BLDCNT_SUB, BLEND_TARGET_BG0, Brightness_Normal);
        Window_SetPanePalette((Struct_0205d81c*)&self->windows[1], 3, 0);
        Window_SetPanePalette((Struct_0205d81c*)&self->windows[1], 2, 0);
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
