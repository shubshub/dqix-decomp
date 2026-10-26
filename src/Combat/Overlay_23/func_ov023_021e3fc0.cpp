#include <globaldefs.h>
#include "GameState/GameState.h"
#if defined(jpn)
#define func_02046c78 func_02047a98
#endif

#define REG_MATRIX_PUSH (*(volatile unsigned int*)0x04000444)
#define REG_MATRIX_POP (*(volatile unsigned int*)0x04000448)
#define REG_MATRIX_SCALE (*(volatile unsigned int*)0x04000470)
#define REG_POLYGON_ATTR (*(volatile unsigned int*)0x04000500)
#define REG_TEXTURE_PARAM (*(volatile unsigned int*)0x04000504)

struct Struct_02000c9c_69 { unsigned char padding0[4]; unsigned short hp; };
struct Struct_ov023_021e3fc0_3 {
    unsigned char padding0[0x16c];
    short values[0x198];
    unsigned char gender : 1;
    unsigned char flags : 7;
#if defined(jpn)
    unsigned char unknown_49d_[0x8b8 - 0x49d];
#else
    unsigned char unknown1_49d_[0x4b3];
#endif

    int index;
};
struct Struct_ov023_021e3fc0_4 {
    unsigned char padding0[0x130];
    Struct_02000c9c_69* unknown_130_;
#if defined(jpn)
    unsigned char unknown_134_[0x10];
#else
    unsigned char unknown1_134_[0x1c];
#endif

    Struct_ov023_021e3fc0_3* character;
    int inline_ov023_021e3fc0_2() const { return unknown_130_->hp; }
    Struct_ov023_021e3fc0_3* inline_ov023_021e3fc0() const { return character; }
};
struct Struct_ov023_021e3fc0 {
    unsigned char padding0[0x14];
    int x;
    int y;
    unsigned char padding1c[6];
    unsigned char depth;
    unsigned char unknown_23_[3];
    unsigned char mode;
    unsigned char unknown_27_;
};
struct Struct_ov023_021e3fc0_2 {
    unsigned char padding0[0x258];
    Struct_ov023_021e3fc0 marker;
};
#if defined(jpn)
struct Struct_02000c9c_66 { char text[0xc]; };
#else
struct Struct_02000c9c_66 { char text[0x20]; };
#endif

#if defined(jpn)
struct Struct_02000c9c_67 { char text[6]; };
#else
struct Struct_02000c9c_67 { char text[0x14]; };
#endif

#if defined(jpn)
struct Struct_02000c9c_68 { char text[4]; };
#else
struct Struct_02000c9c_68 { char text[0x10]; };
#endif

struct Struct_ov003_02165888 {
    void* context;
    unsigned char padding4[0xc4];
    void* renderer;
    Struct_ov023_021e3fc0_2* sprites;
#if defined(jpn)
    unsigned char unknown_d0_[0x428];
#else
    unsigned char unknown1_d0_[0x42c];
#endif

    int selected;
    Struct_02000c9c_66 names[4];
    int positions[4];
    Struct_02000c9c_67 unknown_590_[4];
#if defined(jpn)
    char label[4];
#else
    char label[0x10];
#endif

    Struct_02000c9c_68 values[4];
    unsigned char unknown_630_[0x10];
    char* conditionNames[2];
};
struct Struct0200fb08;
extern "C" void* MessageSystem_GetInstance();
extern "C" void func_02045f3c(void*, void*, int, int, int, int, int, int, int, int);
#if defined(jpn)
extern "C" void func_02046c78(void*, void*, int, int, int, int, int, int);
#endif
extern "C" int Font_GetTextWidth(const char*, int);
extern "C" void SpriteContext_DrawSprite(void*, void*);
extern "C" unsigned char func_ov023_021e4250(char*);
extern "C" char* StandardStrings_Get(int);
extern "C" unsigned char GameState_GetLanguage(Struct0200fb08*);
extern "C" void func_ov005_02155258(void*, int, int, int, int);

