#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/ColorEffects.h"
#include "NitroSDK/Graphics.h"
#include <globaldefs.h>

struct Background0216b07c {
    char unk_0[0x1c];
    unsigned char subScreen_ : 4;
    unsigned char bgNumber_ : 4;
    unsigned char screenCount_;
    char unk_1e[2];
};

struct Struct_ov003_0216b07c_3 {
    void *unknown_0_;
    Struct_ov003_0216b07c_2 *unknown_4_;
    char unknown_8_[0xc4 - 8];
    unsigned char unknown_c4_;
    char unknown_c5_[0xe0 - 0xc5];
};

struct Struct_ov003_0216b07c_5 {
    char unknown_0_[0x98];
    Struct_ov003_0216b07c_2 *unknown_98_;
    char unknown_9c_[0xb2 - 0x9c];
    unsigned char unknown_b2_;
    char unknown_b3_[0xbc - 0xb3];
};

struct Struct_ov003_0216b07c_6 {
#if defined(jpn)
    char unknown_0_[0x28];
    char *unknown_28_;
    char unknown_2c_[0x868 - 0x2c];
    int unknown_998_;
    int unknown_99c_;
    char unknown_870_[0x17e2 - 0x870];
#else
    char unknown1_0_[0x5c];
    char *unknown_5c_;
    char unknown_60_[0x998 - 0x60];
    int unknown_998_;
    int unknown_99c_;
    char unknown_9a0_[0x19b2 - 0x9a0];
#endif
    unsigned char unknown_19b2_;
};

struct Struct_ov003_0216b07c {
    char unknown_0_[4];
    short unknown_4_;
    short unknown_6_;
    char unknown_8_[2];
    short unknown_a_;
#if defined(jpn)
    char unknown_c_[0x10f4 - 0xc];
#else
    char unknown1_c_[0x1264 - 0xc];
#endif
    int unknown_1264_;
    int unknown_1268_;
    char unknown_126c_[0x12a8 - 0x126c];
    int unknown_12a8_;
    int unknown_12ac_;
    char unknown_12b0_[0x12b8 - 0x12b0];
    short unknown_12b8_;
    char unknown_12ba_[2];
    unsigned char unknown_12bc_;
    char unknown_12bd_[0x12c0 - 0x12bd];
    Struct_ov003_0216b07c_5 *unknown_12c0_;
    Struct_ov003_0216b07c_2 *unknown_12c4_;
    Struct_ov003_0216b07c_3 *unknown_12c8_;
    void *unknown_12cc_;
    SafeAllocator *unknown_12d0_;
    char unknown_12d4_[0x12fc - 0x12d4];
    SafeAllocator unknown_12fc_[2];
    char unknown_1324_[0x13ea - 0x1324];
    unsigned char unknown_13ea_;
    char unknown_13eb_;
    unsigned char unknown_13ec_;
    char unknown_13ed_[0x13fc - 0x13ed];
    int unknown_13fc_[3];
};

struct Obj020397cc;
struct BackgroundGraphics;
struct PacRecord;
struct WindowPane;
struct Struct_0205cf78;
struct WindowPane;

void GameObject_DisableControl(Obj020397cc *obj, int a);
int Text_Append(char *dst, const char *src);
const char *StandardStrings_Get(int id);
void Background_SetMapSize(unsigned char *background, int a);
int Pac_CountFiles(PacRecord *archive);
void *Pac_GetFile(PacRecord *archive, int index, void **name, int *size);
int CheckField0NonZero_0202b7d8(int *p);
extern "C" void *func_0202ae18();
extern "C" int func_0202c508();
extern "C" int func_0202c540(void *arg0);
extern "C" void func_02046380(void *arg0);
#if defined(jpn)
struct Obj02046574;
void MessageSystem_SetStringArgument(Obj02046574 *obj, int index, char *name);
extern "C" void func_0204500c(void *p, const char *text, int a);
extern char data_ov003_0217e930[];
#else
extern "C" void func_0204500c(void *arg0, const char *arg1, int arg2, int arg3);
#endif
extern "C" void SpriteContext_LoadFile(void *renderer, void *file, unsigned int size, SafeAllocator *allocator);
extern "C" void KeyTable_Load(void *texts, SafeAllocator *allocator, void *file, unsigned int size);
extern "C" void Background_SetPriority(Background0216b07c *background, int a);
void Background_AllocateMap(BackgroundGraphics *background,
                                                                                         SafeAllocator *allocator);
