#include <globaldefs.h>
#include "Graphics/Background.h"
#include <Memory/SafeAllocator.h>
#include <Graphics/Vector.h>
#include <World/Object3D.h>
#include "Input/Input.h"

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
    int unknown_0_[0xe0 / 4];
};

struct Struct_ov009_02186e00_2 {
    int unknown_0_[0x40 / 4];
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
    void* unknown_b08_;
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
};

// USA: func_ov008_02186e4c
extern "C" ARM void func_ov008_02186e4c(Struct_ov008_021842a0_2* arg0, unsigned int arg1)
{
    int var0 = arg0->unknown_b18_;
    if (var0 & 0x40)
    {
        Vector3fix var1 = arg0->unknown_790_.rotation_;
        int var2 = 0;
        int var3;
        int var4 = fix32ReduceAngle0To2Pi(0x5ccc - var1.y);
        if (var4 >= 0 && var4 < 0x3244)
        {
            var3 = var1.y + var4 / 12;
            for (unsigned int var5 = 0; var5 < arg1 - 1; var5++)
                var3 += fix32ReduceAngle0To2Pi(0x5ccc - var3) / 12;
        }
        else if (var4 >= 0x3244 && var4 < 0x6488)
        {
            var3 = var1.y - (0x6488 - var4) / 12;
            for (unsigned int var6 = 0; var6 < arg1 - 1; var6++)
                var3 -= (0x6488 - fix32ReduceAngle0To2Pi(0x5ccc - var3)) / 12;
        }
        var1.y = fix32ReduceAngle0To2Pi(var3);
        arg0->unknown_790_.rotation_ = var1;
        int var7 = fix32ReduceAngle0To2Pi(0x5ccc - var1.y);
        int var8 = var7 < 0 ? -var7 : var7;
        if (var8 < 0x28)
        {
            var2 = 1;
        }
        else
        {
            var8 = 0x6488 - var7;
            if (var8 < 0)
                var8 = -var8;
            if (var8 < 0x28)
                var2 = 1;
        }
        if (var2)
        {
            var1.y = fix32ReduceAngle0To2Pi(0x5ccc);
            arg0->unknown_790_.rotation_ = var1;
            arg0->unknown_b18_ &= ~0x40;
        }
    }
    else if (var0 & 0x20)
    {
        int var9 = 0;
        int var10 = 0;
        if (g_keyManager.TestKeysHeld(0x200))
            var9 = 1;
        if (g_keyManager.TestKeysHeld(0x100))
            var10 = 1;
        if (var9 && var10)
        {
            arg0->unknown_b18_ |= 0x40;
            return;
        }
        if (!var9 && !var10)
            return;
        Vector3fix var11 = arg0->unknown_790_.rotation_;
        if (var9)
            var11.y += (int)(4096.0f * (0.08f * arg1));
        if (var10)
            var11.y -= (int)(4096.0f * (0.08f * arg1));
        var11.y = fix32ReduceAngle0To2Pi(var11.y);
        arg0->unknown_790_.rotation_ = var11;
    }
}
