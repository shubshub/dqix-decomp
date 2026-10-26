#include "Resource/ActionDataTables.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "NitroSDK/Matrix.h"
#include <globaldefs.h>
#include "Input/Input.h"


struct Struct0205de24;
struct Struct_0205c570;
struct Obj_0205da38;
struct SePlayer;
struct Struct_0205d81c;
struct Struct_0205dee8;
struct Struct_020a83b0;
struct Struct_02048350_2;
struct Struct_ov002_02165b44 {
    char *name;
    int unk4;
    unsigned int lo8 : 8;
    unsigned int b8 : 2;
    unsigned int b10 : 2;
    unsigned int rest : 20;
};
struct TailList020469b4;
struct TailNode020469b4;
extern "C" void func_0205de24(struct Struct0205de24 *obj, unsigned char keyLow, unsigned char keyHigh);
extern "C" int Window_GetSelectedIndex(struct Struct_0205c570 *s);
extern "C" int Window_IsSelectionTouched(struct Obj_0205da38* obj, int key);
extern "C" void SePlayer_Play(struct SePlayer *o, int a, int b);
extern "C" int func_ov002_02161b48(char *base, int a);
extern "C" void Window_SetPanePalette(struct Struct_0205d81c *s, int a, int b);
extern "C" void func_0205dee8(struct Struct_0205dee8 *o, int v);
extern "C" void func_ov002_02156ff0(unsigned char *self, int v);
extern "C" int GameState_GetLeaderIndex(GameState *gs);
extern "C" GameObject *func_0200ff94(GameState *gs, int id);
extern "C" int Scenario_TestFlag(int unused, unsigned char *arr, int index);
extern "C" char *func_020a83b0(struct Struct_020a83b0 *l, int id);
extern "C" char *func_02079e2c(char *t, int id);
extern "C" void func_02048350(struct Struct_02048350_2 *o, int n);
extern "C" int LinkSession_IsActive(int *p);
extern "C" void *GameState_GetZoneTransition(GameState *state);
extern "C" void VectorizedMemset(void *dst, int value, unsigned int length);
extern "C" void *GameState_SetZoneTransition(void *obj, const void *src);
extern "C" void func_ov017_021acd30(char *g, unsigned char a, unsigned char b, unsigned char c);
extern "C" void FieldTask_InitEnterZone(unsigned char *p, int v);
extern "C" void func_020469b4(struct TailList020469b4 *l, struct TailNode020469b4 *n);
extern "C" void func_ov002_02161cf0(char *base);
extern "C" void func_ov002_0215f170(char *base);
extern "C" void func_ov002_02161b98(char *base);
extern "C" void func_ov002_0215a7b4(char *base, int a, short b, int c, int d);
extern "C" void func_ov002_0215b9a4(char *self, unsigned char key, int flag);
extern "C" char *Scenario_GetInstance(void);
extern "C" char *Zone3D_GetInstance(void);
extern "C" int *LinkSession_GetInstance(void);
extern "C" int LinkSession_IsHostOrSolo(int *p);
extern "C" void func_ov023_021dca88(char *obj);
extern "C" void func_ov017_021c9e00(int id, int a, int b, int c);
extern "C" void func_ov017_021d1a18(int a, int b, int c, int d);
extern "C" char g_sePlayer[];

