#include "Combat/MenuNodeChain.h"
#include "Combat/MapDisplay.h"
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "Resource/Brightness.h"
#include "NitroSDK/Graphics.h"
#include "NitroSDK/ColorEffects.h"
#include "Input/Input.h"
#include "Resource/GameResources.h"

#if defined(jpn)
#define func_02046c78 func_02047a98
#endif

struct AllocatorUnion;
struct Obj02086b98;
struct CountHead;
struct Actor0209c678;
struct Actor0209c20c;
struct Obj02081ee4;
struct Sub02081ee4;
struct List0204af64;
struct AllocTarget0204b12c;
struct Obj0204b5e8;
struct Obj0204c7a8;
struct ActiveEntry02046900;
struct Rec020467f0;
struct Obj0207f914;
struct Manager0207f7f0;
struct Node0207f7f0;
struct Obj0207fcb8;
struct Cont0207fd44;
struct Cont0207fd88;
struct Obj0208203c;
struct Obj021ab060;
struct Obj2081;
struct Obj0207fc6c;
struct Ctx021ab0c0;
struct Ctx021ab1a4;
struct SePlayer;
struct Cont0207fe44;
struct FlagWord020466f4;
struct ListHead02046b60;

extern "C" void* func_0202ae18(void);
extern "C" void* func_02012fe4(void);
extern "C" void* func_020d6c00(void);
extern "C" int func_020421a0(void);
extern "C" int func_ov017_021959b4(void);
extern "C" void func_ov017_021aaf08(void* arg0);
extern "C" void* func_02010828(GameState* arg0);
extern "C" int func_02086b98(struct Struct_0201bdac_4* arg0);
extern "C" void func_ov017_021ab010(void* arg0, int arg1);
extern "C" int func_02046c78(struct Struct_02046c78* arg0);
extern "C" void func_0209c678(struct Struct_02109bf4_4* arg0, int arg1);
extern "C" void func_020a0cc4(unsigned int arg0);
extern "C" void* func_02012d88(AllocatorUnion* arg0, unsigned int arg1);
extern "C" void func_020a0c0c(void);
extern "C" void func_02081ee4(struct Struct_02081ee4* arg0, struct Struct_02081ee4_2* arg1);
extern "C" void func_0204af64(struct Struct_02020cb8* arg0);
extern "C" void func_0204b11c(unsigned char* arg0, int arg1);
extern "C" void func_0204b5b4(void* arg0, int arg1);
extern "C" void func_0204b12c(struct Struct_0204b12c* arg0, SafeAllocator* arg1);
extern "C" int func_0204b5e8(struct Struct_02020cb8_5* arg0, int arg1, int arg2);
extern "C" void func_0204c684(void* arg0);
extern "C" void func_0204c7a8(struct Struct_0204c7a8* arg0, SafeAllocator* arg1, int arg2, unsigned int arg3);
extern "C" int func_02046900(struct Struct_02020cb8_4* arg0);
extern "C" void* func_020467f0(struct Struct_02020aec* arg0, int arg1, void** arg2, int* arg3);
extern "C" void func_0204b174(void* arg0, void* arg1, SafeAllocator* arg2, unsigned int arg3);
#if defined(jpn)
extern "C" void func_02080654(struct Struct_0207f914* arg0, int arg1, int arg2);
#else
extern "C" void func_0207f914(struct Struct_0207f914* arg0, int arg1, int arg2, int arg3);
#endif
extern "C" int func_0207f9f4(void* obj);
void InitNodeChain0207f7f0(struct Manager0207f7f0* mgr, struct Node0207f7f0* node, int count);
void ClearAllBuffers0207fcb8(struct Obj0207fcb8* obj);
void CallFunc0204b04cOverList0x2c(struct Cont0207fd44* obj);
void CallFunc0204b088OverList0x2c(struct Cont0207fd88* obj);
void ResetWithSub0208203c(struct Obj0208203c* obj);
extern "C" void func_020813ec(void* obj, int key);
void SetThreeEntryFlags_021ab060(struct Obj021ab060* obj);
void* FindElementByByte0xc4_02081da8(struct Obj2081* obj, int key);
void CallFunc0204c87cOverEntries0207fc6c(struct Obj0207fc6c* obj, int arg);
extern "C" void func_02081f20(void* repeat, int ticks);
extern "C" int func_020800fc(void* menu, short* cursor, short prevCursor, unsigned short buttons, unsigned char columns, bool wrap);
void ClearSublistEntriesFlag4_020804fc(void* obj, int key);
int UpdateElementCoordFlag_021ab0c0(struct Ctx021ab0c0* ctx);
void SePlayer_Play(struct SePlayer* obj, int a, int b);
void CallFunc0204c804OverAllElems(struct Cont0207fe44* obj);
void OrBitsIntoField0_020466e4(unsigned int* p, unsigned int mask);
int CheckCoordsInsideElement_021ab1a4(struct Ctx021ab1a4* ctx);
void ClearFlags020466f4(struct FlagWord020466f4* word, unsigned int mask);
unsigned char GetField0x5729Value_02010750(char* gs);
extern "C" void func_ov017_021d1a18(int a, int b, int c, int d);
int ListContainsId(struct ListHead02046b60* list, int id);
extern "C" void func_02046a8c(struct ListHead02046b60* list, void* node);
void ResetMpForFlaggedCombatants02010604(GameState* gs, int a, int b, int c);
void SetField0x5729Value_0201075c(char* gs, unsigned char value);
void InitActorContext0209c20c(struct Actor0209c20c* actor);

