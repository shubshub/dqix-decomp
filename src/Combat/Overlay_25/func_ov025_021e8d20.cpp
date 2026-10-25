#include "Resource/ActionDataTables.h"
#include <globaldefs.h>
#include "std_library_functions.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

extern "C" void* func_ov000_02160130();
extern "C" void* func_ov000_02160f20(void* arg0);
struct Struct_ov000_0215440c_2;
extern "C" void* func_ov000_02160094(Struct_ov000_0215440c_2*, int);
struct Struct_ov000_0215440c;
extern "C" void* func_ov000_021600f8(Struct_ov000_0215440c*, int);
struct GameState;
void* GetCombatantWithFlag0x400_0200fea4(GameState*, int);
void SePlayer_LoadExtraArchiveB(void* obj, int a, int b);
void ForwardToTargetOrDefault0205eabc(void* obj, void* target, int arg);
void* SearchBothTables02079e2c(char*, int);
int SetSlotEntryNoFlag_021eb42c(void* self, short b, short c);
int SetSlotEntry_021eb148(void*, short, int, unsigned char);
extern "C" void* func_ov000_0215ffa0(void* node);
void* FindNodeAtDepth0215fff4(void* node, int limit, int idx);
extern "C" int func_ov000_0215fd90(void* obj, int flag);
void InitQueueStruct_021ed124(unsigned char* obj);
void InitContainer_021ebab4(char* obj);
void SetIntField360_021ed31c(char*, int);
void SetName021ed324(void* obj, const char* name);
void SetIntField356_021ed314(char*, int);
struct Struct0216fe48;
void ResetStruct0216fe48(Struct0216fe48*);
struct Struct0216fd0c;
void SetField0FromCallFunc0202fa38(Struct0216fd0c*);
#if defined(jpn)
struct SafeAllocator;
extern int data_ov025_021efb88;
#else
#endif
extern "C" void* func_ov000_02160f08(void* arg0);
extern "C" short* func_ov025_021dafd0(char*, int);
extern "C" void func_ov025_021ded50(void* arg0, void* arg1);

extern int data_ov025_021ef990;
extern int data_ov025_021ef9a4;
extern int data_ov025_021ef9c0;
extern int g_sePlayer;
extern int data_ov025_021ef9a8[6];
extern int data_ov025_021ef8b4;
extern int data_ov025_021ef8ca;

static inline int inline_ov000_0215f57c(int arg0) {
    return arg0 >= 0xc0 && arg0 <= 0xc7;
}

#if defined(jpn)
enum { Enum_ov025_021e8d20_20 = 0x8 };
#else
enum { Enum_ov025_021e8d20_20 = 0x14 };
#endif

struct Struct_ov000_021700dc {
    unsigned short unknown_0_;
    short unknown_2_;
    short unknown_4_;
    short unknown_6_;
    char unknown_8_;
    unsigned char unknown_9_;
    char unknown_a_[2];
    unsigned char unknown_c_0_ : 1;
    unsigned char unknown_c_1_ : 1;
    unsigned char unknown_c_2_ : 1;
    unsigned char unknown_c_3_ : 1;
    unsigned char unknown_c_4_ : 1;
    unsigned char unknown_c_5_ : 1;
    char unknown_d_[3];
    struct Struct_ov000_0215b278* unknown_10_;
};

struct Struct_ov000_0215b278 {
    char unknown_0_[0x20];
    unsigned short unknown_20_;
    char unknown_22_[10];
    unsigned char unknown_2c_;
    char unknown_2d_[3];
    struct Struct_ov000_0215b278* unknown_30_;
};

struct Entry {
    char unknown_0_[0x14];
    unsigned int unknown_14_;
    unsigned int unknown_18_;
    unsigned int unknown_1c_;
    unsigned int unknown_20_0_ : 10;
};

struct Struct_ov014_02185c90_4 {
    short unknown_0_;
    short unknown_2_;
    short unknown_4_;
};

struct Struct_ov000_0215ab88 {
    char unknown_0_[2];
    short unknown_2_;
    char unknown_4_[0x134];
    char* unknown_138_;
    char unknown_13c_[Enum_ov025_021e8d20_20];
    char* unknown_150_;
};

