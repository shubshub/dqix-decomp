#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Graphics.h"
#include "NitroSDK/ColorEffects.h"

struct Struct_ov003_0217cf10_6 {
#if defined(jpn)
    char unknown_0_[0x868];
    int unknown_868_;
    char unknown_86c_[0x17e2 - 0x86c];
    unsigned char unknown_17e2_;
#else
    char unknown1_0_[0x998];
    int unknown_998_;
    char unknown_99c_[0x19b2 - 0x99c];
    unsigned char unknown_19b2_;
#endif
};

struct Struct_ov003_0217cf10_7 {
    unsigned char unknown_0_[0xb48];
    unsigned int unknown_b48_;
};

struct Struct_ov003_0217cf10_8 {
    unsigned char unknown_0_[0x1000];
    Struct_ov003_0217cf10_7 unknown_1000_;
};

struct Struct_ov003_0217cf10_9 {
#if defined(jpn)
    unsigned char unknown_0_[0x860];
#else
    unsigned char unknown1_0_[0x840];
#endif
    Struct_ov003_0217cf10_8 unknown_840_;
};

static inline unsigned int inline_ov003_0217cf10(Struct_ov003_0217cf10_7 *arg0) { return arg0->unknown_b48_; }
static inline bool inline_ov003_0217cf10_2(Struct_ov003_0217cf10_7 *arg0, unsigned int arg1) { return (inline_ov003_0217cf10(arg0) & arg1) != 0; }

struct Struct_ov003_0217cf10 {
    char unknown_0_[0x1c];
    unsigned char unknown_1c_0_ : 4;
    unsigned char unknown_1c_4_ : 4;
    unsigned char unknown_1d_;
    char unknown_1e_[2];
};

struct Struct_ov003_0217cf10_2 {
    Struct_ov003_0217cf10_2 *unknown_0_;
    Struct_ov003_0217cf10 *unknown_4_;
    char unknown_8_[0xc4 - 8];
    unsigned char unknown_c4_;
    char unknown_c5_[0xe0 - 0xc5];
};

struct Struct_ov003_0217cf10_3 {
    char unknown_0_[0x98];
    Struct_ov003_0217cf10 *unknown_98_;
    char unknown_9c_[0xb2 - 0x9c];
    unsigned char unknown_b2_;
};

struct Struct_ov003_0217cf10_4 {
    char unknown_0_[0x3c];
    int unknown_3c_;
    int unknown_40_;
    char unknown_44_[0x4c - 0x44];
    unsigned short unknown_4c_;
    char unknown_4e_[0x50 - 0x4e];
    unsigned char unknown_50_;
    char unknown_51_[0x54 - 0x51];
};

struct Struct_0201099c_3;

struct Struct_ov003_0217cf10_5 {
    unsigned char unknown_0_[4];
    unsigned char unknown_4_;
    signed char unknown_5_;
    char unknown_6_[0xc - 6];
    int unknown_c_;
#if !defined(jpn)
    int unknown_10_;
#endif
    char unknown_14_[0x18 - 0x14];
    unsigned char unknown_18_[0x18];
    unsigned char unknown_30_;
    char unknown_31_;
    unsigned char unknown_32_;
    char unknown_33_;
    int unknown_34_;
    int unknown_38_;
    Struct_ov003_0217cf10_4 unknown_3c_;
    Struct_ov003_0217cf10_3 *unknown_90_;
    Struct_ov003_0217cf10 *unknown_94_;
    Struct_ov003_0217cf10_2 *unknown_98_;
    void *unknown_9c_;
    SafeAllocator *unknown_a0_;
    SafeAllocator unknown_a4_;
    SafeAllocator unknown_b8_;
    char unknown_cc_[8];
};

struct Obj020397cc;
struct SePlayer;
struct ActiveEntry02046900;
struct Rec020467f0;
struct AllocTarget0204b12c;
struct Obj0204b5e8;
struct List0204b0e8;
struct Obj0204c7a8;
struct Struct_0205cf78;
struct Struct_0205cf78_2;

