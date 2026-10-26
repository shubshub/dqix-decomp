#include <globaldefs.h>

extern "C" void func_0203fc28(int s, int t);

extern unsigned short data_020e79d8[];

struct Struct_0203f98c {
    unsigned short x;
    unsigned short y;
    unsigned short unknown_4_;
    unsigned short unknown_6_;

    unsigned short inline_0203f98c() const { SDK_NULL_ASSERT(this); return unknown_4_; }
    unsigned short inline_0203f98c_2() const { SDK_NULL_ASSERT(this); return unknown_6_; }
};

struct Struct_0203f98c_2 {
    char pad0[0x2a];
    unsigned short color;
    short field2c;
    short unknown_2e_;
    char pad1[0x50 - 0x30];
    unsigned int flags;
};

static inline void inline_0203f98c_3(unsigned int addr, int arg1) {
    *(volatile unsigned int*)0x040004ac = addr >> (4 - (arg1 == 2));
}

static inline void inline_0203f98c_4(int arg0, int arg1, int arg2, int arg3, int alpha, int misc) {
    *(volatile unsigned int*)0x040004a4 = arg0 | (arg1 << 4) | arg2 | misc | (arg3 << 24) | (alpha << 16);
}

// USA: func_0203f98c
extern "C" ARM void func_0203f98c(struct Struct_0203f98c_2* self, struct Struct_0203f98c* arg1, unsigned int arg2, unsigned int arg3, unsigned short fmt, unsigned short arg5, unsigned short arg6) {
    *(volatile unsigned int*)0x04000444 = 0;
    *(volatile unsigned int*)0x040004a8 = (arg2 >> 3) | (fmt << 26) | 0x40000000 | (arg1->inline_0203f98c() << 20) | (arg1->inline_0203f98c_2() << 23) | 0x20000000;
    inline_0203f98c_3(arg3, fmt);
    inline_0203f98c_4(0, 0, 0xc0, self->unknown_2e_, self->field2c, 0x8000);

    unsigned int w = data_020e79d8[arg1->inline_0203f98c()] << 12;
    unsigned int h = data_020e79d8[arg1->inline_0203f98c_2()] << 12;
    unsigned int x = arg1->x << 12;
    unsigned int y = arg1->y << 12;

    if (self->flags & 2) {
        x = (arg5 << 12) - (w + x);
    }
    if (self->flags & 4) {
        y = (arg6 << 12) - (h + y);
    }

    *(volatile unsigned int*)0x04000470 = x;
    *(volatile unsigned int*)0x04000470 = y;
    *(volatile unsigned int*)0x04000470 = 0;
    *(volatile unsigned int*)0x0400046c = w;
    *(volatile unsigned int*)0x0400046c = h;
    *(volatile unsigned int*)0x0400046c = 0x1000;
    *(volatile unsigned int*)0x04000500 = 1;
    *(volatile unsigned int*)0x04000480 = self->color;

    if (self->flags & 2) {
        if (self->flags & 4) {
            func_0203fc28(w, 0);
            *(volatile unsigned int*)0x04000494 = 0x10000000;
            *(volatile unsigned int*)0x04000488 = 0;
            *(volatile unsigned int*)0x04000494 = 0x10001000;
            func_0203fc28(0, h);
            *(volatile unsigned int*)0x04000494 = 0x1000;
            func_0203fc28(w, h);
            *(volatile unsigned int*)0x04000494 = 0;
        } else {
            func_0203fc28(w, h);
            *(volatile unsigned int*)0x04000494 = 0x10000000;
            func_0203fc28(0, h);
            *(volatile unsigned int*)0x04000494 = 0x10001000;
            *(volatile unsigned int*)0x04000488 = 0;
            *(volatile unsigned int*)0x04000494 = 0x1000;
            func_0203fc28(w, 0);
            *(volatile unsigned int*)0x04000494 = 0;
        }
    } else {
        if (self->flags & 4) {
            *(volatile unsigned int*)0x04000488 = 0;
            *(volatile unsigned int*)0x04000494 = 0x10000000;
            func_0203fc28(w, 0);
            *(volatile unsigned int*)0x04000494 = 0x10001000;
            func_0203fc28(w, h);
            *(volatile unsigned int*)0x04000494 = 0x1000;
            func_0203fc28(0, h);
            *(volatile unsigned int*)0x04000494 = 0;
        } else {
            func_0203fc28(0, h);
            *(volatile unsigned int*)0x04000494 = 0x10000000;
            func_0203fc28(w, h);
            *(volatile unsigned int*)0x04000494 = 0x10001000;
            func_0203fc28(w, 0);
            *(volatile unsigned int*)0x04000494 = 0x1000;
            *(volatile unsigned int*)0x04000488 = 0;
            *(volatile unsigned int*)0x04000494 = 0;
        }
    }

    *(volatile unsigned int*)0x04000504 = 0;
    *(volatile unsigned int*)0x04000448 = 1;
}
