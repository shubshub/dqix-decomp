#include "Combat/MenuNodeChain.h"
#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"

#if defined(jpn)
#define REGIONAL_OFFSET(jp, us) jp
#define REGION_LOAD(gp2, inner, jp) QueueLoadFile(jp, (SafeAllocator*)0)
#define data_ov006_021602bb data_ov006_02161600
extern char data_ov006_021615ce[];
extern char data_ov006_021615e8[];
extern char data_ov006_02161617[];
extern char data_ov006_0216162c[];
extern char data_ov006_02161641[];
extern char data_ov006_02161657[];
struct Struct_0207f914;
extern "C" void func_02080654(Struct_0207f914*, int, int);
#else
#define REGIONAL_OFFSET(jp, us) us
#define REGION_LOAD(gp2, inner, jp) QueueLoadFileInGP2(gp2, inner, (SafeAllocator*)0)
#endif

extern int data_02109bf4;
extern char data_ov006_0216026c[];
extern char data_ov006_02160286[];
extern char data_ov006_02160297[];
extern char data_ov006_021602ab[];
extern char data_ov006_021602bb[];
extern char data_ov006_021602d2[];
extern char data_ov006_021602e7[];
extern char data_ov006_021602f8[];
extern char data_ov006_0216030a[];
extern char data_ov006_02160318[];
extern char data_ov006_0216032e[];
extern char data_ov006_02160340[];
extern char data_ov006_02160359[];

struct Actor0209c3b4;
int SetStateAndDispatch0209c3b4(Actor0209c3b4*, int);
void SetFogState_020c54a4(int, unsigned int, unsigned int, unsigned short);
void Set3DClearColor_020c5588(int, int, int, int, int);
struct Struct020dfc40;
void KeyTable_Reset(Struct020dfc40*);
extern "C" void KeyTable_Load(void*, void*, void*, unsigned int);
struct Struct02071be8;
void ClearListHeader(Struct02071be8*);
struct StreamHeader;
void RunBufferedStream02071c00(int, int, StreamHeader*, int);
extern "C" void* GetSubBG0ScreenBase();
extern "C" void* memset(void*, int, unsigned int);
struct List0204af64;
void Background_Init(List0204af64*);
void Background_SetMapSize(unsigned char*, int);
extern "C" void Background_SetPriority(void*, int);
struct Obj0204b5e8;
void Background_SetScroll(Obj0204b5e8*, int, int);
struct AllocTarget0204b12c;
void Background_AllocateMap(AllocTarget0204b12c*, SafeAllocator*);
struct Foo0204af38;
struct SafeAllocator;
void Background_AllocateScreens(Foo0204af38*, int, SafeAllocator*);
struct ActiveEntry02046900;
int Pac_CountFiles(ActiveEntry02046900*);
struct Rec020467f0;
void* Pac_GetFile(Rec020467f0*, int, void**, int*);
extern "C" void Background_LoadFile(void*, void*, void*, unsigned int);
struct List0204b0e8;
void Background_UploadMap(List0204b0e8*, void*);
extern "C" void func_0204c684(void*);
struct Obj0204c7a8;
void WindowPane_AllocateBuffer(Obj0204c7a8*, SafeAllocator*, int, unsigned int);
void ClearFields_021e20c0(void*);
extern "C" void func_ov023_021e20f0(void*, void*, void*, unsigned int);
extern "C" void* func_ov006_02157368(void*, int);
extern "C" void SpriteContext_LoadFile(void*, void*, void*, void*);
void SpriteContext_Init(char*);
void Zero4Bytes_020e526c(void*);
extern "C" void func_020e5604(void*, void*, void*, unsigned int);
struct Struct_0207f914;
extern "C" void func_0207f914(Struct_0207f914*, int, int, int);
extern "C" int func_0207f9f4(void*);
extern "C" void func_020810a0(void*, int);
struct Struct_0207f7f0;
struct Struct_0207f7f0_2;
extern "C" void func_0207f7f0(Struct_0207f7f0*, Struct_0207f7f0_2*, int);
extern "C" void func_0208108c(void*, int);
extern "C" void ColorEffect_ConfigureAlphaBlend(unsigned int*, int, int, int, int);
extern "C" void func_ov006_02158de0(void*);
extern "C" void func_ov006_02153744(void*, void*, void*, int);
struct Struct_02071ffc_4;
extern "C" void func_02071ffc(Struct_02071ffc_4*, int, int, int, short, short*);
extern "C" void func_ov006_02158cac(void*);
extern "C" void func_ov006_02153c60(void*, int, unsigned short);
extern "C" void func_ov006_0215373c(void*, void*);
struct Struct_02081164;
extern "C" void func_02081164(Struct_02081164*, int, int);
extern "C" void func_020813ec(void*, int);
struct Struct_0207fdcc_2;
extern "C" void* func_02081da8(Struct_0207fdcc_2*, int);
extern "C" void __clear(void*, int);
void* GetGlobalField0x1c020421a0();
struct Container020e0310;
void* KeyTable_Get(Container020e0310*, int);
extern "C" void func_02046608(void*, int, void*, void*, int, int, int);
struct Struct_02080f8c;
extern "C" void func_02080f8c(Struct_02080f8c*, int, int);

