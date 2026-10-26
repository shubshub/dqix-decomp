#include <globaldefs.h>

#if defined(jpn)
#define func_ov008_02189c70 func_ov008_0218a930
#define LOW_REGION(j,u) (j)
#else
#define LOW_REGION(j,u) (u)
#endif
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "Memory/SafeAllocator.h"
#include "Grotto/Main/TreasureMapMetadata.h"
#include "std_library_functions.h"
#include "NitroSDK/Memory.h"
#include "NitroSDK/OverlayId.h"
#include "Resource/Brightness.h"



struct Struct_ov008_02189c70_17 { char c[10]; };

struct Struct_ov008_02189c70_18 {
    unsigned char state;
    char unknown_1_[10];
    char unknown_b_[10];
    unsigned char location;
    unsigned char flags;
    unsigned char quality;
    unsigned char level;
    unsigned short seed;
};

#if defined(jpn)
struct Struct_ov008_02189c70_19 {
    char pad[0x3b];
    char prefix[0x20];
    char suffix[0x20];
    char unknown_7b_[0x20];
    char level[8];
};
struct Struct_ov008_02189c70 {
    char pad[0x90];
    char name[0x20];
    char suffix[0x20];
    char level[8];
};
struct Struct_ov008_02189c70_2 {
    unsigned char f0;
    unsigned char type;
    char pad2[0x4c - 2];
    union {
        Struct_ov008_02189c70_19 unknown_0_;
        Struct_ov008_02189c70 unknown1_0_;
        char all[0x1e4 - 0x4c];
    } names;
};
#else
struct Struct_ov008_02189c70_2 {
    unsigned char f0;
    unsigned char type;
    char pad2[LOW_REGION(0x87 - 2,0xaf - 2)];
    char nameA[LOW_REGION(0xdc - 0x87,0x144 - 0xaf)];
    char nameB[LOW_REGION(0x1e4 - 0xdc,0x1c4 - 0x144)];
};
#endif

struct Struct_ov008_02189c70_3 {
    unsigned char count;
    unsigned char pad1;
    Struct_ov008_02189c70_18 entries[99];
    char unknown_ad6_[2];
};

struct Struct_ov008_02189c70_4 {
    unsigned char f0;
    unsigned char f1;
    unsigned char f2;
    char pad3;
    unsigned short f4;
    unsigned char unknown_6_;
    char name1[0xc];
    char name2[0xd];
    int f20;
    unsigned char f24;
    char unknown_25_;
    unsigned short unknown_26_;
};

struct Struct_ov008_02189c70_5 {
    unsigned char b[6];
};

struct Struct_ov008_02189c70_6 {
    Struct_ov008_02189c70_5 id;
    char pad6[0x14 - 6];
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    short f28;
    unsigned char unknown_2a_;
    unsigned char unknown_2b_;
};

struct Struct_ov008_02189c70_7 {
    char pad0[0xb];
    unsigned char unknown_b_0_ : 7;
    unsigned char active : 1;
    unsigned int kind : 4;
    unsigned int unknown_c_4_ : 28;
    unsigned int f10;
    char unknown_14_[0x2e - 0x14];
    unsigned char unknown_2e_0_ : 1;
    unsigned char unknown_2e_1_ : 7;
    char unknown_2f_[0x50 - 0x2f];
    Struct_ov008_02189c70_18 unknown_50_;
};

struct Struct_ov008_02189c70_8 {
    char pad0[0x414];
    unsigned char bit0 : 1;
    unsigned char hi : 7;
    int inline_01ff8b48_3() { return bit0; }
};

struct Struct_01ff8b48_24 {
    char pad0[0x88];
};

struct Struct_01ff8b48_25 {
    char pad0[0x44];
};

struct Struct_ov008_02189c70_9 {
    char pad0[0x44];
    Struct_01ff8b48_25 blk[2];
};

struct Struct_ov008_02189c70_10 {
    char pad0[LOW_REGION(0x8b8,0x950)];
    int unknown_950_;
#if defined(jpn)
    int inline_ov008_02189c70() const { return unknown_950_; }
#endif
};

