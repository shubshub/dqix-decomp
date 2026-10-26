#include <globaldefs.h>
#include "Input/Input.h"

struct Struct0205de24;
struct Struct_0205c570;
struct Obj_0205da38;
struct SePlayer;

extern "C" void func_0205de24(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
extern "C" int Window_GetSelectedIndex(struct Struct_0205c570 *s);
extern "C" int Window_IsSelectionTouched(struct Obj_0205da38* obj, int key);
extern "C" void SePlayer_Play(struct SePlayer *o, int a, int b);
extern "C" int func_ov002_021574d4(void *self, int idx);
extern "C" int func_ov002_02161b48(char *self, int flag);
extern "C" void func_ov002_02161cf0(void *self);
extern "C" void func_ov002_02160274(void *self);
extern "C" void func_ov002_02156e90(void *self);
extern char g_sePlayer[];
#if defined(jpn)
extern "C" void func_ov002_0215bba8(char *base);
#endif

#if defined(jpn)
enum { regionalState = -0x138, regionalList = -0xa8, Enum_ov002_02169520_0_3 = -0x1d0, Enum_ov002_02169520_30 = 0x1f };
#else
enum { regionalState = 0, regionalList = 0, Enum_ov002_02169520_0_3 = 0, Enum_ov002_02169520_30 = 0x1e };
#endif

// USA: func_ov002_02169520
extern "C" ARM void func_ov002_02169520(char *base) {
    int phase = *(int *) (base + 0x1bc0 + regionalState);
    if (phase == 0) {
        *(short *) (base + 0x1c08 + regionalState) = 0;
        func_0205de24((struct Struct0205de24 *) (base + 0xec8 + regionalList), 0, 2);
        func_ov002_02161cf0(base);
        func_ov002_02160274(base);
        (*(int *) (base + 0x1bc0 + regionalState))++;
        return;
    }
    if (phase != 1) return;
    *(int *) (base + 0x247c + Enum_ov002_02169520_0_3) |= 4;
    short old                  = *(short *) (base + 0x1c08 + regionalState);
    *(short *) (base + 0x1c08 + regionalState) = Window_GetSelectedIndex((struct Struct_0205c570 *) (base + 0xec8 + regionalList));
    if (old != *(short *) (base + 0x1c08 + regionalState)) *(int *) (base + 0x1bcc + regionalState) = 1;
    *(signed char *) (base + 0x1c20 + regionalState) = func_ov002_021574d4(base, *(short *) (base + 0x1c08 + regionalState));
#if defined(jpn)
    func_ov002_0215bba8(base);
#endif
    int pressed                      = g_keyManager.TestKeysPressed(0x601);
    int cancel = (pressed | Window_IsSelectionTouched((struct Obj_0205da38*)(base + 0xec8 + regionalList), 0x14)) ? 1 : 0;
    if (cancel) {
        *(unsigned char *) (base + 0xf80 + regionalList) = *(int *) (base + 0x1bb8 + regionalState);
        *(int *) (base + 0x247c + Enum_ov002_02169520_0_3) &= ~4;
        SePlayer_Play((struct SePlayer *) g_sePlayer, 1, 0);
        int ok                     = 0;
        *(short *) (base + 0x1c12 + regionalState) = ok;
        int sel                    = *(signed char *) (base + 0x1c20 + regionalState);
        if (sel >= 0 && sel <= 3) ok = 1;
        if (!ok) return;
        *(short *) (base + 0x1c28 + regionalState) = sel;
        *(int *) (base + 0x1bb8 + regionalState)   = Enum_ov002_02169520_30;
        *(int *) (base + 0x1bc0 + regionalState)   = 0;
        return;
    }
    if (func_ov002_02161b48(base, 1)) {
        *(short *) (base + 0x1c08 + regionalState)       = -1;
        *(signed char *) (base + 0x1c20 + regionalState) = -1;
        func_ov002_02156e90(base);
    }
}
