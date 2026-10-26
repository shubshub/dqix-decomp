#include <globaldefs.h>

extern "C" void* OamManager_GetInstance(void);
extern "C" void* OamManager_GetMainOamBuffer(void* base);
extern "C" void* OamManager_GetSubOamBuffer(void* base);
extern "C" unsigned int func_020937f0(int engine);
extern "C" int func_0209378c(int engine);

struct Pack020e197c {
    unsigned int w;
    unsigned short h;
};
extern "C" void func_020e197c(struct Pack020e197c* d, int a2, int a3, int a4,
        int a5, int a6, int a7, int a8, int a9, int arg9, int arg10, int arg11);

struct Struct_020e1780_3 {
    unsigned int attr;
    unsigned int offset;
    unsigned char x;
    unsigned char y;
    unsigned char width;
    unsigned char height;
};

struct Struct_020e1780_4 {
    char pad0[8];
    struct Struct_020e1780_3* rects;
    char unknown_c_[0x24 - 0xc];
    unsigned int field24;
    char pad28[0x2e - 0x28];
    unsigned char stepX;
    unsigned char stepY;
    unsigned int unknown_30_;
    unsigned int field34;
    unsigned char x;
    unsigned char y;
    unsigned char width;
    unsigned char height;
    unsigned char count;
    unsigned char start;
    unsigned char display;
    unsigned char unknown_3f_0_ : 1;
};

struct Struct_020e1780 {
    char pad0[4];
    struct Struct_020e1780_4* panel;
};

// USA: func_020e1780
extern "C" ARM void func_020e1780(struct Struct_020e1780* obj) {
    int x;
    int display;
    struct Struct_020e1780_4* p;
    struct Pack020e197c* pack;
    int y;
    int count;
    int shift;
    unsigned int tile;
    struct Struct_020e1780_3* rects;
    int i;
    int j;
    int w;
    unsigned int vram;
    int h;
    void* base;

    if (obj->panel == 0) return;
    if (!obj->panel->unknown_3f_0_ || (rects = obj->panel->rects) == 0) return;

    base = OamManager_GetInstance();
    OamManager_GetMainOamBuffer(base);
    display = obj->panel->display;
    x = obj->panel->x;
    y = obj->panel->y;
    func_020937f0(display);
    shift = func_0209378c(display);
    pack = (struct Pack020e197c*)OamManager_GetMainOamBuffer(base);
    if (display != 0) {
        pack = (struct Pack020e197c*)OamManager_GetSubOamBuffer(base);
    }

    pack += obj->panel->start;
    vram = obj->panel->unknown_30_;
    count = obj->panel->count;
    for (i = 0; i < count; i++) {
        struct Struct_020e1780_3* r = &rects[i];
        unsigned int t = vram + r->offset;
        t >>= shift;
        func_020e197c(pack, x + r->x, y + r->y, 0, 0, 0, 0, r->attr, 0,
                t, 0xe, 0);
        pack++;
    }

    p = obj->panel;
    tile = (vram + p->field34) >> shift;
    w = p->width - 4;
    h = p->height - 4;
    i = 0;
    for (j = 0; j < h; j += p->stepY) {
        if (h < j + p->stepY) j = h - p->stepY;
        for (; i < w; i += p->stepX) {
            if (w < i + p->stepX) i = w - p->stepX;
            func_020e197c(pack, x + i + 2, y + j + 2, 0, 1, 0, 0, p->field24, 0, tile, 0xe, 0);
            pack++;
        }
        i = 0;
    }
}