struct Struct_ov008_02189c70_11 {
    char pad0[LOW_REGION(0x144,0x150)];
    Struct_ov008_02189c70_10* f150;
};

struct Window02189c70 {
    void* f0;
    char pad4[0x10 - 4];
    void* f10;
#if defined(jpn)
    char unknown_14_[0x2c - 0x14];
    char* text;
    char unknown_30_[0x218 - 0x30];
#else
    char unknown1_14_[0x2c8 - 0x14];
#endif
    int unknown_2c8_;
    char unknown_2cc_[LOW_REGION(0x868 - 0x21c,0x998 - 0x2cc)];
    int busy;
    int unknown_99c_;
    char unknown_9a0_[LOW_REGION(0x17e2 - 0x870,0x19b2 - 0x9a0)];
    unsigned char unknown_19b2_;
};

struct Struct_ov008_02189c70_13 {
    char pad0[9];
    unsigned char unknown_9_;
    char padA[0x28 - 0xa];
    char rec[0x2c];
};

struct Struct_ov008_02189c70_14 {
    char pad0[2];
    unsigned char f2;
};

struct Struct_ov008_02189c70_15 {
    char pad0[LOW_REGION(0x392c,0x3b4c)];
    Struct_ov008_02189c70_14* unknown_3b4c_;
    char unknown_3b50_[0x3b84 - 0x3b50];
    Struct_ov008_02189c70_13* unknown_3b84_;
};

struct Struct_ov008_02189c70_16 {
    char pad0[0x250];
    SafeAllocator alloc;
    char unknown_264_[LOW_REGION(0xddc,0xde0) - 0x250 - sizeof(SafeAllocator)];
    void* unknown_de0_;
    char unknown_de4_[0xdf0 - 0xde4];
    Struct_ov008_02189c70_5 id;
    char unknown_df6_[0xe04 - 0xdf6];
    int unknown_e04_;
    int unknown_e08_;
    int unknown_e0c_;
    int unknown_e10_;
    int unknown_e14_;
    short unknown_e18_;
    unsigned char unknown_e1a_;
    unsigned char unknown_e1b_;
    unsigned int unknown_e1c_0_ : 21;
    unsigned int unknown_e1e_5_ : 4;
    unsigned int unknown_e1f_1_ : 1;
    unsigned int unknown_e1f_2_ : 1;
    unsigned int unknown_e1f_3_ : 5;
    unsigned int unknown_e20_0_ : 9;
    int unknown_e21_1_ : 10;
    int unknown_e22_3_ : 11;
    unsigned int unknown_e23_6_ : 2;
    unsigned char unknown_e24_;
    char unknown_e25_[0xe98 - 0xe25];
    unsigned char unknown_e98_;
    unsigned char unknown_e99_;
    signed char state;
    unsigned char unknown_e9b_;
    unsigned char unknown_e9c_;
    char unknown_e9d_[0xeac - 0xe9d];
    int unknown_eac_;
#if !defined(jpn)
    int unknown_eb0_;
#endif
    char unknown_eb4_[0xeb9 - 0xeb4];
    signed char member;
    unsigned char unknown_eba_;
    unsigned char unknown_ebb_;
    Struct_ov008_02189c70_7* ebc;
    unsigned char unknown_ec0_0_ : 1;
    unsigned char unknown_ec0_1_ : 1;
    unsigned char unknown_ec0_2_ : 6;
    char unknown_ec1_[3];
    void* unknown_ec4_;
    unsigned int unknown_ec8_;
};

