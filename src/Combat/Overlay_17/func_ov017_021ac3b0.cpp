#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include <std_library_functions.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "Resource/GameResources.h"

#if defined(jpn)
#define func_0205ec34 func_0205ff20
#endif

#if defined(jpn)
#define func_0206df6c func_0206f0c0
#endif

#if defined(jpn)
enum { Enum_ov017_021ac3b0_2400 = 0x800 };
#else
enum { Enum_ov017_021ac3b0_2400 = 0x960 };
#endif

struct Obj020397cc;
struct Obj02033834;
struct SePlayer;
struct BitFlags020d805c;
struct Obj020d7aa0;
struct StreamHeader;
struct Source021ac3b0 { unsigned short id; char pad2[0x1e]; short angle; };
struct Descriptor021ac3b0 { char pad0[5]; signed char kind; };
struct Zone021ac3b0 { unsigned short id; char pad2[6]; Descriptor021ac3b0* descriptor; };
struct ScriptInfo021ac3b0 {
    const char* text; const char* alternateText; const char* completedText;
    void* data; unsigned short zone; short key; unsigned char kind, index, count, enabled;
};
struct Struct_ov017_021ac3b0 {
    short unknown_0_; unsigned short unknown_2_0_:1, unknown_2_1_:1, unknown_2_2_:14;
};
struct Struct_ov017_021ac3b0_2 {
    unsigned char unknown_0_, unknown_1_; char unknown_2_[6]; Struct_ov017_021ac3b0_6* unknown_8_;
    Struct_ov017_021ac3b0_9* unknown_c_; SafeAllocator unknown_10_; int unknown_24_;
    unsigned char unknown_28_, unknown_29_;
};
struct Struct_ov017_021ac3b0_3 {
#if defined(jpn)
    char unknown_0_[0x28]; char* unknown_5c_; char* unknown_60_; char unknown_30_[0x868 - 0x30];
    int unknown_998_; char unknown_86c_[0x17e2 - 0x86c]; unsigned char unknown_19b2_;
#else
    char unknown1_0_[0x5c]; char* unknown_5c_; char* unknown_60_; char unknown_64_[0x998 - 0x64];
    int unknown_998_; char unknown_99c_[0x19b2 - 0x99c]; unsigned char unknown_19b2_;
#endif
};
struct Struct_ov017_021ac3b0_4 { char unknown_0_[0x8c]; unsigned char unknown_8c_[1]; };
struct Struct_ov017_021ac3b0_5 {
    char unknown_0_[0xc]; int unknown_c_; char unknown_10_[0x14]; int unknown_24_; char unknown_28_[0xc];
};
extern "C" Struct_ov017_021ac3b0_8* func_02012fe4();
extern "C" Struct_ov017_021ac3b0_3* func_020421a0();
extern "C" void func_020397cc(Struct_02018300_3*, int);
extern "C" int func_ov017_021959b4();
void ReinitController02043204(char*);
extern "C" void func_ov017_021ac32c(Event021ac3b0*);
int GetFieldIfFlag4_020100f8(char*);
void SetFlagsAt0x244_020a28a0(unsigned char*, unsigned char);
void SePlayer_Play(SePlayer*, int, int);
void* GetGlobalResetObj020d7a50();
int GetByte0x150Bit6(BitFlags020d805c*);
void TeardownAndResetState020d7aa0(Obj020d7aa0*);
#if defined(jpn)
extern "C" void func_0204500c(void*, const char*, int);
#else
extern "C" void func_0204500c(void*, const char*, int, int);
#endif
extern "C" void func_020a0cc4(unsigned int);
extern "C" void func_02033834(Struct_02033834_2*, int);
extern "C" void func_020a0c0c();
extern "C" void* func_02012d88(AllocatorUnion*, unsigned int);
extern "C" void func_ov017_021acc8c(void*, Struct_02013fb4*, int, int);
extern "C" Struct_ov017_021ac3b0_4* func_0205ec34();
extern "C" int func_0206dfb0(int, unsigned char*, int);
extern "C" void func_02042058(char*, const char*);
extern "C" const char* func_020e51cc(int);
extern "C" char* func_0206f504();
extern "C" void func_0206f510(char*);
extern "C" void func_0206f550(char*, char*, char*);
extern "C" int func_020ac2d4(int, void*, Struct_ov017_021ac3b0*, int);
extern "C" void func_020ac104(int, Struct_ov017_021ac3b0*, int);
extern "C" void func_0206df6c(void*, unsigned char*, int, int);
void SetByteField0x253_020397c0(void*);
int LookupAndForEachNode020649b0(void*, int, void*);
extern "C" void func_0206f81c(Lookup021ac3b0*);
extern SePlayer g_sePlayer;
#if defined(jpn)
extern const char data_ov017_021d7e88[], data_ov017_021d7e96[];
extern const char data_ov017_021d7eb0[], data_ov017_021d7ed2[];
#else
extern const char data_ov017_021d7920[], data_ov017_021d792f[], data_ov017_021d7949[];
#endif
extern AllocatorUnion data_02114e20;

