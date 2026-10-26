#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/ColorEffects.h"
#include "NitroSDK/Graphics.h"
#include "std_library_functions.h"

#if defined(jpn)
enum { Enum_ov003_02174a80_2096 = 0x7ac, kSelfField874 = 0x7f0, kSelfField7D8 = 0x754, Enum_ov003_02174a80_728 = 0x228, Enum_ov003_02174a80_1721 = 0x870 - 0x237 };
extern const char* g_itemDataArchive;
extern const char data_ov003_0217ed74[];
extern const char data_ov003_0217eda8[];
extern const char data_ov003_0217edc6[];
extern "C" void func_02080654(void*, SafeAllocator*, const char*);
extern "C" void func_020dfc84(void*, SafeAllocator*, const char*, int, int, int);
#else
enum { Enum_ov003_02174a80_2096 = 0x830, kSelfField874 = 0x874, kSelfField7D8 = 0x7d8, Enum_ov003_02174a80_728 = 0x2d8, Enum_ov003_02174a80_1721 = 0x9a0 - 0x2e7 };
#endif

struct Struct_ov003_02174a80_6 {
    int a;
    int b;
};

struct Struct_ov003_02174a80_7 {
    SafeAllocator a[6];
};

struct Struct_ov003_02174a80_8 {
    char pad[0x20];
    int unknown_20_;
};

struct Glob02174a80 {
    char pad[Enum_ov003_02174a80_728];
    void* p2d8;
    int unknown_2dc_;
    int unknown_2e0_;
    unsigned short unknown_2e4_;
    unsigned char unknown_2e6_;
    char pad2[Enum_ov003_02174a80_1721];
    int w9a0;
};

struct Struct_ov003_02174a80_2 {
    char pad0[4];
    short h4;
    char pad6[0x16];
    unsigned char lo : 4;
    unsigned char hi : 4;
    char unknown_1d_[3];
};

struct Struct_ov003_02174a80_3 {
    char pad0[4];
    void* f4;
    char pad8[0xe0 - 8];
};

struct Struct_ov003_02174a80_4 {
    char pad0[2];
    short h2;
    short unknown_4_[0x12];
    unsigned short unknown_28_;
    unsigned char unknown_2a_;
};

struct Struct_ov003_02174a80_5 {
    Struct_ov003_02174a80_8* p0;
    Struct_ov003_02174a80_7* alloc;
    char pad8[4];
    char body[Enum_ov003_02174a80_2096 - 0xc];
    int unknown_830_;
    unsigned char unknown_834_;
    unsigned char unknown_835_;
    unsigned char ids[0x12];
    short unknown_848_[0x12];
    unsigned short unknown_86c_;
    short unknown_86e_;
    unsigned char unknown_870_;
    char unknown_871_[0x89c - 0x871];
    void* unknown_89c_;
    Struct_ov003_02174a80_2 ents[2];
    Struct_ov003_02174a80_3 objs[8];
    char unknown_fe0_[0xc];
    int taskId;
    int unknown_ff0_;
    void* buf;
    char unknown_ff8_[0x1034 - 0xff8];
    short unknown_1034_;
    char unknown_1036_[0x103e - 0x1036];
    unsigned char unknown_103e_;
    unsigned char state;
    char unknown_1040_;
    unsigned char unknown_1041_;
    char unknown_1042_[4];
    unsigned short unknown_1046_;
};

