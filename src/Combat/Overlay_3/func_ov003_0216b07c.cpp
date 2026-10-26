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
    char unknown_1e_[2];
};

struct Struct_ov003_0216b07c_3 {
    void *unk_0;
    Background0216b07c *background_;
    char unk_8[0xc4 - 8];
    unsigned char unknown_c4_;
    char unk_c5[0xe0 - 0xc5];
};

struct Struct_ov003_0216b07c_5 {
    char unk_0[0x98];
    Background0216b07c *background_;
    char unknown_9c_[0xb2 - 0x9c];
    unsigned char unknown_b2_;
    char unknown_b3_[0xbc - 0xb3];
};

struct Global0216b07c {
#if defined(jpn)
    char unk_0[0x28];
    char *text_;
    char unk_2c[0x868 - 0x2c];
    int unknown_998_;
    int unknown_99c_;
    char unknown_870_[0x17e2 - 0x870];
#else
    char unk_0[0x5c];
    char *text_;
    char unknown_60_[0x998 - 0x60];
    int unknown_998_;
    int unknown_99c_;
    char unknown_9a0_[0x19b2 - 0x9a0];
#endif
    unsigned char unknown_19b2_;
};

struct Struct_ov003_0216b07c {
    char unk_0[4];
    short state_;
    short step_;
    char unk_8[2];
    short mode_;
#if defined(jpn)
    char unk_c[0x10f4 - 0xc];
#else
    char unk_c[0x1264 - 0xc];
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
    Struct_ov003_0216b07c_5 *window_;
    Background0216b07c *backgrounds_;
    Struct_ov003_0216b07c_3 *canvases_;
    void *pixels_;
    SafeAllocator *allocator_;
    char unknown_12d4_[0x12fc - 0x12d4];
    SafeAllocator allocators_[2];
    char unknown_1324_[0x13ea - 0x1324];
    unsigned char unknown_13ea_;
    char unknown_13eb_;
    unsigned char unknown_13ec_;
    char unknown_13ed_[0x13fc - 0x13ed];
    int tasks_[3];
};

struct Obj020397cc;
struct BackgroundGraphics;
struct PacRecord;
struct WindowPane;
struct Struct_0205cf78;
struct WindowPane;

extern "C" void GameObject_DisableControl(Obj020397cc *obj, int a);
extern "C" int Text_Append(char *dst, const char *src);
extern "C" const char *StandardStrings_Get(int id);
extern "C" void Background_SetMapSize(unsigned char *background, int a);
extern "C" int Pac_CountFiles(PacRecord *archive);
extern "C" void *Pac_GetFile(PacRecord *archive, int index, void **name, int *size);
extern "C" int LinkSession_IsActive(int *p);
extern "C" void *LinkSession_GetInstance();
extern "C" int LinkSession_IsHostOrSolo();
extern "C" int LinkSession_IsGuest(void *p);
extern "C" void func_02046380(void *p);
#if defined(jpn)
struct Obj02046574;
extern "C" void MessageSystem_SetStringArgument(Obj02046574 *obj, int index, char *name);
extern "C" void func_0204500c(void *p, const char *text, int a);
extern char data_ov003_0217e930[];
#else
extern "C" void func_0204500c(void *p, const char *text, int a, int b);
#endif
extern "C" void SpriteContext_LoadFile(void *renderer, void *file, unsigned int size, SafeAllocator *allocator);
extern "C" void KeyTable_Load(void *texts, SafeAllocator *allocator, void *file, unsigned int size);
extern "C" void Background_SetPriority(Background0216b07c *background, int a);
extern "C" void Background_AllocateMap(BackgroundGraphics *background,
                                                                                         SafeAllocator *allocator);
extern "C" void Background_SetScroll(BackgroundGraphics *background, int a, int b);
extern "C" void Background_LoadFile(Background0216b07c *background, void *file, SafeAllocator *allocator, unsigned int size);
extern "C" void Background_FillRect(Background0216b07c *background, int a, int b, int c, int d, int e, int f);
extern "C" void Background_UploadMap(BackgroundGraphics *background, void *a);
extern "C" void WindowPane_AllocateBuffer(WindowPane *canvas, SafeAllocator *allocator,
                                                                           int pixels, unsigned int size);
extern "C" void Window_SetPanes(Struct_0205cf78 *window,
                                                                                     WindowPane *canvases,
                                                                                     unsigned char count);
extern "C" void *MessageSystem_GetInstance();

struct Struct_ov003_0217f56c {
    const char *names_[3];
};
extern Struct_ov003_0217f56c data_ov003_0217f56c;
extern char data_ov003_02180198[];

struct Struct_ov003_0216b07c_4 {
    volatile unsigned short unknown_0_0_ : 2;
    volatile unsigned short unknown_0_2_ : 14;
};

