#include <globaldefs.h>
#include "Graphics/Window.h"
#include "Graphics/Background.h"
#include "Resource/CharacterCreationUI.h"
extern unsigned char g_fileLoadBuffer[0x30000] __attribute__((aligned(4)));
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "Filesystem/GPC.h"
#include "GameState/GameState.h"
#include "Graphics/CharacterModel.h"
#include "GameState/PartyMember.h"
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"
#include "Graphics/SpriteAffineTransform.h"

enum SetupStep
{
    SetupStep_Init = 0,
    SetupStep_LoadBackgrounds = 1,
    SetupStep_LoadSprites = 2,
#if !defined(jpn)
    SetupStep_QueueKeyboard = 3,
    SetupStep_LoadKeyboard = 4,
#endif
    SetupStep_Finish,
};

enum SetupLayers
{
    SetupLayers_Count = 4,
    SetupLayers_BottomTextSlot = 3,
};

enum SummaryWindow
{
    SummaryWindow_PaneCount = 1,
    SummaryWindow_BufferBytes = 0x1000,
    SummaryWindow_PaneBytes = 0x200,
};

enum SetupBgFile
{
    SetupBgFile_WindowTiles = 0,
    SetupBgFile_LastBackdrop = 3,
};

enum BackdropScreen
{
    BackdropScreen_Npc = 0,
    BackdropScreen_Hero = 1,
};

enum SetupText
{
    SetupText_SpriteArchive = 1000,
    SetupText_WingsModel = 2000,
};

enum CreationItemIds
{
    CreationItemIds_Count = 41,
};

enum CharacterModelSize
{
    CharacterModelSize_Bytes = 0xc20,
};

#if defined(jpn)
enum TextFileBuffer
{
    TextFileBuffer_Bytes = 0x1800,
};
#endif

enum WingsTextureVram
{
    WingsTextureVram_Bytes = 0xc00,
};

enum WingsPaletteVram
{
    WingsPaletteVram_Bytes = 0x30,
};

enum FinishEffectVram
{
    FinishEffectVram_TextureBytes = 0x1a00,
    FinishEffectVram_PaletteBytes = 0x20,
};

enum DefaultCamera
{
    DefaultCamera_X = 0xd000,
    DefaultCamera_Y = 0xf800,
    DefaultCamera_PositionZ = 0x42ccc,
};

enum AppearanceSlot
{
    AppearanceSlot_Face = 2,
    AppearanceSlot_HairStyle = 3,
};

enum PlainOutfit
{
    PlainOutfit_Body = 0x32cd,
    PlainOutfit_Arms = 0x36b5,
    PlainOutfit_Legs = 0x3f55,
    PlainOutfit_Feet = 0x43fe,
};

enum CelestrianOutfit
{
    CelestrianOutfit_Body = 0x32cf,
    CelestrianOutfit_Arms = 0x36b7,
    CelestrianOutfit_Legs = 0x3f57,
    CelestrianOutfit_Feet = 0x42e0,
};

enum StartingWeapon
{
    StartingWeapon_Knife = 0x4a6a,
    StartingWeapon_CopperSword = 0x4e24,
    StartingWeapon_PeacockFan = 0x4e84,
    StartingWeapon_OakStaff = 0x4fb3,
    StartingWeapon_BambooSpear = 0x5014,
    StartingWeapon_BambooPole = 0x5078,
    StartingWeapon_Boomerang = 0x50dc,
};

// The header's CreationWindow, field for field.
struct Window {
    unsigned char unknown_[4];
    int frame_[20];
    int cursor_[16];
    unsigned char unknown94_[4];
    BackgroundGraphics* layers_;
    WindowPane* panes_;
    short layout_[8];
    unsigned char activeWindow_;
    unsigned char nextWindow_;
    unsigned char layerCount_;
    unsigned char paneCount_;
    unsigned char count_;
    unsigned char flags_;
    unsigned char noHorizontalInset_;
    unsigned char fontHeight_;
    unsigned int pendingClose_;
};

// One 0x28-byte sprite: the header's B174Outer.
typedef B174Outer Sprite;

#if defined(jpn)
struct CreationStyleOrder { signed char styles[10]; };
#endif
struct SpriteContext {
    char unk_0[0x3c];
    void* spriteEntries_;
    Sprite* sprites_;
    char unknown_44_[0x4c - 0x44];
    short spriteCount_;
    char unknown_4e_[2];
    unsigned char subScreen_;
#if defined(jpn)
    void SetSubScreen(unsigned char subScreen) { subScreen_ = subScreen; }
    void SetSprites(Sprite* sprites, short count)
    {
        sprites_ = sprites;
        spriteCount_ = count;
    }
#endif
};

struct AppearanceModels { short models[10]; };
struct Scene {
    char pad124[0x924 - 0x124];
    char camera_[0xc58 - 0x924];
};

struct MessageSystem {
#if defined(jpn)
    char pad0[0x28];
#else
    char pad0[0x5c];
#endif
    int textBuffer_;
};

struct KeyboardKey {
    short x_;
    short y_;
    const char* text_;
    const char* shiftedText_;
    unsigned char pages_;
    unsigned char action_;
    unsigned char sizeClass_;
    unsigned char disabled_;
};