// USA: func_ov002_02165b44
extern "C" ARM void func_ov002_02165b44(char *base) {
#if defined(jpn)
    int state = *(int *) (base + 0x1a88);
    if (state == 0) {
        *(short *) (base + 0x1ac4) = 0;
        func_0205de24((struct Struct0205de24 *) (base + 0xe20), 0, 2);
        func_ov002_02161cf0(base);
        func_ov002_0215f170(base);
        *(int *) (base + 0x1a88) += 1;
    } else if (state == 1) {
        *(unsigned int *) (base + 0x22ac) |= 4;
        func_ov002_02161b98(base);
        *(short *) (base + 0x1ac4) = Window_GetSelectedIndex((struct Struct_0205c570 *) (base + 0xe20));
        int var1                            = g_keyManager.TestKeysPressed(0x601);
        int tb = Window_IsSelectionTouched((struct Obj_0205da38*)(base + 0xe20), 0x14);
        if ((var1 | tb) ? 1 : 0) {
            GameState *gs = GameState::GetInstance();
            int id        = *(signed char *) (base + 0x1ae8);
            if (id == 4) id = GameState_GetLeaderIndex(gs);
            GameObject *m = func_0200ff94(gs, id);
            if (m == NULL) return;
            *(unsigned char *) (base + 0xed8) = *(int *) (base + 0x1a80);
            *(unsigned int *) (base + 0x22ac) &= ~4;
            if (**(int **) ((char *) m + 0x130) & 1) {
                *(short *) (base + 0x1af0) = -1;
                *(short *) (base + 0x1af2) = -1;
                *(int *) (base + 0x1a80)  = 0x12;
                return;
            }
            *(int *) (base + 0x1a88) = 0;
            SePlayer_Play((struct SePlayer *) g_sePlayer, 1, 0);
            int save    = (int) Scenario_GetInstance();
            char *world = Zone3D_GetInstance();
            int kind    = 0;
            if (!Scenario_TestFlag(save, (unsigned char *) ((char *) save + 0x8c), 0x113a)) {
                char *p = *(char **) (world + 8);
                if (p != NULL) kind = (unsigned int) (*(unsigned char *) (p + 0xe) << 30) >> 30;
            }
            *(short *) (base + 0x1af0) = 0x232d;
            if (kind == 2) {
                char *e = func_020a83b0(*(struct Struct_020a83b0 **) (base + 0x22a4),
                                                    *(short *) (base + 0x1ac4));
                if (e != NULL) {
                    int *rec                          = LinkSession_GetInstance();
                    *(short *) (base + 0x1af2) = -1;
                    *(int *) (base + 0x1a80)  = 0x29;
                    *(int *) (base + 0x1a84)  = 0x2e;
                    if (*(short *) (base + 0x1aea) == 0x5603) {
                        *(short *) (base + 0x1af0)          = 0x7972;
                        *(short *) (base + 0x1af2)          = -1;
                        *(short *) (base + 0x22b8)          = -1;
                        *(unsigned char *) (base + 0x22ba) = 0;
                        if (*(unsigned int *) (base + 0x22ac) & 1) func_ov023_021dca88(base + 0x38);
                        func_ov002_0215a7b4(base, *(signed char *) (base + 0x1ae8), *(short *) (base + 0x1aea),
                                            *(short *) (base + 0x1ab0), 0);
                    } else {
                        SePlayer_Play((struct SePlayer *) g_sePlayer, 0x64, 0);
                        char *t = func_02079e2c((char*)func_020797dc(), 0xca);
                        func_02048350(
                            (struct Struct_02048350_2 *) func_0200ff94(gs, *(signed char *) (base + 0x1ae8)),
                            ((struct Struct_ov002_02165b44 *) t)->lo8);
                        if (LinkSession_IsActive(rec)) func_ov017_021c9e00(*(signed char *) (base + 0x1ae8), 0, 0, 1);
                    }
                    unsigned char *q = (unsigned char *) GameState_GetZoneTransition(gs);
                    VectorizedMemset(q, 0, 0x70);
                    q[4]                       = 1;
                    q[8]                       = 1;
                    q[9]                       = 1;
                    *(signed char *) (q + 0xb) = -1;
                    *(int *) (q + 0x20)        = -1;
                    *(int *) (q + 0x24)        = -1;
                    *(int *) (q + 0x28)        = -1;
                    *(int *) (q + 0x2c)        = -1;
                    *(short *) (q + 0x1e)      = -1;
                    q[0xc]                     = 0;
                    *(short *) (q + 0x6c)      = -1;
                    q[2]                       = 0;
                    q[4]                       = 0;
                    q[5]                       = 1;
                    *(unsigned short *) q      = *(unsigned short *) (e + 8);
                    *(Vector3i *) (q + 0x10)   = *(Vector3i *) (e + 0xc);
                    *(short *) (q + 0x1c)      = *(short *) (e + 0xa);
                    q[7]                       = 1;
                    q[0x63]                    = 0;
                    GameState_SetZoneTransition(gs, q);
                    if (LinkSession_IsHostOrSolo(rec) && Scenario_TestFlag(save, (unsigned char *) ((char *) save + 0x8c), 0x2b)) {
                        *(unsigned short *) (world + 0x27c6) = *(unsigned short *) (e + 0x1a);
                        *(unsigned short *) (world + 0x27c4) = *(unsigned short *) (e + 0x1c);
                        Vector3i *pos                               = (Vector3i *) (world + 0x27b4);
                        Vector3i v                                  = *pos;
                        v.x                                         = *(int *) (e + 0x20);
                        v.z                                         = *(int *) (e + 0x24);
                        *pos                                        = v;
                        func_ov017_021d1a18(*(short *) (e + 0x1a), *(short *) (e + 0x1c), 0, 0);
                    }
                    char *g = (char *) GetGameResources();
                    func_ov017_021acd30(g, 0, 0, 0);
                    struct TailList020469b4 *var17;
                    unsigned char *node = *(unsigned char **) (g + 0x34fc);
                    var17                  = *(struct TailList020469b4 **) (g + 0x34ec);
                    FieldTask_InitEnterZone(node, 0);
                    func_020469b4(var17, (struct TailNode020469b4 *) node);
                    return;
                }
                kind = 0;
            } else if (kind == 1) {
                *(short *) (base + 0x1af2) = -1;
                *(int *) (base + 0x1a80)  = 0x29;
                *(int *) (base + 0x1a84)  = 0x2e;
                if (*(short *) (base + 0x1aea) == 0x5603) {
                    *(short *) (base + 0x1af0)          = 0x7972;
                    *(short *) (base + 0x1af2)          = -1;
                    *(short *) (base + 0x22b8)          = -1;
                    *(unsigned char *) (base + 0x22ba) = 0;
                    if (*(unsigned int *) (base + 0x22ac) & 1) func_ov023_021dca88(base + 0x38);
                } else {
                    SePlayer_Play((struct SePlayer *) g_sePlayer, 0x64, 0);
                }
                func_ov017_021acd30((char *) GetGameResources(), 0, 0, 1);
                return;
            }
            if (kind == 0) {
                if (*(short *) (base + 0x1aea) == 0x5603) {
                    *(short *) (base + 0x1ac4)          = -1;
                    *(short *) (base + 0x1af0)          = 0x7936;
                    *(short *) (base + 0x1af2)          = -1;
                    *(short *) (base + 0x22b8)          = 0x7919;
                    *(unsigned char *) (base + 0x22ba) = 1;
                    *(int *) (base + 0x1a80)           = 0x29;
                    *(int *) (base + 0x1a84)           = 5;
                } else {
                    *(short *) (base + 0x22b8)          = 0x2338;
                    *(unsigned char *) (base + 0x22ba) = 1;
                    SePlayer_Play((struct SePlayer *) g_sePlayer, 0x64, 0);
                    *(int *) (base + 0x1a80) = 0x29;
                    *(int *) (base + 0x1a84) = 0x12;
                }
            }
        } else if (func_ov002_02161b48(base, 1)) {
            *(short *) (base + 0x1ac4) = -1;
            if (*(short *) (base + 0x1aea) == 0x5603) {
                *(short *) (base + 0x1aea) = -1;
                func_ov002_02156ff0((unsigned char *) base, 5);
            } else {
                *(short *) (base + 0x1aee) = -1;
                func_ov002_02156ff0((unsigned char *) base, 0x14);
                *(int *) (base + 0x1a80) = 0x12;
                func_0205dee8((struct Struct_0205dee8 *) (base + 0xe20), 0x12);
                Window_SetPanePalette((struct Struct_0205d81c *) (base + 0xe20), 0x12, 0);
                func_ov002_02161cf0(base);
                func_ov002_0215b9a4(base, *(int *) (base + 0x1a80) & 0xff, 0);
                *(int *) (base + 0x1a88) = 1;
            }
        }
    }
#else
    int state = *(int *) (base + 0x1000 + 0xbc0);
    if (state == 0) {
        *(short *) (base + 0x1b00 + 0xfc) = 0;
        func_0205de24((struct Struct0205de24 *) (base + 0x2c8 + 0xc00), 0, 2);
        func_ov002_02161cf0(base);
        func_ov002_0215f170(base);
        *(int *) (base + 0x1000 + 0xbc0) += 1;
    } else if (state == 1) {
        *(unsigned int *) (base + 0x2000 + 0x47c) |= 4;
        func_ov002_02161b98(base);
        *(short *) (base + 0x1b00 + 0xfc) = Window_GetSelectedIndex((struct Struct_0205c570 *) (base + 0x2c8 + 0xc00));
        int var20                            = g_keyManager.TestKeysPressed(0x601);
        int tb = Window_IsSelectionTouched((struct Obj_0205da38*)(base + 0x2c8 + 0xc00), 0x14);
        if ((var20 | tb) ? 1 : 0) {
            GameState *gs = GameState::GetInstance();
            int id        = *(signed char *) (base + 0x1c00 + 0x20);
            if (id == 4) id = GameState_GetLeaderIndex(gs);
            GameObject *m = func_0200ff94(gs, id);
            if (m == NULL) return;
            *(unsigned char *) (base + 0xf80) = *(int *) (base + 0x1000 + 0xbb8);
            *(unsigned int *) (base + 0x2000 + 0x47c) &= ~4;
            if (**(int **) ((char *) m + 0x130) & 1) {
                *(short *) (base + 0x1c00 + 0x28) = -1;
                *(short *) (base + 0x1c00 + 0x2a) = -1;
                *(int *) (base + 0x1000 + 0xbb8)  = 0x11;
                return;
            }
            *(int *) (base + 0x1000 + 0xbc0) = 0;
            SePlayer_Play((struct SePlayer *) g_sePlayer, 1, 0);
            int save    = (int) Scenario_GetInstance();
            char *world = Zone3D_GetInstance();
            int kind    = 0;
            if (!Scenario_TestFlag(save, (unsigned char *) ((char *) save + 0x8c), 0x113a)) {
                char *p = *(char **) (world + 8);
                if (p != NULL) kind = (unsigned int) (*(unsigned char *) (p + 0xe) << 30) >> 30;
            }
            *(short *) (base + 0x1c00 + 0x28) = 0x232d;
            if (kind == 2) {
                char *e = func_020a83b0(*(struct Struct_020a83b0 **) (base + 0x2000 + 0x474),
                                                    *(short *) (base + 0x1b00 + 0xfc));
                if (e != NULL) {
                    int *rec                          = LinkSession_GetInstance();
                    *(short *) (base + 0x1c00 + 0x2a) = -1;
                    *(int *) (base + 0x1000 + 0xbb8)  = 0x26;
                    *(int *) (base + 0x1000 + 0xbbc)  = 0x2b;
                    if (*(short *) (base + 0x1c00 + 0x22) == 0x5603) {
                        *(short *) (base + 0x1c00 + 0x28)          = 0x7972;
                        *(short *) (base + 0x1c00 + 0x2a)          = -1;
                        *(short *) (base + 0x2400 + 0x88)          = -1;
                        *(unsigned char *) (base + 0x2000 + 0x48a) = 0;
                        if (*(unsigned int *) (base + 0x2000 + 0x47c) & 1) func_ov023_021dca88(base + 0x50);
                        func_ov002_0215a7b4(base, *(signed char *) (base + 0x1c00 + 0x20), *(short *) (base + 0x1c00 + 0x22),
                                            *(short *) (base + 0x1b00 + 0xe8), 0);
                    } else {
                        SePlayer_Play((struct SePlayer *) g_sePlayer, 0x64, 0);
                        char *t = func_02079e2c((char*)func_020797dc(), 0xca);
                        func_02048350(
                            (struct Struct_02048350_2 *) func_0200ff94(gs, *(signed char *) (base + 0x1c00 + 0x20)),
                            ((struct Struct_ov002_02165b44 *) t)->lo8);
                        if (LinkSession_IsActive(rec)) func_ov017_021c9e00(*(signed char *) (base + 0x1c00 + 0x20), 0, 0, 1);
                    }
                    unsigned char *q = (unsigned char *) GameState_GetZoneTransition(gs);
                    VectorizedMemset(q, 0, 0x70);
                    q[4]                       = 1;
                    q[8]                       = 1;
                    q[9]                       = 1;
                    *(signed char *) (q + 0xb) = -1;
                    *(int *) (q + 0x20)        = -1;
                    *(int *) (q + 0x24)        = -1;
                    *(int *) (q + 0x28)        = -1;
                    *(int *) (q + 0x2c)        = -1;
                    *(short *) (q + 0x1e)      = -1;
                    q[0xc]                     = 0;
                    *(short *) (q + 0x6c)      = -1;
                    q[2]                       = 0;
                    q[4]                       = 0;
                    q[5]                       = 1;
                    *(unsigned short *) q      = *(unsigned short *) (e + 8);
                    *(Vector3i *) (q + 0x10)   = *(Vector3i *) (e + 0xc);
                    *(short *) (q + 0x1c)      = *(short *) (e + 0xa);
                    q[7]                       = 1;
                    q[0x63]                    = 0;
                    GameState_SetZoneTransition(gs, q);
                    if (LinkSession_IsHostOrSolo(rec) && Scenario_TestFlag(save, (unsigned char *) ((char *) save + 0x8c), 0x2b)) {
                        *(unsigned short *) (world + 0x2700 + 0x86) = *(unsigned short *) (e + 0x1a);
                        *(unsigned short *) (world + 0x2700 + 0x84) = *(unsigned short *) (e + 0x1c);
                        Vector3i *pos                               = (Vector3i *) (world + 0x374 + 0x2400);
                        Vector3i v                                  = *pos;
                        v.x                                         = *(int *) (e + 0x20);
                        v.z                                         = *(int *) (e + 0x24);
                        *pos                                        = v;
                        func_ov017_021d1a18(*(short *) (e + 0x1a), *(short *) (e + 0x1c), 0, 0);
                    }
                    char *g = (char *) GetGameResources();
                    func_ov017_021acd30(g, 0, 0, 0);
                    struct TailList020469b4 *var36;
                    unsigned char *node = *(unsigned char **) (g + 0x3000 + 0x70c);
                    var36                  = *(struct TailList020469b4 **) (g + 0x3000 + 0x6fc);
                    FieldTask_InitEnterZone(node, 0);
                    func_020469b4(var36, (struct TailNode020469b4 *) node);
                    return;
                }
                kind = 0;
            } else if (kind == 1) {
                *(short *) (base + 0x1c00 + 0x2a) = -1;
                *(int *) (base + 0x1000 + 0xbb8)  = 0x26;
                *(int *) (base + 0x1000 + 0xbbc)  = 0x2b;
                if (*(short *) (base + 0x1c00 + 0x22) == 0x5603) {
                    *(short *) (base + 0x1c00 + 0x28)          = 0x7972;
                    *(short *) (base + 0x1c00 + 0x2a)          = -1;
                    *(short *) (base + 0x2400 + 0x88)          = -1;
                    *(unsigned char *) (base + 0x2000 + 0x48a) = 0;
                    if (*(unsigned int *) (base + 0x2000 + 0x47c) & 1) func_ov023_021dca88(base + 0x50);
                } else {
                    SePlayer_Play((struct SePlayer *) g_sePlayer, 0x64, 0);
                }
                func_ov017_021acd30((char *) GetGameResources(), 0, 0, 1);
                return;
            }
            if (kind == 0) {
                if (*(short *) (base + 0x1c00 + 0x22) == 0x5603) {
                    *(short *) (base + 0x1b00 + 0xfc)          = -1;
                    *(short *) (base + 0x1c00 + 0x28)          = 0x7936;
                    *(short *) (base + 0x1c00 + 0x2a)          = -1;
                    *(short *) (base + 0x2400 + 0x88)          = 0x7919;
                    *(unsigned char *) (base + 0x2000 + 0x48a) = 1;
                    *(int *) (base + 0x1000 + 0xbb8)           = 0x26;
                    *(int *) (base + 0x1000 + 0xbbc)           = 5;
                } else {
                    *(short *) (base + 0x2400 + 0x88)          = 0x2338;
                    *(unsigned char *) (base + 0x2000 + 0x48a) = 1;
                    SePlayer_Play((struct SePlayer *) g_sePlayer, 0x64, 0);
                    *(int *) (base + 0x1000 + 0xbb8) = 0x26;
                    *(int *) (base + 0x1000 + 0xbbc) = 0x11;
                }
            }
        } else if (func_ov002_02161b48(base, 1)) {
            *(short *) (base + 0x1b00 + 0xfc) = -1;
            if (*(short *) (base + 0x1c00 + 0x22) == 0x5603) {
                *(short *) (base + 0x1c00 + 0x22) = -1;
                func_ov002_02156ff0((unsigned char *) base, 5);
            } else {
                *(short *) (base + 0x1c00 + 0x26) = -1;
                func_ov002_02156ff0((unsigned char *) base, 0x13);
                *(int *) (base + 0x1000 + 0xbb8) = 0x11;
                func_0205dee8((struct Struct_0205dee8 *) (base + 0x2c8 + 0xc00), 0x11);
                Window_SetPanePalette((struct Struct_0205d81c *) (base + 0x2c8 + 0xc00), 0x11, 0);
                func_ov002_02161cf0(base);
                func_ov002_0215b9a4(base, *(int *) (base + 0x1000 + 0xbb8) & 0xff, 0);
                *(int *) (base + 0x1000 + 0xbc0) = 1;
            }
        }
    }
#endif
}
