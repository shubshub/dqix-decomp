#include <globaldefs.h>
#include "Resource/GameResources.h"
#include "Resource/Brightness.h"
#include "Resource/MessageSystem.h"
#include "Grotto/Main/TreasureMapDataStructs.h"
#include "NitroSDK/Memory.h"
#include "std_library_functions.h"

struct Struct_ov004_02163c40 {
    TreasureMapMetadata unknown_0_[99];
    DetailedTreasureMapData details[8];
    unsigned char count;
    char unknown_18f5_[5];
    unsigned char unknown_18fa_;
    char unknown_18fb_[3];
    unsigned char unknown_18fe_;
};
struct Struct_ov004_02163c40_2 { char field_0[0xc]; unsigned char flags; char unknown_d_[0x38 - 0xd]; unsigned short selected; };
struct SePlayer;
extern Struct_ov004_02163c40* data_ov004_02171010;
extern SePlayer g_sePlayer;
#if defined(jpn)
extern unsigned short data_ov004_02170660[3];
#else
extern unsigned short data_ov004_0216fef8[3];
#endif
extern "C" void func_ov023_021f809c(void*, void*);
extern "C" MessageSystem* MessageSystem_GetInstance();
extern "C" int SePlayer_Play(SePlayer*, int, int);
extern "C" void func_ov004_02163478(Struct_ov004_02163c40*);
extern "C" void* func_ov011_021849c8(void*);
extern "C" Struct_ov004_02163c40_2* func_ov023_021f6880(void*, int);
extern "C" short func_ov023_021f6f10(void*);
extern "C" void func_ov023_021f6680(void*, int);
extern "C" void func_ov023_021f6600(void*, int, int);
extern "C" void func_ov004_02164084(void*);

// USA: func_ov004_02163c40
// JPN: 0x02164150.
extern "C" ARM int func_ov004_02163c40(void* self) {
    TreasureMapMetadata var0[99];
    unsigned short indices[99];
    unsigned short var2[99];
    DetailedTreasureMapData detail;
    unsigned short var4[3];
    int forward;
    int var6;
    int changed;
    int last;
    int first;
    unsigned short selected;
    int brightness = IsBrightnessTransitionActive(GetGameResources());
    if (brightness && !data_ov004_02171010->unknown_18fe_) return 0;
    if (!data_ov004_02171010->count) return 0;
    if (MessageSystem_GetInstance()->active) return 0;
    if (!data_ov004_02171010->unknown_18fe_) {
        SePlayer_Play(&g_sePlayer, 1, 0);
    }
#if defined(jpn)
    COPY_ARRAY(var4, data_ov004_02170660);
#else
    COPY_ARRAY(var4, data_ov004_0216fef8);
#endif
    selected = var4[data_ov004_02171010->unknown_18fa_];
    VectorizedInvertedMemcpy(data_ov004_02171010, var0, sizeof(var0));
    for (int i = 0; i < 99; i++) indices[i] = i;
    for (unsigned int i = 0; i < 99; i++) {
        if (static_cast<int>(i) >= data_ov004_02171010->count) {
            var2[i] = 0xffff;
        } else {
            var2[i] = 0;
            detail.Clear();
            ExportDetailedTreasureMapData(&data_ov004_02171010->unknown_0_[i], &detail, false, 0);
            if (data_ov004_02171010->unknown_18fa_ == 0) {
                var2[i] += detail.discoveryState_ * 1000;
                if (detail.mapType_ == 1) var2[i] += detail.regular_.level_ * 10;
                else if (detail.mapType_ == 2) var2[i] += detail.legacy_.level_ * 10;
                var2[i] += detail.mapType_;
            } else if (data_ov004_02171010->unknown_18fa_ == 1) {
                if (detail.mapType_ == 1) var2[i] += detail.regular_.level_ * 10;
                else if (detail.mapType_ == 2) var2[i] += detail.legacy_.level_ * 10;
                var2[i] += detail.mapType_;
            } else if (data_ov004_02171010->unknown_18fa_ == 2) {
                var2[i] += (2 - detail.mapType_) * 1000;
                var2[i] += detail.discoveryState_ * 100;
                if (detail.mapType_ == 1) var2[i] += detail.regular_.level_;
                else if (detail.mapType_ == 2) var2[i] += detail.legacy_.level_;
            }
            detail.BlankFunction();
        }
    }
    first = 0;
    last = 98;
    while (last > first) {
        changed = 0;
        for (forward = first; forward < last; forward++) {
            unsigned short var14 = var2[forward + 1];
            unsigned short var15 = var2[forward];
            if (var15 > var14) {
                unsigned short index = indices[forward];
                unsigned short var17 = indices[forward + 1];
                var2[forward] = var14;
                changed = forward;
                indices[forward] = var17;
                var2[forward + 1] = var15;
                indices[forward + 1] = index;
            }
        }
        last = changed;
        first++;
        for (var6 = last; var6 >= first; var6--) {
            unsigned short var18 = var2[var6];
            unsigned short var19 = var2[var6 - 1];
            if (var19 > var18) {
                unsigned short previousIndex = indices[var6 - 1];
                unsigned short index = indices[var6];
                var2[var6 - 1] = var18;
                changed = var6;
                indices[var6 - 1] = index;
                var2[var6] = var19;
                indices[var6] = previousIndex;
            }
        }
        first = changed;
    }
    for (int i = 0; i < 99; i++) {
        VectorizedInvertedMemcpy(&var0[indices[i]], &data_ov004_02171010->unknown_0_[i], sizeof(TreasureMapMetadata));
    }
    func_ov004_02163478(data_ov004_02171010);
    Struct_ov004_02163c40_2* node = func_ov023_021f6880(func_ov011_021849c8(self), 0x35);
    if (node && func_ov023_021f6f10(node) == 8) node->selected = selected;
#if defined(jpn)
    Struct_ov004_02163c40_2* var24 = func_ov023_021f6880(func_ov011_021849c8(self), 0x16);
    if (!var24) return 0;
    if (func_ov023_021f6f10(var24) != 6) return 0;
    func_ov023_021f809c(var24, self);
    var24->flags &= ~8;
#else
    func_ov023_021f6680(self, 0x16);
    func_ov023_021f6600(self, 0x16, 8);
#endif
    func_ov004_02164084(self);
    return 0;
}
