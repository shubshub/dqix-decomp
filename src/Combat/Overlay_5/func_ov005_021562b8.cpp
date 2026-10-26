#include <globaldefs.h>

#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include "World/ZoneLootableRecord.h"
#include <GameState/GameState.h>
#include "Resource/GameResources.h"
#include "Input/Input.h"

struct SePlayer;
struct Foo02048004;

struct MemberScreen {
    char unk_0[LOW_REGION(0x4f8, 0x4fc)];
    int member_;
    char unknown_500_[LOW_REGION(0x56c - 0x4fc, 0x634 - 0x500)];
    unsigned short flags_;
};

struct Struct_ov005_02153ba4 {
    short item_;
    signed char count_;
    unsigned char unknown_3_;
    void* vramState_;
    void* model_;
    int x_;
    int y_;
    int unknown_14_;
    short unknown_18_;
};

struct EquipmentMenu {
    char unk_0[LOW_REGION(0x2d08, 0x2d90)];
    Struct_ov005_02153ba4 slots_[24];
    char slotModels_[0x3cf0 - 0x3030];
    char dragModel_[0x88];
    short dragged_;
    char unknown_3d7a_[0x3db8 - 0x3d7a];
    unsigned char state_;
    unsigned char unknown_3db9_;
    unsigned char step_;
    signed char slot_;
    unsigned char kind_;
    signed char page_;
    unsigned char unknown_3dbe_;
    signed char unknown_3dbf_;
    signed char unknown_3dc0_;
    char unknown_3dc1_[0x3dcc - 0x3dc1];
    unsigned int flags_;
    char unknown_3dd0_[0x3e05 - 0x3dd0];
    signed char unknown_3e05_;
    signed char unknown_3e06_;
    signed char unknown_3e07_;
    short unknown_3e08_;
    short unknown_3e0a_;
};

extern int g_sePlayer;

extern "C" MemberScreen* func_ov017_021a193c(int* p);
extern "C" void SePlayer_Play(SePlayer* obj, int a, int b);
extern "C" void func_ov005_0215792c(EquipmentMenu* self, unsigned char state);
extern "C" void func_ov005_02156658(EquipmentMenu* self, int x, int y);
extern "C" void func_ov005_021567ac(EquipmentMenu* self, int x, int y);
extern "C" void func_ov005_0215690c(EquipmentMenu* self, int x, int y);
extern "C" void func_ov005_021579ec(EquipmentMenu* self, unsigned int state, unsigned char slot);
extern "C" void SprSprite_Unload(Foo02048004* model);
extern "C" void func_ov005_02156e1c(EquipmentMenu* self, int x, int y);
extern "C" void func_ov005_02156ecc(EquipmentMenu* self, int x, int y);

// USA: func_ov005_021562b8
extern "C" ARM void func_ov005_021562b8(EquipmentMenu* self) {
    int x;
    int y;
    g_touchInput.GetTouchPoint(&x, &y);
    int ticks = GameState::GetInstance()->GetTickCount();
    if (ticks == 0)
        ticks = 1;
    if (g_touchInput.pressed_) {
        if (x == 0 || y == 0)
            return;
        MemberScreen* screen = func_ov017_021a193c((int*)GetGameResources()->unknown_ptr_array_3700[2]);
        if (!(self->flags_ & 0x400) && (screen->flags_ & 0x800)) {
            SePlayer_Play((SePlayer*)&g_sePlayer, 0x1b, 0);
            func_ov005_0215792c(self, 1);
            return;
        }
        func_ov005_02156658(self, x, y);
        if (!(self->flags_ & 0x400) && x >= 0x80 && y >= 0xb0) {
            func_ov005_0215792c(self, 7);
            self->flags_ |= 0x80000;
            return;
        }
        if (self->unknown_3dc0_ != -1)
            return;
        func_ov005_021567ac(self, x, y);
        func_ov005_0215690c(self, x, y);
        if (x > 0x83 && y > 0x15 && y < 0x2e) {
            func_ov005_0215792c(self, 3);
            self->slot_ = self->kind_;
            func_ov005_021579ec(self, self->state_, 0);
        }
        if (self->dragged_ < 0)
            return;
        if (self->unknown_3e07_ == self->dragged_) {
            if (self->unknown_3e06_ > 0) {
                if (self->slots_[self->slot_].item_ >= 0) {
                    func_ov005_0215792c(self, 5);
                    SePlayer_Play((SePlayer*)&g_sePlayer, 1, 0);
                    screen->flags_ &= ~1;
                    screen->flags_ &= ~0x80;
                }
                SprSprite_Unload((Foo02048004*)self->dragModel_);
                self->dragged_ = -1;
                self->unknown_3dc0_ = -1;
                self->unknown_3e05_ = 0;
                self->unknown_3e07_ = -2;
                self->unknown_3e06_ = 0;
                return;
            }
            self->unknown_3e07_ = -2;
            self->unknown_3e06_ = 0;
        }
        self->unknown_3e05_ = 0;
        self->unknown_3e08_ = x;
        self->unknown_3e0a_ = y;
    } else if (g_touchInput.isRepeatValid_ != 0 && g_touchInput.currentReading_.isHeld != 0) {
        func_ov005_02156e1c(self, x, y);
        if (self->dragged_ >= 0)
            self->unknown_3e05_ += ticks;
    } else if (g_touchInput.released_ != 0) {
        if (self->dragged_ >= 0) {
            int dx = self->unknown_3e08_ - (short)x;
            int dy = self->unknown_3e0a_ - (short)y;
            int moved = 0;
            if (dx * dx + dy * dy >= 25)
                moved = 1;
            if (self->unknown_3e05_ <= 20 && moved == 0) {
                self->unknown_3e06_ = 20;
                self->unknown_3e07_ = self->dragged_;
            } else {
                self->unknown_3e05_ = 0;
                self->unknown_3e07_ = -2;
                self->unknown_3e06_ = 0;
            }
            self->unknown_3e08_ = -1;
            self->unknown_3e0a_ = -1;
        }
        func_ov005_02156ecc(self, x, y);
        SprSprite_Unload((Foo02048004*)self->dragModel_);
        self->dragged_ = -1;
        self->unknown_3dc0_ = -1;
    }
}
