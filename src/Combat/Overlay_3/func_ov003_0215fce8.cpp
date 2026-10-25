#include <globaldefs.h>
#include "Resource/Brightness.h"

#if defined(jpn)
#define data_ov003_02180cc0 data_ov003_0217ef38
#define data_ov003_0217ff68 data_ov003_0217e758
#endif

class Struct_ov003_0215fce8_3 {
public:
    virtual void inline_ov003_0215fce8();
};
typedef void (Struct_ov003_0215fce8_3::*Type_01ff91ac_4)();

struct Struct_020e6d5c_14 {
    unsigned int unknown_0_;
    unsigned int unknown_4_;
};
union Struct_ov003_0215fce8_4 {
    struct Struct_020e6d5c_14 *unknown_0_;
    Type_01ff91ac_4 *unknown1_0_;
};

extern int data_ov003_02180cc0;
extern struct Entry0215fce8 __ptmf_null;
extern struct Entry0215fce8 data_ov003_0217ff68[];

extern "C" int func_ov017_021959b4();
void *GlobalFlags_GetInstance(void);
int *GetGlobal02109030_020936f8(void);
void FlagWord_SetBits(unsigned int *word, unsigned int bits);
extern "C" void *func_0202ae18();
void *GetData02100044_0202ae24(void);
extern "C" void func_0202b0f4(void *obj);
void ClearTwoBytesAtField_02195748(unsigned char *base);
void SetFlag1ForFlagombatants_02192594_02192594(unsigned char* base);
void ClearFlag0x3c9Bit0AndCleanup_020939fc(unsigned char *obj);
struct BitArrayObj0205e854;
void *FillBitArray0x1524WithFF(BitArrayObj0205e854 *obj);
struct Controller020421a0;
Controller020421a0 *MessageSystem_GetInstance(void);
void MessageSystem_Reset(char *obj);
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
            void *p = GlobalFlags_GetInstance();
            int *g  = GetGlobal02109030_020936f8();
            FlagWord_SetBits((unsigned int *) p, 0x20);
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
            arg0[SO(0x4c0)] = 1;
            arg0[SO(0x4bf)] = 1;
        }
    }

    if (!(*(unsigned int *) (self + SO(0x464)) & 0x2000000) && self[SO(0x4bf)] != 0) {
        short *sel = *(short **) (self + SO(0x470));
        if (sel != 0) *sel = -1;
        *(int *) (self + SO(0x470)) = 0;
        MessageSystem_Reset((char *) MessageSystem_GetInstance());
        *(short *) (self + SO(0x486)) = -1;
        *(short *) (self + SO(0x484)) = *(short *) (self + SO(0x486));
        self[SO(0x4a5)]                      = 0;
        struct Outer020e28dc *o390       = *(struct Outer020e28dc **) (self + SO(0x390));
        if (o390 != 0 && GetInnerFlagBit0020e28dc(o390) != 0) {
            ResetSelectionState020e25e8(*(struct Obj020e25e8 **) (self + SO(0x390)));
        }
        arg0[SO(0x4a3)] = 0xf;
        arg0[SO(0x4a4)] = 0;
        arg0[SO(0x4bf)] = 0;
    }

    if (arg1 == 0) arg1 = 1;
    *(int *) (arg0 + SO(0x460)) = arg1;
    void *var8              = *(void **) (arg0 + SO(0x318));
    if (var8 != 0) {
        func_ov003_02167494(var8, arg1);
    }
    func_ov003_021604d0((struct Struct_ov003_0215fce8 *) arg0);
    func_ov003_02160ec4(arg0);
    if (*(short *) (arg0 + SO(0x484)) >= 0) {
        *(unsigned int *) (arg0 + SO(0x464)) &= ~1u;
        func_ov003_02160f4c(arg0);
        return 0;
    }
    func_ov003_02160b2c((struct Struct_ov003_0215fce8_2 *) arg0);
    arg0[SO(0x4a6)] = 0;
    *(unsigned int *) (arg0 + SO(0x464)) &= ~0x4000u;
    struct Struct_020e28dc *var9;
    if (*(int *) (arg0 + SO(0x470)) != 0 && (var9 = *(struct Struct_020e28dc **) (arg0 + SO(0x390))) != 0 &&
        func_020e28dc(var9) != 0)
    {
        func_020e263c(*(struct Struct_020e263c_2 **) (arg0 + SO(0x390)), arg1);
    }
    char *var10 = *(char **) (arg0 + SO(0x324));
    if (var10 != 0) {
        func_0207fc6c((struct Struct_0207fc6c *) var10, arg1);
    }
    if (func_ov003_02160cc0((char *) arg0) == 0) return 0;
    if (*(unsigned int *) (arg0 + SO(0x464)) & 0x1000) return 0;
    if (*(int *) (arg0 + SO(0x470)) != 0) {
        *(unsigned int *) (arg0 + SO(0x464)) &= ~0x1000000u;
        func_02081f20((char *) arg0 + SO(0x308), arg1);
        *(short *) (arg0 + SO(0x474)) = **(short **) (arg0 + SO(0x470));
        *(int *) (arg0 + SO(0x45c)) =
            func_020800fc(var10, *(short **) (arg0 + SO(0x470)), *(short *) (arg0 + SO(0x474)),
                          *(unsigned short *) (arg0 + SO(0x314)), arg0[SO(0x316)], (*(unsigned int *) (arg0 + SO(0x464)) & 1) != 0);
        *(short *) (var10 + RG(0x36, 0x2a)) = **(short **) (arg0 + SO(0x470));
        if (*(int *) (arg0 + SO(0x45c)) != 0) {
            func_020804fc(var10, *(short *) (arg0 + SO(0x488)));
        }
        if (*(short *) (arg0 + SO(0x474)) != **(short **) (arg0 + SO(0x470))) {
            func_020813ec(var10, *(short *) (arg0 + SO(0x488)));
            *(unsigned int *) (arg0 + SO(0x464)) |= 0x1000000;
            func_ov003_02160794(arg0);
        }
    }
    *(unsigned int *) (arg0 + SO(0x464)) &= ~1u;
    if (!(data_ov003_02180cc0 & 1)) {
        *(unsigned long long *) ((char *) data_ov003_0217ff68 + 0x80) = *(const unsigned long long *) &__ptmf_null;
        data_ov003_02180cc0 |= 1;
    }
    unsigned char var11         = arg0[SO(0x4a3)];
    struct Struct_020e6d5c_14 *var12 = data_ov003_0217ff68;
    if (var12[var11].unknown_0_ == 0) {
        return 1;
    }
    union Struct_ov003_0215fce8_4 var13;
    var13.unknown_0_ = &var12[var11];
    ((Struct_ov003_0215fce8_3 *) arg0->*(*var13.unknown1_0_))();
    return 0;
}
