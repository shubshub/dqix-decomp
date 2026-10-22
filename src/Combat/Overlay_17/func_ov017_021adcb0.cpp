#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "Resource/GameResources.h"
#include "World/LootableContainer.h"
#include "Resource/Brightness.h"
#include "Resource/TextQueue.h"

#if defined(jpn)
#define func_0205ec34 func_0205ff20
#define func_0206df6c func_0206f0c0
enum { Enum_ov017_021adcb0_10020 = 0x2764, Enum_ov017_021adcb0_10068 = 0x2794, Enum_ov017_021adcb0_96 = 0x2c, Enum_ov017_021adcb0_2400 = 0x800 };
extern const char* data_ov017_021d7f9c[];
extern const char* data_ov017_021d7fb4[];
extern char data_ov017_021d8068[], data_ov017_021d8082[], data_ov017_021d80ac[];
extern char data_ov017_021d80b0[], data_ov017_021d80b3[];
extern unsigned char data_ov017_021d6ec0[];
#else
enum { Enum_ov017_021adcb0_10020 = 0x2724, Enum_ov017_021adcb0_10068 = 0x2754, Enum_ov017_021adcb0_96 = 0x60, Enum_ov017_021adcb0_2400 = 0x960 };
#endif

struct Obj020397cc;
struct Obj02033834;
struct Obj02033b68;
struct Obj02086aec;
struct Obj020d7aa0;
struct BitFlags020d805c;
struct Struct0218d618;
struct SePlayer;
struct Obj02046574;
struct Obj021c2744;
struct TailList020469b4;
struct TailNode020469b4;
struct List02046a3c;
struct Node02046a3c;
struct GetElement02094d5cList;
struct Container020dedd0;

typedef LootableContainerManager::Container Container;

struct Struct_ov017_021adcb0_2 {
    char unknown_0_[0x16];
    unsigned char unknown_16_;
    unsigned char unknown_17_;
    char unknown_18_[4];
    unsigned short unknown_1c_;
};

struct Struct_ov017_021adcb0_3 {
    char unknown_0_[2];
    unsigned char unknown_2_;
    char unknown_3_[0xe];
    unsigned char unknown_11_;
    char unknown_12_[2];
    int unknown_14_;
    int unknown_18_;
};

struct Struct_ov017_021a7e14_4 {
    SafeAllocator unknown_0_; char unknown_14_[0x18]; Struct_0201099c_10* unknown_2c_;
    int unknown_30_; int unknown_34_;
};

struct Struct_ov017_021adcb0_4 {
    char unknown_0_[8];
    unsigned char unknown_8_;
    unsigned char unknown_9_;
    unsigned char unknown_a_;
    unsigned char unknown_b_;
    signed char unknown_c_;
    char unknown_d_;
    unsigned short unknown_e_;
    short unknown_10_;
    char unknown_12_[0xe];
    unsigned char unknown_20_;
    unsigned char unknown_21_;
    unsigned short unknown_22_;
    char unknown_24_[8];
    SafeAllocator unknown_2c_;
};

