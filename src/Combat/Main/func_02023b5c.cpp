#include <globaldefs.h>

#include "GameState/GameState.h"
#include "NitroSDK/ColorEffects.h"
#include "NitroSDK/Matrix.h"

extern "C" void Zone3D_GetInstance();
extern "C" void* func_0202ae18();
extern "C" int func_0202c540(void* arg0);
extern "C" int func_02023a9c(char* arg0, int arg1);
extern "C" void func_0202756c(void *arg0, int arg1, int arg2, int arg3, unsigned char arg4, unsigned char arg5,
                              unsigned short arg6, unsigned char arg7, int arg8, int arg9);

struct Struct_02023b5c {
    unsigned char unknown_0_[0x10];
    Vector3i unknown_10_;
};

#if defined(jpn)
enum { Enum_02023b5c_0 = -0xac };
#else
enum { Enum_02023b5c_0 = 0 };
#endif

struct Struct_02023b5c_2 {
    unsigned char unknown_0_[0x38];
    fix32_t unknown_38_;
    unsigned char unknown_3c_[0x77c - 0x3c + Enum_02023b5c_0];
    int unknown_77c_;
    unsigned char unknown_780_;
    unsigned char unknown_781_[3];
    Struct_02023b5c unknown_784_[(0x9b4 - 0x784) / 0x1c];
    int unknown_9b4_;
    unsigned char unknown_9b8_[2];
    unsigned char unknown_9ba_;
};

// USA: func_02023b5c
extern "C" ARM void func_02023b5c(void *receiver, int tileX, int tileY, int xOffset, int yOffset, unsigned char flag) {
    MarkerReceiver02023b5c *self = static_cast<MarkerReceiver02023b5c *>(receiver);
    Zone3D_GetInstance();
    if (!self->active) return;
    if (func_0202c540(func_0202ae18())) return;
    var0->unknown_9b4_ = (var0->unknown_9b4_ + GameState::GetInstance()->GetEffectiveDeltaTime()) % 0x300;
    int var1 = abs((var0->unknown_9b4_ - 0x180) / 0x18) + 2;
    if (var1 > 16) var1 = 16;
    bool var2 = true;
    unsigned char var3 = var0->unknown_780_;
    for (int var4 = 0; var4 < var3; var4++) {
        if (!func_02023a9c(static_cast<char *>(arg0), var4)) continue;
        Vector3i var5;
        var5 = var0->unknown_784_[var4].unknown_10_;
        fix32_t var6 = var0->unknown_38_;
        int var7         = static_cast<int>(static_cast<float>(FIX32_MULTIPLY(var5.x, var6)) / 4096.0f) - arg1;
        int var8         = static_cast<int>(static_cast<float>(FIX32_MULTIPLY(var5.z, var6)) / 4096.0f) - arg2;
        if (arg5) {
            var8 = -(static_cast<int>(static_cast<float>(FIX32_MULTIPLY(var5.y, var6)) / 4096.0f) - arg2);
        }
        if (!var0->unknown_9ba_) continue;
        ColorEffect_ConfigureAlphaBlend(var2 ? 0x04001050 : 0x04000050, 0, 3, var1, 16 - var1);
        func_0202756c(arg0, (var7 + arg3) << 12, (var8 + arg4) << 12, 0x17,
                                 static_cast<unsigned char>(var4 + 0x60), 1, 0xff, 0xff, 0x1000, 0x1000);
    }
}
