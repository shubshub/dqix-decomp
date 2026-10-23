#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Graphics.h"
#include "NitroSDK/ColorEffects.h"

struct Struct_ov003_0217cf10_6 {
#if defined(jpn)
    char unknown_0_[0x868];
    int unknown_868_;
    char unknown_86c_[0x17e2 - 0x86c];
    unsigned char unknown_17e2_;
#else
    char unknown1_0_[0x998];
    int unknown_998_;
    char unknown_99c_[0x19b2 - 0x99c];
    unsigned char unknown_19b2_;
#endif
};

struct Struct_ov003_0217cf10_7 {
    unsigned char unknown_0_[0xb48];
    unsigned int unknown_b48_;
};

struct Struct_ov003_0217cf10_8 {
    unsigned char unknown_0_[0x1000];
    Struct_ov003_0217cf10_7 unknown_1000_;
};

struct Struct_ov003_0217cf10_9 {
#if defined(jpn)
    unsigned char unknown_0_[0x860];
#else
    unsigned char unknown1_0_[0x840];
#endif
    Struct_ov003_0217cf10_8 unknown_840_;
};

static inline unsigned int inline_ov003_0217cf10(Struct_ov003_0217cf10_7 *arg0) { return arg0->unknown_b48_; }
static inline bool inline_ov003_0217cf10_2(Struct_ov003_0217cf10_7 *arg0, unsigned int arg1) { return (inline_ov003_0217cf10(arg0) & arg1) != 0; }

struct Struct_ov003_0217cf10 {
    char unknown_0_[0x1c];
    unsigned char unknown_1c_0_ : 4;
    unsigned char unknown_1c_4_ : 4;
    unsigned char unknown_1d_;
    char unknown_1e_[2];
};

struct Struct_ov003_0217cf10_2 {
    Struct_ov003_0217cf10_2 *unknown_0_;
    Struct_ov003_0217cf10 *unknown_4_;
    char unknown_8_[0xc4 - 8];
    unsigned char unknown_c4_;
    char unknown_c5_[0xe0 - 0xc5];
};

struct Struct_ov003_0217cf10_3 {
    char unknown_0_[0x98];
    Struct_ov003_0217cf10 *unknown_98_;
    char unknown_9c_[0xb2 - 0x9c];
    unsigned char unknown_b2_;
};

struct Struct_ov003_0217cf10_4 {
    char unknown_0_[0x3c];
    int unknown_3c_;
    int unknown_40_;
    char unknown_44_[0x4c - 0x44];
    unsigned short unknown_4c_;
    char unknown_4e_[0x50 - 0x4e];
    unsigned char unknown_50_;
    char unknown_51_[0x54 - 0x51];
};

struct Struct_0201099c_3;

struct Struct_ov003_0217cf10_5 {
    unsigned char unknown_0_[4];
    unsigned char unknown_4_;
    signed char unknown_5_;
    char unknown_6_[0xc - 6];
    int unknown_c_;
#if !defined(jpn)
    int unknown_10_;
#endif
    char unknown_14_[0x18 - 0x14];
    unsigned char unknown_18_[0x18];
    unsigned char unknown_30_;
    char unknown_31_;
    unsigned char unknown_32_;
    char unknown_33_;
    int unknown_34_;
    int unknown_38_;
    Struct_ov003_0217cf10_4 unknown_3c_;
    Struct_ov003_0217cf10_3 *unknown_90_;
    Struct_ov003_0217cf10 *unknown_94_;
    Struct_ov003_0217cf10_2 *unknown_98_;
    void *unknown_9c_;
    SafeAllocator *unknown_a0_;
    SafeAllocator unknown_a4_;
    SafeAllocator unknown_b8_;
    char unknown_cc_[8];
};

struct Obj020397cc;
struct SePlayer;
struct ActiveEntry02046900;
struct Rec020467f0;
struct AllocTarget0204b12c;
struct Obj0204b5e8;
struct List0204b0e8;
struct Obj0204c7a8;
struct Struct_0205cf78;
struct Struct_0205cf78_2;

