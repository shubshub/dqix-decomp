#include <globaldefs.h>
#include "Resource/Brightness.h"

#if defined(jpn)
#define data_ov003_02180cc0 data_ov003_0217ef38
#define data_ov003_0217ff68 data_ov003_0217e758
#endif

class PMFObj0215fce8 {
public:
    virtual void Dummy0215fce8();
};
typedef void (PMFObj0215fce8::*MemFn0215fce8)();

struct Entry0215fce8 {
    unsigned int a;
    unsigned int b;
};
union PMFCast0215fce8 {
    struct Entry0215fce8 *raw;
    MemFn0215fce8 *fn;
};

extern int data_ov003_02180cc0;
extern struct Entry0215fce8 __ptmf_null;
extern struct Entry0215fce8 data_ov003_0217ff68[];

extern "C" int func_ov017_021959b4();
void *GetDataPtr02114e04_020d6c00(void);
int *GetGlobal02109030_020936f8(void);
void OrBitsIntoField0_020466e4(unsigned int *word, unsigned int bits);
extern "C" void *func_0202ae18();
void *GetData02100044_0202ae24(void);
extern "C" void func_0202b0f4(void *obj);
void ClearTwoBytesAtField_02195748(unsigned char *base);
void SetFlag1ForFlagombatants_02192594_02192594(unsigned char* base);
void ClearFlag0x3c9Bit0AndCleanup_020939fc(unsigned char *obj);
struct BitArrayObj0205e854;
void *FillBitArray0x1524WithFF(BitArrayObj0205e854 *obj);
struct Controller020421a0;
Controller020421a0 *GetGlobalField0x1c020421a0(void);
void ReinitController02043204(char *obj);
struct Outer020e28dc;
int GetInnerFlagBit0020e28dc(struct Outer020e28dc *o);
struct Obj020e25e8;
void ResetSelectionState020e25e8(struct Obj020e25e8 *obj);
struct Ctx020e263c;
void UpdateEntryStateAndPosition(struct Ctx020e263c *obj, int value);
struct Obj0207fc6c;
void CallFunc0204c87cOverEntries0207fc6c(struct Obj0207fc6c *obj, int arg);
struct S021604d0;
void UpdateIfFlag4a3_021604d0(struct S021604d0 *s);
struct S02160b2c;
void ClearGlobalField9ae_02160b2c(struct S02160b2c *s);
int DispatchByFlags464_02160cc0(char *s);
extern "C" void func_ov003_02167494(void *obj, int arg);
extern "C" void func_ov003_02160ec4(void *self);
extern "C" void func_ov003_02160f4c(void *self);
extern "C" void func_ov003_02160794(void *self);
extern "C" int func_02081f20(void *obj, int scaleCount);
extern "C" int func_020800fc(void *menu, short *cursor, short prevCursor, unsigned short buttons, unsigned char a, bool b);
void ClearSublistEntriesFlag4_020804fc(void *menu, int group);
extern "C" void func_020813ec(void *obj, int key);

#if defined(jpn)
#define RG(usa, jpn) (jpn)
#define SO(off) ((off) >= 0x45c ? (off) - 0x1d8 : (off) - 0x118)
#else
#define RG(usa, jpn) (usa)
#define SO(off) (off)
#endif

