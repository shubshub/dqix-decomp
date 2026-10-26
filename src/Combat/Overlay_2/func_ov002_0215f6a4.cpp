#include "std_library_functions.h"
#include <globaldefs.h>

#if defined(jpn)
#define func_ov002_0215fcc0 func_ov002_02160d14
#define func_ov002_0215f8b8 func_ov002_02160944
#endif
extern "C" void func_ov002_0215be00(void *base, int a, int b, int c);
extern "C" void func_ov002_02160004(void *base, void *dst, int flag);
extern "C" void func_ov002_0215fcc0(void *base, void *dst, int flag);
extern "C" void func_ov002_0215f8b8(void *base, void *dst, int flag);
#if defined(jpn)
#define RG(u, j) (j)
extern "C" void Window_OpenPane(void *arg0, void *arg1, int arg2, int arg3, int p4, int p5, int p6);
#define D304(a, b, p2, p3, p4, p5, p6, p7) Window_OpenPane(a, b, 0, 1, 0, 1, 0)
#else
#define RG(u, j) (u)
extern "C" void Window_OpenPane(void *a, void *b, int p2, int p3, int p4, int p5, int p6, int p7);
#define D304(a, b, p2, p3, p4, p5, p6, p7) Window_OpenPane(a, b, p2, p3, p4, p5, p6, p7)
#endif

struct Struct_0205d81c;
struct Elem_0205d81c {
    char pad0[0xaa];
    short unknown_aa_;
    short unknown_ac_;
    short unknown_ae_;
    char pad1[0xc2 - 0xb0];
    short unknown_c2_;
};
extern "C" struct Elem_0205d81c *func_0205d81c(struct Struct_0205d81c *s, int key);
struct Struct0205de24;
extern "C" void func_0205de24(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);

struct BufOv0215f6a4 {
    char pad[RG(0xbd0, 0xa98)];
    char *buf;
};
struct Struct_ov002_0215f6a4_2 {
    char pad[RG(0xbb8, 0xa80)];
    int field;
};

static inline void inline_ov002_0215f6a4(struct Elem_0205d81c *e, short x, short y) {
    e->unknown_ac_ = x;
    e->unknown_ae_ = y;
    e->unknown_c2_ = 0;
}

// USA: func_ov002_0215f6a4
extern "C" ARM void func_ov002_0215f6a4(char *base) {
    func_0205de24((struct Struct0205de24 *) (base + RG(0xec8, 0xe20)), 0, 3);
    func_ov002_0215be00(base, RG(0x1b, 0x1c), RG(0x11, 0x13), 1);
    memset(((struct BufOv0215f6a4 *) (base + 0x1000))->buf, 0, RG(0x960, 0x800));
    func_ov002_02160004(base, ((struct BufOv0215f6a4 *) (base + 0x1000))->buf, 0);
    D304(base + RG(0xec8, 0xe20), ((struct BufOv0215f6a4 *) (base + 0x1000))->buf, 0, 0, 0, 0, 0, 0);

    func_0205de24((struct Struct0205de24 *) (base + RG(0xec8, 0xe20)), 0, 3);
    func_ov002_0215be00(base, RG(0x1a, 0x1b), 1, 1);
    memset(((struct BufOv0215f6a4 *) (base + 0x1000))->buf, 0, RG(0x960, 0x800));
    func_ov002_0215fcc0(base, ((struct BufOv0215f6a4 *) (base + 0x1000))->buf, 0);
    D304(base + RG(0xec8, 0xe20), ((struct BufOv0215f6a4 *) (base + 0x1000))->buf, 0, 1, 0, 1, 0, 0);

    func_0205de24((struct Struct0205de24 *) (base + RG(0xec8, 0xe20)), 0, 2);
    func_ov002_0215be00(base, ((struct Struct_ov002_0215f6a4_2 *) (base + 0x1000))->field & 0xff, 1, 1);
    memset(((struct BufOv0215f6a4 *) (base + 0x1000))->buf, 0, RG(0x960, 0x800));
    func_ov002_0215f8b8(base, ((struct BufOv0215f6a4 *) (base + 0x1000))->buf, 0);
    D304(base + RG(0xec8, 0xe20), ((struct BufOv0215f6a4 *) (base + 0x1000))->buf, 0, 1, 0, 1, 0, 0);

    struct Elem_0205d81c *elem = func_0205d81c(
        (struct Struct_0205d81c *) (base + RG(0xec8, 0xe20)), ((struct Struct_ov002_0215f6a4_2 *) (base + 0x1000))->field & 0xff);
    if (elem == NULL) return;
    short x = elem->unknown_ac_;
    short y = elem->unknown_ae_;
    short h = elem->unknown_aa_;
    elem    = func_0205d81c((struct Struct_0205d81c *) (base + RG(0xec8, 0xe20)), RG(0x1a, 0x1b));
    if (elem != NULL) {
        inline_ov002_0215f6a4(elem, x, y + h);
    }
    elem = func_0205d81c((struct Struct_0205d81c *) (base + RG(0xec8, 0xe20)), RG(0x1b, 0x1c));
    if (elem != NULL) {
        inline_ov002_0215f6a4(elem, RG(0x11, 0x13), y + h);
    }
}
