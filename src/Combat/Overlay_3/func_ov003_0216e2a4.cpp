#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Graphics.h"
#include <globaldefs.h>

struct Background0216e2a4 {
    char unk_0[0x1c];
    unsigned char subScreen_ : 4;
    unsigned char bgNumber_ : 4;
    unsigned char screenCount_;
    char unk_1e[2];
};

struct Struct_ov003_0216e2a4_2 {
    void *unknown_0_;
    Struct_ov003_0216e2a4 *unknown_4_;
    char unknown_8_[0xc4 - 8];
    unsigned char unknown_c4_;
    char unknown_c5_[0xe0 - 0xc5];
};

struct Struct_ov003_0216e2a4_3 {
    char unknown_0_[0x98];
    Struct_ov003_0216e2a4 *unknown_98_;
    char unknown_9c_[0xb2 - 0x9c];
    unsigned char unknown_b2_;
    char unknown_b3_[0xbc - 0xb3];
};

struct Struct_ov003_0216e2a4_4 {
    char unknown_0_;
    char unknown_1_;
    char unknown_2_;
    char unknown_3_[0x14 - 3];
    void *unknown_14_;
    char unknown_18_[4];
    int unknown_1c_;
    char unknown_20_[0x3c - 0x20];
    Struct_ov003_0216e2a4_3 *unknown_3c_;
    Struct_ov003_0216e2a4 *unknown_40_;
    Struct_ov003_0216e2a4_2 *unknown_44_;
    char unknown_48_[0x60 - 0x48];
    int unknown_60_;
    int unknown_64_;
    char unknown_68_[0xa4 - 0x68];
    int unknown_a4_;
    int unknown_a8_;
    char unknown_ac_[0xb4 - 0xac];
    short unknown_b4_;
    char unknown_b6_[2];
    unsigned char unknown_b8_;
    char unknown_b9_[0xbc - 0xb9];
    SafeAllocator unknown_bc_;
    SafeAllocator *unknown_d0_;
    void *unknown_d4_;
    char unknown_d8_[4];
    char unknown_dc_[0x20];
};

struct BackgroundGraphics;
struct PacRecord;
struct WindowPane;
struct Struct_0205cf78;
struct WindowPane;

void Background_SetMapSize(unsigned char *background, int a);
int Pac_CountFiles(PacRecord *archive);
void *Pac_GetFile(PacRecord *archive, int index, void **name, int *size);
extern "C" void Background_SetPriority(Background0216e2a4 *background, int a);
void Background_AllocateMap(BackgroundGraphics *background,
                                                                                         SafeAllocator *allocator);
void Background_SetScroll(BackgroundGraphics *background, int a, int b);
extern "C" void Background_LoadFile(Background0216e2a4 *background, void *file, SafeAllocator *allocator, unsigned int size);
extern "C" void Background_FillRect(Background0216e2a4 *background, int a, int b, int c, int d, int e, int f);
void Background_UploadMap(BackgroundGraphics *background, void *a);
void WindowPane_AllocateBuffer(WindowPane *canvas, SafeAllocator *allocator,
                                                                           int pixels, unsigned int size);
void Window_SetPanes(Struct_0205cf78 *window,
                                                                                     WindowPane *canvases,
                                                                                     unsigned char count);
extern "C" void SpriteContext_LoadFile(void *renderer, void *file, unsigned int size, SafeAllocator *allocator);
extern "C" void KeyTable_Load(void *texts, SafeAllocator *allocator, void *file, unsigned int size);
extern "C" void func_ov023_021e20f0(void *obj, SafeAllocator *allocator, void *file, unsigned int size);

extern const unsigned char data_ov003_0217f5ba[2];
extern const unsigned char data_ov003_0217f5b8[2];
extern char data_ov003_02180222[];
extern char data_ov003_02180235[];
extern char data_ov003_02180249[];
extern char data_ov003_02180260[];
#if defined(jpn)
#define data_ov003_02180222 data_ov003_0217e9c0
#define data_ov003_02180235 data_ov003_0217e9d3
#define data_ov003_02180249 data_ov003_0217e9ee
extern char data_ov003_0217e9c0[];
extern char data_ov003_0217e9d3[];
extern char data_ov003_0217e9ee[];
extern char data_ov003_0217ea05[];
#endif
extern char data_ov003_0218027a[];

