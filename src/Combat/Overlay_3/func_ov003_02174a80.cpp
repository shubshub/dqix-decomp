#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/ColorEffects.h"
#include "NitroSDK/Graphics.h"
#include "std_library_functions.h"

#if defined(jpn)
enum { kSelfBodyEnd = 0x7ac, kSelfField874 = 0x7f0, kSelfField7D8 = 0x754, kGlobalPrefix = 0x228, kGlobalGap = 0x870 - 0x237 };
extern const char* g_itemDataArchive;
extern const char data_ov003_0217ed74[];
extern const char data_ov003_0217eda8[];
extern const char data_ov003_0217edc6[];
extern "C" void func_02080654(void*, SafeAllocator*, const char*);
extern "C" void func_020dfc84(void*, SafeAllocator*, const char*, int, int, int);
#else
enum { Enum_ov003_02174a80_2096 = 0x830, Enum_ov003_02174a80_2164 = 0x874, Enum_ov003_02174a80_2008 = 0x7d8, Enum_ov003_02174a80_728 = 0x2d8, Enum_ov003_02174a80_1721 = 0x9a0 - 0x2e7 };
#endif

struct Struct_ov003_02174a80_6 {
    int unknown_0_;
    int unknown_4_;
};

struct Struct_ov003_02174a80_7 {
    SafeAllocator unknown_0_[6];
};

struct Struct_ov003_02174a80_8 {
    char unknown_0_[0x20];
    int unknown_20_;
};

struct Struct_ov003_02174a80 {
    char unknown_0_[Enum_ov003_02174a80_728];
    void* unknown_2d8_;
    int unknown_2dc_;
    int unknown_2e0_;
    unsigned short unknown_2e4_;
    unsigned char unknown_2e6_;
    char unknown_2e7_[Enum_ov003_02174a80_1721];
    int unknown_9a0_;
};

struct Struct_ov003_02174a80_2 {
    char unknown_0_[4];
    short unknown_4_;
    char unknown_6_[0x16];
    unsigned char unknown_1c_0_ : 4;
    unsigned char unknown_1c_4_ : 4;
    char unknown_1d_[3];
};

struct Struct_ov003_02174a80_3 {
    char unknown_0_[4];
    void* unknown_4_;
    char unknown_8_[0xe0 - 8];
};

struct Struct_ov003_02174a80_4 {
    char unknown_0_[2];
    short unknown_2_;
    short unknown_4_[0x12];
    unsigned short unknown_28_;
    unsigned char unknown_2a_;
};

struct Struct_ov003_02174a80_5 {
    Struct_ov003_02174a80_8* unknown_0_;
    Struct_ov003_02174a80_7* unknown_4_;
    char unknown_8_[4];
    char unknown_c_[Enum_ov003_02174a80_2096 - 0xc];
    int unknown_830_;
    unsigned char unknown_834_;
    unsigned char unknown_835_;
    unsigned char unknown_836_[0x12];
    short unknown_848_[0x12];
    unsigned short unknown_86c_;
    short unknown_86e_;
    unsigned char unknown_870_;
    char unknown_871_[0x89c - 0x871];
    void* unknown_89c_;
    Struct_ov003_02174a80_2 unknown_8a0_[2];
    Struct_ov003_02174a80_3 unknown_8e0_[8];
    char unknown_fe0_[0xc];
    int unknown_fec_;
    int unknown_ff0_;
    void* unknown_ff4_;
    char unknown_ff8_[0x1034 - 0xff8];
    short unknown_1034_;
    char unknown_1036_[0x103e - 0x1036];
    unsigned char unknown_103e_;
    unsigned char unknown_103f_;
    char unknown_1040_;
    unsigned char unknown_1041_;
    char unknown_1042_[4];
    unsigned short unknown_1046_;
};

