#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"
#include <std_library_functions.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "NitroSDK/Graphics.h"

// DISPCNT bits 8-12: which of BG0-BG3 and the sprites the engine displays.
#define DISPCNT_MASK_DISPLAY 0x1f00
#define DISPCNT_DISPLAY_BG0 0x100
#define DISPCNT_DISPLAY_BG1 0x200
#define DISPCNT_DISPLAY_BG2 0x400
#define DISPCNT_DISPLAY_OBJ 0x1000

// A background layer (CreationTileMap in the header).
struct BackgroundGraphics {
    char unk_0[0x10];
    void* screens_;              // 0x10 bytes per screen
    unsigned short* map_;
    unsigned int mapSize_;       // BackgroundMapSize
    unsigned char subScreen_ : 4;
    unsigned char bgNumber_ : 4;
    unsigned char screenCount_;  // screens loaded
    unsigned char screenCapacity_;
    unsigned char mapType_;
};

// One of a layer's screens (an SCRN file).
struct BackgroundScreen {
    short width_;
    short height_;
    char unk_4[8];
    unsigned short* tiles_;
};

// CharacterCreationUI::layers.

// The layers the new-game finish rebuilds (Backdrop, TabHighlight, Summary), as CharacterCreationUI_finishBg* list them.
enum FinishLayer
{
    FinishLayer_Count = 3,
};

// The layers a tab rebuilds, as CharacterCreationUI_tabBg* and _tabScreenCounts list them.
enum TabLayer
{
    TabLayer_Page = 0,
    TabLayer_Selection = 1,
    TabLayer_Count = 2,
};

// Size index 0 of the map size table (data_020e7b98[0][0] = 0x800 bytes): a 256 x 256 text background.
enum BackgroundMapSize
{
    BackgroundMapSize_Text256x256 = 0,
};

// How Background_CopyScreenRect and Background_FillRect address a map: 32 tiles a row, clipped at 25 rows; 24 rows fill the screen.
enum BackgroundMap
{
    BackgroundMap_Columns = 32,
    BackgroundMap_ScreenRows = 24,
    BackgroundMap_ClipRows = 25,
};

// The palette argument that keeps each tile's own palette bits.
enum BackgroundPalette
{
    BackgroundPalette_Keep = 0xffff,
};

// Rows of CharacterCreationUI_tabScreenCounts: {tab, page screens, selection screens}.
enum TabScreenCountsRow
{
    TabScreenCountsRow_FirstCount = 1,
    TabScreenCountsRow_Size = 3,
};

// The 4-character tag an archive file starts with ("CHAR", "PALT", "SCRN").
enum ChunkTag
{
    ChunkTag_Length = 4,
};

// bg_cm_msbg.pac, the new-game finish's archive: cm_win_clear_chara.bncg, one blank tile.
enum FinishArchiveFile
{
    FinishArchiveFile_ClearTile = 2,
};

// Screens of the page layer, from the tab archives (bg_cm_*.pac).
enum PageScreen
{
    PageScreen_Page = 0,
    PageScreen_GenderNewGame = 1, // cm_sex_back.bnsc; screen 0 is cm_sex_back_npc.bnsc
    PageScreen_French = 1,        // tabs 2-7: cm_*_fr.bnsc, 13 x 3 tiles
    PageScreen_Italian = 2,
    PageScreen_German = 3,
    PageScreen_Spanish = 4,
    PageScreen_CountWithLanguageTexts = 5,
};

// Where a language text goes on the page.
enum LanguageText
{
    LanguageText_X = 1,
    LanguageText_Y = 1,
    LanguageText_Width = 13,
    LanguageText_Height = 3,
};

// The name tab's page screens (bg_cm_nm.pac): cm_name_small, _capital, _europe, _symbol, then cm_name_que.
enum NameTabScreen
{
    NameTabScreen_KeyboardPageCount = 4,
    NameTabScreen_Que = 4,
};

// cm_name_que.bnsc (4 x 2 tiles), copied onto each keyboard page in party member creation.
enum NameTabQue
{
    NameTabQue_X = 19,
    NameTabQue_Y = 17,
    NameTabQue_Width = 4,
    NameTabQue_Height = 2,
    NameTabQue_Palette = 1,
};