Messages0217cf10 *GetGlobalField0x1c020421a0();
extern "C" Zone0217cf10 *func_02012fe4(void);
void CancelPendingAction020397cc(Obj020397cc *obj, int flag);
void SePlayer_Play(SePlayer *obj, int a, int b);
const char *CallFunc020e0434With02153694_020e51cc(int key);
#if defined(jpn)
extern "C" void func_0204500c(Struct_ov003_0217cf10_6 *arg0, const char *arg1, int arg2);
#else
extern "C" void func_0204500c(Struct_ov003_0217cf10_6 *arg0, const char *arg1, int arg2, int arg3);
#endif
int Pac_CountFiles(ActiveEntry02046900 *archive);
void *Pac_GetFile(Rec020467f0 *archive, int index, void **name, int *size);
extern "C" void SpriteContext_LoadFile(Menu0217cf10 *menu, void *file, int size, SafeAllocator *allocator);
void Background_SetMapSize(unsigned char *background, int a);
extern "C" void Background_SetPriority(Background0217cf10 *background, int a);
void Background_AllocateMap(AllocTarget0204b12c *background, SafeAllocator *allocator);
void Background_SetScroll(Obj0204b5e8 *background, int a, int b);
extern "C" void Background_LoadFile(Background0217cf10 *background, void *file, SafeAllocator *allocator, int size);
extern "C" void Background_FillRect(Background0217cf10 *background, int a, int b, int c, int d, int e, int f);
void Background_UploadMap(List0204b0e8 *background, void *a);
void WindowPane_AllocateBuffer(Obj0204c7a8 *canvas, SafeAllocator *allocator, int pixels, unsigned int size);
void Window_SetPanes(Struct_0205cf78 *window, Elem_0205cf78 *canvases, unsigned char count);
extern "C" void KeyTable_Load(void *texts, SafeAllocator *allocator, void *file, unsigned int size);
const char *KeyTable_Get(Container020e0310 *texts, int key);
extern "C" int func_020420e8(const char *text, int large);

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
extern "C" ARM void func_ov003_0217cf10(Struct_ov003_0217cf10_5 *arg0) {
    Struct_ov003_0217cf10_6 *var0 = func_020421a0();
    GameState *var1 = GameState::GetInstance();
    BackgroundLoader *var2 = BackgroundLoader::GetInstance();
    Struct_ov003_0217cf10_9 *var3 = func_02012fe4();
    Struct_ov003_0217cf10_8 *var4 = &var3->unknown_840_;
    int var5 = arg0->unknown_5_;

    if (step == 0) {
        CancelPendingAction020397cc((Obj020397cc *)gs->GetUnknownGameObject(), 1);
        msg->busy_ = 1;
        SePlayer_Play(&g_sePlayer, 1, 0);
        if (IsSeen(&save->progress_, 0xffffffff)) {
            func_0204500c(msg, data_ov003_0217ee58, 0);
            msg->flag19b2_ = 0;
            msg->busy_ = 1;
        } else {
            func_0204500c(var0, data_ov003_0217ee8c, 0);
            var0->unknown_17e2_ = 0;
            var0->unknown_868_ = 1;
            arg0->unknown_4_ = 1;
            arg0->unknown_5_ = 0;
            return;
        }
        int var6 = 1;
        for (int var7 = 1; var7 < 0x18; var7++) {
            if (var4->unknown_1000_.unknown_b48_ & (1 << var7)) {
                arg0->unknown_18_[var6] = var7;
                var6++;
            }
        }
        self->count_ = count;
        self->pages_ = (self->count_ - 1) / 6 + 1;
        self->menu_.field50_ = 0;
        self->menu_.field40_ = self->field34_;
        self->menu_.field4c_ = 7;
        self->menu_.field3c_ = self->field38_;
        self->task_ = loader->QueueLoadFile(data_ov003_0217eecc, 0);
        self->step_ = 1;
    } else if (step == 1) {
        if (loader->GetTaskStatus(self->task_) == 0) return;
        void *name;
        void *file;
        unsigned int size;
        int recSize;
        loader->GetLoadedFileByID(self->task_, &file, &size);
        int n = Pac_CountFiles((ActiveEntry02046900 *)file);
        for (int i = 0; i < n; i++) {
            void *rec = Pac_GetFile((Rec020467f0 *)file, i, &name, &recSize);
            SpriteContext_LoadFile(&self->menu_, rec, recSize, &self->menuAllocator_);
        }
        loader->RemoveTask(self->task_);
        self->task_ = -1;
        self->task_ = loader->QueueLoadFile(data_ov003_0217eee3, 0);
        self->step_ = 2;
    } else if (step == 2) {
        if (loader->GetTaskStatus(self->task_) == 0) return;
        Background_SetMapSize((unsigned char *)&self->backgrounds_[0], 0);
        self->backgrounds_[0].unk_1c_0_ = 0;
        self->backgrounds_[0].unk_1c_4_ = 1;
        Background_SetPriority(&self->backgrounds_[0], 0);
        Background_AllocateMap((AllocTarget0204b12c *)&self->backgrounds_[0], self->allocator_);
        Background_SetScroll((Obj0204b5e8 *)&self->backgrounds_[0], 0, 0);
        BG1CNT = (BG1CNT & 0x43) | 0xd08;
        Background_SetMapSize((unsigned char *)&self->backgrounds_[1], 0);
        self->backgrounds_[1].unk_1c_0_ = 0;
        self->backgrounds_[1].unk_1c_4_ = 2;
        Background_SetPriority(&self->backgrounds_[1], 1);
        Background_AllocateMap((AllocTarget0204b12c *)&self->backgrounds_[1], self->allocator_);
        Background_SetScroll((Obj0204b5e8 *)&self->backgrounds_[1], 0, 0);
        BG2CNT = (BG2CNT & 0x43) | 0xe08;
        void *name;
        void *file;
        void *recs[2];
        unsigned int size;
        int sizes[2];
        loader->GetLoadedFileByID(self->task_, &file, &size);
        int n = Pac_CountFiles((ActiveEntry02046900 *)file);
        for (int i = 0; i < n; i++) {
            recs[i] = Pac_GetFile((Rec020467f0 *)file, i, &name, &sizes[i]);
        }
        for (int i = 0; i < n; i++) {
            if (recs[i] != 0) {
                Background_LoadFile(&self->backgrounds_[0], recs[i], self->allocator_, sizes[i]);
            }
        }
        loader->RemoveTask(self->task_);
        self->task_ = -1;
        Background_FillRect(&self->backgrounds_[0], 0, 0, 0, 0x20, 0x19, 0);
        Background_UploadMap((List0204b0e8 *)&self->backgrounds_[0], 0);
        Background_FillRect(&self->backgrounds_[1], 0, 0, 0, 0x20, 0x19, 0);
        Background_UploadMap((List0204b0e8 *)&self->backgrounds_[1], 0);
        self->pixels_ = self->allocator_->Allocate(0x2800);
        WindowPane_AllocateBuffer((Obj0204c7a8 *)self->canvas_, self->allocator_, (int)self->pixels_, 0x800);
        self->canvas_->background_ = self->backgrounds_;
        self->canvas_->fieldc4_ = 0;
        Window0217cf10 *window = self->window_;
        window->backgrounds_ = self->backgrounds_;
        window->backgroundCount_ = 2;
        Window_SetPanes((Struct_0205cf78 *)self->window_, (Elem_0205cf78 *)self->canvas_, 1);
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
        arg0->unknown_4_ = 2;
        arg0->unknown_5_ = 0;
    }
}
#else
extern "C" ARM void func_ov003_0217cf10(Struct_ov003_0217cf10_5 *arg0) {
    Struct_ov003_0217cf10_6 *var26 = func_020421a0();
    GameState *var27 = GameState::GetInstance();
    BackgroundLoader *var28 = BackgroundLoader::GetInstance();
    Struct_ov003_0217cf10_9 *var29 = func_02012fe4();
    int var30 = arg0->unknown_5_;

    if (step == 0) {
        Save0217cf10 *save = &zone->save_;
        CancelPendingAction020397cc((Obj020397cc *)gs->GetUnknownGameObject(), 1);
        msg->busy_ = 1;
        SePlayer_Play(&g_sePlayer, 1, 0);
        if (IsSeen(&save->progress_, 0xffffffff)) {
            func_0204500c(msg, CallFunc020e0434With02153694_020e51cc(0x42), 0, 0xe3);
            msg->flag19b2_ = 0;
            msg->busy_ = 1;
        } else {
            func_0204500c(var26, func_020e51cc(0x43), 0, 0xe3);
            var26->unknown_19b2_ = 0;
            var26->unknown_998_ = 1;
            arg0->unknown_4_ = 1;
            arg0->unknown_5_ = 0;
            return;
        }
        int var32 = 1;
        for (int var33 = 1; var33 < 0x18; var33++) {
            if (var31->unknown_1000_.unknown_b48_ & (1 << var33)) {
                arg0->unknown_18_[var32] = var33;
                var32++;
            }
        }
        self->count_ = count;
        self->pages_ = (self->count_ - 1) / 6 + 1;
        self->menu_.field50_ = 0;
        self->menu_.field40_ = self->field34_;
        self->menu_.field4c_ = 7;
        self->menu_.field3c_ = self->field38_;
        self->task_ = loader->QueueLoadFile(data_ov003_02180c2c, 0);
        self->step_ = 1;
    } else if (step == 1) {
        if (loader->GetTaskStatus(self->task_) == 0) return;
        void *name;
        void *file;
        unsigned int size;
        int recSize;
        loader->GetLoadedFileByID(self->task_, &file, &size);
        int n = Pac_CountFiles((ActiveEntry02046900 *)file);
        for (int i = 0; i < n; i++) {
            void *rec = Pac_GetFile((Rec020467f0 *)file, i, &name, &recSize);
            SpriteContext_LoadFile(&self->menu_, rec, recSize, &self->menuAllocator_);
        }
        loader->RemoveTask(self->task_);
        self->task_ = -1;
        self->task_ = loader->QueueLoadFile(data_ov003_02180c43, 0);
        self->step_ = 2;
    } else if (step == 2) {
        if (loader->GetTaskStatus(self->task_) == 0) return;
        Background_SetMapSize((unsigned char *)&self->backgrounds_[0], 0);
        self->backgrounds_[0].unk_1c_0_ = 0;
        self->backgrounds_[0].unk_1c_4_ = 1;
        Background_SetPriority(&self->backgrounds_[0], 0);
        Background_AllocateMap((AllocTarget0204b12c *)&self->backgrounds_[0], self->allocator_);
        Background_SetScroll((Obj0204b5e8 *)&self->backgrounds_[0], 0, 0);
        BG1CNT = (BG1CNT & 0x43) | 0xd08;
        Background_SetMapSize((unsigned char *)&self->backgrounds_[1], 0);
        self->backgrounds_[1].unk_1c_0_ = 0;
        self->backgrounds_[1].unk_1c_4_ = 2;
        Background_SetPriority(&self->backgrounds_[1], 1);
        Background_AllocateMap((AllocTarget0204b12c *)&self->backgrounds_[1], self->allocator_);
        Background_SetScroll((Obj0204b5e8 *)&self->backgrounds_[1], 0, 0);
        BG2CNT = (BG2CNT & 0x43) | 0xe08;
        void *name;
        void *file;
        void *recs[2];
        unsigned int size;
        int sizes[2];
        loader->GetLoadedFileByID(self->task_, &file, &size);
        int n = Pac_CountFiles((ActiveEntry02046900 *)file);
        for (int i = 0; i < n; i++) {
            recs[i] = Pac_GetFile((Rec020467f0 *)file, i, &name, &sizes[i]);
        }
        for (int i = 0; i < n; i++) {
            if (recs[i] != 0) {
                Background_LoadFile(&self->backgrounds_[0], recs[i], self->allocator_, sizes[i]);
            }
        }
        loader->RemoveTask(self->task_);
        self->task_ = -1;
        Background_FillRect(&self->backgrounds_[0], 0, 0, 0, 0x20, 0x19, 0);
        Background_UploadMap((List0204b0e8 *)&self->backgrounds_[0], 0);
        Background_FillRect(&self->backgrounds_[1], 0, 0, 0, 0x20, 0x19, 0);
        Background_UploadMap((List0204b0e8 *)&self->backgrounds_[1], 0);
        self->pixels_ = self->allocator_->Allocate(0x2800);
        WindowPane_AllocateBuffer((Obj0204c7a8 *)self->canvas_, self->allocator_, (int)self->pixels_, 0x800);
        self->canvas_->background_ = self->backgrounds_;
        self->canvas_->fieldc4_ = 0;
        Window0217cf10 *window = self->window_;
        window->backgrounds_ = self->backgrounds_;
        window->backgroundCount_ = 2;
        Window_SetPanes((Struct_0205cf78 *)self->window_, (Elem_0205cf78 *)self->canvas_, 1);
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
        int maxWidth = 0;
        for (int key = 0x64; key < 0x7c; key++) {
            int width = 0;
            const char *text = KeyTable_Get((Container020e0310 *)self->texts_, (short)key);
            if (text != 0) {
                width = func_020420e8(text, 0);
            }
            if (var52 < var54) {
                var52 = var54;
            }
        }
        arg0->unknown_10_ = (var52 + 0x1b) & ~7;
        arg0->unknown_10_ = arg0->unknown_10_ >> 3;
        arg0->unknown_10_ = ((arg0->unknown_10_ + 1) & ~1) << 3;
        DISPCNT = (DISPCNT & ~0x1f00) | 0x1700;
        arg0->unknown_4_ = 2;
        arg0->unknown_5_ = 0;
    }
}
#endif
