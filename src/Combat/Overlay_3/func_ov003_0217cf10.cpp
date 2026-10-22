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
    char pad86c[0x17e2 - 0x86c];
    unsigned char flag19b2_;
#else
    char pad0[0x998];
    int busy_;
    char pad99c[0x19b2 - 0x99c];
    unsigned char flag19b2_;
#endif
};

struct Progress0217cf10 {
    unsigned char pad0[0xb48];
    unsigned int seen_;
};

struct Save0217cf10 {
    unsigned char pad0[0x1000];
    Progress0217cf10 progress_;
};

struct Zone0217cf10 {
#if defined(jpn)
    unsigned char pad0[0x860];
#else
    unsigned char pad0[0x840];
#endif
    Save0217cf10 save_;
};

static inline unsigned int GetSeen(Progress0217cf10 *progress) { return progress->seen_; }
static inline bool IsSeen(Progress0217cf10 *progress, unsigned int mask) { return (GetSeen(progress) & mask) != 0; }

struct Background0217cf10 {
    char unk_0[0x1c];
    unsigned char unk_1c_0_ : 4;
    unsigned char unk_1c_4_ : 4;
    unsigned char unk_1d;
    char unk_1e[2];
};

struct Canvas0217cf10 {
    Canvas0217cf10 *previous_;
    Background0217cf10 *background_;
    char pad8[0xc4 - 8];
    unsigned char fieldc4_;
    char padc5[0xe0 - 0xc5];
};

struct Window0217cf10 {
    char pad0[0x98];
    Background0217cf10 *backgrounds_;
    char pad9c[0xb2 - 0x9c];
    unsigned char backgroundCount_;
};

struct Menu0217cf10 {
    char pad0[0x3c];
    int field3c_;
    int field40_;
    char pad44[0x4c - 0x44];
    unsigned short field4c_;
    char pad4e[0x50 - 0x4e];
    unsigned char field50_;
    char pad51[0x54 - 0x51];
};

struct Container020e0310;