// OS owner info's language (NitroSDK OSLanguage), as NormalizeField5_0200fb08 returns it.
enum OSLanguage
{
    OSLanguage_French = 2,
    OSLanguage_German = 3,
    OSLanguage_Italian = 4,
    OSLanguage_Spanish = 5,
};

struct List0204af64;
struct Obj0204b5e8;
struct AllocTarget0204b12c;
struct Foo0204af38;
struct Rec020467f0;
struct ActiveEntry02046900;
struct Obj0204b8d0;
struct List0204b0e8;
struct SelfTag0204b3a0;
struct EntryList0204af14;
struct Struct0200fb08;

void Background_Init(List0204af64* layer);
void Background_SetMapSize(unsigned char* layer, int mapSize);
extern "C" void Background_SetPriority(BackgroundGraphics* layer, int priority);
void Background_SetScroll(Obj0204b5e8* layer, int x, int y);
void Background_AllocateMap(AllocTarget0204b12c* layer, SafeAllocator* allocator);
void Background_AllocateScreens(Foo0204af38* layer, int screenCount, SafeAllocator* allocator);
int Pac_CountFiles(ActiveEntry02046900* archive);
void* Pac_GetFile(Rec020467f0* archive, int index, void** record, int* size);
extern "C" void Background_LoadFile(BackgroundGraphics* layer, void* file, SafeAllocator* allocator, unsigned int size);
void Background_DrawScreen(Obj0204b8d0* layer, unsigned int screen, int sourceX, int sourceY, short destX, short destY,
                           short width, short height, unsigned short palette);
void Background_UploadMap(List0204b0e8* layer, void* map);
extern "C" void Background_FillRect(BackgroundGraphics* layer, int tile, int x, int y, int width, int height, int palette);
extern "C" int func_02001aec(const void* left, const void* right, unsigned int length);
void Background_FlushFile(void* layer, char* file);
void Background_UploadFile(SelfTag0204b3a0* layer, char* file);
void* Background_GetScreen(EntryList0204af14* layer, unsigned int index);
extern "C" void Background_CopyScreenRect(BackgroundGraphics* unused, void* destination, void* source, int sourceX, int sourceY,
                              int destX, int destY, int width, int height, int palette);
int NormalizeField5_0200fb08(Struct0200fb08* state);
extern "C" void CharacterCreationUI_DrawTabLayers(void* self);
void RefreshFieldIfFlag4000_021d9d34(char* self);
void CharacterCreationUI_RefreshNameText(char* self);

extern const unsigned char CharacterCreationUI_paletteSkipModes[];
extern const unsigned char CharacterCreationUI_tabBgNumbers[];
extern const signed char CharacterCreationUI_tabBgPriorities[];
extern const unsigned char CharacterCreationUI_finishBgNumbers[];
extern const signed char CharacterCreationUI_finishBgScreenCounts[];
extern const signed char CharacterCreationUI_finishBgPriorities[];
extern const signed char CharacterCreationUI_tabScreenCounts[];
extern char CharacterCreationUI_paletteTag[];
extern char CharacterCreationUI_screenTag[];

#if defined(jpn)
extern const unsigned char CharacterCreationUI_tabBgNumbers[];
extern const signed char CharacterCreationUI_tabBgPriorities[];
extern const unsigned char CharacterCreationUI_finishBgNumbers[];
extern const signed char CharacterCreationUI_finishBgScreenCounts[];
extern const signed char CharacterCreationUI_finishBgPriorities[];
extern const signed char CharacterCreationUI_tabScreenCounts[];
extern char CharacterCreationUI_screenTag[];

struct CharacterCreation {
    SafeAllocator allocators_[2];
    char unk_28[0xfc - 0x28];
    BackgroundGraphics layers_[5];
    char unk_19c[0xc1c - 0x19c];
    signed char state_;
    unsigned char step_;
    char unk_c1e[0xd54 - 0xc1e];
    int resourceTask_;
    unsigned char resourceStep_;
    unsigned char mode_;
    char unk_d5a[0xd60 - 0xd5a];
    unsigned int flags_;
    char unk_d64[0xd8f - 0xd64];
    unsigned char nameTabFlushPass_;
};

