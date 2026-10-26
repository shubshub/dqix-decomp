#include <globaldefs.h>
#include "Input/Input.h"

struct Struct0205de24;
struct Struct_0205c570;
struct Obj_0205da38;
struct SePlayer;
struct Struct_0205def8;
extern "C" void func_0205de24(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
extern "C" void func_0205def8(struct Struct_0205def8 *s, int a, int b);
extern "C" int Window_GetSelectedIndex(struct Struct_0205c570 *s);
extern "C" int Window_IsSelectionTouched(struct Obj_0205da38* obj, int key);
extern "C" void SePlayer_Play(struct SePlayer *o, int a, int b);
extern "C" int func_ov002_02161b48(char *base, int a);
extern "C" void func_ov002_0215aa5c(char *base);
extern "C" void func_ov002_0215aa14(char *base);
extern "C" void func_ov002_02160734(unsigned char *base);
extern "C" void func_ov002_02161cf0(void *base);
extern "C" void func_ov002_02156e90(void *base);
extern "C" void func_ov002_0215f3a0(void *base);
extern "C" char g_sePlayer[];

#if defined(jpn)
#define OBJ (base + 0xe20)
#else
#define OBJ (base + 0x2c8 + 0xc00)
#endif

static inline int AnyConfirm021696c0(char *base) {
    return (g_keyManager.TestKeysPressed(0x601) |
            Window_IsSelectionTouched((struct Obj_0205da38*)OBJ, 0x14)) ? 1 : 0;
}

#if defined(jpn)
struct Struct_0205d81c;
extern "C" void Window_SetPanePalette(struct Struct_0205d81c *s, int key, int value);

// USA: func_ov002_021696c0
extern "C" ARM void func_ov002_021696c0(char *base) {
    int state = *(int *) (base + 0x1000 + 0xa88);
    if (state == 0) {
        func_ov002_0215aa5c(base);
        *(unsigned int *) (base + 0x2000 + 0x2ac) &= ~4;
        func_0205def8((struct Struct_0205def8 *) OBJ, 0, 0x2c);
        *(short *) (base + 0x1a00 + 0xd2) = 0;
        func_0205de24((struct Struct0205de24 *) OBJ, 0, 2);
        func_ov002_02161cf0(base);
        func_ov002_02160734((unsigned char *) base);
        (*(int *) (base + 0x1000 + 0xa88))++;
    } else if (state == 1) {
        func_0205def8((struct Struct_0205def8 *) OBJ, 1, 0x22);
        func_0205def8((struct Struct_0205def8 *) OBJ, 1, 0x23);
        Window_SetPanePalette((struct Struct_0205d81c *) OBJ, 0x22, 0);
        Window_SetPanePalette((struct Struct_0205d81c *) OBJ, 0x23, 0);
        *(unsigned int *) (base + 0x2000 + 0x2ac) |= 4;
        *(short *) (base + 0x1a00 + 0xd2) =
            Window_GetSelectedIndex((struct Struct_0205c570 *) OBJ);
        if (AnyConfirm021696c0(base) && *(short *) (base + 0x1a00 + 0xd2) == 7) {
            func_ov002_0215aa14(base);
            SePlayer_Play((struct SePlayer *) g_sePlayer, 1, 0);
            *(int *) (base + 0x1000 + 0xa80) = 0x16;
            *(short *) (base + 0x1a00 + 0xd2) = 0;
            *(unsigned int *) (base + 0x2000 + 0x2ac) &= ~4;
            func_ov002_02156e90(base);
            func_0205def8((struct Struct_0205def8 *) OBJ, 1, 0x2c);
        } else if (AnyConfirm021696c0(base)) {
            *(unsigned char *) (base + 0xed8) = *(int *) (base + 0x1000 + 0xa80);
            *(unsigned int *) (base + 0x2000 + 0x2ac) &= ~4;
            SePlayer_Play((struct SePlayer *) g_sePlayer, 1, 0);
            *(int *) (base + 0x1000 + 0xa80) = 0x25;
            *(int *) (base + 0x1000 + 0xa88) = 0;
        } else if (func_ov002_02161b48(base, 1)) {
            func_ov002_0215aa14(base);
            *(int *) (base + 0x1000 + 0xa80) = 0x16;
            *(short *) (base + 0x1a00 + 0xd2) = 0;
            *(unsigned int *) (base + 0x2000 + 0x2ac) &= ~4;
            func_ov002_02156e90(base);
            func_0205def8((struct Struct_0205def8 *) OBJ, 1, 0x2c);
        }
    }
}
#else
// USA: func_ov002_021696c0
extern "C" ARM void func_ov002_021696c0(char *base) {
    int state = *(int *) (base + 0x1000 + 0xbc0);
    if (state == 0) {
        *(unsigned int *) (base + 0x2000 + 0x47c) &= ~4;
        func_0205def8((struct Struct_0205def8 *) (base + 0x2c8 + 0xc00), 0, 1);
        func_0205def8((struct Struct_0205def8 *) (base + 0x2c8 + 0xc00), 0, 0x29);
        func_ov002_02156e90(base);
        *(int *) (base + 0x1000 + 0xbb8) = 0x21;
        *(int *) (base + 0x1000 + 0xbc0) = 0x32;
    } else if (state == 0x32) {
        func_ov002_0215aa5c(base);
        *(short *) (base + 0x1c00 + 0xa) = 0;
        func_0205de24((struct Struct0205de24 *) (base + 0x2c8 + 0xc00), 0, 2);
        func_ov002_02161cf0(base);
        func_ov002_02160734((unsigned char *) base);
        *(int *) (base + 0x1000 + 0xbc0) = 1;
    } else if (state == 1) {
        *(unsigned int *) (base + 0x2000 + 0x47c) |= 4;
        *(short *) (base + 0x1c00 + 0xa) =
            Window_GetSelectedIndex((struct Struct_0205c570 *) (base + 0x2c8 + 0xc00));
        if (AnyConfirm021696c0(base) && *(short *) (base + 0x1c00 + 0xa) == 7) {
            func_ov002_0215aa14(base);
            SePlayer_Play((struct SePlayer *) g_sePlayer, 1, 0);
            *(unsigned int *) (base + 0x2000 + 0x47c) &= ~4;
            func_ov002_02156e90(base);
            *(int *) (base + 0x1000 + 0xbb8) = 0x21;
            *(int *) (base + 0x1000 + 0xbc0) = 0x64;
        } else if (AnyConfirm021696c0(base)) {
            *(unsigned char *) (base + 0xf80) = *(int *) (base + 0x1000 + 0xbb8);
            *(unsigned int *) (base + 0x2000 + 0x47c) &= ~4;
            SePlayer_Play((struct SePlayer *) g_sePlayer, 1, 0);
            *(int *) (base + 0x1000 + 0xbb8) = 0x22;
            *(int *) (base + 0x1000 + 0xbc0) = 0;
        } else if (func_ov002_02161b48(base, 1)) {
            func_ov002_0215aa14(base);
            *(unsigned int *) (base + 0x2000 + 0x47c) &= ~4;
            func_ov002_02156e90(base);
            *(int *) (base + 0x1000 + 0xbb8) = 0x21;
            *(int *) (base + 0x1000 + 0xbc0) = 0x64;
        }
    } else if (state == 0x64) {
        *(short *) (base + 0x1c00 + 0xa) = 0;
        *(int *) (base + 0x1000 + 0xbb8) = 0x15;
        func_0205de24((struct Struct0205de24 *) (base + 0x2c8 + 0xc00), 0, 2);
        func_ov002_02161cf0(base);
        func_ov002_0215f3a0(base);
        *(int *) (base + 0x1000 + 0xbc0) = 1;
    }
}
#endif