struct Keyboard {
    KeyboardKey* key_;
    void* layout_;
};

struct CharacterCreation {
#if defined(jpn)
    SafeAllocator allocators_[8];
    SafeAllocator* modelAllocator_;
    SafeAllocator* previewAllocators_;
    char itemTable_[0x18];
    char texts_[0x18];
    int textBuffer_;
    NameFilter nameFilter_;
#else
    SafeAllocator allocators_[9];
    SafeAllocator* modelAllocator_;
    SafeAllocator* previewAllocators_;
    KeyboardKey* savedKey_;
    Keyboard* keyboard_;
    void* keyboardLayout_;
    char itemTable_[0x18];
    char texts_[0x18];
    int textBuffer_;
    NameFilter nameFilter_;
#endif
    BackgroundGraphics layers_[6];
    Window windows_[2];
    WindowPane window0Panes_[SummaryWindow_PaneCount];
    WindowPane window1Panes_[BottomWindow_PaneCount];
    void* windowBuffer0_;
    void* windowBuffer1_;
    SpriteContext* mainSpriteContext_;
    Sprite* mainSprites_;
    void* mainSpriteEntries_;
    SpriteContext* subSpriteContext_;
    Sprite* subSprites_;
    void* subSpriteEntries_;
    void* characterModels_[2];
    void* character_;
    void* nextCharacter_;
    int unknown800_;
    int targetAngle_;
    char wingsVramState_[0x878 - 0x808];
    char wings_[0x924 - 0x878];
    char camera_[0xc58 - 0x924];
    signed char state_;
    unsigned char step_;
    char unknownAfterStep_[2];
    int modelTasks_[3];
    char finishEffectVramState_[0xcd8 - 0xc68];
    char finishEffect_[0xd84 - 0xcd8];
    unsigned char selection_;
    unsigned char windowInput_;
    char unknownAfterWindowInput_[2];
    PartyMemberData* characterData_;
    int touchedChoice_;
    int resourceTask_;
    unsigned char resourceStep_;
    unsigned char mode_;
    short waitTimer_;
    short dimTimer_;
    char unknownBeforeFlags_[2];
    unsigned int flags_;
    signed char furthestState_[2];
    unsigned char vocation_;
    unsigned char sex_;
    unsigned char bodyType_[2];
    unsigned char faceStyle_[2];
    unsigned char eyeColor_[2];
    unsigned char skinColor_[2];
    unsigned char hairStyle_[2];
    unsigned char hairColor_[2];
#if defined(jpn)
    char names_[2][0xb];
    char nameLengths_[2];
#endif
};

struct BackgroundGraphics;
struct PacRecord;
struct Struct_0205cf78;
struct Struct_0205d81c;
struct Container020e0310;
struct Foo0207df50;

struct GameResources;
extern "C" char* MessageSystem_GetInstance();
extern "C" void ItemTable_Init(void* itemTable);
extern "C" void ItemTable_LoadIds(void* itemTable, SafeAllocator* allocator, void* itemData, unsigned int size, const void* ids,
                              int count);
extern "C" void KeyTable_Load(void* texts, SafeAllocator* allocator, void* textFile, unsigned int size);
extern "C" void CharacterModel_Init(void* model);
extern "C" void CharacterModel_CreateAllocators(void* model, SafeAllocator* allocator);
extern "C" void CharacterModel_ReserveVram(void* model);
extern "C" void CharacterModel_SetItemTable(void* model, int itemTable);
extern "C" const char* KeyTable_Get(Container020e0310* table, int key);
extern "C" void VramState_Reserve(void* vramState, int textureBytes, int paletteBytes);
extern "C" void VramState_Rewind(Foo0207df50* vramState);
extern "C" void VramState_Restore(char* vramState);
extern "C" void VramState_Save(char* vramState);
extern "C" void func_020a2010(void* camera);
struct Camera;
extern "C" void Camera_SetPosition(Camera* camera, int x, int y, int z);
extern "C" void Camera_SetTarget(struct Camera* camera, int x, int y, int z);
extern "C" void Camera_Update(void* camera);
extern "C" void FollowCamera_DisableFollow(void* camera);
extern "C" void GameState_SetCamera(GameState* gameState, int camera);
extern "C" void CharacterCreationUI_GetBodyDimensions(unsigned char* self, int bodyType, short* width, short* height);
extern "C" int CharacterCreationUI_SlotToStyleIndex(void* self, int tab, int slot);
extern "C" void* memcpy(void* dst, const void* src, unsigned int n);
extern "C" void CharacterModel_SetScale(void* model, short width, short height);
extern "C" void CharacterModel_SetForceStandAnimation(void* model, unsigned char value);
extern "C" void Background_Init(BackgroundGraphics* layer);
extern "C" void Background_SetMapSize(unsigned char* layer, int sizeIndex);
extern "C" void Background_SetPriority(BackgroundGraphics* layer, int priority);
extern "C" void Background_SetScroll(BackgroundGraphics* layer, int x, int y);
extern "C" void Background_AllocateMap(BackgroundGraphics* layer, SafeAllocator* allocator);
extern "C" void Background_AllocateScreens(BackgroundGraphics* layer, int count, SafeAllocator* allocator);
extern "C" int Pac_CountFiles(PacRecord* archive);
extern "C" void* Pac_GetFile(PacRecord* archive, int index, void** record, int* size);
extern "C" void Background_LoadFile(BackgroundGraphics* layer, void* file, SafeAllocator* allocator, unsigned int size);
extern "C" void Background_DrawScreen(BackgroundGraphics* layer, unsigned int screen, int sourceX, int sourceY, short destX, short destY,
                           short width, short height, unsigned short palette);