// USA: func_ov003_0216e2a4
#if defined(jpn)
extern "C" ARM void func_ov003_0216e2a4(Struct_ov003_0216e2a4_4 *arg0) {
    BackgroundLoader *var0 = BackgroundLoader::GetInstance();

    if (self->step_ == 0) {
        Background_SetMapSize((unsigned char *) &self->backgrounds_[0], 0);
        self->backgrounds_[0].subScreen_ = 0;
        self->backgrounds_[0].bgNumber_ = 1;
        Background_SetPriority(&self->backgrounds_[0], 0);
        Background_AllocateMap((BackgroundGraphics *) &self->backgrounds_[0], self->allocatorPtr_);
        Background_SetScroll((BackgroundGraphics *) &self->backgrounds_[0], 0, 0);
        BG1CNT = (BG1CNT & 0x43) | 0xd08;
        Background_SetMapSize((unsigned char *) &self->backgrounds_[1], 0);
        self->backgrounds_[1].subScreen_ = 0;
        self->backgrounds_[1].bgNumber_ = 2;
        Background_SetPriority(&self->backgrounds_[1], 1);
        Background_AllocateMap((BackgroundGraphics *) &self->backgrounds_[1], self->allocatorPtr_);
        Background_SetScroll((BackgroundGraphics *) &self->backgrounds_[1], 0, 0);
        BG2CNT = (BG2CNT & 0x43) | 0xe08;
        self->task_ = loader->QueueLoadFile(data_ov003_02180222, 0);
        self->step_ = 1;
    } else if (self->step_ == 1) {
        if (loader->GetTaskStatus(self->task_) != 0) {
            void *name;
            void *file;
            void *datas[2];
            unsigned int size;
            int sizes[2];
            loader->GetLoadedFileByID(self->task_, &file, &size);
            int count = Pac_CountFiles((PacRecord *) file);
            for (int i = 0; i < count; i++)
                datas[i] = Pac_GetFile((PacRecord *) file, i, &name, &sizes[i]);
            for (int i = 0; i < count; i++) {
                if (datas[i] != 0) Background_LoadFile(self->backgrounds_, datas[i], self->allocatorPtr_, sizes[i]);
            }
            loader->RemoveTask(self->task_);
            self->task_                    = -1;
            Background_FillRect(&self->backgrounds_[0], 0, 0, 0, 0x20, 0x19, 0);
            Background_UploadMap((BackgroundGraphics *) &self->backgrounds_[0], 0);
            Background_FillRect(&self->backgrounds_[1], 0, 0, 0, 0x20, 0x19, 0);
            Background_UploadMap((BackgroundGraphics *) &self->backgrounds_[1], 0);
            self->pixels_ = self->allocatorPtr_->Allocate(0x2800);
            WindowPane_AllocateBuffer((WindowPane *) &self->canvases_[0], self->allocatorPtr_, (int) self->pixels_, 0x500);
            self->canvases_[0].background_ = &self->backgrounds_[0];
            self->canvases_[0].unk_c4      = 0;
            WindowPane_AllocateBuffer((WindowPane *) &self->canvases_[1], self->allocatorPtr_, (int) self->pixels_, 0x500);
            self->canvases_[1].background_ = &self->backgrounds_[1];
            self->canvases_[1].unk_c4      = 0;
            Window0216e2a4 *window = self->window_;
            window->background_    = self->backgrounds_;
            window->unk_b2         = 2;
            Window_SetPanes((Struct_0205cf78 *) self->window_,
                                                                                 (WindowPane *) self->canvases_, 2);
            self->unk_b8 = 0;
            self->unk_a8 = self->unk_60;
            self->unk_b4 = 0xa;
            self->unk_a4 = self->unk_64;
            self->task_  = loader->QueueLoadFile(data_ov003_02180235, 0);
            self->step_  = 2;
        }
    } else if (self->step_ == 2) {
        if (loader->GetTaskStatus(self->task_) != 0) {
            void *name;
            void *file;
            unsigned int size;
            int fileSize;
            loader->GetLoadedFileByID(self->task_, &file, &size);
            int count = Pac_CountFiles((PacRecord *) file);
            for (int i = 0; i < count; i++) {
                void *data = Pac_GetFile((PacRecord *) file, i, &name, &fileSize);
                SpriteContext_LoadFile((char *) self + 0x68, data, fileSize, &self->allocator_);
            }
            var0->RemoveTask(arg0->unknown_1c_);
            arg0->unknown_1c_ = -1;
            arg0->unknown_1c_ = var0->QueueLoadFile(data_ov003_02180249, 0);
            arg0->unknown_2_ = 3;
        }
    } else if (arg0->unknown_2_ == 3) {
        if (var0->GetTaskStatus(arg0->unknown_1c_) != 0) {
            void *var17;
            unsigned int var18;
            var0->GetLoadedFileByID(arg0->unknown_1c_, &var17, &var18);
            func_ov023_021e20f0(arg0->unknown_d4_, arg0->unknown_d0_, var17, var18);
            var0->RemoveTask(arg0->unknown_1c_);
            arg0->unknown_1c_ = -1;
            arg0->unknown_1c_ = var0->QueueLoadFile(data_ov003_0217ea05, 0);
            arg0->unknown_2_ = 4;
        }
    } else if (self->step_ == 4) {
        if (loader->GetTaskStatus(self->task_) != 0) {
            void *file;
            unsigned int size;
            loader->GetLoadedFileByID(self->task_, &file, &size);
            KeyTable_Load(self->unk_dc, self->allocatorPtr_, file, size);
            loader->RemoveTask(self->task_);
            self->task_  = -1;
            self->state_ = 2;
            self->step_  = 0;
        }
    }
}
#else
extern "C" ARM void func_ov003_0216e2a4(Struct_ov003_0216e2a4_4 *arg0) {
    BackgroundLoader *var21 = BackgroundLoader::GetInstance();

    if (self->step_ == 0) {
        Background0216e2a4 *background = self->backgrounds_;
        for (int i = 0; i < 2; i++) {
            Background_SetMapSize((unsigned char *) background, 0);
            background->subScreen_ = 0;
            background->bgNumber_ = data_ov003_0217f5ba[i];
            Background_SetPriority(background, data_ov003_0217f5b8[i]);
            Background_AllocateMap((BackgroundGraphics *) background,
                                                                                     self->allocatorPtr_);
            Background_SetScroll((BackgroundGraphics *) background, 0, 0);
            background++;
        }
        BG1CNT      = (BG1CNT & 0x43) | 0xd08;
        BG2CNT      = (BG2CNT & 0x43) | 0xe08;
        self->task_ = loader->QueueLoadFile(data_ov003_02180222, 0);
        self->step_ = 1;
    } else if (self->step_ == 1) {
        if (loader->GetTaskStatus(self->task_) != 0) {
            void *name;
            void *file;
            void *datas[2];
            unsigned int size;
            int sizes[2];
            loader->GetLoadedFileByID(self->task_, &file, &size);
            int count = Pac_CountFiles((PacRecord *) file);
            for (int i = 0; i < count; i++)
                datas[i] = Pac_GetFile((PacRecord *) file, i, &name, &sizes[i]);
            for (int i = 0; i < count; i++) {
                if (datas[i] != 0) Background_LoadFile(self->backgrounds_, datas[i], self->allocatorPtr_, sizes[i]);
            }
            loader->RemoveTask(self->task_);
            self->task_                    = -1;
            Background0216e2a4 *background = self->backgrounds_;
            for (int i = 0; i < 2; i++) {
                Background_FillRect(background, 0, 0, 0, 0x20, 0x19, 0);
                Background_UploadMap((BackgroundGraphics *) background, 0);
                background++;
            }
            self->pixels_          = self->allocatorPtr_->Allocate(0x2800);
            Canvas0216e2a4 *canvas = self->canvases_;
            for (int i = 0; i < 2; i++) {
                WindowPane_AllocateBuffer((WindowPane *) canvas, self->allocatorPtr_,
                                                                           (int) self->pixels_, 0x500);
                canvas->background_ = &self->backgrounds_[i];
                canvas->unk_c4      = 0;
                canvas++;
            }
            Window0216e2a4 *window = self->window_;
            window->background_    = self->backgrounds_;
            window->unk_b2         = 2;
            Window_SetPanes((Struct_0205cf78 *) self->window_,
                                                                                 (WindowPane *) self->canvases_, 2);
            self->unk_b8 = 0;
            self->unk_a8 = self->unk_60;
            self->unk_b4 = 0x16;
            self->unk_a4 = self->unk_64;
            self->task_  = loader->QueueLoadFile(data_ov003_02180235, 0);
            self->step_  = 2;
        }
    } else if (self->step_ == 2) {
        if (loader->GetTaskStatus(self->task_) != 0) {
            void *name;
            void *file;
            unsigned int size;
            int fileSize;
            loader->GetLoadedFileByID(self->task_, &file, &size);
            int count = Pac_CountFiles((PacRecord *) file);
            for (int i = 0; i < count; i++) {
                void *data = Pac_GetFile((PacRecord *) file, i, &name, &fileSize);
                SpriteContext_LoadFile((char *) self + 0x68, data, fileSize, &self->allocator_);
            }
            var21->RemoveTask(arg0->unknown_1c_);
            arg0->unknown_1c_ = -1;
            arg0->unknown_1c_ = var21->QueueLoadFile(data_ov003_02180249, 0);
            arg0->unknown_2_ = 3;
        }
    } else if (arg0->unknown_2_ == 3) {
        if (var21->GetTaskStatus(arg0->unknown_1c_) != 0) {
            void *var44;
            unsigned int var45;
            var21->GetLoadedFileByID(arg0->unknown_1c_, &var44, &var45);
            func_ov023_021e20f0(arg0->unknown_d4_, arg0->unknown_d0_, var44, var45);
            var21->RemoveTask(arg0->unknown_1c_);
            arg0->unknown_1c_ = -1;
            arg0->unknown_1c_ = var21->QueueLoadFileInGP2(data_ov003_02180260, data_ov003_0218027a, 0);
            arg0->unknown_2_ = 4;
        }
    } else if (self->step_ == 4) {
        if (loader->GetTaskStatus(self->task_) != 0) {
            void *file;
            unsigned int size;
            loader->GetLoadedFileByID(self->task_, &file, &size);
            KeyTable_Load(self->unk_dc, self->allocatorPtr_, file, size);
            loader->RemoveTask(self->task_);
            self->task_  = -1;
            self->state_ = 2;
            self->step_  = 0;
        }
    }
}
#endif
