#include "std_library_functions.h"
#include <globaldefs.h>

extern "C" void func_ov002_0215be00(void *base, int a, int b, int c);
extern "C" void func_ov002_0215f084(void *base, void *dst, int flag);
#if defined(jpn)
extern "C" void Window_OpenPane(void *arg0, void *arg1, int arg2, int arg3, int arg4, int p5, int p6);
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
struct Struct0205de24;
extern "C" void func_0205de24(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
struct StructA0205d5d0;
extern "C" void Window_SetPaneText(struct StructA0205d5d0 *s, int key, int buf, int a3,
                                                                     unsigned char a4);

struct BufOv0215ef60 {
    char pad[0xbd0];
    void *buf;
};

static inline void inline_ov002_0215ef60(struct Elem_0205d81c *e, short x, short y) {
    e->unknown_ac_ = x;
    e->unknown_ae_ = y;
}

// USA: func_ov002_0215ef60
extern "C" ARM void func_ov002_0215ef60(char *base) {
#if defined(jpn)
    func_0205de24((struct Struct0205de24 *) (base + 0xe20), 0, 2);
    func_ov002_0215be00(base, 0x14, 0x15, 8);

    memset(*(void **) (base + 0x1000 + 0xa98), 0, 0x800);
    func_ov002_0215f084(base, *(void **) (base + 0x1000 + 0xa98), 0);

    Window_OpenPane(base + 0xe20, *(void **) (base + 0x1000 + 0xa98), 0, 0, 0, 1, 0);
#else
    short x = 0x17;
    short y = 9;
    short w = 0;
    struct Elem_0205d81c *elem =
        func_0205d81c((struct Struct_0205d81c *) (base + 0xec8), 0x10);
    if (elem != NULL) {
        x = elem->unknown_ac_;
        w = elem->unknown_a8_;
        y = elem->unknown_ae_ + elem->unknown_aa_;
    }
    func_0205de24((struct Struct0205de24 *) (base + 0xec8), 0, 2);
    func_ov002_0215be00(base, 0x13, x, y);

    memset(((struct BufOv0215ef60 *) (base + 0x1000))->buf, 0, 0x960);
    func_ov002_0215f084(base, ((struct BufOv0215ef60 *) (base + 0x1000))->buf, 0);

    Window_OpenPane(base + 0xec8, ((struct BufOv0215ef60 *) (base + 0x1000))->buf, 0, 0, 0, 1, 0, 0);

    elem = func_0205d81c((struct Struct_0205d81c *) (base + 0xec8), 0x13);
    if (elem == NULL) return;
    inline_ov002_0215ef60(elem, x + w - elem->unknown_a8_, elem->unknown_ae_);
    Window_SetPaneText((struct StructA0205d5d0 *) (base + 0xec8), 0x13,
                                                         (int) ((struct BufOv0215ef60 *) (base + 0x1000))->buf, 1, 0);
#endif
}
