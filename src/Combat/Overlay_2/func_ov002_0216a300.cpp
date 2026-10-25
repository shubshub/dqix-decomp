#include "GameState/GameState.h"
#include <globaldefs.h>
#include "Input/Input.h"

#if defined(jpn)
#define RG(u, j) (j)
#define K(u, j) (j)
#else
#define RG(u, j) (u)
#define K(u, j) (u)
#endif

struct Struct_0205de24_2;
struct Struct_0205c570;
struct SePlayer;
struct Struct_0205def8;
struct Struct_0205d81c;
struct Struct_0205dee8;
struct Struct_020e280c;
struct Struct_020676e0;
struct Struct_020e25e8;
struct Struct_0205d6a0;
struct Struct_0205bcdc;
struct ItemTable;
int MessageSystem_GetInstance(void);
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
extern "C" void func_ov002_02161cf0(char *base);
extern "C" void func_ov002_02160fb4(char *base);
void SePlayer_Play(struct SePlayer *o, int a, int b);
void SetElementFlag0x20ByKey0205def8(struct Struct_0205def8 *s, int clear, int key);
char *GetField4Ptr020e1b24(void *p);
void ResetAndReposition020e280c(struct Obj020e280c *self, void *b);
int Window_GetSelectedIndex(struct Struct_0205c570 *s);
char *GetFieldIfFlag4_020100f8(char *obj);
int GetIntAt0x23c(struct IntField0x23c_020a27c4 *obj);
int GetField0x15UnlessInactive_020e2918(signed char *param);
int GetSignedByteAt0x14_020e2910(signed char *p);
void ResetSelectionState020e25e8(struct Obj020e25e8 *obj);
char *ItemTable_Find(struct ItemTable *c, int key);
extern "C" void func_ov002_0215b9a4(char *self, unsigned char key, int flag);
void Window_ClosePane(struct Entry_0205d6a0 *a, int flag);
extern "C" void func_ov017_0219577c(int a, int b, int c);
extern "C" int func_020dc920(int a, int b, int c, int d);
extern "C" void func_ov002_0216bfd4(char *self, int a);
void EnqueueEventTag170_021d0198(int a, int b, int c, int d);
int CheckStateAndGetCode0215753c(unsigned char *p);
extern "C" void func_ov002_02156e90(void *base);
void Window_SetPanePalette(struct Struct_0205d81c *s, int a, int b);
void MessageSystem_Reset(char *obj);
void SetFieldB0AndUpdate0205dee8(struct Obj0205dee8 *o, int v);
void GridCursor_SelectIfValid(struct Struct_0205bcdc *s, int index);
extern "C" void GridCursor_SetSelectedIndex(void *s, int n);
int IsFlag0x2Active020e2984(struct Outer020e28dc* window);
extern "C" char g_sePlayer[];
extern "C" unsigned char data_ov002_0216d3ac;

struct Struct_ov002_0216a300 {
    char unknown_0_[0x3f];
    unsigned char unknown_3f_0_ : 1;
};
#define LST(base) ((base) + RG(0x2c8 + 0xc00, 0xe20))

