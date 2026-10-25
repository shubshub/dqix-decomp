#include <globaldefs.h>
#include "Graphics/SpriteAffineTransform.h"
#include "NitroSDK/Cache.h"
#include "NitroSDK/LoadToVRAM.h"
#include <std_library_functions.h>

#if defined(jpn)
#define REGION(j,u) (j)
#define data_ov023_021fd565 data_ov023_021fc854
#else
#define REGION(j,u) (u)
#endif

struct Struct_ov023_021dc520_2 { int unknown_0_; unsigned int unknown_4_0_:27; unsigned int unknown_7_3_:1; unsigned int unknown_7_4_:1; unsigned int unknown_7_5_:3; };
struct Struct_020dee58 { Struct_ov023_021dc520_2* unknown_0_; int unknown_4_; unsigned int unknown_8_0_:4; unsigned int unknown_8_4_:5; unsigned int unknown_9_1_:3; unsigned int unknown_9_4_:20; };
struct Struct_02075db0 { char unknown_0_[0x14]; void* unknown_14_; char unknown_18_[0xc]; int** unknown_24_; char unknown_28_[0x34]; unsigned short unknown_5c_; char unknown_5e_[2]; int unknown_60_, unknown_64_; };
struct Struct_ov023_021dc520_3 { char unknown_0_[0x2a0]; char unknown_2a0_[1]; };
struct Struct_ov023_021ffa0c { short unknown_0_; short unknown_2_; short unknown_4_, unknown_6_; };
struct Struct_ov023_021ff9e0_6 { char unknown_0_[0x4c]; short unknown_4c_; char unknown_4e_[2]; unsigned char unknown_50_; };
struct Struct_ov023_021dc520 {
    char unknown_0_[0x4c];
    Struct_020dee58* unknown_4c_;
    char unknown_50_[0x74];
    Struct_02075db0* unknown_c4_;
    char unknown_c8_[REGION(0x60,0x64)];
    Struct_0205ac40 unknown_12c_;
    Struct_0205ac40_2 unknown_180_[30];
    char unknown_630_[REGION(0xc4,0x144)];
    unsigned short unknown_774_;
    char unknown_776_[5];
    signed char unknown_77b_, unknown_77c_;
    char unknown_77d_[0x1e];
    unsigned char unknown_79b_0_:1;
    unsigned char unknown_79b_1_:1;
    unsigned char unknown_79b_2_:6;
};
extern Struct_ov023_021ff9e0_6 data_ov023_021ff9e0;
extern Struct_ov023_021ffa0c data_ov023_021ffa0c[3];
extern unsigned char data_ov023_021fd565[2][2];
extern "C" void* func_0203bd08();
extern "C" ObjectBuffer021dc520* func_0203be40(void*);
extern "C" ObjectBuffer021dc520* func_0203be4c(void*);
extern "C" void SpriteContext_DrawSprite(SpriteContext0205ac40*, B174Outer*);
short LookupValueFromField8(Obj020dee58*);
int ForwardTableValue02075db0(Struct02075db0*, int, int);
inline int PaletteOffset021dc520(int index) { return index * 2; }
inline int IsStandardCategory021dc520(Obj020dee58* selection) {
    return selection->lowNibble <= 7;
}

