#include "GameState/GameState.h"
#include "std_library_functions.h"
#include <globaldefs.h>

extern "C" void func_ov002_02157480(void *obj, int *arr);
extern "C" void func_ov002_0215be00(void *base, int a, int b, int c);
extern "C" void func_ov002_021605d4(void *base, void *dst, int flag);
extern "C" void func_ov002_0216049c(void *base, void *dst, int flag);
extern "C" void func_ov002_0215b9a4(void *base, int a, int b);
extern "C" void Window_OpenPane(void *a, void *b, int p2, int p3, int p4, int p5, int p6, int p7);
extern "C" unsigned char data_ov002_0216c9f9[];

struct Struct_ov002_02155960_2;
struct Struct_ov002_02155960_3;
struct Struct_ov002_02155960_4 {
    char unknown_0_[0xa8];
    short unknown_a8_;
    short unknown_aa_;
    short unknown_ac_;
    short unknown_ae_;
};
struct Elem_0205d81c *FindElementByC40205d81c(struct Struct_0205d81c *s, int key);
struct Struct0205de24;
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
void Window_SetPanePalette(struct Struct_0205d81c *s, int a, int b);
void SetElementFlag0x20ByKey0205def8(struct Struct_0205def8 *s, int a, int b);

struct Struct_ov002_02160274 {
    char unknown_0_[0xbd0];
    char *unknown_bd0_;
};
struct Struct_ov002_02160274_2 {
    char unknown_0_[0xbb8];
    int unknown_bb8_;
};

static inline int inline_ov002_02160274(int arg0) {
    return (arg0 >= 0 && arg0 <= 3) ? 1 : 0;
}
static inline void inline_ov002_02160274_2(struct Struct_ov002_02155960_4 *arg0, short arg1, short arg2) {
    arg0->unknown_ac_ = arg1;
    arg0->unknown_ae_ = arg2;
}

// USA: func_ov002_02160274
extern "C" ARM void func_ov002_02160274(char *arg0) {
    int var0[4];
    GameState *var1 = GameState::GetInstance();
    func_ov002_02157480(arg0, var0);
    int var2 = 0;
    for (int var3 = 0; var3 < 4; var3++) {
        if (inline_ov002_02160274(var0[var3]) && func_0200ff1c(var1, var0[var3]) != NULL) {
            var2++;
        }
    }
    int h = n * 2;
    if (n == 1) h++;
    func_ov002_0215be00(base, 0x20, 0x10, (short) (h + 10));
    memset(((struct BufOv02160274 *) (base + 0x1000))->buf, 0, 0x960);
    func_ov002_021605d4(base, ((struct BufOv02160274 *) (base + 0x1000))->buf, 0);
    Window_OpenPane(base + 0xec8, ((struct BufOv02160274 *) (base + 0x1000))->buf, 0, 0, 0, 1, 0, 0);

    FindAndLinkMatchingEntry0205de24((struct Struct0205de24 *) (base + 0xec8), 0, 2);
    func_ov002_0215be00(base, ((struct FieldOv02160274 *) (base + 0x1000))->field & 0xff, 0x10, 8);
    memset(((struct BufOv02160274 *) (base + 0x1000))->buf, 0, 0x960);
    func_ov002_0216049c(base, ((struct BufOv02160274 *) (base + 0x1000))->buf, 0);
    Window_OpenPane(base + 0xec8, ((struct BufOv02160274 *) (base + 0x1000))->buf, 0, 1, 0, 1, 0, 0);

    Window_SetPanePalette((struct Struct_0205d81c *) (base + 0xec8), 0x20, 0);
    SetElementFlag0x20ByKey0205def8((struct Struct_0205def8 *) (base + 0xec8), 0, 0x29);
    struct Elem_0205d81c *elem =
        FindElementByC40205d81c((struct Struct_0205d81c *) (base + 0xec8), 0x15);
    if (elem != NULL) {
        int x = elem->fac + elem->fa8;
        for (int i = 0; i < 2; i++) {
            struct Elem_0205d81c *e = FindElementByC40205d81c(
                (struct Struct_0205d81c *) (base + 0x2c8 + 0xc00), data_ov002_0216c9f9[i]);
            if (e != NULL) {
                SetPos02160274(e, x, e->fae);
            }
        }
    }
    func_ov002_0215b9a4(arg0, ((struct Struct_ov002_02160274_2 *) (arg0 + 0x1000))->unknown_bb8_ & 0xff, 0);
#endif
}