extern AllocatorUnion data_02114e20;
extern struct SePlayer g_sePlayer;
#if defined(jpn)
extern char data_ov017_021d7ddc[];
extern char data_ov017_021d7def[];
#else
extern char data_ov017_021d7870[];
extern char data_ov017_021d7883[];
extern char data_ov017_021d789c[];
#endif

struct Struct_02109bf4_10 {
    char unknown_0_[0xd0];
};
extern Struct_02109bf4_10 data_02109bf4;

struct Struct_ov017_021aa59c {
    unsigned short unknown_0_;
    unsigned char unknown_2_;
};

struct Struct_ov017_021aa59c_2 {
    unsigned short unknown_0_;
#if defined(jpn)
    char unknown_2_[0x27c2];
#else
    char unknown1_2_[0x2782];
#endif
    short unknown_2784_;
    short unknown_2786_;
    unsigned char unknown_2788_;
};

struct Struct_ov017_021aa59c_3 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    char unknown_2_[6];
    void* unknown_8_;
    int unknown_c_;
    char unknown_10_[4];
    int unknown_14_;
    Struct_0207f7f0* unknown_18_;
    Struct_02020cb8* unknown_1c_;
    Struct_0207f7f0_2* unknown_20_;
    SafeAllocator unknown_24_;
    int unknown_38_;
    void* unknown_3c_;
    Struct_ov017_021aa59c* unknown_40_;
    short* unknown_44_;
    short unknown_48_;
    short unknown_4a_;
    short unknown_4c_;
    short unknown_4e_;
    int unknown_50_;
    char unknown_54_[0x10];
    int unknown_64_;
};

