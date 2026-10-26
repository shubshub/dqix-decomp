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



struct Struct_ov008_02189c70_17 { char unknown_0_[10]; };

struct Struct_ov008_02189c70_18 {
    unsigned char unknown_0_;
    char unknown_1_[10];
    char unknown_b_[10];
    unsigned char unknown_15_;
    unsigned char unknown_16_;
    unsigned char unknown_17_;
    unsigned char unknown_18_;
    unsigned short unknown_1a_;
};

#if defined(jpn)
struct Struct_ov008_02189c70_19 {
    char unknown_0_[0x3b];
    char unknown_3b_[0x20];
    char unknown_5b_[0x20];
    char unknown_7b_[0x20];
    char unknown_9b_[8];
};
struct Struct_ov008_02189c70 {
    char unknown_0_[0x90];
    char unknown_90_[0x20];
    char unknown_b0_[0x20];
    char unknown_d0_[8];
};
struct Struct_ov008_02189c70_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    char unknown_2_[0x4c - 2];
    union {
        Struct_ov008_02189c70_19 unknown_0_;
        Struct_ov008_02189c70 unknown1_0_;
        char unknown2_0_[0x1e4 - 0x4c];
    } unknown_4c_;
};
#else
struct Struct_ov008_02189c70_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    char unknown_2_[LOW_REGION(0x87 - 2,0xaf - 2)];
    char unknown_af_[LOW_REGION(0xdc - 0x87,0x144 - 0xaf)];
    char unknown_144_[LOW_REGION(0x1e4 - 0xdc,0x1c4 - 0x144)];
};
#endif

struct Struct_ov008_02189c70_3 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    Struct_ov008_02189c70_18 unknown_2_[99];
    char unknown_ad6_[2];
};

struct Struct_ov008_02189c70_4 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
    char unknown_3_;
    unsigned short unknown_4_;
    unsigned char unknown_6_;
    char unknown_7_[0xc];
    char unknown_13_[0xd];
    int unknown_20_;
    unsigned char unknown_24_;
    char unknown_25_;
    unsigned short unknown_26_;
};

struct Struct_ov008_02189c70_5 {
    unsigned char unknown_0_[6];
};

struct Struct_ov008_02189c70_6 {
    Struct_ov008_02189c70_5 unknown_0_;
    char unknown_6_[0x14 - 6];
    int unknown_14_;
    int unknown_18_;
    int unknown_1c_;
    int unknown_20_;
    int unknown_24_;
    short unknown_28_;
    unsigned char unknown_2a_;
    unsigned char unknown_2b_;
};

struct Struct_ov008_02189c70_7 {
    char unknown_0_[0xb];
    unsigned char unknown_b_0_ : 7;
    unsigned char unknown_b_7_ : 1;
    unsigned int unknown_c_0_ : 4;
    unsigned int unknown_c_4_ : 28;
    unsigned int unknown_10_;
    char unknown_14_[0x2e - 0x14];
    unsigned char unknown_2e_0_ : 1;
    unsigned char unknown_2e_1_ : 7;
    char unknown_2f_[0x50 - 0x2f];
    Struct_ov008_02189c70_18 unknown_50_;
};

struct Struct_ov008_02189c70_8 {
    char unknown_0_[0x414];
    unsigned char unknown_414_0_ : 1;
    unsigned char unknown_414_1_ : 7;
    int inline_01ff8b48_3() { return unknown_414_0_; }
};

struct Struct_01ff8b48_24 {
    char unknown_0_[0x88];
};

struct Struct_01ff8b48_25 {
    char unknown_0_[0x44];
};

struct Struct_ov008_02189c70_9 {
    char unknown_0_[0x44];
    Struct_01ff8b48_25 unknown_44_[2];
};

struct Struct_ov008_02189c70_10 {
    char unknown_0_[LOW_REGION(0x8b8,0x950)];
    int unknown_950_;
#if defined(jpn)
    int inline_ov008_02189c70() const { return unknown_950_; }
#endif
};

struct Struct_ov008_02189c70_11 {
    char unknown_0_[LOW_REGION(0x144,0x150)];
    Struct_ov008_02189c70_10* unknown_150_;
};