void Background_SetScroll(BackgroundGraphics *background, int a, int b);
extern "C" void Background_LoadFile(Background0216b07c *background, void *file, SafeAllocator *allocator, unsigned int size);
extern "C" void Background_FillRect(Background0216b07c *background, int a, int b, int c, int d, int e, int f);
void Background_UploadMap(BackgroundGraphics *background, void *a);
void WindowPane_AllocateBuffer(WindowPane *canvas, SafeAllocator *allocator,
                                                                           int pixels, unsigned int size);
void Window_SetPanes(Struct_0205cf78 *window,
                                                                                     WindowPane *canvases,
                                                                                     unsigned char count);
void *MessageSystem_GetInstance();

struct Struct_ov003_0217f56c {
    const char *unknown_0_[3];
};
extern Struct_ov003_0217f56c data_ov003_0217f56c;
extern char data_ov003_02180198[];

struct Struct_ov003_0216b07c_4 {
    volatile unsigned short unknown_0_0_ : 2;
    volatile unsigned short unknown_0_2_ : 14;
};

// USA: func_ov003_0216b07c
extern "C" ARM void func_ov003_0216b07c(Menu0216b07c *self) {
    Global0216b07c *global   = (Global0216b07c *) MessageSystem_GetInstance();
    GameState *state         = GameState::GetInstance();
    BackgroundLoader *loader = BackgroundLoader::GetInstance();

    if (self->step_ == 0) {
        GameObject_DisableControl((Obj020397cc *) state->GetUnknownGameObject(), 1);
        ColorEffect_ConfigureAlphaBlend(0x4000050, 0x10, 1, 0x1f, 0);
        func_0202ae18();
        if (func_0202c508() != 0 && *(short *) ((char *) var1->GetUnknownGameObject() + 4) == 0) {
            if (arg0->unknown_a_ == 3) {
                var0->unknown_998_ = 1;
#if defined(jpn)
                Text_Append(global->text_, data_ov003_0217e930);
                func_0204500c(global, global->text_, 0);
#else
                char *text      = global->text_;
                Text_Append(text, StandardStrings_Get(0x44));
                func_02046380(global);
                func_0204500c(global, global->text_, 0, 0xe3);
#endif
                var0->unknown_19b2_ = 1;
                var0->unknown_99c_  = 2;
                var0->unknown_998_  = 1;
            }
        } else {
            arg0->unknown_13ea_ = 1;
            arg0->unknown_13ec_ |= 1;
            arg0->unknown_4_ = 3;
            arg0->unknown_6_  = 0;
            return;
        }
        arg0->unknown_12fc_[0].CreateTypeA(arg0->unknown_12d0_->Allocate(0x3800), 0x3800);
        arg0->unknown_12fc_[1].CreateTypeA(arg0->unknown_12d0_->Allocate(0xc00), 0xc00);
        arg0->unknown_12fc_[1].Reset();
        int var4               = 0;
        arg0->unknown_12bc_      = 0;
        arg0->unknown_12ac_      = arg0->unknown_1264_;
        arg0->unknown_12b8_      = 0xf;
        arg0->unknown_12a8_      = arg0->unknown_1268_;
        Struct_ov003_0217f56c var5 = data_ov003_0217f56c;
        int var6            = 0;
        for (; var4 < 3; var4++) {
            int var7;
#if defined(jpn)
            var7 = var2->QueueLoadFile(var5.unknown_0_[var4], (SafeAllocator *) var6);
#else
            if (var4 == 0)
                var7 = var2->QueueLoadFileInGP2(data_ov003_02180198, var5.unknown_0_[var4], (SafeAllocator *) var6);
            else
                var7 = var2->QueueLoadFile(var5.unknown_0_[var4], (SafeAllocator *) var6);
#endif
            arg0->unknown_13fc_[var4] = var7;
        }
        arg0->unknown_6_ = 1;
    }
    if (arg0->unknown_6_ == 1) {
        for (int var8 = 0; var8 < 3; var8++) {
            if (arg0->unknown_13fc_[var8] == -1) continue;
            if (var2->GetTaskStatus(arg0->unknown_13fc_[var8]) != 0) {
                arg0->unknown_6_ = var8 + 2;
                break;
            }
        }
    }
#if defined(jpn)
    if (arg0->unknown_6_ == 2) {
        void *var9;
        void *var10;
        unsigned int var11;
        int var12;
        int var13 = arg0->unknown_13fc_[0];
#else
    if (arg0->unknown_6_ == 4) {
        void *var9;
        void *var10;
        unsigned int var11;
        int var12;
        int var13 = arg0->unknown_13fc_[2];
#endif
        loader->GetLoadedFileByID(task, &file, &size);
        int count            = Pac_CountFiles((PacRecord *) file);
        SafeAllocator *alloc = &self->allocators_[1];
        for (int i = 0; i < count; i++) {
            void *data = Pac_GetFile((PacRecord *) file, i, &name, &fileSize);
#if defined(jpn)
            SpriteContext_LoadFile((char *) self + 0x10fc, data, fileSize, alloc);
#else
            SpriteContext_LoadFile((char *) self + 0x126c, data, fileSize, alloc);
#endif
        }
        var2->RemoveTask(var13);
#if defined(jpn)
        arg0->unknown_13fc_[0] = -1;
#else
        arg0->unknown_13fc_[2] = -1;
#endif
        arg0->unknown_6_     = 1;
    }
#if defined(jpn)
    if (self->step_ == 3) {
        Background_SetMapSize((unsigned char *) self->backgrounds_, 0);
        self->backgrounds_->subScreen_ = 0;
        self->backgrounds_->bgNumber_ = 1;
        Background_SetPriority(self->backgrounds_, 0);
        Background_AllocateMap((BackgroundGraphics *) self->backgrounds_, self->allocator_);
        Background_SetScroll((BackgroundGraphics *) self->backgrounds_, 0, 0);
        BG1CNT = (BG1CNT & 0x43) | 0xd08;
        Background_SetMapSize((unsigned char *) &self->backgrounds_[1], 0);
        self->backgrounds_[1].subScreen_ = 0;
        self->backgrounds_[1].bgNumber_ = 2;
        Background_SetPriority(&self->backgrounds_[1], 1);
        Background_AllocateMap((BackgroundGraphics *) &self->backgrounds_[1], self->allocator_);
        Background_SetScroll((BackgroundGraphics *) &self->backgrounds_[1], 0, 0);
        BG2CNT = (BG2CNT & 0x43) | 0xe08;
        void *name;
        void *file;
        void *datas[2];
        unsigned int size;
        int sizes[2];
        int task = self->tasks_[1];
        loader->GetLoadedFileByID(task, &file, &size);
        int count = Pac_CountFiles((PacRecord *) file);
        for (int i = 0; i < count; i++) {
            datas[i] = Pac_GetFile((PacRecord *) file, i, &name, &sizes[i]);
        }
        for (int i = 0; i < count; i++) {
            if (datas[i] != 0) Background_LoadFile(self->backgrounds_, datas[i], self->allocator_, sizes[i]);
        }
        loader->RemoveTask(task);
        self->tasks_[1] = -1;
        Background_FillRect(self->backgrounds_, 0, 0, 0, 0x20, 0x19, 0);
        Background_UploadMap((BackgroundGraphics *) self->backgrounds_, 0);
        Background_FillRect(&self->backgrounds_[1], 0, 0, 0, 0x20, 0x19, 0);
        Background_UploadMap((BackgroundGraphics *) &self->backgrounds_[1], 0);
        self->pixels_ = self->allocator_->Allocate(0x2800);
        WindowPane_AllocateBuffer((WindowPane *) self->canvases_, self->allocator_, (int) self->pixels_, 0x400);
        self->canvases_->background_ = self->backgrounds_;
        self->canvases_->unk_c4      = 0;
        Window0216b07c *window       = self->window_;
        window->background_          = self->backgrounds_;
        window->unk_b2               = 2;
        Window_SetPanes((Struct_0205cf78 *) self->window_, (WindowPane *) self->canvases_, 1);
        ((BgCnt0216b07c *) 0x4000008)[0].priority_ = 3;
        ((BgCnt0216b07c *) 0x4000008)[1].priority_ = 1;
        ((BgCnt0216b07c *) 0x4000008)[2].priority_ = 2;
        ((BgCnt0216b07c *) 0x4000008)[3].priority_ = 0;
        ColorEffect_ConfigureAlphaBlend(0x4000050, 4, 1, 0xa, 6);
        arg0->unknown_6_ = 1;
    }
#else
    if (self->step_ == 3) {
        Background0216b07c *background = self->backgrounds_;
        Background_SetMapSize((unsigned char *) background, 0);
        background->subScreen_ = 0;
        background->bgNumber_ = 1;
        Background_SetPriority(background, 0);
        Background_AllocateMap((BackgroundGraphics *) background,
                                                                                 self->allocator_);
        Background_SetScroll((BackgroundGraphics *) background, 0, 0);
        BG1CNT                     = (BG1CNT & 0x43) | 0xd08;
        Background0216b07c *second = self->backgrounds_;
        Background_SetMapSize((unsigned char *) &second[1], 0);
        second[1].subScreen_ = 0;
        second[1].bgNumber_ = 2;
        Background_SetPriority(&second[1], 1);
        Background_AllocateMap((BackgroundGraphics *) &second[1],
                                                                                 self->allocator_);
        Background_SetScroll((BackgroundGraphics *) &second[1], 0, 0);
        BG2CNT = (BG2CNT & 0x43) | 0xe08;
        void *name;
        void *file;
        void *datas[2];
        unsigned int size;
        int sizes[2];
        int task = self->tasks_[1];
        loader->GetLoadedFileByID(task, &file, &size);
        int count  = Pac_CountFiles((PacRecord *) file);
        background = self->backgrounds_;
        for (int i = 0; i < count; i++) {
            datas[i] = Pac_GetFile((PacRecord *) file, i, &name, &sizes[i]);
        }
        for (int i = 0; i < count; i++) {
            if (datas[i] != 0) Background_LoadFile(background, datas[i], self->allocator_, sizes[i]);
        }
        loader->RemoveTask(task);
        self->tasks_[1] = -1;
        Background_FillRect(background, 0, 0, 0, 0x20, 0x19, 0);
        Background_UploadMap((BackgroundGraphics *) background, 0);
        second = self->backgrounds_;
        Background_FillRect(&second[1], 0, 0, 0, 0x20, 0x19, 0);
        Background_UploadMap((BackgroundGraphics *) &second[1], 0);
        self->pixels_          = self->allocator_->Allocate(0x2800);
        Canvas0216b07c *canvas = self->canvases_;
        WindowPane_AllocateBuffer((WindowPane *) canvas, self->allocator_,
                                                                   (int) self->pixels_, 0x400);
        canvas->background_    = self->backgrounds_;
        canvas->unk_c4         = 0;
        Window0216b07c *window = self->window_;
        window->background_    = self->backgrounds_;
        window->unk_b2         = 2;
        Window_SetPanes((Struct_0205cf78 *) self->window_,
                                                                             (WindowPane *) self->canvases_, 1);
        ((BgCnt0216b07c *) 0x4000008)[0].priority_ = 3;
        ((BgCnt0216b07c *) 0x4000008)[1].priority_ = 1;
        ((BgCnt0216b07c *) 0x4000008)[2].priority_ = 2;
        ((BgCnt0216b07c *) 0x4000008)[3].priority_ = 0;
        ColorEffect_ConfigureAlphaBlend(0x4000050, 4, 1, 0xa, 6);
        arg0->unknown_6_ = 1;
    }
#endif
#if defined(jpn)
    if (self->step_ == 4) {
        int task = self->tasks_[2];
        void *file;
        unsigned int size;
        loader->GetLoadedFileByID(task, &file, &size);
        self->allocators_[0].Reset();
        KeyTable_Load((char *) self + 0x11b4, &self->allocators_[0], file, size);
        loader->RemoveTask(task);
        self->tasks_[2] = -1;
#else
    if (self->step_ == 2) {
        int task = self->tasks_[0];
        void *file;
        unsigned int size;
        loader->GetLoadedFileByID(task, &file, &size);
        self->allocators_[0].Reset();
        KeyTable_Load((char *) self + 0x1324, &self->allocators_[0], file, size);
        loader->RemoveTask(task);
        self->tasks_[0] = -1;
#endif
        arg0->unknown_6_     = 1;
    }
    int var47 = 1;
    for (int var48 = 0; var48 < 3; var48++) {
        if (arg0->unknown_13fc_[var48] != -1) {
            var47 = 0;
            break;
        }
    }
    if (var47) {
        DISPCNT = (DISPCNT & ~0x1f00) | 0x1700;
        arg0->unknown_13ec_ |= 1;
#if defined(jpn)
        MessageSystem_SetStringArgument((Obj02046574 *) global, 0, *(char **) ((char *) state->GetUnknownGameObject() + 0x134));
#endif
        void *var49 = func_0202ae18();
        if ((func_0202b7d8((int *) var49) != 0 && func_0202c540(var49) != 0) ||
            *(short *) ((char *) var1->GetUnknownGameObject() + 4) != 0)
        {
            arg0->unknown_4_ = 3;
            arg0->unknown_6_  = 0;
        } else if (arg0->unknown_a_ != 1 && arg0->unknown_a_ != 2) {
            arg0->unknown_4_ = 2;
            arg0->unknown_6_  = 0;
        } else {
            arg0->unknown_13ea_ = 1;
            arg0->unknown_4_   = 5;
            arg0->unknown_6_    = 0;
        }
    }
}
