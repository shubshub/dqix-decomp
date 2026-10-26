#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
#define RG(u, j) (j)
#else
#define RG(u, j) (u)
#endif

struct Struct_0207fdcc_2 {
    char unk_0[RG(0x36, 0x2a)];
    short selected;
};

struct Struct_0207fdf0_2;
struct SePlayer;
struct Struct_02081f20_2;

extern "C" void* GameState_GetParty(GameState* gs);
extern "C" void func_0207fdf0(struct Struct_0207fdf0_2* obj, int key);
extern "C" void func_ov003_021749c0(char* base);
extern "C" short func_02080468(void* obj, int id);
extern "C" void func_ov003_02177820(void* self);
extern "C" void func_ov003_02177938(void* self);
extern "C" void func_02081ea4(struct Struct_0207fdcc_2* obj, int id, int value);
extern "C" void func_02080c68(void* obj, int id, int value);
extern "C" void func_0208203c(struct Struct_02081f20_2* obj);
extern "C" int func_ov003_021765b4(void* self);
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern "C" int func_ov003_02179f34(void* self);
extern "C" int func_ov003_021766e8(void* self);
extern struct SePlayer g_sePlayer;

struct Struct_ov003_0217a4ac {
    char unk_0[RG(0x88c, 0x808)];
    char repeat[0x89c - 0x88c];
    struct Struct_0207fdcc_2* menu;
    char unknown_8a0_[0xff8 - 0x8a0];
    short* cursor;
    short unknown_ffc_;
    short key;
    char unknown_1000_[4];
    short unknown_1004_;
    char unknown_1006_[6];
    short unknown_100c_;
    short unknown_100e_;
    short unknown_1010_;
    short unknown_1012_;
    short unknown_1014_;
    short unknown_1016_;
    char unknown_1018_[0x1030 - 0x1018];
    int unknown_1030_;
    char unknown_1034_[2];
    short nextState;
    char unknown_1038_[4];
    unsigned char unknown_103c_;
    char unknown_103d_;
    unsigned char mode;
    unsigned char step;
    char unknown_1040_[3];
    signed char unknown_1043_;
    char unknown_1044_[2];
    unsigned short flags;
};

// USA: func_ov003_0217a4ac
extern "C" ARM void func_ov003_0217a4ac(struct Struct_ov003_0217a4ac* self) {
    GameState_GetParty(GameState::GetInstance());
    struct Struct_0207fdcc_2* menu = self->menu;
    if (self->step == 0) {
        self->unknown_1014_ = 0;
        self->unknown_1016_ = 0;
        func_0207fdf0((struct Struct_0207fdf0_2*)menu, 0);
        self->step++;
        return;
    }
    if (self->step == 1) {
        func_ov003_021749c0((char*)self);
        switch (self->unknown_1030_) {
        case 1:
            self->key = 0x11;
            break;
        case 2:
            self->key = 0x12;
            break;
        case 3:
            self->key = 0x13;
            break;
        case 4:
            self->key = 0x14;
            break;
        }
        if (self->unknown_1010_ < 0) {
            self->unknown_1010_ = func_02080468(menu, self->key);
        }
        menu->selected = self->unknown_1010_;
        func_ov003_02177820(self);
        func_ov003_02177938(self);
        func_02081ea4(menu, self->key, 0);
        func_02080c68(menu, self->key, 0);
        func_0208203c((struct Struct_02081f20_2*)self->repeat);
        self->cursor = 0;
        self->step++;
        return;
    }
    if (self->step == 2) {
        self->cursor = &self->unknown_1010_;
        func_ov003_02177938(self);
        func_02080c68(self->menu, 0x15, 1);
        if (func_ov003_021765b4(self)) {
            SePlayer_Play(&g_sePlayer, 1, 0);
            func_0208203c((struct Struct_02081f20_2*)self->repeat);
            self->cursor = 0;
            if (func_ov003_02179f34(self) == 0) {
                short next = 0x13;
                if (self->unknown_1043_ < 0) {
                    next = 0x14;
                }
                self->nextState = next;
                func_0207fdf0((struct Struct_0207fdf0_2*)menu, 0);
                self->step = 0;
                self->flags |= 0x20;
                return;
            }
            int mode = 5;
            int inRange = 0;
            if (self->unknown_1043_ >= 0 && self->unknown_1043_ <= 3) {
                inRange = 1;
            }
            if (inRange == 0) {
                mode = 6;
                func_0207fdf0((struct Struct_0207fdf0_2*)menu, 0);
            }
            self->mode = mode;
            self->step = 0;
            func_02080c68(menu, self->key, 1);
            self->unknown_ffc_ = self->key;
            self->unknown_100e_ = -1;
            self->unknown_103c_ = 1;
            return;
        }
        if (!func_ov003_021766e8(self)) {
            return;
        }
#if !defined(jpn)
        self->cursor = 0;
#endif
        func_0207fdf0((struct Struct_0207fdf0_2*)menu, 0);
        self->mode = 3;
        self->step = 0;
    }
}