void ItemTable_Init(void*);
extern "C" void func_020dea64(void*, SafeAllocator*, void*, unsigned int, const char*, int);
struct Struct_02072488;
extern "C" void func_02072488(Struct_02072488*);
struct Struct_02013fb4;
extern "C" void func_0207249c(int, int, Struct_02013fb4*, int);
extern "C" void* func_0206f504(void);
struct Struct_0206f7f4;
extern "C" short func_0206f7f4(Struct_0206f7f4*, int);
struct Struct_020725d8;
extern "C" Struct_ov003_02174a80_4* func_020725d8(Struct_020725d8*, int);
struct Struct_ov003_02174114_4;
extern "C" void func_ov003_02174408(Struct_ov003_02174114_4*);
#if !defined(jpn)
extern "C" void func_020dfc84(void*, SafeAllocator*, char*, char*, int, int);
#endif
extern "C" int func_020dfd40(void*, int, int);
void Background_SetMapSize(unsigned char*, int);
extern "C" void Background_SetPriority(void*, int);
struct AllocTarget0204b12c;
void Background_AllocateMap(AllocTarget0204b12c*, SafeAllocator*);
struct Obj0204b5e8;
void Background_SetScroll(Obj0204b5e8*, int, int);
extern "C" void MapVRAMBanksToMainBG(int);
extern "C" void MapVRAMBanksToMainObj(int);
struct ActiveEntry02046900;
int Pac_CountFiles(ActiveEntry02046900*);
struct Rec020467f0;
void* Pac_GetFile(Rec020467f0*, int, void**, int*);
extern "C" void Background_LoadFile(void*, void*, SafeAllocator*, int);
extern "C" void Background_FillRect(void*, int, int, int, int, int, int);
struct List0204b0e8;
void Background_UploadMap(List0204b0e8*, void*);
struct Obj0204c7a8;
void WindowPane_AllocateBuffer(Obj0204c7a8*, SafeAllocator*, int, unsigned int);
struct Obj0207f914;
void SetFieldsFromFormattedValue0207f914(Obj0207f914*, int, int, int);
extern "C" int func_0207f9f4(void*);
void DispatchEntryOp0x8_0208108c(void*, int);
extern "C" void SpriteContext_LoadFile(void*, void*, int, SafeAllocator*);
Glob02174a80* GetGlobalField0x1c020421a0(void);
extern "C" void func_ov003_02176798(void*);

extern const char* g_itemDataArchive;
extern const char* g_itemDataFile;
extern char data_ov003_0217fab4[];
extern char data_ov003_02180af4[];
extern char data_ov003_02180b10[];
extern char data_ov003_02180b2c[];
extern const unsigned char data_ov003_0217fa94[];
extern const unsigned char data_ov003_0217fa90[];
extern char data_ov003_02180b3f[];
extern char data_ov003_02180b55[];
extern char data_ov003_02180b6f[];
extern char data_ov003_02180b77[];
extern char data_ov003_02180b8d[];

