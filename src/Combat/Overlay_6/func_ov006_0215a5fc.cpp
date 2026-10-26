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

extern int g_bgmPlayer;
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
extern "C" int func_0209c3b4(Actor0209c3b4*, int);
extern "C" void func_020c54a4(int, unsigned int, unsigned int, unsigned short);
extern "C" void Set3DClearColor(int, int, int, int, int);
struct Struct020dfc40;
extern "C" void KeyTable_Reset(Struct020dfc40*);
extern "C" void KeyTable_Load(void*, void*, void*, unsigned int);
struct Struct_02071be8;
extern "C" void func_02071be8(Struct_02071be8*);
struct StreamHeader;
extern "C" void func_02071c00(int, int, StreamHeader*, int);
extern "C" void* GetSubBG0ScreenBase();
extern "C" void* memset(void*, int, unsigned int);
struct BackgroundGraphics;
extern "C" void Background_Init(BackgroundGraphics*);
extern "C" void Background_SetMapSize(unsigned char*, int);
extern "C" void Background_SetPriority(void*, int);
extern "C" void Background_SetScroll(BackgroundGraphics*, int, int);
extern "C" void Background_AllocateMap(BackgroundGraphics*, SafeAllocator*);
struct SafeAllocator;
extern "C" void Background_AllocateScreens(BackgroundGraphics*, int, SafeAllocator*);
struct PacRecord;
extern "C" int Pac_CountFiles(PacRecord*);
extern "C" void* Pac_GetFile(PacRecord*, int, void**, int*);
extern "C" void Background_LoadFile(void*, void*, void*, unsigned int);
extern "C" void Background_UploadMap(BackgroundGraphics*, void*);
extern "C" void WindowPane_Init(void*);
struct WindowPane;
extern "C" void WindowPane_AllocateBuffer(WindowPane*, SafeAllocator*, int, unsigned int);
extern "C" void func_ov023_021e20c0(void*);
extern "C" void func_ov023_021e20f0(void*, void*, void*, unsigned int);
extern "C" void* func_ov006_02157368(void*, int);
extern "C" void SpriteContext_LoadFile(void*, void*, void*, void*);
extern "C" void SpriteContext_Init(char*);
extern "C" void func_020e526c(void*);
extern "C" void func_020e5604(void*, void*, void*, unsigned int);
struct Struct_0207f914;
extern "C" void func_0207f914(Struct_0207f914*, int, int, int);
extern "C" int func_0207f9f4(void*);
extern "C" void func_020810a0(void*, int);
struct Manager0207f7f0;
struct Node0207f7f0;
extern "C" void func_0207f7f0(Manager0207f7f0*, Node0207f7f0*, int);
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
extern "C" void* MessageSystem_GetInstance();
struct Container020e0310;
extern "C" void* KeyTable_Get(Container020e0310*, int);
extern "C" void MessageSystem_FormatText(void*, int, void*, void*, int, int, int);
struct Container02080f8c;
extern "C" void func_02080f8c(Container02080f8c*, int, int);

struct Canvas {
    unsigned char pad[0xb8];
    unsigned short fb8;
    unsigned short unknown_ba_;
};

struct Struct_ov006_0215a5fc {
    unsigned char lo : 4;
    unsigned char hi : 4;
};

struct Scene {
#if !defined(jpn)
    unsigned char unknown_0_[0x08];
#endif
    void* f08;
    void* alloc;
    unsigned char pad10[0x04];
    Manager0207f7f0* f14;
    void* f18;
    BackgroundGraphics* f1c;
    Node0207f7f0* f20;
    void* f24;
    unsigned char pad28[0x04];
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
    short sel;
    unsigned char pad0[2];
    unsigned int cs;
    void* cd;
    int rbs;
    unsigned int unknown_10_;
    void* cbd;
    void* rbd;
    unsigned int unknown_1c_;
    void* unknown_20_;
    int r7s;
    unsigned int unknown_28_;
    void* c7d;
    void* r7d;
    unsigned int unknown_34_;
    void* unknown_38_;
    unsigned int c3s;
    void* c3d;
#if !defined(jpn)
    unsigned char buf[0x400];
#endif
};

