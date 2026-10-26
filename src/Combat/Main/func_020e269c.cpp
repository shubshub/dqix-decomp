#include <globaldefs.h>
#include "Input/Input.h"

struct Struct_020e1e4c {
    char pad0[8];
    unsigned char count;
};

extern "C" int func_020e1e4c(struct Struct_020e1e4c* list);
extern "C" long long _s32_div_f(int a, int b);

struct Struct_020e269c {
    char pad0[0x10];
    struct Struct_020e1e4c* list;
    signed char cur;
    unsigned char prev;
    char pad1;
    unsigned char flag;
};

// USA: func_020e269c
extern "C" ARM void func_020e269c(struct Struct_020e269c* self) {
    struct Struct_020e1e4c* l = self->list;
    int step = l->count;
    int idx = func_020e1e4c(l);
    if (idx >= 0) {
        signed char cur = self->cur;
        if (cur == idx && self->flag) {
            self->prev = cur;
        }
        self->flag = 1;
        self->cur = idx;
        return;
    }
    if (g_keyManager.TestKeysPressed(0x80)) {
        self->cur = (int)(_s32_div_f(self->cur + 1, step) >> 32);
        self->flag = 0;
        return;
    }
    if (g_keyManager.TestKeysPressed(0x40)) {
        signed char v = self->cur;
        self->cur = (v > 0) ? v - 1 : step - 1;
        self->flag = 0;
        return;
    }
    if (g_keyManager.TestKeysPressed(1) ||
        g_keyManager.TestKeysPressed(0x400) ||
        g_keyManager.TestKeysPressed(0x200)) {
        self->prev = self->cur;
    }
}
