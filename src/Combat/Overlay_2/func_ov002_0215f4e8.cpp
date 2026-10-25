#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov002_0215f4e8_7166 = 0x1ac6, Enum_ov002_0215f4e8_3036 = 0xaa4, Enum_ov002_0215f4e8_32 = 0x8 };
#define func_02041cc0 func_0204234c
#else
enum { Enum_ov002_0215f4e8_7166 = 0x1bfe, Enum_ov002_0215f4e8_3036 = 0xbdc, Enum_ov002_0215f4e8_32 = 0x20 };
#endif

struct Container020e0310;
int KeyTable_Get(struct Container020e0310 *c, int key);
int Text_AppendFrameTag(char *dst, int a1, int a2, int a3, int a4, int a5);
int Text_AppendCursorTag(char *dst, int cursor);
const char *StandardStrings_Get(int key);
int Text_Append(char *dst, const char *src);
#if defined(jpn)
extern "C" int func_0204234c(char *arg0, int arg1);
#else
extern "C" int func_02041cc0(char *arg0, int arg1);
#endif
int AppendXYTag_02041a90(char *dst, int x, int y);
int Text_AppendPaletteTag(char *dst, int palette);
int Text_AppendNTag(char *dst, int n, const char *name);
extern "C" void func_ov002_02156080(void *self, short *out, short *outCount);
extern "C" int func_ov002_02161920(void *self);

// USA: func_ov002_0215f4e8
extern "C" ARM void func_ov002_0215f4e8(unsigned char *arg0, char *arg1, int arg2) {
    if (arg1 == NULL) return;

    int cursor = *(short *) (base + CursorOffset);
    if (flag) {
        Text_AppendFrameTag(dst, cursor, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, cursor);
#if defined(jpn)
    Text_Append(dst, (const char *) KeyTable_Get((struct Container020e0310 *) (base + NamesOffset), 0xfa0));
#else
    Text_Append(dst, StandardStrings_Get(0x16));
#endif
    Text_Append(dst, *(const char **) (base + 0x1000 + SeparatorOffset));
    AppendLineTag02041cc0(dst, 0x18);
    AppendXYTag_02041a90(dst, 0xc, 0x1f);

    short count = 0;
    short list[9];
    func_ov002_02156080(base, list, &count);
    int mode = func_ov002_02161920(base);
    for (unsigned char i = 0; i < count; i++) {
        short v = list[i];
        if (mode == 1 && v == 6) {
            Text_AppendPaletteTag(dst, 3);
        }
        Text_AppendNTag(dst, i,
                      (const char *) KeyTable_Get((struct Container020e0310 *) (base + NamesOffset), (short) (v + 0xfa1)));
        if (i != count - 1) {
            Text_Append(dst, *(const char **) (base + 0x1000 + SeparatorOffset));
        }
        if (mode == 1 && v == 6) {
            Text_AppendPaletteTag(dst, 0xf);
        }
    }
}