// USA: func_ov003_02174a80
extern "C" ARM void func_ov003_02174a80(Struct_ov003_02174a80_5* arg0) {
    Struct_ov003_02174a80_7* var0;
    BackgroundLoader* var1;
    Struct_ov003_02174a80_2* var2;
    int var3;
    var1 = BackgroundLoader::GetInstance();

    if (arg0->unknown_103f_ == 0) {
        var1->AddFence();
#if defined(jpn)
        self->taskId = loader->QueueLoadGP1(g_itemDataArchive, 0);
#else
        self->taskId = loader->QueueLoadFileInGP2(g_itemDataArchive, g_itemDataFile, 0);
#endif
        self->state++;
    } else if (self->state == 1) {
        if (loader->GetTaskStatus(self->taskId)) {
            void* file;
            unsigned int size;
            loader->GetLoadedFileByID(self->taskId, &file, &size);
            SafeAllocator* alloc = &self->alloc->a[0];
            alloc->Reset();
            ItemTable_Init((char*)self + kSelfField874);
            func_020dea64((char*)self + kSelfField874, alloc, file, size, data_ov003_0217fab4, 9);
            loader->RemoveTask(self->taskId);
            self->taskId = -1;
            self->state++;
        }
    }

    if (arg0->unknown_103f_ == 2) {
        arg0->unknown_fec_ = var1->QueueLoadFile(data_ov003_02180af4, 0);
        arg0->unknown_103f_++;
    } else if (arg0->unknown_103f_ == 3) {
        if (var1->GetTaskStatus(arg0->unknown_fec_)) {
            void* var7;
            unsigned int var8;
            Struct_ov003_02174a80_6 var9;
            char var10[0x40];
            char var11[0x20];
            Struct_ov003_02174a80_7* var12;
            var1->GetLoadedFileByID(arg0->unknown_fec_, &var7, &var8);
            var12 = arg0->unknown_4_;
            var12->unknown_0_[1].Reset();
            func_02072488((Struct_02072488*)&var9);
            func_0207249c((int)&var9, (int)&var12->unknown_0_[1], (Struct_02013fb4*)((int)var7), var8);
            arg0->unknown_1034_ = func_0206f7f4((Struct_0206f7f4*)func_0206f504(), 0);
            Struct_ov003_02174a80_4* var13 = func_020725d8((Struct_020725d8*)&var9, arg0->unknown_1034_);
            func_ov003_02174408((Struct_ov003_02174114_4*)&arg0->unknown_834_);
            arg0->unknown_834_ = 0x63;
            arg0->unknown_835_ = 5;
            arg0->unknown_848_[0] = 0x3386;
            arg0->unknown_848_[1] = 0x2fa5;
            arg0->unknown_848_[2] = 0x43f2;
            arg0->unknown_848_[3] = 0x4e36;
            arg0->unknown_848_[4] = 0x4e36 + 0x490;
            if (var13 != 0) {
                short var14 = 0;
                short var15 = 0;
                for (; var15 < 0x12; var15++) {
                    arg0->unknown_848_[var15] = var13->unknown_4_[var15];
                    arg0->unknown_836_[var15] = 0;
                    if (arg0->unknown_848_[var15] <= 0) {
                        arg0->unknown_848_[var15] = -1;
                    } else {
                        var14++;
                    }
                }
                arg0->unknown_834_ = 0x63;
                arg0->unknown_835_ = var14;
                arg0->unknown_86e_ = var13->unknown_2_;
                arg0->unknown_86c_ = var13->unknown_28_;
                arg0->unknown_870_ = var13->unknown_2a_;
            }
            var1->RemoveTask(arg0->unknown_fec_);
            arg0->unknown_fec_ = -1;
            arg0->unknown_103f_++;
            var12 = arg0->unknown_4_;
            var12->unknown_0_[1].Reset();
#if defined(jpn)
            func_020dfc84((char*)arg0 + 0xc, &var12->unknown_0_[1], data_ov003_0217ed74, 0, (short)(arg0->unknown_86e_ - 1), -1);
#else
            sprintf(var10, data_ov003_02180b10, arg0->unknown_86e_ - 1);
            sprintf(var11, data_ov003_02180b2c, arg0->unknown_86e_ - 1);
            func_020dfc84((char*)arg0 + 0xc, &var12->unknown_0_[1], var10, var11, 0, -1);
#endif
        }
    } else if (arg0->unknown_103f_ == 4) {
        if (func_020dfd40((char*)arg0 + 0xc, 0, 0)) {
            arg0->unknown_103f_++;
        }
    }

    if (self->state == 5) {
        allocs = self->alloc;
        allocs->a[4].Reset();
        for (i = 0; i < 2; i++) {
            e = &self->ents[i];
            Background_SetMapSize((unsigned char*)e, 0);
            e->lo = 0;
            e->hi = data_ov003_0217fa94[i];
            Background_SetPriority(e, data_ov003_0217fa90[i]);
            Background_AllocateMap((AllocTarget0204b12c*)e, &allocs->a[4]);
            Background_SetScroll((Obj0204b5e8*)e, 0, 0);
        }
        MapVRAMBanksToMainBG(0x10);
        BG1CNT = (BG1CNT & 0x43) | 0x1d00;
        BG2CNT = (BG2CNT & 0x43) | 0x1e00;
        BG3CNT = (BG3CNT & 0x43) | 0x308 | 0x1c00;
        ColorEffect_ConfigureAlphaBlend(0x4000050, 2, 1, 10, 6);
        self->taskId = loader->QueueLoadFile(data_ov003_02180b3f, 0);
        self->state++;
    } else if (self->state == 6) {
        if (loader->GetTaskStatus(self->taskId)) {
            int tmp;
            void* file;
            unsigned int size;
            void* recs[12];
            int outs[12];
            loader->GetLoadedFileByID(self->taskId, &file, &size);
            int n = Pac_CountFiles((ActiveEntry02046900*)file);
            for (i = 0; i < n; i++) {
                recs[i] = Pac_GetFile((Rec020467f0*)file, i, (void**)&tmp, &outs[i]);
            }
            allocs = self->alloc;
            for (i = 0; i < n; i++) {
                if (recs[i] != 0) {
                    Background_LoadFile(&self->ents[1], recs[i], &allocs->a[4], outs[i]);
                }
            }
            loader->RemoveTask(self->taskId);
            self->taskId = -1;
            e = &self->ents[1];
            e->h4 = 3;
            for (i = 0; i < 2; i++) {
                e = &self->ents[i];
                Background_FillRect(e, 0, 0, 0, 0x20, 0x19, 0);
                Background_UploadMap((List0204b0e8*)e, 0);
            }
            self->buf = allocs->a[4].Allocate(0x5000);
            for (i = 0; i < 8; i++) {
                Obj02174a80* o = &self->objs[i];
                WindowPane_AllocateBuffer((Obj0204c7a8*)o, &allocs->a[4], (int)self->buf, 0x4cc);
                o->f4 = &self->ents[1];
            }
            arg0->unknown_103f_++;
        }
    }

    if (arg0->unknown_103f_ == 7) {
        Struct_ov003_02174a80_7* var23 = arg0->unknown_4_;
        var23->unknown_0_[5].Reset();
#if defined(jpn)
        func_02080654(arg0->unknown_89c_, &var23->unknown_0_[5], data_ov003_0217eda8);
#else
        func_0207f914((Struct_0207f914*)arg0->unknown_89c_, (int)&var23->unknown_0_[5], (int)data_ov003_02180b55, (int)data_ov003_02180b6f);
#endif
        arg0->unknown_103f_++;
    } else if (arg0->unknown_103f_ == 8) {
        int var24 = func_0207f9f4(arg0->unknown_89c_);
        if (var24 == 0) {
            arg0->unknown_103f_++;
        }
        if (var24 < 0) {
            arg0->unknown_103e_ = 9;
        }
    }

    if (arg0->unknown_103f_ == 9) {
        void* var25 = arg0->unknown_89c_;
        func_0208108c(var25, 0x21);
        func_0208108c(var25, 0x2c);
        func_0208108c(var25, 0x3c);
        func_0208108c(var25, 0x51);
#if !defined(jpn)
        func_0208108c(var25, 0x52);
        func_0208108c(var25, 0x55);
#endif
        func_0208108c(var25, 0x5c);
        func_0208108c(var25, 0x5f);
        func_0208108c(var25, 0x63);
        func_0208108c(var25, 0x70);
        func_0208108c(var25, 0x71);
        func_0208108c(var25, 0x75);
        func_0208108c(var25, 0xd2);
        BG0CNT = (BG0CNT & ~3) | 3;
        BG1CNT = (BG1CNT & ~3) | 2;
        BG2CNT = (BG2CNT & ~3) | 1;
        BG3CNT = (BG3CNT & ~3) | 0;
        MapVRAMBanksToMainObj(0x20);
        DISPCNT = (DISPCNT & 0xffcfffef) | 0x10;
        DISPCNT = (DISPCNT & ~0x1f00) | 0x1700;
#if defined(jpn)
        arg0->unknown_fec_ = var1->QueueLoadFile(data_ov003_0217edc6, 0);
#else
        arg0->unknown_fec_ = var1->QueueLoadFileInGP2(data_ov003_02180b77, data_ov003_02180b8d, 0);
#endif
        self->state++;
    } else if (self->state == 10) {
        if (loader->GetTaskStatus(self->taskId)) {
            int tmp;
            void* file;
            unsigned int size;
            int out;
            loader->GetLoadedFileByID(self->taskId, &file, &size);
            int n = Pac_CountFiles((ActiveEntry02046900*)file);
            allocs = self->alloc;
            allocs->a[3].Reset();
            for (i = 0; i < n; i++) {
                void* rec = Pac_GetFile((Rec020467f0*)file, i, (void**)&tmp, &out);
                SpriteContext_LoadFile((char*)self + kSelfField7D8, rec, out, &allocs->a[3]);
            }
            var1->RemoveTask(arg0->unknown_fec_);
            arg0->unknown_fec_ = -1;
            Struct_ov003_02174a80* var32 = func_020421a0();
            var32->unknown_2d8_ = (char*)arg0 + Enum_ov003_02174a80_2008;
            var32->unknown_2dc_ = arg0->unknown_830_;
            if (arg0->unknown_0_ != 0) {
                var32->unknown_2e0_ = arg0->unknown_0_->unknown_20_;
            }
            var32->unknown_2e4_ = 0;
            var32->unknown_2e6_ = 0;
            arg0->unknown_103f_++;
        }
    }

    if (arg0->unknown_103f_ == 11) {
        if (func_020421a0()->unknown_9a0_ == 3) {
            arg0->unknown_1046_ |= 0x40;
            arg0->unknown_1041_ = 0;
            func_ov003_02176798(arg0);
            arg0->unknown_103e_ = 1;
            arg0->unknown_103f_ = 0;
        }
    }
}