struct Struct_ov006_02158478 {
    unsigned char unknown_0_[0xb8];
    unsigned short unknown_b8_;
    unsigned short unknown_ba_;
};

struct Struct_ov006_0215a5fc {
    unsigned char unknown_0_0_ : 4;
    unsigned char unknown_0_4_ : 4;
};

struct Struct_ov003_02154af4_3 {
#if !defined(jpn)
    unsigned char unknown_0_[0x08];
#endif
    void* unknown_8_;
    void* unknown_c_;
    unsigned char unknown_10_[0x04];
    Struct_0207f7f0* unknown_14_;
    void* unknown_18_;
    Struct_02020cb8* unknown_1c_;
    Struct_0207f7f0_2* unknown_20_;
    void* unknown_24_;
    unsigned char unknown_28_[0x04];
    int unknown_2c_;
    int unknown_30_;
    unsigned char unknown_34_[0x04];
    int unknown_38_;
    unsigned char unknown_3c_[0x54 - 0x3c];
    unsigned char unknown_54_[0x1c];
    unsigned char unknown_70_;
    unsigned char unknown_71_[0x74 - 0x71];
    unsigned char unknown_74_[0xac - 0x74];
    unsigned char unknown_ac_[0xe8 - 0xac];
    int unknown_e8_;
    int unknown_ec_;
    unsigned char unknown_f0_[0xf8 - 0xf0];
    unsigned short unknown_f8_;
    unsigned char unknown_fa_[0xfc - 0xfa];
    unsigned char unknown_fc_;
    unsigned char unknown_fd_[0x100 - 0xfd];
    unsigned char unknown_100_[REGIONAL_OFFSET(0x48, 0x14c - 0x100)];
    int unknown_14c_;
    unsigned char unknown_150_[0x158 - 0x150];
    unsigned char unknown_158_[0x170 - 0x158];
    unsigned char unknown_170_[REGIONAL_OFFSET(0x300 - 0x164, 0x300 - 0x170)];
    unsigned char unknown_300_[0x54];
    int unknown_354_;
    unsigned char unknown_358_[0x35c - 0x358];
    short* unknown_35c_;
    unsigned char unknown_360_[0x384 - 0x360];
    signed char unknown_384_;
    signed char unknown_385_;
    unsigned char unknown_386_;
    unsigned char unknown_387_[0x38f - 0x387];
    unsigned char unknown_38f_;
    unsigned char unknown_390_;
    unsigned char unknown_391_[0x394 - 0x391];
    unsigned short unknown_394_;
};