// USA: func_ov023_021dc520
extern "C" ARM void func_ov023_021dc520(Struct_ov023_021dc520* arg0) {
    if (arg0->unknown_77b_ == 1) {
        if (!arg0->unknown_79b_1_ || !(arg0->unknown_774_ & 0x2000)) return;
    }
    if (!(arg0->unknown_774_ & 2) || !arg0->unknown_4c_) return;
    Struct_0205ac40_2* var0;
    Struct_ov023_021dc520_3* var1;
    if (arg0->unknown_77c_ == 0) {
        Struct_ov023_021dc520_3* var2 = func_0203be40(func_0203bd08());
        var1 = var2;
    } else {
        Struct_ov023_021dc520_3* var3 = func_0203be4c(func_0203bd08());
        var1 = var3;
    }
    if (data_ov023_021ff9e0.unknown_50_) {
        for (int var4 = 0; var4 < 3; ++var4) {
            short var5 = data_ov023_021ffa0c[var4].unknown_0_;
            Struct_ov023_021ffa0c* var6 = &data_ov023_021ffa0c[var4];
            int var7 = 0;
            float var8;
            if (var4 == 2) {
                var8 = 0.0001f + (float)(20 - (var5 - 3)) / 20.0f;
                if (var8 < 0.2f) var7 = 1;
                else if (var8 < 0.4f) var7 = 2;
                else if (var8 < 0.6f) var7 = 3;
                else if (var8 < 0.8f) var7 = 2;
                else if (var8 < 1.0f) var7 = 1;
            } else {
                var8 = 0.0001f + (float)(10 - (var5 - 5)) / 10.0f;
                if (var8 < 0.25f) var7 = 1;
                else if (var8 < 0.75f) var7 = 2;
                else if (var8 < 1.0f) var7 = 1;
            }
            if (style > 0) {
                if (style == 1) sprite = &view->sprites[26];
                else if (style == 2) sprite = &view->sprites[27];
                else sprite = &view->sprites[28];
                int y = (gauge->y + 10) << 12;
                int x = (gauge->x + REGION(190,202)) << 12;
                sprite->position[0] = x;
                sprite->position[1] = y;
                sprite->firstObject = i + 0x48;
                SpriteContext_DrawSprite(&view->renderer, sprite);
            }
        }
    }
    if (!(arg0->unknown_774_ & 0x1000)) {
        int var11 = REGION(191,203);
        unsigned char var12 = 0;
        while (var12 < arg0->unknown_4c_->unknown_9_1_) {
            var0 = &arg0->unknown_180_[21];
            int var13 = 0;
            if (arg0->unknown_4c_->unknown_9_1_ == 5) {
                var0 = &arg0->unknown_180_[24];
                var13 = 1;
                int var14 = abs(20 - data_ov023_021ff9e0.unknown_4c_) - 5;
                if (var14 < 0) var14 = 0;
                else if (var14 > 10) var14 = 10;
                for (int var15 = 2; var15 <= 6; ++var15) {
                    int var16 = var14 + var15 * 3 - 14;
                    int var17 = (var16 * 10) / 10 + 14;
                    int var18 = (var16 * 3) / 10 + 29;
                    if (var17 > 31) var17 = 31;
                    if (var18 > 31) var18 = 31;
                    if (var17 < 0) var17 = 0;
                    if (var18 < 0) var18 = 0;
                    unsigned short var19 = var17 | (var18 << 5) | (var18 << 10);
                    int var20 = inline_ov023_021dc520(var15);
                    CleanInvalidateCacheRange(&var19, 2);
                    int var21 = 0xe0 + var20;
                    if (arg0->unknown_77c_ == 0) LoadToMainObjStandardPalette(&var19, var21, 2);
                    else LoadToSubObjStandardPalette(&var19, var21, 2);
                }
            }
            sprite->position[0] = (x + offset) << 12;
            sprite->position[1] = (offset + 11) << 12;
            sprite->firstObject = index + 0x4c;
            SpriteContext_DrawSprite(&view->renderer, sprite);
            x += 8;
            ++index;
        }
    }
    int lookup = LookupValueFromField8(view->selection);
    sprite = &view->sprites[lookup + 1];
    sprite->position[0] = REGION(0x18000,0x10000);
    sprite->position[1] = 0x8000;
    sprite->firstObject = 0x52;
    SpriteContext_DrawSprite(&view->renderer, sprite);
    if (IsStandardCategory021dc520(view->selection)) {
        int first = 0, second = 0;
        ParentFlags021dc520* parent = view->selection->parent;
        if (parent) {
            if (parent->first == 1) first = 1;
            if (parent->second == 1) second = 1;
        }
        unsigned char indicator = data_ov023_021fd565[first][second];
        if (indicator) {
            sprite = &view->sprites[indicator];
            sprite->position[0] = REGION(0x9a000,0x90000);
            sprite->position[1] = 0x8000;
            sprite->firstObject = 0x53;
            SpriteContext_DrawSprite(&view->renderer, sprite);
        }
        if (!(arg0->unknown_774_ & 8)) {
            func_0203bd08();
            arg0->unknown_c4_->unknown_14_ = var1->unknown_2a0_;
            func_02075db0(arg0->unknown_c4_, 0x1c, 0x34);
        }
    } else {
        if (!(arg0->unknown_774_ & 8)) {
            arg0->unknown_c4_->unknown_14_ = var1->unknown_2a0_;
            func_02075db0(arg0->unknown_c4_, 0x1c, 0x34);
        }
    }
}
