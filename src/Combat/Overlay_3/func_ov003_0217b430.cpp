#include "GameState/GameState.h"
#include <globaldefs.h>
#include "Input/Input.h"

#if defined(jpn)
#define REGIONAL_OFFSET(jp, us) jp
#else
#define REGIONAL_OFFSET(jp, us) us
#endif

struct Struct_0207fdcc_2;
struct Struct_0207fdf0_2;
struct SePlayer;
struct Struct_02081f20_2;
struct ItemTable;
struct Obj02179e18;
struct Struct_ov003_02178910;

extern "C" void *GameState_GetParty(GameState *gs);

extern "C" int func_ov003_02179f34(char *obj);
extern "C" short func_02080468(void *obj, int id);
extern "C" int func_ov003_02175f20(void *obj);
extern "C" void func_ov003_02177dd4(void *obj);
extern "C" void func_ov003_021769ec(void *obj);
extern "C" void func_02081ea4(struct Struct_0207fdcc_2 *obj, int id, int value);
extern "C" void func_02080c68(void *obj, int id, int value);
extern "C" void func_0208203c(struct Struct_02081f20_2 *obj);
extern "C" void func_ov003_021748c4(unsigned char *self);
extern "C" void func_ov003_0217a14c(void *p);
extern "C" void func_ov023_021dcae0(struct Struct_ov003_02178910 *obj, int val);
extern "C" int func_ov003_021765b4(void *self);
extern "C" void SePlayer_Play(struct SePlayer *obj, int a, int b);
struct Element020de650 {
    char pad[8];
    unsigned int word;
};
extern "C" struct Element020de650 *ItemTable_Find(struct ItemTable *c, int key);
extern "C" void func_0207fdf0(struct Struct_0207fdf0_2 *obj, int key);
extern "C" int func_ov003_02179da8(void *obj, int flag);
extern "C" int func_ov003_021766e8(void *self);
extern "C" void func_ov003_02177208(char *obj);
extern "C" void func_ov003_0217726c(char *obj);
extern "C" int func_ov003_02178218(void *self);
extern "C" int func_02081f20(void *obj, int scaleCount);
extern "C" unsigned short func_ov003_0217b200(void **obj);
extern "C" int func_0207c7a0(void *map, int value, int key);
extern "C" unsigned int func_ov003_02179e18(struct Obj02179e18 *obj);
extern "C" int func_ov003_021782a0(struct Struct_0207fdcc_2 *obj);
extern "C" void func_0207fdcc(struct Struct_0207fdcc_2 *obj, int key);
extern "C" void func_ov003_02176468(unsigned char *self);
extern "C" int func_ov003_021764f4(unsigned char *self);
extern "C" void func_ov003_02175d78(char *obj);
extern "C" void func_ov003_02175df4(void *self);

extern struct SePlayer g_sePlayer;

static inline int inline_ov003_0217b430(struct Element020de650 *e) {
    unsigned int w = e->word;
    return (int) ((w << 18) >> 30);
}

