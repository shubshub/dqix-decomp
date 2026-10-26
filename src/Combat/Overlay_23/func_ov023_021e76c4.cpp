#include <globaldefs.h>
#include <Filesystem/BackgroundLoader.h>
#include <Memory/SafeAllocator.h>
#include <NitroSDK/Cache.h>

#define REG_DISPCNT_SUB (*(volatile unsigned int*)0x04001000)
#define REG_BG0CNT_SUB (*(volatile unsigned short*)0x04001008)
#define REG_BG1CNT_SUB (*(volatile unsigned short*)0x0400100a)
#define REG_BG0OFS_SUB (*(volatile unsigned int*)0x04001010)
#define REG_BG1OFS_SUB (*(volatile unsigned int*)0x04001014)
#define REG_BLDCNT_SUB (*(volatile unsigned short*)0x04001050)

struct BackgroundGraphics_021e76c4 {
    char unk_0[0x1c];
    unsigned char subScreen_ : 4;
    unsigned char bgNumber_ : 4;
    unsigned char screenCount_;
    char unknown_1e_[2];
};

struct Struct_ov023_021e76c4_5 {
    Struct_ov023_021e76c4_5* unk_0;
    BackgroundGraphics_021e76c4* background_;
    char unk_8[0xe0 - 8];
};

struct Struct_ov023_021e76c4_6 {
    char unknown_0_[0x98];
    BackgroundGraphics_021e76c4* background_;
    char unknown_9c_[0xb2 - 0x9c];
    unsigned char unknown_b2_;
    char unknown_b3_[0xbc - 0xb3];
};

struct ScreenData_021e76c4 {
    char unk_0[8];
    unsigned int size_;
    void* unknown_c_;
};

struct MessageSystem_021e76c4 {
#if defined(jpn)
    char unk_0[0x28];
#else
    char unk_0[0x5c];
#endif
    void* unk_5c;
};

struct Struct_ov023_021e76c4_3 {
    SafeAllocator allocators_[3];
    int mode_;
    unsigned int unknown_40_;
    unsigned int unknown_44_;
    unsigned int unknown_48_;
    char cardTexts_[0x18];
    char unk_64[0x10];
    unsigned char unknown_74_;
    unsigned char unknown_75_;
    char unk_76[2];
    Struct_ov023_021e76c4_6 window_;
    BackgroundGraphics_021e76c4 backgrounds_[2];
    Struct_ov023_021e76c4_5 canvases_[5];
    void* pixels_;
    char* text_;
    int loaded_;
    int step_;
    int task_;
};

struct BackgroundGraphics;
struct PacRecord;
struct WindowPane;
struct Struct_0205cf78;
struct WindowPane;

extern "C" MessageSystem_021e76c4* MessageSystem_GetInstance();
extern "C" void Background_SetMapSize(unsigned char* obj, int value);
extern "C" void Background_AllocateMap(BackgroundGraphics* obj, SafeAllocator* alloc);
extern "C" int Background_SetScroll(BackgroundGraphics* obj, int a, int b);
extern "C" void Background_AllocateScreens(BackgroundGraphics* obj, int count, SafeAllocator* alloc);
extern "C" int Pac_CountFiles(PacRecord* entry);
extern "C" void* Pac_GetFile(PacRecord* rec, int index, void** out, int* out44);
extern "C" void Background_UploadMap(BackgroundGraphics* obj, void* buf);
extern "C" ScreenData_021e76c4* Background_GetScreen(BackgroundGraphics* list, unsigned int index);
extern "C" void WindowPane_AllocateBuffer(WindowPane* obj, SafeAllocator* alloc, int val, unsigned int len);
extern "C" void Window_SetPanes(Struct_0205cf78* s, WindowPane* arr, unsigned char count);

extern "C" {
void __clear(void* buffer, unsigned long size);
void KeyTable_Load(void* texts, SafeAllocator* allocator, void* file, unsigned int size);
void Background_SetPriority(BackgroundGraphics_021e76c4* background, int index);
void DisableSubBGVRAMBanks();
void MapVRAMBanksToSubBG(int banks);
void Background_LoadFile(BackgroundGraphics_021e76c4* background, void* file, SafeAllocator* allocator, unsigned int size);
void Background_FillRect(BackgroundGraphics_021e76c4* background, int a, int b, int c, int d, int e, int f);
void LoadToSubBG1ScreenData(void* data, int offset, unsigned int size);
void func_020dc7e8(int a, int b);
void LoadToSubBGStandardPalette(const void* data, int offset, unsigned int size);
}

extern const char data_ov023_021fdd6e[];
#if defined(jpn)
extern const char data_ov023_021fd018[];
#endif
extern const char data_ov023_021fdd88[];
extern const char data_ov023_021fdd99[];
extern const unsigned short data_ov023_021fd760;