struct Struct_ov008_02189c70_12 {
    void* unknown_0_;
    char unknown_4_[0x10 - 4];
    void* unknown_10_;
#if defined(jpn)
    char unknown_14_[0x2c - 0x14];
    char* unknown_2c_;
    char unknown_30_[0x218 - 0x30];
#else
    char unknown1_14_[0x2c8 - 0x14];
#endif
    int unknown_2c8_;
    char unknown_2cc_[LOW_REGION(0x868 - 0x21c,0x998 - 0x2cc)];
    int unknown_998_;
    int unknown_99c_;
    char unknown_9a0_[LOW_REGION(0x17e2 - 0x870,0x19b2 - 0x9a0)];
    unsigned char unknown_19b2_;
};

struct Struct_ov008_02189c70_13 {
    char unknown_0_[9];
    unsigned char unknown_9_;
    char unknown_a_[0x28 - 0xa];
    char unknown_28_[0x2c];
};

struct Struct_ov008_02189c70_14 {
    char unknown_0_[2];
    unsigned char unknown_2_;
};

struct Struct_ov008_02189c70_15 {
    char unknown_0_[LOW_REGION(0x392c,0x3b4c)];
    Struct_ov008_02189c70_14* unknown_3b4c_;
    char unknown_3b50_[0x3b84 - 0x3b50];
    Struct_ov008_02189c70_13* unknown_3b84_;
};