// USA: func_ov003_0217b430
extern "C" ARM void func_ov003_0217b430(unsigned char *self) {
    GameState *battle = GameState::GetInstance();
    char *battleSum   = (char *) GameState_GetParty(battle);
    void *var2     = *(void **) (self + REGIONAL_OFFSET(0x818, 0x89c));
    int state         = *(unsigned char *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x3f);

    if (state == 0) {
        int cnt               = func_ov003_02179f34((char *) self);
        unsigned short *flags = (unsigned short *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x46);
        *flags                = (unsigned short) (*flags & ~0x400);
        if (cnt > 5) {
            *flags = (unsigned short) (*flags | 0x400);
        }
        *(short *) (self + 0xf00 + REGIONAL_OFFSET(0x7a, 0xfe)) = 0x1e;
        if (*(short *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0xe) < 0) {
            *(short *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0xe) = func_02080468(var2, *(short *) (self + 0xf00 + REGIONAL_OFFSET(0x7a, 0xfe)));
        }
        *(short *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x3a)         = (short) func_ov003_02175f20(self);
        *(unsigned char *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x3c) = 1;
        func_ov003_02177dd4(self);
        func_ov003_021769ec(self);
        func_02081ea4((struct Struct_0207fdcc_2 *) var2, *(short *) (self + 0xf00 + REGIONAL_OFFSET(0x7a, 0xfe)), 0);
        func_02080c68(var2, *(short *) (self + 0xf00 + REGIONAL_OFFSET(0x7a, 0xfe)), 0);
        func_0208203c((struct Struct_02081f20_2 *) (self + REGIONAL_OFFSET(0x808, 0x88c)));
        *(void **) (self + REGIONAL_OFFSET(0xf74, 0xff8))                 = 0;
        *(unsigned char *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x3f) = 1;
        func_ov003_021748c4(self);
        return;
    }

    if (state == 1) {
        short saved               = *(short *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x3a);
        *(void **) (self + REGIONAL_OFFSET(0xf74, 0xff8)) = self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0xe;
        func_ov003_0217a14c(self);
        func_ov023_021dcae0((struct Struct_ov003_02178910 *) (self + 0x3c), *(short *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x3a));
        if (func_ov003_021765b4(self) != 0 && saved == *(short *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x3a)) {
            SePlayer_Play(&g_sePlayer, 1, 0);
            func_0208203c((struct Struct_02081f20_2 *) (self + REGIONAL_OFFSET(0x808, 0x88c)));
            *(void **) (self + REGIONAL_OFFSET(0xf74, 0xff8)) = 0;
            *(void **) (self + 8) =
                ItemTable_Find((struct ItemTable *) (self + REGIONAL_OFFSET(0x7f0, 0x874)), *(short *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x3a));
            if (*(void **) (self + 8) == 0) return;
            *(short *) (self + 0xf00 + REGIONAL_OFFSET(0x78, 0xfc)) = *(short *) (self + 0xf00 + REGIONAL_OFFSET(0x7a, 0xfe));
            func_02080c68(var2, *(short *) (self + 0xf00 + REGIONAL_OFFSET(0x7a, 0xfe)), 1);
            func_02080c68(var2, 4, 1);
            func_02080c68(var2, 5, 1);
            func_02080c68(var2, 6, 1);
            func_02080c68(var2, 7, 1);
            *(unsigned char *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x3f) = 2;
            if (inline_ov003_0217b430(*(struct Element020de650 **) (self + 8)) == 0) {
                func_0207fdf0((struct Struct_0207fdf0_2 *) var2, 0);
                *(short *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x36)          = 0x12;
                *(unsigned char *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x3f)  = 0;
                unsigned short f                           = *(unsigned short *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x46);
#if defined(jpn)
                f = (unsigned short) (f | 0x20);
#else
                f                                          = (unsigned short) ((f | 0x20) & ~0x2000);
#endif
                *(unsigned short *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x46) = f;
                return;
            }
            int var8 = func_ov003_02179da8(*(void **) (self + 8), 1);
            switch (var8) {
                case 1:
                    func_0207fdf0((struct Struct_0207fdf0_2 *) var2, 0);
                    *(short *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x36)         = 0xd;
                    *(unsigned char *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x3f) = 6;
                    *(unsigned short *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x46) =
                        (unsigned short) (*(unsigned short *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x46) | 0x2000);
                    if (inline_ov003_0217b430(*(struct Element020de650 **) (self + 8)) != 2) return;
                    *(short *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x36)         = 0x11;
                    *(unsigned char *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x3f) = 4;
                    return;
                case 2:
                    func_0207fdf0((struct Struct_0207fdf0_2 *) var2, 0);
                    *(short *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x36)         = 0x1c;
                    *(unsigned char *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x3e) = 1;
                    *(unsigned char *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x3f) = 0;
                    *(unsigned short *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x46) =
                        (unsigned short) (*(unsigned short *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x46) | 0x2000);
                    return;
                default: return;
            }
        }
        if (func_ov003_021766e8(self) == 0) return;
        func_0208203c((struct Struct_02081f20_2 *) (self + REGIONAL_OFFSET(0x808, 0x88c)));
        *(void **) (self + REGIONAL_OFFSET(0xf74, 0xff8)) = 0;
        func_0207fdf0((struct Struct_0207fdf0_2 *) var2, 0);
        *(unsigned char *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x3e)  = 7;
        *(unsigned char *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x3f)  = 1;
        *(unsigned short *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x46) = (unsigned short) (*(unsigned short *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x46) | 0x2000);
        return;
    }

    if (state == 2) {
        func_ov003_02177208((char *) self);
        func_ov003_0217726c((char *) self);
        func_0208203c((struct Struct_02081f20_2 *) (self + REGIONAL_OFFSET(0x808, 0x88c)));
        *(unsigned char *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x3f) = 3;
        *(unsigned char *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x4a) = 0;
        return;
    }

    if (state == 3) {
        int delta             = 0;
        unsigned char counter = *(unsigned char *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x4a);
        if (counter < 5) {
            *(unsigned char *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x4a) = (unsigned char) (counter + 1);
        } else {
            delta = func_ov003_02178218(self);
            if (delta != 0) {
                *(unsigned char *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x4a) = 0;
            }
        }
        GameState *b2 = GameState::GetInstance();
        int ticks     = (int) b2->GetTickCount();
        int ratio     = func_02081f20(self + REGIONAL_OFFSET(0x808, 0x88c), ticks);
        if ((unsigned short) (ratio + 0xffff) <= 1) {
            unsigned short v = func_ov003_0217b200((void **) (self + REGIONAL_OFFSET(0x808, 0x88c)));
            if (v == 0x40)
                delta = 1;
            else if (v == 0x80)
                delta = -1;
            else if (v == 0x20)
                delta = 0x63;
            else if (v == 0x10)
                delta = ~0x62;
        }
        if (delta != 0) {
            int var15          = *(unsigned char *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x3c) + delta;
            int var16           = func_0207c7a0(battleSum + 0x1d4, *(short *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x3a), 9);
            unsigned int var17 = func_ov003_02179e18(*(struct Obj02179e18 **) (self + 8));
            if ((int) var17 < var16) var16 = (int) var17;
            if (var16 < var15) var15 = var16;
            if (var15 <= 1) var15 = 1;
            *(unsigned char *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x4b) = (*(unsigned char *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x3c) < var15) ? 1 : 0;
            *(unsigned char *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x4c) = (var15 < *(unsigned char *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x3c)) ? 1 : 0;
            *(unsigned char *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x3c) = (unsigned char) var15;
            func_ov003_02177208((char *) self);
            func_ov003_0217726c((char *) self);
        }
        int hit = func_ov003_021782a0((struct Struct_0207fdcc_2 *) self);
        if (g_keyManager.TestKeysPressed(0x401) != 0 || hit == 1) {
            SePlayer_Play(&g_sePlayer, 1, 0);
            func_0207fdf0((struct Struct_0207fdf0_2 *) var2, 0);
            *(short *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x36) = 0xd;
            if (*(unsigned char *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x3c) > 1) {
                *(short *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x36) = 0x20;
            }
            *(unsigned char *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x3f) = 6;
            *(unsigned short *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x46) =
                (unsigned short) (*(unsigned short *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x46) | 0x2000);
            func_0208203c((struct Struct_02081f20_2 *) (self + REGIONAL_OFFSET(0x808, 0x88c)));
            if (inline_ov003_0217b430(*(struct Element020de650 **) (self + 8)) != 2) return;
            *(short *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x36)         = 0x11;
            *(unsigned char *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x3f) = 4;
            return;
        }
        if (g_keyManager.TestKeysPressed(2) != 0 || hit == -1) {
            func_0207fdcc((struct Struct_0207fdcc_2 *) var2, 9);
            func_0207fdcc((struct Struct_0207fdcc_2 *) var2, 0xa);
            func_0208203c((struct Struct_02081f20_2 *) (self + REGIONAL_OFFSET(0x808, 0x88c)));
            *(unsigned char *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x3f) = 0;
        }
        return;
    }

    if (state == 4) {
        func_ov003_02176468(self);
        *(unsigned char *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x3f) = 5;
        return;
    }

    if (state == 5) {
        int res = func_ov003_021764f4(self);
        if (res == -1) goto fail5;
        if (res != 1) return;
        *(short *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x36)         = 0x10;
        *(unsigned char *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x3f) = 6;
        return;
    fail5:
        *(short *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x36)          = 0x30;
        *(unsigned char *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x3f)  = 0;
        *(unsigned short *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x46) = (unsigned short) (*(unsigned short *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x46) | 0x20);
        return;
    }

    if (state == 6) {
        func_ov003_02176468(self);
        *(unsigned char *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x3f) = 7;
        return;
    }

    if (state == 7) {
        int res = func_ov003_021764f4(self);
        if (res == -1) goto fail7;
        if (res != 1) return;
        func_ov003_02175d78((char *) self);
        func_ov003_02175df4(self);
        *(short *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x36)          = 0xe;
        *(unsigned char *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x3e)  = 7;
        *(unsigned char *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x3f)  = 1;
        *(unsigned short *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x46) = (unsigned short) (*(unsigned short *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x46) | 0x20);
        return;
    fail7:
        *(short *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x36)          = 0x30;
        *(unsigned char *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x3e)  = 8;
        *(unsigned char *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x3f)  = 0;
        *(unsigned short *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x46) = (unsigned short) (*(unsigned short *) (self + REGIONAL_OFFSET(0xf7c, 0x1000) + 0x46) | 0x20);
        return;
    }
}
