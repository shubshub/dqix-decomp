#include "std_library_functions.h"
#include <globaldefs.h>

extern "C" void func_ov002_02157030(void *base, int type, short *a, short *b, short *c, short *d);
extern "C" void func_ov002_0215be00(void *base, int a, int b, int c);
extern "C" void func_ov002_021610c4(void *base, void *dst, int flag);
#if defined(jpn)
extern "C" void Window_OpenPane(void *a, void *b, int p2, int p3, int p4, int p5, int p6);
#else
extern "C" void Window_OpenPane(void *a, void *b, int p2, int p3, int p4, int p5, int p6, int p7);
#endif

struct Struct_0205d81c;
struct Elem_0205d81c {
    char pad0[0xa8];
    short unknown_a8_;
    short unknown_aa_;
    short unknown_ac_;
    short unknown_ae_;
};
extern "C" struct Elem_0205d81c *func_0205d81c(struct Struct_0205d81c *s, int key);
extern "C" void func_0205d904(unsigned char *obj);

struct BufOv02160fb4 {
#if defined(jpn)
    char pad[0xa98];
#else
    char pad[0xbd0];
#endif
    void *buf;
};
struct Struct_ov002_02160fb4_2 {
#if defined(jpn)
    char pad[0xa80];
#else
    char pad[0xbb8];
#endif
    int field;
};

static inline void inline_ov002_02160fb4(struct Elem_0205d81c *e, short x, short y) {
    e->unknown_ac_ = x;
    e->unknown_ae_ = y;
}
static inline void inline_ov002_02160fb4_2(struct Elem_0205d81c *e, short w, short h) {
    e->unknown_a8_ = w;
    e->unknown_aa_ = h;
}

// USA: func_ov002_02160fb4
#if defined(jpn)
extern "C" ARM void func_ov002_02160fb4(char *base) {
    short var0, var1, var2, var3;
    func_ov002_0215be00(base, ((struct Struct_ov002_02160fb4_2 *) (base + 0x1000))->field & 0xff, 1, 1);

    memset(((struct BufOv02160fb4 *) (base + 0x1000))->buf, 0, 0x800);
    func_ov002_021610c4(base, ((struct BufOv02160fb4 *) (base + 0x1000))->buf, 0);

    Window_OpenPane(base + 0xe20, ((struct BufOv02160fb4 *) (base + 0x1000))->buf, 0, 1, 0, 1, 0);

    struct Elem_0205d81c *elem = func_0205d81c(
        (struct Struct_0205d81c *) (base + 0xe20), ((struct Struct_ov002_02160fb4_2 *) (base + 0x1000))->field & 0xff);
    if (elem == NULL) return;

    func_ov002_02157030(base, ((struct Struct_ov002_02160fb4_2 *) (base + 0x1000))->field & 0xff, &var0, &var1, &var2, &var3);
    var0 = 0x20 - var2;
    var1 = 0xf - var3;
    inline_ov002_02160fb4(elem, var0, var1);
    inline_ov002_02160fb4_2(elem, var2, var3);
    func_0205d904((unsigned char *) (base + 0xe20));
}
#else
extern "C" ARM void func_ov002_02160fb4(char *base) {
    short var5, var6, var7, var8;
    func_ov002_0215be00(base, ((struct Struct_ov002_02160fb4_2 *) (base + 0x1000))->field & 0xff, 1, 1);

    memset(((struct BufOv02160fb4 *) (base + 0x1000))->buf, 0, 0x960);
    func_ov002_021610c4(base, ((struct BufOv02160fb4 *) (base + 0x1000))->buf, 0);

    Window_OpenPane(base + 0xec8, ((struct BufOv02160fb4 *) (base + 0x1000))->buf, 0, 1, 0, 1, 0, 0);

    struct Elem_0205d81c *elem = func_0205d81c(
        (struct Struct_0205d81c *) (base + 0xec8), ((struct Struct_ov002_02160fb4_2 *) (base + 0x1000))->field & 0xff);
    if (elem == NULL) return;

    func_ov002_02157030(base, ((struct Struct_ov002_02160fb4_2 *) (base + 0x1000))->field & 0xff, &var5, &var6, &var7, &var8);
    var5 = 0x20 - var7;
    var6 = 0xf - var8;
    inline_ov002_02160fb4(elem, var5, var6);
    inline_ov002_02160fb4_2(elem, var7, var8);
    func_0205d904((unsigned char *) (base + 0xec8));
}
#endif