// USA: func_ov006_0215a5fc
extern "C" ARM void func_ov006_0215a5fc(Scene* obj) {
    Struct_ov006_0215a5fc_2 f;
    GameState::GetInstance()->GetResources();
    void* loader = BackgroundLoader::GetInstance();
    unsigned char st = obj->unknown_390_;

    if (st == 0) {
        if ((obj->unknown_394_ & 2) == 0) {
            func_0209c3b4((Actor0209c3b4*)&g_bgmPlayer, 8);
        }
        func_020c54a4(0, 0, 0, 0);
        Set3DClearColor(0, 0, 0x7fff, 0, 0);
        FontBankLoader* g = FontBankLoader_GetInstance();
        func_02094b40(g);
        func_02094b34(g, 0x6c, 0x1fd, 0, 0);
        obj->unknown_390_ = obj->unknown_390_ + 1;
    }
    else if (st == 1) {
        if (func_02094b4c(FontBankLoader_GetInstance()) != 0) {
            obj->unknown_390_ = obj->unknown_390_ + 1;
        }
    }
    else if (st == 2) {
        obj->unknown_354_ = ((BackgroundLoader*)loader)->REGION_LOAD(data_ov006_0216026c, data_ov006_02160286, data_ov006_021615ce);
        obj->unknown_390_ = obj->unknown_390_ + 1;
    }
    else if (st == 3) {
        if (((BackgroundLoader*)loader)->GetTaskStatus(obj->unknown_354_) != 0) {
            ((BackgroundLoader*)loader)->GetLoadedFileByID(obj->unknown_354_, &f.c3d, &f.c3s);
            if (f.c3d != 0) {
                void* alloc = obj->alloc;
                ((SafeAllocator*)((char*)alloc + 0x14))->Reset();
                KeyTable_Reset((Struct020dfc40*)((char*)obj + REGIONAL_OFFSET(0x14c, 0x158)));
                KeyTable_Load((char*)obj + REGIONAL_OFFSET(0x14c, 0x158), (char*)alloc + 0x14, f.c3d, f.c3s);
            }
            ((BackgroundLoader*)loader)->RemoveTask(obj->unknown_354_);
            obj->unknown_354_ = -1;
            obj->unknown_390_ = obj->unknown_390_ + 1;
        }
    }
    else if (st == 4) {
        obj->unknown_354_ = ((BackgroundLoader*)loader)->REGION_LOAD(data_ov006_02160297, data_ov006_021602ab, data_ov006_021615e8);
        obj->unknown_390_ = obj->unknown_390_ + 1;
    }
    else if (st == 5) {
        if (((BackgroundLoader*)loader)->GetTaskStatus(obj->unknown_354_) != 0) {
            ((BackgroundLoader*)loader)->GetLoadedFileByID(obj->unknown_354_, &f.unknown_38_, &f.unknown_34_);
            if (f.unknown_38_ != 0) {
                void* alloc = obj->alloc;
                ((SafeAllocator*)alloc)->Reset();
                func_02071be8((Struct_02071be8*)((char*)obj + REGIONAL_OFFSET(0x140, 0x14c)));
                func_02071c00((int)((char*)obj + REGIONAL_OFFSET(0x140, 0x14c)), (unsigned int)alloc, (StreamHeader*)f.unknown_38_, (int)f.unknown_34_);
            }
            ((BackgroundLoader*)loader)->RemoveTask(obj->unknown_354_);
            obj->unknown_354_ = -1;
            obj->unknown_390_ = obj->unknown_390_ + 1;
        }
    }
    else if (st == 6) {
        volatile unsigned short* bg = (volatile unsigned short*)0x04001008;
        bg[0] = (bg[0] & 0x43) | 0x10 | 0x1000;
        bg[1] = (bg[1] & 0x43) | 0x1010 + 0x100;
        bg[2] = (bg[2] & 0x43) | 0x1010 + 0x200;
        *(volatile unsigned short*)0x0400100e = (*(volatile unsigned short*)0x0400100e & 0x43) | 0x1300;
        memset(GetSubBG0ScreenBase(), 0, 0x800);
        *(volatile unsigned int*)0x04001010 = 0;
        ((SafeAllocator*)((char*)obj->alloc + 0x3c))->Reset();
        Background_Init((BackgroundGraphics*)((char*)obj + REGIONAL_OFFSET(0x4c, 0x54)));
        Background_SetMapSize((unsigned char*)((char*)obj + REGIONAL_OFFSET(0x4c, 0x54)), 0);
        obj->unknown_70_ = (unsigned char)((obj->unknown_70_ & ~0xf) | 1);
        obj->unknown_70_ = (unsigned char)((obj->unknown_70_ & ~0xf0) | 0x30);
        Background_SetPriority((char*)obj + REGIONAL_OFFSET(0x4c, 0x54), 3);
        Background_SetScroll((BackgroundGraphics*)((char*)obj + REGIONAL_OFFSET(0x4c, 0x54)), 0, 0);
        Background_AllocateMap((BackgroundGraphics*)((char*)obj + REGIONAL_OFFSET(0x4c, 0x54)), (SafeAllocator*)((char*)obj->alloc + 0x3c));
        Background_AllocateScreens((BackgroundGraphics*)((char*)obj + REGIONAL_OFFSET(0x4c, 0x54)), REGIONAL_OFFSET(3, 7), (SafeAllocator*)((char*)obj->alloc + 0x3c));
        obj->unknown_354_ = ((BackgroundLoader*)loader)->QueueLoadFile(data_ov006_021602bb, (SafeAllocator*)0);
        obj->unknown_390_ = obj->unknown_390_ + 1;
    }
    else if (st == 7) {
        if (((BackgroundLoader*)loader)->GetTaskStatus(obj->unknown_354_) != 0) {
            ((BackgroundLoader*)loader)->GetLoadedFileByID(obj->unknown_354_, &f.c7d, &f.unknown_28_);
            void* rec;
            int n = Pac_CountFiles((PacRecord*)f.c7d);
            int i;
            for (i = 0; i < n; i++) {
                rec = Pac_GetFile((PacRecord*)f.c7d, i, &f.r7d, &f.r7s);
                if (rec != 0) {
                if (i == 0) {
                    int j;
                    for (j = 0; j < 2; j++) {
                        unsigned char* o = (unsigned char*)obj->f1c + (j << 5);
                        Background_Init((BackgroundGraphics*)o);
                        Background_SetMapSize((unsigned char*)o, 0);
                        Struct_ov006_0215a5fc* var12 = (Struct_ov006_0215a5fc*)(o + 0x1c);
                        var12->lo = 1;
                        var12->hi = (unsigned char)(j + 1);
                        Background_SetScroll((BackgroundGraphics*)o, 0, 0);
                        Background_SetPriority(o, j + 1);
                        Background_AllocateMap((BackgroundGraphics*)o, (SafeAllocator*)((char*)obj->alloc + 0x3c));
                        Background_LoadFile(o, rec, (char*)obj->alloc + 0x3c, f.r7s);
                    }
                }
                else {
                    Background_LoadFile((char*)obj + REGIONAL_OFFSET(0x4c, 0x54), rec, (char*)obj->alloc + 0x3c, f.r7s);
                }
                }
            }
            Background_UploadMap((BackgroundGraphics*)((char*)obj + REGIONAL_OFFSET(0x4c, 0x54)), 0);
            ((BackgroundLoader*)loader)->RemoveTask(obj->unknown_354_);
            obj->unknown_354_ = -1;
            obj->unknown_390_ = obj->unknown_390_ + 1;
        }
    }
    else if (st == 8) {
        void* alloc = obj->alloc;
        ((SafeAllocator*)((char*)alloc + 0x50))->Reset();
        unsigned int i;
        for (i = 0; i < 7; i = (i + 1) & 0xff) {
            void* o = (char*)obj->f20 + i * 0xe0;
            WindowPane_Init(o);
            WindowPane_AllocateBuffer((WindowPane*)o, (SafeAllocator*)((char*)alloc + 0x50), (int)obj->f08, 0x600);
            *(unsigned int*)((char*)o + 4) = (unsigned int)obj->f1c;
        }
        obj->unknown_354_ = ((BackgroundLoader*)loader)->REGION_LOAD(data_ov006_021602d2, data_ov006_021602e7, data_ov006_02161617);
        obj->unknown_390_ = obj->unknown_390_ + 1;
    }
    else if (st == 9) {
        if (((BackgroundLoader*)loader)->GetTaskStatus(obj->unknown_354_) != 0) {
            ((BackgroundLoader*)loader)->GetLoadedFileByID(obj->unknown_354_, &f.unknown_20_, &f.unknown_1c_);
            if (f.unknown_20_ != 0) {
                void* alloc = obj->alloc;
                ((SafeAllocator*)((char*)alloc + 0x78))->Reset();
                func_ov023_021e20c0((char*)obj + REGIONAL_OFFSET(0xf8, 0x100));
                func_ov023_021e20f0((char*)obj + REGIONAL_OFFSET(0xf8, 0x100), (char*)alloc + 0x78, f.unknown_20_, f.unknown_1c_);
                unsigned char* e = (unsigned char*)func_ov006_02157368((char*)obj + REGIONAL_OFFSET(0xf8, 0x100), 1);
                if (e != 0) {
                    e[0x16] = (unsigned char)(e[0x16] & ~1);
                }
                e = (unsigned char*)func_ov006_02157368((char*)obj + REGIONAL_OFFSET(0xf8, 0x100), 0x23);
                if (e != 0) {
                    e[0x16] = (unsigned char)(e[0x16] & ~1);
                }
                e = (unsigned char*)func_ov006_02157368((char*)obj + REGIONAL_OFFSET(0xf8, 0x100), 0x24);
                if (e != 0) {
                    e[0x16] = (unsigned char)(e[0x16] & ~1);
                }
            }
            ((BackgroundLoader*)loader)->RemoveTask(obj->unknown_354_);
            obj->unknown_354_ = -1;
            obj->unknown_390_ = obj->unknown_390_ + 1;
        }
    }
    else if (st == 0xa) {
        SpriteContext_Init((char*)((char*)obj + REGIONAL_OFFSET(0xa4, 0xac)));
        obj->unknown_fc_ = 1;
        obj->unknown_ec_ = (int)obj->f24;
        obj->unknown_f8_ = 0x1d;
        obj->unknown_e8_ = *(int*)((char*)obj->f18 + 0x20);
        obj->unknown_354_ = ((BackgroundLoader*)loader)->REGION_LOAD(data_ov006_021602f8, data_ov006_0216030a, data_ov006_0216162c);
        obj->unknown_390_ = obj->unknown_390_ + 1;
    }
    else if (st == 0xb) {
        if (((BackgroundLoader*)loader)->GetTaskStatus(obj->unknown_354_) != 0) {
            ((BackgroundLoader*)loader)->GetLoadedFileByID(obj->unknown_354_, &f.cbd, &f.unknown_10_);
            void* alloc;
            int n = Pac_CountFiles((PacRecord*)f.cbd);
            alloc = obj->alloc;
            ((SafeAllocator*)((char*)alloc + 0x8c))->Reset();
            int i;
            for (i = 0; i < n; i++) {
                void* rec = Pac_GetFile((PacRecord*)f.cbd, i, &f.rbd, &f.rbs);
                if (rec != 0) {
                SpriteContext_LoadFile((char*)obj + REGIONAL_OFFSET(0xa4, 0xac), rec, (void*)f.rbs, (char*)alloc + 0x8c);
                }
            }
            ((BackgroundLoader*)loader)->RemoveTask(obj->unknown_354_);
            obj->unknown_354_ = -1;
            obj->unknown_390_ = obj->unknown_390_ + 1;
            int j;
            for (j = 0; j < 8; j++) {
                *((unsigned char*)obj->f24 + (j + 0x12) * 0x28 + 0x22) = 0x18;
            }
        }
    }
    else if (st == 0xc) {
        obj->unknown_354_ = ((BackgroundLoader*)loader)->REGION_LOAD(data_ov006_02160318, data_ov006_0216032e, data_ov006_02161641);
        obj->unknown_390_ = obj->unknown_390_ + 1;
    }
    else if (st == 0xd) {
        if (((BackgroundLoader*)loader)->GetTaskStatus(obj->unknown_354_) != 0) {
            ((BackgroundLoader*)loader)->GetLoadedFileByID(obj->unknown_354_, &f.cd, &f.cs);
            if (f.cd != 0) {
                void* alloc = obj->alloc;
                ((SafeAllocator*)((char*)alloc + 0x28))->Reset();
#if defined(jpn)
                KeyTable_Reset((Struct020dfc40*)((char*)obj + REGIONAL_OFFSET(0x164, 0x170)));
                KeyTable_Load((char*)obj + REGIONAL_OFFSET(0x164, 0x170), (char*)alloc + 0x28, f.cd, f.cs);
#else
                func_020e526c((char*)obj + REGIONAL_OFFSET(0x164, 0x170));
                func_020e5604((char*)obj + REGIONAL_OFFSET(0x164, 0x170), (char*)alloc + 0x28, f.cd, f.cs);
#endif
            }
            ((BackgroundLoader*)loader)->RemoveTask(obj->unknown_354_);
            obj->unknown_354_ = -1;
            obj->unknown_390_ = obj->unknown_390_ + 1;
        }
    }
    else if (st == 0xe) {
        void* alloc = obj->alloc;
        ((SafeAllocator*)((char*)alloc + 0x64))->Reset();
        func_0207f84c(obj->f14);
#if defined(jpn)
        func_02080654((Struct_0207f914*)obj->f14, (unsigned int)alloc + 0x64, (int)data_ov006_02161657);
#else
        func_0207f914((Struct_0207f914*)obj->f14, (unsigned int)alloc + 0x64, (int)data_ov006_02160340, (int)data_ov006_02160359);
#endif
        obj->unknown_390_ = obj->unknown_390_ + 1;
    }
    else if (st == 0xf) {
        int res = func_0207f9f4(obj->f14);
        if (res == 0) {
            obj->unknown_390_ = obj->unknown_390_ + 1;
        }
        if (res < 0) {
            obj->unknown_38f_ = 0xc;
        }
    }
    else if (st == 0x10) {
        func_020810a0(obj->f14, 1);
        {
            Manager0207f7f0* n2 = obj->f14;
            n2->lists = obj->f1c;
            n2->mode = 2;
        }
        func_0207f7f0(obj->f14, obj->f20, 7);
        obj->f14->active = 1;
#if !defined(jpn)
        func_0208108c(obj->f14, 0x20);
        func_0208108c(obj->f14, 0x3e);
#endif
        volatile unsigned short* bg = (volatile unsigned short*)0x04001008;
        bg[0] = bg[0] & ~3;
        bg[1] = (bg[1] & ~3) | 1;
        bg[2] = (bg[2] & ~3) | 2;
        bg[3] = (bg[3] & ~3) | 3;
        *(volatile unsigned int*)0x04001000 = (*(volatile unsigned int*)0x04001000 & ~0x1f00) | 0x1f00;
        ColorEffect_ConfigureAlphaBlend((unsigned int*)((char*)bg + 0x48), 4, 0x18, 0xa, 6);
        func_ov006_02158de0(obj);
        obj->unknown_38f_ = 1;
        obj->unknown_390_ = 0;
        func_ov006_02153744((char*)obj + REGIONAL_OFFSET(0x6c, 0x74), (char*)obj + REGIONAL_OFFSET(0x140, 0x14c), (void*)obj->unknown_38_, 0x1d8 - 1);
        func_02071ffc((Struct_02071ffc_4*)((char*)obj + REGIONAL_OFFSET(0x140, 0x14c)), -1, -1, 0, 0, (short*)((char*)obj + 0x35c));
        f.sel = 0;
        func_02071ffc((Struct_02071ffc_4*)((char*)obj + REGIONAL_OFFSET(0x140, 0x14c)), obj->unknown_384_, obj->unknown_385_, obj->unknown_386_, 0x10, &f.sel);
        int v = obj->unknown_14c_;
        obj->unknown_2c_ = v;
        obj->unknown_30_ = v;
        func_ov006_02158cac(obj);
        func_ov006_02153c60((char*)obj + REGIONAL_OFFSET(0x6c, 0x74), obj->unknown_38_, 0x1d7);
        func_ov006_0215373c((char*)obj + REGIONAL_OFFSET(0x6c, 0x74), (char*)obj + REGIONAL_OFFSET(0x140, 0x14c));
        if ((obj->unknown_394_ & 2) == 0) {
            func_02081164((Struct_02081164*)obj->f14, 0, 1);
            func_02081164((Struct_02081164*)obj->f14, 1, 1);
            func_020813ec(obj->f14, 0);
            func_020813ec(obj->f14, 1);
            Canvas* var29 = (Canvas*)func_02081da8((Struct_0207fdcc_2*)obj->f14, 1);
            if (var29 != 0) {
                var29->fb8 = 0xc;
                var29->unknown_ba_ = 0x10;
            }
#if defined(jpn)
            void* r = KeyTable_Get((Container020e0310*)((char*)obj + REGIONAL_OFFSET(0x14c, 0x158)), 0);
            func_02080f8c((Container02080f8c*)obj->f14, 1, (int)r);
#else
            __clear(f.buf, 0x400);
            void* g = MessageSystem_GetInstance();
            void* r = KeyTable_Get((Container020e0310*)((char*)obj + REGIONAL_OFFSET(0x14c, 0x158)), 0);
            MessageSystem_FormatText(g, 0xc, r, f.buf, 0xe3, 0, 1);
            func_02080f8c((Container02080f8c*)obj->f14, 1, (int)f.buf);
#endif
            func_020813ec(obj->f14, 1);
        }
    }
}