#define CONFIRM_0216A300() \
    do { \
        char *e = ItemTable_Find((struct ItemTable *) (base + RG(0x3ec + 0x400, 0x750)), \
                                                                    *(short *) (base + RG(0x1c00 + 0x22, 0x1a00 + 0xea))); \
        if (e != NULL && *(short *) (e + 0x18) == 0x5612) { \
            func_ov002_0215b9a4(base, *(int *) (base + 0x1000 + RG(0xbb8, 0xa80)), 1); \
            Window_ClosePane((struct Entry_0205d6a0 *) LST(base), 0); \
            *(short *) (base + RG(0x1c00 + 0x28, 0x1a00 + 0xf0))          = 0x797e; \
            *(short *) (base + RG(0x1c00 + 0x2a, 0x1a00 + 0xf2))          = -1; \
            *(int *) (base + 0x1000 + RG(0xbb8, 0xa80))           = K(0x26, 0x29); \
            *(int *) (base + 0x1000 + RG(0xbbc, 0xa84))           = 5; \
            *(int *) (base + 0x1000 + RG(0xbc0, 0xa88))           = 0; \
            *(unsigned char *) (base + 0x1000 + RG(0xc2e, 0xaf6)) = 0; \
            return; \
        } \
        if (*(unsigned char *) (base + 0x1000 + RG(0xc30, 0xaf8)) != 0) { \
            func_ov002_0215b9a4(base, *(int *) (base + 0x1000 + RG(0xbb8, 0xa80)), 1); \
            Window_ClosePane((struct Entry_0205d6a0 *) LST(base), 0); \
            switch (*(unsigned char *) (base + 0x1000 + RG(0xc79, 0xb3d))) { \
                case 0: func_ov002_0216bfd4(base, 4); return; \
                case 3: func_ov002_0216bfd4(base, 2); return; \
            } \
            return; \
        } \
        func_ov002_02156e90(base); \
        MessageSystem_Reset(g); \
        if (*(unsigned char *) (base + 0x2000 + RG(0x521, 0x351)) != 0) { \
            *(int *) (base + 0x1000 + RG(0xbb8, 0xa80)) = *(int *) (base + 0x1000 + RG(0xbbc, 0xa84)); \
            SetFieldB0AndUpdate0205dee8((struct Obj0205dee8 *) LST(base), 4); \
            Window_SetPanePalette((struct Struct_0205d81c *) LST(base), 4, 0); \
            func_ov002_02161cf0(base); \
            *(unsigned char *) (base + 0x2000 + RG(0x521, 0x351)) = 0; \
        } else if ((*(short *) (base + RG(0x1b00 + 0xf0, 0x1a00 + 0xb8)) >= 0 || *(short *) (base + RG(0x1b00 + 0xe8, 0x1a00 + 0xb0)) >= 0 || \
                    *(short *) (base + RG(0x1c00 + 0xa, 0x1a00 + 0xd2)) >= 0) && \
                   *(short *) (base + RG(0x1c00 + 0xa, 0x1a00 + 0xd2)) != 0) \
        { \
            int n_   = (*(short *) (base + RG(0x1c00 + 0xa, 0x1a00 + 0xd2)) = 7); \
            char *l_ = LST(base); \
            GridCursor_SelectIfValid((struct Struct_0205bcdc *) (l_ + 4), n_); \
            GridCursor_SetSelectedIndex(l_ + 0x54, n_); \
            func_ov002_0215b9a4(base, K(0x21, 0x24), 0); \
        } \
        if (*(int *) (base + 0x1000 + RG(0xbbc, 0xa84)) == K(0xb, 0xc)) { \
            *(int *) (base + 0x1000 + RG(0xbb8, 0xa80)) = K(0xb, 0xc); \
            func_ov002_0215b9a4(base, K(0xb, 0xc), 0); \
            SetFieldB0AndUpdate0205dee8((struct Obj0205dee8 *) LST(base), K(0xb, 0xc)); \
            Window_SetPanePalette((struct Struct_0205d81c *) LST(base), K(0xb, 0xc), 0); \
            Window_SetPanePalette((struct Struct_0205d81c *) LST(base), K(0xd, 0xe), 1); \
            func_ov002_02161cf0(base); \
        } \
    } while (0)

