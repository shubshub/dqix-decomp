#include <globaldefs.h>
#include <GameState/GameState.h>

struct Struct_020546c8;
struct PointerField32c_ffc0;
struct PointerField330_ffd0;
struct Struct_02059720;
struct Struct_02059720_2 { char unknown_0_[3]; unsigned char unknown_3_; };
struct Follow02059720 { char unknown_0_[0x130]; unsigned int flags; };
struct Struct_02059720_4 {
    int field_0, time, duration;
    unsigned char disabled;
    char unknown_d_[3];
    int x, y, z;
    char unknown_1c_[0xc];
    Struct_020546c8* unknown_28_;
    unsigned char active, unknown_2d_, unknown_2e_, unknown_2f_;
    float unknown_30_, unknown_34_, unknown_38_, unknown_3c_, unknown_40_, unknown_44_, unknown_48_, unknown_4c_;
    char unknown_50_[0x2c];
    Object3D object;
    char unknown_128_[4];
    float red, green, blue, alpha, offsetX, offsetY, angle;
};
extern "C" int func_02059a2c(Struct_02059720*);
extern "C" void* func_02055108(Struct_020546c8*);
extern "C" void* GameState_GetShip(PointerField32c_ffc0*);
extern "C" void* GameState_GetStarflight(PointerField330_ffd0*);
extern "C" void func_02058750(Struct_02059720_4*);
extern "C" void func_020589b8(Struct_02059720_4*);
extern "C" void func_02058b3c(Struct_02059720_4*);

// USA: func_02059720
extern "C" ARM void func_02059720(Struct_02059720_4* self) {
    if (!self->active) return;
    if (func_02059a2c((Struct_02059720*)self)) return;
    if (self->object.HasAnimationStopped()) {
        Struct_02059720_2* source = (Struct_02059720_2*)func_02055108(self->unknown_28_);
        if (source->unknown_3_) {
            self->disabled = 0;
            self->active = 0;
            return;
        }
    }
    GameState* game = GameState::GetInstance();
    int elapsed = game->GetTickCount();
    self->time += elapsed;
    if (func_02059a2c((Struct_02059720*)self)) {
        self->active = 0;
        return;
    }
    self->red += self->unknown_34_ * (float)elapsed;
    self->green += self->unknown_38_ * (float)elapsed;
    self->blue += self->unknown_3c_ * (float)elapsed;
    self->alpha += self->unknown_40_ * (float)elapsed;
    if (self->red < 0.0f) self->red = 0.0f;
    if (self->green < 0.0f) self->green = 0.0f;
    if (self->blue < 0.0f) self->blue = 0.0f;
    if (self->alpha < 0.0f) self->alpha = 0.0f;
    if (self->red > 31.0f) self->red = 31.0f;
    if (self->green > 31.0f) self->green = 31.0f;
    if (self->blue > 31.0f) self->blue = 31.0f;
    if (self->alpha > 31.0f) self->alpha = 31.0f;
    self->offsetX += self->unknown_44_ * (float)elapsed;
    self->offsetY += self->unknown_48_ * (float)elapsed;
    self->angle += self->unknown_4c_ * (float)elapsed;
    if (self->angle < 0.0f) self->angle = 360.0f;
    if (self->angle > 360.0f) self->angle = 0.0f;
    func_02058750(self);
    func_020589b8(self);
    func_02058b3c(self);
    unsigned int flags = 0;
    if (self->unknown_2d_) {
        Follow02059720* follow = (Follow02059720*)GameState_GetShip((PointerField32c_ffc0*)game);
        if (follow) flags = follow->flags;
    } else if (self->unknown_2e_) {
        Follow02059720* follow = (Follow02059720*)GameState_GetStarflight((PointerField330_ffd0*)game);
        if (follow) flags = follow->flags;
    }
    if (self->unknown_2d_ || self->unknown_2e_) {
        if (flags & 1) self->x -= 0x120000;
        else if (flags & 2) self->x += 0x120000;
        if (flags & 4) self->z -= 0xe0000;
        else if (flags & 8) self->z += 0xe0000;
    }
    self->object.AdvanceEffects();
}
