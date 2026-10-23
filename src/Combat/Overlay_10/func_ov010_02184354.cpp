#include "Resource/ActionDataTables.h"
#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"
#include "Resource/MessageSystem.h"
#include "Resource/GameResources.h"

#if defined(jpn)
#define data_ov010_02184a80 data_ov010_02185b40
#define data_ov010_02184aa6 data_ov010_02185b54
#endif

extern AllocatorUnion data_02114e20;
extern int g_sePlayer;
extern const char data_ov010_02184a80[];
extern const char data_ov010_02184a95[];
extern const char data_ov010_02184aa6[];

struct Struct_ov010_021842d8;
extern "C" void func_ov010_021842d8(struct Struct_ov010_021842d8* arg0);

struct Struct_02018300_3;
extern "C" void func_020397cc(struct Struct_02018300_3* arg0, int arg1);
extern "C" void* func_02012d88(AllocatorUnion* arg0, unsigned int arg1);

struct Struct_020727d8 {
    void* unknown_0_;
    short unknown_4_;
    short unknown_6_;
};
extern "C" void func_020727d8(struct Struct_020727d8* arg0);
extern "C" void func_020728ac(void* arg0, void* arg1, void* arg2, int arg3, int arg4, int arg5, int arg6);

struct Struct_02072a68_2;
extern "C" void* func_02072a68(struct Struct_02072a68_2* arg0, int arg1);

struct SePlayer;
void SePlayer_Play(struct SePlayer* obj, int a, int b);
void SetForwardAndStore0205ebc0(void* obj, int a, int b);
void DispatchIfField0xc4NonNeg_0205ebfc(void* obj, int a, int b);
void ForwardField0xc0_0205ebec(void* obj);

struct Struct_0204bd7c;
extern "C" unsigned short func_0204bd7c(struct Struct_0204bd7c* arg0);

struct Struct_02099950 {
    unsigned short unknown_0_;
    unsigned char unknown_2_[0xc];
    unsigned char unknown_e_0_ : 2;
    unsigned char unknown_e_2_ : 4;
    unsigned char unknown_e_6_ : 2;
    unsigned char unknown_f_;
};
struct Struct_02095924_2;
extern "C" struct Struct_02099950* func_02099950(struct Struct_02095924_2* arg0, int arg1);

extern "C" void* func_02033fa0(void* arg0);
extern "C" void* func_02011584(void* arg0);
extern "C" int func_020100a8(GameState* arg0);
extern "C" void* func_020120a0(char* arg0, unsigned int arg1);
extern "C" unsigned char func_020100b0(GameState* arg0);

struct Struct_020340b4;
extern "C" void func_020340b4(struct Struct_020340b4* arg0);

extern "C" void func_020e4bf4(void* arg0, int arg1);
extern "C" void func_02046380(void* arg0);
extern "C" int func_020457e0(void* arg0);

struct Foo0207df50;
void CopyInternalFields0207df50(struct Foo0207df50* p);
void VramState_Restore(char* obj);
void VramState_Save(char* obj);

struct Struct_02057de0_2;
extern "C" void* func_02057924(void);
extern "C" int func_02057de0(struct Struct_02057de0_2* arg0, int arg1, SafeAllocator* arg2, int arg3, int arg4);
extern "C" int func_02057fb4(void* arg0, int arg1, void* arg2);

struct Vector3i;

extern "C" void* func_02079e2c(char* arg0, int arg1);

struct Struct_02048350_2;
extern "C" int func_02048350(struct Struct_02048350_2* arg0, int arg1);

extern "C" void* func_0202ae18(void);
extern "C" void* func_02012fe4(void);
extern "C" int func_0202c508(void* arg0);

struct Struct_ov010_02184354 { short unknown_0_; short unknown_2_; short unknown_4_; };
extern "C" void func_ov017_021d360c(int arg0, unsigned char arg1, int arg2, struct Struct_ov010_02184354 arg3);

struct Struct_ov010_02184354_2 {
    unsigned short unknown_0_;
    unsigned char unknown_2_[6];
    struct Struct_ov010_02184354_3* unknown_8_;
};
struct Struct_ov010_02184354_3 {
    unsigned char unknown_0_[0xc];
    unsigned char unknown_c_0_ : 4;
    unsigned char unknown_c_4_ : 4;
    unsigned char unknown_d_;
    unsigned char unknown_e_0_ : 6;
    unsigned char unknown_e_6_ : 1;
    unsigned char unknown_e_7_ : 1;
};

