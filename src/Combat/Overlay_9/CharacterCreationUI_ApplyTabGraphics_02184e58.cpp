#include <globaldefs.h>
#include "Graphics/Background.h"
#include "Resource/CharacterCreationUI.h"
#include <std_library_functions.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "NitroSDK/Graphics.h"
#include "NitroSDK/OSLanguage.h"

// DISPCNT bits 8-12: which of BG0-BG3 and the sprites the engine displays.
#define DISPCNT_MASK_DISPLAY 0x1f00
#define DISPCNT_DISPLAY_BG0 0x100
#define DISPCNT_DISPLAY_BG1 0x200
#define DISPCNT_DISPLAY_BG2 0x400
#define DISPCNT_DISPLAY_OBJ 0x1000



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

// Size index 0 of the map size table (Background_mapSizes[0][0] = 0x800 bytes): a 256 x 256 text background.
enum BackgroundMapSize
{
    BackgroundMapSize_Text256x256 = 0,
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

struct BackgroundGraphics;
struct PacRecord;
struct Struct0200fb08;

extern "C" void Background_Init(BackgroundGraphics* layer);
extern "C" void Background_SetMapSize(unsigned char* layer, int mapSize);
extern "C" void Background_SetPriority(BackgroundGraphics* layer, int priority);
extern "C" void Background_SetScroll(BackgroundGraphics* layer, int x, int y);
extern "C" void Background_AllocateMap(BackgroundGraphics* layer, SafeAllocator* allocator);
extern "C" void Background_AllocateScreens(BackgroundGraphics* layer, int screenCount, SafeAllocator* allocator);
extern "C" int Pac_CountFiles(PacRecord* archive);
extern "C" void* Pac_GetFile(PacRecord* archive, int index, void** record, int* size);
extern "C" void Background_LoadFile(BackgroundGraphics* layer, void* file, SafeAllocator* allocator, unsigned int size);
extern "C" void Background_DrawScreen(BackgroundGraphics* layer, unsigned int screen, int sourceX, int sourceY, short destX, short destY,
                           short width, short height, unsigned short palette);
extern "C" void Background_UploadMap(BackgroundGraphics* layer, void* map);
extern "C" void Background_FillRect(BackgroundGraphics* layer, int tile, int x, int y, int width, int height, int palette);
extern "C" int memcmp(const void* left, const void* right, unsigned int length);
extern "C" void Background_FlushFile(void* layer, char* file);
extern "C" void Background_UploadFile(BackgroundGraphics* layer, char* file);
extern "C" void* Background_GetScreen(BackgroundGraphics* layer, unsigned int index);
extern "C" void Background_CopyScreenRect(BackgroundGraphics* unused, void* destination, void* source, int sourceX, int sourceY,
                              int destX, int destY, int width, int height, int palette);
extern "C" int GameState_GetLanguage(Struct0200fb08* state);
extern "C" void CharacterCreationUI_DrawTabLayers(void* self);
extern "C" void func_ov023_021d9d34(char* self);
extern "C" void CharacterCreationUI_RefreshNameText(char* self);

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

// The scene at jpn offsets; each padN stands for the header's (CharacterCreationUI) fields from offset N.
struct CharacterCreation {
    SafeAllocator allocators_[2];
    char pad28[0xfc - 0x28];
    BackgroundGraphics layers_[5];
    char pad19c[0xc1c - 0x19c];
    signed char state_;
    unsigned char step_;
    char padC1e[0xd54 - 0xc1e];
    int resourceTask_;
    unsigned char resourceStep_;
    unsigned char mode_;
    char padD5a[0xd60 - 0xd5a];
    unsigned int flags_;
    char padD64[0xd8f - 0xd64];
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
            Background_Init((BackgroundGraphics*)layer);
            Background_SetMapSize((unsigned char*)layer, BackgroundMapSize_Text256x256);
            layer->subScreen_ = 0;
            layer->bgNumber_ = CharacterCreationUI_finishBgNumbers[i];
            Background_SetPriority(layer, CharacterCreationUI_finishBgPriorities[i]);
            Background_SetScroll((BackgroundGraphics*)layer, 0, 0);
            Background_AllocateMap((BackgroundGraphics*)layer, &self->allocators_[0]);
            if (CharacterCreationUI_finishBgScreenCounts[i] > 0)
                Background_AllocateScreens((BackgroundGraphics*)layer, (unsigned char)CharacterCreationUI_finishBgScreenCounts[i], &self->allocators_[0]);
        }
        char record[4];
        void* archive;
        unsigned int archiveSize;
        loader->GetLoadedFileByID(self->resourceTask_, &archive, &archiveSize);
        int fileCount = Pac_CountFiles((PacRecord*)archive);
        if (self->mode_ == CreationMode_PartyMemberCreation)
            fileCount--;
        for (int i = 0; i < fileCount; i++)
        {
            unsigned int fileSize;
            void* file = Pac_GetFile((PacRecord*)archive, i, (void**)record, (int*)&fileSize);
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
        Background_DrawScreen((BackgroundGraphics*)&self->layers_[CreationLayer_Backdrop], 0, 0, 0, 0, 0,
                              BackgroundMap_Columns, BackgroundMap_ScreenRows, BackgroundPalette_Keep);
        Background_UploadMap((BackgroundGraphics*)&self->layers_[CreationLayer_Backdrop], 0);
        Background_FillRect(&self->layers_[CreationLayer_TabHighlight], 0, 0, 0, BackgroundMap_Columns, BackgroundMap_Rows, 0);
        Background_UploadMap((BackgroundGraphics*)&self->layers_[CreationLayer_TabHighlight], 0);
        Background_FillRect(&self->layers_[CreationLayer_SummaryText], 0, 0, 0, BackgroundMap_Columns, BackgroundMap_Rows, 0);
        Background_UploadMap((BackgroundGraphics*)&self->layers_[CreationLayer_SummaryText], 0);
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
        Background_Init((BackgroundGraphics*)layer);
        Background_SetMapSize((unsigned char*)layer, BackgroundMapSize_Text256x256);
        layer->subScreen_ = 1;
        layer->bgNumber_ = CharacterCreationUI_tabBgNumbers[i];
        Background_SetPriority(layer, CharacterCreationUI_tabBgPriorities[i]);
        Background_SetScroll((BackgroundGraphics*)layer, 0, 0);
        Background_AllocateMap((BackgroundGraphics*)layer, &self->allocators_[1]);
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
            Background_AllocateScreens((BackgroundGraphics*)layer, screenCount, &self->allocators_[1]);
    }

