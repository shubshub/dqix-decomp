#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

#if defined(jpn)
#define func_ov014_02185c90 func_ov014_02186d00
#endif

struct Struct_ov003_0215d4fc {
    char pad[0x16];
    unsigned char unknown_16_;
};
struct Struct_ov014_02185c90_2 {
    unsigned int lo : 10;
    unsigned int b10 : 1;
    unsigned int c : 7;
    unsigned int d : 7;
};
struct Struct_ov014_02185c90_4 {
    char pad0[8];
    int f8;
    short fc;
    char pad1[4];
    signed char f12;
    char pad2[7];
    short unknown_1a_;
};
struct Struct_ov014_02185c90_5 {
    unsigned short a;
    unsigned short pad : 12;
    unsigned short n : 4;
};
struct Slot {
    unsigned short off;
    unsigned short bit0 : 1;
};
struct Struct_ov014_02185c90_6 {
    char pad[0x1c];
    unsigned char lo : 4;
    unsigned char hi : 4;
    char pad2[3];
};
struct Struct_ov014_02185c90_7 {
    int pad0;
    void* p4;
    char pad8[10];
    short unknown_12_;
};
struct Struct_ov014_02185c90_8 {
    int a;
    short cnt;
    unsigned short b;
};
struct Struct_ov000_0217c638_2 {
    void** bufs;
    char pad4[0x18];
    char arr[0x2c];
    struct Struct_ov014_02185c90_4* rec;
    char unknown_4c_[4];
    struct Struct_ov014_02185c90_2* pk;
    char unknown_54_[4];
    struct Struct_ov014_02185c90_7* ents;
    void* cont;
    const char* unknown_60_;
    const char* unknown_64_;
    void* p68;
    char pad6c[4];
    int unknown_70_;
    char unknown_74_[10];
    unsigned char unknown_7e_;
    unsigned char unknown_7f_;
    unsigned char unknown_80_;
    unsigned char unknown_81_;
    char unknown_82_[10];
    short unknown_8c_;
    char unknown_8e_[5];
    unsigned char unknown_93_;
    unsigned char unknown_94_;
    char unknown_95_[7];
    struct Struct_ov014_02185c90_8 blk;
};
struct Struct_ov014_02185c90 {
    char pad0[8];
    void* p8;
    char pad1[0x9c];
    short unknown_a8_;
    short unknown_aa_;
    char pad2[8];
    short unknown_b4_;
    short unknown_b6_;
    char pad3[0x28];
};

struct PacRecord;
extern "C" int Pac_CountFiles(PacRecord*);
extern "C" void* Pac_GetFile(PacRecord*, int, void**, int*);
extern "C" void WindowPane_Init(void*);
struct Struct_02097054_5;
extern "C" int func_02097224(Struct_02097054_5*, int);
extern "C" void __clear(void*, int);
extern "C" void func_0206819c(const char*, char*, int);
extern "C" void* MessageSystem_GetInstance();
extern "C" void MessageSystem_FormatText(void*, int, char*, char*, int, int, int);
extern "C" void func_ov023_021e24b0(void*, int, int, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);
extern "C" void func_ov023_021e23d0(void*, int, int, unsigned char, unsigned char);
struct Container020e0310;
extern "C" void* KeyTable_Get(Container020e0310*, int);
extern "C" struct Struct_ov003_0215d4fc* func_ov014_021842a0(void*, short);
struct Struct_ov014_02185c90_3;
extern "C" void* func_ov014_021893c4(Struct_ov014_02185c90_3*, int);
extern "C" struct Slot* func_ov014_0218940c(void*, int, void*);
extern "C" int* func_ov014_02189430(void*, int, void*);
extern "C" void func_ov023_021e257c(void*);
struct BackgroundGraphics;
extern "C" void Background_Init(BackgroundGraphics*);
extern "C" void Background_SetMapSize(unsigned char*, int);
extern "C" void Background_SetPriority(void*, int);
extern "C" void Background_SetScroll(BackgroundGraphics*, int, int);
extern "C" void func_0204b4c0(void*, void*);
extern "C" void Background_FlushFile(void*, char*);
extern "C" void Background_UploadFile(BackgroundGraphics*, char*);

#define FLAGOP(e, id, stmt) do { struct Struct_ov003_0215d4fc* p = func_ov014_021842a0(e, id); if (p) { stmt; } } while (0)
#define SetBit4(e, id) FLAGOP(e, id, p->unknown_16_ |= 0x10)
#define SetBit0(e, id) FLAGOP(e, id, p->unknown_16_ |= 1)
#define ClrBit0(e, id) FLAGOP(e, id, p->unknown_16_ &= ~1)

