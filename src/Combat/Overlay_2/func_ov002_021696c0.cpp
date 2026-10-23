#include <globaldefs.h>
#include "Input/Input.h"

struct Struct0205de24;
struct Struct_0205c570;
struct Obj_0205da38;
struct SePlayer;
struct Struct_0205def8;
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
void SetElementFlag0x20ByKey0205def8(struct Struct_0205def8 *s, int a, int b);
int Window_GetSelectedIndex(struct Struct_0205c570 *s);
int Window_IsSelectionTouched(struct Obj_0205da38* obj, int key);
void SePlayer_Play(struct SePlayer *o, int a, int b);
int CheckFlagOrThreshold_02161b48(char *base, int a);
void CopyByteField0215aa5c(char *base);
void CopyByteField0215aa14(char *base);
void ResetAndRebuildEntries02160734(unsigned char *base);
extern "C" void func_ov002_02161cf0(void *base);
extern "C" void func_ov002_02156e90(void *base);
extern "C" void func_ov002_0215f3a0(void *base);
extern "C" char g_sePlayer[];

#if defined(jpn)
#define OBJ (arg0 + 0xe20)
#else
#define OBJ (arg0 + 0x2c8 + 0xc00)
#endif

static inline int inline_ov002_021696c0(char *arg0) {
    return (g_keyManager.TestKeysPressed(0x601) |
            Window_IsSelectionTouched((struct Obj_0205da38*)(base + 0x2c8 + 0xc00), 0x14)) ? 1 : 0;
}

#if defined(jpn)
struct Struct_ov002_02155960_2;
extern "C" void func_0205deb4(struct Struct_ov002_02155960_2 *arg0, int arg1, int arg2);

// USA: func_ov002_021696c0
extern "C" ARM void func_ov002_021696c0(char *base) {
    int state = *(int *) (base + 0x1000 + 0xbc0);
    if (state == 0) {
        *(unsigned int *) (base + 0x2000 + 0x47c) &= ~4;
        SetElementFlag0x20ByKey0205def8((struct Struct_0205def8 *) (base + 0x2c8 + 0xc00), 0, 1);
        SetElementFlag0x20ByKey0205def8((struct Struct_0205def8 *) (base + 0x2c8 + 0xc00), 0, 0x29);
        func_ov002_02156e90(base);
        *(int *) (base + 0x1000 + 0xbb8) = 0x21;
        *(int *) (base + 0x1000 + 0xbc0) = 0x32;
    } else if (state == 0x32) {
        CopyByteField0215aa5c(base);
        *(short *) (base + 0x1c00 + 0xa) = 0;
        FindAndLinkMatchingEntry0205de24((struct Struct0205de24 *) (base + 0x2c8 + 0xc00), 0, 2);
        func_ov002_02161cf0(base);
        ResetAndRebuildEntries02160734((unsigned char *) base);
        *(int *) (base + 0x1000 + 0xbc0) = 1;
    } else if (state == 1) {
        *(unsigned int *) (base + 0x2000 + 0x47c) |= 4;
        *(short *) (base + 0x1c00 + 0xa) =
            Window_GetSelectedIndex((struct Struct_0205c570 *) (base + 0x2c8 + 0xc00));
        if (AnyConfirm021696c0(base) && *(short *) (base + 0x1c00 + 0xa) == 7) {
            CopyByteField0215aa14(base);
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
        } else if (CheckFlagOrThreshold_02161b48(base, 1)) {
            CopyByteField0215aa14(base);
            *(unsigned int *) (base + 0x2000 + 0x47c) &= ~4;
            func_ov002_02156e90(base);
            *(int *) (base + 0x1000 + 0xbb8) = 0x21;
            *(int *) (base + 0x1000 + 0xbc0) = 0x64;
        }
    }
}
#else
// USA: func_ov002_021696c0
extern "C" ARM void func_ov002_021696c0(char *arg0) {
    int var1 = *(int *) (arg0 + 0x1000 + 0xbc0);
    if (var1 == 0) {
        *(unsigned int *) (arg0 + 0x2000 + 0x47c) &= ~4;
        func_0205def8((struct Struct_ov002_02155960_3 *) (arg0 + 0x2c8 + 0xc00), 0, 1);
        func_0205def8((struct Struct_ov002_02155960_3 *) (arg0 + 0x2c8 + 0xc00), 0, 0x29);
        func_ov002_02156e90(arg0);
        *(int *) (arg0 + 0x1000 + 0xbb8) = 0x21;
        *(int *) (arg0 + 0x1000 + 0xbc0) = 0x32;
    } else if (var1 == 0x32) {
        func_ov002_0215aa5c(arg0);
        *(short *) (arg0 + 0x1c00 + 0xa) = 0;
        func_0205de24((struct Struct_ov002_0215624c_11 *) (arg0 + 0x2c8 + 0xc00), 0, 2);
        func_ov002_02161cf0(arg0);
        func_ov002_02160734((unsigned char *) arg0);
        *(int *) (arg0 + 0x1000 + 0xbc0) = 1;
    } else if (var1 == 1) {
        *(unsigned int *) (arg0 + 0x2000 + 0x47c) |= 4;
        *(short *) (arg0 + 0x1c00 + 0xa) =
            func_0205d794((struct Struct_ov002_0215624c_15 *) (arg0 + 0x2c8 + 0xc00));
        if (inline_ov002_021696c0(arg0) && *(short *) (arg0 + 0x1c00 + 0xa) == 7) {
            func_ov002_0215aa14(arg0);
            func_0205eaa0((struct Struct_ov002_02157d40_7 *) data_02108760, 1, 0);
            *(unsigned int *) (arg0 + 0x2000 + 0x47c) &= ~4;
            func_ov002_02156e90(arg0);
            *(int *) (arg0 + 0x1000 + 0xbb8) = 0x21;
            *(int *) (arg0 + 0x1000 + 0xbc0) = 0x64;
        } else if (inline_ov002_021696c0(arg0)) {
            *(unsigned char *) (arg0 + 0xf80) = *(int *) (arg0 + 0x1000 + 0xbb8);
            *(unsigned int *) (arg0 + 0x2000 + 0x47c) &= ~4;
            func_0205eaa0((struct Struct_ov002_02157d40_7 *) data_02108760, 1, 0);
            *(int *) (arg0 + 0x1000 + 0xbb8) = 0x22;
            *(int *) (arg0 + 0x1000 + 0xbc0) = 0;
        } else if (func_ov002_02161b48(arg0, 1)) {
            func_ov002_0215aa14(arg0);
            *(unsigned int *) (arg0 + 0x2000 + 0x47c) &= ~4;
            func_ov002_02156e90(arg0);
            *(int *) (arg0 + 0x1000 + 0xbb8) = 0x21;
            *(int *) (arg0 + 0x1000 + 0xbc0) = 0x64;
        }
    } else if (var1 == 0x64) {
        *(short *) (arg0 + 0x1c00 + 0xa) = 0;
        *(int *) (arg0 + 0x1000 + 0xbb8) = 0x15;
        func_0205de24((struct Struct_ov002_0215624c_11 *) (arg0 + 0x2c8 + 0xc00), 0, 2);
        func_ov002_02161cf0(arg0);
        func_ov002_0215f3a0(arg0);
        *(int *) (arg0 + 0x1000 + 0xbc0) = 1;
    }
}
#endif