// USA: func_ov003_0216b07c
extern "C" ARM void func_ov003_0216b07c(Struct_ov003_0216b07c *self) {
    Global0216b07c *global   = (Global0216b07c *) MessageSystem_GetInstance();
    GameState *state         = GameState::GetInstance();
    BackgroundLoader *loader = BackgroundLoader::GetInstance();

    if (self->step_ == 0) {
        GameObject_DisableControl((Obj020397cc *) state->GetLeader(), 1);
        ColorEffect_ConfigureAlphaBlend(0x4000050, 0x10, 1, 0x1f, 0);
        LinkSession_GetInstance();
        if (LinkSession_IsHostOrSolo() != 0 && *(short *) ((char *) state->GetLeader() + 4) == 0) {
            if (self->mode_ == 3) {
                global->unknown_998_ = 1;
#if defined(jpn)
                Text_Append(global->text_, data_ov003_0217e930);
                func_0204500c(global, global->text_, 0);
#else
                char *text      = global->text_;
                Text_Append(text, StandardStrings_Get(0x44));
                func_02046380(global);
                func_0204500c(global, global->text_, 0, 0xe3);
#endif
                global->unknown_19b2_ = 1;
                global->unknown_99c_  = 2;
                global->unknown_998_  = 1;
            }
        } else {
            self->unknown_13ea_ = 1;
            self->unknown_13ec_ |= 1;
            self->state_ = 3;
            self->step_  = 0;
            return;
        }
        self->allocators_[0].CreateTypeA(self->allocator_->Allocate(0x3800), 0x3800);
        self->allocators_[1].CreateTypeA(self->allocator_->Allocate(0xc00), 0xc00);
        self->allocators_[1].Reset();
        int i               = 0;
        self->unknown_12bc_      = 0;
        self->unknown_12ac_      = self->unknown_1264_;
        self->unknown_12b8_      = 0xf;
        self->unknown_12a8_      = self->unknown_1268_;
        Struct_ov003_0217f56c names = data_ov003_0217f56c;
        int zero            = 0;
        for (; i < 3; i++) {
            int id;
#if defined(jpn)
            id = loader->QueueLoadFile(names.names_[i], (SafeAllocator *) zero);
#else
            if (i == 0)
                id = loader->QueueLoadFileInGP2(data_ov003_02180198, names.names_[i], (SafeAllocator *) zero);
            else
                id = loader->QueueLoadFile(names.names_[i], (SafeAllocator *) zero);
#endif
            self->tasks_[i] = id;
        }
        self->step_ = 1;
    }
    if (self->step_ == 1) {
        for (int i = 0; i < 3; i++) {
            if (self->tasks_[i] == -1) continue;
            if (loader->GetTaskStatus(self->tasks_[i]) != 0) {
                self->step_ = i + 2;
                break;
            }
        }
    }
#if defined(jpn)
    if (self->step_ == 2) {
        void *name;
        void *file;
        unsigned int size;
        int fileSize;
        int task = self->tasks_[0];
#else
    if (self->step_ == 4) {
        void *name;
        void *file;
        unsigned int size;
        int fileSize;
        int task = self->tasks_[2];
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
        loader->RemoveTask(task);
#if defined(jpn)
        self->tasks_[0] = -1;
#else
        self->tasks_[2] = -1;
#endif
        self->step_     = 1;
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
        self->canvases_->unknown_c4_      = 0;
        Struct_ov003_0216b07c_5 *window       = self->window_;
        window->background_          = self->backgrounds_;
        window->unknown_b2_               = 2;
        Window_SetPanes((Struct_0205cf78 *) self->window_, (WindowPane *) self->canvases_, 1);
        ((Struct_ov003_0216b07c_4 *) 0x4000008)[0].unknown_0_0_ = 3;
        ((Struct_ov003_0216b07c_4 *) 0x4000008)[1].unknown_0_0_ = 1;
        ((Struct_ov003_0216b07c_4 *) 0x4000008)[2].unknown_0_0_ = 2;
        ((Struct_ov003_0216b07c_4 *) 0x4000008)[3].unknown_0_0_ = 0;
        ColorEffect_ConfigureAlphaBlend(0x4000050, 4, 1, 0xa, 6);
        self->step_ = 1;
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
        Struct_ov003_0216b07c_3 *canvas = self->canvases_;
        WindowPane_AllocateBuffer((WindowPane *) canvas, self->allocator_,
                                                                   (int) self->pixels_, 0x400);
        canvas->background_    = self->backgrounds_;
        canvas->unknown_c4_         = 0;
        Struct_ov003_0216b07c_5 *window = self->window_;
        window->background_    = self->backgrounds_;
        window->unknown_b2_         = 2;
        Window_SetPanes((Struct_0205cf78 *) self->window_,
                                                                             (WindowPane *) self->canvases_, 1);
        ((Struct_ov003_0216b07c_4 *) 0x4000008)[0].unknown_0_0_ = 3;
        ((Struct_ov003_0216b07c_4 *) 0x4000008)[1].unknown_0_0_ = 1;
        ((Struct_ov003_0216b07c_4 *) 0x4000008)[2].unknown_0_0_ = 2;
        ((Struct_ov003_0216b07c_4 *) 0x4000008)[3].unknown_0_0_ = 0;
        ColorEffect_ConfigureAlphaBlend(0x4000050, 4, 1, 0xa, 6);
        self->step_ = 1;
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
        self->step_     = 1;
    }
    int done = 1;
    for (int i = 0; i < 3; i++) {
        if (self->tasks_[i] != -1) {
            done = 0;
            break;
        }
    }
    if (done) {
        DISPCNT = (DISPCNT & ~0x1f00) | 0x1700;
        self->unknown_13ec_ |= 1;
#if defined(jpn)
        MessageSystem_SetStringArgument((Obj02046574 *) global, 0, *(char **) ((char *) state->GetLeader() + 0x134));
#endif
        void *obj = LinkSession_GetInstance();
        if ((LinkSession_IsActive((int *) obj) != 0 && LinkSession_IsGuest(obj) != 0) ||
            *(short *) ((char *) state->GetLeader() + 4) != 0)
        {
            self->state_ = 3;
            self->step_  = 0;
        } else if (self->mode_ != 1 && self->mode_ != 2) {
            self->state_ = 2;
            self->step_  = 0;
        } else {
            self->unknown_13ea_ = 1;
            self->state_   = 5;
            self->step_    = 0;
        }
    }
}
