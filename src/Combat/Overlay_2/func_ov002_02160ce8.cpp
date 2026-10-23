#include "GameState/GameState.h"
#include <globaldefs.h>

struct Struct_0201099c_3;

int AppendFrameTag02041c08(char *dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag_02041ea4(char *dst, int cursor);
char *KeyTable_Get(struct Container020e0310 *c, int key);
extern "C" int func_020420e8(const char *text, int large);
void AppendXYTag_02041a90(char *text, int x, int y);
int AppendString02042058(char *dst, const char *src);
int AppendFormatted02041fac(char *dst, int str, int b);
int AppendHeightTag_02041b00(char *dst, int h);
int AppendPaletteTag_02041e70(char *dst, int palette);
int AppendNameTag_02041b70(char *dst, int n, const char *name);
int AppendXTag_02041a28(char *dst, int x);
int AppendSourceRectTag_02041bac(char *dst, int a, int b, int c, int d, int e);
int AppendLineTag02041cc0(char *dst, int a1);
extern "C" void *__clear(void *destination, int count);

extern "C" char data_ov002_0216d2b3[];

// USA: func_ov002_02160ce8
extern "C" ARM void func_ov002_02160ce8(unsigned char *arg0, char *arg1, int arg2) {
    unsigned char *var0[3];
    short var1;
    int var2;
    unsigned char var3;
    short var4;
    int var5;
    unsigned char var6;
    if (arg1 == NULL) return;
    GameState::GetInstance();
    int var7  = *(short *) (arg0 + 0x1c0e);
    int var8     = 0;
    int var9 = 3;
    __clear(var0, 0xc);
    var0[0] = arg0 + 0x1c2c;
    var0[1] = arg0 + 0x1c2d;
    if (arg2) {
        func_02041c08(arg1, var7, 8, 5, 5, 5);
    }
    AppendCursorTag_02041ea4(dst, cursor);
    char *title = KeyTable_Get((struct Container020e0310 *) (self + 0x20), 0xfa6);
    AppendXYTag_02041a90(dst, (0xf0 - func_020420e8(title, 0)) >> 1, 4);
    AppendString02042058(dst, title);
    AppendFormatted02041fac(dst, (int) data_ov002_0216d2b3, 0x10);
    key = 0x11f8;
    for (r = 0; r < 3; r++) {
        if (r == 2) {
            AppendHeightTag_02041b00(dst, 7);
        }
        AppendPaletteTag_02041e70(dst, 0xf);
        AppendNameTag_02041b70(dst, row,
                      KeyTable_Get((struct Container020e0310 *) (self + 0x20), key++));
        if (r != 2) {
            AppendXTag_02041a28(dst, 0x5a);
            k = 0x11fb;
            AppendPaletteTag_02041e70(dst, 3);
            AppendString02042058(
                dst, KeyTable_Get((struct Container020e0310 *) (self + 0x20), k++));
            x = 0x7d;
            for (c = 0; c < 5; c++) {
                AppendXTag_02041a28(dst, x);
                int pal = 0xf;
                if (c + 1 == *sels[r]) {
                    pal  = 5;
                    selX = x;
                }
                AppendPaletteTag_02041e70(dst, pal);
                AppendNameTag_02041b70(dst, nameIdx,
                              KeyTable_Get((struct Container020e0310 *) (self + 0x20), k++));
                nameIdx++;
                x += 0x10;
            }
            AppendXTag_02041a28(dst, 0xce);
            AppendPaletteTag_02041e70(dst, 3);
            AppendString02042058(
                dst, KeyTable_Get((struct Container020e0310 *) (self + 0x20), k));
            AppendXTag_02041a28(dst, selX + 3);
            AppendPaletteTag_02041e70(dst, 0xf);
            AppendString02042058(
                dst, KeyTable_Get((struct Container020e0310 *) (self + 0x20), 0x1202));
        }
        if (var3 != 2) {
            func_02042058(arg1, *(char **) (arg0 + 0x1bdc));
        }
        var8++;
    }
    func_02041bac(arg1, 0xf, 0x4e, 0x10, 1, 0x24);
    func_02041cc0(arg1, 0x34);
}
