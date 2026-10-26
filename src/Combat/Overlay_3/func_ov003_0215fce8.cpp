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
    unsigned int a;
    unsigned int b;
};
union Struct_ov003_0215fce8_4 {
    struct Struct_020e6d5c_14 *raw;
    Type_01ff91ac_4 *fn;
};

extern int data_ov003_02180cc0;
extern struct Struct_020e6d5c_14 __ptmf_null;
extern struct Struct_020e6d5c_14 data_ov003_0217ff68[];

extern "C" int func_ov017_021959b4();
extern "C" void *GlobalFlags_GetInstance(void);
extern "C" int *func_020936f8(void);
extern "C" void FlagWord_SetBits(unsigned int *word, unsigned int bits);
extern "C" void *LinkSession_GetInstance();
extern "C" void *LinkMessageQueue_GetInstance(void);
extern "C" void LinkSession_End(void *obj);
extern "C" void func_ov017_02195748(unsigned char *base);
extern "C" void func_ov017_02192594(unsigned char* base);
extern "C" void func_020939fc(unsigned char *obj);
struct BitArrayObj0205e854;
extern "C" void *func_0205e854(BitArrayObj0205e854 *obj);
struct Controller020421a0;
extern "C" Controller020421a0 *MessageSystem_GetInstance(void);
extern "C" void MessageSystem_Reset(char *obj);
struct Struct_020e28dc;
extern "C" int func_020e28dc(struct Struct_020e28dc *o);
struct Struct_020e25e8;
extern "C" void func_020e25e8(struct Struct_020e25e8 *obj);
struct Struct_020e263c_2;
extern "C" void func_020e263c(struct Struct_020e263c_2 *obj, int value);
struct Struct_0207fc6c;
extern "C" void func_0207fc6c(struct Struct_0207fc6c *obj, int arg);
struct Struct_ov003_0215fce8;
extern "C" void func_ov003_021604d0(struct Struct_ov003_0215fce8 *s);
struct Struct_ov003_0215fce8_2;
extern "C" void func_ov003_02160b2c(struct Struct_ov003_0215fce8_2 *s);
extern "C" int func_ov003_02160cc0(char *s);
extern "C" void func_ov003_02167494(void *obj, int arg);
extern "C" void func_ov003_02160ec4(void *self);
extern "C" void func_ov003_02160f4c(void *self);
extern "C" void func_ov003_02160794(void *self);
extern "C" int func_02081f20(void *obj, int scaleCount);
extern "C" int func_020800fc(void *menu, short *cursor, short arg2, unsigned short arg3, unsigned char a, bool b);
extern "C" void func_020804fc(void *menu, int group);
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
            int *g  = func_020936f8();
            FlagWord_SetBits((unsigned int *) p, 0x20);
            unsigned char *r8 = (unsigned char*)GetGameResources();
            void *r7          = LinkSession_GetInstance();
            void *d           = LinkMessageQueue_GetInstance();
            SetFlags00((GameResources*)r8, 2);
            LinkSession_End(r7);
            func_ov017_02195748(r8);
            func_ov017_02192594(r8);
            func_020939fc((unsigned char *) g);
            func_0205e854((BitArrayObj0205e854 *) d);
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
        MessageSystem_Reset((char *) MessageSystem_GetInstance());
        *(short *) (self + SO(0x486)) = -1;
        *(short *) (self + SO(0x484)) = *(short *) (self + SO(0x486));
        self[SO(0x4a5)]                      = 0;
        struct Struct_020e28dc *var7       = *(struct Struct_020e28dc **) (self + SO(0x390));
        if (var7 != 0 && func_020e28dc(var7) != 0) {
            func_020e25e8(*(struct Struct_020e25e8 **) (self + SO(0x390)));
        }
        self[SO(0x4a3)] = 0xf;
        self[SO(0x4a4)] = 0;
        self[SO(0x4bf)] = 0;
    }

    if (arg == 0) arg = 1;
    *(int *) (self + SO(0x460)) = arg;
    void *var8              = *(void **) (self + SO(0x318));
    if (var8 != 0) {
        func_ov003_02167494(var8, arg);
    }
    func_ov003_021604d0((struct Struct_ov003_0215fce8 *) self);
    func_ov003_02160ec4(self);
    if (*(short *) (self + SO(0x484)) >= 0) {
        *(unsigned int *) (self + SO(0x464)) &= ~1u;
        func_ov003_02160f4c(self);
        return 0;
    }
    func_ov003_02160b2c((struct Struct_ov003_0215fce8_2 *) self);
    self[SO(0x4a6)] = 0;
    *(unsigned int *) (self + SO(0x464)) &= ~0x4000u;
    struct Struct_020e28dc *var9;
    if (*(int *) (self + SO(0x470)) != 0 && (var9 = *(struct Struct_020e28dc **) (self + SO(0x390))) != 0 &&
        func_020e28dc(var9) != 0)
    {
        func_020e263c(*(struct Struct_020e263c_2 **) (self + SO(0x390)), arg);
    }
    char *m = *(char **) (self + SO(0x324));
    if (m != 0) {
        func_0207fc6c((struct Struct_0207fc6c *) m, arg);
    }
    if (func_ov003_02160cc0((char *) self) == 0) return 0;
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
            func_020804fc(m, *(short *) (self + SO(0x488)));
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
    struct Struct_020e6d5c_14 *tbl = data_ov003_0217ff68;
    if (tbl[idx].a == 0) {
        return 1;
    }
    union Struct_ov003_0215fce8_4 var13;
    var13.raw = &tbl[idx];
    ((Struct_ov003_0215fce8_3 *) self->*(*var13.fn))();
    return 0;
}
