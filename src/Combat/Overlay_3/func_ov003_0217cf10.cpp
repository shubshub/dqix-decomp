#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Graphics.h"
#include "NitroSDK/ColorEffects.h"

struct Messages0217cf10 {
#if defined(jpn)
    char pad0[0x868];
    int busy_;
    char unknown_86c_[0x17e2 - 0x86c];
    unsigned char unknown_17e2_;
#else
    char pad0[0x998];
    int busy_;
    char unknown_99c_[0x19b2 - 0x99c];
    unsigned char unknown_19b2_;
#endif
};

struct Struct_ov003_0217cf10_7 {
    unsigned char pad0[0xb48];
    unsigned int unknown_b48_;
};

struct Struct_ov003_0217cf10_8 {
    unsigned char pad0[0x1000];
    Struct_ov003_0217cf10_7 unknown_1000_;
};

struct Zone0217cf10 {
#if defined(jpn)
    unsigned char pad0[0x860];
#else
    unsigned char pad0[0x840];
#endif
    Struct_ov003_0217cf10_8 unknown_840_;
};

static inline unsigned int inline_ov003_0217cf10(Struct_ov003_0217cf10_7 *progress) { return progress->unknown_b48_; }
static inline bool inline_ov003_0217cf10_2(Struct_ov003_0217cf10_7 *progress, unsigned int mask) { return (inline_ov003_0217cf10(progress) & mask) != 0; }

struct Background0217cf10 {
    char unk_0[0x1c];
    unsigned char subScreen_ : 4;
    unsigned char bgNumber_ : 4;
    unsigned char screenCount_;
    char unknown_1e_[2];
};

struct Struct_ov003_0217cf10_2 {
    Struct_ov003_0217cf10_2 *previous_;
    Background0217cf10 *background_;
    char pad8[0xc4 - 8];
    unsigned char unknown_c4_;
    char unknown_c5_[0xe0 - 0xc5];
};

struct Struct_ov003_0217cf10_3 {
    char pad0[0x98];
    Background0217cf10 *backgrounds_;
    char unknown_9c_[0xb2 - 0x9c];
    unsigned char unknown_b2_;
};

struct Menu0217cf10 {
    char pad0[0x3c];
    int unknown_3c_;
    int unknown_40_;
    char unknown_44_[0x4c - 0x44];
    unsigned short unknown_4c_;
    char unknown_4e_[0x50 - 0x4e];
    unsigned char unknown_50_;
    char unknown_51_[0x54 - 0x51];
};

struct Container020e0310;

struct Struct_ov003_0217cf10_5 {
    unsigned char pad0[4];
    unsigned char state_;
    signed char step_;
    char pad6[0xc - 6];
    int task_;
#if !defined(jpn)
    int width_;
#endif
    char unknown_14_[0x18 - 0x14];
    unsigned char list_[0x18];
    unsigned char count_;
    char unknown_31_;
    unsigned char pages_;
    char unknown_33_;
    int unknown_34_;
    int unknown_38_;
    Menu0217cf10 menu_;
    Struct_ov003_0217cf10_3 *window_;
    Background0217cf10 *backgrounds_;
    Struct_ov003_0217cf10_2 *canvas_;
    void *pixels_;
    SafeAllocator *allocator_;
    SafeAllocator textAllocator_;
    SafeAllocator menuAllocator_;
    char texts_[8];
};

struct Obj020397cc;
struct SePlayer;
struct PacRecord;
struct BackgroundGraphics;
struct WindowPane;
struct Struct_0205cf78;
struct WindowPane;