// USA: func_ov017_021ac3b0
extern "C" ARM void func_ov017_021ac3b0(Struct_ov017_021ac3b0_2* arg0) {
    GameState* var0 = GameState::GetInstance();
    GetGameResources();
    GameObject* var1 = var0->GetUnknownGameObject();
    Struct_ov017_021ac3b0_8* var2 = func_02012fe4();
    Struct_ov017_021ac3b0_3* var3 = func_020421a0();
    BackgroundLoader* var4 = BackgroundLoader::GetInstance();
    Struct_0208cb08* var5 = func_02094a00();
    func_020397cc((Struct_02018300_3*)var1, 1);
    if (!arg0->unknown_29_ && func_ov017_021959b4()) {
        arg0->unknown_29_ = 1; func_02043204((char*)var3);
        func_ov017_021ac32c(arg0); arg0->unknown_1_ = 1; return;
    }
    if (self->stage == 0) {
        int actor = GetFieldIfFlag4_020100f8((char*)game);
        if (actor) SetFlagsAt0x244_020a28a0((unsigned char*)actor, 3);
        SePlayer_Play(&g_sePlayer, 1, 0);
        void* reset = GetGlobalResetObj020d7a50();
        if (GetByte0x150Bit6((BitFlags020d805c*)reset)) TeardownAndResetState020d7aa0((Obj020d7aa0*)reset);
#if defined(jpn)
        func_0204500c(var3, data_ov017_021d7e88, 0);
#else
        func_0204500c(var3, data_ov017_021d7920, 0, 0xe3);
#endif
        var3->unknown_19b2_ = 0; var3->unknown_998_ = 1;
        func_02094b3c(var5, 10);
        func_02094b30(var5, 0x1f6, 1);
        arg0->unknown_28_++;
    } else if (arg0->unknown_28_ == 1) {
        if (func_02094b4c(var5)) arg0->unknown_28_++;
    } else if (arg0->unknown_28_ == 2) {
        func_020a0cc4(0x2800);
        func_020397cc((Struct_02018300_3*)var1, 1);
        func_02033834((Struct_02033834_2*)var1, fix32ReduceAngle0To2Pi(arg0->unknown_8_->unknown_20_));
        Struct_ov017_021ac3b0_7* var8 = var2->unknown_8_;
        char var9[0x50];
#if defined(jpn)
        sprintf(var9, data_ov017_021d7e96, var8->unknown_5_);
        arg0->unknown_24_ = var4->QueueLoadFile(var9, 0);
#else
        char var10[0x40];
        sprintf(var9, data_ov017_021d792f, var8->unknown_5_);
        sprintf(var10, data_ov017_021d7949, var8->unknown_5_);
        arg0->unknown_24_ = var4->QueueLoadFileInGP2(var9, var10, 0);
#endif
        arg0->unknown_28_++;
    } else if (arg0->unknown_28_ == 3) {
        if (!var4->GetTaskStatus(arg0->unknown_24_)) return;
        if (var4->GetDetailedTaskStatus(arg0->unknown_24_) != 2) {
            var4->RemoveTask(arg0->unknown_24_); arg0->unknown_24_ = -1; arg0->unknown_1_ = 1;
            func_ov017_021ac32c(arg0); func_020a0c0c(); return;
        }
        void* var11; unsigned int var12;
        var4->GetLoadedFileByID(arg0->unknown_24_, &var11, &var12);
        arg0->unknown_10_.CreateTypeA(func_02012d88(&data_02114e20, 0x2800), 0x2800);
        arg0->unknown_10_.Reset();
        Struct_ov017_021ac3b0_8* var13 = func_02012fe4();
        Struct_ov017_021ac3b0_9* var14 = (Struct_ov017_021ac3b0_9*)arg0->unknown_10_.Allocate(0x18);
        arg0->unknown_c_ = var14;
        var14->unknown_0_ = 0; var14->unknown_4_ = 0; var14->unknown_8_ = 0; var14->unknown_c_ = 0;
        var14->unknown_10_ = 0; var14->unknown_12_ = -1;
        var14->unknown_14_ = 0; var14->unknown_15_ = 0; var14->unknown_16_ = 0; var14->unknown_17_ = 0;
        arg0->unknown_c_->unknown_10_ = var13->unknown_0_; arg0->unknown_c_->unknown_12_ = arg0->unknown_8_->unknown_0_;
        func_ov017_021acc8c(&arg0->unknown_10_, (Struct_02013fb4*)var11, var12, (int)arg0->unknown_c_);
        var4->RemoveTask(arg0->unknown_24_); arg0->unknown_24_ = -1; arg0->unknown_28_ = 4;
    } else if (arg0->unknown_28_ == 4) {
        char* var15 = var3->unknown_5c_;
        char* var16 = var3->unknown_60_;
        memset(var15, 0, Enum_ov017_021ac3b0_2400); memset(var16, 0, Enum_ov017_021ac3b0_2400);
        if (arg0->unknown_c_->unknown_17_) {
            const char* var17 = arg0->unknown_c_->unknown_0_;
            if (arg0->unknown_c_->unknown_14_ == 1) {
                Struct_ov017_021ac3b0_4* var18 = func_0205ec34();
                if (func_0206dfb0((int)var18, var18->unknown_8c_, 0x777)) {
                    var17 = arg0->unknown_c_->unknown_4_;
                    if (func_0206dfb0((int)var18, var18->unknown_8c_, arg0->unknown_c_->unknown_15_ + 0x114c) && arg0->unknown_c_->unknown_8_)
                        var17 = arg0->unknown_c_->unknown_8_;
                }
            }
            if (var17) func_02042058(var16, var17);
#if defined(jpn)
            else func_02042058(var16, data_ov017_021d7eb0);
        } else func_02042058(var16, data_ov017_021d7ed2);
#else
            else func_02042058(var16, func_020e51cc(0x3f2));
        } else func_02042058(var16, func_020e51cc(0x53));
#endif
        if (strlen(var16) >= Enum_ov017_021ac3b0_2400) var16[Enum_ov017_021ac3b0_2400 - 1] = 0;
        char* var19 = func_0206f504();
        func_0206f510(var19); func_0206f550(var19, var16, var15);
#if defined(jpn)
        func_0204500c(var3, var15, 0);
#else
        func_0204500c(var3, var15, 0, 0xe3);
#endif
        var3->unknown_998_ = 1; var3->unknown_19b2_ = 0; arg0->unknown_28_ = 5;
    } else if (arg0->unknown_28_ == 5) {
        if (var3->unknown_998_) return;
        Struct_ov017_021ac3b0_4* var20 = func_0205ec34();
        if (func_0206dfb0((int)var20, var20->unknown_8c_, 0x777) && arg0->unknown_c_->unknown_14_ == 1 &&
            !func_0206dfb0((int)var20, var20->unknown_8c_, arg0->unknown_c_->unknown_15_ + 0x114c)) {
            unsigned char var21 = arg0->unknown_c_->unknown_16_;
            if (var21) {
                Struct_ov017_021ac3b0* var22 = (Struct_ov017_021ac3b0*)arg0->unknown_10_.Allocate(var21 * 4);
                for (unsigned char var23 = 0; var23 < var21; var23++) {
                    var22[var23].unknown_0_ = -1; var22[var23].unknown_2_0_ = 0; var22[var23].unknown_2_1_ = 0; var22[var23].unknown_2_2_ = 0;
                }
                if (func_020ac2d4(0, arg0->unknown_c_->unknown_c_, var22, var21)) {
                    for (unsigned char var24 = 0; var24 < var21; var24++) var22[var24].unknown_2_1_ = 1;
                    func_020ac104(0, var22, var21);
                }
            }
            func_0206df6c(var20, var20->unknown_8c_, arg0->unknown_c_->unknown_15_ + 0x114c, 1);
        }
        Struct_0208cb08* var25 = func_02094a00(); func_02094ab0(var25);
        func_02094b34(var25, 0x6f, 0x1388, 1, 1);
        arg0->unknown_28_ = 6;
    } else if (arg0->unknown_28_ == 6) {
        if (!func_02094b4c(func_02094a00())) return;
        func_ov017_021ac32c(arg0); func_020397c0(var1); arg0->unknown_1_ = 1;
        Struct_ov017_021ac3b0_4* var26 = func_0205ec34();
        Struct_ov017_021ac3b0_5 var27;
        var27.unknown_c_ = var2->unknown_0_; var27.unknown_24_ = arg0->unknown_8_->unknown_0_;
        if (func_020649b0(var26, 0x18, &var27)) func_0206f81c(&var27);
    }
}
