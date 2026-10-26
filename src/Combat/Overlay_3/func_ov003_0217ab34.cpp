#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Input/Input.h"

struct Struct_0207fdcc_2;
struct Struct_0207fdf0_2;
struct SePlayer;
struct Struct_02081f20_2;
struct ItemTable;
struct Struct_ov003_02178910;
struct Obj02179e18;

struct Obj02179e18 {
    char pad[8];
    unsigned int unknown_8_0_ : 12;
    unsigned int kind_ : 2;
};

struct Struct_ov003_0217ab34 {
    char pad[0xc];
    short unknown_c_[1];
};

struct Struct_ov003_0217ab34_2 {
    char unk_0[8];
    struct Obj02179e18* elem;
    char unk_c[0x30];
#if defined(jpn)
    char unknown_3c_[0x7f0 - 0x3c];
#else
    char unknown_3c_[0x874 - 0x3c];
#endif
    char container[0x88c - 0x874];
    char repeat[0x89c - 0x88c];
    struct Struct_0207fdcc_2* menu;
    char unknown_8a0_[0xff8 - 0x8a0];
    short* cursor;
    short unknown_ffc_;
    short key;
    char unknown_1000_[0xe];
    short unknown_100e_;
    char unknown_1010_[4];
    short unknown_1014_;
    char unknown_1016_[0x1036 - 0x1016];
    short nextState;
    char unknown_1038_[2];
    short sel;
    unsigned char count;
    char unknown_103d_;
    unsigned char mode;
    unsigned char step;
    char unknown_1040_[6];
    unsigned short flags;
    char unknown_1048_[2];
    unsigned char tick;
    unsigned char up;
    unsigned char down;
};

extern "C" void* GameState_GetParty(GameState* gs);
extern "C" short func_02080468(void* obj, int id);
extern "C" void func_02081ea4(struct Struct_0207fdcc_2* obj, int id, int value);
extern "C" void func_02080c68(void* obj, int id, int value);
extern "C" void func_0208203c(struct Struct_02081f20_2* obj);
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern "C" struct Obj02179e18* ItemTable_Find(struct ItemTable* c, int key);
extern "C" void func_0207fdf0(struct Struct_0207fdf0_2* obj, int key);
extern "C" void func_0207fdcc(struct Struct_0207fdcc_2* obj, int key);
extern "C" unsigned short func_ov003_0217b200(void** obj);
extern "C" int func_02086bf4(char* table, int key);
extern "C" int func_ov003_02179e18(struct Obj02179e18* elem);
extern "C" void func_ov003_02175d78(char* obj);

extern "C" int func_ov003_02179f34(void* self);
extern "C" void func_ov003_02177dd4(void* self);
extern "C" void func_ov003_021748c4(void* self);
extern "C" void func_ov003_0217a14c(void* self);
extern "C" void func_ov023_021dcae0(struct Struct_ov003_02178910* obj, int val);
extern "C" int func_ov003_021765b4(void* self);
extern "C" int func_ov003_02179da8(void* elem, int flag);
extern "C" int func_ov003_021766e8(void* self);
extern "C" void func_ov003_02177208(void* self);
extern "C" void func_ov003_0217726c(void* self);
extern "C" int func_ov003_02178218(void* self);
extern "C" int func_02081f20(void* obj, unsigned int tick);
extern "C" int func_ov003_021782a0(void* self);
extern "C" void func_ov003_02176468(void* self);
extern "C" int func_ov003_021764f4(void* self);
extern "C" void func_ov003_02175df4(void* self);

extern struct SePlayer g_sePlayer;