struct Struct_ov006_0215a5fc_2 {
    short unknown_0_;
    unsigned char unknown_2_[2];
    unsigned int unknown_4_;
    void* unknown_8_;
    int unknown_c_;
    unsigned int unknown_10_;
    void* unknown_14_;
    void* unknown_18_;
    unsigned int unknown_1c_;
    void* unknown_20_;
    int unknown_24_;
    unsigned int unknown_28_;
    void* unknown_2c_;
    void* unknown_30_;
    unsigned int unknown_34_;
    void* unknown_38_;
    unsigned int unknown_3c_;
    void* unknown_40_;
#if !defined(jpn)
    unsigned char unknown_44_[0x400];
#endif
};

// USA: func_ov006_0215a5fc
extern "C" ARM void func_ov006_0215a5fc(Scene* obj) {
    Frame f;
    GameState::GetInstance()->GetResources();
    void* loader = BackgroundLoader::GetInstance();
    unsigned char st = obj->f390;

    if (var2 == 0) {
        if ((arg0->unknown_394_ & 2) == 0) {
            func_0209c3b4((Struct_0209c3b4_2*)&data_02109bf4, 8);
        }
        func_020c54a4(0, 0, 0, 0);
        func_020c5588(0, 0, 0x7fff, 0, 0);
        Struct_0208cb08* var3 = func_02094a00();
        func_02094b40(var3);
        func_02094b34(var3, 0x6c, 0x1fd, 0, 0);
        arg0->unknown_390_ = arg0->unknown_390_ + 1;
    }
    else if (var2 == 1) {
        if (func_02094b4c(func_02094a00()) != 0) {
            arg0->unknown_390_ = arg0->unknown_390_ + 1;
        }
    }
    else if (var2 == 2) {
        arg0->unknown_354_ = ((BackgroundLoader*)var1)->REGION_LOAD(data_ov006_0216026c, data_ov006_02160286, data_ov006_021615ce);
        arg0->unknown_390_ = arg0->unknown_390_ + 1;
    }
    else if (st == 3) {
        if (((BackgroundLoader*)loader)->GetTaskStatus(obj->f354) != 0) {
            ((BackgroundLoader*)loader)->GetLoadedFileByID(obj->f354, &f.c3d, &f.c3s);
            if (f.c3d != 0) {
                void* alloc = obj->alloc;
                ((SafeAllocator*)((char*)alloc + 0x14))->Reset();
                KeyTable_Reset((Struct020dfc40*)((char*)obj + REGIONAL_OFFSET(0x14c, 0x158)));
                KeyTable_Load((char*)obj + REGIONAL_OFFSET(0x14c, 0x158), (char*)alloc + 0x14, f.c3d, f.c3s);
            }
            ((BackgroundLoader*)var1)->RemoveTask(arg0->unknown_354_);
            arg0->unknown_354_ = -1;
            arg0->unknown_390_ = arg0->unknown_390_ + 1;
        }
    }
    else if (var2 == 4) {
        arg0->unknown_354_ = ((BackgroundLoader*)var1)->REGION_LOAD(data_ov006_02160297, data_ov006_021602ab, data_ov006_021615e8);
        arg0->unknown_390_ = arg0->unknown_390_ + 1;
    }
    else if (var2 == 5) {
        if (((BackgroundLoader*)var1)->GetTaskStatus(arg0->unknown_354_) != 0) {
            ((BackgroundLoader*)var1)->GetLoadedFileByID(arg0->unknown_354_, &var0.unknown_38_, &var0.unknown_34_);
            if (var0.unknown_38_ != 0) {
                void* var5 = arg0->unknown_c_;
                ((SafeAllocator*)var5)->Reset();
                func_02071be8((Struct_02071be8*)((char*)arg0 + REGIONAL_OFFSET(0x140, 0x14c)));
                func_02071c00((int)((char*)arg0 + REGIONAL_OFFSET(0x140, 0x14c)), (unsigned int)var5, (Struct_02013fb4*)var0.unknown_38_, (int)var0.unknown_34_);
            }
            ((BackgroundLoader*)var1)->RemoveTask(arg0->unknown_354_);
            arg0->unknown_354_ = -1;
            arg0->unknown_390_ = arg0->unknown_390_ + 1;
        }
    }
    else if (var2 == 6) {
        volatile unsigned short* var6 = (volatile unsigned short*)0x04001008;
        var6[0] = (var6[0] & 0x43) | 0x10 | 0x1000;
        var6[1] = (var6[1] & 0x43) | 0x1010 + 0x100;
        var6[2] = (var6[2] & 0x43) | 0x1010 + 0x200;
        *(volatile unsigned short*)0x0400100e = (*(volatile unsigned short*)0x0400100e & 0x43) | 0x1300;
        memset(GetSubBG0ScreenBase(), 0, 0x800);
        *(volatile unsigned int*)0x04001010 = 0;
        ((SafeAllocator*)((char*)obj->alloc + 0x3c))->Reset();
        Background_Init((List0204af64*)((char*)obj + REGIONAL_OFFSET(0x4c, 0x54)));
        Background_SetMapSize((unsigned char*)((char*)obj + REGIONAL_OFFSET(0x4c, 0x54)), 0);
        obj->f70 = (unsigned char)((obj->f70 & ~0xf) | 1);
        obj->f70 = (unsigned char)((obj->f70 & ~0xf0) | 0x30);
        Background_SetPriority((char*)obj + REGIONAL_OFFSET(0x4c, 0x54), 3);
        Background_SetScroll((Obj0204b5e8*)((char*)obj + REGIONAL_OFFSET(0x4c, 0x54)), 0, 0);
        Background_AllocateMap((AllocTarget0204b12c*)((char*)obj + REGIONAL_OFFSET(0x4c, 0x54)), (SafeAllocator*)((char*)obj->alloc + 0x3c));
        Background_AllocateScreens((Foo0204af38*)((char*)obj + REGIONAL_OFFSET(0x4c, 0x54)), REGIONAL_OFFSET(3, 7), (SafeAllocator*)((char*)obj->alloc + 0x3c));
        obj->f354 = ((BackgroundLoader*)loader)->QueueLoadFile(data_ov006_021602bb, (SafeAllocator*)0);
        obj->f390 = obj->f390 + 1;
    }
    else if (st == 7) {
        if (((BackgroundLoader*)loader)->GetTaskStatus(obj->f354) != 0) {
            ((BackgroundLoader*)loader)->GetLoadedFileByID(obj->f354, &f.c7d, &f.c7s);
            void* rec;
            int n = Pac_CountFiles((ActiveEntry02046900*)f.c7d);
            int i;
            for (i = 0; i < n; i++) {
                rec = Pac_GetFile((Rec020467f0*)f.c7d, i, &f.r7d, &f.r7s);
                if (rec != 0) {
                if (i == 0) {
                    int j;
                    for (j = 0; j < 2; j++) {
                        unsigned char* o = (unsigned char*)obj->f1c + (j << 5);
                        Background_Init((List0204af64*)o);
                        Background_SetMapSize((unsigned char*)o, 0);
                        Nib* nib = (Nib*)(o + 0x1c);
                        nib->lo = 1;
                        nib->hi = (unsigned char)(j + 1);
                        Background_SetScroll((Obj0204b5e8*)o, 0, 0);
                        Background_SetPriority(o, j + 1);
                        Background_AllocateMap((AllocTarget0204b12c*)o, (SafeAllocator*)((char*)obj->alloc + 0x3c));
                        Background_LoadFile(o, rec, (char*)obj->alloc + 0x3c, f.r7s);
                    }
                }
                else {
                    Background_LoadFile((char*)obj + REGIONAL_OFFSET(0x4c, 0x54), rec, (char*)obj->alloc + 0x3c, f.r7s);
                }
                }
            }
            Background_UploadMap((List0204b0e8*)((char*)obj + REGIONAL_OFFSET(0x4c, 0x54)), 0);
            ((BackgroundLoader*)loader)->RemoveTask(obj->f354);
            obj->f354 = -1;
            obj->f390 = obj->f390 + 1;
        }
    }
    else if (st == 8) {
        void* alloc = obj->alloc;
        ((SafeAllocator*)((char*)alloc + 0x50))->Reset();
        unsigned int i;
        for (i = 0; i < 7; i = (i + 1) & 0xff) {
            void* o = (char*)obj->f20 + i * 0xe0;
            func_0204c684(o);
            WindowPane_AllocateBuffer((Obj0204c7a8*)o, (SafeAllocator*)((char*)alloc + 0x50), (int)obj->f08, 0x600);
            *(unsigned int*)((char*)o + 4) = (unsigned int)obj->f1c;
        }
        arg0->unknown_354_ = ((BackgroundLoader*)var1)->REGION_LOAD(data_ov006_021602d2, data_ov006_021602e7, data_ov006_02161617);
        arg0->unknown_390_ = arg0->unknown_390_ + 1;
    }
    else if (var2 == 9) {
        if (((BackgroundLoader*)var1)->GetTaskStatus(arg0->unknown_354_) != 0) {
            ((BackgroundLoader*)var1)->GetLoadedFileByID(arg0->unknown_354_, &var0.unknown_20_, &var0.unknown_1c_);
            if (var0.unknown_20_ != 0) {
                void* var16 = arg0->unknown_c_;
                ((SafeAllocator*)((char*)var16 + 0x78))->Reset();
                func_ov023_021e20c0((char*)arg0 + REGIONAL_OFFSET(0xf8, 0x100));
                func_ov023_021e20f0((char*)arg0 + REGIONAL_OFFSET(0xf8, 0x100), (char*)var16 + 0x78, var0.unknown_20_, var0.unknown_1c_);
                unsigned char* var17 = (unsigned char*)func_ov006_02157368((char*)arg0 + REGIONAL_OFFSET(0xf8, 0x100), 1);
                if (var17 != 0) {
                    var17[0x16] = (unsigned char)(var17[0x16] & ~1);
                }
                var17 = (unsigned char*)func_ov006_02157368((char*)arg0 + REGIONAL_OFFSET(0xf8, 0x100), 0x23);
                if (var17 != 0) {
                    var17[0x16] = (unsigned char)(var17[0x16] & ~1);
                }
                var17 = (unsigned char*)func_ov006_02157368((char*)arg0 + REGIONAL_OFFSET(0xf8, 0x100), 0x24);
                if (var17 != 0) {
                    var17[0x16] = (unsigned char)(var17[0x16] & ~1);
                }
            }
            ((BackgroundLoader*)var1)->RemoveTask(arg0->unknown_354_);
            arg0->unknown_354_ = -1;
            arg0->unknown_390_ = arg0->unknown_390_ + 1;
        }
    }
    else if (st == 0xa) {
        SpriteContext_Init((char*)((char*)obj + REGIONAL_OFFSET(0xa4, 0xac)));
        obj->ffc = 1;
        obj->fec = (int)obj->f24;
        obj->ff8 = 0x1d;
        obj->fe8 = *(int*)((char*)obj->f18 + 0x20);
        obj->f354 = ((BackgroundLoader*)loader)->REGION_LOAD(data_ov006_021602f8, data_ov006_0216030a, data_ov006_0216162c);
        obj->f390 = obj->f390 + 1;
    }
    else if (st == 0xb) {
        if (((BackgroundLoader*)loader)->GetTaskStatus(obj->f354) != 0) {
            ((BackgroundLoader*)loader)->GetLoadedFileByID(obj->f354, &f.cbd, &f.cbs);
            void* alloc;
            int n = Pac_CountFiles((ActiveEntry02046900*)f.cbd);
            alloc = obj->alloc;
            ((SafeAllocator*)((char*)alloc + 0x8c))->Reset();
            int i;
            for (i = 0; i < n; i++) {
                void* rec = Pac_GetFile((Rec020467f0*)f.cbd, i, &f.rbd, &f.rbs);
                if (rec != 0) {
                SpriteContext_LoadFile((char*)obj + REGIONAL_OFFSET(0xa4, 0xac), rec, (void*)f.rbs, (char*)alloc + 0x8c);
                }
            }
            ((BackgroundLoader*)var1)->RemoveTask(arg0->unknown_354_);
            arg0->unknown_354_ = -1;
            arg0->unknown_390_ = arg0->unknown_390_ + 1;
            int var22;
            for (var22 = 0; var22 < 8; var22++) {
                *((unsigned char*)arg0->unknown_24_ + (var22 + 0x12) * 0x28 + 0x22) = 0x18;
            }
        }
    }
    else if (var2 == 0xc) {
        arg0->unknown_354_ = ((BackgroundLoader*)var1)->REGION_LOAD(data_ov006_02160318, data_ov006_0216032e, data_ov006_02161641);
        arg0->unknown_390_ = arg0->unknown_390_ + 1;
    }
    else if (var2 == 0xd) {
        if (((BackgroundLoader*)var1)->GetTaskStatus(arg0->unknown_354_) != 0) {
            ((BackgroundLoader*)var1)->GetLoadedFileByID(arg0->unknown_354_, &var0.unknown_8_, &var0.unknown_4_);
            if (var0.unknown_8_ != 0) {
                void* var23 = arg0->unknown_c_;
                ((SafeAllocator*)((char*)var23 + 0x28))->Reset();
#if defined(jpn)
                KeyTable_Reset((Struct020dfc40*)((char*)obj + REGIONAL_OFFSET(0x164, 0x170)));
                KeyTable_Load((char*)obj + REGIONAL_OFFSET(0x164, 0x170), (char*)alloc + 0x28, f.cd, f.cs);
#else
                func_020e526c((char*)arg0 + REGIONAL_OFFSET(0x164, 0x170));
                func_020e5604((char*)arg0 + REGIONAL_OFFSET(0x164, 0x170), (char*)var23 + 0x28, var0.unknown_8_, var0.unknown_4_);
#endif
            }
            ((BackgroundLoader*)var1)->RemoveTask(arg0->unknown_354_);
            arg0->unknown_354_ = -1;
            arg0->unknown_390_ = arg0->unknown_390_ + 1;
        }
    }
    else if (var2 == 0xe) {
        void* var24 = arg0->unknown_c_;
        ((SafeAllocator*)((char*)var24 + 0x64))->Reset();
        func_0207f84c(arg0->unknown_14_);
#if defined(jpn)
        func_02080654((Struct_0207f914*)arg0->unknown_14_, (unsigned int)var24 + 0x64, (int)data_ov006_02161657);
#else
        func_0207f914((Struct_0207f914*)arg0->unknown_14_, (unsigned int)var24 + 0x64, (int)data_ov006_02160340, (int)data_ov006_02160359);
#endif
        arg0->unknown_390_ = arg0->unknown_390_ + 1;
    }
    else if (var2 == 0xf) {
        int var25 = func_0207f9f4(arg0->unknown_14_);
        if (var25 == 0) {
            arg0->unknown_390_ = arg0->unknown_390_ + 1;
        }
        if (var25 < 0) {
            arg0->unknown_38f_ = 0xc;
        }
    }
    else if (var2 == 0x10) {
        func_020810a0(arg0->unknown_14_, 1);
        {
            Struct_0207f7f0* var26 = arg0->unknown_14_;
            var26->unknown_2c_ = arg0->unknown_1c_;
            var26->unknown_38_ = 2;
        }
        func_0207f7f0(arg0->unknown_14_, arg0->unknown_20_, 7);
        arg0->unknown_14_->unknown_3a_ = 1;
#if !defined(jpn)
        func_0208108c(arg0->unknown_14_, 0x20);
        func_0208108c(arg0->unknown_14_, 0x3e);
#endif
        volatile unsigned short* var27 = (volatile unsigned short*)0x04001008;
        var27[0] = var27[0] & ~3;
        var27[1] = (var27[1] & ~3) | 1;
        var27[2] = (var27[2] & ~3) | 2;
        var27[3] = (var27[3] & ~3) | 3;
        *(volatile unsigned int*)0x04001000 = (*(volatile unsigned int*)0x04001000 & ~0x1f00) | 0x1f00;
        ColorEffect_ConfigureAlphaBlend((unsigned int*)((char*)var27 + 0x48), 4, 0x18, 0xa, 6);
        func_ov006_02158de0(arg0);
        arg0->unknown_38f_ = 1;
        arg0->unknown_390_ = 0;
        func_ov006_02153744((char*)arg0 + REGIONAL_OFFSET(0x6c, 0x74), (char*)arg0 + REGIONAL_OFFSET(0x140, 0x14c), (void*)arg0->unknown_38_, 0x1d8 - 1);
        func_02071ffc((Struct_02071ffc_4*)((char*)arg0 + REGIONAL_OFFSET(0x140, 0x14c)), -1, -1, 0, 0, (short*)((char*)arg0 + 0x35c));
        var0.unknown_0_ = 0;
        func_02071ffc((Struct_02071ffc_4*)((char*)arg0 + REGIONAL_OFFSET(0x140, 0x14c)), arg0->unknown_384_, arg0->unknown_385_, arg0->unknown_386_, 0x10, &var0.unknown_0_);
        int var28 = arg0->unknown_14c_;
        arg0->unknown_2c_ = var28;
        arg0->unknown_30_ = var28;
        func_ov006_02158cac(arg0);
        func_ov006_02153c60((char*)arg0 + REGIONAL_OFFSET(0x6c, 0x74), arg0->unknown_38_, 0x1d7);
        func_ov006_0215373c((char*)arg0 + REGIONAL_OFFSET(0x6c, 0x74), (char*)arg0 + REGIONAL_OFFSET(0x140, 0x14c));
        if ((arg0->unknown_394_ & 2) == 0) {
            func_02081164((Struct_02081164*)arg0->unknown_14_, 0, 1);
            func_02081164((Struct_02081164*)arg0->unknown_14_, 1, 1);
            func_020813ec(arg0->unknown_14_, 0);
            func_020813ec(arg0->unknown_14_, 1);
            Struct_ov006_02158478* var29 = (Struct_ov006_02158478*)func_02081da8((Struct_0207fdcc_2*)arg0->unknown_14_, 1);
            if (var29 != 0) {
                var29->unknown_b8_ = 0xc;
                var29->unknown_ba_ = 0x10;
            }
#if defined(jpn)
            void* r = KeyTable_Get((Container020e0310*)((char*)obj + REGIONAL_OFFSET(0x14c, 0x158)), 0);
            SetEntryFirstField02080f8c((Container02080f8c*)obj->f14, 1, (int)r);
#else
            __clear(f.buf, 0x400);
            void* g = GetGlobalField0x1c020421a0();
            void* r = KeyTable_Get((Container020e0310*)((char*)obj + REGIONAL_OFFSET(0x14c, 0x158)), 0);
            func_02046608(g, 0xc, r, f.buf, 0xe3, 0, 1);
            SetEntryFirstField02080f8c((Container02080f8c*)obj->f14, 1, (int)f.buf);
#endif
            func_020813ec(arg0->unknown_14_, 1);
        }
    }
}