// USA: func_ov017_021aa59c
extern "C" ARM void func_ov017_021aa59c(Struct_ov017_021aa59c_3* arg0, Struct_02038598_5* arg1) {
    GameResources* var0;
    Struct_ov017_021aa59c_2* var1;
    GameState* var2 = GameState::GetInstance();
    func_0202ae18();
    var0 = GetGameResources();
    func_020421a0();
    Struct_02046c78* var3 = (Struct_02046c78*)var0->unknown_ptr_array_36fc[0];
    var1 = (Struct_ov017_021aa59c_2*)func_02012fe4();
    unsigned int* var4 = (unsigned int*)func_020d6c00();

    if (arg0->unknown_14_ < 6 && (func_ov017_021959b4() != 0 || var0->unknown_42e2_ != 0)) {
        func_ov017_021aaf08(arg0);
        arg0->unknown_1_ = 1;
        return;
    }
    if (!func_02086b98((Struct_0201bdac_4*)func_02010828(var2))) {
        func_ov017_021ab010(arg0, 1);
        return;
    }
    if (func_02046c78(var3) > 1) {
        func_ov017_021aaf08(arg0);
        arg0->unknown_1_ = 1;
        return;
    }

    func_0209c678((Struct_02109bf4_4*)&data_02109bf4, 0);
    BackgroundLoader* var5 = BackgroundLoader::GetInstance();
    int var6 = arg0->unknown_14_;
    if (var6 == 0) {
        func_020a0cc4(0x7800);
        void* var7 = func_02012d88(&data_02114e20, 0x7800);
        if (var7 == NULL) {
            func_020a0c0c();
            func_ov017_021aaf08(arg0);
            arg0->unknown_1_ = 1;
            return;
        }
        arg0->unknown_24_.CreateTypeA(var7, 0x7800);
        arg0->unknown_24_.Reset();
        arg0->unknown_8_ = arg0->unknown_24_.Allocate(0x1400);
        arg0->unknown_20_ = (Struct_0207f7f0_2*)arg0->unknown_24_.Allocate(0x1c0);
        arg0->unknown_1c_ = (Struct_02020cb8*)arg0->unknown_24_.Allocate(0x40);
#if defined(jpn)
        arg0->unknown_18_ = (Struct_0207f7f0*)arg0->unknown_24_.Allocate(0x34);
#else
        arg0->unknown_18_ = (Struct_0207f7f0*)arg0->unknown_24_.Allocate(0x40);
#endif
        arg0->unknown_3c_ = arg0->unknown_24_.Allocate(0xc);
        arg0->unknown_40_ = (Struct_ov017_021aa59c*)arg0->unknown_24_.Allocate(4);
        func_02081ee4((Struct_02081ee4*)arg0->unknown_3c_, (Struct_02081ee4_2*)arg0->unknown_40_);

        Struct_02020cb8* var8 = arg0->unknown_1c_;
        for (int var9 = 0; var9 < 2; var9++) {
            func_0204af64((Struct_02020cb8*)var8);
            func_0204b11c((unsigned char*)var8, 0);
            var8->unknown_1c_0_ = 0;
            var8->unknown_1c_4_ = var9 + 1;
            func_0204b5b4(var8, var9);
            func_0204b12c((Struct_0204b12c*)var8, &arg0->unknown_24_);
            func_0204b5e8((Struct_02020cb8_5*)var8, 0, 0);
            var8++;
        }

        Struct_0207f7f0_2* var10 = arg0->unknown_20_;
        for (unsigned char var11 = 0; var11 < 2; var11++) {
            func_0204c684(var10);
            func_0204c7a8((Struct_0204c7a8*)var10, &arg0->unknown_24_, (int)arg0->unknown_8_, 0x800);
            var10->unknown_4_ = arg0->unknown_1c_;
            var10++;
        }

        BG1CNT = (BG1CNT & 0x43) | 0x1e00;
        BG2CNT = (BG2CNT & 0x43) | 0x1f00;
        ColorEffect_ConfigureAlphaBlend(0x04000050, 4, 1, 10, 6);
#if defined(jpn)
        arg0->unknown_50_ = var5->QueueLoadFile(data_ov017_021d7ddc, NULL);
#else
        arg0->unknown_50_ = var5->QueueLoadFile(data_ov017_021d7870, NULL);
#endif
        arg0->unknown_14_ = 1;
    } else if (var6 == 1) {
        if (var5->GetTaskStatus(arg0->unknown_50_) != 0) {
            void* var12;
            void* var13;
            unsigned int var14;
            var5->GetLoadedFileByID(arg0->unknown_50_, &var13, &var14);
            int var15 = func_02046900((Struct_02020cb8_4*)var13);
            Struct_02020cb8* var16 = arg0->unknown_1c_;
            for (int var17 = 0; var17 < var15; var17++) {
                int var18;
                void* var19 = func_020467f0((Struct_02020aec*)var13, var17, &var12, &var18);
                func_0204b174(var16, var19, NULL, var18);
            }
            var5->RemoveTask(arg0->unknown_50_);
            arg0->unknown_50_ = -1;
            func_0207f84c(arg0->unknown_18_);
#if defined(jpn)
            func_02080654((Struct_0207f914*)arg0->unknown_18_, (int)&arg0->unknown_24_, (int)data_ov017_021d7def);
#else
            func_0207f914((Struct_0207f914*)arg0->unknown_18_, (int)&arg0->unknown_24_, (int)data_ov017_021d7883, (int)data_ov017_021d789c);
#endif
            arg0->unknown_14_ = 2;
        }
    } else if (var6 == 2) {
        int var20 = func_0207f9f4(arg0->unknown_18_);
        if (var20 == 0) {
            arg0->unknown_14_ = 3;
        }
        if (var20 < 0) {
            arg0->unknown_14_ = 8;
        }
    } else if (var6 == 3) {
        Struct_0207f7f0* var21 = arg0->unknown_18_;
        var21->unknown_2c_ = arg0->unknown_1c_;
        var21->unknown_38_ = 2;
        func_0207f7f0(var21, arg0->unknown_20_, 2);
        var21->unknown_3a_ = 1;
        func_0207fcb8((Struct_0207fcb8*)var21);
        func_0207fd44((Struct_0207fd44_2*)var21);
        func_0207fd88((Struct_0207fd88*)var21);
        BG0CNT = (BG0CNT & ~3) | 2;
        BG1CNT = BG1CNT & ~3;
        BG2CNT = (BG2CNT & ~3) | 1;
        BG3CNT = (BG3CNT & ~3) | 3;
        DISPCNT = (DISPCNT & ~0x1f00) | 0x1700;
        arg0->unknown_14_ = 4;
    } else if (var6 == 4) {
        arg0->unknown_48_ = 0;
        arg0->unknown_4c_ = 0;
        arg0->unknown_4e_ = 0;
        func_0208203c((Struct_02081f20_2*)arg0->unknown_3c_);
        arg0->unknown_44_ = NULL;
        func_020813ec(arg0->unknown_18_, arg0->unknown_48_);
        func_ov017_021ab060((Struct_ov017_021aa59c_4*)arg0);
        arg0->unknown_14_ = 5;
    } else if (var6 == 5) {
        bool var22 = false;
        bool var23 = false;
        void* var24;
        Struct_0207f7f0* var25 = arg0->unknown_18_;
        var24 = func_02081da8((Struct_0207fdcc_2*)var25, arg0->unknown_48_);
        if (var25 != NULL) {
            if (var24 != NULL) {
                int var26 = var2->GetTickCount();
                func_0207fc6c((Struct_0207fc6c*)var25, var26);
                arg0->unknown_44_ = &arg0->unknown_4c_;
                if (arg0->unknown_44_ != NULL) {
                    func_02081f20(arg0->unknown_3c_, var26);
                    arg0->unknown_4e_ = *arg0->unknown_44_;
                    arg0->unknown_38_ = func_020800fc(var25, arg0->unknown_44_, arg0->unknown_4e_, arg0->unknown_40_->unknown_0_, arg0->unknown_40_->unknown_2_, false);
                    var25->unknown_36_ = *arg0->unknown_44_;
                    if (arg0->unknown_38_ != 0) {
                        func_020804fc(var25, arg0->unknown_48_);
                    }
                    if (arg0->unknown_4e_ != *arg0->unknown_44_ || g_touchInput.pressed_ != 0) {
                        func_020813ec(var25, arg0->unknown_48_);
                        func_ov017_021ab060((Struct_ov017_021aa59c_4*)arg0);
                    }
                }
                if (func_ov017_021ab0c0((Struct_ov017_021aa59c_5*)arg0) != 0) {
                    if (arg0->unknown_4e_ != *arg0->unknown_44_) {
                        return;
                    }
                    SePlayer_Play(&g_sePlayer, 1, 0);
                    ResetWithSub0208203c((Obj0208203c*)self->repeat);
                    self->cursorPtr = NULL;
                    if (self->cursor == 0) {
                        CallFunc0204c804OverAllElems((Cont0207fe44*)self->menu);
                        OrBitsIntoField0_020466e4(flags, 0x200);
                    } else if (self->cursor == 1) {
                        cancelled = true;
                    }
                } else if (func_ov017_021ab1a4((Struct_ov017_021aa59c_6*)arg0) != 0) {
                    var23 = true;
                }
            } else if (g_keyManager.TestKeysPressed(0x401) != 0 || g_touchInput.pressed_ != 0) {
                func_020813ec(var25, arg0->unknown_48_);
                func_ov017_021ab060((Struct_ov017_021aa59c_4*)arg0);
                func_020466f4((Struct_02038598_4*)var4, 0x200);
            }
        }
        if (func_02010750((char*)var2) != 0 || var22) {
            arg0->unknown_14_ = 6;
            var23 = true;
            arg0->unknown_64_ = true;
        }
        if (var23 && var25 != NULL && var24 != NULL) {
            func_0207fe44((Struct_0207fe44*)arg0->unknown_18_);
            func_020466e4(var4, 0x200);
        }
    } else if (var6 == 6) {
        if (var1->unknown_0_ == 10000) {
            func_ov017_021d1a18(var1->unknown_2786_, var1->unknown_2784_, var1->unknown_2788_, 1);
        }
        func_020466e4((unsigned int*)func_020d6c00(), 0x200000);
        SetBrightness(var0, -16, 120);
        arg0->unknown_14_ = 7;
    } else if (var6 == 7) {
        if (IsBrightnessTransitionActive(var0) != 0) {
            arg0->unknown_14_ = 8;
        }
    } else if (var6 == 8) {
        if (IsBrightnessTransitionActive(var0) == 0) {
            if (func_02046b60(arg1, 0x40) != 0) {
                func_02046a8c(arg1, var0->unknown_ptr_array_3afc[39]);
            }
            func_02010604(var2, 0, func_02010750((char*)var2), 0);
            func_0201075c((char*)var2, 0);
            DISPCNT = (DISPCNT & ~0x1f00) | (arg0->unknown_c_ << 8);
            func_020a0c0c();
            func_0209c20c((Struct_02109bf4_3*)&data_02109bf4);
            func_ov017_021aaf08(arg0);
            arg0->unknown_1_ = 1;
        }
    }
}
