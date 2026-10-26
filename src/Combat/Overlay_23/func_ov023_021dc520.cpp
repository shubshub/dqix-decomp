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

struct Struct_ov023_021dc520_2 { int field0; unsigned int unknown0:27; unsigned int first:1; unsigned int second:1; unsigned int unknown_7_5_:3; };
struct Obj020dee58 { Struct_ov023_021dc520_2* parent; int field4; unsigned int unknown_8_0_:4; unsigned int unknown_8_4_:5; unsigned int unknown_9_1_:3; unsigned int unknown:20; };
struct Struct_02075db0 { char pad0[0x14]; void* objects; char pad18[0xc]; int** rows; char pad28[0x34]; unsigned short unknown_5c_; char unknown_5e_[2]; int unknown_60_, unknown_64_; };
struct ObjectBuffer021dc520 { char pad0[0x2a0]; char unknown_2a0_[1]; };
struct Struct_ov023_021ffa0c { short value; short unknown2; short x, y; };
struct Struct_ov023_021ff9e0_6 { char pad0[0x4c]; short unknown_4c_; char unknown_4e_[2]; unsigned char enabled; };
struct Struct_ov023_021dc520 {
    char pad0[0x4c];
    Obj020dee58* selection;
    char unknown_50_[0x74];
    Struct_02075db0* table;
    char unknown_c8_[REGION(0x60,0x64)];
    SpriteContext0205ac40 renderer;
    B174Outer sprites[30];
    char unknown_630_[REGION(0xc4,0x144)];
    unsigned short flags;
    char unknown_776_[5];
    signed char mode, subScreen;
    char unknown_77d_[0x1e];
    unsigned char unknown0:1;
    unsigned char unknown_79b_1_:1;
    unsigned char unknown_79b_2_:6;
};
extern Struct_ov023_021ff9e0_6 data_ov023_021ff9e0;
extern Struct_ov023_021ffa0c data_ov023_021ffa0c[3];
extern unsigned char data_ov023_021fd565[2][2];
extern "C" void* OamManager_GetInstance();
extern "C" ObjectBuffer021dc520* OamManager_GetMainOamBuffer(void*);
extern "C" ObjectBuffer021dc520* OamManager_GetSubOamBuffer(void*);
extern "C" void SpriteContext_DrawSprite(SpriteContext0205ac40*, B174Outer*);
extern "C" short func_020dee58(Obj020dee58*);
extern "C" int func_02075db0(Struct_02075db0*, int, int);
inline int inline_ov023_021dc520(int index) { return index * 2; }
inline int inline_ov023_021dc520_2(Obj020dee58* selection) {
    return selection->unknown_8_0_ <= 7;
}

// USA: func_ov023_021dc520
extern "C" ARM void func_ov023_021dc520(Struct_ov023_021dc520* view) {
    if (view->mode == 1) {
        if (!view->unknown_79b_1_ || !(view->flags & 0x2000)) return;
    }
    if (!(view->flags & 2) || !view->selection) return;
    B174Outer* sprite;
    ObjectBuffer021dc520* objects;
    if (view->subScreen == 0) {
        ObjectBuffer021dc520* screenObjects = OamManager_GetMainOamBuffer(OamManager_GetInstance());
        objects = screenObjects;
    } else {
        ObjectBuffer021dc520* screenObjects = OamManager_GetSubOamBuffer(OamManager_GetInstance());
        objects = screenObjects;
    }
    if (data_ov023_021ff9e0.enabled) {
        for (int i = 0; i < 3; ++i) {
            short var5 = data_ov023_021ffa0c[i].value;
            Struct_ov023_021ffa0c* gauge = &data_ov023_021ffa0c[i];
            int style = 0;
            float progress;
            if (i == 2) {
                progress = 0.0001f + (float)(20 - (var5 - 3)) / 20.0f;
                if (progress < 0.2f) style = 1;
                else if (progress < 0.4f) style = 2;
                else if (progress < 0.6f) style = 3;
                else if (progress < 0.8f) style = 2;
                else if (progress < 1.0f) style = 1;
            } else {
                progress = 0.0001f + (float)(10 - (var5 - 5)) / 10.0f;
                if (progress < 0.25f) style = 1;
                else if (progress < 0.75f) style = 2;
                else if (progress < 1.0f) style = 1;
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
    if (!(view->flags & 0x1000)) {
        int x = REGION(191,203);
        unsigned char index = 0;
        while (index < view->selection->unknown_9_1_) {
            sprite = &view->sprites[21];
            int offset = 0;
            if (view->selection->unknown_9_1_ == 5) {
                sprite = &view->sprites[24];
                offset = 1;
                int var14 = abs(20 - data_ov023_021ff9e0.unknown_4c_) - 5;
                if (var14 < 0) var14 = 0;
                else if (var14 > 10) var14 = 10;
                for (int paletteIndex = 2; paletteIndex <= 6; ++paletteIndex) {
                    int value = var14 + paletteIndex * 3 - 14;
                    int red = (value * 10) / 10 + 14;
                    int green = (value * 3) / 10 + 29;
                    if (red > 31) red = 31;
                    if (green > 31) green = 31;
                    if (red < 0) red = 0;
                    if (green < 0) green = 0;
                    unsigned short color = red | (green << 5) | (green << 10);
                    int paletteOffset = inline_ov023_021dc520(paletteIndex);
                    CleanInvalidateCacheRange(&color, 2);
                    int destination = 0xe0 + paletteOffset;
                    if (view->subScreen == 0) LoadToMainObjStandardPalette(&color, destination, 2);
                    else LoadToSubObjStandardPalette(&color, destination, 2);
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
    int lookup = func_020dee58(view->selection);
    sprite = &view->sprites[lookup + 1];
    sprite->position[0] = REGION(0x18000,0x10000);
    sprite->position[1] = 0x8000;
    sprite->firstObject = 0x52;
    SpriteContext_DrawSprite(&view->renderer, sprite);
    if (inline_ov023_021dc520_2(view->selection)) {
        int first = 0, second = 0;
        Struct_ov023_021dc520_2* parent = view->selection->parent;
        if (parent) {
            if (parent->first == 1) first = 1;
            if (parent->second == 1) second = 1;
        }
        unsigned char var26 = data_ov023_021fd565[first][second];
        if (var26) {
            sprite = &view->sprites[var26];
            sprite->position[0] = REGION(0x9a000,0x90000);
            sprite->position[1] = 0x8000;
            sprite->firstObject = 0x53;
            SpriteContext_DrawSprite(&view->renderer, sprite);
        }
        if (!(view->flags & 8)) {
            OamManager_GetInstance();
            view->table->objects = objects->unknown_2a0_;
            func_02075db0(view->table, 0x1c, 0x34);
        }
    } else {
        if (!(view->flags & 8)) {
            view->table->objects = objects->unknown_2a0_;
            func_02075db0(view->table, 0x1c, 0x34);
        }
    }
}
