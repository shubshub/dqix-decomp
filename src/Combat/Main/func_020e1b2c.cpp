#include <globaldefs.h>

struct Struct_020e1b2c {
    unsigned int attr;
    unsigned int offset;
    unsigned char x;
    unsigned char y;
    unsigned char width;
    unsigned char height;
};

struct Struct_020e1384 {
    int field0;
    int field4;
    char pad8[4];
    int unknown_c_;
    char pad10[4];
    unsigned char unknown_14_;
};

struct Struct_020e1b2c_2 {
    char pad0[8];
    struct Struct_020e1b2c* rects;
    char unknown_c_[0x30 - 0xc];
    int unknown_30_;
    int field34;
    unsigned char x;
    unsigned char y;
    unsigned char width;
    unsigned char height;
    unsigned char count;
    unsigned char unknown_3d_;
    unsigned char display;
};

struct Struct_020e1b2c_3 {
    char pad0[4];
    struct Struct_020e1b2c_2* panel;
};

struct Struct_020e1674_2;
struct Struct_020e1288;

extern "C" unsigned int func_020e1438(struct Struct_020e1b2c* out, unsigned int maxCount,
                                      unsigned int x, unsigned int arg3,
                                      unsigned int width, unsigned int height);
extern "C" unsigned int func_0209378c(int engine);
extern "C" int func_020937f0(int engine);
extern "C" int func_020e1288(struct Struct_020e1288* obj);
extern "C" void func_020e1384(struct Struct_020e1384* obj);
extern "C" void func_020e16f4(struct Struct_020e1674_2* self);

// USA: func_020e1b2c
extern "C" ARM int func_020e1b2c(struct Struct_020e1b2c_3* obj, int arg) {
    if (obj->panel == 0) return 0;

    func_020e16f4((struct Struct_020e1674_2*)obj);

    struct Struct_020e1b2c* rects = obj->panel->rects;
    unsigned int h = obj->panel->height;
    unsigned int cap = obj->panel->count;
    unsigned int w = obj->panel->width;
    unsigned int var4;
    int count;
    unsigned int y;
    unsigned int total;
    unsigned int height;

    if (rects == 0 || cap == 0 || w == 0 || h == 0) {
        count = 0;
    } else {
        count = 0;
        total = (w + 7) & ~7u;
        y = 0;
        height = (h + 7) & ~7u;
        while (y < total) {
            if (count >= cap) break;
            var4 = 0x40;
            unsigned int rem = total - y;
            while (var4 > 8 && var4 > rem) var4 >>= 1;
            count += func_020e1438(&rects[count], cap - count, y, 0, var4, height);
            y += var4;
        }
    }
    obj->panel->count = count;

    unsigned int offset = 0;
    unsigned char display = obj->panel->display;
    int prod;
    struct Struct_020e1b2c* arr;
    unsigned int n = obj->panel->count;
    arr = obj->panel->rects;
    for (count = 0; count < n; count++) {
        struct Struct_020e1b2c* e = &arr[count];
        e->offset = offset;
        prod = e->width * e->height;
        unsigned int mask = 1 << func_0209378c(display);
        if (mask != 0) mask--;
        offset += (~mask) & (mask + (prod >> 1));
    }
    obj->panel->field34 = offset;

    int size = func_020937f0(obj->panel->display);
    if (arg != -1) size = arg;
    obj->panel->unknown_30_ =
        size - (obj->panel->field34 + func_020e1288((struct Struct_020e1288*)obj->panel));
    func_020e1384((struct Struct_020e1384*)((char*)obj->panel + 0xc));
    return obj->panel->unknown_30_;
}