// USA: func_ov023_021e3fc0
extern "C" ARM void func_ov023_021e3fc0(Struct_ov003_02165888* panel) {
    int textColor;
    GameState* game = GameState::GetInstance();
    void* renderer = MessageSystem_GetInstance();
    int var3 = 0x7fff;
    Struct_ov023_021e3fc0_4* combatant = (Struct_ov023_021e3fc0_4*)func_0200ff1c(game, panel->selected);
    if (combatant->inline_ov023_021e3fc0_2() <= 0) var3 = 0x1f;
    REG_MATRIX_PUSH = 0;
    REG_POLYGON_ATTR = 1;
    REG_MATRIX_SCALE = 0;
    REG_MATRIX_SCALE = 0;
    REG_MATRIX_SCALE = 0xffc01000;
#if defined(jpn)
    func_02046c78(renderer, &panel->names[panel->selected], panel->positions[panel->selected], 0xa3, var3, 10, 0, 0);
    short x = 0x2f;
    if (func_ov023_021e4250((char*)combatant)) x += 7;
    if (combatant->inline_ov023_021e3fc0_2() <= 0) x = 0x14;
    x = ((0x3b - x) >> 1) + 0x40;
    func_02046c78(renderer, &panel->unknown_590_[panel->selected], x, 0xa3, var3, 10, 0, 0);
    if (combatant->inline_ov023_021e3fc0_2() > 0) {
        x += 0x14;
        if (func_ov023_021e4250((char*)combatant)) {
            unsigned short var6 = 0xf0a;
            short y = 0xa4;
            if (func_ov023_021e4250((char*)combatant) >= 10) {
                y--;
                var6 = 0x31f;
            }
            func_02046c78(renderer, &panel->values[panel->selected], x, y, var6, 10, 0, 0);
            x += 7;
        }
        x += 2;
        func_02046c78(renderer, panel->label, x, 0xa3, var3, 10, 0, 0);
        if (panel->context) {
            Struct_ov023_021e3fc0_3* character = combatant->inline_ov023_021e3fc0();
            textColor = var3;
            var3 = character->values[character->index];
            func_ov005_02155258(panel->context, var3, (short)(x + 9), 0xa5, textColor);
        }
    }

#else
    func_02045f3c(renderer, &panel->names[panel->selected], panel->positions[panel->selected], 0xa1, var3, 10, 0, 0, 0, 0x11);
    if (combatant->inline_ov023_021e3fc0_2() <= 0) {
        short width = Font_GetTextWidth(panel->conditionNames[combatant->character->gender], 0);
        short x = ((0x3b - width) >> 1) + 0x40;
        func_02045f3c(renderer, &panel->unknown_590_[panel->selected], x, 0xa1, var3, 10, 0, 0, 0, 0x11);
    } else {
        Struct_ov023_021e3fc0_2* sprites = panel->sprites;
        sprites->marker.x = 0x44000;
        sprites->marker.y = 0xa2000;
        sprites->marker.depth = 0x70;
        sprites->marker.mode = 2;
        SpriteContext_DrawSprite(panel->renderer, &sprites->marker);
        if (func_ov023_021e4250((char*)combatant)) {
            unsigned short var12 = 0xf0a;
            if (func_ov023_021e4250((char*)combatant) >= 10)
                var12 = 0x31f;
            func_02045f3c(renderer, &panel->values[panel->selected], 0x50, 0xa1, var12, 10, 0, 0, 0, 0x11);
        }
        func_02045f3c(renderer, panel->label, 0x5c, 0xa1, var3, 10, 0, 0, 0, 0x11);
        short x = Font_GetTextWidth(StandardStrings_Get(0x3f3), 0) + 0x5e;
        if (GameState_GetLanguage((Struct0200fb08*)game) == 1) x += 2;
        Struct_ov023_021e3fc0_3* character = combatant->inline_ov023_021e3fc0();
        textColor = var3;
        var3 = character->values[character->index];
        func_ov005_02155258(panel->context, var3, x, 0xa1, textColor);
    }

#endif
    REG_TEXTURE_PARAM = 0;
    REG_MATRIX_POP = 1;
}
