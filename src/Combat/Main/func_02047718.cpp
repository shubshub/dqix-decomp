#include <globaldefs.h>

extern "C" void func_02047888(int s, int t);

struct Struct_02047718_2 {
    int polygonId;
    unsigned short unknown_4_;
    char pad6[0x10 - 0x6];
    unsigned int unknown_10_;
    char unknown_14_[0x80 - 0x14];
    unsigned short color;
    short alpha;
};

struct Struct_02047718 {
    unsigned int unknown_0_;
    unsigned short unknown_4_;
    unsigned short position;
};

static inline void inline_020417b0(int x, int y, int z) {
    *(volatile unsigned int*)0x04000470 = x;
    *(volatile unsigned int*)0x04000470 = y;
    *(volatile unsigned int*)0x04000470 = z;
}

static inline void inline_020417b0_2(int x, int y, int z) {
    *(volatile unsigned int*)0x0400046c = x;
    *(volatile unsigned int*)0x0400046c = y;
    *(volatile unsigned int*)0x0400046c = z;
}

static inline void inline_020417b0_3(unsigned short x, unsigned short y, unsigned short z) {
    *(volatile unsigned int*)0x0400048c = (unsigned short)x | ((unsigned short)y << 16);
    *(volatile unsigned int*)0x0400048c = (unsigned short)z;
}

// USA: func_02047718
extern "C" ARM void func_02047718(Struct_02047718_2* obj, Struct_02047718* cell, int arg2) {
    *(volatile unsigned int*)0x04000444 = 0;
    int s = cell->unknown_4_ & 0xf;
    int t = (cell->unknown_4_ & 0xf0) >> 4;
    int w = 8 << (s + 12);
    int h = 8 << (t + 12);
    int x = (cell->position & 0xff) << 12;
    int y = ((cell->position & 0xff00) >> 8) << 12;
    int fmt = obj->unknown_4_;
    fmt <<= 26;
    *(volatile unsigned int*)0x040004a8 = (cell->unknown_0_ >> 3) | fmt | (s << 20) | (t << 23) | (arg2 << 29);
    *(volatile unsigned int*)0x040004ac = obj->unknown_10_ >> (4 - (obj->unknown_4_ == 2));
    int alpha = obj->alpha & 0x1f;
    alpha <<= 16;
    *(volatile unsigned int*)0x040004a4 = 0x80c0 | (obj->polygonId << 24) | alpha;
    inline_020417b0(x, y, 0);
    inline_020417b0_2(w, h, 0x1000);

    *(volatile unsigned int*)0x04000500 = 1;
    *(volatile unsigned int*)0x04000480 = obj->color;
    *(volatile unsigned int*)0x04000488 = 0;
    inline_020417b0_3(0, 0x1000, 0);
    func_02047888(w, 0);
    inline_020417b0_3(0x1000, 0x1000, 0);
    func_02047888(w, h);
    inline_020417b0_3(0x1000, 0, 0);
    func_02047888(0, h);
    inline_020417b0_3(0, 0, 0);
    *(volatile unsigned int*)0x04000504 = 0;
    *(volatile unsigned int*)0x04000448 = 1;
}