Messages0217cf10 *GetGlobalField0x1c020421a0();
extern "C" Zone0217cf10 *func_02012fe4(void);
void CancelPendingAction020397cc(Obj020397cc *obj, int flag);
void SePlayer_Play(SePlayer *obj, int a, int b);
const char *CallFunc020e0434With02153694_020e51cc(int key);
#if defined(jpn)
extern "C" void func_0204500c(Struct_ov003_0217cf10_6 *arg0, const char *arg1, int arg2);
#else
extern "C" void func_0204500c(Struct_ov003_0217cf10_6 *arg0, const char *arg1, int arg2, int arg3);
#endif
extern "C" int func_02046900(Struct_02020cb8_4 *arg0);
extern "C" void *func_020467f0(Struct_02020aec *arg0, int arg1, void **arg2, int *arg3);
extern "C" void func_0205a528(Struct_ov003_0217cf10_4 *arg0, void *arg1, int arg2, SafeAllocator *arg3);
extern "C" void func_0204b11c(unsigned char *arg0, int arg1);
extern "C" void func_0204b5b4(Struct_ov003_0217cf10 *arg0, int arg1);
extern "C" void func_0204b12c(Struct_0204b12c *arg0, SafeAllocator *arg1);
extern "C" void func_0204b5e8(Struct_02020cb8_5 *arg0, int arg1, int arg2);
extern "C" void func_0204b174(Struct_ov003_0217cf10 *arg0, void *arg1, SafeAllocator *arg2, int arg3);
extern "C" void func_0204bc74(Struct_ov003_0217cf10 *arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6);
extern "C" void func_0204b0e8(Struct_02020cb8_2 *arg0, void *arg1);
extern "C" void func_0204c7a8(Struct_0204c7a8 *arg0, SafeAllocator *arg1, int arg2, unsigned int arg3);
extern "C" void func_0205cf78(Struct_0205cf78 *arg0, Struct_0205cf78_2 *arg1, unsigned char arg2);
extern "C" void func_020dfec0(void *arg0, SafeAllocator *arg1, void *arg2, unsigned int arg3);
extern "C" const char *func_020e0434(Struct_0201099c_3 *arg0, int arg1);
extern "C" int func_020420e8(const char *arg0, int arg1);

extern SePlayer g_sePlayer;
extern char data_ov003_02180c2c[];
extern char data_ov003_02180c43[];
extern char data_ov003_02180c56[];
extern char data_ov003_02180c6f[];
#if defined(jpn)
extern char data_ov003_0217ee58[];
extern char data_ov003_0217ee8c[];
extern char data_ov003_0217eecc[];
extern char data_ov003_0217eee3[];
extern char data_ov003_0217eef6[];
#endif

