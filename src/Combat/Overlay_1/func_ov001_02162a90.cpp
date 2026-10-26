#include <globaldefs.h>
#include "NitroSDK/Graphics.h"
#include "NitroSDK/VRAM.h"

typedef enum
{
    Enum_02000c9c_E_0 = 0,
    Enum_02000c9c_E_1 = 1,
    Enum_02000c9c_E_2 = 2,
    Enum_02000c9c_E_3 = 3
} Enum_02000c9c_E;

typedef enum
{
    Enum_02000c9c_B_0  = 0,
    Enum_02000c9c_B_1 = 1
} Enum_02000c9c_B;

typedef enum
{
    Enum_02000c9c_C_0 = 0,
    Enum_02000c9c_C_1 = 1,
    Enum_02000c9c_C_2 = 2,
    Enum_02000c9c_C_3 = 3,
    Enum_02000c9c_C_4 = 4,
    Enum_02000c9c_C_5 = 5,
    Enum_02000c9c_C_6 = 6,
    Enum_02000c9c_C_7 = 7,
    Enum_02000c9c_C_8 = 8,
    Enum_02000c9c_C_9 = 9,
    Enum_02000c9c_C_10 = 10,
    Enum_02000c9c_C_11 = 11,
    Enum_02000c9c_C_12 = 12,
    Enum_02000c9c_C_13 = 13,
    Enum_02000c9c_C_14 = 14,
    Enum_02000c9c_C_15 = 15
} Enum_02000c9c_C;

typedef enum
{
    Enum_02000c9c_D_0 = 0,
    Enum_02000c9c_D_1 = 1,
    Enum_02000c9c_D_2 = 2,
    Enum_02000c9c_D_3 = 3,
    Enum_02000c9c_D_4 = 4,
    Enum_02000c9c_D_5 = 5,
    Enum_02000c9c_D_6 = 6,
    Enum_02000c9c_D_7 = 7,
    Enum_02000c9c_D_8 = 8,
    Enum_02000c9c_D_9 = 9,
    Enum_02000c9c_D_10 = 10,
    Enum_02000c9c_D_11 = 11,
    Enum_02000c9c_D_12 = 12,
    Enum_02000c9c_D_13 = 13,
    Enum_02000c9c_D_14 = 14,
    Enum_02000c9c_D_15 = 15,
    Enum_02000c9c_D_16 = 16,
    Enum_02000c9c_D_17 = 17,
    Enum_02000c9c_D_18 = 18,
    Enum_02000c9c_D_19 = 19,
    Enum_02000c9c_D_20 = 20,
    Enum_02000c9c_D_21 = 21,
    Enum_02000c9c_D_22 = 22,
    Enum_02000c9c_D_23 = 23,
    Enum_02000c9c_D_24 = 24,
    Enum_02000c9c_D_25 = 25,
    Enum_02000c9c_D_26 = 26,
    Enum_02000c9c_D_27 = 27,
    Enum_02000c9c_D_28 = 28,
    Enum_02000c9c_D_29 = 29,
    Enum_02000c9c_D_30 = 30,
    Enum_02000c9c_D_31 = 31
} Enum_02000c9c_D;

typedef enum
{
    Enum_02000c9c_0 = 0,
    Enum_02000c9c_1 = 1
} Enum_02000c9c;

union Struct_ov001_02162a90 {
    unsigned short raw;
    struct {
        unsigned short priority : 2;
        unsigned short unknown_0_2_ : 4;
        unsigned short unknown_0_6_ : 1;
        unsigned short colorMode : 1;
        unsigned short screenBase : 5;
        unsigned short unknown_1_5_ : 1;
        unsigned short screenSize : 2;
    } fields;
};
struct Struct_ov001_021658b8_13 {
    char pad0[0x494];
    int unknown_494_;
    Struct_ov001_02162a90 unknown_498_[4];
    unsigned int unknown_4a0_;
    int unknown_4a4_;
    Struct_ov001_02162a90 sub[4];
    unsigned int unknown_4b0_;
};
extern Struct_ov001_021658b8_13 data_ov001_021658b8;
union Struct_ov017_021d60f4 {
    int i;
    float f;
};
struct Struct_ov001_0215f344 {
    int type;
    Struct_ov017_021d60f4 value;
};
extern "C" int func_ov017_021d60f4(Struct_ov001_0215f344*);
extern "C" void func_ov001_02162678(int, int, int, int);
extern "C" void func_ov001_0215e758(int, int, int, int, int);
extern "C" void func_ov001_0215e78c(int, int, int, int, int);
extern "C" void func_ov001_021628d4(int, int, int, int);