// Overlay 9, originally func_ov009_02184e58 (USA/EUR 0x02184e58, JPN 0x02186158)
extern "C" ARM void CharacterCreationUI_ApplyTabGraphics(CharacterCreation* self)
{
    int pageScreenCount;
    int pageFileCount;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (self->resourceStep_ != TabLoadStep_Loaded)
        return;

    if (self->state_ == CreationTab_NewGameFinish)
    {
        self->allocators_[0].Reset();
        BackgroundGraphics* layers[] = {&self->layers_[CreationLayer_Backdrop], &self->layers_[CreationLayer_TabHighlight],
                                        &self->layers_[CreationLayer_SummaryText]};
        for (int i = 0; i < FinishLayer_Count; i++)
        {
            BackgroundGraphics* layer = layers[i];
            Background_Init((List0204af64*)layer);
            Background_SetMapSize((unsigned char*)layer, BackgroundMapSize_Text256x256);
            layer->subScreen_ = 0;
            layer->bgNumber_ = CharacterCreationUI_finishBgNumbers[i];
            Background_SetPriority(layer, CharacterCreationUI_finishBgPriorities[i]);
            Background_SetScroll((Obj0204b5e8*)layer, 0, 0);
            Background_AllocateMap((AllocTarget0204b12c*)layer, &self->allocators_[0]);
            if (CharacterCreationUI_finishBgScreenCounts[i] > 0)
                Background_AllocateScreens((Foo0204af38*)layer, (unsigned char)CharacterCreationUI_finishBgScreenCounts[i], &self->allocators_[0]);
        }
        char record[4];
        void* archive;
        unsigned int archiveSize;
        loader->GetLoadedFileByID(self->resourceTask_, &archive, &archiveSize);
        int fileCount = Pac_CountFiles((ActiveEntry02046900*)archive);
        if (self->mode_ == CreationMode_PartyMemberCreation)
            fileCount--;
        for (int i = 0; i < fileCount; i++)
        {
            unsigned int fileSize;
            void* file = Pac_GetFile((Rec020467f0*)archive, i, (void**)record, (int*)&fileSize);
            if (file != NULL)
            {
                if (i == FinishArchiveFile_ClearTile)
                {
                    Background_LoadFile(&self->layers_[CreationLayer_TabHighlight], file, &self->allocators_[0], fileSize);
                    Background_LoadFile(&self->layers_[CreationLayer_SummaryText], file, &self->allocators_[0], fileSize);
                }
                else
                {
                    Background_LoadFile(&self->layers_[CreationLayer_Backdrop], file, &self->allocators_[0], fileSize);
                }
            }
        }
        loader->RemoveTask(self->resourceTask_);
        self->resourceTask_ = -1;
        Background_DrawScreen((Obj0204b8d0*)&self->layers_[CreationLayer_Backdrop], 0, 0, 0, 0, 0,
                              BackgroundMap_Columns, BackgroundMap_ScreenRows, BackgroundPalette_Keep);
        Background_UploadMap((List0204b0e8*)&self->layers_[CreationLayer_Backdrop], 0);
        Background_FillRect(&self->layers_[CreationLayer_TabHighlight], 0, 0, 0, BackgroundMap_Columns, BackgroundMap_ClipRows, 0);
        Background_UploadMap((List0204b0e8*)&self->layers_[CreationLayer_TabHighlight], 0);
        Background_FillRect(&self->layers_[CreationLayer_SummaryText], 0, 0, 0, BackgroundMap_Columns, BackgroundMap_ClipRows, 0);
        Background_UploadMap((List0204b0e8*)&self->layers_[CreationLayer_SummaryText], 0);
        self->flags_ &= ~CreationFlag_TabLoading;
        self->resourceStep_ = TabLoadStep_Queue;
        return;
    }

    DISPCNTSUB = (DISPCNTSUB & ~DISPCNT_MASK_DISPLAY) | (DISPCNT_DISPLAY_BG0 | DISPCNT_DISPLAY_BG2 | DISPCNT_DISPLAY_OBJ);
    self->allocators_[1].Reset();
    pageScreenCount = 0;
    BackgroundGraphics* layers[] = {&self->layers_[CreationLayer_Page], &self->layers_[CreationLayer_Selection]};
    for (int i = 0; i < TabLayer_Count; i++)
    {
        BackgroundGraphics* layer = layers[i];
        Background_Init((List0204af64*)layer);
        Background_SetMapSize((unsigned char*)layer, BackgroundMapSize_Text256x256);
        layer->subScreen_ = 1;
        layer->bgNumber_ = CharacterCreationUI_tabBgNumbers[i];
        Background_SetPriority(layer, CharacterCreationUI_tabBgPriorities[i]);
        Background_SetScroll((Obj0204b5e8*)layer, 0, 0);
        Background_AllocateMap((AllocTarget0204b12c*)layer, &self->allocators_[1]);
        unsigned char screenCount = 0;
        for (int row = 0; CharacterCreationUI_tabScreenCounts[row] >= 0; row += TabScreenCountsRow_Size)
        {
            if (self->state_ == CharacterCreationUI_tabScreenCounts[row])
            {
                screenCount = CharacterCreationUI_tabScreenCounts[row + i + TabScreenCountsRow_FirstCount];
                if (i == TabLayer_Page)
                    pageScreenCount = screenCount;
                break;
            }
        }
        if (screenCount != 0)
            Background_AllocateScreens((Foo0204af38*)layer, screenCount, &self->allocators_[1]);
    }

    char record[4];
    void* archive;
    unsigned int archiveSize;
    unsigned int fileSize;
    loader->GetLoadedFileByID(self->resourceTask_, &archive, &archiveSize);
    void* file;
    int fileCount = Pac_CountFiles((ActiveEntry02046900*)archive);
    if (self->state_ == CreationTab_NameEntry)
    {
        if (self->nameTabFlushPass_ != 0)
            self->nameTabFlushPass_ = 0;
        else
            self->nameTabFlushPass_ = 1;
    }
    if (self->mode_ == CreationMode_PartyMemberCreation)
        fileCount--;
    int pageFileCountBothModes = pageScreenCount * 2 + 1;
    pageFileCount = pageScreenCount + 1;
    for (int i = 0; i < fileCount; i++)
    {
        file = Pac_GetFile((Rec020467f0*)archive, i, (void**)record, (int*)&fileSize);
        if (file == NULL)
            continue;
        if (self->state_ == CreationTab_NameEntry)
        {
            BackgroundGraphics* layer = &self->layers_[CreationLayer_Selection];
            if (i < pageFileCountBothModes)
            {
                if (self->mode_ == CreationMode_PartyMemberCreation)
                {
                    if (i >= pageFileCount)
                        continue;
                }
                else if (i < pageFileCount && i != 0)
                {
                    continue;
                }
                layer = &self->layers_[CreationLayer_Page];
            }
            if (self->nameTabFlushPass_ != 0)
            {
                Background_FlushFile(layer, (char*)file);
            }
            else
            {
                char tag[ChunkTag_Length + 1] = {};
                memcpy(tag, file, ChunkTag_Length);
                Background_UploadFile((SelfTag0204b3a0*)layer, (char*)file);
                if (func_02001aec(tag, CharacterCreationUI_screenTag, ChunkTag_Length) == 0)
                    Background_LoadFile(layer, file, &self->allocators_[1], fileSize);
            }
        }
        else if (i < pageFileCount)
        {
            Background_LoadFile(&self->layers_[CreationLayer_Page], file, &self->allocators_[1], fileSize);
        }
        else
        {
            Background_LoadFile(&self->layers_[CreationLayer_Selection], file, &self->allocators_[1], fileSize);
        }
    }

    if (self->nameTabFlushPass_ != 0)
        return;
    loader->RemoveTask(self->resourceTask_);
    self->resourceTask_ = -1;
    int pageScreen = PageScreen_Page;
    if (self->mode_ == CreationMode_NewGame && self->state_ == CreationTab_Gender)
        pageScreen = PageScreen_GenderNewGame;
    Background_DrawScreen((Obj0204b8d0*)&self->layers_[CreationLayer_Page], pageScreen, 0, 0, 0, 0, BackgroundMap_Columns,
                          BackgroundMap_ScreenRows, BackgroundPalette_Keep);
    Background_FillRect(&self->layers_[CreationLayer_Selection], 0, 0, 0, BackgroundMap_Columns, BackgroundMap_ClipRows, 0);
    self->flags_ |= CreationFlag_RedrawPanel;
    if (self->layers_[CreationLayer_Selection].screenCount_ != 0)
        CharacterCreationUI_DrawTabLayers(self);
    self->flags_ &= ~CreationFlag_RedrawPanel;
    Background_UploadMap((List0204b0e8*)&self->layers_[CreationLayer_Page], 0);
    Background_UploadMap((List0204b0e8*)&self->layers_[CreationLayer_Selection], 0);
    self->flags_ |= 0x4000;
    RefreshFieldIfFlag4000_021d9d34((char*)self);
    self->flags_ &= ~0x4000;
    self->flags_ |= CreationFlag_RefreshName;
    CharacterCreationUI_RefreshNameText((char*)self);
    self->flags_ &= ~CreationFlag_RefreshName;
    self->flags_ &= ~CreationFlag_TabLoading;
    self->resourceStep_ = TabLoadStep_Queue;
    DISPCNTSUB = (DISPCNTSUB & ~DISPCNT_MASK_DISPLAY)
                 | (DISPCNT_DISPLAY_BG0 | DISPCNT_DISPLAY_BG1 | DISPCNT_DISPLAY_BG2 | DISPCNT_DISPLAY_OBJ);
}
#else
struct CharacterCreation {
    SafeAllocator allocators_[9];
    char unk_b4[0x138 - 0xb4];
    BackgroundGraphics layers_[6];
    char unk_1f8[0xc58 - 0x1f8];
    signed char state_;
    unsigned char step_;
    char unk_c5a[0xd90 - 0xc5a];
    int resourceTask_;
    unsigned char resourceStep_;
    unsigned char mode_;
    char unk_d96[0xd9c - 0xd96];
    unsigned int flags_;
    char unk_da0[0xdb6 - 0xda0];
    unsigned char nameTabFlushPass_;
};

