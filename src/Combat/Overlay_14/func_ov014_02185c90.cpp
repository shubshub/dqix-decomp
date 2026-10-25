#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

#if defined(jpn)
#define func_ov014_02185c90 func_ov014_02186d00
#endif

struct Struct_ov003_0215d4fc {
    char unknown_0_[0x16];
    unsigned char unknown_16_;
};
struct Struct_ov014_02185c90_2 {
    unsigned int unknown_0_0_ : 10;
    unsigned int unknown_1_2_ : 1;
    unsigned int unknown_1_3_ : 7;
    unsigned int unknown_2_2_ : 7;
};
struct Struct_ov014_02185c90_4 {
    char unknown_0_[8];
    int unknown_8_;
    short unknown_c_;
    char unknown_e_[4];
    signed char unknown_12_;
    char unknown_13_[7];
    short unknown_1a_;
};
struct Struct_ov014_02185c90_5 {
    unsigned short unknown_0_;
    unsigned short unknown_2_0_ : 12;
    unsigned short unknown_3_4_ : 4;
};
struct Struct_ov000_021700dc {
    unsigned short unknown_0_;
    unsigned short unknown_2_0_ : 1;
};
struct Struct_ov014_02185c90_6 {
    char unknown_0_[0x1c];
    unsigned char unknown_1c_0_ : 4;
    unsigned char unknown_1c_4_ : 4;
    char unknown_1d_[3];
};
struct Struct_ov014_02185c90_7 {
    int unknown_0_;
    void* unknown_4_;
    char unknown_8_[10];
    short unknown_12_;
};
struct Struct_ov014_02185c90_8 {
    int unknown_0_;
    short unknown_4_;
    unsigned short unknown_6_;
};
struct Struct_ov000_0217c638_2 {
    void** unknown_0_;
    char unknown_4_[0x18];
    char unknown_1c_[0x2c];
    struct Struct_ov014_02185c90_4* unknown_48_;
    char unknown_4c_[4];
    struct Struct_ov014_02185c90_2* unknown_50_;
    char unknown_54_[4];
    struct Struct_ov014_02185c90_7* unknown_58_;
    void* unknown_5c_;
    const char* unknown_60_;
    const char* unknown_64_;
    void* unknown_68_;
    char unknown_6c_[4];
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
    struct Struct_ov014_02185c90_8 unknown_9c_;
};
struct Struct_ov014_02185c90 {
    char unknown_0_[8];
    void* unknown_8_;
    char unknown_c_[0x9c];
    short unknown_a8_;
    short unknown_aa_;
    char unknown_ac_[8];
    short unknown_b4_;
    short unknown_b6_;
    char unknown_b8_[0x28];
};

struct PacRecord;
int Pac_CountFiles(PacRecord*);
void* Pac_GetFile(PacRecord*, int, void**, int*);
extern "C" void WindowPane_Init(void*);
struct BinarySearch020971a8Container;
int BinarySearchByField4_02097224(BinarySearch020971a8Container*, int);
extern "C" void __clear(void*, int);
void CopyTextAndUppercaseIfFlagged0206819c(const char*, char*, int);
void* MessageSystem_GetInstance();
extern "C" void MessageSystem_FormatText(void*, int, char*, char*, int, int, int);
void SetPackedFields_021e24b0(void*, int, int, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);
void SetEntryFields_021e23d0(void*, int, int, unsigned char, unsigned char);
struct Container020e0310;
void* KeyTable_Get(Container020e0310*, int);
extern "C" struct Ent* func_ov014_021842a0(void*, short);
struct IndexedArrayStruct021893c4;
void* FindOrGetDefaultElement_021893c4(IndexedArrayStruct021893c4*, int);
extern "C" struct Slot* func_ov014_0218940c(void*, int, void*);
extern "C" int* func_ov014_02189430(void*, int, void*);
extern "C" void func_ov023_021e257c(void*);
struct BackgroundGraphics;
void Background_Init(BackgroundGraphics*);
void Background_SetMapSize(unsigned char*, int);
extern "C" void Background_SetPriority(void*, int);
void Background_SetScroll(BackgroundGraphics*, int, int);
extern "C" void func_0204b4c0(void*, void*);
void Background_FlushFile(void*, char*);
void Background_UploadFile(BackgroundGraphics*, char*);