extern "C" void* func_020421a0(void);
extern "C" unsigned char* func_02012fe4(void);
extern "C" void* func_020d7a50(void);
extern "C" void func_ov017_021ae760(Struct_ov017_021adcb0_4* arg0);
extern "C" void func_ov017_0218d5ac(void* arg0);
extern "C" void* func_020100f8(char* arg0);
extern "C" void func_020a27a0(void* arg0);
extern "C" void func_020a2794(void* arg0);
extern "C" void func_02033834(Struct_02033834_2* arg0, int arg1);
extern "C" int* func_0202ae18(void);
extern "C" unsigned char* func_020177a8(unsigned char* arg0, int arg1);
extern "C" Container* func_02094d5c(Struct_02015ef4_3* arg0, int arg1);
extern "C" void* func_02010828(GameState* arg0);
extern "C" int func_0202b7d8(int* arg0);
extern "C" int func_0202c540(void* arg0);
extern "C" void func_020e4bf4(void* arg0, int arg1);
extern "C" int func_020e51cc(int arg0);
extern "C" void func_02046608(void* arg0, int arg1, int arg2, char* arg3, int arg4, int arg5, int arg6);
extern "C" void func_020397cc(Struct_02018300_3* arg0, int arg1);
extern "C" int func_020d805c(Struct_020d805c* arg0);
extern "C" void func_020d7aa0(Struct_020d7aa0_2* arg0);
extern "C" short func_02086aec(Struct_02053f7c* arg0, int arg1);
extern "C" int sprintf(char* arg0, const char* arg1, ...);
extern "C" void func_020113a8(void* arg0, int arg1, int arg2);
extern "C" void func_02033b68(Struct_02033b68* arg0, int arg1);
extern "C" void* func_02012d88(AllocatorUnion* arg0, unsigned int arg1);
extern "C" void func_ov017_0218d510(GameResources* arg0, SafeAllocator* arg1);
extern "C" void func_020397c0(void* arg0);
struct Struct_02015a98;
extern "C" void func_02015a98(Struct_02015a98*, int, int, int);
extern "C" void func_ov017_021cfd5c(unsigned char arg0, unsigned short arg1, unsigned short arg2);
extern "C" int func_ov017_0218d618(Struct_ov017_0218d618_2* arg0);
extern "C" void* memset(void* arg0, int arg1, unsigned int arg2);
extern "C" void* func_0205ec34(void);
extern "C" void func_ov017_021a9bc4(void* arg0, int arg1);
extern "C" void func_ov017_021a9a9c(void* arg0, int arg1, int arg2, int arg3, int arg4);
extern "C" void func_020469b4(Struct_0201bdac_2* arg0, Struct_0201bdac* arg1);
extern "C" void* func_020de824(void*);
extern "C" void func_0207cbe8(char*);
extern "C" int func_0207d538(void*, int, int, char*, int);
extern "C" void func_ov017_0218d644(GameResources*, Vector3fix*, int);
void ForwardField0xc0_0205eb80(void* obj);
void SetForwardAndStore0205eb54(void* obj, int arg1, int arg2);
void DispatchIfField0xc4NonNeg_0205eb90(void* obj, int a, int b);
void SePlayer_Play(SePlayer* obj, int a, int b);
extern "C" void func_0206df6c(void* unused, unsigned char* array, int bit, int value);
extern "C" void func_ov017_021cdb00(int, int, int, int);
extern "C" int func_ov017_0218d75c(void* arg0);
extern "C" void func_02046574(Struct_02046574_2* arg0, int arg1, char* arg2);
extern "C" void func_ov017_021c2744(Struct_ov017_021adcb0* arg0);
extern "C" void func_02046a3c(Struct_02046a3c_2* arg0, Struct_02046a3c* arg1);

extern char data_ov017_021d799c[];
extern char data_ov017_021d79a2[];
extern AllocatorUnion data_02114e20;
extern char g_sePlayer;
extern short data_ov017_021d6ac4[];
extern unsigned char data_ov017_021d6ac0[];