// USA: func_ov002_0216a300
extern "C" ARM void func_ov002_0216a300(char *base) {
    char *g                                 = (char *) MessageSystem_GetInstance();
    *(unsigned char *) (g + 0x1000 + RG(0x9ae, 0x7de)) = 0;
    int state                               = *(int *) (base + 0x1000 + RG(0xbc0, 0xa88));
    if (state == 0) {
        *(unsigned int *) (base + 0x2000 + RG(0x47c, 0x2ac)) &= ~4;
        FindAndLinkMatchingEntry0205de24((struct Struct0205de24 *) LST(base), 0, 3);
        func_ov002_02161cf0(base);
        func_ov002_02160fb4(base);
        SePlayer_Play((struct SePlayer *) g_sePlayer, 5, 0);
        SetElementFlag0x20ByKey0205def8((struct Struct_0205def8 *) LST(base), 0, K(0x25, 0x28));
        char *p = GetField4Ptr020e1b24(*(void **) (*(char **) base + 0x10));
        if (((struct Bits0216a300 *) p)->b0) {
            ResetAndReposition020e280c(*(struct Obj020e280c **) (base + 4), *(void **) (p + 0x30));
        } else {
            func_020e280c(*(struct Struct_020e280c **) (arg0 + 4), (void *) -1);
        }
        *(int *) (base + 0x1000 + RG(0xbc0, 0xa88)) += 1;
    } else if (state == 1) {
        SetElementFlag0x20ByKey0205def8((struct Struct_0205def8 *) LST(base), 0, K(0x25, 0x28));
        *(unsigned int *) (base + 0x2000 + RG(0x47c, 0x2ac)) |= 4;
        *(short *) (base + RG(0x1c00 + 0x12, 0x1a00 + 0xda)) =
            Window_GetSelectedIndex((struct Struct_0205c570 *) LST(base));
        int ok  = 0;
        char *f = GetFieldIfFlag4_020100f8((char *) GameState::GetInstance());
        if (f != NULL && ((*(unsigned char *) (f + 0x244) & 2) || GetIntAt0x23c((struct IntField0x23c_020a27c4 *) f) == 0)) {
            if (g_keyManager.TestKeysPressed(0x200)) {
                var3 = 1;
            } else {
                var3 = 0;
            }
        }
        *(short *) (base + RG(0x1c00 + 0x12, 0x1a00 + 0xda)) = GetField0x15UnlessInactive_020e2918(*(signed char **) (base + 4));
        if (*(short *) (base + RG(0x1c00 + 0x12, 0x1a00 + 0xda)) >= 0 || ok) {
            *(short *) (base + RG(0x1c00 + 0x12, 0x1a00 + 0xda)) = GetSignedByteAt0x14_020e2910(*(signed char **) (base + 4));
            ResetSelectionState020e25e8(*(struct Obj020e25e8 **) (base + 4));
            SePlayer_Play((struct SePlayer *) g_sePlayer, 1, 0);
            data_ov002_0216d3ac = 0;
            switch (*(short *) (arg0 + RG(0x1c00 + 0x12, 0x1a00 + 0xda))) {
                case 0: {
                    *(unsigned int *) (base + 0x2000 + RG(0x47c, 0x2ac)) &= ~4;
                    *(unsigned char *) (base + RG(0xf80, 0xed8)) = *(int *) (base + 0x1000 + RG(0xbb8, 0xa80));
                    char *e                           = ItemTable_Find(
                        (struct ItemTable *) (base + RG(0x3ec + 0x400, 0x750)), *(short *) (base + RG(0x1c00 + 0x22, 0x1a00 + 0xea)));
                    if (e != NULL && *(short *) (e + 0x18) == 0x5612) {
                        func_ov002_0215b9a4(base, *(int *) (base + 0x1000 + RG(0xbb8, 0xa80)), 1);
                        Window_ClosePane((struct Entry_0205d6a0 *) LST(base), 0);
                        *(short *) (base + RG(0x1c00 + 0x28, 0x1a00 + 0xf0))          = 0x7972;
                        *(short *) (base + RG(0x1c00 + 0x2a, 0x1a00 + 0xf2))          = -1;
                        *(int *) (base + 0x1000 + RG(0xbb8, 0xa80))           = K(0x26, 0x29);
                        *(int *) (base + 0x1000 + RG(0xbbc, 0xa84))           = K(0x2b, 0x2e);
                        *(int *) (base + 0x1000 + RG(0xbc0, 0xa88))           = 0;
                        *(unsigned char *) (base + 0x1000 + RG(0xc2e, 0xaf6)) = 0;
                        func_ov017_0219577c(1, 1, 1);
                        return;
                    }
                    if (*(unsigned char *) (base + 0x1000 + RG(0xc30, 0xaf8)) != 0) {
                        *(unsigned char *) (base + 0x1000 + RG(0xc2e, 0xaf6)) = 0;
                        Window_ClosePane((struct Entry_0205d6a0 *) LST(base), 0);
                        switch (*(unsigned char *) (base + 0x1000 + RG(0xc79, 0xb3d))) {
                            case 0: {
                                char *var6 = (char *)func_0200ff1c(GameState::GetInstance(), *(signed char *) (arg0 + RG(0x1c00 + 0x21, 0x1a00 + 0xe9)));
                                int var7  = 1;
                                if (var6 != NULL && *(unsigned short *) (*(char **) (var6 + 0x130) + 4) == 0) var7 = 0;
                                if (!func_020dc920(*(unsigned char *) (arg0 + 0x1000 + RG(0xc21, 0xae9)), 1, 0, 0)) var7 = 0;
                                if (var7) {
                                    func_ov002_0216bfd4(arg0, 1);
                                    func_ov017_021d0198(1, *(signed char *) (arg0 + RG(0x1c00 + 0x20, 0x1a00 + 0xe8)),
                                                                        *(signed char *) (arg0 + RG(0x1c00 + 0x21, 0x1a00 + 0xe9)),
                                                                        *(short *) (arg0 + RG(0x1c00 + 0x22, 0x1a00 + 0xea)));
                                    *(int *) (arg0 + 0x1000 + RG(0xc74, 0xb38)) = 0x1e;
                                } else {
                                    func_ov002_0216bfd4(arg0, 6);
                                }
                                return;
                            }
                            case 3:
                                func_ov002_0216bfd4(arg0, 4);
                                func_ov017_021d0198(2, *(signed char *) (arg0 + RG(0x1c00 + 0x20, 0x1a00 + 0xe8)),
                                                                    *(signed char *) (arg0 + RG(0x1c00 + 0x21, 0x1a00 + 0xe9)),
                                                                    *(short *) (arg0 + RG(0x1c00 + 0x22, 0x1a00 + 0xea)));
                                return;
                        }
                        return;
                    }
                    if (*(unsigned char *) (arg0 + 0x1000 + RG(0xc32, 0xafa)) != 0) {
                        *(unsigned char *) (arg0 + 0x1000 + RG(0xc32, 0xafa)) = 0;
                        *(short *) (arg0 + RG(0x1c00 + 0x28, 0x1a00 + 0xf0))          = 0x2367;
                        *(short *) (arg0 + RG(0x1c00 + 0x2a, 0x1a00 + 0xf2))          = -1;
                        *(int *) (arg0 + 0x1000 + RG(0xbb8, 0xa80))           = K(0x26, 0x29);
                        *(int *) (arg0 + 0x1000 + RG(0xbbc, 0xa84))           = 5;
                        *(int *) (arg0 + 0x1000 + RG(0xbc0, 0xa88))           = 0;
                        *(unsigned char *) (arg0 + 0x1000 + RG(0xc2e, 0xaf6)) = 1;
                        return;
                    }
                    *(short *) (arg0 + RG(0x1c00 + 0x28, 0x1a00 + 0xf0))          = func_ov002_0215753c((unsigned char *) arg0);
                    *(short *) (arg0 + RG(0x1c00 + 0x2a, 0x1a00 + 0xf2))          = -1;
                    *(unsigned char *) (arg0 + 0x1000 + RG(0xc2e, 0xaf6)) = 0;
                    if (*(short *) (arg0 + RG(0x1c00 + 0x28, 0x1a00 + 0xf0)) < 0) {
                        func_ov002_02156e90(arg0);
                        if (*(short *) (arg0 + RG(0x1c00 + 0xa, 0x1a00 + 0xd2)) >= 0) {
                            func_ov002_02156e90(arg0);
                            func_ov002_02156e90(arg0);
                            func_ov002_02161cf0(arg0);
                            *(int *) (arg0 + 0x1000 + RG(0xbc0, 0xa88)) = 1;
                            *(short *) (arg0 + RG(0x1c00 + 0xa, 0x1a00 + 0xd2)) = -1;
                        }
                    } else {
                        Window_ClosePane((struct Entry_0205d6a0 *) LST(base), 0);
                        *(int *) (base + 0x1000 + RG(0xbb8, 0xa80))  = K(0x26, 0x29);
                        *(short *) (base + RG(0x1c00 + 0x16, 0x1a00 + 0xde)) = 0;
                        *(short *) (base + RG(0x1c00 + 0x18, 0x1a00 + 0xe0)) = 0;
                        func_ov002_02161cf0(base);
                        *(int *) (base + 0x1000 + RG(0xbc8, 0xa90)) = 1;
                        *(int *) (base + 0x1000 + RG(0xbc0, 0xa88)) = 0;
                    }
                    if (*(int *) (base + 0x1000 + RG(0xbbc, 0xa84)) == K(0x24, 0x27)) {
                        Window_SetPanePalette((struct Struct_0205d81c *) LST(base), K(0x15, 0x16), 1);
                        *(int *) (base + 0x1000 + RG(0xbb8, 0xa80)) = K(0x24, 0x27);
                        *(int *) (base + 0x1000 + RG(0xbc0, 0xa88)) = 1;
                    }
                    if (*(int *) (base + 0x1000 + RG(0xbbc, 0xa84)) == K(0xb, 0xc)) {
                        func_ov002_0215b9a4(base, K(0xd, 0xe), 0);
                        Window_SetPanePalette((struct Struct_0205d81c *) LST(base), K(0xb, 0xc), 1);
                        Window_SetPanePalette((struct Struct_0205d81c *) LST(base), K(0xd, 0xe), 1);
                    }
                    break;
                }
                case 1:
                    *(unsigned int *) (arg0 + 0x2000 + RG(0x47c, 0x2ac)) &= ~4;
                    *(unsigned char *) (arg0 + 0x1000 + RG(0xc2e, 0xaf6)) = 0;
                    CONFIRM_0216A300();
                    break;
            }
        } else if (*(struct Struct_020e28dc **) (arg0 + 4) != NULL && func_020e2984(*(struct Struct_020e28dc **) (arg0 + 4))) {
            func_020e25e8(*(struct Struct_020e25e8 **) (arg0 + 4));
            *(unsigned int *) (arg0 + 0x2000 + RG(0x47c, 0x2ac)) &= ~4;
            *(unsigned char *) (arg0 + 0x1000 + RG(0xc2e, 0xaf6)) = 0;
            data_ov002_0216d3ac                        = 0;
            CONFIRM_0216A300();
        } else {
            data_ov002_0216d3ac = 1;
        }
    }
}