extern "C" void Background_UploadMap(BackgroundGraphics* layer, void* buffer);
extern "C" void Background_FillRect(BackgroundGraphics* layer, int tile, int x, int y, int width, int height, int palette);
extern "C" void CharacterCreationUI_DrawTabLayers(void* self);
extern "C" void WindowPane_AllocateBuffer(WindowPane* pane, SafeAllocator* allocator, int windowBuffer, unsigned int size);
extern "C" void Window_SetPanes(Struct_0205cf78* window, WindowPane* panes, unsigned char count);
extern "C" void SpriteContext_Init(char* context);
struct Struct0205a198;
extern "C" void Sprite_Init(Struct0205a198* sprite);
struct ClearTarget0205a234;
extern "C" void func_0205a234(ClearTarget0205a234* spriteEntries);
extern "C" void SpriteContext_LoadFile(SpriteContext* context, void* file, int size, SafeAllocator* allocator);
extern "C" void KeyboardLayout_Load(void* layout, SafeAllocator* allocator, void* script, unsigned int size);
extern "C" void Keyboard_ResetToKey(Keyboard* keyboard, const char* text);
extern "C" KeyboardKey* Keyboard_FindKeyByText(Keyboard* keyboard, const char* text);
extern "C" void CharacterModel_SetAngle(void* model, unsigned int angle);
extern "C" void CharacterModel_Load(void* model, PartyMemberData* member, short vocation, int unused, int force);
extern "C" void CharacterCreationUI_CreateSummaryPane(void* self);
extern "C" void func_ov023_021d9c7c(void* self);
extern "C" void CharacterCreationUI_CreateNamePane(void* self);
extern "C" void Window_SetPanePalette(Struct_0205d81c* window, int paneId, int value);
extern "C" void CharacterCreationUI_SwitchTab(unsigned char* self, int tab);

extern const char CharacterCreationUI_textArchive[];
extern const char CharacterCreationUI_textFile[];
extern const char* g_itemDataArchive;
extern const char* g_itemDataFile;
extern const char CharacterCreationUI_itemIds[];

extern const char CharacterCreationUI_characterArchive[];
extern signed char CharacterCreationUI_styleOrder[10];
extern const AppearanceModels CharacterCreationUI_defaultAppearance;
extern const unsigned char CharacterCreationUI_setupBgSubScreen[];
extern const unsigned char CharacterCreationUI_setupBgNumbers[];
extern const signed char CharacterCreationUI_setupBgPriorities[];
extern const signed char CharacterCreationUI_setupBgScreenCounts[];
extern const unsigned short CharacterCreationUI_window1PaneSizes[];
extern const char CharacterCreationUI_newGameKeyboardFile[];
extern const char CharacterCreationUI_partyKeyboardFile[];
extern const char CharacterCreationUI_firstKeyText[];
extern const char CharacterCreationUI_spaceKeyText[];

#if defined(jpn)
extern "C" void func_020e0484(void* itemTable, SafeAllocator* allocator, const char* path, const void* ids, int count,
                              int flag);
extern "C" void func_ov009_02185888(void* nameFilter);
extern "C" void NameFilter_Reset(void* nameFilter);
extern "C" int func_ov009_02185c58(void* nameFilter);
extern "C" void CharacterCreationUI_SwitchTab(unsigned char* self, int tab);
#define CHARACTER_MODEL0 self->characterModels_[0]
#define CHARACTER_MODEL1 self->characterModels_[1]
#define MAIN_SPRITE_CONTEXT self->mainSpriteContext_
#define SUB_SPRITE_CONTEXT self->subSpriteContext_
#else
#define CHARACTER_MODEL0 characterModel0
#define CHARACTER_MODEL1 characterModel1
#define MAIN_SPRITE_CONTEXT mainSpriteContext
#define SUB_SPRITE_CONTEXT subSpriteContext
#endif

