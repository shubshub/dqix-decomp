#include <globaldefs.h>
#include "Graphics/Background.h"
#include "Resource/FontBankLoader.h"
#if defined(jpn)
#define func_ov008_02188d74 func_ov008_02189a9c
#define func_ov008_0218712c func_ov008_02188008
#define func_ov008_02187f6c func_ov008_02188ccc
#endif

#include <Memory/SafeAllocator.h>
#include <World/Object3D.h>
#include <Resource/MessageSystem.h>
#include <Filesystem/BackgroundLoader.h>
#include "Input/Input.h"
#include "Resource/GameResources.h"

struct Struct_01ff8b48_26 {
    unsigned short unknown_0_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
};

struct Struct_01ff8b48_13 {
    int unknown_0_[0x18 / 4];
};


struct Struct_02081870_2 {
    int unknown_0_[0xbc / 4];
};

struct Struct_ov006_02158478 {
    char unknown_0_[0xc2];
    unsigned short unknown_c2_;
    char unknown_c4_[0xe0 - 0xc4];
};

struct Struct_ov009_02186e00_2 {
    int unknown_0_[0x40 / 4];
};

struct Struct_ov008_02185a70 {
    char unknown_0_[0x438];
    unsigned short unknown_438_;
    char unknown_43a_[0x44c - 0x43a];
};

struct Struct_ov008_021842a0_2 {
    SafeAllocator unknown_0_;
    SafeAllocator unknown_14_;
    SafeAllocator unknown_28_;
    SafeAllocator unknown_3c_;
    SafeAllocator unknown_50_;
    SafeAllocator unknown_64_;
    SafeAllocator unknown_78_;
    SafeAllocator unknown_8c_;
    Struct_01ff8b48_13 unknown_a0_;
    char* unknown_b8_;
    char unknown_bc_[0x14];
    Struct_ov003_021594c4 unknown_d0_[3];
    Struct_02081870_2 unknown_130_;
    Struct_ov006_02158478 unknown_1ec_[6];
    void* unknown_72c_;
    void* unknown_730_;
    void* unknown_734_;
    void* unknown_738_;
    void* unknown_73c_;
    void* unknown_740_;
    unsigned char unknown_744_[8];
    unsigned char unknown_74c_;
    Struct_ov009_02186e00_2 unknown_750_;
    Object3D unknown_790_;
    char unknown_83c_[0x2c8];
    void* unknown_b04_;
    Struct_ov008_02185a70* unknown_b08_;
    void* unknown_b0c_;
    signed char unknown_b10_;
    unsigned char unknown_b11_;
    unsigned char unknown_b12_;
    unsigned char unknown_b13_;
    short unknown_b14_;
    short unknown_b16_;
    int unknown_b18_;
    int unknown_b1c_;
    int unknown_b20_;
    int unknown_b24_;
    unsigned char unknown_b28_;
    unsigned char unknown_b29_;
    unsigned char unknown_b2a_;
    int unknown_b2c_;
    const void* unknown_b30_;
    void* unknown_b34_;
    void* unknown_b38_;
    void* unknown_b3c_;
    Struct_01ff8b48_26 unknown_b40_[2];

    int inline_ov008_02185a70(int arg0)
    {
        return unknown_b18_ & arg0 ? 1 : 0;
    }
};

struct GameResources;
struct Struct_0205d6a0;
struct Struct_ov008_02184a4c_13;
struct Struct_0205d81c;

MessageSystem* MessageSystem_GetInstance();
void Window_ClosePane(Entry_0205d6a0* window, int value);
void SetMainBrightness(GameResources* resources, int screen, int brightness);
extern "C" void func_ov008_02187664(Struct_ov008_02184a4c_13* arg0, int arg1);
extern "C" Struct_ov006_02158478* func_0205d81c(Struct_0205d81c* arg0, int arg1);
int IsBrightnessTransitionActive(GameResources* resources);

extern "C" {
void func_ov023_021eb138(Struct_ov008_02185a70* arg0, int arg1);
void func_ov023_021eb080(Struct_ov008_02185a70* arg0, SafeAllocator* arg1);
void func_ov023_021eb564(Struct_ov008_02185a70* arg0, void* arg1, int arg2);
void func_ov023_021eb26c(Struct_ov008_02185a70* arg0);
void func_ov008_02186964(Struct_ov008_021842a0_2* arg0);
int func_ov008_02188d74(Struct_ov008_021842a0_2* arg0);
int func_ov008_02188a54(Struct_ov008_021842a0_2* arg0, int arg1);
void func_ov008_0218712c(Struct_ov008_021842a0_2* arg0, void* arg1);
void func_ov008_02187a70(Struct_ov008_021842a0_2* arg0, void* arg1);
void func_ov008_02187f6c(Struct_ov008_021842a0_2* arg0, void* arg1);
void func_ov008_02186cec(Struct_ov008_021842a0_2* arg0);
}

