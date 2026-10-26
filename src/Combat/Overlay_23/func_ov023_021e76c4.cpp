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
    char unk_1e[2];
};

struct Struct_ov023_021e76c4_5 {
    Struct_ov023_021e76c4_5* unknown_0_;
    Struct_ov023_021e76c4_4* unknown_4_;
    char unknown_8_[0xe0 - 8];
};

struct Struct_ov023_021e76c4_6 {
    char unknown_0_[0x98];
    Struct_ov023_021e76c4_4* unknown_98_;
    char unknown_9c_[0xb2 - 0x9c];
    unsigned char unknown_b2_;
    char unknown_b3_[0xbc - 0xb3];
};

struct Struct_ov023_021e76c4 {
    char unknown_0_[8];
    unsigned int unknown_8_;
    void* unknown_c_;
};

struct Struct_ov023_021e76c4_2 {
#if defined(jpn)
    char unknown_0_[0x28];
#else
    char unknown1_0_[0x5c];
#endif
    void* unknown_5c_;
};

struct Struct_ov023_021e76c4_3 {
    SafeAllocator unknown_0_[3];
    int unknown_3c_;
    unsigned int unknown_40_;
    unsigned int unknown_44_;
    unsigned int unknown_48_;
    char unknown_4c_[0x18];
    char unknown_64_[0x10];
    unsigned char unknown_74_;
    unsigned char unknown_75_;
    char unknown_76_[2];
    Struct_ov023_021e76c4_6 unknown_78_;
    Struct_ov023_021e76c4_4 unknown_134_[2];
    Struct_ov023_021e76c4_5 unknown_174_[5];
    void* unknown_5d4_;
    char* unknown_5d8_;
    int unknown_5dc_;
    int unknown_5e0_;
    int unknown_5e4_;
};

struct BackgroundGraphics;
struct PacRecord;
struct WindowPane;
struct Struct_0205cf78;
struct WindowPane;

MessageSystem_021e76c4* MessageSystem_GetInstance();
void Background_SetMapSize(unsigned char* obj, int value);
void Background_AllocateMap(BackgroundGraphics* obj, SafeAllocator* alloc);
int Background_SetScroll(BackgroundGraphics* obj, int a, int b);
void Background_AllocateScreens(BackgroundGraphics* obj, int count, SafeAllocator* alloc);
int Pac_CountFiles(PacRecord* entry);
void* Pac_GetFile(PacRecord* rec, int index, void** out, int* out44);
void Background_UploadMap(BackgroundGraphics* obj, void* buf);
ScreenData_021e76c4* Background_GetScreen(BackgroundGraphics* list, unsigned int index);
void WindowPane_AllocateBuffer(WindowPane* obj, SafeAllocator* alloc, int val, unsigned int len);
void Window_SetPanes(Struct_0205cf78* s, WindowPane* arr, unsigned char count);

extern "C" {
void __clear(void* buffer, unsigned long size);
void KeyTable_Load(void* texts, SafeAllocator* allocator, void* file, unsigned int size);
void Background_SetPriority(BackgroundGraphics_021e76c4* background, int index);
void DisableSubBGVRAMBanks();
void MapVRAMBanksToSubBG(int banks);
void Background_LoadFile(BackgroundGraphics_021e76c4* background, void* file, SafeAllocator* allocator, unsigned int size);
void Background_FillRect(BackgroundGraphics_021e76c4* background, int a, int b, int c, int d, int e, int f);
void LoadToSubBG1ScreenData(void* data, int offset, unsigned int size);
void func_020dc7e8(int arg0, int arg1);
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
extern "C" ARM int func_ov023_021e76c4(Struct_ov023_021e76c4_3* arg0)
{
    void* var0[4];
    unsigned int var1[4];
    void* var2;
    unsigned int var3;
    int var4[2];
    char var5[4];
    void* var6;
    unsigned int var7;
    if (arg0->unknown_5dc_ != 0)
        return 1;
    int var8 = 1;
    BackgroundLoader* var9 = BackgroundLoader::GetInstance();
    if (arg0->unknown_5e0_ == 0)
    {
        REG_BG0OFS_SUB = 0;
        REG_BG1OFS_SUB = 0;
#if defined(jpn)
        arg0->unknown_5e4_ = var9->QueueLoadFile(data_ov023_021fd018, NULL);
#else
        arg0->unknown_5e4_ = var9->QueueLoadFileInGP2(data_ov023_021fdd6e, data_ov023_021fdd88, NULL);
#endif
        var8 = 0;
        arg0->unknown_5e0_++;
    }
    else if (arg0->unknown_5e0_ == 1)
    {
        if (var9->GetTaskStatus(arg0->unknown_5e4_))
        {
            loader->GetLoadedFileByID(self->task_, &file, &size);
            self->allocators_[2].Reset();
            KeyTable_Load(self->cardTexts_, &self->allocators_[2], file, size);
            loader->RemoveTask(self->task_);
            self->task_ = -1;
            self->step_++;
        }
        var8 = 0;
    }
    else if (arg0->unknown_5e0_ == 2)
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
    else if (arg0->unknown_5e0_ == 3)
    {
        if (var9->GetTaskStatus(arg0->unknown_5e4_))
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
                void* var17;
                unsigned int var18;
                var18 = var16->unknown_8_;
                var17 = var16->unknown_c_;
                CleanInvalidateCacheRange(var17, var18);
                LoadToSubBG1ScreenData(var17, 0, var18);
            }
            arg0->unknown_5d4_ = arg0->unknown_0_[0].Allocate(0x4e00);
            Struct_ov023_021e76c4_5* var19;
            int var20;
            for (var20 = 0; var20 < 4; var20++)
            {
                canvas = &self->canvases_[j];
                WindowPane_AllocateBuffer((WindowPane*)canvas, &self->allocators_[1], (int)self->pixels_, 0x600);
                canvas->background_ = &self->backgrounds_[0];
            }
            canvas = &self->canvases_[4];
            WindowPane_AllocateBuffer((WindowPane*)canvas, &self->allocators_[1], (int)self->pixels_, 0x40);
            canvas->background_ = &self->backgrounds_[0];
            self->window_.background_ = &self->backgrounds_[0];
            self->window_.unk_b2 = 1;
            Window_SetPanes((Struct_0205cf78*)&self->window_, (WindowPane*)self->canvases_, 5);
            self->step_++;
        }
        var8 = 0;
    }
    else if (arg0->unknown_5e0_ == 4)
    {
        REG_DISPCNT_SUB = (REG_DISPCNT_SUB & ~0x1f00) | 0x1300;
        arg0->unknown_5dc_ = var8;
        arg0->unknown_5e0_ = 0;
        func_020dc7e8(2, -1);
        CleanInvalidateCacheRange(&data_ov023_021fd760, 2);
        LoadToSubBGStandardPalette(&data_ov023_021fd760, 2, 2);
        CleanCacheRange(&data_ov023_021fd760, 2);
        CleanInvalidateCacheRange(&data_ov023_021fd760, 2);
        LoadToSubBGStandardPalette(&data_ov023_021fd760, 0x22, 2);
        CleanCacheRange(&data_ov023_021fd760, 2);
    }
    return var8;
}