    char record[4];
    void* archive;
    unsigned int archiveSize;
    unsigned int fileSize;
    loader->GetLoadedFileByID(self->resourceTask_, &archive, &archiveSize);
    void* file;
    int fileCount = Pac_CountFiles((PacRecord*)archive);
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
        file = Pac_GetFile((PacRecord*)archive, i, (void**)record, (int*)&fileSize);
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
                Background_UploadFile((BackgroundGraphics*)layer, (char*)file);
                if (memcmp(tag, CharacterCreationUI_screenTag, ChunkTag_Length) == 0)
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
    Background_DrawScreen((BackgroundGraphics*)&self->layers_[CreationLayer_Page], pageScreen, 0, 0, 0, 0, BackgroundMap_Columns,
                          BackgroundMap_ScreenRows, BackgroundPalette_Keep);
    Background_FillRect(&self->layers_[CreationLayer_Selection], 0, 0, 0, BackgroundMap_Columns, BackgroundMap_Rows, 0);
    self->flags_ |= CreationFlag_RedrawPanel;
    if (self->layers_[CreationLayer_Selection].screenCount_ != 0)
        CharacterCreationUI_DrawTabLayers(self);
    self->flags_ &= ~CreationFlag_RedrawPanel;
    Background_UploadMap((BackgroundGraphics*)&self->layers_[CreationLayer_Page], 0);
    Background_UploadMap((BackgroundGraphics*)&self->layers_[CreationLayer_Selection], 0);
    self->flags_ |= 0x4000;
    func_ov023_021d9d34((char*)self);
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
// The scene at usa/eur offsets; each padN stands for the header's (CharacterCreationUI) fields from offset N.
struct CharacterCreation {
    SafeAllocator allocators_[9];
    char padB4[0x138 - 0xb4];
    BackgroundGraphics layers_[6];
    char pad1f8[0xc58 - 0x1f8];
    signed char state_;
    unsigned char step_;
    char padC5a[0xd90 - 0xc5a];
    int resourceTask_;
    unsigned char resourceStep_;
    unsigned char mode_;
    char padD96[0xd9c - 0xd96];
    unsigned int flags_;
    char padDa0[0xdb6 - 0xda0];
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
            Background_Init((BackgroundGraphics*)layer);
            Background_SetMapSize((unsigned char*)layer, BackgroundMapSize_Text256x256);
            layer->subScreen_ = 0;
            layer->bgNumber_ = CharacterCreationUI_finishBgNumbers[i];
            Background_SetPriority(layer, CharacterCreationUI_finishBgPriorities[i]);
            Background_SetScroll((BackgroundGraphics*)layer, 0, 0);
            Background_AllocateMap((BackgroundGraphics*)layer, &self->allocators_[0]);
            if (CharacterCreationUI_finishBgScreenCounts[i] > 0)
                Background_AllocateScreens((BackgroundGraphics*)layer, (unsigned char)CharacterCreationUI_finishBgScreenCounts[i], &self->allocators_[0]);
        }
        char record[4];
        void* archive;
        unsigned int archiveSize;
        loader->GetLoadedFileByID(self->resourceTask_, &archive, &archiveSize);
        int fileCount = Pac_CountFiles((PacRecord*)archive);
        if (self->mode_ == CreationMode_PartyMemberCreation)
            fileCount--;
        for (int i = 0; i < fileCount; i++)
        {
            unsigned int fileSize;
            void* file = Pac_GetFile((PacRecord*)archive, i, (void**)record, (int*)&fileSize);
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
        Background_DrawScreen((BackgroundGraphics*)&self->layers_[CreationLayer_Backdrop], 0, 0, 0, 0, 0,
                              BackgroundMap_Columns, BackgroundMap_ScreenRows, BackgroundPalette_Keep);
        Background_UploadMap((BackgroundGraphics*)&self->layers_[CreationLayer_Backdrop], 0);
        Background_FillRect(&self->layers_[CreationLayer_TabHighlight], 0, 0, 0, BackgroundMap_Columns, BackgroundMap_Rows, 0);
        Background_UploadMap((BackgroundGraphics*)&self->layers_[CreationLayer_TabHighlight], 0);
        Background_FillRect(&self->layers_[CreationLayer_SummaryText], 0, 0, 0, BackgroundMap_Columns, BackgroundMap_Rows, 0);
        Background_UploadMap((BackgroundGraphics*)&self->layers_[CreationLayer_SummaryText], 0);
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
        Background_Init((BackgroundGraphics*)layer);
        Background_SetMapSize((unsigned char*)layer, BackgroundMapSize_Text256x256);
        layer->subScreen_ = 1;
        layer->bgNumber_ = CharacterCreationUI_tabBgNumbers[i];
        Background_SetPriority(layer, CharacterCreationUI_tabBgPriorities[i]);
        Background_SetScroll((BackgroundGraphics*)layer, 0, 0);
        Background_AllocateMap((BackgroundGraphics*)layer, &self->allocators_[1]);
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
            Background_AllocateScreens((BackgroundGraphics*)layer, screenCount, &self->allocators_[1]);
    }

