#include <globaldefs.h>
#include "std_library_functions.h"
#include "NitroSDK/Cache.h"
#include "NitroSDK/LoadToVRAM.h"

struct Struct_0203c35c {
    #if defined(jpn)
    unsigned char unknown_0_[0x604];
    #else
    unsigned char unknown1_0_[0x504];
    #endif
    int unknown_504_;
    int unknown_508_;
    unsigned int unknown_50c_;
    #if defined(jpn)
    unsigned char unknown_610_[4];
    unsigned short unknown_614_[112];
    #endif
};
struct Struct_0203c35c_2 {
    unsigned char unknown_0_[0x60];
    unsigned short* unknown_60_;
};
struct Struct_020e78c4 {
    float unknown_0_;
    float unknown_4_;
    float unknown_8_;
};
#if defined(jpn)
extern Struct_0203c35c* data_02105244;
#define data_020e78c4 data_020e8220
#define data_020e78b0 data_020e81ec
#define data_020e78a0 data_020e81dc
#else
int MessageSystem_GetInstance();
#endif
extern Struct_020e78c4 data_020e78c4[] __attribute__((aligned(4)));
extern float data_020e78b0[];
extern unsigned short data_020e78a0[];

// USA: func_0203c35c
extern "C" ARM void func_0203c35c(Struct_0203c35c* arg0) {
    int var0;
    int var1;
    int var2;
    const float* var3;
    unsigned short* var4;
    unsigned int var5;
    int var6;
    unsigned short var7[16] = {};
#if defined(jpn)
    var4 = data_02105244->unknown_614_;
#else
    palette = ((PaletteWork0203c35c*)MessageSystem_GetInstance())->palette;
#endif
    unsigned short var8 = 0xe0;
    memset(var4, 0, var8);
    for (var5 = 0; var5 < 7; var5++) {
        var7[1] = 0x294a;
        if (var5 == 6) var7[1] = 0x18c6;
        const Struct_020e78c4* var9 = &data_020e78c4[var5];
        const float& var10 = var9->unknown_0_;
        const float& var11 = var9->unknown_4_;
        for (var6 = 0, var3 = data_020e78b0; var6 < 5; var6++) {
            float var12 = var3[var6];
            var12 *= var10;
            var2 = (int)var12;
            var12 = var3[var6];
            var12 *= var11;
            var0 = (int)var12;
            var12 = var3[var6];
            var12 *= var9->unknown_8_;
            var1 = (int)var12;
            int var13 = var2 >> 3;
            int var14 = var0 >> 3;
            int var15 = var1 >> 3;
            int var16 = var14 << 5;
            var16 |= var13;
            var16 |= var15 << 10;
            var7[var6 + 2] = var16;
        }
        var7[15] = data_020e78a0[var5];
        memcpy(var4 + var5 * 16, var7, 0x20);
    }
    CleanInvalidateCacheRange(var4, 0xe0);
    if (arg0->unknown_504_ == 0) LoadToMainObjStandardPalette(var4, arg0->unknown_50c_, 0xe0);
    else if (arg0->unknown_504_ == 1) LoadToSubObjStandardPalette(var4, arg0->unknown_50c_, 0xe0);
}
