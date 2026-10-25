#include <globaldefs.h>
#include "GameState/GameState.h"

#define REG_MATRIX_PUSH (*(volatile unsigned int*)0x04000444)
#define REG_MATRIX_POP (*(volatile unsigned int*)0x04000448)
#define REG_MATRIX_SCALE (*(volatile unsigned int*)0x04000470)
#define REG_POLYGON_ATTR (*(volatile unsigned int*)0x04000500)
#define REG_TEXTURE_PARAM (*(volatile unsigned int*)0x04000504)

struct Struct_02000c9c_69 { unsigned char unknown_0_[4]; unsigned short unknown_4_; };
struct Struct_ov023_021e3fc0_3 {
    unsigned char unknown_0_[0x16c];
    short unknown_16c_[0x198];
    unsigned char unknown_49c_0_ : 1;
    unsigned char unknown_49c_1_ : 7;
#if defined(jpn)
    unsigned char unknown_49d_[0x8b8 - 0x49d];
#else
    unsigned char unknown1_49d_[0x4b3];
#endif

    int unknown_950_;
};
struct Struct_ov023_021e3fc0_4 {
    unsigned char unknown_0_[0x130];
    Struct_02000c9c_69* unknown_130_;
#if defined(jpn)
    unsigned char unknown_134_[0x10];
#else
    unsigned char unknown1_134_[0x1c];
#endif

    Struct_ov023_021e3fc0_3* unknown_150_;
    int inline_ov023_021e3fc0_2() const { return unknown_130_->unknown_4_; }
    Struct_ov023_021e3fc0_3* inline_ov023_021e3fc0() const { return unknown_150_; }
};
struct Struct_ov023_021e3fc0 {
    unsigned char unknown_0_[0x14];
    int unknown_14_;
    int unknown_18_;
    unsigned char unknown_1c_[6];
    unsigned char unknown_22_;
    unsigned char unknown_23_[3];
    unsigned char unknown_26_;
    unsigned char unknown_27_;
};
struct Struct_ov023_021e3fc0_2 {
    unsigned char unknown_0_[0x258];
    Struct_ov023_021e3fc0 unknown_258_;
};
#if defined(jpn)
struct Struct_02000c9c_66 { char unknown_0_[0xc]; };
#else
struct Struct_02000c9c_66 { char unknown_0_[0x20]; };
#endif

#if defined(jpn)
struct Struct_02000c9c_67 { char unknown_0_[6]; };
#else
struct Struct_02000c9c_67 { char unknown_0_[0x14]; };
#endif

#if defined(jpn)
struct Struct_02000c9c_68 { char unknown_0_[4]; };
#else
struct Struct_02000c9c_68 { char unknown_0_[0x10]; };
#endif

struct Struct_ov003_02165888 {
    void* unknown_0_;
    unsigned char unknown_4_[0xc4];
    void* unknown_c8_;
    Struct_ov023_021e3fc0_2* unknown_cc_;
#if defined(jpn)
    unsigned char unknown_d0_[0x428];
#else
    unsigned char unknown1_d0_[0x42c];
#endif

    int unknown_4fc_;
    Struct_02000c9c_66 unknown_500_[4];
    int unknown_580_[4];
    Struct_02000c9c_67 unknown_590_[4];
#if defined(jpn)
    char unknown_554_[4];
#else
    char unknown_5e0_[0x10];
#endif

    Struct_02000c9c_68 unknown_5f0_[4];
    unsigned char unknown_630_[0x10];
    char* unknown_640_[2];
};
struct Struct0200fb08;
void* MessageSystem_GetInstance();
extern "C" void func_02045f3c(void*, void*, int, int, int, int, int, int, int, int);
#if defined(jpn)
extern "C" void func_02046c78(void*, void*, int, int, int, int, int, int);
#endif
extern "C" int Font_GetTextWidth(const char*, int);
extern "C" void SpriteContext_DrawSprite(void*, void*);
unsigned char GetByteViaFieldIndirectOffset_021e4250_021e4250(char*);
char* StandardStrings_Get(int);
unsigned char GameState_GetLanguage(Struct0200fb08*);
extern "C" void func_ov005_02155258(void*, int, int, int, int);