// Overlay 9, originally func_ov009_02185634 (USA/EUR 0x02185634, JPN 0x02186814)
extern "C" ARM void CharacterCreationUI_HandleSetup(CharacterCreation* self)
{
    unsigned int headerLength;
    GameState* gameState = GameState::GetInstance();
    gameState->GetResources();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    unsigned char step = self->step_;
    if (step == SetupStep_Init)
    {
#if defined(jpn)
        self->allocators_[CreationAllocator_TabLayers].Reset();
        void* textFile = self->allocators_[CreationAllocator_TabLayers].Allocate(TextFileBuffer_Bytes);
        unsigned int textFileSize;
        LoadFileIntoMemory(CharacterCreationUI_textArchive, textFile, &textFileSize);
        self->allocators_[CreationAllocator_Texts].Reset();
        KeyTable_Load(self->texts_, &self->allocators_[CreationAllocator_Texts], textFile, textFileSize);
        self->textBuffer_ = ((MessageSystem*)MessageSystem_GetInstance())->textBuffer_;
        ItemTable_Init(self->itemTable_);
        func_020e0484(self->itemTable_, &self->allocators_[CreationAllocator_ItemTable], g_itemDataArchive,
                      CharacterCreationUI_itemIds, CreationItemIds_Count, 1);
#else
        BackgroundLoader::AddLockGlobal();
        BackgroundLoader::FreeAllocationsGlobal();
        unsigned int textFileSize;
        void* textFile = ExtractFileFromGP2(CharacterCreationUI_textArchive, CharacterCreationUI_textFile, &textFileSize);
        self->allocators_[CreationAllocator_Texts].Reset();
        KeyTable_Load(self->texts_, &self->allocators_[CreationAllocator_Texts], textFile, textFileSize);
        BackgroundLoader::RemoveLockGlobal();
        self->textBuffer_ = ((MessageSystem*)MessageSystem_GetInstance())->textBuffer_;
        ItemTable_Init(self->itemTable_);
        BackgroundLoader::AddLockGlobal();
        unsigned int itemDataSize;
        void* itemData = ExtractFileFromGP2(g_itemDataArchive, g_itemDataFile, &itemDataSize);
        if (itemData != NULL)
            ItemTable_LoadIds(self->itemTable_, &self->allocators_[CreationAllocator_ItemTable], itemData, itemDataSize,
                          CharacterCreationUI_itemIds, CreationItemIds_Count);
        BackgroundLoader::RemoveLockGlobal();
#endif

        self->characterModels_[0] = self->allocators_[CreationAllocator_Characters].Allocate(CharacterModelSize_Bytes);
#if !defined(jpn)
        void* characterModel0 = self->characterModels_[0];
#endif
        CharacterModel_Init(CHARACTER_MODEL0);
        CharacterModel_CreateAllocators(CHARACTER_MODEL0, &self->allocators_[CreationAllocator_Characters]);
        CharacterModel_ReserveVram(CHARACTER_MODEL0);
        CharacterModel_SetItemTable(CHARACTER_MODEL0, (int)self->itemTable_);
        self->characterModels_[1] = self->allocators_[CreationAllocator_Characters].Allocate(CharacterModelSize_Bytes);
#if !defined(jpn)
        void* characterModel1 = self->characterModels_[1];
#endif
        CharacterModel_Init(CHARACTER_MODEL1);
        CharacterModel_CreateAllocators(CHARACTER_MODEL1, &self->allocators_[CreationAllocator_Characters]);
        CharacterModel_ReserveVram(CHARACTER_MODEL1);
        CharacterModel_SetItemTable(CHARACTER_MODEL1, (int)self->itemTable_);

        if (self->mode_ == CreationMode_NewGame)
        {
#if defined(jpn)
            WingsTextureVram textureBytes = WingsTextureVram_Bytes;
            WingsPaletteVram paletteBytes = WingsPaletteVram_Bytes;
#endif
            BackgroundLoader::AddLockGlobal();
            BackgroundLoader::FreeAllocationsGlobal();
            GPCReadPair characterArchive;
            GPCReadPair* characterArchiveRef = &characterArchive;
            unsigned int decompressedLength = 0;
            unsigned char* buffer = g_fileLoadBuffer;
            int capacity = sizeof(g_fileLoadBuffer);
            ZeroInitGPCPointer(&characterArchiveRef->pGPCFile);
            characterArchiveRef->ZeroInitializeMachine();
            if (LoadAndDecompressGPCHeaderAndInnerFileInfo(&characterArchive.pGPCFile, characterArchive.machine,
                                                           CharacterCreationUI_characterArchive, buffer,
                                                           decompressedLength, capacity, false, 0))
            {
                headerLength = decompressedLength;
                capacity -= headerLength;
#if !defined(jpn)
                WingsTextureVram textureBytes = WingsTextureVram_Bytes;
                WingsPaletteVram paletteBytes = WingsPaletteVram_Bytes;
#endif
                if (DecompressFileFromGPCByName(characterArchive.pGPCFile, characterArchive.machine, buffer + headerLength,
                                                decompressedLength, capacity,
                                                KeyTable_Get((Container020e0310*)self->texts_, SetupText_WingsModel)))
                {
                    VramState_Reserve(self->wingsVramState_, textureBytes, paletteBytes);
                    VramState_Rewind((Foo0207df50*)self->wingsVramState_);
                    VramState_Restore(self->wingsVramState_);
                    ((Object3D*)self->wings_)->SetModelFromFileCopy(self->modelAllocator_, buffer + headerLength,
                                                                    decompressedLength,
                                                                    Model3D::TextureStagingMode_Normal);
                    VramState_Save(self->wingsVramState_);
                }
            }
            BackgroundLoader::RemoveLockGlobal();
            VramState_Reserve(self->finishEffectVramState_, FinishEffectVram_TextureBytes, FinishEffectVram_PaletteBytes);
            characterArchive.Reset();
            ZeroDestroyGPCPointer(&characterArchive.pGPCFile);
        }

#if defined(jpn)
        CharacterCreation* scene = self;
#else
        Scene* scene = (Scene*)((char*)self + 0x124);
#endif
        func_020a2010(scene->camera_);
        Camera_SetPosition((Camera*)scene->camera_, DefaultCamera_X, DefaultCamera_Y, DefaultCamera_PositionZ);
        Camera_SetTarget((struct Camera*)scene->camera_, DefaultCamera_X, DefaultCamera_Y, 0);
        Camera_Update(scene->camera_);
        FollowCamera_DisableFollow(scene->camera_);
        GameState_SetCamera(gameState, (int)scene->camera_);

        self->sex_ = CreationSex_Male;
        self->bodyType_[CreationSex_Male] = 2;
        self->bodyType_[CreationSex_Female] = 2;
        self->faceStyle_[CreationSex_Male] = 0;
        self->faceStyle_[CreationSex_Female] = 0;
        self->eyeColor_[CreationSex_Male] = 0;
        self->eyeColor_[CreationSex_Female] = 5;
        self->skinColor_[CreationSex_Male] = 3;
        self->skinColor_[CreationSex_Female] = 3;
        self->hairStyle_[CreationSex_Male] = 0;
        self->hairStyle_[CreationSex_Female] = 0;
        self->hairColor_[CreationSex_Male] = 0;
        self->hairColor_[CreationSex_Female] = 3;
        if (self->mode_ == CreationMode_PartyMemberCreation)
        {
            self->faceStyle_[CreationSex_Male] = 1;
            self->faceStyle_[CreationSex_Female] = 1;
            self->hairStyle_[CreationSex_Female] = 1;
            self->eyeColor_[CreationSex_Female] = 0;
            self->hairColor_[CreationSex_Female] = 0;
        }
#if defined(jpn)
        memcpy(self->names_[CreationSex_Male], KeyTable_Get((Container020e0310*)self->texts_, CreationText_BlankName),
               sizeof(self->names_[CreationSex_Male]));
        self->nameLengths_[CreationSex_Male] = 0;
        memcpy(self->names_[CreationSex_Female], KeyTable_Get((Container020e0310*)self->texts_, CreationText_BlankName),
               sizeof(self->names_[CreationSex_Female]));
        self->nameLengths_[CreationSex_Female] = 0;
#endif

        AppearanceModels appearanceModels;
        BackgroundGraphics* setupLayers[SetupLayers_Count];
        PartyMemberAppearance* appearance = &self->characterData_->appearance_;
        appearance->female_ = self->sex_;
        appearance->skinColor_ = self->skinColor_[self->sex_];
        int eyeColor = self->eyeColor_[self->sex_];
        {
#if defined(jpn)
            CreationStyleOrder order = *(CreationStyleOrder*)CharacterCreationUI_styleOrder;
#else
            signed char order[10];
            int remaining;
            unsigned char* dst;
            unsigned char* src = (unsigned char*)CharacterCreationUI_styleOrder;
            dst = (unsigned char*)order;
            remaining = 10;
            do {
                unsigned char style = *src;
                src++;
                *dst = style;
                dst++;
            } while (--remaining);
#endif
        }
        appearance->eyeColor_ = eyeColor;
        {
            signed char order[10];
            int remaining;
            unsigned char* dst;
            unsigned char* src;
            int hairColor = self->hairColor_[self->sex_];
            src = (unsigned char*)CharacterCreationUI_styleOrder;
            dst = (unsigned char*)order;
            remaining = 10;
            do {
                unsigned char style = *src;
                src++;
                *dst = style;
                dst++;
            } while (--remaining);
            appearance->hairColor_ = hairColor;
        }
        CharacterCreationUI_GetBodyDimensions((unsigned char*)self, self->bodyType_[self->sex_], &appearance->width_,
                                              &appearance->height_);
        short face = CharacterCreationUI_SlotToStyleIndex(self, CreationTab_Face, self->faceStyle_[self->sex_]) +
                     AppearanceModel_FirstFace;
        short hairStyle = CharacterCreationUI_SlotToStyleIndex(self, CreationTab_HairStyle, self->hairStyle_[self->sex_]) +
                          AppearanceModel_FirstHairStyle;
        appearanceModels = CharacterCreationUI_defaultAppearance;
        appearanceModels.models[AppearanceSlot_Face] = face;
        appearanceModels.models[AppearanceSlot_HairStyle] = hairStyle;
        memcpy(appearance, &appearanceModels, sizeof(appearanceModels));
        appearance->defaultArms_ = -1;
        CharacterModel_SetScale(CHARACTER_MODEL0, appearance->width_, appearance->height_);
        CharacterModel_SetScale(CHARACTER_MODEL1, appearance->width_, appearance->height_);

        if (self->vocation_ != 0)
        {
            CharacterModel_SetForceStandAnimation(CHARACTER_MODEL0, 1);
            CharacterModel_SetForceStandAnimation(CHARACTER_MODEL1, 1);
            switch (self->vocation_)
            {
            case 1:
            case 7:
            case 8:
                appearance->weapon_ = StartingWeapon_CopperSword;
                break;
            case 2:
            case 9:
                appearance->weapon_ = StartingWeapon_BambooSpear;
                break;
            case 3:
            case 10:
                appearance->weapon_ = StartingWeapon_OakStaff;
                break;
            case 4:
                appearance->weapon_ = StartingWeapon_BambooPole;
                break;
            case 6:
            case 11:
                appearance->weapon_ = StartingWeapon_PeacockFan;
                break;
            case 5:
                appearance->weapon_ = StartingWeapon_Knife;
                break;
            case 12:
                appearance->weapon_ = StartingWeapon_Boomerang;
                break;
            }
            appearance->body_ = PlainOutfit_Body;
            appearance->defaultArms_ = PlainOutfit_Arms;
            appearance->legs_ = PlainOutfit_Legs;
            appearance->feet_ = PlainOutfit_Feet;
        }
        if (self->mode_ == CreationMode_NewGame)
        {
            appearance->body_ = CelestrianOutfit_Body;
            appearance->defaultArms_ = CelestrianOutfit_Arms;
            appearance->legs_ = CelestrianOutfit_Legs;
            appearance->feet_ = CelestrianOutfit_Feet;
        }

        setupLayers[0] = &self->layers_[CreationLayer_Backdrop];
        setupLayers[1] = &self->layers_[CreationLayer_TabHighlight];
        setupLayers[2] = &self->layers_[CreationLayer_SummaryText];
        setupLayers[SetupLayers_BottomTextSlot] = &self->layers_[CreationLayer_BottomText];
        for (int i = 0; i < SetupLayers_Count; i++)
        {
            BackgroundGraphics* layer = setupLayers[i];
            SafeAllocator* allocator = &self->allocators_[CreationAllocator_MainLayers];
            if (i == SetupLayers_BottomTextSlot)
                allocator = &self->allocators_[CreationAllocator_BottomText];
            Background_Init((BackgroundGraphics*)layer);
            Background_SetMapSize((unsigned char*)layer, 0);
            unsigned char subScreen = CharacterCreationUI_setupBgSubScreen[i];
            layer->subScreen_ = subScreen;
            layer->bgNumber_ = CharacterCreationUI_setupBgNumbers[i];
            Background_SetPriority(layer, CharacterCreationUI_setupBgPriorities[i]);
            Background_SetScroll((BackgroundGraphics*)layer, 0, 0);
            Background_AllocateMap((BackgroundGraphics*)layer, allocator);
            if (CharacterCreationUI_setupBgScreenCounts[i] > 0)
                Background_AllocateScreens((BackgroundGraphics*)layer, (unsigned char)CharacterCreationUI_setupBgScreenCounts[i], allocator);
        }

#if defined(jpn)
        self->resourceTask_ = loader->QueueLoadFile(KeyTable_Get((Container020e0310*)self->texts_, self->state_), NULL);
#else
        signed char tab = self->state_;
        const char* innerFile = KeyTable_Get((Container020e0310*)self->texts_, (short)(tab + CreationText_InnerFileOffset));
        self->resourceTask_ = loader->QueueLoadFileInGP2(KeyTable_Get((Container020e0310*)self->texts_, tab),
                                                         innerFile, NULL);
#endif
        self->step_++;
    }
    else if (step == SetupStep_LoadBackgrounds)
    {
        if (loader->GetTaskStatus(self->resourceTask_) != 0)
        {
            char record[4];
            void* archive;
            unsigned int archiveSize;
            int fileSize;
            loader->GetLoadedFileByID(self->resourceTask_, &archive, &archiveSize);
            int fileCount = Pac_CountFiles((PacRecord*)archive);
            if (self->mode_ == CreationMode_PartyMemberCreation)
                fileCount--;
            for (int i = 0; i < fileCount; i++)
            {
                void* file = Pac_GetFile((PacRecord*)archive, i, (void**)record, &fileSize);
                if (file != NULL)
                {
                    if (i == SetupBgFile_WindowTiles)
                    {
                        Background_LoadFile(&self->layers_[CreationLayer_SummaryText], file,
                                      &self->allocators_[CreationAllocator_MainLayers], fileSize);
                        Background_LoadFile(&self->layers_[CreationLayer_BottomText], file,
                                      &self->allocators_[CreationAllocator_BottomText], fileSize);
                    }
                    else if (i <= SetupBgFile_LastBackdrop)
                    {
                        Background_LoadFile(&self->layers_[CreationLayer_Backdrop], file,
                                      &self->allocators_[CreationAllocator_MainLayers], fileSize);
                    }
                    else
                    {
                        Background_LoadFile(&self->layers_[CreationLayer_TabHighlight], file,
                                      &self->allocators_[CreationAllocator_MainLayers], fileSize);
                    }
                }
            }
            loader->RemoveTask(self->resourceTask_);
            self->resourceTask_ = -1;
            int backdropScreen = BackdropScreen_Hero;
            if (self->mode_ == CreationMode_PartyMemberCreation)
                backdropScreen = BackdropScreen_Npc;
            Background_DrawScreen((BackgroundGraphics*)&self->layers_[CreationLayer_Backdrop], backdropScreen, 0, 0, 0, 0,
                                  BackgroundMap_Columns, BackgroundMap_ScreenRows, BackgroundPalette_Keep);
            Background_UploadMap((BackgroundGraphics*)&self->layers_[CreationLayer_Backdrop], 0);
            Background_FillRect(&self->layers_[CreationLayer_TabHighlight], 0, 0, 0, BackgroundMap_Columns, BackgroundMap_Rows, 0);
            Background_UploadMap((BackgroundGraphics*)&self->layers_[CreationLayer_TabHighlight], 0);
            Background_FillRect(&self->layers_[CreationLayer_SummaryText], 0, 0, 0, BackgroundMap_Columns, BackgroundMap_Rows, 0);
            Background_UploadMap((BackgroundGraphics*)&self->layers_[CreationLayer_SummaryText], 0);
            Background_FillRect(&self->layers_[CreationLayer_BottomText], 0, 0, 0, BackgroundMap_Columns, BackgroundMap_Rows, 0);
            Background_UploadMap((BackgroundGraphics*)&self->layers_[CreationLayer_BottomText], 0);
            self->flags_ |= CreationFlag_RedrawTabHighlight;
            CharacterCreationUI_DrawTabLayers(self);
            Background_UploadMap((BackgroundGraphics*)&self->layers_[CreationLayer_TabHighlight], 0);
            self->flags_ &= ~CreationFlag_RedrawTabHighlight;

            self->windowBuffer0_ = self->allocators_[CreationAllocator_MainLayers].Allocate(SummaryWindow_BufferBytes);
            WindowPane* pane;
            unsigned int window0PaneSize = SummaryWindow_PaneBytes;
            for (int i = 0; i < SummaryWindow_PaneCount; i++)
            {
                pane = &self->window0Panes_[i];
                WindowPane_AllocateBuffer((WindowPane*)pane, &self->allocators_[CreationAllocator_MainLayers],
                                       (int)self->windowBuffer0_, window0PaneSize);
                pane->layer_ = &self->layers_[CreationLayer_SummaryText];
            }
            self->windows_[CreationWindowIndex_Summary].layers_ = &self->layers_[CreationLayer_SummaryText];
            self->windows_[CreationWindowIndex_Summary].layerCount_ = 1;
            Window_SetPanes((Struct_0205cf78*)&self->windows_[CreationWindowIndex_Summary],
                                          (WindowPane*)self->window0Panes_, SummaryWindow_PaneCount);

            self->windowBuffer1_ = self->allocators_[CreationAllocator_BottomText].Allocate(BottomWindow_BufferBytes);
            for (int i = 0; i < BottomWindow_PaneCount; i++)
            {
                pane = &self->window1Panes_[i];
                WindowPane_AllocateBuffer((WindowPane*)pane, &self->allocators_[CreationAllocator_BottomText],
                                       (int)self->windowBuffer1_, CharacterCreationUI_window1PaneSizes[i]);
                pane->layer_ = &self->layers_[CreationLayer_BottomText];
            }
            self->windows_[CreationWindowIndex_Bottom].layers_ = &self->layers_[CreationLayer_BottomText];
            self->windows_[CreationWindowIndex_Bottom].layerCount_ = 1;
            Window_SetPanes((Struct_0205cf78*)&self->windows_[CreationWindowIndex_Bottom],
                                          (WindowPane*)self->window1Panes_, BottomWindow_PaneCount);

            int i;
#if !defined(jpn)
            SpriteContext* mainSpriteContext = self->mainSpriteContext_;
#endif
            SpriteContext_Init((char*)MAIN_SPRITE_CONTEXT);
            MAIN_SPRITE_CONTEXT->subScreen_ = 0;
#if defined(jpn)
            MAIN_SPRITE_CONTEXT->SetSprites(self->mainSprites_, MainSprites_Count);
#else
            MAIN_SPRITE_CONTEXT->sprites_ = self->mainSprites_;
            MAIN_SPRITE_CONTEXT->spriteCount_ = MainSprites_Count;
#endif
            MAIN_SPRITE_CONTEXT->spriteEntries_ = self->mainSpriteEntries_;
            for (i = 0; i < MainSprites_Count; i++)
                Sprite_Init((Struct0205a198*)&self->mainSprites_[i]);
            func_0205a234((ClearTarget0205a234*)self->mainSpriteEntries_);

#if !defined(jpn)
            SpriteContext* subSpriteContext = self->subSpriteContext_;
#endif
            SpriteContext_Init((char*)SUB_SPRITE_CONTEXT);
#if defined(jpn)
            SUB_SPRITE_CONTEXT->SetSubScreen(1);
#else
            SUB_SPRITE_CONTEXT->subScreen_ = 1;
#endif
#if defined(jpn)
            SUB_SPRITE_CONTEXT->SetSprites(self->subSprites_, SubSprites_Count);
#else
            SUB_SPRITE_CONTEXT->sprites_ = self->subSprites_;
            SUB_SPRITE_CONTEXT->spriteCount_ = SubSprites_Count;
#endif
            SUB_SPRITE_CONTEXT->spriteEntries_ = self->subSpriteEntries_;
            for (int j = 0; j < SubSprites_Count; j++)
                Sprite_Init((Struct0205a198*)&self->subSprites_[j]);
            func_0205a234((ClearTarget0205a234*)self->subSpriteEntries_);

#if defined(jpn)
            self->resourceTask_ = loader->QueueLoadFile(KeyTable_Get((Container020e0310*)self->texts_, SetupText_SpriteArchive),
                                                        NULL);
#else
            const char* innerFile = KeyTable_Get((Container020e0310*)self->texts_,
                                                 SetupText_SpriteArchive + CreationText_InnerFileOffset);
            self->resourceTask_ = loader->QueueLoadFileInGP2(KeyTable_Get((Container020e0310*)self->texts_, SetupText_SpriteArchive),
                                                             innerFile, NULL);
#endif
            self->step_++;
        }
    }
    else if (step == SetupStep_LoadSprites)
    {
        if (loader->GetTaskStatus(self->resourceTask_) != 0)
        {
            char record[4];
            void* archive;
            unsigned int archiveSize;
            int fileSize;
            loader->GetLoadedFileByID(self->resourceTask_, &archive, &archiveSize);
            int fileCount = Pac_CountFiles((PacRecord*)archive);
            self->allocators_[CreationAllocator_Sprites].Reset();
            for (int i = 0; i < fileCount; i++)
            {
                void* file = Pac_GetFile((PacRecord*)archive, i, (void**)record, &fileSize);
                if (file != NULL)
                {
                    if (i < SubSprites_FirstFile)
                        SpriteContext_LoadFile(self->mainSpriteContext_, file, fileSize, &self->allocators_[CreationAllocator_Sprites]);
                    else
                        SpriteContext_LoadFile(self->subSpriteContext_, file, fileSize, &self->allocators_[CreationAllocator_Sprites]);
                }
            }
            loader->RemoveTask(self->resourceTask_);
            self->resourceTask_ = -1;
            self->step_++;
        }
    }
#if !defined(jpn)
    else if (step == SetupStep_QueueKeyboard)
    {
        if (self->mode_ == CreationMode_NewGame)
            self->resourceTask_ = loader->QueueLoadFile(CharacterCreationUI_newGameKeyboardFile, NULL);
        else
            self->resourceTask_ = loader->QueueLoadFile(CharacterCreationUI_partyKeyboardFile, NULL);
        self->step_++;
    }
    else if (step == SetupStep_LoadKeyboard)
    {
        if (loader->GetTaskStatus(self->resourceTask_) != 0)
        {
            void* keyboardFile;
            unsigned int keyboardFileSize;
            loader->GetLoadedFileByID(self->resourceTask_, &keyboardFile, &keyboardFileSize);
            if (keyboardFile != NULL && keyboardFileSize != 0)
            {
                self->allocators_[CreationAllocator_KeyboardLayout].Reset();
                KeyboardLayout_Load(self->keyboardLayout_, &self->allocators_[CreationAllocator_KeyboardLayout], keyboardFile,
                                    keyboardFileSize);
                self->keyboard_->layout_ = self->keyboardLayout_;
                Keyboard_ResetToKey(self->keyboard_, CharacterCreationUI_firstKeyText);
                KeyboardKey* spaceKey = Keyboard_FindKeyByText(self->keyboard_, CharacterCreationUI_spaceKeyText);
                if (spaceKey != NULL)
                    spaceKey->disabled_ = 1;
            }
            loader->RemoveTask(self->resourceTask_);
            self->resourceTask_ = -1;
            self->step_++;
        }
    }
#endif
    else
    {
        CharacterModel_SetAngle(self->characterModels_[0], CreationAngle_Default);
        CharacterModel_SetAngle(self->characterModels_[1], CreationAngle_Default);
        CharacterModel_Load(self->characterModels_[0], self->characterData_, self->characterData_->unk_568, 0, 0);
        CharacterModel_Load(self->characterModels_[1], self->characterData_, self->characterData_->unk_568, 0, 0);
        self->character_ = self->characterModels_[0];
        self->nextCharacter_ = self->characterModels_[1];
        CharacterCreationUI_CreateSummaryPane(self);
        func_ov023_021d9c7c(self);
        CharacterCreationUI_CreateNamePane(self);
        Window_SetPanePalette((Struct_0205d81c*)&self->windows_[CreationWindowIndex_Bottom], BottomWindow_UnknownPane2, 0);
        Window_SetPanePalette((Struct_0205d81c*)&self->windows_[CreationWindowIndex_Bottom], BottomWindow_NamePane, 0);
#if defined(jpn)
        func_ov009_02185888(&self->nameFilter_);
        NameFilter_Reset(&self->nameFilter_);
        self->nameFilter_.allocator = &self->allocators_[CreationAllocator_NameFilter];
        self->nameFilter_.field12 = 1;
        func_ov009_02185c58(&self->nameFilter_);
#endif
        CharacterCreationUI_SwitchTab((unsigned char*)self, CreationTab_Gender);
    }
}
