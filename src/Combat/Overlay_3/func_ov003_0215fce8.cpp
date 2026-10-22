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
extern "C" void *func_020d6c00(void);
extern "C" int *func_020936f8(void);
extern "C" void func_020466e4(unsigned int *arg0, unsigned int arg1);
extern "C" void *func_0202ae18();
extern "C" void *func_0202ae24(void);
extern "C" void func_0202b0f4(void *arg0);
extern "C" void func_ov017_02195748(unsigned char *arg0);
extern "C" void func_ov017_02192594(unsigned char* arg0);
extern "C" void func_020939fc(unsigned char *arg0);
struct Struct_0205e854;
extern "C" void *func_0205e854(Struct_0205e854 *arg0);
struct Struct_ov003_021549a8;
extern "C" Struct_ov003_021549a8 *func_020421a0(void);
extern "C" void func_02043204(char *arg0);
struct Struct_020e28dc;
extern "C" int func_020e28dc(struct Struct_020e28dc *arg0);
struct Struct_020e25e8;
extern "C" void func_020e25e8(struct Struct_020e25e8 *arg0);
struct Struct_020e263c_2;
extern "C" void func_020e263c(struct Struct_020e263c_2 *arg0, int arg1);
struct Struct_0207fc6c;
extern "C" void func_0207fc6c(struct Struct_0207fc6c *arg0, int arg1);
struct Struct_ov003_0215fce8;
extern "C" void func_ov003_021604d0(struct Struct_ov003_0215fce8 *arg0);
struct Struct_ov003_0215fce8_2;
extern "C" void func_ov003_02160b2c(struct Struct_ov003_0215fce8_2 *arg0);
extern "C" int func_ov003_02160cc0(char *arg0);
extern "C" void func_ov003_02167494(void *arg0, int arg1);
extern "C" void func_ov003_02160ec4(void *arg0);
extern "C" void func_ov003_02160f4c(void *arg0);
extern "C" void func_ov003_02160794(void *arg0);
extern "C" int func_02081f20(void *arg0, int arg1);
extern "C" int func_020800fc(void *arg0, short *arg1, short arg2, unsigned short arg3, unsigned char arg4, bool arg5);
extern "C" void func_020804fc(void *arg0, int arg1);
extern "C" void func_020813ec(void *arg0, int arg1);

#if defined(jpn)
#define RG(usa, jpn) (jpn)
#define SO(off) ((off) >= 0x45c ? (off) - 0x1d8 : (off) - 0x118)
#else
#define RG(usa, jpn) (usa)
#define SO(off) (off)
#endif

// USA: func_ov003_0215fce8
extern "C" ARM int func_ov003_0215fce8(unsigned char *arg0, int arg1) {
    if (arg0[SO(0x4c0)] == 0 && func_ov017_021959b4() != 0) {
        unsigned char var0 = arg0[SO(0x4a3)];
        if ((var0 == 0xb && arg0[SO(0x4a4)] == 0x11) || (var0 == 6 && arg0[SO(0x4a4)] == 0)) {
            void *var1 = func_020d6c00();
            int *var2  = func_020936f8();
            func_020466e4((unsigned int *) var1, 0x20);
            unsigned char *var3 = (unsigned char*)GetGameResources();
            void *var4          = func_0202ae18();
            void *var5           = func_0202ae24();
            SetFlags00((GameResources*)var3, 2);
            func_0202b0f4(var4);
            func_ov017_02195748(var3);
            func_ov017_02192594(var3);
            func_020939fc((unsigned char *) var2);
            func_0205e854((Struct_0205e854 *) var5);
            ClearFlags00((GameResources*)var3, 0x40);
            var3[RG(0x42e3, 0x40c3)]               = 0;
            var3[RG(0x42e2, 0x40c2)]               = 0;
            *(short *) (arg0 + SO(0x484)) = 0x37;
            arg0[SO(0x4a5)]                      = 0;
            arg0[SO(0x4a4)]                      = 5;
            arg0[SO(0x4a3)]                      = 0xb;
            *(unsigned int *) (arg0 + SO(0x464)) = (*(unsigned int *) (arg0 + SO(0x464)) & ~2u) | 4u;
        } else {
            arg0[SO(0x4c0)] = 1;
            arg0[SO(0x4bf)] = 1;
        }
    }

    if (!(*(unsigned int *) (arg0 + SO(0x464)) & 0x2000000) && arg0[SO(0x4bf)] != 0) {
        short *var6 = *(short **) (arg0 + SO(0x470));
        if (var6 != 0) *var6 = -1;
        *(int *) (arg0 + SO(0x470)) = 0;
        func_02043204((char *) func_020421a0());
        *(short *) (arg0 + SO(0x486)) = -1;
        *(short *) (arg0 + SO(0x484)) = *(short *) (arg0 + SO(0x486));
        arg0[SO(0x4a5)]                      = 0;
        struct Struct_020e28dc *var7       = *(struct Struct_020e28dc **) (arg0 + SO(0x390));
        if (var7 != 0 && func_020e28dc(var7) != 0) {
            func_020e25e8(*(struct Struct_020e25e8 **) (arg0 + SO(0x390)));
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