// USA: func_ov001_02162a90
extern "C" ARM int func_ov001_02162a90(Struct_ov001_0215f344* arguments) {
    Struct_ov001_02162a90 var0, var1, var2, var3;
    Struct_ov001_02162a90 var4, var5, var6, var7;
    int screen = func_ov017_021d60f4(arguments);
    if (screen == 0) {
        ReleaseMainBGVRAMBanks();
        MapVRAMBanksToMainBG(data_ov001_021658b8.unknown_494_);
        var0 = data_ov001_021658b8.unknown_498_[0];
        var1 = data_ov001_021658b8.unknown_498_[1];
        var2 = data_ov001_021658b8.unknown_498_[2];
        var3 = data_ov001_021658b8.unknown_498_[3];
        {
            Enum_02000c9c var9 = (Enum_02000c9c)var0.fields.unknown_1_5_;
            Enum_02000c9c_C var10 = (Enum_02000c9c_C)var0.fields.unknown_0_2_;
            Enum_02000c9c_D screenBase = (Enum_02000c9c_D)var0.fields.screenBase;
            Enum_02000c9c_B colorMode = (Enum_02000c9c_B)var0.fields.colorMode;
            Enum_02000c9c_E screenSize = (Enum_02000c9c_E)var0.fields.screenSize;
            BG0CNT = (unsigned short)((BG0CNT & 0x43)
                | (screenSize << 14)
                | (colorMode << 7)
                | (screenBase << 8)
                | (var10 << 2)
                | (var9 << 13));
        }
        {
            Enum_02000c9c var14 = (Enum_02000c9c)var1.fields.unknown_1_5_;
            Enum_02000c9c_C var15 = (Enum_02000c9c_C)var1.fields.unknown_0_2_;
            Enum_02000c9c_D screenBase = (Enum_02000c9c_D)var1.fields.screenBase;
            Enum_02000c9c_B colorMode = (Enum_02000c9c_B)var1.fields.colorMode;
            Enum_02000c9c_E screenSize = (Enum_02000c9c_E)var1.fields.screenSize;
            BG1CNT = (unsigned short)((BG1CNT & 0x43)
                | (screenSize << 14)
                | (colorMode << 7)
                | (screenBase << 8)
                | (var15 << 2)
                | (var14 << 13));
        }
        {
            Enum_02000c9c_C var19 = (Enum_02000c9c_C)var2.fields.unknown_0_2_;
            Enum_02000c9c_D screenBase = (Enum_02000c9c_D)var2.fields.screenBase;
            Enum_02000c9c_B colorMode = (Enum_02000c9c_B)var2.fields.colorMode;
            Enum_02000c9c_E screenSize = (Enum_02000c9c_E)var2.fields.screenSize;
            BG2CNT = (unsigned short)((BG2CNT & 0x43)
                | (screenSize << 14)
                | (colorMode << 7)
                | (screenBase << 8)
                | (var19 << 2));
        }
        func_ov001_02162678(var3.fields.screenSize, var3.fields.colorMode, var3.fields.screenBase, var3.fields.unknown_0_2_);
        DISPCNT = (DISPCNT & ~0x1f00) | (data_ov001_021658b8.unknown_4a0_ << 8);
    } else if (screen == 1) {
        ReleaseSubBGVRAMBanks();
        MapVRAMBanksToSubBG(data_ov001_021658b8.unknown_4a4_);
        var4 = data_ov001_021658b8.sub[0];
        var5 = data_ov001_021658b8.sub[1];
        var6 = data_ov001_021658b8.sub[2];
        var7 = data_ov001_021658b8.sub[3];
        func_ov001_0215e758(var4.fields.screenSize, var4.fields.colorMode, var4.fields.screenBase, var4.fields.unknown_0_2_, var4.fields.unknown_1_5_);
        func_ov001_0215e78c(var5.fields.screenSize, var5.fields.colorMode, var5.fields.screenBase, var5.fields.unknown_0_2_, var5.fields.unknown_1_5_);
        {
            Enum_02000c9c_C var23 = (Enum_02000c9c_C)var6.fields.unknown_0_2_;
            Enum_02000c9c_D screenBase = (Enum_02000c9c_D)var6.fields.screenBase;
            Enum_02000c9c_B colorMode = (Enum_02000c9c_B)var6.fields.colorMode;
            Enum_02000c9c_E screenSize = (Enum_02000c9c_E)var6.fields.screenSize;
            BG2CNTSUB = (unsigned short)((BG2CNTSUB & 0x43)
                | (screenSize << 14)
                | (colorMode << 7)
                | (screenBase << 8)
                | (var23 << 2));
        }
        func_ov001_021628d4(var7.fields.screenSize, var7.fields.colorMode, var7.fields.screenBase, var7.fields.unknown_0_2_);
        DISPCNTSUB = (DISPCNTSUB & ~0x1f00) | (data_ov001_021658b8.unknown_4b0_ << 8);
    }
    return 1;
}