// USA: func_ov014_02185c90
extern "C" ARM void func_ov014_02185c90(struct Struct_ov000_0217c638_2* self) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if ((self->unknown_81_ & 1) && self->unknown_7f_ == 5 && loader->GetTaskStatus(self->unknown_8c_)) {
        void* rp;
        void* file;
        unsigned int size;
        int rs;
        struct Struct_ov014_02185c90 draw;
        char buf358[0x48];
        char buf310[0x48];
        char var8[0x200];
        char var9[0x48];
        char buf80[0x48];
        struct Struct_ov014_02185c90_6 list;
        int count;
        loader->GetLoadedFileByID(self->unknown_8c_, &file, &size);
        count = Pac_CountFiles((PacRecord*)file);
        if (count != 0) {
            char* rec = (char*)Pac_GetFile((PacRecord*)file, 0, &rp, &rs);
            if (rec != 0) {
                WindowPane_Init(&draw);
                draw.unknown_a8_ = 0x20;
                draw.unknown_aa_ = 0x18;
                draw.unknown_b4_ = 0xa;
                draw.unknown_b6_ = 0xb;
                draw.p8 = rec + 0x10;
                func_02097224((Struct_02097054_5*)((char*)self + 0xc), self->rec->fc);
                __clear(buf358, 0x48);
                __clear(buf310, 0x48);
                __clear(var8, 0x200);
                __clear(var9, 0x48);
                __clear(buf80, 0x48);
                func_0206819c(self->unknown_60_, buf358, 0);
                func_0206819c(self->unknown_64_, buf310, 0);
                char* n1 = var9;
                char* n2 = buf80;
                char* n3 = var8;
                void* g = MessageSystem_GetInstance();
                MessageSystem_FormatText(g, 0xa, buf358, n1, 0x400, 0, 0);
                MessageSystem_FormatText(g, 0xa, buf310, n2, 0x400, 0, 0);
                MessageSystem_FormatText(g, 0xa, (char*)self->p68, n3, 0x8c, 0, 0);
                void* ents;
                void* cont;
                struct Struct_ov014_02185c90_2* pk;
                struct Struct_ov014_02185c90_4* r;
                unsigned char var22 = self->unknown_80_;
                ents = self->ents;
                pk = self->pk;
                cont = self->cont;
                r = self->rec;
                if (ents && r && cont && pk && pk->lo) {
                    func_ov023_021e24b0(ents, 2, r->unknown_1a_, 8, 0xf, 1, 3, 0, 1);
                    func_ov023_021e23d0(ents, 3, (int)r->f8, 0xa, 0xf);
                    func_ov023_021e23d0(ents, 4, (int)(KeyTable_Get((Container020e0310*)cont, r->f12)), 0xa, 0xf);
                    SetBit4(ents, 4);
                    if (&self->blk && self->blk.cnt > 0) {
                        func_ov023_021e24b0(ents, 5, self->blk.a, 8, 0xf, 1, 6, 0, 0);
                        func_ov023_021e24b0(ents, 6, self->blk.b, 8, 0xf, 1, 6, 0, 0);
                    }
                    func_ov023_021e24b0(ents, 7, pk->lo, 8, 0xf, 1, 6, 0, 0);
                    ClrBit0(ents, 8);
                    ClrBit0(ents, 0xa);
                    ClrBit0(ents, 0xc);
                    ClrBit0(ents, 9);
                    ClrBit0(ents, 0xb);
                    ClrBit0(ents, 0xd);
                    ClrBit0(ents, 0x16);
                    ClrBit0(ents, 0x14);
                    ClrBit0(ents, 0x1a);
                    ClrBit0(ents, 0x1b);
                    ClrBit0(ents, 0x17);
                    ClrBit0(ents, 0x18);
                    ClrBit0(ents, 0x19);
                    SetBit0(ents, 0x15);
                    short c;
                    short b;
                    short a;
                    int ok;
                    ok = 0;
                    a = 8;
                    b = 0xa;
                    c = 0xc;
                    if (pk->b10 || pk->lo) {
                        ok = 1;
                        if (n1[0] != 0) {
                            SetBit0(ents, 8);
                            SetBit0(ents, 0xa);
                            SetBit0(ents, 0xc);
                            func_ov023_021e23d0(ents, 8, (int)n1, 0xa, 0xf);
                            func_ov023_021e24b0(ents, 0xa, pk->c, 8, 0xf, 1, 3, 0, 0);
                            func_ov023_021e23d0(ents, 0xc, (int)(KeyTable_Get((Container020e0310*)cont, 0xf)), 0xa, 0xf);
                            a = 9;
                            b = 0xb;
                            c = 0xd;
                        }
                    }
                    if (pk->d || pk->b10) {
                        if (n2[0] != 0) {
                            ok = 1;
                            SetBit0(ents, a);
                            SetBit0(ents, b);
                            SetBit0(ents, c);
                            func_ov023_021e23d0(ents, a, (int)n2, 0xa, 0xf);
                            func_ov023_021e24b0(ents, b, pk->d, 8, 0xf, 1, 3, 0, 0);
                            func_ov023_021e23d0(ents, c, (int)(KeyTable_Get((Container020e0310*)cont, 0xf)), 0xa, 0xf);
                        }
                    }
                    if (ok == 0) {
                        SetBit0(ents, 0x16);
                        func_ov023_021e23d0(ents, 0x16, (int)(KeyTable_Get((Container020e0310*)cont, 0xe)), 0xa, 0xf);
                    }
                    func_ov023_021e23d0(ents, 0x13, (int)n3, 0xa, 0xf);
                    if (pk->b10) {
                        ClrBit0(ents, 0x14);
                        SetBit0(ents, 0x17);
                        func_ov023_021e23d0(ents, 0x17, (int)(KeyTable_Get((Container020e0310*)cont, 0x1c)), 8, 0xf);
                        SetBit0(ents, 0x18);
                        func_ov023_021e24b0(ents, 0x18, var22 + 1, 8, 0xf, 0, 1, 0, 0);
                        SetBit0(ents, 0x19);
                        func_ov023_021e24b0(ents, 0x19, 2, 8, 0xf, 0, 1, 0, 0);
                    }
                    ClrBit0(ents, 0xe);
                    ClrBit0(ents, 0xf);
                    ClrBit0(ents, 0x10);
                    int i;
                    short id;
                    struct Struct_ov014_02185c90_5* arr = (struct Struct_ov014_02185c90_5*)func_ov014_021893c4((Struct_ov014_02185c90_3*)self->arr, -1);
                    if (arr) {
                        id = 0xe;
                        for (i = 0; i < 2; i++) {
                            if (i < arr->n) {
                                SetBit0(ents, id);
                                struct Slot* s = func_ov014_0218940c(self->arr, i, arr);
                                int* v = func_ov014_02189430(self->arr, i, arr);
                                if (s->bit0) {
                                    func_ov023_021e23d0(ents, id, (int)((void*)*v), 0xa, 0xf);
                                } else {
                                    func_ov023_021e23d0(ents, id, (int)(KeyTable_Get((Container020e0310*)cont, 0x15)), 0xa, 0xf);
                                }
                                id++;
                            }
                        }
                        if (arr->n >= 3) {
                            if (func_ov014_0218940c(self->arr, 2, arr)->bit0) {
                                SetBit0(ents, 0x10);
                                func_ov023_021e23d0(ents, 0x10, (int)(KeyTable_Get((Container020e0310*)cont, 0x10)), 0xa, 0xf);
                            }
                        }
                    }
                }
                struct Struct_ov014_02185c90_7* e = self->ents;
                e->p4 = &draw;
                e->unknown_12_ = 1;
                func_ov023_021e257c(self->ents);
                Background_Init((BackgroundGraphics*)&list);
                Background_SetMapSize((unsigned char*)&list, 0);
                list.lo = 0;
                list.hi = 1;
                Background_SetPriority(&list, 1);
                Background_SetScroll((BackgroundGraphics*)&list, 0, 0);
                for (int i = 0; i < count; i++) {
                    void* r2 = Pac_GetFile((PacRecord*)file, i, &rp, &rs);
                    if (r2) {
                        memcpy(self->bufs[i], r2, rs);
                        func_0204b4c0(&list, self->bufs[i]);
                    }
                }
                self->unknown_81_ &= ~0x20;
            }
        }
        loader->RemoveTask(self->unknown_8c_);
        self->unknown_8c_ = -1;
        self->unknown_7f_++;
    }
    if ((self->unknown_81_ & 0x10) && self->unknown_7e_ == 1 && loader->GetTaskStatus(self->unknown_70_)) {
        void* rp;
        void* file;
        unsigned int size;
        int rs;
        struct Struct_ov014_02185c90_6 list;
        loader->GetLoadedFileByID(self->unknown_70_, &file, &size);
        int count = Pac_CountFiles((PacRecord*)file);
        Background_Init((BackgroundGraphics*)&list);
        Background_SetMapSize((unsigned char*)&list, 0);
        list.lo = 0;
        list.hi = 1;
        Background_SetPriority(&list, 1);
        Background_SetScroll((BackgroundGraphics*)&list, 0, 0);
        for (int i = 0; i < count; i++) {
            void* rec = Pac_GetFile((PacRecord*)file, i, &rp, &rs);
            if (rec) {
                Background_FlushFile(&list, (char*)rec);
                Background_UploadFile((BackgroundGraphics*)&list, (char*)rec);
            }
        }
        loader->RemoveTask(self->unknown_70_);
        self->unknown_70_ = -1;
        self->unknown_7e_ = 0;
        self->unknown_81_ &= ~0x10;
        self->unknown_94_ = self->unknown_93_;
        self->unknown_93_ = 0;
    }
}
