#include "GameState/GameState.h"
#include <globaldefs.h>

struct Container020e0310;

extern "C" int Text_AppendFrameTag(char *dst, int a1, int a2, int a3, int a4, int a5);
extern "C" int Text_AppendCursorTag(char *dst, int cursor);
extern "C" char *KeyTable_Get(struct Container020e0310 *c, int key);
extern "C" int Font_GetTextWidth(const char *text, int large);
extern "C" void func_02041a90(char *text, int x, int y);
extern "C" int Text_Append(char *dst, const char *src);
extern "C" int func_02041fac(char *dst, int str, int b);
extern "C" int func_02041b00(char *dst, int h);
extern "C" int Text_AppendPaletteTag(char *dst, int palette);
extern "C" int Text_AppendNTag(char *dst, int n, const char *name);
extern "C" int func_02041a28(char *dst, int x);
extern "C" int Text_AppendSdrcTag(char *dst, int a, int b, int c, int d, int e);
extern "C" int func_02041cc0(char *dst, int a1);
extern "C" void *__clear(void *destination, int count);

extern "C" char data_ov002_0216d2b3[];

// USA: func_ov002_02160ce8
extern "C" ARM void func_ov002_02160ce8(unsigned char *self, char *dst, int flag) {
    unsigned char *var0[3];
    short key;
    int var2;
    unsigned char r;
    short k;
    int x;
    unsigned char c;
    if (dst == NULL) return;
    GameState::GetInstance();
    int cursor  = *(short *) (self + 0x1c0e);
    int row     = 0;
    int nameIdx = 3;
    __clear(var0, 0xc);
    var0[0] = self + 0x1c2c;
    var0[1] = self + 0x1c2d;
    if (flag) {
        Text_AppendFrameTag(dst, cursor, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, cursor);
    char *title = KeyTable_Get((struct Container020e0310 *) (self + 0x20), 0xfa6);
    func_02041a90(dst, (0xf0 - Font_GetTextWidth(title, 0)) >> 1, 4);
    Text_Append(dst, title);
    func_02041fac(dst, (int) data_ov002_0216d2b3, 0x10);
    key = 0x11f8;
    for (r = 0; r < 3; r++) {
        if (r == 2) {
            func_02041b00(dst, 7);
        }
        Text_AppendPaletteTag(dst, 0xf);
        Text_AppendNTag(dst, row,
                      KeyTable_Get((struct Container020e0310 *) (self + 0x20), key++));
        if (r != 2) {
            func_02041a28(dst, 0x5a);
            k = 0x11fb;
            Text_AppendPaletteTag(dst, 3);
            Text_Append(
                dst, KeyTable_Get((struct Container020e0310 *) (self + 0x20), k++));
            x = 0x7d;
            for (c = 0; c < 5; c++) {
                func_02041a28(dst, x);
                int pal = 0xf;
                if (c + 1 == *var0[r]) {
                    pal  = 5;
                    var2 = x;
                }
                Text_AppendPaletteTag(dst, pal);
                Text_AppendNTag(dst, nameIdx,
                              KeyTable_Get((struct Container020e0310 *) (self + 0x20), k++));
                nameIdx++;
                x += 0x10;
            }
            func_02041a28(dst, 0xce);
            Text_AppendPaletteTag(dst, 3);
            Text_Append(
                dst, KeyTable_Get((struct Container020e0310 *) (self + 0x20), k));
            func_02041a28(dst, var2 + 3);
            Text_AppendPaletteTag(dst, 0xf);
            Text_Append(
                dst, KeyTable_Get((struct Container020e0310 *) (self + 0x20), 0x1202));
        }
        if (r != 2) {
            Text_Append(dst, *(char **) (self + 0x1bdc));
        }
        row++;
    }
    Text_AppendSdrcTag(dst, 0xf, 0x4e, 0x10, 1, 0x24);
    func_02041cc0(dst, 0x34);
}