// USA: func_ov003_0217ab34
extern "C" ARM void func_ov003_0217ab34(struct Struct_ov003_0217ab34_2* self) {
    char* data = (char*)GameState_GetParty(GameState::GetInstance());
    struct Struct_0207fdcc_2* menu = self->menu;

    if (self->step == 0) {
        int var2 = func_ov003_02179f34(self);
        self->flags &= ~0x400;
        if (var2 > 8) {
            self->flags |= 0x400;
        }
        self->key = 0x16;
        if (self->unknown_100e_ < 0) {
            self->unknown_100e_ = func_02080468(menu, self->key);
        }
        short base = func_02080468(menu, self->key);
        short idx = (short)(self->unknown_100e_ - base);
        struct Struct_ov003_0217ab34* table = (struct Struct_ov003_0217ab34*)data;
        self->sel = table->unknown_c_[(short)(self->unknown_1014_ * 8 + idx)];
        self->count = 1;
        func_ov003_02177dd4(self);
        func_02081ea4(menu, self->key, 0);
        func_02080c68(menu, self->key, 0);
        func_0208203c((struct Struct_02081f20_2*)self->repeat);
        self->cursor = 0;
        self->step = 1;
        func_ov003_021748c4(self);
        return;
    }

    if (self->step == 1) {
        short var6 = self->sel;
        self->cursor = &self->unknown_100e_;
        func_ov003_0217a14c(self);
        func_ov023_021dcae0((struct Struct_ov003_02178910*)self->unknown_3c_, self->sel);
        if (func_ov003_021765b4(self) && var6 == self->sel) {
            SePlayer_Play(&g_sePlayer, 1, 0);
            func_0208203c((struct Struct_02081f20_2*)self->repeat);
            self->cursor = 0;
            self->elem = ItemTable_Find((struct ItemTable*)self->container, self->sel);
            if (self->elem == 0) {
                return;
            }
            self->unknown_ffc_ = self->key;
            func_02080c68(menu, self->key, 1);
            self->step = 2;
            if (self->elem->kind_ == 0) {
                func_0207fdf0((struct Struct_0207fdf0_2*)menu, 0);
                self->nextState = 0x12;
                self->step = 0;
                self->flags |= 0x20;
#if !defined(jpn)
                self->flags &= ~0x2000;
#endif
                return;
            }
            switch (func_ov003_02179da8(self->elem, 1)) {
            case 1:
                func_0207fdf0((struct Struct_0207fdf0_2*)menu, 0);
                self->nextState = 0xd;
                self->step = 6;
                self->flags |= 0x2000;
                if (self->elem->kind_ == 2) {
                    self->nextState = 0x11;
                    self->step = 4;
                }
                break;
            case 2:
                func_0207fdf0((struct Struct_0207fdf0_2*)menu, 0);
                self->nextState = 0x1c;
                self->mode = 1;
                self->step = 0;
                self->flags |= 0x2000;
                break;
            }
            return;
        }
        if (func_ov003_021766e8(self) == 0) {
            return;
        }
        func_0208203c((struct Struct_02081f20_2*)self->repeat);
        self->cursor = 0;
        func_0207fdf0((struct Struct_0207fdf0_2*)menu, 0);
        self->mode = 4;
        self->step = 1;
        self->flags |= 0x2000;
        return;
    }

    if (self->step == 2) {
        func_ov003_02177208(self);
        func_ov003_0217726c(self);
        func_0208203c((struct Struct_02081f20_2*)self->repeat);
        self->step = 3;
        self->tick = 0;
        return;
    }

    if (self->step == 3) {
        int dir = 0;
        if (self->tick < 5) {
            self->tick++;
        } else {
            dir = func_ov003_02178218(self);
            if (dir != 0) {
                self->tick = 0;
            }
        }
        int state = func_02081f20(self->repeat, GameState::GetInstance()->GetTickCount());
        if ((unsigned short)(state + 0xffff) <= 1) {
            unsigned short pad = func_ov003_0217b200((void**)self->repeat);
            if (pad == 0x40) {
                dir = 1;
            } else if (pad == 0x80) {
                dir = -1;
            } else if (pad == 0x20) {
                dir = 0x83;
            } else if (pad == 0x10) {
                dir = -0x83;
            }
        }
        if (dir != 0) {
            int next = self->count + dir;
            int limit = func_02086bf4(data, self->sel);
            int remaining = func_ov003_02179e18(self->elem);
            if (remaining < limit) {
                limit = remaining;
            }
            if (limit < next) {
                next = limit;
            }
            if (next <= 1) {
                next = 1;
            }
            self->up = self->count < next;
            self->down = next < self->count;
            self->count = next;
            func_ov003_02177208(self);
            func_ov003_0217726c(self);
        }
        int pressed = func_ov003_021782a0(self);
        if (g_keyManager.TestKeysPressed(0x401) != 0 || pressed == 1) {
            SePlayer_Play(&g_sePlayer, 1, 0);
            func_0207fdf0((struct Struct_0207fdf0_2*)menu, 0);
            self->nextState = 0xd;
            if (self->count > 1) {
                self->nextState = 0x20;
            }
            self->step = 6;
            self->flags |= 0x2000;
            func_0208203c((struct Struct_02081f20_2*)self->repeat);
            if (self->elem->kind_ == 2) {
                self->nextState = 0x11;
                self->step = 4;
            }
        } else if (g_keyManager.TestKeysPressed(2) != 0 || pressed == -1) {
            func_0207fdcc(menu, 9);
            func_0207fdcc(menu, 10);
            func_0208203c((struct Struct_02081f20_2*)self->repeat);
            self->step = 0;
        }
        return;
    }

    if (self->step == 4) {
        func_ov003_02176468(self);
        self->step = 5;
        return;
    }

    if (self->step == 5) {
        int res = func_ov003_021764f4(self);
        if (res != -1) {
            if (res != 1) {
                return;
            }
            self->nextState = 0x10;
            self->step = 6;
        } else {
            self->nextState = 0x30;
            self->step = 0;
            self->flags |= 0x20;
        }
        return;
    }

    if (self->step == 6) {
        func_ov003_02176468(self);
        self->step = 7;
        return;
    }

    if (self->step == 7) {
        int res = func_ov003_021764f4(self);
        if (res != -1) {
            if (res != 1) {
                return;
            }
            func_ov003_02175d78((char*)self);
            func_ov003_02175df4(self);
            self->nextState = 0xe;
            self->mode = 4;
            self->step = 1;
            self->flags |= 0x20;
        } else {
            self->nextState = 0x30;
            self->mode = 6;
            self->step = 0;
            self->flags |= 0x20;
        }
    }
}