struct Struct_ov010_02184354_4 {
    unsigned char unknown_0_[0xc];
    unsigned char unknown_c_;
};
extern "C" Struct_02021b84* func_020421a0(void);

struct Struct_ov010_02184354_5 {
    unsigned char unknown_0_[8];
    unsigned int unknown_8_0_ : 8;
    unsigned int unknown_9_0_ : 24;
};

struct Struct_ov010_02184354_6 { int unknown_0_; int unknown_4_; int unknown_8_; };

struct Struct_ov010_02184354_7 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[0xf];
    unsigned char unknown_10_;
    unsigned char unknown_11_0_ : 1;
    unsigned char unknown_11_1_ : 1;
    unsigned char unknown_11_2_ : 1;
    unsigned char unknown_11_3_ : 1;
    unsigned char unknown_11_4_ : 1;
    unsigned char unknown_11_5_ : 1;
    unsigned char unknown_11_6_ : 1;
    unsigned char unknown_11_7_ : 1;
    short unknown_12_;
    short unknown_14_;
    short unknown_16_;
    short unknown_18_;
    short unknown_1a_;
    short unknown_1c_;
    short unknown_1e_;
    int unknown_20_; int unknown_24_; int unknown_28_;
    int unknown_2c_; int unknown_30_; int unknown_34_;
    int unknown_38_; int unknown_3c_; int unknown_40_;
    int unknown_44_; int unknown_48_; int unknown_4c_;
};

struct Struct_ov010_02184354_8 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned short unknown_2_;
    int unknown_4_;
    int unknown_8_;
    struct Struct_020727d8 unknown_c_;
    SafeAllocator unknown_14_;
};

