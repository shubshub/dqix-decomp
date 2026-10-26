// USA: func_ov003_02175504
#include <globaldefs.h>
#include "Resource/ItemTable.h"

struct Struct_0207fdcc_2;
struct Obj020dee58;

extern "C" unsigned char *func_02081da8(Struct_0207fdcc_2 *, int);
extern "C" bool WindowPane_IsReady(unsigned char *);
extern "C" Obj020dee58 *ItemTable_Find(ItemTable *, int);
extern "C" void func_020809c4(void *, int, int, short *, short *);
extern "C" int func_020dee58(Obj020dee58 *);
extern "C" void func_ov003_0217585c(void *, int, int, int, unsigned char);
extern "C" bool WindowPane_IsOpen(unsigned char *);

#if defined(jpn)
extern unsigned char data_ov003_0217e34d[];
extern unsigned char data_ov003_0217e32c[];
#else
extern unsigned char data_ov003_0217fabd[];
extern unsigned char data_ov003_0217fa9c[];
#endif

struct Entry02175504 {
    char unk_0[0xac];
    short x_;
    short y_;
};

struct Struct_ov003_02175504_2 {
#if defined(jpn)
    unsigned char unknown_0_[0x7c4];
#else
    unsigned char unknown1_0_[0x848];
#endif
    short unknown_848_[12];
    unsigned char unknown_860_[0x14];
    ItemTable entries;
    unsigned char unknown_88c_[0x10];
    Struct_0207fdcc_2* menu;
    unsigned char unknown_8a0_[0xff8 - 0x8a0];
    int unknown_ff8_;
    unsigned char unknown_ffc_[2];
    short unknown_ffe_;
    unsigned char unknown_1000_[0xc];
    short state;
    unsigned char unknown_100e_[2];
    short unknown_1010_;
    short selection;
    short page;
};

// USA: func_ov003_02175504
extern "C" ARM void func_ov003_02175504(Struct_ov003_02175504_2 *self) {
    Struct_0207fdcc_2 *obj     = self->menu;
    unsigned char k  = 6;
    unsigned char *e = func_02081da8(obj, 3);
    if (e) {
        if (!WindowPane_IsReady(e)) return;
        short a = 7;
        short b = (short) (self->page * 6);
        for (unsigned char i = 0; i < 6; i++) {
            Obj020dee58 *it = ItemTable_Find(&self->entries,
                                                                                self->unknown_848_[b]);
            if (it) {
                short x, y;
                func_020809c4(obj, 3, a, &x, &y);
                int v = func_020dee58(it);
                func_ov003_0217585c(self, x, y - 1, (v + 6) & 0xff, k);
            }
            k++;
            a++;
            b++;
        }
        return;
    }
    if (self->state == 0x77) {
        Entry02175504 *cand = 0;
        e                   = func_02081da8(obj, 0x15);
        if (e && WindowPane_IsReady(e)) cand = (Entry02175504 *) e;
        e = func_02081da8(obj, 0x16);
        if (e && WindowPane_IsReady(e)) cand = (Entry02175504 *) e;
        e = func_02081da8(obj, 0x1e);
        if (e && WindowPane_IsReady(e)) cand = (Entry02175504 *) e;
        if (cand) {
            int cx = cand->x_;
            int var12 = cand->y_;
            cx     = (short) (cx << 3) + 3;
            var12     = (short) (var12 << 3) + 3;
#if defined(jpn)
            func_ov003_0217585c(self, cx, var12, data_ov003_0217e34d[(self->selection + (k - 0x124)) & 0xff], k);
#else
            func_ov003_0217585c(self, cx, var12, data_ov003_0217fabd[(self->selection + (k - 0x124)) & 0xff], k);
#endif
            return;
        }
    }
    if (self->unknown_ff8_ == 0) return;
    if (self->unknown_ffe_ < 0) return;
    e = func_02081da8(obj, 0xe);
    if (!e) return;
    if (!WindowPane_IsOpen(e)) return;
    short a = 0x68;
    for (unsigned char i = 0; i < 8; i++) {
        short x, y;
        func_020809c4(obj, 0xe, a, &x, &y);
#if defined(jpn)
        func_ov003_0217585c(self, x, y - 1, data_ov003_0217e32c[i], k);
#else
        func_ov003_0217585c(self, x, y - 1, data_ov003_0217fa9c[i], k);
#endif
        a++;
        k++;
    }
}