// USA: func_ov017_021adcb0
// JPN: func_ov017_021ae4b8
extern "C" ARM void func_ov017_021adcb0(Struct_ov017_021adcb0_4* arg0) {
    GameState* var0 = GameState::GetInstance();
    void* var1 = func_020421a0();
    unsigned char* var2 = func_02012fe4();
    LootableContainerManager* var3 = LootableContainerManager::GetMainInstance();
    Struct_02015ef4_3* var4 = (Struct_02015ef4_3*)(var2 + Enum_ov017_021adcb0_10020);
    void* var5 = func_020d7a50();
    GameObject* var6 = var0->GetPartyMemberByIndex(arg0->unknown_8_);
    GameResources* var7 = GetGameResources();
    Struct_0201bdac_2* var8 = (Struct_0201bdac_2*)var7->unknown_ptr_array_36fc[0];

    if (var6 == NULL) {
        func_ov017_021ae760(arg0);
        return;
    }
    if (var7) {
        func_ov017_0218d5ac(var7);
    }

    if (arg0->unknown_9_ == 0) {
        GameState* var9 = GameState::GetInstance();
        void* var10 = func_020100f8((char*)var9);
        if (var10) {
            func_020a27a0(var10);
        }
        if (var7) {
            SetFlags04(var7, 0x80);
        }
        *(unsigned short*)((char*)var6 + 0xb2) = 0;
        func_02033834((Struct_02033834_2*)var6, arg0->unknown_10_);
        int* var11 = func_0202ae18();
        Struct_ov017_021adcb0_2* var12 = (Struct_ov017_021adcb0_2*)func_020177a8(var2, arg0->unknown_a_);
        Container* var13 = NULL;
        if (var12) {
            if (arg0->unknown_20_) {
                var13 = func_02094d5c(var4, var12->unknown_1c_);
            } else {
                var13 = var3->GetContainerByID(var12->unknown_1c_, NULL);
            }
        }
        Struct_02053f7c* var14 = (Struct_02053f7c*)func_02010828(var9);
        if (func_0202b7d8(var11) && func_0202c540(var11) && var13 && var13->containerType == 0) {
#if !defined(jpn)
            char var15[0xc];
#endif
            char var16[0x50];
#if defined(jpn)
            sprintf(var16, data_ov017_021d7f9c[2], var6->baseStats_->unk);
            func_020d7e10(func_020d7a50(), var16, 0, 0, 1);
#else
            func_020e4bf4(var15, arg0->unknown_8_);
            *(char**)var1 = var15;
            func_02046608(var1, 0xc, func_020e51cc(0x28), var16, 0xe3, 0, 1);
            func_020d7e10(func_020d7a50(), var16, 0, 0, 1, 1);
#endif
            func_ov017_021ae760(arg0);
        } else if (var13 && var13->unk_4_0 != 0) {
            func_020397cc((Struct_02018300_3*)var6, 1);
            void* var17 = func_020d7a50();
            if (func_020d805c((Struct_020d805c*)var17)) {
                func_020d7aa0((Struct_020d7aa0_2*)var17);
            }
            int var18 = 0;
            int var19 = func_02086aec(var14, 0x561c);
            int var20 = func_02086aec(var14, 0x561a);
            int var21 = func_02086aec(var14, 0x561b);
            if (var19 > 0) {
                var18 = 1;
            } else if (var13->unk_4_0 == 1 && (var20 > 0 || var21 > 0)) {
                var18 = 1;
            } else if (var13->unk_4_0 == 2 && var21 > 0) {
                var18 = 1;
            }
            if (var18) {
#if defined(jpn)
                char var22[0x78];
                sprintf(var22, data_ov017_021d8068, data_ov017_021d7f9c[1], var6->baseStats_->unk);
                func_020d7e10(func_020d7a50(), var22, 0, 0, 1);
#else
                char var23[0x100];
                char var24[0xc];
                char var25[0x100];
                int var26 = func_020e51cc(0x29);
                sprintf(var25, data_ov017_021d799c, var26, func_020e51cc(0x2b));
                func_020e4bf4(var24, arg0->unknown_8_);
                *(char**)var1 = var24;
                func_02046608(var1, 0xc, (int)var25, var23, 0xe3, 0, 1);
                func_020d7e10(func_020d7a50(), var23, 0, 0, 1, 1);
#endif
                arg0->unknown_c_ = 0xf;
                arg0->unknown_9_ = 9;
            } else {
#if defined(jpn)
                char var27[0x78];
                if (var20 > 0 || var21 > 0) {
                    sprintf(var27, data_ov017_021d8082, data_ov017_021d7f9c[1]);
                } else {
                    sprintf(var27, data_ov017_021d80ac, data_ov017_021d7f9c[1]);
                }
                func_020d7e10(func_020d7a50(), var27, 0, 0, 1);
#else
                char var28[0x100];
                if (var20 > 0 || var21 > 0) {
                    int var29 = func_020e51cc(0x29);
                    sprintf(var28, data_ov017_021d799c, var29, func_020e51cc(0x2c));
                } else {
                    sprintf(var28, data_ov017_021d79a2, func_020e51cc(0x29));
                }
                func_020d7e10(func_020d7a50(), var28, 0, 0, 1, 1);
#endif
                arg0->unknown_e_ = 0;
                arg0->unknown_9_ = 8;
            }
        } else {
            func_020397cc((Struct_02018300_3*)var6, 1);
            if (arg0->unknown_20_) {
                func_020113a8(var9, *(unsigned short*)var2 % 20, arg0->unknown_a_);
            }
            func_02033b68((Struct_02033b68*)var6, 7);
            arg0->unknown_9_ = 1;
        }
        if ((arg0->unknown_9_ == 1 || arg0->unknown_9_ == 9) && var13 && var13->itemIDOrRank == 0x5617) {
            arg0->unknown_b_ = 1;
            arg0->unknown_2c_.ResetAllocatorPointer();
            arg0->unknown_2c_.CreateTypeA(func_02012d88(&data_02114e20, 0x4000), 0x4000);
            arg0->unknown_2c_.Reset();
            func_ov017_0218d510(GetGameResources(), &arg0->unknown_2c_);
        }
    } else if (arg0->unknown_9_ == 8) {
        arg0->unknown_e_ += var0->GetEffectiveDeltaTime();
        if (arg0->unknown_e_ > 0x2ee) {
            GameObject* var30 = var0->GetUnknownGameObject();
            if (var30) {
                func_020397c0(var30);
            }
            func_ov017_021ae760(arg0);
        }
    } else if (arg0->unknown_9_ == 9) {
        arg0->unknown_c_--;
        if (arg0->unknown_c_ <= 0) {
            func_02033b68((Struct_02033b68*)var6, 7);
            arg0->unknown_9_ = 1;
        }
    } else if (arg0->unknown_9_ == 1) {
        if (var6->obj3D_.normalizedAnimationTime_ >= 0x666) {
            Struct_ov017_021adcb0_2* var31 = (Struct_ov017_021adcb0_2*)func_020177a8(var2, arg0->unknown_a_);
            if (var31) {
                if (var31->unknown_17_ == 2 || var31->unknown_17_ == 1) {
                    func_02015a98((Struct_02015a98*)var31, var6->obj3D_.unknown_4_, 1, 1);
                } else {
                    func_02015a98((Struct_02015a98*)var31, var6->obj3D_.unknown_4_, 1, 0);
                }
            }
            func_ov017_021cfd5c(var6->obj3D_.unknown_4_, *(unsigned short*)var2, arg0->unknown_a_);
            arg0->unknown_9_ = 2;
        }
    } else if (arg0->unknown_9_ == 2) {
        if (var6->obj3D_.normalizedAnimationTime_ >= 0xb33) {
            if (arg0->unknown_b_ && !func_ov017_0218d618((Struct_ov017_0218d618_2*)GetGameResources())) {
                return;
            }
            if (!arg0->unknown_21_ && !arg0->unknown_b_) {
                GameObject* var32 = var0->GetUnknownGameObject();
                if (var32) {
                    func_020397c0(var32);
                }
                void* var33 = func_020100f8((char*)GameState::GetInstance());
                if (var33) {
                    func_020a2794(var33);
                }
                if (var7) {
                    ClearFlags04(var7, 0x80);
                }
            }
            arg0->unknown_9_ = 4;
        }
    } else if (arg0->unknown_9_ == 4) {
        var2 = func_02012fe4();
        Struct_ov017_021adcb0_2* var34 = (Struct_ov017_021adcb0_2*)func_020177a8(var2, arg0->unknown_a_);
        if (var34) {
            char* var35 = *(char**)((char*)var1 + Enum_ov017_021adcb0_96);
            memset(var35, 0, Enum_ov017_021adcb0_2400);
            int var36 = 0;
            if (var34) {
                func_0205ec34();
                unsigned short var37 = 0;
                Container* var38;
                if (arg0->unknown_20_) {
                    var38 = func_02094d5c(var4, var34->unknown_1c_);
                } else {
                    var38 = var3->GetContainerByID(var34->unknown_1c_, &var37);
                }
                if (var38) {
                    if (var38->lootType == 4) {
                        void* var39 = var7->unknown_ptr_array_3afc[0x1b];
                        func_ov017_021a9bc4(var39, 0);
                        func_ov017_021a9a9c(var39, 1, 0, 0, 0);
                        func_020469b4(var8, (Struct_0201bdac*)var39);
                        var36 = 1;
                    } else if (var38->lootType == 3) {
                        var36 = 1;
                        arg0->unknown_21_ = var36;
                        arg0->unknown_22_ = var38->itemIDOrRank;
                    } else {
                        Struct_ov017_021a7e14_4 var40;
                        var40.unknown_0_.ResetAllocatorPointer();
                        func_020de824(var40.unknown_14_);
                        func_0207cbe8((char*)&var40);
                        char var41[0x80] = {};
                        func_0207cbe8((char*)&var40);
                        var40.unknown_2c_ = (Struct_0201099c_10*)(var2 + Enum_ov017_021adcb0_10068);
                        if (func_0207d538(&var40, var38->lootType, var38->itemIDOrRank, var41, 1)) {
#if defined(jpn)
                            sprintf(var35, data_ov017_021d80b0, var41);
#else
                            sprintf(var35, data_ov017_021d79a2, var41);
#endif
                            var36 = 1;
                        }
                    }
                }
            }
            if (!var36) {
#if defined(jpn)
                sprintf(var35, data_ov017_021d80b3);
#else
                sprintf(var35, (char*)func_020e51cc(0x2d));
#endif
            }
        }
        Struct_ov017_021adcb0_2* var42 = (Struct_ov017_021adcb0_2*)func_020177a8(var2, arg0->unknown_a_);
        if (var42) {
            LootableContainerManager* var43 = LootableContainerManager::GetMainInstance();
            unsigned short var44 = 0;
            Container* var45;
            if (arg0->unknown_20_) {
                var45 = func_02094d5c(var4, var42->unknown_1c_);
            } else {
                var45 = var43->GetContainerByID(var42->unknown_1c_, &var44);
            }
            if (var45) {
                GameResources* var46 = GetGameResources();
                if (arg0->unknown_b_) {
                    func_ov017_0218d644(var46, &var45->position, 0);
                }
                int var47 = var45->lootType;
                if (var47 != 4) {
#if defined(jpn)
                    func_020d7e10(var5, *(char**)((char*)var1 + Enum_ov017_021adcb0_96), var47 == 2, var45->lootType == 2, 0);
#else
                    func_020d7e10(var5, *(char**)((char*)var1 + Enum_ov017_021adcb0_96), var47 == 2, var45->lootType == 2, 0, 0);
#endif
                    if (self->ambush) {
                        ForwardField0xc0_0205eb80(&g_sePlayer);
                        SetForwardAndStore0205eb54(&g_sePlayer, 0x15e, 0x15e);
                        DispatchIfField0xc4NonNeg_0205eb90(&g_sePlayer, 0, 0);
                    } else if (chest->lootType != 0 && chest->itemIDOrRank != 0x5617) {
                        SePlayer_Play((SePlayer*)&g_sePlayer, 0xe, 0);
                    }
                }
                int var48 = var45->uniqueID;
                unsigned char* var49 = (unsigned char*)func_0205ec34();
                if (var45->containerType == 0) {
                    func_0206df6c(var49, var49 + 0x8c, var48 + 0x212, 1);
                    func_ov017_021cdb00(1, var48, 1, -1);
                } else if (!arg0->unknown_20_) {
                    func_0206df6c(var49, var49 + 0x8c, var48 + 0x79e, 1);
                }
                var45->unk_4_0 = 0;
                var45->lootType = 0;
            }
        }
        arg0->unknown_9_ = 5;
    } else if (arg0->unknown_9_ == 5) {
        if (arg0->unknown_b_) {
            if (!func_ov017_0218d75c(GetGameResources())) {
                GameObject* var50 = var0->GetUnknownGameObject();
                if (var50) {
                    func_020397c0(var50);
                }
                func_ov017_021ae760(arg0);
            }
        } else if (arg0->unknown_21_) {
            arg0->unknown_9_ = 6;
        } else {
            func_ov017_021ae760(arg0);
        }
    } else if (arg0->unknown_9_ == 6) {
        Struct_ov017_021adcb0_3* var51 = (Struct_ov017_021adcb0_3*)var7->unknown_ptr_array_3afc[0x2c];
        if (var51->unknown_2_ == 0) {
            Struct_ov017_021adcb0_2* var52 = (Struct_ov017_021adcb0_2*)func_020177a8(var2, arg0->unknown_a_);
            if (var52) {
                var52->unknown_16_ = 0;
            }
            char var53[0x78];
            var53[0] = 0;
#if defined(jpn)
            const char** var54 = data_ov017_021d7fb4;
            const unsigned char* var56 = data_ov017_021d6ec0;
#else
            const short* var55 = data_ov017_021d6ac4;
            const unsigned char* var56 = data_ov017_021d6ac0;
#endif
            for (int var57 = 0; var57 < 3; var57++) {
                unsigned char var58 = var56[var57];
                if (var58 == arg0->unknown_22_) {
#if defined(jpn)
                    sprintf(var53, data_ov017_021d7f9c[0], var54[var57]);
#else
                    func_02046574((Struct_02046574_2*)var1, 0, (char*)func_020e51cc(var55[var57]));
                    func_02046608(var1, 0xc, func_020e51cc(0x2a), var53, 0xe3, 0, 1);
#endif
                }
            }
#if defined(jpn)
            func_020d7e10(func_020d7a50(), var53, 0, 0, 1);
#else
            func_020d7e10(func_020d7a50(), var53, 0, 0, 1, 1);
#endif
            func_ov017_021c2744((Struct_ov017_021adcb0*)var51);
            var51->unknown_14_ = var6->obj3D_.unknown_4_;
            var51->unknown_11_ = 1;
            var51->unknown_18_ = arg0->unknown_22_;
            func_02046a3c((Struct_02046a3c_2*)var8, (Struct_02046a3c*)var51);
        }
        func_ov017_021ae760(arg0);
    }
}
