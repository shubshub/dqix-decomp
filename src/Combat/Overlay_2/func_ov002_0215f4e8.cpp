#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov002_0215f4e8_7166 = 0x1ac6, Enum_ov002_0215f4e8_3036 = 0xaa4, Enum_ov002_0215f4e8_32 = 0x8 };
#define func_02041cc0 func_0204234c
#else
enum { Enum_ov002_0215f4e8_7166 = 0x1bfe, Enum_ov002_0215f4e8_3036 = 0xbdc, Enum_ov002_0215f4e8_32 = 0x20 };
#endif

struct Container020e0310;
int KeyTable_Get(struct Container020e0310 *c, int key);
int AppendFrameTag02041c08(char *dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag_02041ea4(char *dst, int cursor);
const char *CallFunc020e0434With02153694_020e51cc(int key);
int AppendString02042058(char *dst, const char *src);
#if defined(jpn)
extern "C" int func_0204234c(char *arg0, int arg1);
#else
extern "C" int func_02041cc0(char *arg0, int arg1);
#endif
extern "C" int func_02041a90(char *arg0, int arg1, int arg2);
extern "C" int func_02041e70(char *arg0, int arg1);
extern "C" int func_02041b70(char *arg0, int arg1, const char *arg2);
extern "C" void func_ov002_02156080(void *arg0, short *arg1, short *arg2);
extern "C" int func_ov002_02161920(void *arg0);

// USA: func_ov002_0215f4e8
extern "C" ARM void func_ov002_0215f4e8(unsigned char *arg0, char *arg1, int arg2) {
    if (arg1 == NULL) return;

    int var0 = *(short *) (arg0 + Enum_ov002_0215f4e8_7166);
    if (arg2) {
        func_02041c08(arg1, var0, 8, 5, 5, 5);
    }
    func_02041ea4(arg1, var0);
#if defined(jpn)
    AppendString02042058(dst, (const char *) KeyTable_Get((struct Container020e0310 *) (base + NamesOffset), 0xfa0));
#else
    func_02042058(arg1, func_020e51cc(0x16));
#endif
    func_02042058(arg1, *(const char **) (arg0 + 0x1000 + Enum_ov002_0215f4e8_3036));
    func_02041cc0(arg1, 0x18);
    func_02041a90(arg1, 0xc, 0x1f);

    short var1 = 0;
    short var2[9];
    func_ov002_02156080(arg0, var2, &var1);
    int var3 = func_ov002_02161920(arg0);
    for (unsigned char var4 = 0; var4 < var1; var4++) {
        short var5 = var2[var4];
        if (var3 == 1 && var5 == 6) {
            func_02041e70(arg1, 3);
        }
        AppendNameTag_02041b70(dst, i,
                      (const char *) KeyTable_Get((struct Container020e0310 *) (base + NamesOffset), (short) (v + 0xfa1)));
        if (i != count - 1) {
            AppendString02042058(dst, *(const char **) (base + 0x1000 + SeparatorOffset));
        }
        if (var3 == 1 && var5 == 6) {
            func_02041e70(arg1, 0xf);
        }
    }
}
