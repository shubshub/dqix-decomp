#include <globaldefs.h>
#include "Resource/GameResources.h"
#include "Resource/Brightness.h"
#include "Resource/MessageSystem.h"
#include "Grotto/Main/TreasureMapDataStructs.h"
#include "NitroSDK/Memory.h"
#include "std_library_functions.h"

struct Struct_ov004_02163c40 {
    TreasureMapMetadata unknown_0_[99];
    DetailedTreasureMapData unknown_ad4_[8];
    unsigned char unknown_18f4_;
    char unknown_18f5_[5];
    unsigned char unknown_18fa_;
    char unknown_18fb_[3];
    unsigned char unknown_18fe_;
};
struct Node3C40 { char field_0[0xc]; unsigned char flags; char field_d[0x38 - 0xd]; unsigned short selected; };
struct SePlayer;
extern MapList3C40* data_ov004_02171010;
extern SePlayer g_sePlayer;
#if defined(jpn)
extern unsigned short data_ov004_02170660[3];
#else
extern unsigned short data_ov004_0216fef8[3];
#endif
extern "C" void func_ov023_021f809c(void*, void*);
MessageSystem* MessageSystem_GetInstance();
int SePlayer_Play(SePlayer*, int, int);
extern "C" void func_ov004_02163478(MapList3C40*);
extern "C" void* func_ov011_021849c8(void*);
extern "C" Struct_ov004_02163c40_2* func_ov023_021f6880(void*, int);
extern "C" short func_ov023_021f6f10(void*);
extern "C" void func_ov023_021f6680(void*, int);
extern "C" void func_ov023_021f6600(void*, int, int);
extern "C" void func_ov004_02164084(void*);

// USA: func_ov004_02163c40
// JPN: 0x02164150.
extern "C" ARM int func_ov004_02163c40(void* self) {
    TreasureMapMetadata maps[99];
    unsigned short indices[99];
    unsigned short scores[99];
    DetailedTreasureMapData detail;
    unsigned short modes[3];
    int forward;
    int backward;
    int changed;
    int last;
    int first;
    unsigned short selected;
    int brightness = IsBrightnessTransitionActive(GetGameResources());
    if (brightness && !data_ov004_02171010->field_18fe) return 0;
    if (!data_ov004_02171010->count) return 0;
    if (MessageSystem_GetInstance()->active) return 0;
    if (!data_ov004_02171010->field_18fe) {
        SePlayer_Play(&g_sePlayer, 1, 0);
    }
#if defined(jpn)
    COPY_ARRAY(var4, data_ov004_02170660);
#else
    COPY_ARRAY(var4, data_ov004_0216fef8);
#endif
    var10 = var4[data_ov004_02171010->unknown_18fa_];
    VectorizedInvertedMemcpy(data_ov004_02171010, var0, sizeof(var0));
    for (int var12 = 0; var12 < 99; var12++) var1[var12] = var12;
    for (unsigned int var13 = 0; var13 < 99; var13++) {
        if (static_cast<int>(var13) >= data_ov004_02171010->unknown_18f4_) {
            var2[var13] = 0xffff;
        } else {
            var2[var13] = 0;
            var3.Clear();
            ExportDetailedTreasureMapData(&data_ov004_02171010->unknown_0_[var13], &var3, false, 0);
            if (data_ov004_02171010->unknown_18fa_ == 0) {
                var2[var13] += var3.discoveryState_ * 1000;
                if (var3.mapType_ == 1) var2[var13] += var3.regular_.level_ * 10;
                else if (var3.mapType_ == 2) var2[var13] += var3.legacy_.level_ * 10;
                var2[var13] += var3.mapType_;
            } else if (data_ov004_02171010->unknown_18fa_ == 1) {
                if (var3.mapType_ == 1) var2[var13] += var3.regular_.level_ * 10;
                else if (var3.mapType_ == 2) var2[var13] += var3.legacy_.level_ * 10;
                var2[var13] += var3.mapType_;
            } else if (data_ov004_02171010->unknown_18fa_ == 2) {
                var2[var13] += (2 - var3.mapType_) * 1000;
                var2[var13] += var3.discoveryState_ * 100;
                if (var3.mapType_ == 1) var2[var13] += var3.regular_.level_;
                else if (var3.mapType_ == 2) var2[var13] += var3.legacy_.level_;
            }
            var3.BlankFunction();
        }
    }
    var9 = 0;
    var8 = 98;
    while (var8 > var9) {
        var7 = 0;
        for (var5 = var9; var5 < var8; var5++) {
            unsigned short var14 = var2[var5 + 1];
            unsigned short var15 = var2[var5];
            if (var15 > var14) {
                unsigned short var16 = var1[var5];
                unsigned short var17 = var1[var5 + 1];
                var2[var5] = var14;
                var7 = var5;
                var1[var5] = var17;
                var2[var5 + 1] = var15;
                var1[var5 + 1] = var16;
            }
        }
        var8 = var7;
        var9++;
        for (var6 = var8; var6 >= var9; var6--) {
            unsigned short var18 = var2[var6];
            unsigned short var19 = var2[var6 - 1];
            if (var19 > var18) {
                unsigned short var20 = var1[var6 - 1];
                unsigned short var21 = var1[var6];
                var2[var6 - 1] = var18;
                var7 = var6;
                var1[var6 - 1] = var21;
                var2[var6] = var19;
                var1[var6] = var20;
            }
        }
        var9 = var7;
    }
    for (int var22 = 0; var22 < 99; var22++) {
        VectorizedInvertedMemcpy(&var0[var1[var22]], &data_ov004_02171010->unknown_0_[var22], sizeof(TreasureMapMetadata));
    }
    func_ov004_02163478(data_ov004_02171010);
    Struct_ov004_02163c40_2* var23 = func_ov023_021f6880(func_ov011_021849c8(arg0), 0x35);
    if (var23 && func_ov023_021f6f10(var23) == 8) var23->unknown_38_ = var10;
#if defined(jpn)
    Struct_ov004_02163c40_2* var24 = func_ov023_021f6880(func_ov011_021849c8(arg0), 0x16);
    if (!var24) return 0;
    if (func_ov023_021f6f10(var24) != 6) return 0;
    func_ov023_021f809c(var24, arg0);
    var24->unknown_c_ &= ~8;
#else
    func_ov023_021f6680(arg0, 0x16);
    func_ov023_021f6600(arg0, 0x16, 8);
#endif
    func_ov004_02164084(arg0);
    return 0;
}