#define FLAGOP(e, id, stmt) do { struct Struct_ov003_0215d4fc* p = func_ov014_021842a0(e, id); if (p) { stmt; } } while (0)
#define SetBit4(e, id) FLAGOP(e, id, p->unknown_16_ |= 0x10)
#define SetBit0(e, id) FLAGOP(e, id, p->unknown_16_ |= 1)
#define ClrBit0(e, id) FLAGOP(e, id, p->unknown_16_ &= ~1)

// USA: func_ov014_02185c90
extern "C" ARM void func_ov014_02185c90(struct Panel* self) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if ((self->b81 & 1) && self->b7f == 5 && loader->GetTaskStatus(self->s8c)) {
        void* rp;
        void* file;
        unsigned int size;
        int rs;
        struct Draw draw;
        char buf358[0x48];
        char buf310[0x48];
        char buf110[0x200];
        char bufc8[0x48];
        char buf80[0x48];
        struct ListObj list;
        int count;
        loader->GetLoadedFileByID(self->s8c, &file, &size);
        count = Pac_CountFiles((PacRecord*)file);
        if (count != 0) {
            char* rec = (char*)Pac_GetFile((PacRecord*)file, 0, &rp, &rs);
            if (rec != 0) {
                WindowPane_Init(&draw);
                draw.s28 = 0x20;
                draw.s2a = 0x18;
                draw.s34 = 0xa;
                draw.s36 = 0xb;
                draw.p8 = rec + 0x10;
                BinarySearchByField4_02097224((BinarySearch020971a8Container*)((char*)self + 0xc), self->rec->fc);
                __clear(buf358, 0x48);
                __clear(buf310, 0x48);
                __clear(buf110, 0x200);
                __clear(bufc8, 0x48);
                __clear(buf80, 0x48);
                CopyTextAndUppercaseIfFlagged0206819c(self->text60, buf358, 0);
                CopyTextAndUppercaseIfFlagged0206819c(self->text64, buf310, 0);
                char* n1 = bufc8;
                char* n2 = buf80;
                char* n3 = buf110;
                void* g = MessageSystem_GetInstance();
                MessageSystem_FormatText(g, 0xa, buf358, n1, 0x400, 0, 0);
                MessageSystem_FormatText(g, 0xa, buf310, n2, 0x400, 0, 0);
                MessageSystem_FormatText(g, 0xa, (char*)self->p68, n3, 0x8c, 0, 0);
                void* ents;
                void* cont;
                struct Pk* pk;
                struct Rec* r;
                unsigned char b80 = self->b80;
                ents = self->ents;
                pk = self->pk;
                cont = self->cont;
                r = self->rec;
                if (ents && r && cont && pk && pk->lo) {
                    SetPackedFields_021e24b0(ents, 2, r->f1a, 8, 0xf, 1, 3, 0, 1);
                    SetEntryFields_021e23d0(ents, 3, (int)r->f8, 0xa, 0xf);
                    SetEntryFields_021e23d0(ents, 4, (int)(KeyTable_Get((Container020e0310*)cont, r->f12)), 0xa, 0xf);
                    SetBit4(ents, 4);
                    if (&self->blk && self->blk.cnt > 0) {
                        SetPackedFields_021e24b0(ents, 5, self->blk.a, 8, 0xf, 1, 6, 0, 0);
                        SetPackedFields_021e24b0(ents, 6, self->blk.b, 8, 0xf, 1, 6, 0, 0);
                    }
                    SetPackedFields_021e24b0(ents, 7, pk->lo, 8, 0xf, 1, 6, 0, 0);
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
                            SetEntryFields_021e23d0(ents, 8, (int)n1, 0xa, 0xf);
                            SetPackedFields_021e24b0(ents, 0xa, pk->c, 8, 0xf, 1, 3, 0, 0);
                            SetEntryFields_021e23d0(ents, 0xc, (int)(KeyTable_Get((Container020e0310*)cont, 0xf)), 0xa, 0xf);
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
                            SetEntryFields_021e23d0(ents, a, (int)n2, 0xa, 0xf);
                            SetPackedFields_021e24b0(ents, b, pk->d, 8, 0xf, 1, 3, 0, 0);
                            SetEntryFields_021e23d0(ents, c, (int)(KeyTable_Get((Container020e0310*)cont, 0xf)), 0xa, 0xf);
                        }
                    }
                    if (ok == 0) {
                        SetBit0(ents, 0x16);
                        SetEntryFields_021e23d0(ents, 0x16, (int)(KeyTable_Get((Container020e0310*)cont, 0xe)), 0xa, 0xf);
                    }
                    SetEntryFields_021e23d0(ents, 0x13, (int)n3, 0xa, 0xf);
                    if (pk->b10) {
                        ClrBit0(ents, 0x14);
                        SetBit0(ents, 0x17);
                        SetEntryFields_021e23d0(ents, 0x17, (int)(KeyTable_Get((Container020e0310*)cont, 0x1c)), 8, 0xf);
                        SetBit0(ents, 0x18);
                        SetPackedFields_021e24b0(ents, 0x18, b80 + 1, 8, 0xf, 0, 1, 0, 0);
                        SetBit0(ents, 0x19);
                        SetPackedFields_021e24b0(ents, 0x19, 2, 8, 0xf, 0, 1, 0, 0);
                    }
                    ClrBit0(var18, 0xe);
                    ClrBit0(var18, 0xf);
                    ClrBit0(var18, 0x10);
                    int var27;
                    short var28;
                    struct Struct_ov014_02185c90_5* var29 = (struct Struct_ov014_02185c90_5*)func_ov014_021893c4((Struct_ov014_02185c90_3*)arg0->unknown_1c_, -1);
                    if (var29) {
                        var28 = 0xe;
                        for (var27 = 0; var27 < 2; var27++) {
                            if (var27 < var29->unknown_3_4_) {
                                SetBit0(var18, var28);
                                struct Struct_ov000_021700dc* var30 = func_ov014_0218940c(arg0->unknown_1c_, var27, var29);
                                int* var31 = func_ov014_02189430(arg0->unknown_1c_, var27, var29);
                                if (var30->unknown_2_0_) {
                                    func_ov023_021e23d0(var18, var28, (int)((void*)*var31), 0xa, 0xf);
                                } else {
                                    SetEntryFields_021e23d0(ents, id, (int)(KeyTable_Get((Container020e0310*)cont, 0x15)), 0xa, 0xf);
                                }
                                var28++;
                            }
                        }
                        if (arr->n >= 3) {
                            if (func_ov014_0218940c(self->arr, 2, arr)->bit0) {
                                SetBit0(ents, 0x10);
                                SetEntryFields_021e23d0(ents, 0x10, (int)(KeyTable_Get((Container020e0310*)cont, 0x10)), 0xa, 0xf);
                            }
                        }
                    }
                }
                struct EntObj* e = self->ents;
                e->p4 = &draw;
                e->s12 = 1;
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
                arg0->unknown_81_ &= ~0x20;
            }
        }
        var0->RemoveTask(arg0->unknown_8c_);
        arg0->unknown_8c_ = -1;
        arg0->unknown_7f_++;
    }
    if ((self->b81 & 0x10) && self->b7e == 1 && loader->GetTaskStatus(self->id70)) {
        void* rp;
        void* file;
        unsigned int size;
        int rs;
        struct ListObj list;
        loader->GetLoadedFileByID(self->id70, &file, &size);
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
        var0->RemoveTask(arg0->unknown_70_);
        arg0->unknown_70_ = -1;
        arg0->unknown_7e_ = 0;
        arg0->unknown_81_ &= ~0x10;
        arg0->unknown_94_ = arg0->unknown_93_;
        arg0->unknown_93_ = 0;
    }
}