// USA: func_ov003_0215fce8
extern "C" ARM int func_ov003_0215fce8(unsigned char *self, int arg) {
    if (self[SO(0x4c0)] == 0 && func_ov017_021959b4() != 0) {
        unsigned char a3 = self[SO(0x4a3)];
        if ((a3 == 0xb && self[SO(0x4a4)] == 0x11) || (a3 == 6 && self[SO(0x4a4)] == 0)) {
            void *p = GetDataPtr02114e04_020d6c00();
            int *g  = GetGlobal02109030_020936f8();
            OrBitsIntoField0_020466e4((unsigned int *) p, 0x20);
            unsigned char *r8 = (unsigned char*)GetGameResources();
            void *r7          = func_0202ae18();
            void *d           = GetData02100044_0202ae24();
            SetFlags00((GameResources*)r8, 2);
            func_0202b0f4(r7);
            ClearTwoBytesAtField_02195748(r8);
            SetFlag1ForFlagombatants_02192594_02192594(r8);
            ClearFlag0x3c9Bit0AndCleanup_020939fc((unsigned char *) g);
            FillBitArray0x1524WithFF((BitArrayObj0205e854 *) d);
            ClearFlags00((GameResources*)r8, 0x40);
            r8[RG(0x42e3, 0x40c3)]               = 0;
            r8[RG(0x42e2, 0x40c2)]               = 0;
            *(short *) (self + SO(0x484)) = 0x37;
            self[SO(0x4a5)]                      = 0;
            self[SO(0x4a4)]                      = 5;
            self[SO(0x4a3)]                      = 0xb;
            *(unsigned int *) (self + SO(0x464)) = (*(unsigned int *) (self + SO(0x464)) & ~2u) | 4u;
        } else {
            self[SO(0x4c0)] = 1;
            self[SO(0x4bf)] = 1;
        }
    }

    if (!(*(unsigned int *) (self + SO(0x464)) & 0x2000000) && self[SO(0x4bf)] != 0) {
        short *sel = *(short **) (self + SO(0x470));
        if (sel != 0) *sel = -1;
        *(int *) (self + SO(0x470)) = 0;
        ReinitController02043204((char *) GetGlobalField0x1c020421a0());
        *(short *) (self + SO(0x486)) = -1;
        *(short *) (self + SO(0x484)) = *(short *) (self + SO(0x486));
        self[SO(0x4a5)]                      = 0;
        struct Outer020e28dc *o390       = *(struct Outer020e28dc **) (self + SO(0x390));
        if (o390 != 0 && GetInnerFlagBit0020e28dc(o390) != 0) {
            ResetSelectionState020e25e8(*(struct Obj020e25e8 **) (self + SO(0x390)));
        }
        self[SO(0x4a3)] = 0xf;
        self[SO(0x4a4)] = 0;
        self[SO(0x4bf)] = 0;
    }

    if (arg == 0) arg = 1;
    *(int *) (self + SO(0x460)) = arg;
    void *o318              = *(void **) (self + SO(0x318));
    if (o318 != 0) {
        func_ov003_02167494(o318, arg);
    }
    UpdateIfFlag4a3_021604d0((struct S021604d0 *) self);
    func_ov003_02160ec4(self);
    if (*(short *) (self + SO(0x484)) >= 0) {
        *(unsigned int *) (self + SO(0x464)) &= ~1u;
        func_ov003_02160f4c(self);
        return 0;
    }
    ClearGlobalField9ae_02160b2c((struct S02160b2c *) self);
    self[SO(0x4a6)] = 0;
    *(unsigned int *) (self + SO(0x464)) &= ~0x4000u;
    struct Outer020e28dc *q390;
    if (*(int *) (self + SO(0x470)) != 0 && (q390 = *(struct Outer020e28dc **) (self + SO(0x390))) != 0 &&
        GetInnerFlagBit0020e28dc(q390) != 0)
    {
        UpdateEntryStateAndPosition(*(struct Ctx020e263c **) (self + SO(0x390)), arg);
    }
    char *m = *(char **) (self + SO(0x324));
    if (m != 0) {
        CallFunc0204c87cOverEntries0207fc6c((struct Obj0207fc6c *) m, arg);
    }
    if (DispatchByFlags464_02160cc0((char *) self) == 0) return 0;
    if (*(unsigned int *) (self + SO(0x464)) & 0x1000) return 0;
    if (*(int *) (self + SO(0x470)) != 0) {
        *(unsigned int *) (self + SO(0x464)) &= ~0x1000000u;
        func_02081f20((char *) self + SO(0x308), arg);
        *(short *) (self + SO(0x474)) = **(short **) (self + SO(0x470));
        *(int *) (self + SO(0x45c)) =
            func_020800fc(m, *(short **) (self + SO(0x470)), *(short *) (self + SO(0x474)),
                          *(unsigned short *) (self + SO(0x314)), self[SO(0x316)], (*(unsigned int *) (self + SO(0x464)) & 1) != 0);
        *(short *) (m + RG(0x36, 0x2a)) = **(short **) (self + SO(0x470));
        if (*(int *) (self + SO(0x45c)) != 0) {
            ClearSublistEntriesFlag4_020804fc(m, *(short *) (self + SO(0x488)));
        }
        if (*(short *) (self + SO(0x474)) != **(short **) (self + SO(0x470))) {
            func_020813ec(m, *(short *) (self + SO(0x488)));
            *(unsigned int *) (self + SO(0x464)) |= 0x1000000;
            func_ov003_02160794(self);
        }
    }
    *(unsigned int *) (self + SO(0x464)) &= ~1u;
    if (!(data_ov003_02180cc0 & 1)) {
        *(unsigned long long *) ((char *) data_ov003_0217ff68 + 0x80) = *(const unsigned long long *) &__ptmf_null;
        data_ov003_02180cc0 |= 1;
    }
    unsigned char idx         = self[SO(0x4a3)];
    struct Entry0215fce8 *tbl = data_ov003_0217ff68;
    if (tbl[idx].a == 0) {
        return 1;
    }
    union PMFCast0215fce8 pmf;
    pmf.raw = &tbl[idx];
    ((PMFObj0215fce8 *) self->*(*pmf.fn))();
    return 0;
}
