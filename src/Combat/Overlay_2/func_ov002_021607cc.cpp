#include "GameState/GameState.h"
#include <globaldefs.h>

struct Container020e0310;

struct Struct_ov002_0216caa4 {
    int v[8];
};
struct Struct_ov002_0216ca88 {
    int v[7];
};

extern "C" int Text_AppendFrameTag(char *dst, int a1, int a2, int a3, int a4, int a5);
extern "C" int Text_AppendCursorTag(char *dst, int cursor);
extern "C" int func_02041c64(char *dst, int a1, int a2, int a3, int a4, int a5);
extern "C" char *KeyTable_Get(struct Container020e0310 *c, int key);
extern "C" int Font_GetTextWidth(const char *text, int large);
extern "C" int func_02041a28(char *dst, int x);
extern "C" int Text_Append(char *dst, const char *src);
extern "C" int func_02041cc0(char *dst, int a1);
extern "C" void *__clear(void *destination, int count);
extern "C" void func_02041a90(char *text, int x, int y);
extern "C" int func_02042084(char *buffer, char *label, int width, int extra);
extern "C" int Text_AppendNTag(char *dst, int n, const char *name);

extern Struct_ov002_0216caa4 data_ov002_0216caa4;
extern Struct_ov002_0216ca88 data_ov002_0216ca88;

// USA: func_ov002_021607cc
#if defined(jpn)
extern "C" int func_0204234c(char *dst, int a1);
extern Struct_ov002_0216caa4 data_ov002_0216d0d0;
extern Struct_ov002_0216ca88 data_ov002_0216d0b4;
#define func_02041cc0 func_0204234c
#define data_ov002_0216caa4 data_ov002_0216d0d0
#define data_ov002_0216ca88 data_ov002_0216d0b4
extern "C" ARM void func_ov002_021607cc(unsigned char *self, char *dst, int flag) {
    if (dst == NULL) return;
    GameState::GetInstance();
    int cursor        = *(short *) (self + 0x1ad2);
    Struct_ov002_0216caa4 ys = data_ov002_0216caa4;
    if (flag) {
        Text_AppendFrameTag(dst, cursor, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, cursor);
    func_02041c64(dst, 0x64, 2, 2, 2, 2);
    char *title = KeyTable_Get((struct Container020e0310 *) (self + 8), 0x1194);
    Text_Append(dst, title);
    func_02041cc0(dst, 0x11);
    Struct_ov002_0216ca88 var3 = data_ov002_0216ca88;
    char buf[0x40];
    int i;
    for (i = 0; i < 7; i++) {
        signed char v = *(signed char *) (self + var3.v[i] + 0x1b40);
        int key;
        if (v < 0) {
            key = 0x119d;
        } else {
            key = v;
            key += 0x119d;
        }
        __clear(buf, 0x40);
        func_02041a90(dst, 0x2b, ys.v[i]);
        if (key != 0x119d) {
            Text_Append(
                buf, KeyTable_Get((struct Container020e0310 *) (self + 8), (short) key));
        } else {
            func_02042084(
                buf, KeyTable_Get((struct Container020e0310 *) (self + 8), (short) key),
                0x64, 0xa);
        }
        Text_AppendNTag(dst, i, buf);
    }
    func_02041c64(dst, 0, 2, 2, 2, 2);
    func_02041cc0(dst, 0xa2);
    func_02041a90(dst, 0x2b, ys.v[i]);
    Text_AppendNTag(dst, i, KeyTable_Get((struct Container020e0310 *) (self + 8), 0x11fa));
}
#else
extern "C" ARM void func_ov002_021607cc(unsigned char *self, char *dst, int flag) {
    if (dst == NULL) return;
    GameState::GetInstance();
    int cursor        = *(short *) (self + 0x1c0a);
    Struct_ov002_0216caa4 ys = data_ov002_0216caa4;
    if (flag) {
        Text_AppendFrameTag(dst, cursor, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, cursor);
    func_02041c64(dst, 0x64, 2, 2, 2, 2);
    char *title = KeyTable_Get((struct Container020e0310 *) (self + 0x20), 0x1194);
    func_02041a28(dst, (0x98 - Font_GetTextWidth(title, 0)) >> 1);
    Text_Append(dst, title);
    func_02041cc0(dst, 0x11);
    Struct_ov002_0216ca88 var11 = data_ov002_0216ca88;
    char buf[0x40];
    int i;
    for (i = 0; i < 7; i++) {
        signed char v = *(signed char *) (self + var11.v[i] + 0x1c7c);
        int key;
        if (v < 0) {
            key = 0x119d;
        } else {
            key = v;
            key += 0x119d;
        }
        __clear(buf, 0x40);
        func_02041a90(dst, 0x2b, ys.v[i]);
        if (key != 0x119d) {
            Text_Append(
                buf, KeyTable_Get((struct Container020e0310 *) (self + 0x20), (short) key));
        } else {
            func_02042084(
                buf, KeyTable_Get((struct Container020e0310 *) (self + 0x20), (short) key),
                0x64, 0);
        }
        Text_AppendNTag(dst, i, buf);
    }
    func_02041c64(dst, 0, 2, 2, 2, 2);
    func_02041cc0(dst, 0xa2);
    func_02041a90(dst, 0x2b, ys.v[i]);
    Text_AppendNTag(dst, i, KeyTable_Get((struct Container020e0310 *) (self + 0x20), 0x11fa));
}
#endif