extern "C" Messages0217cf10 *MessageSystem_GetInstance();
extern "C" Zone0217cf10 *Zone3D_GetInstance(void);
extern "C" void GameObject_DisableControl(Obj020397cc *obj, int flag);
extern "C" void SePlayer_Play(SePlayer *obj, int a, int b);
extern "C" const char *StandardStrings_Get(int key);
#if defined(jpn)
extern "C" void func_0204500c(Messages0217cf10 *window, const char *text, int mode);
#else
extern "C" void func_0204500c(Messages0217cf10 *window, const char *text, int mode, int width);
#endif
extern "C" int Pac_CountFiles(PacRecord *archive);
extern "C" void *Pac_GetFile(PacRecord *archive, int index, void **name, int *size);
extern "C" void SpriteContext_LoadFile(Menu0217cf10 *menu, void *file, int size, SafeAllocator *allocator);
extern "C" void Background_SetMapSize(unsigned char *background, int a);
extern "C" void Background_SetPriority(Background0217cf10 *background, int a);
extern "C" void Background_AllocateMap(BackgroundGraphics *background, SafeAllocator *allocator);
extern "C" void Background_SetScroll(BackgroundGraphics *background, int a, int b);
extern "C" void Background_LoadFile(Background0217cf10 *background, void *file, SafeAllocator *allocator, int size);
extern "C" void Background_FillRect(Background0217cf10 *background, int a, int b, int c, int d, int e, int f);
extern "C" void Background_UploadMap(BackgroundGraphics *background, void *a);
extern "C" void WindowPane_AllocateBuffer(WindowPane *canvas, SafeAllocator *allocator, int pixels, unsigned int size);
extern "C" void Window_SetPanes(Struct_0205cf78 *window, WindowPane *canvases, unsigned char count);
extern "C" void KeyTable_Load(void *texts, SafeAllocator *allocator, void *file, unsigned int size);
extern "C" const char *KeyTable_Get(Container020e0310 *texts, int key);
extern "C" int Font_GetTextWidth(const char *text, int large);

extern SePlayer g_sePlayer;
extern char data_ov003_02180c2c[];
extern char data_ov003_02180c43[];
extern char data_ov003_02180c56[];
extern char data_ov003_02180c6f[];
#if defined(jpn)
extern char data_ov003_0217ee58[];
extern char data_ov003_0217ee8c[];
extern char data_ov003_0217eecc[];
extern char data_ov003_0217eee3[];
extern char data_ov003_0217eef6[];
#endif

