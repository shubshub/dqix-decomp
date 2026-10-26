#include <globaldefs.h>
#include <GameState/GameState.h>

struct Struct_020546c8;
struct Struct_0200ffc0;
struct Struct_0200ffd0;
struct Struct_02059720;
struct Struct_02059720_2 { char unknown_0_[3]; unsigned char unknown_3_; };
struct Struct_02059720_3 { char unknown_0_[0x130]; unsigned int unknown_130_; };
struct Struct_02059720_4 {
    int unknown_0_, unknown_4_, unknown_8_;
    unsigned char unknown_c_;
    char unknown_d_[3];
    int unknown_10_, unknown_14_, unknown_18_;
    char unknown_1c_[0xc];
    Struct_020546c8* unknown_28_;
    unsigned char unknown_2c_, unknown_2d_, unknown_2e_, unknown_2f_;
    float unknown_30_, unknown_34_, unknown_38_, unknown_3c_, unknown_40_, unknown_44_, unknown_48_, unknown_4c_;
    char unknown_50_[0x2c];
    Object3D unknown_7c_;
    char unknown_128_[4];
    float unknown_12c_, unknown_130_, unknown_134_, unknown_138_, unknown_13c_, unknown_140_, unknown_144_;
};
int CheckByte0xcZeroAndField8LeField4(State02059a2c*);
void* GetSubField0x14_02055108(S02055080*);
void* GameState_GetShip(PointerField32c_ffc0*);
void* GameState_GetStarflight(PointerField330_ffd0*);
extern "C" void func_02058750(Animation02059720*);
extern "C" void func_020589b8(Animation02059720*);
extern "C" void func_02058b3c(Animation02059720*);

// USA: func_02059720
extern "C" ARM void func_02059720(Struct_02059720_4* arg0) {
    if (!arg0->unknown_2c_) return;
    if (func_02059a2c((Struct_02059720*)arg0)) return;
    if (arg0->unknown_7c_.HasAnimationStopped()) {
        Struct_02059720_2* var0 = (Struct_02059720_2*)func_02055108(arg0->unknown_28_);
        if (var0->unknown_3_) {
            arg0->unknown_c_ = 0;
            arg0->unknown_2c_ = 0;
            return;
        }
    }
    GameState* var1 = GameState::GetInstance();
    int var2 = var1->GetTickCount();
    arg0->unknown_4_ += var2;
    if (func_02059a2c((Struct_02059720*)arg0)) {
        arg0->unknown_2c_ = 0;
        return;
    }
    self->red += self->redRate * (float)elapsed;
    self->green += self->greenRate * (float)elapsed;
    self->blue += self->blueRate * (float)elapsed;
    self->alpha += self->alphaRate * (float)elapsed;
    if (self->red < 0.0f) self->red = 0.0f;
    if (self->green < 0.0f) self->green = 0.0f;
    if (self->blue < 0.0f) self->blue = 0.0f;
    if (self->alpha < 0.0f) self->alpha = 0.0f;
    if (self->red > 31.0f) self->red = 31.0f;
    if (self->green > 31.0f) self->green = 31.0f;
    if (self->blue > 31.0f) self->blue = 31.0f;
    if (self->alpha > 31.0f) self->alpha = 31.0f;
    self->offsetX += self->xRate * (float)elapsed;
    self->offsetY += self->yRate * (float)elapsed;
    self->angle += self->angleRate * (float)elapsed;
    if (self->angle < 0.0f) self->angle = 360.0f;
    if (self->angle > 360.0f) self->angle = 0.0f;
    func_02058750(self);
    func_020589b8(self);
    func_02058b3c(self);
    unsigned int flags = 0;
    if (self->followFirst) {
        Follow02059720* follow = (Follow02059720*)GameState_GetShip((PointerField32c_ffc0*)game);
        if (follow) flags = follow->flags;
    } else if (self->followSecond) {
        Follow02059720* follow = (Follow02059720*)GameState_GetStarflight((PointerField330_ffd0*)game);
        if (follow) flags = follow->flags;
    }
    if (arg0->unknown_2d_ || arg0->unknown_2e_) {
        if (var3 & 1) arg0->unknown_10_ -= 0x120000;
        else if (var3 & 2) arg0->unknown_10_ += 0x120000;
        if (var3 & 4) arg0->unknown_18_ -= 0xe0000;
        else if (var3 & 8) arg0->unknown_18_ += 0xe0000;
    }
    arg0->unknown_7c_.AdvanceEffects();
}