struct Self0217cf10 {
    unsigned char pad0[4];
    unsigned char state_;
    signed char step_;
    char pad6[0xc - 6];
    int task_;
#if !defined(jpn)
    int width_;
#endif
    char pad14[0x18 - 0x14];
    unsigned char list_[0x18];
    unsigned char count_;
    char pad31;
    unsigned char pages_;
    char pad33;
    int field34_;
    int field38_;
    Menu0217cf10 menu_;
    Window0217cf10 *window_;
    Background0217cf10 *backgrounds_;
    Canvas0217cf10 *canvas_;
    void *pixels_;
    SafeAllocator *allocator_;
    SafeAllocator textAllocator_;
    SafeAllocator menuAllocator_;
    char texts_[8];
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
struct Elem_0205cf78;

Messages0217cf10 *GetGlobalField0x1c020421a0();
extern "C" Zone0217cf10 *func_02012fe4(void);
void CancelPendingAction020397cc(Obj020397cc *obj, int flag);
void SePlayer_Play(SePlayer *obj, int a, int b);
const char *CallFunc020e0434With02153694_020e51cc(int key);
#if defined(jpn)
extern "C" void func_0204500c(Messages0217cf10 *window, const char *text, int mode);
#else
extern "C" void func_0204500c(Messages0217cf10 *window, const char *text, int mode, int width);
#endif
int CountActiveEntries(ActiveEntry02046900 *archive);
void *FindRecordByIndex(Rec020467f0 *archive, int index, void **name, int *size);
extern "C" void func_0205a528(Menu0217cf10 *menu, void *file, int size, SafeAllocator *allocator);
void SetWord0x18ClearByte0x1f_0204b11c(unsigned char *background, int a);
extern "C" void func_0204b5b4(Background0217cf10 *background, int a);
void AllocateAndClearBuffer0204b12c(AllocTarget0204b12c *background, SafeAllocator *allocator);
void DispatchViaTable0204b5e8(Obj0204b5e8 *background, int a, int b);
extern "C" void func_0204b174(Background0217cf10 *background, void *file, SafeAllocator *allocator, int size);
extern "C" void func_0204bc74(Background0217cf10 *background, int a, int b, int c, int d, int e, int f);
void FlushAndDispatchList0204b0e8(List0204b0e8 *background, void *a);
void AllocateBuffer0204c7a8(Obj0204c7a8 *canvas, SafeAllocator *allocator, int pixels, unsigned int size);
void LinkArrayPrevPointers0205cf78(Struct_0205cf78 *window, Elem_0205cf78 *canvases, unsigned char count);
extern "C" void func_020dfec0(void *texts, SafeAllocator *allocator, void *file, unsigned int size);
const char *GetFieldByKey020e0434(Container020e0310 *texts, int key);
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
extern "C" ARM void func_ov003_0217cf10(Self0217cf10 *self) {
    Messages0217cf10 *msg = GetGlobalField0x1c020421a0();
    GameState *gs = GameState::GetInstance();
    BackgroundLoader *loader = BackgroundLoader::GetInstance();
    Zone0217cf10 *zone = func_02012fe4();
    Save0217cf10 *save = &zone->save_;
    int step = self->step_;

    if (step == 0) {
        CancelPendingAction020397cc((Obj020397cc *)gs->GetUnknownGameObject(), 1);
        msg->busy_ = 1;
        SePlayer_Play(&g_sePlayer, 1, 0);
        if (IsSeen(&save->progress_, 0xffffffff)) {
            func_0204500c(msg, data_ov003_0217ee58, 0);
            msg->flag19b2_ = 0;
            msg->busy_ = 1;
        } else {
            func_0204500c(msg, data_ov003_0217ee8c, 0);
            msg->flag19b2_ = 0;
            msg->busy_ = 1;
            self->state_ = 1;
            self->step_ = 0;
            return;
        }
        int count = 1;
        for (int i = 1; i < 0x18; i++) {
            if (save->progress_.seen_ & (1 << i)) {
                self->list_[count] = i;
                count++;
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
        int n = CountActiveEntries((ActiveEntry02046900 *)file);
        for (int i = 0; i < n; i++) {
            void *rec = FindRecordByIndex((Rec020467f0 *)file, i, &name, &recSize);
            func_0205a528(&self->menu_, rec, recSize, &self->menuAllocator_);
        }
        loader->RemoveTask(self->task_);
        self->task_ = -1;
        self->task_ = loader->QueueLoadFile(data_ov003_0217eee3, 0);
        self->step_ = 2;
    } else if (step == 2) {
        if (loader->GetTaskStatus(self->task_) == 0) return;
        SetWord0x18ClearByte0x1f_0204b11c((unsigned char *)&self->backgrounds_[0], 0);
        self->backgrounds_[0].unk_1c_0_ = 0;
        self->backgrounds_[0].unk_1c_4_ = 1;
        func_0204b5b4(&self->backgrounds_[0], 0);
        AllocateAndClearBuffer0204b12c((AllocTarget0204b12c *)&self->backgrounds_[0], self->allocator_);
        DispatchViaTable0204b5e8((Obj0204b5e8 *)&self->backgrounds_[0], 0, 0);
        BG1CNT = (BG1CNT & 0x43) | 0xd08;
        SetWord0x18ClearByte0x1f_0204b11c((unsigned char *)&self->backgrounds_[1], 0);
        self->backgrounds_[1].unk_1c_0_ = 0;
        self->backgrounds_[1].unk_1c_4_ = 2;
        func_0204b5b4(&self->backgrounds_[1], 1);
        AllocateAndClearBuffer0204b12c((AllocTarget0204b12c *)&self->backgrounds_[1], self->allocator_);
        DispatchViaTable0204b5e8((Obj0204b5e8 *)&self->backgrounds_[1], 0, 0);
        BG2CNT = (BG2CNT & 0x43) | 0xe08;
        void *name;
        void *file;
        void *recs[2];
        unsigned int size;
        int sizes[2];
        loader->GetLoadedFileByID(self->task_, &file, &size);
        int n = CountActiveEntries((ActiveEntry02046900 *)file);
        for (int i = 0; i < n; i++) {
            recs[i] = FindRecordByIndex((Rec020467f0 *)file, i, &name, &sizes[i]);
        }
        for (int i = 0; i < n; i++) {
            if (recs[i] != 0) {
                func_0204b174(&self->backgrounds_[0], recs[i], self->allocator_, sizes[i]);
            }
        }
        loader->RemoveTask(self->task_);
        self->task_ = -1;
        func_0204bc74(&self->backgrounds_[0], 0, 0, 0, 0x20, 0x19, 0);
        FlushAndDispatchList0204b0e8((List0204b0e8 *)&self->backgrounds_[0], 0);
        func_0204bc74(&self->backgrounds_[1], 0, 0, 0, 0x20, 0x19, 0);
        FlushAndDispatchList0204b0e8((List0204b0e8 *)&self->backgrounds_[1], 0);
        self->pixels_ = self->allocator_->Allocate(0x2800);
        AllocateBuffer0204c7a8((Obj0204c7a8 *)self->canvas_, self->allocator_, (int)self->pixels_, 0x800);
        self->canvas_->background_ = self->backgrounds_;
        self->canvas_->fieldc4_ = 0;
        Window0217cf10 *window = self->window_;
        window->backgrounds_ = self->backgrounds_;
        window->backgroundCount_ = 2;
        LinkArrayPrevPointers0205cf78((Struct_0205cf78 *)self->window_, (Elem_0205cf78 *)self->canvas_, 1);
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
        func_020dfec0(self->texts_, &self->textAllocator_, file, size);
        loader->RemoveTask(self->task_);
        self->task_ = -1;
        DISPCNT = (DISPCNT & ~0x1f00) | 0x1700;
        self->state_ = 2;
        self->step_ = 0;
    }
}
#else
extern "C" ARM void func_ov003_0217cf10(Self0217cf10 *self) {
    Messages0217cf10 *msg = GetGlobalField0x1c020421a0();
    GameState *gs = GameState::GetInstance();
    BackgroundLoader *loader = BackgroundLoader::GetInstance();
    Zone0217cf10 *zone = func_02012fe4();
    int step = self->step_;

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
            func_0204500c(msg, CallFunc020e0434With02153694_020e51cc(0x43), 0, 0xe3);
            msg->flag19b2_ = 0;
            msg->busy_ = 1;
            self->state_ = 1;
            self->step_ = 0;
            return;
        }
        int count = 1;
        for (int i = 1; i < 0x18; i++) {
            if (save->progress_.seen_ & (1 << i)) {
                self->list_[count] = i;
                count++;
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
        int n = CountActiveEntries((ActiveEntry02046900 *)file);
        for (int i = 0; i < n; i++) {
            void *rec = FindRecordByIndex((Rec020467f0 *)file, i, &name, &recSize);
            func_0205a528(&self->menu_, rec, recSize, &self->menuAllocator_);
        }
        loader->RemoveTask(self->task_);
        self->task_ = -1;
        self->task_ = loader->QueueLoadFile(data_ov003_02180c43, 0);
        self->step_ = 2;
    } else if (step == 2) {
        if (loader->GetTaskStatus(self->task_) == 0) return;
        SetWord0x18ClearByte0x1f_0204b11c((unsigned char *)&self->backgrounds_[0], 0);
        self->backgrounds_[0].unk_1c_0_ = 0;
        self->backgrounds_[0].unk_1c_4_ = 1;
        func_0204b5b4(&self->backgrounds_[0], 0);
        AllocateAndClearBuffer0204b12c((AllocTarget0204b12c *)&self->backgrounds_[0], self->allocator_);
        DispatchViaTable0204b5e8((Obj0204b5e8 *)&self->backgrounds_[0], 0, 0);
        BG1CNT = (BG1CNT & 0x43) | 0xd08;
        SetWord0x18ClearByte0x1f_0204b11c((unsigned char *)&self->backgrounds_[1], 0);
        self->backgrounds_[1].unk_1c_0_ = 0;
        self->backgrounds_[1].unk_1c_4_ = 2;
        func_0204b5b4(&self->backgrounds_[1], 1);
        AllocateAndClearBuffer0204b12c((AllocTarget0204b12c *)&self->backgrounds_[1], self->allocator_);
        DispatchViaTable0204b5e8((Obj0204b5e8 *)&self->backgrounds_[1], 0, 0);
        BG2CNT = (BG2CNT & 0x43) | 0xe08;
        void *name;
        void *file;
        void *recs[2];
        unsigned int size;
        int sizes[2];
        loader->GetLoadedFileByID(self->task_, &file, &size);
        int n = CountActiveEntries((ActiveEntry02046900 *)file);
        for (int i = 0; i < n; i++) {
            recs[i] = FindRecordByIndex((Rec020467f0 *)file, i, &name, &sizes[i]);
        }
        for (int i = 0; i < n; i++) {
            if (recs[i] != 0) {
                func_0204b174(&self->backgrounds_[0], recs[i], self->allocator_, sizes[i]);
            }
        }
        loader->RemoveTask(self->task_);
        self->task_ = -1;
        func_0204bc74(&self->backgrounds_[0], 0, 0, 0, 0x20, 0x19, 0);
        FlushAndDispatchList0204b0e8((List0204b0e8 *)&self->backgrounds_[0], 0);
        func_0204bc74(&self->backgrounds_[1], 0, 0, 0, 0x20, 0x19, 0);
        FlushAndDispatchList0204b0e8((List0204b0e8 *)&self->backgrounds_[1], 0);
        self->pixels_ = self->allocator_->Allocate(0x2800);
        AllocateBuffer0204c7a8((Obj0204c7a8 *)self->canvas_, self->allocator_, (int)self->pixels_, 0x800);
        self->canvas_->background_ = self->backgrounds_;
        self->canvas_->fieldc4_ = 0;
        Window0217cf10 *window = self->window_;
        window->backgrounds_ = self->backgrounds_;
        window->backgroundCount_ = 2;
        LinkArrayPrevPointers0205cf78((Struct_0205cf78 *)self->window_, (Elem_0205cf78 *)self->canvas_, 1);
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
        func_020dfec0(self->texts_, &self->textAllocator_, file, size);
        loader->RemoveTask(self->task_);
        self->task_ = -1;
        int maxWidth = 0;
        for (int key = 0x64; key < 0x7c; key++) {
            int width = 0;
            const char *text = GetFieldByKey020e0434((Container020e0310 *)self->texts_, (short)key);
            if (text != 0) {
                width = func_020420e8(text, 0);
            }
            if (maxWidth < width) {
                maxWidth = width;
            }
        }
        self->width_ = (maxWidth + 0x1b) & ~7;
        self->width_ = self->width_ >> 3;
        self->width_ = ((self->width_ + 1) & ~1) << 3;
        DISPCNT = (DISPCNT & ~0x1f00) | 0x1700;
        self->state_ = 2;
        self->step_ = 0;
    }
}
#endif
