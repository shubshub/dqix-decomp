#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_020a63f8 {
    int x;
    int y;
    signed char dx;
    signed char dy;
    signed char unk_a;
    unsigned char unknown_b_;
};

// USA: func_020a63f8
extern "C" ARM void func_020a63f8(struct Struct_020a63f8* p) {
    GameState::GetInstance();
    if (p->unknown_b_) {
        return;
    }
    *(volatile unsigned int*)0x4001014 = (p->x & 0x1ff) | ((p->y << 16) & 0x1ff0000);

    p->x += p->dx;
    if (p->x >= 0x100) {
        p->x -= 0x100;
    }
    if (p->x <= -1) {
        p->x += 0x100;
    }

    p->y += p->dy;
    if (p->y >= 0x100) {
        p->y -= 0x100;
    }
    if (p->y <= -1) {
        p->y += 0x100;
    }
}