// USA: func_ov025_021e8d20
extern "C" ARM void func_ov025_021e8d20(char* arg0, char* arg1) {
    char* var0;
    int var1;
    int var2;
    void* var3 = GameState::GetInstance();
    Struct_02108e10* var4 = func_020797dc();
    void* var5 = func_ov000_02160130();
    Struct_ov000_021700dc* var6 = (Struct_ov000_021700dc*)func_ov000_02160f20(var5);
    *(char**)arg0 = arg1;
    *(int*)(arg0 + 4) = *(int*)(arg1 + 8);
    int var7 = 0;
    data_ov025_021ef9a4 = 0;
    data_ov025_021ef990 = 0;
    data_ov025_021ef9c0 = 0;
    *(int*)(self + 0x1c4) = 0;
    *(int*)(self + 0x1d8) = 0;
    *(short*)(self + 0x21c) = 1;
    *(short*)(self + 0x21e) = 0;
    *(short*)(self + 0x220) = 0x1e;
    *(short*)(self + 0x222) = -1;
    self[0x5ca] = 0;
    self[0x5cb] = 0;
    self[0x5cc] = 0;
    self[0x5d0] = 0;
    self[0x5d1] = 0;
    *(int*)(self + 0x5e4) = 0;
    Node* first = (Node*)GetNodeAtIndex02160094((List02160094*)slot, 0);
    if (first != 0) {
        if (InRange(first->id)) {
            flag = 1;
            void* obj = ((GameState*)gs)->GetGameObjectByIndex(first->id);
            if (obj != 0) {
                int a = ((Object3D*)obj)->GetField78();
                int b = ((Object3D*)obj)->GetField7a();
                SePlayer_LoadExtraArchiveB(&g_sePlayer, a, b);
            }
        }
    }
    if (var6->unknown_0_ == 1 || var6->unknown_0_ == 2) {
        *(int*)(arg0 + 0x224) = 1;
    } else {
        *(int*)(arg0 + 0x224) = 0;
    }
    Entry* var12 = (Entry*)func_02079e2c((char*)var4, (short)var6->unknown_0_);
    *(Entry**)(arg0 + 8) = var12;
    if ((var12 != 0 && ((var12->unknown_18_ << 16) >> 28) == 2) || var6->unknown_0_ == 0x1f8 || var6->unknown_0_ == 0x392) {
        int var13 = 0;
        func_ov000_02160094((Struct_ov000_0215440c_2*)var6, var13);
        Struct_ov000_0215b278* var14 = (Struct_ov000_0215b278*)func_ov000_02160094((Struct_ov000_0215440c_2*)var6, var13);
        if (var14->unknown_20_ <= 3) var13 = 1;
        if (var13 != 0) {
            func_ov025_021eb42c(arg0, 4, 0x14);
            *(int*)(arg0 + 0x1c4) |= 2;
        } else {
            func_ov025_021eb42c(arg0, 4, 0x6f);
        }
    }
    for (int var15 = 0; var15 < var6->unknown_9_; var15++) {
        char* var16 = (char*)func_ov000_021600f8((Struct_ov000_0215440c*)var6, var15);
        if (var16 == 0) continue;
        unsigned char* var17 = (unsigned char*)var16 + 0x14;
        int var18 = 1;
        for (; var18 < (unsigned char)var16[0x17]; var18++) {
            int var19 = var17[var18];
            if (var19 == 3) {
                unsigned short var20 = *(unsigned short*)(var16 + (var18 - 1) * 2 + 0xe);
                int var21 = var20 <= 3 ? 1 : 0;
                if (var21 == 0) {
                    Struct_ov000_0215ab88* var22 = (Struct_ov000_0215ab88*)func_0200fea4((GameState*)var3, var20);
                    if (var22 != 0 && var22->unknown_2_ == 0xf4) {
                        func_ov025_021eb148(arg0, 0x1a, 0xcfe5, 1);
                    }
                    var7 = 1;
                } else {
                    func_ov025_021eb42c(arg0, 0x22, 1);
                }
            } else if (var19 == 2) {
                func_ov025_021eb148(arg0, 0x20, 0x2c6, 3);
            } else if (!(var19 != 5 && var19 != 4)) {
                short var23 = *(short*)(var16 + (var18 - 1) * 2 + 0xe);
                var1 = 0;
                if (var23 >= 0) var1 = var23 <= 3;
                if (var1 == 0) var7 = 1;
                func_ov025_021eb148(arg0, 0x23, 0x4d8, 3);
            }
        }
        {
            void* var24 = func_ov000_0215ffa0(var16);
            Struct_ov000_0215ab88* var25 = (Struct_ov000_0215ab88*)((GameState*)var3)->GetCombatantByIndex((int)var24);
            if (var25 != 0 && (*(unsigned int*)(var25->unknown_138_ + 0x18) & 0x20)) {
                func_ov025_021eb148(arg0, 0x1f, 0xb2c, 3);
                *(short*)(arg0 + 0x21c) = 0x1f;
            }
        }
        for (int var26 = 0; var26 < 3; var26++) {
            var2 = (unsigned char)var26;
            int var27 = 0;
            var0 = var16 + var26;
            for (; var27 < (unsigned char)var0[0x18]; var27++) {
                void* var28 = func_ov000_0215fff4(var16, var27, var2);
                if (var28 != 0 && var28 != 0) {
                    if (func_ov000_0215fd90(var28, 0xd)) {
                        func_ov025_021eb42c(arg0, 0x1b, 0x3c);
                    }
                    if (func_ov000_0215fd90(f, 0xc)) {
                        SetSlotEntry_021eb148(self, 0x19, 0x38e, 2);
                    } else if (func_ov000_0215fd90(f, 6) == 0) {
                        ForwardToTargetOrDefault0205eabc(&g_sePlayer, 0, 0);
                        if (((unsigned char*)f)[0x1c] != 0 && flag != 0) {
                            unsigned int t = slot->type;
                            if (t == 0xf4 || t == 0xf5 || t == 0x48 || t == 0x70) {
                                SetSlotEntryNoFlag_021eb42c(self, 0x24, 0xb);
                            }
                        }
                    }
                }
            }
        }
    }
    memset(arg0 + 0x1c8, 0, 0x10);
    data_ov025_021ef9a8[0] = 0;
    data_ov025_021ef9a8[1] = -1;
    data_ov025_021ef9a8[2] = 0;
    data_ov025_021ef9a8[3] = 0;
    data_ov025_021ef9a8[4] = 0;
    data_ov025_021ef9a8[5] = 0;
    func_ov025_021ed124((unsigned char*)(arg0 + 0x5e8));
    func_ov025_021ebab4(arg0 + 0x22c);
    *(char**)(arg0 + 0x538) = arg0 + 0x5e8;
    *(int*)(arg0 + 0x540) = 0;
    *(int*)(arg0 + 0x544) = 0;
    *(int*)(arg0 + 0x548) = 0;
    *(int*)(arg0 + 0x54c) = 0;
    *(int*)(arg0 + 0x550) = 0;
    *(short*)(arg0 + 0x554) = -1;
    *(short*)(arg0 + 0x556) = -1;
    *(int*)(arg0 + 0x558) = 0;
    *(short*)(arg0 + 0x55c) = -1;
    *(short*)(arg0 + 0x55e) = -1;
    *(int*)(arg0 + 0x560) = 0;
    *(short*)(arg0 + 0x564) = 0;
    *(short*)(arg0 + 0x566) = 0;
    *(short*)(arg0 + 0x568) = 0;
    *(short*)(arg0 + 0x56c) = 0;
    *(short*)(arg0 + 0x56a) = 0;
    *(short*)(arg0 + 0x572) = 0;
    *(short*)(arg0 + 0x570) = 0;
    *(short*)(arg0 + 0x56e) = 0;
    arg0[0x574] = 0;
    arg0[0x575] = 0;
    arg0[0x578] = 0;
    var12 = (Entry*)func_02079e2c((char*)var4, (short)var6->unknown_0_);
    if (var12 != 0) {
        unsigned int var30 = var12->unknown_14_ >> 28;
        if (!(var30 != 3 && var30 != 4)) {
            if (((var12->unknown_18_ << 20) >> 25) == 1) arg0[0x53d] = 1;
        }
    }
    if (var6->unknown_0_ == 1 && var8 != 0) {
        Struct_ov000_0215ab88* var31 = (Struct_ov000_0215ab88*)(void*)func_0200ff1c((GameState*)var3, var8->unknown_20_);
        if (var31 != 0) {
            char* var32 = var31->unknown_150_ + 0x294;
            if (var32 != 0) {
                unsigned int var33 = (*(unsigned int*)(var32 + 8) << 23) >> 27;
                if (var33 == 4 || var33 == 10) arg0[0x53d] = 1;
            }
        }
    }
    if ((var6->unknown_c_1_ && var6->unknown_c_2_) || (var6->unknown_c_4_ && var6->unknown_c_5_)) {
        arg0[0x5d0] = 1;
    }
    func_ov025_021ed31c(arg0 + 0x5e8, (int)(arg0 + 0x798));
    func_ov025_021ed324(arg0 + 0x5e8, 0);
    func_ov025_021ed314(arg0 + 0x5e8, (int)var6);
    func_ov000_0216fe48((Struct_ov000_0216fe48*)(arg0 + 0x798));
    func_ov000_0216fd0c((Struct_ov000_0216fd0c*)(arg0 + 0x798));
    arg0[0x87c] = 0;
    *(int*)(arg0 + 0x880) = -1;
    void* var34 = BackgroundLoader::GetInstance();
    int var35 = 0;
    Struct_ov000_0215b278* var36 = (Struct_ov000_0215b278*)func_ov000_02160094((Struct_ov000_0215440c_2*)var6, 0);
    void* var37 = func_ov000_02160f08(var5);
    short* var38 = 0;
    if (var36 != 0) var38 = func_ov025_021dafd0((char*)var37, var36->unknown_20_);
    if (var38 != 0) var35 = var38[0x2c / 2];
    if (var6->unknown_4_ != 0) var35 = var6->unknown_4_;
    if (var35 > 0) {
        if (var35 == *(int*)(arg0 + 0x884)) {
            func_ov025_021ed324(arg0 + 0x5e8, arg0 + 0x83c);
#if !defined(jpn)
            *(short*)(arg0 + 0x794) = var35;
#endif
            arg0[0x87c] = 1;
        } else {
            *(int*)(arg0 + 0x884) = var35;
#if defined(jpn)
            *(int*)(arg0 + 0x880) = ((BackgroundLoader*)var34)->QueueLoadFile((const char*)&data_ov025_021efb88, (SafeAllocator*)0);
#else
            *(int*)(arg0 + 0x880) = ((BackgroundLoader*)var34)->QueueLoadFileInGP2((const char*)&data_ov025_021ef8b4, (const char*)&data_ov025_021ef8ca, (SafeAllocator*)0);
#endif
            if (*(int*)(arg0 + 0x880) < 0) arg0[0x87c] = 1;
        }
    } else {
        *(int*)(arg0 + 0x884) = 0;
        arg0[0x87c] = 1;
        func_ov025_021ed324(arg0 + 0x5e8, 0);
    }
    for (Struct_ov000_0215b278* var39 = var6->unknown_10_; var39 != 0; var39 = var39->unknown_30_) {
        void* var40 = ((GameState*)var3)->GetCombatantByIndex(var39->unknown_20_);
        if (var40 != 0) {
            ((Object3D*)var40)->EnableFlag(0x800);
            if (var39->unknown_2c_ != 0) {
                int var41 = var39->unknown_20_ <= 3 ? 1 : 0;
                if (var41 != 0) {
                    void* var42 = func_02079e2c((char*)var4, 0x39a);
                    if (var42 != 0) {
                        Struct_ov014_02185c90_4 var43;
                        var43.unknown_0_ = var39->unknown_20_;
                        var43.unknown_2_ = 0x39a;
                        var43.unknown_4_ = ((Entry*)var42)->unknown_20_0_;
                        func_ov025_021ded50(var5, &var43);
                    }
                }
            }
        }
    }
    *(short*)(arg0 + 0x57c) = 0;
    *(short*)(arg0 + 0x57e) = 0;
    *(short*)(arg0 + 0x580) = 0x333;
    arg0[0x582] = 0;
    arg0[0x5c5] = 0;
    arg0[0x5c6] = 0;
    *(int*)(arg0 + 0x228) = 0;
    *(short*)(arg0 + 0x5c8) = 0xff;
    *(short*)(arg0 + 0x5ce) = 0;
}