// USA: func_ov003_0217cf10
#if defined(jpn)
extern "C" ARM void func_ov003_0217cf10(Struct_ov003_0217cf10_5 *arg0) {
    Struct_ov003_0217cf10_6 *var0 = func_020421a0();
    GameState *var1 = GameState::GetInstance();
    BackgroundLoader *var2 = BackgroundLoader::GetInstance();
    Struct_ov003_0217cf10_9 *var3 = func_02012fe4();
    Struct_ov003_0217cf10_8 *var4 = &var3->unknown_840_;
    int var5 = arg0->unknown_5_;

    if (step == 0) {
        CancelPendingAction020397cc((Obj020397cc *)gs->GetUnknownGameObject(), 1);
        msg->busy_ = 1;
        SePlayer_Play(&g_sePlayer, 1, 0);
        if (IsSeen(&save->progress_, 0xffffffff)) {
            func_0204500c(msg, data_ov003_0217ee58, 0);
            msg->flag19b2_ = 0;
            msg->busy_ = 1;
        } else {
            func_0204500c(var0, data_ov003_0217ee8c, 0);
            var0->unknown_17e2_ = 0;
            var0->unknown_868_ = 1;
            arg0->unknown_4_ = 1;
            arg0->unknown_5_ = 0;
            return;
        }
        int var6 = 1;
        for (int var7 = 1; var7 < 0x18; var7++) {
            if (var4->unknown_1000_.unknown_b48_ & (1 << var7)) {
                arg0->unknown_18_[var6] = var7;
                var6++;
            }
        }
        arg0->unknown_30_ = var6;
        arg0->unknown_32_ = (arg0->unknown_30_ - 1) / 6 + 1;
        arg0->unknown_3c_.unknown_50_ = 0;
        arg0->unknown_3c_.unknown_40_ = arg0->unknown_34_;
        arg0->unknown_3c_.unknown_4c_ = 7;
        arg0->unknown_3c_.unknown_3c_ = arg0->unknown_38_;
        arg0->unknown_c_ = var2->QueueLoadFile(data_ov003_0217eecc, 0);
        arg0->unknown_5_ = 1;
    } else if (var5 == 1) {
        if (var2->GetTaskStatus(arg0->unknown_c_) == 0) return;
        void *var8;
        void *var9;
        unsigned int var10;
        int var11;
        var2->GetLoadedFileByID(arg0->unknown_c_, &var9, &var10);
        int var12 = func_02046900((Struct_02020cb8_4 *)var9);
        for (int var13 = 0; var13 < var12; var13++) {
            void *var14 = func_020467f0((Struct_02020aec *)var9, var13, &var8, &var11);
            func_0205a528(&arg0->unknown_3c_, var14, var11, &arg0->unknown_b8_);
        }
        var2->RemoveTask(arg0->unknown_c_);
        arg0->unknown_c_ = -1;
        arg0->unknown_c_ = var2->QueueLoadFile(data_ov003_0217eee3, 0);
        arg0->unknown_5_ = 2;
    } else if (var5 == 2) {
        if (var2->GetTaskStatus(arg0->unknown_c_) == 0) return;
        func_0204b11c((unsigned char *)&arg0->unknown_94_[0], 0);
        arg0->unknown_94_[0].unknown_1c_0_ = 0;
        arg0->unknown_94_[0].unknown_1c_4_ = 1;
        func_0204b5b4(&arg0->unknown_94_[0], 0);
        func_0204b12c((Struct_0204b12c *)&arg0->unknown_94_[0], arg0->unknown_a0_);
        func_0204b5e8((Struct_02020cb8_5 *)&arg0->unknown_94_[0], 0, 0);
        BG1CNT = (BG1CNT & 0x43) | 0xd08;
        func_0204b11c((unsigned char *)&arg0->unknown_94_[1], 0);
        arg0->unknown_94_[1].unknown_1c_0_ = 0;
        arg0->unknown_94_[1].unknown_1c_4_ = 2;
        func_0204b5b4(&arg0->unknown_94_[1], 1);
        func_0204b12c((Struct_0204b12c *)&arg0->unknown_94_[1], arg0->unknown_a0_);
        func_0204b5e8((Struct_02020cb8_5 *)&arg0->unknown_94_[1], 0, 0);
        BG2CNT = (BG2CNT & 0x43) | 0xe08;
        void *var15;
        void *var16;
        void *var17[2];
        unsigned int var18;
        int var19[2];
        var2->GetLoadedFileByID(arg0->unknown_c_, &var16, &var18);
        int var20 = func_02046900((Struct_02020cb8_4 *)var16);
        for (int var21 = 0; var21 < var20; var21++) {
            var17[var21] = func_020467f0((Struct_02020aec *)var16, var21, &var15, &var19[var21]);
        }
        for (int var22 = 0; var22 < var20; var22++) {
            if (var17[var22] != 0) {
                func_0204b174(&arg0->unknown_94_[0], var17[var22], arg0->unknown_a0_, var19[var22]);
            }
        }
        var2->RemoveTask(arg0->unknown_c_);
        arg0->unknown_c_ = -1;
        func_0204bc74(&arg0->unknown_94_[0], 0, 0, 0, 0x20, 0x19, 0);
        func_0204b0e8((Struct_02020cb8_2 *)&arg0->unknown_94_[0], 0);
        func_0204bc74(&arg0->unknown_94_[1], 0, 0, 0, 0x20, 0x19, 0);
        func_0204b0e8((Struct_02020cb8_2 *)&arg0->unknown_94_[1], 0);
        arg0->unknown_9c_ = arg0->unknown_a0_->Allocate(0x2800);
        func_0204c7a8((Struct_0204c7a8 *)arg0->unknown_98_, arg0->unknown_a0_, (int)arg0->unknown_9c_, 0x800);
        arg0->unknown_98_->unknown_4_ = arg0->unknown_94_;
        arg0->unknown_98_->unknown_c4_ = 0;
        Struct_ov003_0217cf10_3 *var23 = arg0->unknown_90_;
        var23->unknown_98_ = arg0->unknown_94_;
        var23->unknown_b2_ = 2;
        func_0205cf78((Struct_0205cf78 *)arg0->unknown_90_, (Struct_0205cf78_2 *)arg0->unknown_98_, 1);
        BG0CNT = (BG0CNT & ~3) | 3;
        BG1CNT = (BG1CNT & ~3) | 1;
        BG2CNT = (BG2CNT & ~3) | 2;
        BG3CNT = (BG3CNT & ~3) | 0;
        ColorEffect_ConfigureAlphaBlend(0x04000050, 4, 1, 10, 6);
        arg0->unknown_c_ = var2->QueueLoadFile(data_ov003_0217eef6, 0);
        arg0->unknown_5_ = 3;
    } else if (var5 == 3) {
        if (var2->GetTaskStatus(arg0->unknown_c_) == 0) return;
        void *var24;
        unsigned int var25;
        var2->GetLoadedFileByID(arg0->unknown_c_, &var24, &var25);
        arg0->unknown_a4_.Reset();
        func_020dfec0(arg0->unknown_cc_, &arg0->unknown_a4_, var24, var25);
        var2->RemoveTask(arg0->unknown_c_);
        arg0->unknown_c_ = -1;
        DISPCNT = (DISPCNT & ~0x1f00) | 0x1700;
        arg0->unknown_4_ = 2;
        arg0->unknown_5_ = 0;
    }
}
#else
extern "C" ARM void func_ov003_0217cf10(Struct_ov003_0217cf10_5 *arg0) {
    Struct_ov003_0217cf10_6 *var26 = func_020421a0();
    GameState *var27 = GameState::GetInstance();
    BackgroundLoader *var28 = BackgroundLoader::GetInstance();
    Struct_ov003_0217cf10_9 *var29 = func_02012fe4();
    int var30 = arg0->unknown_5_;

    if (step == 0) {
        Save0217cf10 *save = &zone->save_;
        CancelPendingAction020397cc((Obj020397cc *)gs->GetUnknownGameObject(), 1);
        msg->busy_ = 1;
        SePlayer_Play(&g_sePlayer, 1, 0);
        if (IsSeen(&save->progress_, 0xffffffff)) {
            func_0204500c(msg, CallFunc020e0434With02153694_020e51cc(0x42), 0, 0xe3);
            msg->flag19b2_ = 0;
            msg->busy_ = 1;
        } else {
            func_0204500c(var26, func_020e51cc(0x43), 0, 0xe3);
            var26->unknown_19b2_ = 0;
            var26->unknown_998_ = 1;
            arg0->unknown_4_ = 1;
            arg0->unknown_5_ = 0;
            return;
        }
        int var32 = 1;
        for (int var33 = 1; var33 < 0x18; var33++) {
            if (var31->unknown_1000_.unknown_b48_ & (1 << var33)) {
                arg0->unknown_18_[var32] = var33;
                var32++;
            }
        }
        arg0->unknown_30_ = var32;
        arg0->unknown_32_ = (arg0->unknown_30_ - 1) / 6 + 1;
        arg0->unknown_3c_.unknown_50_ = 0;
        arg0->unknown_3c_.unknown_40_ = arg0->unknown_34_;
        arg0->unknown_3c_.unknown_4c_ = 7;
        arg0->unknown_3c_.unknown_3c_ = arg0->unknown_38_;
        arg0->unknown_c_ = var28->QueueLoadFile(data_ov003_02180c2c, 0);
        arg0->unknown_5_ = 1;
    } else if (var30 == 1) {
        if (var28->GetTaskStatus(arg0->unknown_c_) == 0) return;
        void *var34;
        void *var35;
        unsigned int var36;
        int var37;
        var28->GetLoadedFileByID(arg0->unknown_c_, &var35, &var36);
        int var38 = func_02046900((Struct_02020cb8_4 *)var35);
        for (int var39 = 0; var39 < var38; var39++) {
            void *var40 = func_020467f0((Struct_02020aec *)var35, var39, &var34, &var37);
            func_0205a528(&arg0->unknown_3c_, var40, var37, &arg0->unknown_b8_);
        }
        var28->RemoveTask(arg0->unknown_c_);
        arg0->unknown_c_ = -1;
        arg0->unknown_c_ = var28->QueueLoadFile(data_ov003_02180c43, 0);
        arg0->unknown_5_ = 2;
    } else if (var30 == 2) {
        if (var28->GetTaskStatus(arg0->unknown_c_) == 0) return;
        func_0204b11c((unsigned char *)&arg0->unknown_94_[0], 0);
        arg0->unknown_94_[0].unknown_1c_0_ = 0;
        arg0->unknown_94_[0].unknown_1c_4_ = 1;
        func_0204b5b4(&arg0->unknown_94_[0], 0);
        func_0204b12c((Struct_0204b12c *)&arg0->unknown_94_[0], arg0->unknown_a0_);
        func_0204b5e8((Struct_02020cb8_5 *)&arg0->unknown_94_[0], 0, 0);
        BG1CNT = (BG1CNT & 0x43) | 0xd08;
        func_0204b11c((unsigned char *)&arg0->unknown_94_[1], 0);
        arg0->unknown_94_[1].unknown_1c_0_ = 0;
        arg0->unknown_94_[1].unknown_1c_4_ = 2;
        func_0204b5b4(&arg0->unknown_94_[1], 1);
        func_0204b12c((Struct_0204b12c *)&arg0->unknown_94_[1], arg0->unknown_a0_);
        func_0204b5e8((Struct_02020cb8_5 *)&arg0->unknown_94_[1], 0, 0);
        BG2CNT = (BG2CNT & 0x43) | 0xe08;
        void *var41;
        void *var42;
        void *var43[2];
        unsigned int var44;
        int var45[2];
        var28->GetLoadedFileByID(arg0->unknown_c_, &var42, &var44);
        int var46 = func_02046900((Struct_02020cb8_4 *)var42);
        for (int var47 = 0; var47 < var46; var47++) {
            var43[var47] = func_020467f0((Struct_02020aec *)var42, var47, &var41, &var45[var47]);
        }
        for (int var48 = 0; var48 < var46; var48++) {
            if (var43[var48] != 0) {
                func_0204b174(&arg0->unknown_94_[0], var43[var48], arg0->unknown_a0_, var45[var48]);
            }
        }
        var28->RemoveTask(arg0->unknown_c_);
        arg0->unknown_c_ = -1;
        func_0204bc74(&arg0->unknown_94_[0], 0, 0, 0, 0x20, 0x19, 0);
        func_0204b0e8((Struct_02020cb8_2 *)&arg0->unknown_94_[0], 0);
        func_0204bc74(&arg0->unknown_94_[1], 0, 0, 0, 0x20, 0x19, 0);
        func_0204b0e8((Struct_02020cb8_2 *)&arg0->unknown_94_[1], 0);
        arg0->unknown_9c_ = arg0->unknown_a0_->Allocate(0x2800);
        func_0204c7a8((Struct_0204c7a8 *)arg0->unknown_98_, arg0->unknown_a0_, (int)arg0->unknown_9c_, 0x800);
        arg0->unknown_98_->unknown_4_ = arg0->unknown_94_;
        arg0->unknown_98_->unknown_c4_ = 0;
        Struct_ov003_0217cf10_3 *var49 = arg0->unknown_90_;
        var49->unknown_98_ = arg0->unknown_94_;
        var49->unknown_b2_ = 2;
        func_0205cf78((Struct_0205cf78 *)arg0->unknown_90_, (Struct_0205cf78_2 *)arg0->unknown_98_, 1);
        BG0CNT = (BG0CNT & ~3) | 3;
        BG1CNT = (BG1CNT & ~3) | 1;
        BG2CNT = (BG2CNT & ~3) | 2;
        BG3CNT = (BG3CNT & ~3) | 0;
        ColorEffect_ConfigureAlphaBlend(0x04000050, 4, 1, 10, 6);
        arg0->unknown_c_ = var28->QueueLoadFileInGP2(data_ov003_02180c56, data_ov003_02180c6f, 0);
        arg0->unknown_5_ = 3;
    } else if (var30 == 3) {
        if (var28->GetTaskStatus(arg0->unknown_c_) == 0) return;
        void *var50;
        unsigned int var51;
        var28->GetLoadedFileByID(arg0->unknown_c_, &var50, &var51);
        arg0->unknown_a4_.Reset();
        func_020dfec0(arg0->unknown_cc_, &arg0->unknown_a4_, var50, var51);
        var28->RemoveTask(arg0->unknown_c_);
        arg0->unknown_c_ = -1;
        int var52 = 0;
        for (int var53 = 0x64; var53 < 0x7c; var53++) {
            int var54 = 0;
            const char *var55 = func_020e0434((Struct_0201099c_3 *)arg0->unknown_cc_, (short)var53);
            if (var55 != 0) {
                var54 = func_020420e8(var55, 0);
            }
            if (var52 < var54) {
                var52 = var54;
            }
        }
        arg0->unknown_10_ = (var52 + 0x1b) & ~7;
        arg0->unknown_10_ = arg0->unknown_10_ >> 3;
        arg0->unknown_10_ = ((arg0->unknown_10_ + 1) & ~1) << 3;
        DISPCNT = (DISPCNT & ~0x1f00) | 0x1700;
        arg0->unknown_4_ = 2;
        arg0->unknown_5_ = 0;
    }
}
#endif
