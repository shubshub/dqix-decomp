#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "World/Zone3D.h"
#include "Resource/Brightness.h"
#include "Resource/GameResources.h"

#if defined(jpn)
#define func_0205ec34 func_0205ff20
#endif

#if defined(jpn)
#define func_0206df6c func_0206f0c0
#endif

struct Struct_02072a68;
struct Struct_02072a68_2 { Struct_02072a68* unknown_0_; short unknown_4_; short unknown_6_; };
struct Struct_020d80b0_3 {
    unsigned char unknown_0_[4];
    int unknown_4_;
    int unknown_8_;
    Struct_02072a68_2 unknown_c_;
    SafeAllocator unknown_14_;
    int unknown_28_;
};
struct Obj020397cc;
struct SePlayer;
extern SePlayer g_sePlayer;
extern AllocatorUnion data_02114e20;
extern char data_020f235c[];
extern char data_020f2371[];
extern "C" void func_0202ae18(GameState*);
extern "C" Zone3D* func_02012fe4();
extern "C" void* func_0205ec34();
extern "C" int func_020421a0();
extern "C" int func_020100f8(char*);
extern "C" void func_020d8484(Struct_020d80b0_3*);
extern "C" void func_020397cc(Struct_02018300_3*, int);
extern "C" void func_020a27b8(unsigned char*);
extern "C" void* func_02012d88(AllocatorUnion*, unsigned int);
extern "C" void func_020728ac(Struct_02072a68_2*, SafeAllocator*, void*, unsigned int, int, int, int);
extern "C" void func_02046380(void*);
extern "C" int func_0206dfb0(int, unsigned char*, int);
extern "C" void func_0206df6c(void*, unsigned char*, int, int);
extern "C" void* func_02072a68(Struct_02072a68_2*, int);
#if defined(jpn)
extern "C" void func_0204500c(void*, char*, int);
#define SHOW_TEXT_020d80b0(d, t) func_0204500c(d, t, 0)
extern char data_020f24b8[];
#else
extern "C" void func_0204500c(void*, char*, int, int);
#define SHOW_TEXT_020d80b0(d, t) func_0204500c(d, t, 0, 0xe3)
#endif
void SePlayer_Play(SePlayer*, int, int);
void SetByteField0x253_020397c0(void*);
void SetCombatModeFromCase020dc2d0(int);
struct Dialog020d80b0 {
#if defined(jpn)
    unsigned char unknown_0_[0x28];
    char* unknown_5c_;
    unsigned char unknown_2c_[0x868-0x2c];
    int unknown_998_;
    unsigned char unknown_86c_[0x17e2-0x86c];
#else
    unsigned char unknown1_0_[0x5c];
    char* unknown_5c_;
    unsigned char unknown_60_[0x998-0x60];
    int unknown_998_;
    unsigned char unknown_99c_[0x19b2-0x99c];
#endif
    unsigned char unknown_19b2_;
};
struct Struct_020d80b0_2 { unsigned char unknown_0_[0x8c]; unsigned char unknown_8c_[1]; };

// USA: func_020d80b0
extern "C" ARM void func_020d80b0(Struct_020d80b0_3* arg0) {
    GameState* var0 = GameState::GetInstance();
    func_0202ae18(var0);
    GameResources* var1 = GetGameResources();
    Struct_020d80b0* var2 = (Struct_020d80b0*)func_020421a0();
    GameObject* var3;
    Struct_020d80b0_2* var4;
    Zone3D_StructPtr_8* var5 = func_02012fe4()->pUnknownStruct_8_;
    GrottoStruct* var6 = var0->GetGrottoStruct();
    var3 = var0->GetUnknownGameObject();
    var4 = (Struct_020d80b0_2*)func_0205ec34();
    unsigned char* var7 = (unsigned char*)func_020100f8((char*)var0);
    if (var6->activeMapData.GetDiscoveryState() != 1) {
        arg0->unknown_8_ = 7;
        func_020d8484(arg0);
    }
    if (arg0->unknown_8_ == 0) {
        func_020397cc((Struct_02018300_3*)var3, 1);
        func_020a27b8(var7);
        arg0->unknown_14_.CreateTypeA(func_02012d88(&data_02114e20, 0x300), 0x300);
#if defined(jpn)
        arg0->unknown_28_ = BackgroundLoader::GetInstance()->QueueLoadFile(data_020f24b8, 0);
#else
        arg0->unknown_28_ = BackgroundLoader::GetInstance()->QueueLoadFileInGP2(data_020f235c, data_020f2371, 0);
#endif
        arg0->unknown_8_ = 1;
    } else if (arg0->unknown_8_ == 1) {
        if (BackgroundLoader::GetInstance()->GetTaskStatus(arg0->unknown_28_)) {
            void* var8;
            unsigned int var9;
            BackgroundLoader::GetInstance()->GetLoadedFileByID(arg0->unknown_28_, &var8, &var9);
            arg0->unknown_14_.Reset();
            func_020728ac(&arg0->unknown_c_, &arg0->unknown_14_, var8, var9, 0, 0, 0);
            BackgroundLoader::GetInstance()->RemoveTask(arg0->unknown_28_);
            arg0->unknown_28_ = -1;
            func_02046380(var2);
            func_02094b30(func_02094a00(), 0x203, 0);
            arg0->unknown_8_ = 2;
        }
    } else if (arg0->unknown_8_ == 2) {
        if (func_02094b4c(func_02094a00())) {
            if (func_0206dfb0((int)var4, var4->unknown_8c_, 0x119e)) arg0->unknown_8_ = 5;
            else {
                arg0->unknown_8_ = 3;
                func_0206df6c(var4, var4->unknown_8c_, 0x119e, 1);
            }
        }
    } else if (self->state == 3) {
        char* text = dialog->text;
        strcpy(text, (char*)FindEntryByKey_02072a68(&self->table, 2));
        SHOW_TEXT_020d80b0(dialog, text);
        dialog->flag = 0;
        dialog->busy = 1;
        self->state = 4;
    } else if (self->state == 4) {
        if (!dialog->busy) {
            SePlayer_Play(&g_sePlayer, 1, 0);
            self->state = 5;
        }
    } else if (self->state == 5) {
        char* text = dialog->text;
        strcpy(text, (char*)FindEntryByKey_02072a68(&self->table, 1));
        SHOW_TEXT_020d80b0(dialog, text);
        dialog->flag = 0;
        dialog->busy = 1;
        self->state = 6;
    } else if (self->state == 6) {
        if (!dialog->busy) {
            SePlayer_Play(&g_sePlayer, 1, 0);
            self->state = 7;
        }
    } else if (arg0->unknown_8_ == 7) {
        func_020397c0(var3);
        Struct_0208cb08* var12 = func_02094a00();
        func_02094b38(var12, 0x203);
        func_02094ab0(var12);
        if (var5 && !var5->unknown_c_low_) func_020d8484(arg0);
        else {
            SetSubBrightness(var1, -16, 15);
            arg0->unknown_8_ = 8;
        }
    } else if (arg0->unknown_8_ == 8) {
        if (!IsBrightnessTransitionActive(var1)) {
            func_020dc2d0(2);
            arg0->unknown_8_ = 9;
        }
    } else if (arg0->unknown_8_ == 9) func_020d8484(arg0);
}
