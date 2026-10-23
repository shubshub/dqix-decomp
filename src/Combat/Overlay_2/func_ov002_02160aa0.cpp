#include <globaldefs.h>

#if defined(jpn)
#define func_0205ec34 func_0205ff20
#endif

struct Container020e0310;
int KeyTable_Get(struct Container020e0310 *c, int key);
int AppendFrameTag02041c08(char *dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag_02041ea4(char *dst, int cursor);
int AppendPaletteTag_02041e70(char *dst, int palette);
int AppendNameTag_02041b70(char *dst, int n, const char *name);
int AppendString02042058(char *dst, const char *src);
int NextIndexOrZero_0215a9b4(void *base, short i);
int GetShortFromTable0206e3d4(int a, int b);
void SetElementStateOrCreate0215b918(unsigned char *self, int a, int b, int c);
extern "C" char *func_0205ec34(void);
extern "C" char data_ov002_0216d2b4[];

// USA: func_ov002_02160aa0
extern "C" ARM void func_ov002_02160aa0(unsigned char *arg0, char *arg1, int arg2) {
    if (arg1 == NULL) return;

    short var0                                    = *(short *) (arg0 + 0x1c00 + 0xc);
    int var1                                 = var0 % 16;
    *(unsigned char *) (arg0 + 0x2000 + 0x484) = var0 / 16;
    if (arg2) {
        func_02041c08(arg1, var1, 8, 5, 5, 5);
    }
    func_02041ea4(arg1, var1);

    short n = 0;
    unsigned char end;
    unsigned char i = *(unsigned char *) (base + 0x2000 + 0x484) << 4;
    end             = i + 0x10;
    char *save      = func_0205ec34();
    for (; i < end; i++) {
        cursor = GetShortFromTable0206e3d4((int) save, NextIndexOrZero_0215a9b4(base, i));
        if (cursor == 0) {
            AppendPaletteTag_02041e70(dst, 0xf);
            AppendNameTag_02041b70(dst, n,
                          (const char *) KeyTable_Get(
                              (struct Container020e0310 *) (base + 0x20), 0x119c + 1));
        } else if (*(unsigned int *) (base + 0x2000 + 0x480) & (1 << (cursor - 1))) {
            AppendPaletteTag_02041e70(dst, 0xf);
            AppendNameTag_02041b70(dst, n,
                          (const char *) KeyTable_Get(
                              (struct Container020e0310 *) (base + 0x20), (short) (cursor + 0x119d)));
        } else {
            AppendPaletteTag_02041e70(dst, 0xf);
            AppendNameTag_02041b70(dst, n,
                          (const char *) KeyTable_Get(
                              (struct Container020e0310 *) (base + 0x20), 0x119c));
        }
        var2++;
        if (var4 & 1) {
            func_02042058(arg1, *(const char **) (arg0 + 0x1000 + 0xbdc));
        } else {
            func_02042058(arg1, data_ov002_0216d2b4);
        }
    }
    func_02041e70(arg1, 0xf);
    func_ov002_0215b918(arg0, 0x22, *(unsigned char *) (arg0 + 0x2000 + 0x484), 2);
}
