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

int Pac_CountFiles(PacRecord *archive);
void *Pac_GetFile(PacRecord *archive, int index, void **name, int *size);
extern "C" void SpriteContext_LoadFile(void *renderer, void *file, unsigned int size, void *allocator);
extern "C" void WindowPane_Init(void *canvas);
extern "C" Zone02172a14 *Zone3D_GetInstance(void);
extern "C" void __clear(void *dst, int count);
extern "C" void func_0204f41c(void *canvas, int a, int b, char *text, int c, int d, short *outA, short *outB, int e);
void Background_Init(BackgroundGraphics *obj);
void Background_SetMapSize(unsigned char *obj, int a);
void Background_SetScroll(BackgroundGraphics *obj, int a, int b);
void Background_FlushFile(void *obj, char *str);
void Background_UploadFile(BackgroundGraphics *self, char *str);
extern "C" void ColorEffect_ConfigureAlphaBlend(int control, int a, int b, int c, int d);
void SetMainBrightness(GameResources *resources, int a, int b);
extern "C" void func_020728ac(void *arg0, void *arg1, void *arg2, unsigned int arg3, int arg4, int arg5, int arg6);

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
    unsigned char unknown_0_[0xb34];
    int unknown_b34_;
};

struct Struct_ov003_02172a14 {
    unsigned char unknown_0_[0x1840];
    Struct_02000c9c_88 unknown_1840_;
};

static inline Struct_02000c9c_88 *inline_ov003_0216e714_2(Struct_ov003_02172a14 *arg0) { return &arg0->unknown_1840_; }
static inline int inline_ov003_02172a14(Struct_02000c9c_88 *arg0) { return arg0->unknown_b34_; }

struct Struct_ov003_02172a14_2 {
    unsigned char unknown_0_[0x1c];
    unsigned char unknown_1c_0_ : 4;
    unsigned char unknown_1c_4_ : 4;
    unsigned char unknown_1d_[3];
};

struct Struct_ov003_02172a14_3 {
    void *unknown_0_;
    void *unknown_4_;
    void *unknown_8_;
    char unknown_c_[0xa8 - 0xc];
    short unknown_a8_;
    short unknown_aa_;
    char unknown_ac_[0xb4 - 0xac];
    short unknown_b4_;
    short unknown_b6_;
    char unknown_b8_[0xe0 - 0xb8];
};

struct Struct_ov003_02172a14_4 {
    char unknown_0_[0xec];
    unsigned char unknown_ec_;
    char unknown_ed_;
    unsigned char unknown_ee_;
    char unknown_ef_;
    int unknown_f0_;
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
extern "C" ARM void func_ov003_02172a14(Self02172a14 *self) {
    GameResources *res       = GetGameResources();
    BackgroundLoader *loader = BackgroundLoader::GetInstance();
    FontBankLoader* global = FontBankLoader_GetInstance();
    if (self->step_ == 0) {
        self->b180_ = 0;
        self->w170_ = self->w128_;
        self->h17c_ = 0xd;
        self->w16c_ = self->w12c_;
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
        var1->RemoveTask(arg0->unknown_f0_);
        arg0->unknown_f0_ = -1;
        arg0->unknown_f0_ = var1->QueueLoadFileInGP2(data_ov003_021809d4, data_ov003_021809e6, 0);
        arg0->unknown_ee_ = 2;
    }
    if (self->step_ == 2) {
        if (loader->GetTaskStatus(self->task_) == 0) return;
        void *name;
        void *file;
        unsigned int size;
        void *datas[3];
        int sizes[3];
        Canvas02172a14 canvas;
        char text[0x40];
        List02172a14 list;
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
        canvas.unk_b4  = 8;
        canvas.unk_b6  = 8;
        Zone02172a14 *zone = Zone3D_GetInstance();
        __clear(text, 0x40);
        int v = GetValue(GetProgress(zone));
        if (v > 9999) v = 9999;
        sprintf(text, data_ov003_021809f4, v);
        func_0204f41c(&canvas, 0xb0, 0x48, text, 8, 1, &outA, &outB, 0);
        Background_Init((BackgroundGraphics *) &list);
        list.lo_ = 0;
        list.hi_ = 1;
        Background_SetMapSize((unsigned char *) &list, 0);
        Background_SetScroll((BackgroundGraphics *) &list, 0, 0);
        for (int i = 0; i < count; i++) {
            Background_FlushFile(&list, (char *) datas[i]);
            Background_UploadFile((BackgroundGraphics *) &list, (char *) datas[i]);
        }
        ColorEffect_ConfigureAlphaBlend(0x04000050, 1, 0x12, 0x1f, 0x1f);
        SetMainBrightness(var0, 0, 0x18);
        var1->RemoveTask(arg0->unknown_f0_);
        arg0->unknown_f0_ = -1;
        arg0->unknown_f0_ = var1->QueueLoadFileInGP2(data_ov003_021809f8, data_ov003_02180a0d, 0);
        arg0->unknown_ee_ = 3;
    }
    if (arg0->unknown_ee_ == 3) {
        if (var1->GetTaskStatus(arg0->unknown_f0_) == 0) return;
        void *var25;
        unsigned int var26;
        var1->GetLoadedFileByID(arg0->unknown_f0_, &var25, &var26);
        func_020728ac((char *) arg0 + 0x1d0, (char *) arg0 + 0x184, var25, var26, 0, 0, 0);
        var1->RemoveTask(arg0->unknown_f0_);
        arg0->unknown_f0_ = var1->QueueLoadFileInGP2(data_ov003_02180a1e, data_ov003_02180a38, 0);
        arg0->unknown_ee_ = 4;
    }
    if (arg0->unknown_ee_ == 4) {
        if (var1->GetTaskStatus(arg0->unknown_f0_) == 0) return;
        void *var27;
        unsigned int var28;
        var1->GetLoadedFileByID(arg0->unknown_f0_, &var27, &var28);
        func_020728ac((char *) arg0 + 0x1d8, (char *) arg0 + 0x198, var27, var28, 0, 0, 0);
        var1->RemoveTask(arg0->unknown_f0_);
        arg0->unknown_f0_ = -1;
        arg0->unknown_ee_ = 5;
    }
    if (arg0->unknown_ee_ == 5) {
        func_02094b30(var2, 0x1ff, 0);
        if (func_02094b4c(var2) != 0) {
            arg0->unknown_ec_ = 2;
            arg0->unknown_ee_  = 0;
        }
    }
}