// Overlay 9, originally func_ov009_02184e58 (USA/EUR 0x02184e58, JPN 0x02186158)
extern "C" ARM void CharacterCreationUI_ApplyTabGraphics(CharacterCreation* self)
{
    int pageFileCount;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    int pageScreenCount;
    int lastFile;
    signed char tab = self->state_;
    if (self->resourceStep_ != TabLoadStep_Loaded)
        return;

    if (tab == CreationTab_NewGameFinish)
    {
        self->allocators_[0].Reset();
        BackgroundGraphics* layers[] = {&self->layers_[CreationLayer_Backdrop], &self->layers_[CreationLayer_TabHighlight],
                                        &self->layers_[CreationLayer_SummaryText]};
        for (int i = 0; i < FinishLayer_Count; i++)
        {
            BackgroundGraphics* layer = layers[i];
            Background_Init((List0204af64*)layer);
            Background_SetMapSize((unsigned char*)layer, BackgroundMapSize_Text256x256);
            layer->subScreen_ = 0;
            layer->bgNumber_ = CharacterCreationUI_finishBgNumbers[i];
            Background_SetPriority(layer, CharacterCreationUI_finishBgPriorities[i]);
            Background_SetScroll((Obj0204b5e8*)layer, 0, 0);
            Background_AllocateMap((AllocTarget0204b12c*)layer, &self->allocators_[0]);
            if (CharacterCreationUI_finishBgScreenCounts[i] > 0)
                Background_AllocateScreens((Foo0204af38*)layer, (unsigned char)CharacterCreationUI_finishBgScreenCounts[i], &self->allocators_[0]);
        }
        char record[4];
        void* archive;
        unsigned int archiveSize;
        loader->GetLoadedFileByID(self->resourceTask_, &archive, &archiveSize);
        int fileCount = Pac_CountFiles((ActiveEntry02046900*)archive);
        if (self->mode_ == CreationMode_PartyMemberCreation)
            fileCount--;
        for (int i = 0; i < fileCount; i++)
        {
            unsigned int fileSize;
            void* file = Pac_GetFile((Rec020467f0*)archive, i, (void**)record, (int*)&fileSize);
            if (file != NULL)
            {
                if (i == FinishArchiveFile_ClearTile)
                {
                    Background_LoadFile(&self->layers_[CreationLayer_TabHighlight], file, &self->allocators_[0], fileSize);
                    Background_LoadFile(&self->layers_[CreationLayer_SummaryText], file, &self->allocators_[0], fileSize);
                }
                else
                {
                    Background_LoadFile(&self->layers_[CreationLayer_Backdrop], file, &self->allocators_[0], fileSize);
                }
            }
        }
        loader->RemoveTask(self->resourceTask_);
        self->resourceTask_ = -1;
        Background_DrawScreen((Obj0204b8d0*)&self->layers_[CreationLayer_Backdrop], 0, 0, 0, 0, 0,
                              BackgroundMap_Columns, BackgroundMap_ScreenRows, BackgroundPalette_Keep);
        Background_UploadMap((List0204b0e8*)&self->layers_[CreationLayer_Backdrop], 0);
        Background_FillRect(&self->layers_[CreationLayer_TabHighlight], 0, 0, 0, BackgroundMap_Columns, BackgroundMap_ClipRows, 0);
        Background_UploadMap((List0204b0e8*)&self->layers_[CreationLayer_TabHighlight], 0);
        Background_FillRect(&self->layers_[CreationLayer_SummaryText], 0, 0, 0, BackgroundMap_Columns, BackgroundMap_ClipRows, 0);
        Background_UploadMap((List0204b0e8*)&self->layers_[CreationLayer_SummaryText], 0);
        self->flags_ &= ~CreationFlag_TabLoading;
        self->resourceStep_ = TabLoadStep_Queue;
        return;
    }

    DISPCNTSUB = (DISPCNTSUB & ~DISPCNT_MASK_DISPLAY) | (DISPCNT_DISPLAY_BG0 | DISPCNT_DISPLAY_BG2 | DISPCNT_DISPLAY_OBJ);
    self->allocators_[1].Reset();
    pageScreenCount = 0;
    BackgroundGraphics* layers[] = {&self->layers_[CreationLayer_Page], &self->layers_[CreationLayer_Selection]};
    for (int i = 0; i < TabLayer_Count; i++)
    {
        BackgroundGraphics* layer = layers[i];
        Background_Init((List0204af64*)layer);
        Background_SetMapSize((unsigned char*)layer, BackgroundMapSize_Text256x256);
        layer->subScreen_ = 1;
        layer->bgNumber_ = CharacterCreationUI_tabBgNumbers[i];
        Background_SetPriority(layer, CharacterCreationUI_tabBgPriorities[i]);
        Background_SetScroll((Obj0204b5e8*)layer, 0, 0);
        Background_AllocateMap((AllocTarget0204b12c*)layer, &self->allocators_[1]);
        unsigned char screenCount = 0;
        for (int row = 0; CharacterCreationUI_tabScreenCounts[row] >= 0; row += TabScreenCountsRow_Size)
        {
            if (tab == CharacterCreationUI_tabScreenCounts[row])
            {
                screenCount = CharacterCreationUI_tabScreenCounts[row + i + TabScreenCountsRow_FirstCount];
                if (i == TabLayer_Page)
                    pageScreenCount = screenCount;
                break;
            }
        }
        if (screenCount != 0)
            Background_AllocateScreens((Foo0204af38*)layer, screenCount, &self->allocators_[1]);
    }

    char record[4];
    void* archive;
    unsigned int archiveSize;
    unsigned int fileSize;
    loader->GetLoadedFileByID(self->resourceTask_, &archive, &archiveSize);
    int fileCount = Pac_CountFiles((ActiveEntry02046900*)archive);
    if (tab == CreationTab_NameEntry)
        self->nameTabFlushPass_ = self->nameTabFlushPass_ == 0 ? 1 : 0;
    unsigned char paletteIndex = 0;
    lastFile = fileCount - 1;
    pageFileCount = pageScreenCount + 1;
    void* file;
    for (int i = 0; i < fileCount; i++)
    {
        file = Pac_GetFile((Rec020467f0*)archive, i, (void**)record, (int*)&fileSize);
        if (file == NULL)
            continue;
        char tag[ChunkTag_Length + 1] = {};
        memcpy(tag, file, ChunkTag_Length);
        if (func_02001aec(tag, CharacterCreationUI_paletteTag, ChunkTag_Length) == 0 && CharacterCreationUI_paletteSkipModes[paletteIndex++] == self->mode_)
            continue;
        if (tab == CreationTab_NameEntry)
        {
            BackgroundGraphics* layer = &self->layers_[CreationLayer_Selection];
            if (i < pageScreenCount)
                layer = &self->layers_[CreationLayer_Page];
            if (i == lastFile)
                layer = &self->layers_[CreationLayer_Page];
            if (self->nameTabFlushPass_ != 0)
            {
                if (i != lastFile)
                    Background_FlushFile(layer, (char*)file);
            }
            else
            {
                if (i != lastFile)
                    Background_UploadFile((SelfTag0204b3a0*)layer, (char*)file);
                if (func_02001aec(tag, CharacterCreationUI_screenTag, ChunkTag_Length) == 0)
                    Background_LoadFile(layer, file, &self->allocators_[1], fileSize);
            }
        }
        else if (i < pageFileCount)
        {
            Background_LoadFile(&self->layers_[CreationLayer_Page], file, &self->allocators_[1], fileSize);
        }
        else
        {
            Background_LoadFile(&self->layers_[CreationLayer_Selection], file, &self->allocators_[1], fileSize);
        }
    }

    if (self->nameTabFlushPass_ != 0)
        return;
    loader->RemoveTask(self->resourceTask_);
    self->resourceTask_ = -1;
    int pageScreen = PageScreen_Page;
    if (self->mode_ == CreationMode_NewGame && tab == CreationTab_Gender)
        pageScreen = PageScreen_GenderNewGame;
    if (tab == CreationTab_NameEntry && self->mode_ == CreationMode_PartyMemberCreation)
    {
        void* queScreen = Background_GetScreen((EntryList0204af14*)&self->layers_[CreationLayer_Page], NameTabScreen_Que);
        for (int i = 0; i < NameTabScreen_KeyboardPageCount; i++)
        {
            BackgroundScreen* keyboardPage =
                (BackgroundScreen*)Background_GetScreen((EntryList0204af14*)&self->layers_[CreationLayer_Page], (unsigned char)i);
            BackgroundGraphics unusedLayer;
            Background_Init((List0204af64*)&unusedLayer);
            Background_CopyScreenRect(&unusedLayer, keyboardPage->tiles_, queScreen, 0, 0, NameTabQue_X, NameTabQue_Y, NameTabQue_Width,
                          NameTabQue_Height, NameTabQue_Palette);
        }
    }
    Background_DrawScreen((Obj0204b8d0*)&self->layers_[CreationLayer_Page], pageScreen, 0, 0, 0, 0, BackgroundMap_Columns,
                          BackgroundMap_ScreenRows, BackgroundPalette_Keep);
    if (self->layers_[CreationLayer_Page].screenCount_ == PageScreen_CountWithLanguageTexts)
    {
        int language = NormalizeField5_0200fb08((Struct0200fb08*)GameState::GetInstance());
        int languageScreen = 0;
        switch (language)
        {
        case OSLanguage_French:
            languageScreen = PageScreen_French;
            break;
        case OSLanguage_Italian:
            languageScreen = PageScreen_Italian;
            break;
        case OSLanguage_German:
            languageScreen = PageScreen_German;
            break;
        case OSLanguage_Spanish:
            languageScreen = PageScreen_Spanish;
            break;
        }
        if (languageScreen != 0)
            Background_DrawScreen((Obj0204b8d0*)&self->layers_[CreationLayer_Page], languageScreen, 0, 0, LanguageText_X,
                                  LanguageText_Y, LanguageText_Width, LanguageText_Height, BackgroundPalette_Keep);
    }
    Background_FillRect(&self->layers_[CreationLayer_Selection], 0, 0, 0, BackgroundMap_Columns, BackgroundMap_ClipRows, 0);
    self->flags_ |= CreationFlag_RedrawPanel;
    if (self->layers_[CreationLayer_Selection].screenCount_ != 0)
        CharacterCreationUI_DrawTabLayers(self);
    self->flags_ &= ~CreationFlag_RedrawPanel;
    Background_UploadMap((List0204b0e8*)&self->layers_[CreationLayer_Page], 0);
    Background_UploadMap((List0204b0e8*)&self->layers_[CreationLayer_Selection], 0);
    self->flags_ |= 0x4000;
    RefreshFieldIfFlag4000_021d9d34((char*)self);
    self->flags_ &= ~0x4000;
    self->flags_ |= CreationFlag_RefreshName;
    CharacterCreationUI_RefreshNameText((char*)self);
    self->flags_ &= ~CreationFlag_RefreshName;
    self->flags_ &= ~CreationFlag_TabLoading;
    self->resourceStep_ = TabLoadStep_Queue;
    DISPCNTSUB = (DISPCNTSUB & ~DISPCNT_MASK_DISPLAY)
                 | (DISPCNT_DISPLAY_BG0 | DISPCNT_DISPLAY_BG1 | DISPCNT_DISPLAY_BG2 | DISPCNT_DISPLAY_OBJ);
}
#endif