// USA: func_ov008_02185a70
extern "C" ARM void func_ov008_02185a70(Struct_ov008_021842a0_2* arg0, unsigned int arg1)
{
    MessageSystem* messages = MessageSystem_GetInstance();
    GameResources* resources = GetGameResources();
    BackgroundLoader::GetInstance();
    FontBankLoader* music = FontBankLoader_GetInstance();
    unsigned char step = self->step_;
    if (step >= 2)
        messages->b19ae = 0;
    if (step == 0)
    {
        if (var0->unknown_9a0_ != 3)
            return;
        arg0->unknown_b11_++;
    }
    if (var3 == 1 && (g_keyManager.TestKeysPressed(0xff3) || g_touchInput.pressed_))
        arg0->unknown_b11_++;
    if (var3 == 2)
    {
        arg0->unknown_b08_ = (Struct_ov008_02185a70*)arg0->unknown_78_.Allocate(sizeof(Struct_ov008_02185a70));
        func_ov023_021eb138(arg0->unknown_b08_, 0);
        func_ov023_021eb080(arg0->unknown_b08_, &arg0->unknown_78_);
        func_ov023_021eb564(arg0->unknown_b08_, arg0->unknown_b0c_, 1);
        {
            int var4 = arg0->inline_ov008_02185a70(0x8000);
            Struct_ov008_02185a70* var5 = arg0->unknown_b08_;
            if (var4)
                var5->unknown_438_ |= 0x400;
            else
                var5->unknown_438_ &= ~0x400;
        }
        {
            int var6 = arg0->inline_ov008_02185a70(2);
            Struct_ov008_02185a70* var7 = arg0->unknown_b08_;
            if (var6)
                var7->unknown_438_ |= 0x800;
            else
                var7->unknown_438_ &= ~0x800;
        }
        arg0->unknown_b11_++;
    }
    if (var3 == 3 && (arg0->unknown_b08_->unknown_438_ & 4))
        arg0->unknown_b11_++;
    if (var3 == 4)
    {
        func_ov023_021eb26c(arg0->unknown_b08_);
        arg0->unknown_78_.Reset();
        arg0->unknown_b08_ = NULL;
        arg0->unknown_b0c_ = NULL;
        arg0->unknown_b18_ &= ~0x200000;
        func_ov008_02186964(arg0);
        int var8 = arg0->unknown_b18_;
        if ((var8 & 0x8000) || (var8 & 2))
            arg0->unknown_b18_ &= ~0x200;
        arg0->unknown_b18_ &= ~0x8000;
        arg0->unknown_b11_++;
    }
    if (var3 == 5)
    {
        Window_ClosePane((Entry_0205d6a0*)&self->window_, 1);
        BlankFunction02094b40(music);
        BlankFunction02094b34(music, 0x6b, 0x1fc, 0, 0);
        self->step_++;
    }
    if (var3 == 6)
    {
        if (!func_02094b4c(var2))
            return;
        if (func_ov008_02188d74(arg0))
        {
            arg0->unknown_b11_++;
            var3++;
        }
    }
    if (var3 == 7 && func_ov008_02188a54(arg0, 0))
    {
        SetMainBrightness(var1, 0, 0xf);
        func_ov008_0218712c(arg0, NULL);
        func_ov008_02187664((Struct_ov008_02184a4c_13*)arg0, 0);
        func_ov008_02187a70(arg0, NULL);
        func_ov008_02187f6c(arg0, NULL);
        for (int var9 = 0; var9 < 6; var9++)
        {
            Struct_ov006_02158478* var10 = func_0205d81c((Struct_0205d81c*)&arg0->unknown_130_, (unsigned char)var9);
            if (var10 != NULL)
                var10->unknown_c2_ = 0;
        }
        arg0->unknown_b11_++;
    }
    if (var3 == 8 && !IsBrightnessTransitionActive(var1))
    {
        arg0->unknown_b18_ |= 0x2000;
        func_ov008_02186cec(arg0);
        arg0->unknown_b10_ = 3;
        arg0->unknown_b11_ = 0;
        arg0->unknown_b18_ |= 0x20000;
        if (arg0->unknown_b18_ & 2)
            arg0->unknown_b28_ = 7;
        func_ov008_02186964(arg0);
        arg0->unknown_b11_ = 1;
    }
}