    char record[4];
    void* archive;
    unsigned int archiveSize;
    unsigned int fileSize;
    loader->GetLoadedFileByID(self->resourceTask_, &archive, &archiveSize);
    int fileCount = Pac_CountFiles((PacRecord*)archive);
    if (tab == CreationTab_NameEntry)
        self->nameTabFlushPass_ = self->nameTabFlushPass_ == 0 ? 1 : 0;
    unsigned char paletteIndex = 0;
    lastFile = fileCount - 1;
    pageFileCount = pageScreenCount + 1;
    void* file;
    for (int i = 0; i < fileCount; i++)
    {
        file = Pac_GetFile((PacRecord*)archive, i, (void**)record, (int*)&fileSize);
        if (file == NULL)
            continue;
        char tag[ChunkTag_Length + 1] = {};
        memcpy(tag, file, ChunkTag_Length);
        if (memcmp(tag, CharacterCreationUI_paletteTag, ChunkTag_Length) == 0 && CharacterCreationUI_paletteSkipModes[paletteIndex++] == self->mode_)
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
                    Background_UploadFile((BackgroundGraphics*)layer, (char*)file);
                if (memcmp(tag, CharacterCreationUI_screenTag, ChunkTag_Length) == 0)
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
        void* queScreen = Background_GetScreen((BackgroundGraphics*)&self->layers_[CreationLayer_Page], NameTabScreen_Que);
        for (int i = 0; i < NameTabScreen_KeyboardPageCount; i++)
        {
            BackgroundScreen* keyboardPage =
                (BackgroundScreen*)Background_GetScreen((BackgroundGraphics*)&self->layers_[CreationLayer_Page], (unsigned char)i);
            BackgroundGraphics unusedLayer;
            Background_Init((BackgroundGraphics*)&unusedLayer);
            Background_CopyScreenRect(&unusedLayer, keyboardPage->tiles_, queScreen, 0, 0, NameTabQue_X, NameTabQue_Y, NameTabQue_Width,
                          NameTabQue_Height, NameTabQue_Palette);
        }
    }
    Background_DrawScreen((BackgroundGraphics*)&self->layers_[CreationLayer_Page], pageScreen, 0, 0, 0, 0, BackgroundMap_Columns,
                          BackgroundMap_ScreenRows, BackgroundPalette_Keep);
    if (self->layers_[CreationLayer_Page].screenCount_ == PageScreen_CountWithLanguageTexts)
    {
        int language = GameState_GetLanguage((Struct0200fb08*)GameState::GetInstance());
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
            Background_DrawScreen((BackgroundGraphics*)&self->layers_[CreationLayer_Page], languageScreen, 0, 0, LanguageText_X,
                                  LanguageText_Y, LanguageText_Width, LanguageText_Height, BackgroundPalette_Keep);
    }
    Background_FillRect(&self->layers_[CreationLayer_Selection], 0, 0, 0, BackgroundMap_Columns, BackgroundMap_Rows, 0);
    self->flags_ |= CreationFlag_RedrawPanel;
    if (self->layers_[CreationLayer_Selection].screenCount_ != 0)
        CharacterCreationUI_DrawTabLayers(self);
    self->flags_ &= ~CreationFlag_RedrawPanel;
    Background_UploadMap((BackgroundGraphics*)&self->layers_[CreationLayer_Page], 0);
    Background_UploadMap((BackgroundGraphics*)&self->layers_[CreationLayer_Selection], 0);
    self->flags_ |= 0x4000;
    func_ov023_021d9d34((char*)self);
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