// USA: func_ov023_021e76c4
extern "C" ARM int func_ov023_021e76c4(Struct_ov023_021e76c4_3* self)
{
    void* files[4];
    unsigned int sizes[4];
    void* file;
    unsigned int size;
    int screens[2];
    char name[4];
    void* archive;
    unsigned int archiveSize;
    if (self->loaded_ != 0)
        return 1;
    int result = 1;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (self->step_ == 0)
    {
        REG_BG0OFS_SUB = 0;
        REG_BG1OFS_SUB = 0;
#if defined(jpn)
        self->task_ = loader->QueueLoadFile(data_ov023_021fd018, NULL);
#else
        self->task_ = loader->QueueLoadFileInGP2(data_ov023_021fdd6e, data_ov023_021fdd88, NULL);
#endif
        result = 0;
        self->step_++;
    }
    else if (self->step_ == 1)
    {
        if (loader->GetTaskStatus(self->task_))
        {
            loader->GetLoadedFileByID(self->task_, &file, &size);
            self->allocators_[2].Reset();
            KeyTable_Load(self->cardTexts_, &self->allocators_[2], file, size);
            loader->RemoveTask(self->task_);
            self->task_ = -1;
            self->step_++;
        }
        result = 0;
    }
    else if (self->step_ == 2)
    {
        self->allocators_[0].Reset();
        self->text_ = (char*)MessageSystem_GetInstance()->unk_5c;
        __clear(screens, sizeof(screens));
        BackgroundGraphics_021e76c4* background;
        int i;
        for (i = 0; i < 2; i++)
        {
            background = &self->backgrounds_[i];
            Background_SetMapSize((unsigned char*)background, screens[i]);
            background->subScreen_ = 1;
            background->bgNumber_ = i;
            Background_SetPriority(background, i);
            Background_AllocateMap((BackgroundGraphics*)background, &self->allocators_[1]);
            Background_SetScroll((BackgroundGraphics*)background, 0, 0);
        }
        Background_AllocateScreens((BackgroundGraphics*)&self->backgrounds_[1], 1, &self->allocators_[1]);
        DisableSubBGVRAMBanks();
        MapVRAMBanksToSubBG(0x80);
        REG_BG0CNT_SUB = (REG_BG0CNT_SUB & 0x43) | 0xe00;
        REG_BG1CNT_SUB = (REG_BG1CNT_SUB & 0x43) | 0xf00;
        REG_BLDCNT_SUB = 0;
        loader->FreeAllocations();
        self->task_ = loader->QueueLoadFile(data_ov023_021fdd99, NULL);
        result = 0;
        self->step_++;
    }
    else if (self->step_ == 3)
    {
        if (loader->GetTaskStatus(self->task_))
        {
            loader->GetLoadedFileByID(self->task_, &archive, &archiveSize);
            int count = Pac_CountFiles((PacRecord*)archive);
            for (int i = 0; i < count; i++)
                files[i] = Pac_GetFile((PacRecord*)archive, i, (void**)name, (int*)&sizes[i]);
            BackgroundGraphics_021e76c4* background = &self->backgrounds_[0];
            for (int i = 0; i < count; i++)
            {
                if (files[i] != NULL)
                    Background_LoadFile(background, files[i], &self->allocators_[1], sizes[i]);
                background = &self->backgrounds_[1];
            }
            loader->RemoveTask(self->task_);
            self->task_ = -1;
            Background_FillRect(&self->backgrounds_[0], 0, 0, 0, 0x20, 0x19, 0);
            Background_UploadMap((BackgroundGraphics*)&self->backgrounds_[0], 0);
            ScreenData_021e76c4* screen = Background_GetScreen((BackgroundGraphics*)&self->backgrounds_[1], 0);
            if (screen != NULL)
            {
                void* data;
                unsigned int screenSize;
                screenSize = screen->size_;
                data = screen->unknown_c_;
                CleanInvalidateCacheRange(data, screenSize);
                LoadToSubBG1ScreenData(data, 0, screenSize);
            }
            self->pixels_ = self->allocators_[0].Allocate(0x4e00);
            Struct_ov023_021e76c4_5* canvas;
            int j;
            for (j = 0; j < 4; j++)
            {
                canvas = &self->canvases_[j];
                WindowPane_AllocateBuffer((WindowPane*)canvas, &self->allocators_[1], (int)self->pixels_, 0x600);
                canvas->background_ = &self->backgrounds_[0];
            }
            canvas = &self->canvases_[4];
            WindowPane_AllocateBuffer((WindowPane*)canvas, &self->allocators_[1], (int)self->pixels_, 0x40);
            canvas->background_ = &self->backgrounds_[0];
            self->window_.background_ = &self->backgrounds_[0];
            self->window_.unknown_b2_ = 1;
            Window_SetPanes((Struct_0205cf78*)&self->window_, (WindowPane*)self->canvases_, 5);
            self->step_++;
        }
        result = 0;
    }
    else if (self->step_ == 4)
    {
        REG_DISPCNT_SUB = (REG_DISPCNT_SUB & ~0x1f00) | 0x1300;
        self->loaded_ = result;
        self->step_ = 0;
        func_020dc7e8(2, -1);
        CleanInvalidateCacheRange(&data_ov023_021fd760, 2);
        LoadToSubBGStandardPalette(&data_ov023_021fd760, 2, 2);
        CleanCacheRange(&data_ov023_021fd760, 2);
        CleanInvalidateCacheRange(&data_ov023_021fd760, 2);
        LoadToSubBGStandardPalette(&data_ov023_021fd760, 0x22, 2);
        CleanCacheRange(&data_ov023_021fd760, 2);
    }
    return result;
}