// USA: func_ov023_021e3fc0
extern "C" ARM void func_ov023_021e3fc0(StatusPanel* panel) {
    int textColor;
    GameState* game = GameState::GetInstance();
    void* renderer = MessageSystem_GetInstance();
    int drawValue = 0x7fff;
    StatusCombatant* combatant = (StatusCombatant*)GetCombatantWithFlag0x100_0200ff1c(game, panel->selected);
    if (combatant->GetHP() <= 0) drawValue = 0x1f;
    REG_MATRIX_PUSH = 0;
    REG_POLYGON_ATTR = 1;
    REG_MATRIX_SCALE = 0;
    REG_MATRIX_SCALE = 0;
    REG_MATRIX_SCALE = 0xffc01000;
#if defined(jpn)
    func_02046c78(var2, &arg0->unknown_500_[arg0->unknown_4fc_], arg0->unknown_580_[arg0->unknown_4fc_], 0xa3, var3, 10, 0, 0);
    short var5 = 0x2f;
    if (func_ov023_021e4250((char*)var4)) var5 += 7;
    if (var4->inline_ov023_021e3fc0_2() <= 0) var5 = 0x14;
    var5 = ((0x3b - var5) >> 1) + 0x40;
    func_02046c78(var2, &arg0->unknown_590_[arg0->unknown_4fc_], var5, 0xa3, var3, 10, 0, 0);
    if (var4->inline_ov023_021e3fc0_2() > 0) {
        var5 += 0x14;
        if (func_ov023_021e4250((char*)var4)) {
            unsigned short var6 = 0xf0a;
            short var7 = 0xa4;
            if (func_ov023_021e4250((char*)var4) >= 10) {
                var7--;
                var6 = 0x31f;
            }
            func_02046c78(var2, &arg0->unknown_5f0_[arg0->unknown_4fc_], var5, var7, var6, 10, 0, 0);
            var5 += 7;
        }
        var5 += 2;
        func_02046c78(var2, arg0->unknown_554_, var5, 0xa3, var3, 10, 0, 0);
        if (arg0->unknown_0_) {
            Struct_ov023_021e3fc0_3* var8 = var4->inline_ov023_021e3fc0();
            var0 = var3;
            var3 = var8->unknown_16c_[var8->unknown_950_];
            func_ov005_02155258(arg0->unknown_0_, var3, (short)(var5 + 9), 0xa5, var0);
        }
    }

#else
    func_02045f3c(renderer, &panel->names[panel->selected], panel->positions[panel->selected], 0xa1, drawValue, 10, 0, 0, 0, 0x11);
    if (combatant->GetHP() <= 0) {
        short width = Font_GetTextWidth(panel->conditionNames[combatant->character->gender], 0);
        short x = ((0x3b - width) >> 1) + 0x40;
        func_02045f3c(renderer, &panel->conditions[panel->selected], x, 0xa1, drawValue, 10, 0, 0, 0, 0x11);
    } else {
        StatusSprites* sprites = panel->sprites;
        sprites->marker.x = 0x44000;
        sprites->marker.y = 0xa2000;
        sprites->marker.depth = 0x70;
        sprites->marker.mode = 2;
        SpriteContext_DrawSprite(panel->renderer, &sprites->marker);
        if (GetByteViaFieldIndirectOffset_021e4250_021e4250((char*)combatant)) {
            unsigned short valueColor = 0xf0a;
            if (GetByteViaFieldIndirectOffset_021e4250_021e4250((char*)combatant) >= 10)
                valueColor = 0x31f;
            func_02045f3c(renderer, &panel->values[panel->selected], 0x50, 0xa1, valueColor, 10, 0, 0, 0, 0x11);
        }
        func_02045f3c(renderer, panel->label, 0x5c, 0xa1, drawValue, 10, 0, 0, 0, 0x11);
        short x = Font_GetTextWidth(StandardStrings_Get(0x3f3), 0) + 0x5e;
        if (GameState_GetLanguage((Struct0200fb08*)game) == 1) x += 2;
        StatusCharacter* character = combatant->GetCharacter();
        textColor = drawValue;
        drawValue = character->values[character->index];
        func_ov005_02155258(panel->context, drawValue, x, 0xa1, textColor);
    }

#endif
    REG_TEXTURE_PARAM = 0;
    REG_MATRIX_POP = 1;
}