extern "C" void ItemTable_Init(void*);
extern "C" void func_020dea64(void*, SafeAllocator*, void*, unsigned int, const char*, int);
struct Struct_02072488;
extern "C" void func_02072488(Struct_02072488*);
struct StreamHeader;
extern "C" void func_0207249c(int, int, StreamHeader*, int);
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
extern "C" void Background_SetMapSize(unsigned char*, int);
extern "C" void Background_SetPriority(void*, int);
struct BackgroundGraphics;
extern "C" void Background_AllocateMap(BackgroundGraphics*, SafeAllocator*);
extern "C" void Background_SetScroll(BackgroundGraphics*, int, int);
extern "C" void MapVRAMBanksToMainBG(int);
extern "C" void MapVRAMBanksToMainObj(int);
struct PacRecord;
extern "C" int Pac_CountFiles(PacRecord*);
extern "C" void* Pac_GetFile(PacRecord*, int, void**, int*);
extern "C" void Background_LoadFile(void*, void*, SafeAllocator*, int);
extern "C" void Background_FillRect(void*, int, int, int, int, int, int);
extern "C" void Background_UploadMap(BackgroundGraphics*, void*);
struct WindowPane;
extern "C" void WindowPane_AllocateBuffer(WindowPane*, SafeAllocator*, int, unsigned int);
struct Struct_0207f914;
extern "C" void func_0207f914(Struct_0207f914*, int, int, int);
extern "C" int func_0207f9f4(void*);
extern "C" void func_0208108c(void*, int);
extern "C" void SpriteContext_LoadFile(void*, void*, int, SafeAllocator*);
extern "C" Glob02174a80* MessageSystem_GetInstance(void);
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
extern "C" ARM void func_ov003_02174a80(Struct_ov003_02174a80_5* self) {
    Struct_ov003_02174a80_7* allocs;
    BackgroundLoader* loader;
    Struct_ov003_02174a80_2* e;
    int i;
    loader = BackgroundLoader::GetInstance();

    if (self->state == 0) {
        loader->AddFence();
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

    if (self->state == 2) {
        self->taskId = loader->QueueLoadFile(data_ov003_02180af4, 0);
        self->state++;
    } else if (self->state == 3) {
        if (loader->GetTaskStatus(self->taskId)) {
            void* file;
            unsigned int size;
            Struct_ov003_02174a80_6 hdr;
            char buf1[0x40];
            char buf2[0x20];
            Struct_ov003_02174a80_7* var12;
            loader->GetLoadedFileByID(self->taskId, &file, &size);
            var12 = self->alloc;
            var12->a[1].Reset();
            func_02072488((Struct_02072488*)&hdr);
            func_0207249c((int)&hdr, (int)&var12->a[1], (StreamHeader*)((int)file), size);
            self->unknown_1034_ = func_0206f7f4((Struct_0206f7f4*)func_0206f504(), 0);
            Struct_ov003_02174a80_4* rec = func_020725d8((Struct_020725d8*)&hdr, self->unknown_1034_);
            func_ov003_02174408((Struct_ov003_02174114_4*)&self->unknown_834_);
            self->unknown_834_ = 0x63;
            self->unknown_835_ = 5;
            self->unknown_848_[0] = 0x3386;
            self->unknown_848_[1] = 0x2fa5;
            self->unknown_848_[2] = 0x43f2;
            self->unknown_848_[3] = 0x4e36;
            self->unknown_848_[4] = 0x4e36 + 0x490;
            if (rec != 0) {
                short count = 0;
                short i = 0;
                for (; i < 0x12; i++) {
                    self->unknown_848_[i] = rec->unknown_4_[i];
                    self->ids[i] = 0;
                    if (self->unknown_848_[i] <= 0) {
                        self->unknown_848_[i] = -1;
                    } else {
                        count++;
                    }
                }
                self->unknown_834_ = 0x63;
                self->unknown_835_ = count;
                self->unknown_86e_ = rec->h2;
                self->unknown_86c_ = rec->unknown_28_;
                self->unknown_870_ = rec->unknown_2a_;
            }
            loader->RemoveTask(self->taskId);
            self->taskId = -1;
            self->state++;
            var12 = self->alloc;
            var12->a[1].Reset();
#if defined(jpn)
            func_020dfc84((char*)self + 0xc, &var12->a[1], data_ov003_0217ed74, 0, (short)(self->unknown_86e_ - 1), -1);
#else
            sprintf(buf1, data_ov003_02180b10, self->unknown_86e_ - 1);
            sprintf(buf2, data_ov003_02180b2c, self->unknown_86e_ - 1);
            func_020dfc84((char*)self + 0xc, &var12->a[1], buf1, buf2, 0, -1);
#endif
        }
    } else if (self->state == 4) {
        if (func_020dfd40((char*)self + 0xc, 0, 0)) {
            self->state++;
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
            Background_AllocateMap((BackgroundGraphics*)e, &allocs->a[4]);
            Background_SetScroll((BackgroundGraphics*)e, 0, 0);
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
            int n = Pac_CountFiles((PacRecord*)file);
            for (i = 0; i < n; i++) {
                recs[i] = Pac_GetFile((PacRecord*)file, i, (void**)&tmp, &outs[i]);
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
                Background_UploadMap((BackgroundGraphics*)e, 0);
            }
            self->buf = allocs->a[4].Allocate(0x5000);
            for (i = 0; i < 8; i++) {
                Struct_ov003_02174a80_3* o = &self->objs[i];
                WindowPane_AllocateBuffer((WindowPane*)o, &allocs->a[4], (int)self->buf, 0x4cc);
                o->f4 = &self->ents[1];
            }
            self->state++;
        }
    }

    if (self->state == 7) {
        Struct_ov003_02174a80_7* var23 = self->alloc;
        var23->a[5].Reset();
#if defined(jpn)
        func_02080654(self->unknown_89c_, &var23->a[5], data_ov003_0217eda8);
#else
        func_0207f914((Struct_0207f914*)self->unknown_89c_, (int)&var23->a[5], (int)data_ov003_02180b55, (int)data_ov003_02180b6f);
#endif
        self->state++;
    } else if (self->state == 8) {
        int r = func_0207f9f4(self->unknown_89c_);
        if (r == 0) {
            self->state++;
        }
        if (r < 0) {
            self->unknown_103e_ = 9;
        }
    }

    if (self->state == 9) {
        void* p = self->unknown_89c_;
        func_0208108c(p, 0x21);
        func_0208108c(p, 0x2c);
        func_0208108c(p, 0x3c);
        func_0208108c(p, 0x51);
#if !defined(jpn)
        func_0208108c(p, 0x52);
        func_0208108c(p, 0x55);
#endif
        func_0208108c(p, 0x5c);
        func_0208108c(p, 0x5f);
        func_0208108c(p, 0x63);
        func_0208108c(p, 0x70);
        func_0208108c(p, 0x71);
        func_0208108c(p, 0x75);
        func_0208108c(p, 0xd2);
        BG0CNT = (BG0CNT & ~3) | 3;
        BG1CNT = (BG1CNT & ~3) | 2;
        BG2CNT = (BG2CNT & ~3) | 1;
        BG3CNT = (BG3CNT & ~3) | 0;
        MapVRAMBanksToMainObj(0x20);
        DISPCNT = (DISPCNT & 0xffcfffef) | 0x10;
        DISPCNT = (DISPCNT & ~0x1f00) | 0x1700;
#if defined(jpn)
        self->taskId = loader->QueueLoadFile(data_ov003_0217edc6, 0);
#else
        self->taskId = loader->QueueLoadFileInGP2(data_ov003_02180b77, data_ov003_02180b8d, 0);
#endif
        self->state++;
    } else if (self->state == 10) {
        if (loader->GetTaskStatus(self->taskId)) {
            int tmp;
            void* file;
            unsigned int size;
            int out;
            loader->GetLoadedFileByID(self->taskId, &file, &size);
            int n = Pac_CountFiles((PacRecord*)file);
            allocs = self->alloc;
            allocs->a[3].Reset();
            for (i = 0; i < n; i++) {
                void* rec = Pac_GetFile((PacRecord*)file, i, (void**)&tmp, &out);
                SpriteContext_LoadFile((char*)self + kSelfField7D8, rec, out, &allocs->a[3]);
            }
            loader->RemoveTask(self->taskId);
            self->taskId = -1;
            Glob02174a80* g = MessageSystem_GetInstance();
            g->p2d8 = (char*)self + kSelfField7D8;
            g->unknown_2dc_ = self->unknown_830_;
            if (self->p0 != 0) {
                g->unknown_2e0_ = self->p0->unknown_20_;
            }
            g->unknown_2e4_ = 0;
            g->unknown_2e6_ = 0;
            self->state++;
        }
    }

    if (self->state == 11) {
        if (MessageSystem_GetInstance()->w9a0 == 3) {
            self->unknown_1046_ |= 0x40;
            self->unknown_1041_ = 0;
            func_ov003_02176798(self);
            self->unknown_103e_ = 1;
            self->state = 0;
        }
    }
}
