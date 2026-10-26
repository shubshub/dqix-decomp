#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "Resource/GameResources.h"

struct GameResources;
struct PacRecord;
struct BackgroundGraphics;
struct Zone02172a14;

extern "C" int Pac_CountFiles(PacRecord *archive);
extern "C" void *Pac_GetFile(PacRecord *archive, int index, void **name, int *size);
extern "C" void SpriteContext_LoadFile(void *renderer, void *file, unsigned int size, void *allocator);
extern "C" void WindowPane_Init(void *canvas);
extern "C" Zone02172a14 *Zone3D_GetInstance(void);
extern "C" void __clear(void *dst, int count);
extern "C" void func_0204f41c(void *canvas, int a, int b, char *text, int c, int d, short *outA, short *outB, int e);
extern "C" void Background_Init(BackgroundGraphics *obj);
extern "C" void Background_SetMapSize(unsigned char *obj, int a);
extern "C" void Background_SetScroll(BackgroundGraphics *obj, int a, int b);
extern "C" void Background_FlushFile(void *obj, char *str);
extern "C" void Background_UploadFile(BackgroundGraphics *self, char *str);
extern "C" void ColorEffect_ConfigureAlphaBlend(int control, int a, int b, int c, int d);
void SetMainBrightness(GameResources *resources, int a, int b);
extern "C" void func_020728ac(void *a, void *b, void *file, unsigned int size, int c, int d, int e);

extern char data_ov003_021809b0[];
extern char data_ov003_021809c4[];
extern char data_ov003_021809d4[];
extern char data_ov003_021809e6[];
extern char data_ov003_021809f4[];
extern char data_ov003_021809f8[];
extern char data_ov003_02180a0d[];
extern char data_ov003_02180a1e[];
extern char data_ov003_02180a38[];

struct Struct_02000c9c_88 {
    unsigned char pad0[0xb34];
    int unknown_b34_;
};

struct Zone02172a14 {
    unsigned char pad0[0x1840];
    Struct_02000c9c_88 unknown_1840_;
};

static inline Struct_02000c9c_88 *GetProgress(Zone02172a14 *zone) { return &zone->unknown_1840_; }
static inline int inline_ov003_02172a14(Struct_02000c9c_88 *progress) { return progress->unknown_b34_; }

struct Struct_ov003_02172a14_2 {
    unsigned char pad0[0x1c];
    unsigned char unknown_1c_0_ : 4;
    unsigned char unknown_1c_4_ : 4;
    unsigned char unknown_1d_[3];
};

struct Struct_ov003_02172a14_3 {
    void *unk_0;
    void *background_;
    void *pixels_;
    char unk_c[0xa8 - 0xc];
    short width_;
    short height_;
    char unk_ac[0xb4 - 0xac];
    short unknown_b4_;
    short unknown_b6_;
    char unk_b8[0xe0 - 0xb8];
};

struct Struct_ov003_02172a14_4 {
    char unknown_0_[0xec];
    unsigned char unknown_ec_;
    char unknown_ed_;
    unsigned char step_;
    char unknown_ef_;
    int task_;
    char unknown_f4_[0x128 - 0xf4];
    int unknown_128_;
    int unknown_12c_;
    char unknown_130_[0x16c - 0x130];
    int unknown_16c_;
    int unknown_170_;
    char unknown_174_[0x17c - 0x174];
    short unknown_17c_;
    char unknown_17e_[2];
    unsigned char unknown_180_;
    char unknown_181_[0x1d8 + 8 - 0x181];
};