// USA: func_ov003_0217cf10
#if defined(jpn)
extern "C" ARM void func_ov003_0217cf10(Struct_ov003_0217cf10_5 *self) {
    Messages0217cf10 *msg = MessageSystem_GetInstance();
    GameState *gs = GameState::GetInstance();
    BackgroundLoader *loader = BackgroundLoader::GetInstance();
    Zone0217cf10 *zone = Zone3D_GetInstance();
    Struct_ov003_0217cf10_8 *save = &zone->unknown_840_;
    int step = self->step_;

    if (step == 0) {
        GameObject_DisableControl((Obj020397cc *)gs->GetLeader(), 1);
        msg->busy_ = 1;
        SePlayer_Play(&g_sePlayer, 1, 0);
        if (inline_ov003_0217cf10_2(&save->unknown_1000_, 0xffffffff)) {
            func_0204500c(msg, data_ov003_0217ee58, 0);
            msg->unknown_17e2_ = 0;
            msg->busy_ = 1;
        } else {
            func_0204500c(msg, data_ov003_0217ee8c, 0);
            msg->unknown_17e2_ = 0;
            msg->busy_ = 1;
            self->state_ = 1;
            self->step_ = 0;
            return;
        }
        int count = 1;
        for (int i = 1; i < 0x18; i++) {
            if (save->unknown_1000_.unknown_b48_ & (1 << i)) {
                self->list_[count] = i;
                count++;
            }
        }
        self->count_ = count;
        self->pages_ = (self->count_ - 1) / 6 + 1;
        self->menu_.unknown_50_ = 0;
        self->menu_.unknown_40_ = self->unknown_34_;
        self->menu_.unknown_4c_ = 7;
        self->menu_.unknown_3c_ = self->unknown_38_;
        self->task_ = loader->QueueLoadFile(data_ov003_0217eecc, 0);
        self->step_ = 1;
    } else if (step == 1) {
        if (loader->GetTaskStatus(self->task_) == 0) return;
        void *name;
        void *file;
        unsigned int size;
        int recSize;
        loader->GetLoadedFileByID(self->task_, &file, &size);
        int n = Pac_CountFiles((PacRecord *)file);
        for (int i = 0; i < n; i++) {
            void *rec = Pac_GetFile((PacRecord *)file, i, &name, &recSize);
            SpriteContext_LoadFile(&self->menu_, rec, recSize, &self->menuAllocator_);
        }
        loader->RemoveTask(self->task_);
        self->task_ = -1;
        self->task_ = loader->QueueLoadFile(data_ov003_0217eee3, 0);
        self->step_ = 2;
    } else if (step == 2) {
        if (loader->GetTaskStatus(self->task_) == 0) return;
        Background_SetMapSize((unsigned char *)&self->backgrounds_[0], 0);
        self->backgrounds_[0].subScreen_ = 0;
        self->backgrounds_[0].bgNumber_ = 1;
        Background_SetPriority(&self->backgrounds_[0], 0);
        Background_AllocateMap((BackgroundGraphics *)&self->backgrounds_[0], self->allocator_);
        Background_SetScroll((BackgroundGraphics *)&self->backgrounds_[0], 0, 0);
        BG1CNT = (BG1CNT & 0x43) | 0xd08;
        Background_SetMapSize((unsigned char *)&self->backgrounds_[1], 0);
        self->backgrounds_[1].subScreen_ = 0;
        self->backgrounds_[1].bgNumber_ = 2;
        Background_SetPriority(&self->backgrounds_[1], 1);
        Background_AllocateMap((BackgroundGraphics *)&self->backgrounds_[1], self->allocator_);
        Background_SetScroll((BackgroundGraphics *)&self->backgrounds_[1], 0, 0);
        BG2CNT = (BG2CNT & 0x43) | 0xe08;
        void *name;
        void *file;
        void *recs[2];
        unsigned int size;
        int sizes[2];
        loader->GetLoadedFileByID(self->task_, &file, &size);
        int n = Pac_CountFiles((PacRecord *)file);
        for (int i = 0; i < n; i++) {
            recs[i] = Pac_GetFile((PacRecord *)file, i, &name, &sizes[i]);
        }
        for (int i = 0; i < n; i++) {
            if (recs[i] != 0) {
                Background_LoadFile(&self->backgrounds_[0], recs[i], self->allocator_, sizes[i]);
            }
        }
        loader->RemoveTask(self->task_);
        self->task_ = -1;
        Background_FillRect(&self->backgrounds_[0], 0, 0, 0, 0x20, 0x19, 0);
        Background_UploadMap((BackgroundGraphics *)&self->backgrounds_[0], 0);
        Background_FillRect(&self->backgrounds_[1], 0, 0, 0, 0x20, 0x19, 0);
        Background_UploadMap((BackgroundGraphics *)&self->backgrounds_[1], 0);
        self->pixels_ = self->allocator_->Allocate(0x2800);
        WindowPane_AllocateBuffer((WindowPane *)self->canvas_, self->allocator_, (int)self->pixels_, 0x800);
        self->canvas_->background_ = self->backgrounds_;
        self->canvas_->unknown_c4_ = 0;
        Struct_ov003_0217cf10_3 *window = self->window_;
        window->backgrounds_ = self->backgrounds_;
        window->unknown_b2_ = 2;
        Window_SetPanes((Struct_0205cf78 *)self->window_, (WindowPane *)self->canvas_, 1);
        BG0CNT = (BG0CNT & ~3) | 3;
        BG1CNT = (BG1CNT & ~3) | 1;
        BG2CNT = (BG2CNT & ~3) | 2;
        BG3CNT = (BG3CNT & ~3) | 0;
        ColorEffect_ConfigureAlphaBlend(0x04000050, 4, 1, 10, 6);
        self->task_ = loader->QueueLoadFile(data_ov003_0217eef6, 0);
        self->step_ = 3;
    } else if (step == 3) {
        if (loader->GetTaskStatus(self->task_) == 0) return;
        void *file;
        unsigned int size;
        loader->GetLoadedFileByID(self->task_, &file, &size);
        self->textAllocator_.Reset();
        KeyTable_Load(self->texts_, &self->textAllocator_, file, size);
        loader->RemoveTask(self->task_);
        self->task_ = -1;
        DISPCNT = (DISPCNT & ~0x1f00) | 0x1700;
        self->state_ = 2;
        self->step_ = 0;
    }
}
#else
extern "C" ARM void func_ov003_0217cf10(Struct_ov003_0217cf10_5 *self) {
    Messages0217cf10 *msg = MessageSystem_GetInstance();
    GameState *gs = GameState::GetInstance();
    BackgroundLoader *loader = BackgroundLoader::GetInstance();
    Zone0217cf10 *zone = Zone3D_GetInstance();
    int step = self->step_;

    if (step == 0) {
        Struct_ov003_0217cf10_8 *save = &zone->unknown_840_;
        GameObject_DisableControl((Obj020397cc *)gs->GetLeader(), 1);
        msg->busy_ = 1;
        SePlayer_Play(&g_sePlayer, 1, 0);
        if (inline_ov003_0217cf10_2(&save->unknown_1000_, 0xffffffff)) {
            func_0204500c(msg, StandardStrings_Get(0x42), 0, 0xe3);
            msg->unknown_19b2_ = 0;
            msg->busy_ = 1;
        } else {
            func_0204500c(msg, StandardStrings_Get(0x43), 0, 0xe3);
            msg->unknown_19b2_ = 0;
            msg->busy_ = 1;
            self->state_ = 1;
            self->step_ = 0;
            return;
        }
        int count = 1;
        for (int i = 1; i < 0x18; i++) {
            if (save->unknown_1000_.unknown_b48_ & (1 << i)) {
                self->list_[count] = i;
                count++;
            }
        }
        self->count_ = count;
        self->pages_ = (self->count_ - 1) / 6 + 1;
        self->menu_.unknown_50_ = 0;
        self->menu_.unknown_40_ = self->unknown_34_;
        self->menu_.unknown_4c_ = 7;
        self->menu_.unknown_3c_ = self->unknown_38_;
        self->task_ = loader->QueueLoadFile(data_ov003_02180c2c, 0);
        self->step_ = 1;
    } else if (step == 1) {
        if (loader->GetTaskStatus(self->task_) == 0) return;
        void *name;
        void *file;
        unsigned int size;
        int recSize;
        loader->GetLoadedFileByID(self->task_, &file, &size);
        int n = Pac_CountFiles((PacRecord *)file);
        for (int i = 0; i < n; i++) {
            void *rec = Pac_GetFile((PacRecord *)file, i, &name, &recSize);
            SpriteContext_LoadFile(&self->menu_, rec, recSize, &self->menuAllocator_);
        }
        loader->RemoveTask(self->task_);
        self->task_ = -1;
        self->task_ = loader->QueueLoadFile(data_ov003_02180c43, 0);
        self->step_ = 2;
    } else if (step == 2) {
        if (loader->GetTaskStatus(self->task_) == 0) return;
        Background_SetMapSize((unsigned char *)&self->backgrounds_[0], 0);
        self->backgrounds_[0].subScreen_ = 0;
        self->backgrounds_[0].bgNumber_ = 1;
        Background_SetPriority(&self->backgrounds_[0], 0);
        Background_AllocateMap((BackgroundGraphics *)&self->backgrounds_[0], self->allocator_);
        Background_SetScroll((BackgroundGraphics *)&self->backgrounds_[0], 0, 0);
        BG1CNT = (BG1CNT & 0x43) | 0xd08;
        Background_SetMapSize((unsigned char *)&self->backgrounds_[1], 0);
        self->backgrounds_[1].subScreen_ = 0;
        self->backgrounds_[1].bgNumber_ = 2;
        Background_SetPriority(&self->backgrounds_[1], 1);
        Background_AllocateMap((BackgroundGraphics *)&self->backgrounds_[1], self->allocator_);
        Background_SetScroll((BackgroundGraphics *)&self->backgrounds_[1], 0, 0);
        BG2CNT = (BG2CNT & 0x43) | 0xe08;
        void *name;
        void *file;
        void *recs[2];
        unsigned int size;
        int sizes[2];
        loader->GetLoadedFileByID(self->task_, &file, &size);
        int n = Pac_CountFiles((PacRecord *)file);
        for (int i = 0; i < n; i++) {
            recs[i] = Pac_GetFile((PacRecord *)file, i, &name, &sizes[i]);
        }
        for (int i = 0; i < n; i++) {
            if (recs[i] != 0) {
                Background_LoadFile(&self->backgrounds_[0], recs[i], self->allocator_, sizes[i]);
            }
        }
        loader->RemoveTask(self->task_);
        self->task_ = -1;
        Background_FillRect(&self->backgrounds_[0], 0, 0, 0, 0x20, 0x19, 0);
        Background_UploadMap((BackgroundGraphics *)&self->backgrounds_[0], 0);
        Background_FillRect(&self->backgrounds_[1], 0, 0, 0, 0x20, 0x19, 0);
        Background_UploadMap((BackgroundGraphics *)&self->backgrounds_[1], 0);
        self->pixels_ = self->allocator_->Allocate(0x2800);
        WindowPane_AllocateBuffer((WindowPane *)self->canvas_, self->allocator_, (int)self->pixels_, 0x800);
        self->canvas_->background_ = self->backgrounds_;
        self->canvas_->unknown_c4_ = 0;
        Struct_ov003_0217cf10_3 *window = self->window_;
        window->backgrounds_ = self->backgrounds_;
        window->unknown_b2_ = 2;
        Window_SetPanes((Struct_0205cf78 *)self->window_, (WindowPane *)self->canvas_, 1);
        BG0CNT = (BG0CNT & ~3) | 3;
        BG1CNT = (BG1CNT & ~3) | 1;
        BG2CNT = (BG2CNT & ~3) | 2;
        BG3CNT = (BG3CNT & ~3) | 0;
        ColorEffect_ConfigureAlphaBlend(0x04000050, 4, 1, 10, 6);
        self->task_ = loader->QueueLoadFileInGP2(data_ov003_02180c56, data_ov003_02180c6f, 0);
        self->step_ = 3;
    } else if (step == 3) {
        if (loader->GetTaskStatus(self->task_) == 0) return;
        void *file;
        unsigned int size;
        loader->GetLoadedFileByID(self->task_, &file, &size);
        self->textAllocator_.Reset();
        KeyTable_Load(self->texts_, &self->textAllocator_, file, size);
        loader->RemoveTask(self->task_);
        self->task_ = -1;
        int var52 = 0;
        for (int key = 0x64; key < 0x7c; key++) {
            int width = 0;
            const char *text = KeyTable_Get((Container020e0310 *)self->texts_, (short)key);
            if (text != 0) {
                width = Font_GetTextWidth(text, 0);
            }
            if (var52 < width) {
                var52 = width;
            }
        }
        self->width_ = (var52 + 0x1b) & ~7;
        self->width_ = self->width_ >> 3;
        self->width_ = ((self->width_ + 1) & ~1) << 3;
        DISPCNT = (DISPCNT & ~0x1f00) | 0x1700;
        self->state_ = 2;
        self->step_ = 0;
    }
}
#endif
