#include "GameState/GameState.h"
#include <globaldefs.h>

struct Struct_0201099c_3;

struct Struct_ov002_0216caa4 {
    int unknown_0_[8];
};
struct Struct_ov002_0216ca88 {
    int unknown_0_[7];
};

int Text_AppendFrameTag(char *dst, int a1, int a2, int a3, int a4, int a5);
int Text_AppendCursorTag(char *dst, int cursor);
int AppendWireTag02041c64(char *dst, int a1, int a2, int a3, int a4, int a5);
char *KeyTable_Get(struct Container020e0310 *c, int key);
extern "C" int Font_GetTextWidth(const char *text, int large);
int AppendXTag_02041a28(char *dst, int x);
int Text_Append(char *dst, const char *src);
int AppendLineTag02041cc0(char *dst, int a1);
extern "C" void *__clear(void *destination, int count);
void AppendXYTag_02041a90(char *text, int x, int y);
int AppendDotLeaderLabel02042084(char *buffer, char *label, int width, int extra);
int Text_AppendNTag(char *dst, int n, const char *name);

extern Struct_ov002_0216caa4 data_ov002_0216caa4;
extern Struct_ov002_0216ca88 data_ov002_0216ca88;

// USA: func_ov002_021607cc
#if defined(jpn)
extern "C" int func_0204234c(char *arg0, int arg1);
extern Struct_ov002_0216caa4 data_ov002_0216d0d0;
extern Struct_ov002_0216ca88 data_ov002_0216d0b4;
#define func_02041cc0 func_0204234c
#define data_ov002_0216caa4 data_ov002_0216d0d0
#define data_ov002_0216ca88 data_ov002_0216d0b4
extern "C" ARM void func_ov002_021607cc(unsigned char *arg0, char *arg1, int arg2) {
    if (arg1 == NULL) return;
    GameState::GetInstance();
    int cursor        = *(short *) (self + 0x1ad2);
    Ints8_0216caa4 ys = data_ov002_0216caa4;
    if (flag) {
        Text_AppendFrameTag(dst, cursor, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, cursor);
    AppendWireTag02041c64(dst, 0x64, 2, 2, 2, 2);
    char *title = KeyTable_Get((struct Container020e0310 *) (self + 8), 0x1194);
    Text_Append(dst, title);
    AppendLineTag02041cc0(dst, 0x11);
    Ints7_0216ca88 offs = data_ov002_0216ca88;
    char buf[0x40];
    int i;
    for (i = 0; i < 7; i++) {
        signed char v = *(signed char *) (self + offs.v[i] + 0x1b40);
        int key;
        if (v < 0) {
            key = 0x119d;
        } else {
            var7 = var6;
            var7 += 0x119d;
        }
        __clear(buf, 0x40);
        AppendXYTag_02041a90(dst, 0x2b, ys.v[i]);
        if (key != 0x119d) {
            Text_Append(
                buf, KeyTable_Get((struct Container020e0310 *) (self + 8), (short) key));
        } else {
            AppendDotLeaderLabel02042084(
                buf, KeyTable_Get((struct Container020e0310 *) (self + 8), (short) key),
                0x64, 0xa);
        }
        Text_AppendNTag(dst, i, buf);
    }
    AppendWireTag02041c64(dst, 0, 2, 2, 2, 2);
    AppendLineTag02041cc0(dst, 0xa2);
    AppendXYTag_02041a90(dst, 0x2b, ys.v[i]);
    Text_AppendNTag(dst, i, KeyTable_Get((struct Container020e0310 *) (self + 8), 0x11fa));
}
#else
extern "C" ARM void func_ov002_021607cc(unsigned char *arg0, char *arg1, int arg2) {
    if (arg1 == NULL) return;
    GameState::GetInstance();
    int cursor        = *(short *) (self + 0x1c0a);
    Ints8_0216caa4 ys = data_ov002_0216caa4;
    if (flag) {
        Text_AppendFrameTag(dst, cursor, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, cursor);
    AppendWireTag02041c64(dst, 0x64, 2, 2, 2, 2);
    char *title = KeyTable_Get((struct Container020e0310 *) (self + 0x20), 0x1194);
    AppendXTag_02041a28(dst, (0x98 - Font_GetTextWidth(title, 0)) >> 1);
    Text_Append(dst, title);
    AppendLineTag02041cc0(dst, 0x11);
    Ints7_0216ca88 offs = data_ov002_0216ca88;
    char buf[0x40];
    int i;
    for (i = 0; i < 7; i++) {
        signed char v = *(signed char *) (self + offs.v[i] + 0x1c7c);
        int key;
        if (v < 0) {
            key = 0x119d;
        } else {
            var15 = var14;
            var15 += 0x119d;
        }
        __clear(buf, 0x40);
        AppendXYTag_02041a90(dst, 0x2b, ys.v[i]);
        if (key != 0x119d) {
            Text_Append(
                buf, KeyTable_Get((struct Container020e0310 *) (self + 0x20), (short) key));
        } else {
            AppendDotLeaderLabel02042084(
                buf, KeyTable_Get((struct Container020e0310 *) (self + 0x20), (short) key),
                0x64, 0);
        }
        Text_AppendNTag(dst, i, buf);
    }
    AppendWireTag02041c64(dst, 0, 2, 2, 2, 2);
    AppendLineTag02041cc0(dst, 0xa2);
    AppendXYTag_02041a90(dst, 0x2b, ys.v[i]);
    Text_AppendNTag(dst, i, KeyTable_Get((struct Container020e0310 *) (self + 0x20), 0x11fa));
}
#endif