// USA: func_ov003_02172a14
extern "C" ARM void func_ov003_02172a14(Struct_ov003_02172a14_4 *self) {
    GameResources *res       = GetGameResources();
    BackgroundLoader *loader = BackgroundLoader::GetInstance();
    FontBankLoader* global = FontBankLoader_GetInstance();
    if (self->step_ == 0) {
        self->unknown_180_ = 0;
        self->unknown_170_ = self->unknown_128_;
        self->unknown_17c_ = 0xd;
        self->unknown_16c_ = self->unknown_12c_;
        self->task_ = loader->QueueLoadFileInGP2(data_ov003_021809b0, data_ov003_021809c4, 0);
        self->step_ = 1;
    }
    if (self->step_ == 1) {
        if (loader->GetTaskStatus(self->task_) == 0) return;
        void *name;
        void *file;
        unsigned int size;
        int fileSize;
        loader->GetLoadedFileByID(self->task_, &file, &size);
        int count = Pac_CountFiles((PacRecord *) file);
        for (int i = 0; i < count; i++) {
            void *data = Pac_GetFile((PacRecord *) file, i, &name, &fileSize);
            SpriteContext_LoadFile((char *) self + 0x130, data, fileSize, (char *) self + 0x1ac);
        }
        loader->RemoveTask(self->task_);
        self->task_ = -1;
        self->task_ = loader->QueueLoadFileInGP2(data_ov003_021809d4, data_ov003_021809e6, 0);
        self->step_ = 2;
    }
    if (self->step_ == 2) {
        if (loader->GetTaskStatus(self->task_) == 0) return;
        void *name;
        void *file;
        unsigned int size;
        void *datas[3];
        int sizes[3];
        Struct_ov003_02172a14_3 canvas;
        char text[0x40];
        Struct_ov003_02172a14_2 list;
        short outA;
        short outB;
        loader->GetLoadedFileByID(self->task_, &file, &size);
        int count = Pac_CountFiles((PacRecord *) file);
        for (int i = 0; i < count; i++) {
            datas[i] = Pac_GetFile((PacRecord *) file, i, &name, &sizes[i]);
        }
        WindowPane_Init(&canvas);
        canvas.pixels_ = (char *) datas[0] + 0x10;
        canvas.width_  = 0x20;
        canvas.height_ = 0x18;
        canvas.unknown_b4_  = 8;
        canvas.unknown_b6_  = 8;
        Zone02172a14 *zone = Zone3D_GetInstance();
        __clear(text, 0x40);
        int v = inline_ov003_02172a14(GetProgress(zone));
        if (v > 9999) v = 9999;
        sprintf(text, data_ov003_021809f4, v);
        func_0204f41c(&canvas, 0xb0, 0x48, text, 8, 1, &outA, &outB, 0);
        Background_Init((BackgroundGraphics *) &list);
        list.unknown_1c_0_ = 0;
        list.unknown_1c_4_ = 1;
        Background_SetMapSize((unsigned char *) &list, 0);
        Background_SetScroll((BackgroundGraphics *) &list, 0, 0);
        for (int i = 0; i < count; i++) {
            Background_FlushFile(&list, (char *) datas[i]);
            Background_UploadFile((BackgroundGraphics *) &list, (char *) datas[i]);
        }
        ColorEffect_ConfigureAlphaBlend(0x04000050, 1, 0x12, 0x1f, 0x1f);
        SetMainBrightness(res, 0, 0x18);
        loader->RemoveTask(self->task_);
        self->task_ = -1;
        self->task_ = loader->QueueLoadFileInGP2(data_ov003_021809f8, data_ov003_02180a0d, 0);
        self->step_ = 3;
    }
    if (self->step_ == 3) {
        if (loader->GetTaskStatus(self->task_) == 0) return;
        void *file;
        unsigned int size;
        loader->GetLoadedFileByID(self->task_, &file, &size);
        func_020728ac((char *) self + 0x1d0, (char *) self + 0x184, file, size, 0, 0, 0);
        loader->RemoveTask(self->task_);
        self->task_ = loader->QueueLoadFileInGP2(data_ov003_02180a1e, data_ov003_02180a38, 0);
        self->step_ = 4;
    }
    if (self->step_ == 4) {
        if (loader->GetTaskStatus(self->task_) == 0) return;
        void *file;
        unsigned int size;
        loader->GetLoadedFileByID(self->task_, &file, &size);
        func_020728ac((char *) self + 0x1d8, (char *) self + 0x198, file, size, 0, 0, 0);
        loader->RemoveTask(self->task_);
        self->task_ = -1;
        self->step_ = 5;
    }
    if (self->step_ == 5) {
        func_02094b30(global, 0x1ff, 0);
        if (func_02094b4c(global) != 0) {
            self->unknown_ec_ = 2;
            self->step_  = 0;
        }
    }
}
