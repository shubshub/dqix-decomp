// USA: func_ov003_02175504
#include <globaldefs.h>
#include "Resource/ItemTable.h"

struct Obj2081;
struct Obj020dee58;

unsigned char *FindElementByByte0xc4_02081da8(Obj2081 *, int);
bool WindowPane_IsReady(unsigned char *);
Obj020dee58 *ItemTable_Find(ItemTable *, int);
void GetLookAndTurnOffsets020809c4(void *, int, int, short *, short *);
int LookupValueFromField8(Obj020dee58 *);
void InitEntryAtIndex_0217585c(void *, int, int, int, unsigned char);
bool WindowPane_IsOpen(unsigned char *);

#if defined(jpn)
extern unsigned char data_ov003_0217e34d[];
extern unsigned char data_ov003_0217e32c[];
#else
extern unsigned char data_ov003_0217fabd[];
extern unsigned char data_ov003_0217fa9c[];
#endif

struct Struct_ov003_02175504 {
    char unknown_0_[0xac];
    short unknown_ac_;
    short unknown_ae_;
};

struct Struct_ov003_02175504_2 {
#if defined(jpn)
    unsigned char unknown_0_[0x7c4];
#else
    unsigned char unknown1_0_[0x848];
#endif
    short keys_[12];
    unsigned char unknownBeforeEntries[0x14];
    ItemTable entries;
    unsigned char unknownAfterEntries[0x10];
    Obj2081* menu;
    unsigned char unknownBeforeUpdate[0xff8 - 0x8a0];
    int updateEnabled;
    unsigned char unknownBeforeIndex[2];
    short selectedIndex;
    unsigned char unknownBeforeState[0xc];
    short state;
    unsigned char unknownAfterState[2];
    short unknown1010;
    short selection;
    short page;
};

// USA: func_ov003_02175504
extern "C" ARM void func_ov003_02175504(Battle02175504 *self) {
    Obj2081 *obj     = self->menu;
    unsigned char k  = 6;
    unsigned char *e = FindElementByByte0xc4_02081da8(obj, 3);
    if (e) {
        if (!WindowPane_IsReady(e)) return;
        short a = 7;
        short b = (short) (self->page * 6);
        for (unsigned char i = 0; i < 6; i++) {
            Obj020dee58 *it = ItemTable_Find(&self->entries,
                                                                                self->keys_[b]);
            if (it) {
                short x, y;
                GetLookAndTurnOffsets020809c4(obj, 3, a, &x, &y);
                int v = LookupValueFromField8(it);
                InitEntryAtIndex_0217585c(self, x, y - 1, (v + 6) & 0xff, k);
            }
            var1++;
            var3++;
            var4++;
        }
        return;
    }
    if (self->state == 0x77) {
        Entry02175504 *cand = 0;
        e                   = FindElementByByte0xc4_02081da8(obj, 0x15);
        if (e && WindowPane_IsReady(e)) cand = (Entry02175504 *) e;
        e = FindElementByByte0xc4_02081da8(obj, 0x16);
        if (e && WindowPane_IsReady(e)) cand = (Entry02175504 *) e;
        e = FindElementByByte0xc4_02081da8(obj, 0x1e);
        if (e && WindowPane_IsReady(e)) cand = (Entry02175504 *) e;
        if (cand) {
            int cx = cand->x_;
            int cy = cand->y_;
            cx     = (short) (cx << 3) + 3;
            cy     = (short) (cy << 3) + 3;
#if defined(jpn)
            func_ov003_0217585c(arg0, var11, var12, data_ov003_0217e34d[(arg0->unknown_1012_ + (var1 - 0x124)) & 0xff], var1);
#else
            func_ov003_0217585c(arg0, var11, var12, data_ov003_0217fabd[(arg0->unknown_1012_ + (var1 - 0x124)) & 0xff], var1);
#endif
            return;
        }
    }
    if (self->updateEnabled == 0) return;
    if (self->selectedIndex < 0) return;
    e = FindElementByByte0xc4_02081da8(obj, 0xe);
    if (!e) return;
    if (!WindowPane_IsOpen(e)) return;
    short a = 0x68;
    for (unsigned char i = 0; i < 8; i++) {
        short x, y;
        GetLookAndTurnOffsets020809c4(obj, 0xe, a, &x, &y);
#if defined(jpn)
        func_ov003_0217585c(arg0, var15, var16 - 1, data_ov003_0217e32c[var14], var1);
#else
        func_ov003_0217585c(arg0, var15, var16 - 1, data_ov003_0217fa9c[var14], var1);
#endif
        var13++;
        var1++;
    }
}