#if defined(jpn)
extern char data_ov008_0218c184[];
extern char data_ov008_0218c196[];
extern "C" void func_020474a8(Window02189c70*, int, char*, char*);
extern "C" void func_0204500c(Window02189c70*, char*, int);
#endif
extern "C" void* MessageSystem_GetInstance();
extern "C" int LinkSession_GetInstance();
extern "C" void func_020728ac(void* table, SafeAllocator* alloc, void* data, unsigned int size, int a, int b, int c);
extern "C" void* GlobalFlags_GetInstance();
struct FlagWord020466f4;
extern "C" void FlagWord_ClearBits(FlagWord020466f4*, unsigned int);
extern "C" void __clear(void* p, unsigned int size);
extern "C" void func_ov008_0218b240(Struct_ov008_02189c70_16* self);
extern "C" Struct_ov008_02189c70_9* func_02053c6c(unsigned char*);
extern "C" void Font_DecodeText(void* src, void* dst, int flag);
struct TableA68;
extern "C" char* func_02072a68(TableA68*, int);
struct Container020e0310;
extern "C" char* KeyTable_Get(Container020e0310*, int);
extern "C" void func_02099304(void* name, void* a1, void* a2, unsigned int a3, char* buf, int arg5, int flag, char* p1, char* p2);
extern "C" void func_02046380(void* w);
extern "C" void* Scenario_GetInstance();
extern "C" int Scenario_TestFlag(int, unsigned char*, int);
extern "C" void Scenario_SetFlag(void*, unsigned char*, int, int);
extern "C" void NameText_InitFromPartyMember(void* obj, int id);
extern "C" void MessageSystem_FormatText(Window02189c70* w, int a, char* str, char* buf, int b, int c, int d);
#if !defined(jpn)
extern "C" void func_0204500c(Window02189c70* w, char* str, int a, int b);
#endif
extern "C" int LinkSession_IsHostOrSolo(int v);
extern "C" int func_020457e0(Window02189c70* w);
extern "C" void func_ov008_0218b1e0(void* obj);
struct Entry_0205d6a0;
extern "C" void Window_ClosePane(Entry_0205d6a0*, int);
extern "C" void func_020a3720();
struct DetailedTreasureMapData;
bool ExportDetailedTreasureMapData(TreasureMapMetadata const*, DetailedTreasureMapData*, bool, unsigned char const*);
extern "C" void func_020a395c();
extern "C" void func_020464e8(char*, int, char*);
extern "C" void func_020e4b34(void* obj, void* a, void* b, int c, int d, int e, int f, int g, int h, int i, int j, int k);
extern "C" int GameState_GetLeaderIndex(GameState* gs);
extern "C" unsigned char func_02011804(GameState* gameState);
extern "C" void func_020ac760(void* dst);
extern "C" void func_020ac734(void* src);
struct Struct_02011818;
extern "C" void func_02011818(void*, Struct_02011818*);
extern "C" void func_02011ab8(char*);
extern "C" void func_02011a74(char*, unsigned int, char const*);
extern "C" void func_ov017_021a9ff0(int v);
extern "C" void Overlay_Load(unsigned int id);
struct Obj020397cc;
extern "C" void GameObject_DisableControl(Obj020397cc*, int);
struct Obj02046574;
extern "C" void MessageSystem_SetStringArgument(Obj02046574*, int, char*);

static inline Struct_ov008_02189c70_8* inline_ov008_02189c70_2(Struct_ov008_02189c70_9* ent, int i) {
    return (Struct_ov008_02189c70_8*)&ent->blk[i];
}

