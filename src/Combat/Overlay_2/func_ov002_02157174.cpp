#include "Resource/ActionDataTables.h"
#include "GameState/GameState.h"
#include <globaldefs.h>

struct Struct_020839dc;
struct Struct_0209a9dc_2;

struct Struct_ov002_02157174 {
    int f0;
    int f4;
    unsigned int pad8 : 10;
    unsigned int flag8 : 2;
    unsigned int unknown_9_4_ : 20;
    int fc;
    int f10;
    int f14;
    unsigned int pad18 : 12;
    unsigned int unknown_19_4_ : 4;
    unsigned int rest18 : 16;
};

struct Struct_ov002_02157174_2 {
    int f0;
    int f4;
    unsigned short h8;
};

extern "C" int func_020839dc(struct Struct_020839dc *s, unsigned char *out, int max);
extern "C" void *__clear(void *dst, int count);
extern "C" int func_0209acdc(Struct_0209a9dc_2 *holder, unsigned char *bits, unsigned int count, unsigned short *out);
extern "C" Struct_ov002_02157174 *func_02079e2c(char *p, int key);
extern "C" void *memset(void *dst, int value, unsigned int length);
extern "C" int func_0209ab7c(void *holder, void *member, unsigned char *bits);
extern "C" int func_02083b00(unsigned char *obj, int index);
extern "C" Struct_ov002_02157174_2 *func_0209a594(void *p, int id);
extern "C" void *func_02053c6c(unsigned char *member);

// USA: func_ov002_02157174
extern "C" ARM void func_ov002_02157174(char *self, int combatantId) {
#if defined(jpn)
    enum { regionalOffset0 = 0x22d0, regionalOffset1 = 0x2350, regionalOffset2 = 0x2d0, regionalOffset3 = 0x27c, regionalOffset4 = 0x274, regionalOffset5 = 0x2000, regionalOffset6 = 0x144, Enum_ov002_02157174_2384 = 0x8b8 };
#else
    enum { regionalOffset0 = 0x24a0, regionalOffset1 = 0x2520, regionalOffset2 = 0x4a0, regionalOffset3 = 0x44, regionalOffset4 = 0x3c, regionalOffset5 = 0x2400, regionalOffset6 = 0x150, Enum_ov002_02157174_2384 = 0x950 };
#endif
    unsigned char bits[0x42];
    short ids[0x42];
    unsigned char i;
    Struct_ov002_02157174 **out;
    unsigned char *member;
    unsigned char *pm;
    int n;
    int count;
    ActionDataTables* table;
    int j;
    int k;
    unsigned short b;
    for (i = 0; i < 0x20; i++) {
        *(int *) (self + i * 4 + regionalOffset0) = 0;
    }
    *(unsigned char *) (self + regionalOffset1) = 0;
    out                                = (Struct_ov002_02157174 **) (self + regionalOffset2 + 0x2000);
    member                             = (unsigned char *) func_0200ff1c(GameState::GetInstance(), combatantId);
    if (member == 0) {
        return;
    }
    pm = (unsigned char *) func_02053c6c(member);
    if (pm == 0) {
        return;
    }
    n = func_020839dc((struct Struct_020839dc *) pm, bits, 0x42);
    __clear(ids, 0x84);
    n     = func_0209acdc((Struct_0209a9dc_2 *) (self + regionalOffset3 + regionalOffset5), bits, n, (unsigned short *) ids);
    count = 0;
    table = func_020797dc();
    for (j = 0; j < n; j++) {
        Struct_ov002_02157174 *e = func_02079e2c((char*)table, ids[j]);
        if (e != 0 && bits[j] == 0x3c) {
            if (e->flag8 & 1) {
                out[count] = e;
                count++;
            }
        }
    }
    if (*(int *) (*(char **) (member + regionalOffset6) + Enum_ov002_02157174_2384) == 0) {
        memset(bits, 0, 0x42);
        n = func_020839dc((struct Struct_020839dc *) pm, bits, 0x42);
    } else {
        memset(bits, 0, 0x42);
        n = func_0209ab7c(self + regionalOffset3 + regionalOffset5, member, bits);
    }
    memset(ids, 0, 0x84);
    n = func_0209acdc((Struct_0209a9dc_2 *) (self + regionalOffset3 + regionalOffset5), bits, n, (unsigned short *) ids);
    for (k = 0; k < n; k++) {
        Struct_ov002_02157174 *e = func_02079e2c((char*)table, ids[k]);
        if (e != 0 && bits[k] != 0x3c) {
            if (e->flag8 & 1) {
                out[count] = e;
                count++;
            }
        }
    }
    for (b = 0; b < 0x11f; b++) {
        if (func_02083b00(pm, b)) {
            Struct_ov002_02157174_2 *s = func_0209a594(self + regionalOffset4 + regionalOffset5, b);
            if (s != 0 && s->h8 != 0) {
                Struct_ov002_02157174 *e = func_02079e2c((char*)table, (short) s->h8);
                if (e != 0 && e->unknown_19_4_ == 1) {
                    if (e->flag8 & 1) {
                        out[count] = e;
                        count++;
                    }
                }
            }
        }
    }
    *(unsigned char *) (self + regionalOffset1) = count;
}