struct Struct_ov008_02189c70_16 {
    char unknown_0_[0x250];
    SafeAllocator unknown_250_;
    char unknown_264_[LOW_REGION(0xddc,0xde0) - 0x250 - sizeof(SafeAllocator)];
    void* unknown_de0_;
    char unknown_de4_[0xdf0 - 0xde4];
    Struct_ov008_02189c70_5 unknown_df0_;
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
    signed char unknown_e9a_;
    unsigned char unknown_e9b_;
    unsigned char unknown_e9c_;
    char unknown_e9d_[0xeac - 0xe9d];
    int unknown_eac_;
#if !defined(jpn)
    int unknown_eb0_;
#endif
    char unknown_eb4_[0xeb9 - 0xeb4];
    signed char unknown_eb9_;
    unsigned char unknown_eba_;
    unsigned char unknown_ebb_;
    Struct_ov008_02189c70_7* unknown_ebc_;
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
extern "C" void func_020474a8(Struct_ov008_02189c70_12*, int, char*, char*);
extern "C" void func_0204500c(Struct_ov008_02189c70_12*, char*, int);
#endif
void* MessageSystem_GetInstance();
extern "C" int LinkSession_GetInstance();
extern "C" void func_020728ac(void* table, SafeAllocator* alloc, void* data, unsigned int size, int a, int b, int c);
void* GlobalFlags_GetInstance();
struct FlagWord020466f4;
void FlagWord_ClearBits(FlagWord020466f4*, unsigned int);
extern "C" void __clear(void* p, unsigned int size);
extern "C" void func_ov008_0218b240(Self02189c70* self);
Ent02189c70* GetFieldAt0x150_02053c6c(unsigned char*);
extern "C" void Font_DecodeText(void* src, void* dst, int flag);
struct TableA68;
char* FindEntryByKey_02072a68(TableA68*, int);
struct Container020e0310;
char* KeyTable_Get(Container020e0310*, int);
extern "C" void func_02099304(void* name, void* a1, void* a2, unsigned int a3, char* buf, int bufSize, int flag, char* p1, char* p2);
extern "C" void func_02046380(void* w);
extern "C" void* Scenario_GetInstance();
int Scenario_TestFlag(int, unsigned char*, int);
extern "C" void Scenario_SetFlag(void*, unsigned char*, int, int);
void NameText_InitFromPartyMember(void* obj, int id);
extern "C" void MessageSystem_FormatText(Window02189c70* w, int a, char* str, char* buf, int b, int c, int d);
#if !defined(jpn)
extern "C" void func_0204500c(Struct_ov008_02189c70_12* arg0, char* arg1, int arg2, int arg3);
#endif
extern "C" int LinkSession_IsHostOrSolo(int v);
extern "C" int func_020457e0(Window02189c70* w);
void AllocateFreeSlot0218b1e0(void* obj);
struct Entry_0205d6a0;
void Window_ClosePane(Entry_0205d6a0*, int);
extern "C" void func_020a3720();
struct DetailedTreasureMapData;
bool ExportDetailedTreasureMapData(TreasureMapMetadata const*, DetailedTreasureMapData*, bool, unsigned char const*);
extern "C" void func_020a395c();
void CopyStringToIndexedField0x2ec_020464e8(char*, int, char*);
extern "C" void func_020e4b34(void* obj, void* a, void* b, int c, int d, int e, int f, int g, int h, int i, int j, int k);
int GameState_GetLeaderIndex(GameState* gs);
unsigned char ReadBattleField0x64f4Byte_02011804(GameState* gameState);
void CopyOutBattleRegion0x64f4_020ac760(void* dst);
void CopyToBattleRegion0x64f4_020ac734(void* src);
struct Src02011818;
void SetNameEntries02011818(void*, Src02011818*);
void ClearRegion0x649e_02011ab8(char*);
void CopyStringToField0x649e_02011a74(char*, unsigned int, char const*);
extern "C" void func_ov017_021a9ff0(int v);
extern "C" void Overlay_Load(unsigned int id);
struct Obj020397cc;
void GameObject_DisableControl(Obj020397cc*, int);
struct Obj02046574;
void MessageSystem_SetStringArgument(Obj02046574*, int, char*);

static inline Struct_ov008_02189c70_8* inline_ov008_02189c70_2(Struct_ov008_02189c70_9* arg0, int arg1) {
    return (Struct_ov008_02189c70_8*)&arg0->unknown_44_[arg1];
}

// USA: func_ov008_02189c70
extern "C" ARM void func_ov008_02189c70(Struct_ov008_02189c70_16* arg0) {
    char var0[0x400];
    char var1[0x100];
    char var2[0x80];
    Struct_ov008_02189c70_2 var3;
    Struct_ov008_02189c70_3 var4;
    Struct_ov008_02189c70_2 var5;
    Struct_ov008_02189c70_2 var6;
#if !defined(jpn)
    char var7[0xc];
    char var8[0xc];
#endif

    GameState* gs = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    Window02189c70* win = (Window02189c70*)MessageSystem_GetInstance();
    Res02189c70* res = (Res02189c70*)GetGameResources();
    Sub3b84* sub = res->f3b84;
    int token = LinkSession_GetInstance();

    if (arg0->unknown_e9a_ == 0) {
#if defined(jpn)
        if ((self->e98 & 2) && loader->GetTaskStatus(self->eac)) {
            void* archive;
            void* data;
            unsigned int archiveSize;
            unsigned int size;
            int failed = 0;
            loader->GetLoadedFileByID(self->eac, &archive, &archiveSize);
            if (!GetFileInNarc(archive, data_ov008_0218c184, (const void**)&data, &size, 0))
                failed = 1;
            self->alloc.Reset();
            func_020728ac((char*)self + 0x280, &self->alloc, data, size, 0, 0, 0);
            self->de0 = (char*)self + 0x280;
            self->ec0_b1 = 1;
            if (!GetFileInNarc(archive, data_ov008_0218c196, (const void**)&data, &size, 0))
                failed = 1;
            if (failed) {
                loader->RemoveTask(self->eac);
                Window_ClosePane((Entry_0205d6a0*)((char*)self + 0x18), 1);
                self->e99 = 2;
                self->state = 0;
                self->e9b = 2;
                self->e9c = 0;
                return;
            }
            self->ec4 = data;
            self->ec8 = size;
            FlagWord_ClearBits((FlagWord020466f4*)GlobalFlags_GetInstance(), 0x2f);
            ClearFlags00(GetGameResources(), 0x10);
            arg0->unknown_e9a_ = arg0->unknown_e9a_ + 1;
        }
#else
        if ((self->e98 & 2) && loader->GetTaskStatus(self->eac) && loader->GetTaskStatus(self->eb0)) {
            void* data;
            unsigned int size;
            loader->GetLoadedFileByID(self->eac, &data, &size);
            self->alloc.Reset();
            func_020728ac((char*)self + 0x280, &self->alloc, data, size, 0, 0, 0);
            self->de0 = (char*)self + 0x280;
            self->ec0_b1 = 1;
            loader->GetLoadedFileByID(self->eb0, &data, &size);
            self->ec4 = data;
            self->ec8 = size;
            FlagWord_ClearBits((FlagWord020466f4*)GlobalFlags_GetInstance(), 0x2f);
            ClearFlags00(GetGameResources(), 0x10);
            arg0->unknown_e9a_ = arg0->unknown_e9a_ + 1;
        }
#endif
    } else if (arg0->unknown_e9a_ == 1) {
        Struct_ov008_02189c70_11* var22 = (Struct_ov008_02189c70_11*)var9->GetPartyMemberByIndex(arg0->unknown_eb9_);
        Struct_ov008_02189c70_9* var23 = 0;
        int var24;
        char* var25;
#if !defined(jpn)
        char var26[0x30];
        __clear(var26, 0x30);
#endif
        if (arg0->unknown_ebc_ == 0) {
            if (var22 == 0) {
                func_ov008_0218b240(arg0);
                return;
            }
            var23 = func_02053c6c((unsigned char*)var22);
            var24 = (signed char)var22->unknown_150_->unknown_950_;
#if defined(jpn)
            var25 = (char*)arg0 + 0xdf2;
#else
            Font_DecodeText((char*)self + 0xdf6, clr1, 1);
            name = clr1;
#endif
        } else {
#if defined(jpn)
            var25 = (char*)arg0->unknown_ebc_;
#else
            Font_DecodeText(self->ebc, clr1, 1);
            name = clr1;
#endif
            var24 = (signed char)arg0->unknown_ebc_->unknown_c_0_;
        }
        if (var23 != 0 && !arg0->unknown_e1f_2_) {
            Struct_ov008_02189c70_8* var27 = inline_ov008_02189c70_2(var23, 1);
            arg0->unknown_e1f_1_ = var27->unknown_414_0_;
            arg0->unknown_e1e_5_ = var27->unknown_414_0_;
            arg0->unknown_e21_1_ = 300;
            int var28 = 20700;
#if !defined(jpn)
            if (var27->unknown_414_0_ == 1) var28 += 50;
#endif
#if defined(jpn)
            arg0->unknown_e22_3_ = var22->unknown_150_->inline_ov008_02189c70() + 700;
#else
            arg0->unknown_e22_3_ = var28 - 20000 + var22->unknown_150_->unknown_950_;
#endif
            arg0->unknown_e24_ = 0;
        }
        int mode = self->ebc != 0 ? 3 : 1;
        char* title = FindEntryByKey_02072a68((TableA68*)((char*)self + 0x280), (short)(self->e20_f9 + 10000));
        char* body;
        int v = self->e20_f19;
        if (v < 700) {
            body = KeyTable_Get((Container020e0310*)((char*)self + 0x288), (short)v);
        } else if (v < 800) {
            int key = 20700;
#if !defined(jpn)
            if (arg0->unknown_e1f_1_ == 1) var33 += 50;
#endif
            var31 = func_02072a68((Struct_02072a68_2*)((char*)arg0 + 0x280), (short)(var24 + var33));
        } else {
            var31 = func_02072a68((Struct_02072a68_2*)((char*)arg0 + 0x280), (short)(var32 + 20000));
        }
        func_02099304((char*)self + LOW_REGION(0xe18,0xe1c), name, self->ec4, self->ec8, buf400, 0x400, mode, title, body);
        func_02046380(win);
        int found = 0;
        char* p = buf400;
        p += strlen(buf400);
        if (self->ebc == 0) {
            void* flags = Scenario_GetInstance();
            if (!Scenario_TestFlag((int)flags, (unsigned char*)((char*)flags + 0x8c), 0x119b)) {
                char* str = FindEntryByKey_02072a68((TableA68*)((char*)self + 0x278), 0x66);
                int len = strlen(str);
                memcpy(p, str, len);
                p += len;
                Scenario_SetFlag(flags, (unsigned char*)((char*)flags + 0x8c), 0x119b, 1);
            }
#if defined(jpn)
            unsigned char* var41;
            Struct_ov008_02189c70_6* var39;
            int var40;
            var41 = (unsigned char*)var9 + 0x3bc + 0x6c00;
#else
            Struct_ov008_02189c70_6* var39;
            int var40;
            unsigned char* var41 = (unsigned char*)var9 + 0x1fc + 0x7000;
#endif
            var39 = (Struct_ov008_02189c70_6*)(var41 + 4);
            Struct_ov008_02189c70_5 var42 = arg0->unknown_df0_;
            for (var40 = 0; var40 < *var41; var40++, var39++) {
                Struct_ov008_02189c70_5 var43 = var42;
                int var44;
                int var45;
                for (var45 = 0; var45 < 6; var45++) {
                    if (var43.unknown_0_[var45] != var39->unknown_0_.unknown_0_[var45]) {
                        var44 = 0;
                        goto compared;
                    }
                }
                var44 = 1;
            compared:
                if (var44) {
                    var39->unknown_14_ = arg0->unknown_e04_;
                    var39->unknown_18_ = arg0->unknown_e08_;
                    var39->unknown_1c_ = arg0->unknown_e0c_;
                    var39->unknown_20_ = arg0->unknown_e10_;
                    var39->unknown_24_ = arg0->unknown_e14_;
                    var39->unknown_28_ = arg0->unknown_e18_;
                    var39->unknown_2a_ = arg0->unknown_e1a_;
                    var39->unknown_2b_ = arg0->unknown_e1b_;
                    var34 = 1;
                    break;
                }
            }
            memset(var1, 0, 0x100);
            if (!var34) {
                char* var46 = func_02072a68((Struct_02072a68_2*)((char*)arg0 + 0x278), 0x64);
#if defined(jpn)
                MessageSystem_SetStringArgument((Obj02046574*)win, 0, name);
                func_020474a8(win, 0xc, str, buf100);
#else
                NameText_InitFromPartyMember(obj144, self->member);
                win->f10 = obj144;
                MessageSystem_FormatText(win, 0xc, str, buf100, 0xe3, 0, 1);
#endif
                memcpy(var35, var1, strlen(var1));
            }
        }
        if (!arg0->unknown_e1f_1_) var11->unknown_99c_ = 0; else var11->unknown_99c_ = 2;
        var11->unknown_19b2_ = 1;
#if defined(jpn)
        func_0204500c(var11, var0, 0);
#else
        func_0204500c(var11, var0, 0, 0xe3);
#endif
        var11->unknown_998_ = 1;
        var10->RemoveTask(arg0->unknown_eac_);
#if !defined(jpn)
        var10->RemoveTask(arg0->unknown_eb0_);
#endif
        arg0->unknown_eac_ = -1;
#if !defined(jpn)
        arg0->unknown_eb0_ = -1;
#endif
        if (self->ebc != 0) {
            if (self->ebc->active && LinkSession_IsHostOrSolo(token)) {
                self->state = 3;
            } else {
                arg0->unknown_e9a_ = 2;
            }
        } else if (var34) {
            arg0->unknown_e9a_ = 2;
        } else {
            arg0->unknown_e9a_ = 100;
        }
    } else if (arg0->unknown_e9a_ == 100) {
        if (var11->unknown_998_ != 0) return;
        if (func_020457e0(var11) == 0) {
            memset(var2, 0, 0x80);
            if (*((unsigned char*)var9 + LOW_REGION(0x6000 + 0xfbc,0x7000 + 0x1fc)) >= 0x10) {
                char* var47 = func_02072a68((Struct_02072a68_2*)((char*)arg0 + 0x278), 0x69);
                memcpy(var2, var47, strlen(var47));
                arg0->unknown_ebb_ = 1;
            } else {
#if defined(jpn)
                MessageSystem_SetStringArgument((Obj02046574*)win, 0, (char*)self + 0xdf2);
                char* str = FindEntryByKey_02072a68((TableA68*)((char*)self + 0x278), 0x68);
                func_020474a8(win, 0xc, str, buf80);
#else
                char* str = FindEntryByKey_02072a68((TableA68*)((char*)self + 0x278), 0x68);
                NameText_InitFromPartyMember(obj144, self->member);
                win->f10 = obj144;
                MessageSystem_FormatText(win, 0xc, str, buf80, 0xe3, 0, 1);
#endif
                func_ov008_0218b1e0(arg0);
            }
            if (!arg0->unknown_e1f_1_) var11->unknown_99c_ = 0; else var11->unknown_99c_ = 2;
            var11->unknown_19b2_ = 1;
#if defined(jpn)
            func_0204500c(var11, var2, 0);
#else
            func_0204500c(var11, var2, 0, 0xe3);
#endif
            var11->unknown_998_ = 1;
        }
        arg0->unknown_e9a_ = 2;
    } else if (arg0->unknown_e9a_ == 2) {
        if (var11->unknown_998_ != 0) return;
        if (func_020457e0(var11) == 0 && arg0->unknown_ebb_ != 0) {
            memcpy(var13->unknown_28_, &arg0->unknown_df0_, 0x2c);
            var13->unknown_9_ = 1;
            arg0->unknown_eba_ = 1;
        }
        Window_ClosePane((Entry_0205d6a0*)((char*)self + 0x18), 1);
        self->e99 = 2;
        self->state = 0;
        self->e9b = 2;
        self->e9c = 0;
    } else if (self->state == 3) {
        if (win->busy != 0) return;
        MapMeta02189c70 meta3 = self->ebc->meta;
        func_020a3720();
        ExportDetailedTreasureMapData((TreasureMapMetadata const*)&var50, (DetailedTreasureMapData*)&var3, 0, (unsigned char const*)0);
        func_020a395c();
#if defined(jpn)
        if (detail3.type == 1) {
            RegularMapNames02189c70* names = &detail3.names.regular;
            MessageSystem_SetStringArgument((Obj02046574*)win, 2, names->prefix);
            MessageSystem_SetStringArgument((Obj02046574*)win, 3, names->suffix);
            MessageSystem_SetStringArgument((Obj02046574*)win, 4, FindEntryByKey_02072a68((TableA68*)((char*)self + 0x278), 0xc8));
            MessageSystem_SetStringArgument((Obj02046574*)win, 5, names->level);
        } else if (detail3.type == 2) {
            LegacyMapNames02189c70* names = &detail3.names.legacy;
            MessageSystem_SetStringArgument((Obj02046574*)win, 2, names->name);
            MessageSystem_SetStringArgument((Obj02046574*)win, 3, names->suffix);
            MessageSystem_SetStringArgument((Obj02046574*)win, 5, names->level);
        } else {
            arg0->unknown_e9a_ = 2;
            return;
        }
#else
        if (var3.unknown_1_ == 1) {
            func_020464e8((char*)var11, 2, var3.unknown_af_);
        } else if (var3.unknown_1_ == 2) {
            func_020464e8((char*)var11, 2, var3.unknown_144_);
        } else {
            arg0->unknown_e9a_ = 2;
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
        func_020e4b34(obj144, clr3, clr3, 0, 0, 0, 0, self->ebc->flag2e, 0, 1, 0, 1);
        NameText_InitFromPartyMember(obj150, GameState_GetLeaderIndex(gs));
        win->f10 = obj144;
        win->f0 = obj150;
#endif
        if (func_02011804(var9) >= 0x63) {
#if defined(jpn)
            func_0204500c(var11, func_02072a68((Struct_02072a68_2*)((char*)arg0 + 0x278), 0xc9), 0);
#else
            func_0204500c(var11, func_02072a68((Struct_02072a68_2*)((char*)arg0 + 0x278), 0xc9), 0, 0xe3);
#endif
        } else {
#if defined(jpn)
            func_0204500c(var11, func_02072a68((Struct_02072a68_2*)((char*)arg0 + 0x278), 0xca), 0);
#else
            func_0204500c(var11, func_02072a68((Struct_02072a68_2*)((char*)arg0 + 0x278), 0xca), 0, 0xe3);
#endif
        }
        var11->unknown_998_ = 1;
        var11->unknown_19b2_ = 0;
        arg0->unknown_e9a_ = 4;
    } else if (arg0->unknown_e9a_ == 4) {
        if (var11->unknown_998_ != 0) return;
        if (func_02011804(var9) >= 0x63) {
#if defined(jpn)
            char* text = win->text;
            char* name = *(char**)((char*)gs->GetLeader() + 0x134);
            sprintf(text, FindEntryByKey_02072a68((TableA68*)((char*)self + 0x278), 0xcb), name);
            win->f2c8 = 1;
            func_0204500c(win, text, 0);
#else
            NameText_InitFromPartyMember(obj150, GameState_GetLeaderIndex(gs));
            win->f0 = obj150;
            win->f2c8 = 1;
#if defined(jpn)
            func_0204500c(var11, func_02072a68((Struct_02072a68_2*)((char*)arg0 + 0x278), 0xcb), 0);
#else
            func_0204500c(var11, func_02072a68((Struct_02072a68_2*)((char*)arg0 + 0x278), 0xcb), 0, 0xe3);
#endif
#endif
            var11->unknown_998_ = 1;
            var11->unknown_19b2_ = 1;
            arg0->unknown_e9a_ = 5;
        } else {
            func_020ac760(&var4);
            VectorizedMemset(&var4.unknown_2_[var4.unknown_0_], 0, 0x1c);
            Struct_ov008_02189c70_18* var56 = &arg0->unknown_ebc_->unknown_50_;
            Struct_ov008_02189c70_18* var57 = &var4.unknown_2_[var4.unknown_0_];
            var57->unknown_0_ = var56->unknown_0_;
            *(Struct_ov008_02189c70_17*)var57->unknown_1_ = *(Struct_ov008_02189c70_17*)var56->unknown_1_;
            *(Struct_ov008_02189c70_17*)var57->unknown_b_ = *(Struct_ov008_02189c70_17*)var56->unknown_b_;
            var57->unknown_15_ = var56->unknown_15_;
            var57->unknown_16_ = var56->unknown_16_;
            var57->unknown_17_ = var56->unknown_17_;
            var57->unknown_18_ = var56->unknown_18_;
            var57->unknown_1a_ = var56->unknown_1a_;
            var4.unknown_0_++;
            func_020ac734(&var4);
            arg0->unknown_ebc_->unknown_b_7_ = 0;
            arg0->unknown_e9a_ = 2;
        }
    } else if (arg0->unknown_e9a_ == 5) {
        if (var11->unknown_998_ != 0) return;
        int var58 = func_020457e0(var11);
        if (var58 == 0) {
            arg0->unknown_e9a_ = 2;
            return;
        }
        if (var58 != 1) return;
        Struct_ov008_02189c70_18 var59 = arg0->unknown_ebc_->unknown_50_;
        func_020a3720();
        ExportDetailedTreasureMapData((TreasureMapMetadata const*)&var59, (DetailedTreasureMapData*)&var5, 0, (unsigned char const*)0);
        func_020a395c();
        Struct_ov008_02189c70_4 var60;
        VectorizedMemset(&var60, 0, 0x28);
        var60.unknown_7_[0] = 0;
        var60.unknown_13_[0] = 0;
        var60.unknown_6_ = 0;
        var60.unknown_20_ = -1;
        var60.unknown_0_ = ((TreasureMapMetadata*)&var59)->GetMapType();
        var60.unknown_1_ = var59.unknown_17_;
        var60.unknown_2_ = var59.unknown_18_;
        var60.unknown_4_ = var59.unknown_1a_;
        var60.unknown_6_ = 0;
        strcpy(var60.unknown_7_, var59.unknown_1_);
        strcpy(var60.unknown_13_, var59.unknown_b_);
        var60.unknown_24_ = var59.unknown_16_;
        if (var60.unknown_0_ == 2) var60.unknown_26_ = var59.unknown_1a_;
        var60.unknown_20_ = var59.unknown_15_;
        func_02011818(var9, (Struct_02011818*)&var60);
#if defined(jpn)
        if (((TreasureMapMetadata*)&var59)->GetMapType() == 1) {
            Struct_ov008_02189c70_19* var61 = &var5.unknown_4c_.unknown_0_;
            func_02011ab8((char*)var9);
            func_02011a74((char*)var9, 0, var61->unknown_3b_);
            func_02011a74((char*)var9, 1, var61->unknown_5b_);
            func_02011a74((char*)var9, 2, func_02072a68((Struct_02072a68_2*)((char*)arg0 + 0x278), 0xc8));
            func_02011a74((char*)var9, 3, var61->unknown_9b_);
        } else if (((TreasureMapMetadata*)&var59)->GetMapType() == 2) {
            Struct_ov008_02189c70* var62 = &var5.unknown_4c_.unknown1_0_;
            func_02011ab8((char*)var9);
            func_02011a74((char*)var9, 0, var62->unknown_90_);
            func_02011a74((char*)var9, 1, var62->unknown_b0_);
            func_02011a74((char*)var9, 3, var62->unknown_d0_);
        }
#else
        if (((TreasureMapMetadata*)&var59)->GetMapType() == 1) {
            func_02011ab8((char*)var9);
            func_02011a74((char*)var9, 0, var5.unknown_af_);
        } else if (((TreasureMapMetadata*)&var59)->GetMapType() == 2) {
            func_02011a74((char*)var9, 0, var5.unknown_144_);
        }
#endif
        *(unsigned int*)((char*)var9 + LOW_REGION(0x61f4,0x6474)) = arg0->unknown_ebc_->unknown_10_ >> 2;
        func_ov017_021a9ff0(0);
        Window_ClosePane((Entry_0205d6a0*)((char*)self + 0x18), 1);
        self->state = 2;
    } else if (self->state == 6) {
        if (res->f3b4c->f2 != 0) return;
        Overlay_Load(OVERLAY_ID(8));
        self->ec0_b0 = 0;
        self->state = 7;
    } else if (self->state == 7) {
        void* obj = gs->GetLeader();
        if (obj != 0) GameObject_DisableControl((Obj020397cc*)obj, 1);
        if (*((unsigned char*)gs + LOW_REGION(0x6000 + 0x1ee,0x6000 + 0x46e)) != 0) {
            MapMeta02189c70 meta7 = self->ebc->meta;
            func_020a3720();
            ExportDetailedTreasureMapData((TreasureMapMetadata const*)&var64, (DetailedTreasureMapData*)&var6, 0, (unsigned char const*)0);
            func_020a395c();
    #if defined(jpn)
            if (detail7.type == 1) {
            RegularMapNames02189c70* names = &detail7.names.regular;
                MessageSystem_SetStringArgument((Obj02046574*)win, 2, names->prefix);
                MessageSystem_SetStringArgument((Obj02046574*)win, 3, names->suffix);
                MessageSystem_SetStringArgument((Obj02046574*)win, 4, FindEntryByKey_02072a68((TableA68*)((char*)self + 0x278), 0xc8));
                MessageSystem_SetStringArgument((Obj02046574*)win, 5, names->level);
            } else if (detail7.type == 2) {
            LegacyMapNames02189c70* names = &detail7.names.legacy;
                MessageSystem_SetStringArgument((Obj02046574*)win, 2, names->name);
                MessageSystem_SetStringArgument((Obj02046574*)win, 3, names->suffix);
                MessageSystem_SetStringArgument((Obj02046574*)win, 5, names->level);
            }
#else
        if (var6.unknown_1_ == 1) {
                func_020464e8((char*)var11, 2, var6.unknown_af_);
            } else if (var6.unknown_1_ == 2) {
                func_020464e8((char*)var11, 2, var6.unknown_144_);
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
            func_0204500c(var11, func_02072a68((Struct_02072a68_2*)((char*)arg0 + 0x278), 0xca), 0);
#else
            func_0204500c(var11, func_02072a68((Struct_02072a68_2*)((char*)arg0 + 0x278), 0xca), 0, 0xe3);
#endif
            var11->unknown_998_ = 1;
            var11->unknown_19b2_ = 0;
            arg0->unknown_ebc_->unknown_b_7_ = 0;
        }
        arg0->unknown_e9a_ = 2;
    }
}