// USA: func_ov010_02184354
extern "C" ARM int func_ov010_02184354(struct Struct_ov010_02184354_8* arg0) {
    BackgroundLoader* var0 = BackgroundLoader::GetInstance();
    Struct_02021b84* var1 = func_020421a0();
    GameState* var2 = GameState::GetInstance();
    GameObject* var3;
    struct Struct_ov010_02184354_2* var4;
#if defined(jpn)
    struct Struct_ov010_02184354_4* var5 = *(Struct_ov010_02184354_4**)((char*)GetGameResources() + 0x3988);
#else
    struct Struct_ov010_02184354_4* var5 = *(Struct_ov010_02184354_4**)((char*)GetGameResources() + 0x3ba8);
#endif
    var3 = var2->GetPartyMemberByIndex(var5->unknown_c_);
    GameObject* var6 = var2->GetPartyMemberByIndex(func_020100b0(var2));
    void* var7 = func_0202ae18();
    void* var8 = GetGameResources();
    var4 = (struct Struct_ov010_02184354_2*)func_02012fe4();
#if defined(jpn)
    char var9[200];
#endif

    if (var3 == NULL || var6 == NULL) {
        func_ov010_021842d8((struct Struct_ov010_021842d8*)arg0);
        return 1;
    }

    unsigned char var10 = arg0->unknown_0_;
    if (var10 == 0) {
        func_020397cc((struct Struct_02018300_3*)var6, 1);
        void* var11 = func_02012d88(&data_02114e20, 0x7800);
        if (var11 == NULL) {
            func_ov010_021842d8((struct Struct_ov010_021842d8*)arg0);
            return 1;
        }
        arg0->unknown_14_.CreateTypeA(var11, 0x7800);
#if defined(jpn)
        arg0->unknown_4_ = var0->QueueLoadFile(data_ov010_02184a80, NULL);
#else
        arg0->unknown_4_ = var0->QueueLoadFileInGP2(data_ov010_02184a80, data_ov010_02184a95, NULL);
#endif
        arg0->unknown_0_ = 1;
    } else if (var10 == 1) {
        if (var0->GetTaskStatus(arg0->unknown_4_) == 0) return 0;
        if (var0->GetDetailedTaskStatus(arg0->unknown_4_) != 2) {
            func_ov010_021842d8((struct Struct_ov010_021842d8*)arg0);
            return 1;
        }
        void* var12;
        unsigned int var13;
        var0->GetLoadedFileByID(arg0->unknown_4_, &var12, &var13);
        func_020727d8(&arg0->unknown_c_);
        func_020728ac(&arg0->unknown_c_, &arg0->unknown_14_, var12, var13, 0, 0, 0);
        var0->RemoveTask(arg0->unknown_4_);

        unsigned short* var14 = (unsigned short*)func_020120a0((char*)var2, func_020100a8(var2));
        if (var14 == NULL) {
            func_ov010_021842d8((struct Struct_ov010_021842d8*)arg0);
            return 1;
        }
        struct Struct_ov010_02184354_3* var15 = var4->unknown_8_;
        if (var15 == NULL) {
            func_ov010_021842d8((struct Struct_ov010_021842d8*)arg0);
            return 1;
        }

        unsigned char var16 = 1;
        arg0->unknown_1_ = var16;
        if (var15->unknown_c_0_ == 0) {
            void* var17 = func_02033fa0(var3);
            if (var17 != NULL) {
                struct Struct_02095924_2* var18 = (struct Struct_02095924_2*)func_02011584(var2);
                struct Struct_02099950* var19 = func_02099950(var18,
                    func_0204bd7c((struct Struct_0204bd7c*)var17));
                if (var19 != NULL) {
                    if (var19->unknown_e_2_ != 0) arg0->unknown_1_ = 0;
                }
            }
        } else {
            struct Struct_ov010_02184354_3* var20 = var4->unknown_8_;
            if (var20 != NULL) {
                if (var20->unknown_e_6_ == 0) var16 = 0;
                arg0->unknown_1_ = var16;
            }
        }

        int var21;
        if (arg0->unknown_1_ == 0) {
            arg0->unknown_0_ = 3;
            var21 = 2;
        } else if (*var14 != 0) {
            arg0->unknown_0_ = 2;
            var21 = 1;
        } else {
            key = 0;
            obj->state = 4;
            SePlayer_Play((struct SePlayer*)&g_sePlayer, 0x64, key);
        }

        void* var22 = func_02072a68((struct Struct_02072a68_2*)&arg0->unknown_c_, (short)var21);
#if defined(jpn)
        sprintf(var9, (const char*)var22, *(char**)((char*)var3 + 0x134));
        func_0204500c(var1, var9, 0);
        var1->unknown_998_ = 1;
#else
        struct Struct_ov010_02184354_6 var23;
        func_020e4bf4(&var23, var5->unknown_c_);
        func_02046380(var1);
        *(void**)var1 = &var23;
        func_0204500c(var1, (const char*)var22, 0, 0xe3);
        var1->unknown_998_ = 1;
#endif
    } else if (var10 == 2) {
#if defined(jpn)
        if (var1->unknown_998_ != 0) return 0;
#else
        if (var1->unknown_998_ != 0) return 0;
#endif
        if (func_020457e0(var1) == 0) {
            void* var24 = func_02072a68((struct Struct_02072a68_2*)&arg0->unknown_c_, 0);
#if defined(jpn)
            sprintf(var9, (const char*)var24, *(char**)((char*)var3 + 0x134));
            func_0204500c(var1, var9, 0);
            var1->unknown_998_ = 1;
#else
            struct Struct_ov010_02184354_6 var25;
            func_020e4bf4(&var25, var5->unknown_c_);
            func_02046380(var1);
            *(void**)var1 = &var25;
            func_0204500c(var1, (const char*)var24, 0, 0xe3);
            var1->unknown_998_ = 1;
#endif
            SePlayer_Play((struct SePlayer*)&g_sePlayer, 0x64, 0);
            unsigned short* slot = (unsigned short*)GetField0x74deForValidIndex_020120a0((char*)bs, GetField0x3acValue_020100a8(bs));
            if (slot != NULL) *slot = 0;
            obj->state = 4;
        } else {
            func_ov010_021842d8((struct Struct_ov010_021842d8*)arg0);
            return 1;
        }
    } else if (var10 == 4) {
        arg0->unknown_4_ = var0->QueueLoadFile(data_ov010_02184aa6, NULL);
        arg0->unknown_0_ = 5;
        arg0->unknown_2_ = 0;
    } else if (var10 == 5) {
        if (var0->GetTaskStatus(arg0->unknown_4_) == 0) return 0;
        if (var0->GetDetailedTaskStatus(arg0->unknown_4_) != 2) {
            func_ov010_021842d8((struct Struct_ov010_021842d8*)arg0);
            return 1;
        }
        if (arg0->unknown_2_ < 0xf) {
            arg0->unknown_2_ = arg0->unknown_2_ + 1;
            return 0;
        }
        SetForwardAndStore0205ebc0(&g_sePlayer, 0x74, 0x74);
        DispatchIfField0xc4NonNeg_0205ebfc(&g_sePlayer, 0, 0);

        void* var27;
        unsigned int var28;
        var0->GetLoadedFileByID(arg0->unknown_4_, &var27, &var28);

#if defined(jpn)
        char* var29 = (char*)var8 + 0x27c;
#else
        char* var29 = (char*)var8 + 0x2cc;
#endif
        struct Vec3i02184354 pos = *(struct Vec3i02184354*)((char*)caster + 0x44);
        CopyInternalFields0207df50((struct Foo0207df50*)(stage + 0xc40));
        VramState_Restore(stage + 0xc40);
        void* nodes = func_02057924();
        CreateAndRegisterNode02057de0((struct NodeList02057de0*)nodes, 0x11, &obj->alloc,
                                      (int)filePtr, (int)fileLen);
        VramState_Save(stage + 0xc40);

        struct Struct_ov010_02184354_6 var32;
        var32.unknown_0_ = 0x10a;
        var32.unknown_4_ = 0x10a;
        var32.unknown_8_ = 0x10a;

        struct Struct_ov010_02184354_7 var33;
        var33.unknown_0_ = 0;
        var33.unknown_10_ = 1;
        var33.unknown_12_ = 0;
        var33.unknown_14_ = -1;
        var33.unknown_16_ = -1;
        var33.unknown_18_ = -1;
        var33.unknown_1a_ = -1;
        var33.unknown_1c_ = -0x1000;
        var33.unknown_20_ = 0;
        var33.unknown_24_ = 0;
        var33.unknown_28_ = 0;
        var33.unknown_2c_ = 0;
        var33.unknown_30_ = 0;
        var33.unknown_34_ = 0;
        var33.unknown_38_ = 0;
        var33.unknown_3c_ = 0;
        var33.unknown_40_ = 0;
        var33.unknown_44_ = 0x1000;
        var33.unknown_48_ = 0x1000;
        var33.unknown_4c_ = 0x1000;
        var33.unknown_11_0_ = 0;
        var33.unknown_11_1_ = 0;
        var33.unknown_11_2_ = 1;
        var33.unknown_11_3_ = 0;
        var33.unknown_11_4_ = 0;
        var33.unknown_11_5_ = 0;
        var33.unknown_11_6_ = 0;
        var33.unknown_11_7_ = 0;

        *(Vector3i*)&var33.unknown_2c_ = *(Vector3i const*)&var30.unknown_0_;
        *(Vector3i*)&var33.unknown_44_ = *(Vector3i const*)&var32.unknown_0_;
        arg0->unknown_8_ = func_02057fb4(var31, 0x11, &var33);

        struct Struct_ov010_02184354 var34;
        var34.unknown_0_ = (short)(var30.unknown_0_ >> 4);
        var34.unknown_2_ = (short)(var30.unknown_4_ >> 4);
        var34.unknown_4_ = (short)(var30.unknown_8_ >> 4);

        if (func_0202c508(var7) != 0) {
            unsigned short* var35 = (unsigned short*)func_020120a0((char*)var2, func_020100a8(var2));
            if (var35 != NULL) {
                var35[0] = var4->unknown_0_;
                var35[1] = var34.unknown_0_;
                var35[2] = var34.unknown_2_;
                var35[3] = var34.unknown_4_;
            }
        }

        struct Struct_ov010_02184354_5* var36 =
            (struct Struct_ov010_02184354_5*)func_02079e2c((char*)func_020797dc(), 0xd2);
        if (var36 != NULL) {
            func_02048350((struct Struct_02048350_2*)var3, var36->unknown_8_0_);
        }
        GameObject* var37 = var2->GetUnknownGameObject();
        if (var37 != NULL) {
            func_020340b4((struct Struct_020340b4*)var37);
        }
        func_ov017_021d360c(0, func_020100a8(var2), var4->unknown_0_, var34);
        arg0->unknown_0_ = 3;
    } else if (var10 == 3) {
        GameState* var38 = GameState::GetInstance();
        int var39 = 0;
        if (arg0->unknown_1_ != 0) {
#if defined(jpn)
            if (var38->GetGameObjectByIndex(arg0->unknown_8_) == NULL && var1->unknown_998_ == 0) {
#else
            if (var38->GetGameObjectByIndex(arg0->unknown_8_) == NULL && var1->unknown_998_ == 0) {
#endif
                var39 = 1;
            }
        } else {
#if defined(jpn)
            if (var1->unknown_998_ == 0) var39 = 1;
#else
            if (var1->unknown_998_ == 0) var39 = 1;
#endif
        }
        if (finished != 0) {
            ResetStateAndCleanup021842d8((struct Struct021842d8*)obj);
            ForwardField0xc0_0205ebec(&g_sePlayer);
            return 1;
        }
    }
    return 0;
}