// USA: func_ov008_02189c70
extern "C" ARM void func_ov008_02189c70(Struct_ov008_02189c70_16* self) {
    char var0[0x400];
    char buf100[0x100];
    char buf80[0x80];
    Struct_ov008_02189c70_2 var3;
    Struct_ov008_02189c70_3 region;
    Struct_ov008_02189c70_2 var5;
    Struct_ov008_02189c70_2 var6;
#if !defined(jpn)
    char obj150[0xc];
    char obj144[0xc];
#endif

    GameState* gs = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    Window02189c70* win = (Window02189c70*)MessageSystem_GetInstance();
    Struct_ov008_02189c70_15* res = (Struct_ov008_02189c70_15*)GetGameResources();
    Struct_ov008_02189c70_13* sub = res->unknown_3b84_;
    int token = LinkSession_GetInstance();

    if (self->state == 0) {
#if defined(jpn)
        if ((self->unknown_e98_ & 2) && loader->GetTaskStatus(self->unknown_eac_)) {
            void* archive;
            void* data;
            unsigned int archiveSize;
            unsigned int size;
            int failed = 0;
            loader->GetLoadedFileByID(self->unknown_eac_, &archive, &archiveSize);
            if (!GetFileInNarc(archive, data_ov008_0218c184, (const void**)&data, &size, 0))
                failed = 1;
            self->alloc.Reset();
            func_020728ac((char*)self + 0x280, &self->alloc, data, size, 0, 0, 0);
            self->unknown_de0_ = (char*)self + 0x280;
            self->unknown_ec0_1_ = 1;
            if (!GetFileInNarc(archive, data_ov008_0218c196, (const void**)&data, &size, 0))
                failed = 1;
            if (failed) {
                loader->RemoveTask(self->unknown_eac_);
                Window_ClosePane((Entry_0205d6a0*)((char*)self + 0x18), 1);
                self->unknown_e99_ = 2;
                self->state = 0;
                self->unknown_e9b_ = 2;
                self->unknown_e9c_ = 0;
                return;
            }
            self->unknown_ec4_ = data;
            self->unknown_ec8_ = size;
            FlagWord_ClearBits((FlagWord020466f4*)GlobalFlags_GetInstance(), 0x2f);
            ClearFlags00(GetGameResources(), 0x10);
            self->state = self->state + 1;
        }
#else
        if ((self->unknown_e98_ & 2) && loader->GetTaskStatus(self->unknown_eac_) && loader->GetTaskStatus(self->unknown_eb0_)) {
            void* data;
            unsigned int size;
            loader->GetLoadedFileByID(self->unknown_eac_, &data, &size);
            self->alloc.Reset();
            func_020728ac((char*)self + 0x280, &self->alloc, data, size, 0, 0, 0);
            self->unknown_de0_ = (char*)self + 0x280;
            self->unknown_ec0_1_ = 1;
            loader->GetLoadedFileByID(self->unknown_eb0_, &data, &size);
            self->unknown_ec4_ = data;
            self->unknown_ec8_ = size;
            FlagWord_ClearBits((FlagWord020466f4*)GlobalFlags_GetInstance(), 0x2f);
            ClearFlags00(GetGameResources(), 0x10);
            self->state = self->state + 1;
        }
#endif
    } else if (self->state == 1) {
        Struct_ov008_02189c70_11* m = (Struct_ov008_02189c70_11*)gs->GetPartyMemberByIndex(self->member);
        Struct_ov008_02189c70_9* ent = 0;
        int base;
        char* name;
#if !defined(jpn)
        char clr1[0x30];
        __clear(clr1, 0x30);
#endif
        if (self->ebc == 0) {
            if (m == 0) {
                func_ov008_0218b240(self);
                return;
            }
            ent = func_02053c6c((unsigned char*)m);
            base = (signed char)m->f150->unknown_950_;
#if defined(jpn)
            name = (char*)self + 0xdf2;
#else
            Font_DecodeText((char*)self + 0xdf6, clr1, 1);
            name = clr1;
#endif
        } else {
#if defined(jpn)
            name = (char*)self->ebc;
#else
            Font_DecodeText(self->ebc, clr1, 1);
            name = clr1;
#endif
            base = (signed char)self->ebc->kind;
        }
        if (ent != 0 && !self->unknown_e1f_2_) {
            Struct_ov008_02189c70_8* var27 = inline_ov008_02189c70_2(ent, 1);
            self->unknown_e1f_1_ = var27->bit0;
            self->unknown_e1e_5_ = var27->bit0;
            self->unknown_e21_1_ = 300;
            int key = 20700;
#if !defined(jpn)
            if (var27->bit0 == 1) key += 50;
#endif
#if defined(jpn)
            self->unknown_e22_3_ = m->f150->inline_ov008_02189c70() + 700;
#else
            self->unknown_e22_3_ = key - 20000 + m->f150->unknown_950_;
#endif
            self->unknown_e24_ = 0;
        }
        int mode = self->ebc != 0 ? 3 : 1;
        char* title = func_02072a68((TableA68*)((char*)self + 0x280), (short)(self->unknown_e21_1_ + 10000));
        char* body;
        int v = self->unknown_e22_3_;
        if (v < 700) {
            body = KeyTable_Get((Container020e0310*)((char*)self + 0x288), (short)v);
        } else if (v < 800) {
            int key = 20700;
#if !defined(jpn)
            if (self->unknown_e1f_1_ == 1) key += 50;
#endif
            body = func_02072a68((TableA68*)((char*)self + 0x280), (short)(base + key));
        } else {
            body = func_02072a68((TableA68*)((char*)self + 0x280), (short)(v + 20000));
        }
        func_02099304((char*)self + LOW_REGION(0xe18,0xe1c), name, self->unknown_ec4_, self->unknown_ec8_, var0, 0x400, mode, title, body);
        func_02046380(win);
        int found = 0;
        char* p = var0;
        p += strlen(var0);
        if (self->ebc == 0) {
            void* flags = Scenario_GetInstance();
            if (!Scenario_TestFlag((int)flags, (unsigned char*)((char*)flags + 0x8c), 0x119b)) {
                char* str = func_02072a68((TableA68*)((char*)self + 0x278), 0x66);
                int len = strlen(str);
                memcpy(p, str, len);
                p += len;
                Scenario_SetFlag(flags, (unsigned char*)((char*)flags + 0x8c), 0x119b, 1);
            }
#if defined(jpn)
            unsigned char* var41;
            Struct_ov008_02189c70_6* slot;
            int i;
            var41 = (unsigned char*)gs + 0x3bc + 0x6c00;
#else
            Struct_ov008_02189c70_6* slot;
            int i;
            unsigned char* var41 = (unsigned char*)gs + 0x1fc + 0x7000;
#endif
            slot = (Struct_ov008_02189c70_6*)(var41 + 4);
            Struct_ov008_02189c70_5 id = self->id;
            for (i = 0; i < *var41; i++, slot++) {
                Struct_ov008_02189c70_5 tmp = id;
                int same;
                int j;
                for (j = 0; j < 6; j++) {
                    if (tmp.b[j] != slot->id.b[j]) {
                        same = 0;
                        goto compared;
                    }
                }
                same = 1;
            compared:
                if (same) {
                    slot->f14 = self->unknown_e04_;
                    slot->f18 = self->unknown_e08_;
                    slot->f1c = self->unknown_e0c_;
                    slot->f20 = self->unknown_e10_;
                    slot->f24 = self->unknown_e14_;
                    slot->f28 = self->unknown_e18_;
                    slot->unknown_2a_ = self->unknown_e1a_;
                    slot->unknown_2b_ = self->unknown_e1b_;
                    found = 1;
                    break;
                }
            }
            memset(buf100, 0, 0x100);
            if (!found) {
                char* str = func_02072a68((TableA68*)((char*)self + 0x278), 0x64);
#if defined(jpn)
                MessageSystem_SetStringArgument((Obj02046574*)win, 0, name);
                func_020474a8(win, 0xc, str, buf100);
#else
                NameText_InitFromPartyMember(obj144, self->member);
                win->f10 = obj144;
                MessageSystem_FormatText(win, 0xc, str, buf100, 0xe3, 0, 1);
#endif
                memcpy(p, buf100, strlen(buf100));
            }
        }
        if (!self->unknown_e1f_1_) win->unknown_99c_ = 0; else win->unknown_99c_ = 2;
        win->unknown_19b2_ = 1;
#if defined(jpn)
        func_0204500c(win, var0, 0);
#else
        func_0204500c(win, var0, 0, 0xe3);
#endif
        win->busy = 1;
        loader->RemoveTask(self->unknown_eac_);
#if !defined(jpn)
        loader->RemoveTask(self->unknown_eb0_);
#endif
        self->unknown_eac_ = -1;
#if !defined(jpn)
        self->unknown_eb0_ = -1;
#endif
        if (self->ebc != 0) {
            if (self->ebc->active && LinkSession_IsHostOrSolo(token)) {
                self->state = 3;
            } else {
                self->state = 2;
            }
        } else if (found) {
            self->state = 2;
        } else {
            self->state = 100;
        }
    } else if (self->state == 100) {
        if (win->busy != 0) return;
        if (func_020457e0(win) == 0) {
            memset(buf80, 0, 0x80);
            if (*((unsigned char*)gs + LOW_REGION(0x6000 + 0xfbc,0x7000 + 0x1fc)) >= 0x10) {
                char* str = func_02072a68((TableA68*)((char*)self + 0x278), 0x69);
                memcpy(buf80, str, strlen(str));
                self->unknown_ebb_ = 1;
            } else {
#if defined(jpn)
                MessageSystem_SetStringArgument((Obj02046574*)win, 0, (char*)self + 0xdf2);
                char* str = func_02072a68((TableA68*)((char*)self + 0x278), 0x68);
                func_020474a8(win, 0xc, str, buf80);
#else
                char* str = func_02072a68((TableA68*)((char*)self + 0x278), 0x68);
                NameText_InitFromPartyMember(obj144, self->member);
                win->f10 = obj144;
                MessageSystem_FormatText(win, 0xc, str, buf80, 0xe3, 0, 1);
#endif
                func_ov008_0218b1e0(self);
            }
            if (!self->unknown_e1f_1_) win->unknown_99c_ = 0; else win->unknown_99c_ = 2;
            win->unknown_19b2_ = 1;
#if defined(jpn)
            func_0204500c(win, buf80, 0);
#else
            func_0204500c(win, buf80, 0, 0xe3);
#endif
            win->busy = 1;
        }
        self->state = 2;
    } else if (self->state == 2) {
        if (win->busy != 0) return;
        if (func_020457e0(win) == 0 && self->unknown_ebb_ != 0) {
            memcpy(sub->rec, &self->id, 0x2c);
            sub->unknown_9_ = 1;
            self->unknown_eba_ = 1;
        }
        Window_ClosePane((Entry_0205d6a0*)((char*)self + 0x18), 1);
        self->unknown_e99_ = 2;
        self->state = 0;
        self->unknown_e9b_ = 2;
        self->unknown_e9c_ = 0;
    } else if (self->state == 3) {
        if (win->busy != 0) return;
        Struct_ov008_02189c70_18 var50 = self->ebc->unknown_50_;
        func_020a3720();
        ExportDetailedTreasureMapData((TreasureMapMetadata const*)&var50, (DetailedTreasureMapData*)&var3, 0, (unsigned char const*)0);
        func_020a395c();
#if defined(jpn)
        if (var3.type == 1) {
            Struct_ov008_02189c70_19* names = &var3.names.unknown_0_;
            MessageSystem_SetStringArgument((Obj02046574*)win, 2, names->prefix);
            MessageSystem_SetStringArgument((Obj02046574*)win, 3, names->suffix);
            MessageSystem_SetStringArgument((Obj02046574*)win, 4, func_02072a68((TableA68*)((char*)self + 0x278), 0xc8));
            MessageSystem_SetStringArgument((Obj02046574*)win, 5, names->level);
        } else if (var3.type == 2) {
            Struct_ov008_02189c70* names = &var3.names.unknown1_0_;
            MessageSystem_SetStringArgument((Obj02046574*)win, 2, names->name);
            MessageSystem_SetStringArgument((Obj02046574*)win, 3, names->suffix);
            MessageSystem_SetStringArgument((Obj02046574*)win, 5, names->level);
        } else {
            self->state = 2;
            return;
        }
#else
        if (var3.type == 1) {
            func_020464e8((char*)win, 2, var3.nameA);
        } else if (var3.type == 2) {
            func_020464e8((char*)win, 2, var3.nameB);
        } else {
            self->state = 2;
            return;
        }
#endif
#if defined(jpn)
        MessageSystem_SetStringArgument((Obj02046574*)win, 0, (char*)self->ebc);
        MessageSystem_SetStringArgument((Obj02046574*)win, 1, *(char**)((char*)gs->GetLeader() + 0x134));
#else
        char clr3[0x30];
        __clear(clr3, 0x30);
        Font_DecodeText(self->ebc, clr3, 1);
        func_020e4b34(obj144, clr3, clr3, 0, 0, 0, 0, self->ebc->unknown_2e_0_, 0, 1, 0, 1);
        NameText_InitFromPartyMember(obj150, GameState_GetLeaderIndex(gs));
        win->f10 = obj144;
        win->f0 = obj150;
#endif
        if (func_02011804(gs) >= 0x63) {
#if defined(jpn)
            func_0204500c(win, func_02072a68((TableA68*)((char*)self + 0x278), 0xc9), 0);
#else
            func_0204500c(win, func_02072a68((TableA68*)((char*)self + 0x278), 0xc9), 0, 0xe3);
#endif
        } else {
#if defined(jpn)
            func_0204500c(win, func_02072a68((TableA68*)((char*)self + 0x278), 0xca), 0);
#else
            func_0204500c(win, func_02072a68((TableA68*)((char*)self + 0x278), 0xca), 0, 0xe3);
#endif
        }
        win->busy = 1;
        win->unknown_19b2_ = 0;
        self->state = 4;
    } else if (self->state == 4) {
        if (win->busy != 0) return;
        if (func_02011804(gs) >= 0x63) {
#if defined(jpn)
            char* text = win->text;
            char* name = *(char**)((char*)gs->GetLeader() + 0x134);
            sprintf(text, func_02072a68((TableA68*)((char*)self + 0x278), 0xcb), name);
            win->unknown_2c8_ = 1;
            func_0204500c(win, text, 0);
#else
            NameText_InitFromPartyMember(obj150, GameState_GetLeaderIndex(gs));
            win->f0 = obj150;
            win->unknown_2c8_ = 1;
#if defined(jpn)
            func_0204500c(win, func_02072a68((TableA68*)((char*)self + 0x278), 0xcb), 0);
#else
            func_0204500c(win, func_02072a68((TableA68*)((char*)self + 0x278), 0xcb), 0, 0xe3);
#endif
#endif
            win->busy = 1;
            win->unknown_19b2_ = 1;
            self->state = 5;
        } else {
            func_020ac760(&region);
            VectorizedMemset(&region.entries[region.count], 0, 0x1c);
            Struct_ov008_02189c70_18* src = &self->ebc->unknown_50_;
            Struct_ov008_02189c70_18* e = &region.entries[region.count];
            e->state = src->state;
            *(Struct_ov008_02189c70_17*)e->unknown_1_ = *(Struct_ov008_02189c70_17*)src->unknown_1_;
            *(Struct_ov008_02189c70_17*)e->unknown_b_ = *(Struct_ov008_02189c70_17*)src->unknown_b_;
            e->location = src->location;
            e->flags = src->flags;
            e->quality = src->quality;
            e->level = src->level;
            e->seed = src->seed;
            region.count++;
            func_020ac734(&region);
            self->ebc->active = 0;
            self->state = 2;
        }
    } else if (self->state == 5) {
        if (win->busy != 0) return;
        int r = func_020457e0(win);
        if (r == 0) {
            self->state = 2;
            return;
        }
        if (r != 1) return;
        Struct_ov008_02189c70_18 var59 = self->ebc->unknown_50_;
        func_020a3720();
        ExportDetailedTreasureMapData((TreasureMapMetadata const*)&var59, (DetailedTreasureMapData*)&var5, 0, (unsigned char const*)0);
        func_020a395c();
        Struct_ov008_02189c70_4 names;
        VectorizedMemset(&names, 0, 0x28);
        names.name1[0] = 0;
        names.name2[0] = 0;
        names.unknown_6_ = 0;
        names.f20 = -1;
        names.f0 = ((TreasureMapMetadata*)&var59)->GetMapType();
        names.f1 = var59.quality;
        names.f2 = var59.level;
        names.f4 = var59.seed;
        names.unknown_6_ = 0;
        strcpy(names.name1, var59.unknown_1_);
        strcpy(names.name2, var59.unknown_b_);
        names.f24 = var59.flags;
        if (names.f0 == 2) names.unknown_26_ = var59.seed;
        names.f20 = var59.location;
        func_02011818(gs, (Struct_02011818*)&names);
#if defined(jpn)
        if (((TreasureMapMetadata*)&var59)->GetMapType() == 1) {
            Struct_ov008_02189c70_19* names = &var5.names.unknown_0_;
            func_02011ab8((char*)gs);
            func_02011a74((char*)gs, 0, names->prefix);
            func_02011a74((char*)gs, 1, names->suffix);
            func_02011a74((char*)gs, 2, func_02072a68((TableA68*)((char*)self + 0x278), 0xc8));
            func_02011a74((char*)gs, 3, names->level);
        } else if (((TreasureMapMetadata*)&var59)->GetMapType() == 2) {
            Struct_ov008_02189c70* names = &var5.names.unknown1_0_;
            func_02011ab8((char*)gs);
            func_02011a74((char*)gs, 0, names->name);
            func_02011a74((char*)gs, 1, names->suffix);
            func_02011a74((char*)gs, 3, names->level);
        }
#else
        if (((TreasureMapMetadata*)&var59)->GetMapType() == 1) {
            func_02011ab8((char*)gs);
            func_02011a74((char*)gs, 0, var5.nameA);
        } else if (((TreasureMapMetadata*)&var59)->GetMapType() == 2) {
            func_02011a74((char*)gs, 0, var5.nameB);
        }
#endif
        *(unsigned int*)((char*)gs + LOW_REGION(0x61f4,0x6474)) = self->ebc->f10 >> 2;
        func_ov017_021a9ff0(0);
        Window_ClosePane((Entry_0205d6a0*)((char*)self + 0x18), 1);
        self->state = 2;
    } else if (self->state == 6) {
        if (res->unknown_3b4c_->f2 != 0) return;
        Overlay_Load(OVERLAY_ID(8));
        self->unknown_ec0_0_ = 0;
        self->state = 7;
    } else if (self->state == 7) {
        void* obj = gs->GetLeader();
        if (obj != 0) GameObject_DisableControl((Obj020397cc*)obj, 1);
        if (*((unsigned char*)gs + LOW_REGION(0x6000 + 0x1ee,0x6000 + 0x46e)) != 0) {
            Struct_ov008_02189c70_18 var64 = self->ebc->unknown_50_;
            func_020a3720();
            ExportDetailedTreasureMapData((TreasureMapMetadata const*)&var64, (DetailedTreasureMapData*)&var6, 0, (unsigned char const*)0);
            func_020a395c();
    #if defined(jpn)
            if (var6.type == 1) {
            Struct_ov008_02189c70_19* names = &var6.names.unknown_0_;
                MessageSystem_SetStringArgument((Obj02046574*)win, 2, names->prefix);
                MessageSystem_SetStringArgument((Obj02046574*)win, 3, names->suffix);
                MessageSystem_SetStringArgument((Obj02046574*)win, 4, func_02072a68((TableA68*)((char*)self + 0x278), 0xc8));
                MessageSystem_SetStringArgument((Obj02046574*)win, 5, names->level);
            } else if (var6.type == 2) {
            Struct_ov008_02189c70* names = &var6.names.unknown1_0_;
                MessageSystem_SetStringArgument((Obj02046574*)win, 2, names->name);
                MessageSystem_SetStringArgument((Obj02046574*)win, 3, names->suffix);
                MessageSystem_SetStringArgument((Obj02046574*)win, 5, names->level);
            }
#else
        if (var6.type == 1) {
                func_020464e8((char*)win, 2, var6.nameA);
            } else if (var6.type == 2) {
                func_020464e8((char*)win, 2, var6.nameB);
            }
#endif
#if defined(jpn)
            MessageSystem_SetStringArgument((Obj02046574*)win, 0, (char*)self->ebc);
#else
            char clr7[0x30];
            __clear(clr7, 0x30);
            Font_DecodeText(self->ebc, clr7, 1);
            MessageSystem_SetStringArgument((Obj02046574*)win, 0, clr7);
#endif
            MessageSystem_SetStringArgument((Obj02046574*)win, 1, *(char**)((char*)gs->GetLeader() + 0x134));
#if defined(jpn)
            func_0204500c(win, func_02072a68((TableA68*)((char*)self + 0x278), 0xca), 0);
#else
            func_0204500c(win, func_02072a68((TableA68*)((char*)self + 0x278), 0xca), 0, 0xe3);
#endif
            win->busy = 1;
            win->unknown_19b2_ = 0;
            self->ebc->active = 0;
        }
        self->state = 2;
    }
}
