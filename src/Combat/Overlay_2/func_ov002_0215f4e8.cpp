#include <globaldefs.h>

#if defined(jpn)
enum { CursorOffset = 0x1ac6, SeparatorOffset = 0xaa4, NamesOffset = 0x8 };
#define func_02041cc0 func_0204234c
#else
enum { CursorOffset = 0x1bfe, SeparatorOffset = 0xbdc, NamesOffset = 0x20 };
#endif

struct Container020e0310;
extern "C" int KeyTable_Get(struct Container020e0310 *c, int key);
extern "C" int Text_AppendFrameTag(char *dst, int a1, int a2, int a3, int a4, int a5);
extern "C" int Text_AppendCursorTag(char *dst, int cursor);
extern "C" const char *StandardStrings_Get(int key);
extern "C" int Text_Append(char *dst, const char *src);
#if defined(jpn)
extern "C" int func_0204234c(char *dst, int a);
#else
extern "C" int func_02041cc0(char *dst, int a);
#endif
extern "C" int func_02041a90(char *dst, int x, int y);
extern "C" int Text_AppendPaletteTag(char *dst, int palette);
extern "C" int Text_AppendNTag(char *dst, int n, const char *name);
extern "C" void func_ov002_02156080(void *self, short *out, short *outCount);
extern "C" int func_ov002_02161920(void *self);

// USA: func_ov002_0215f4e8
extern "C" ARM void func_ov002_0215f4e8(unsigned char *base, char *dst, int flag) {
    if (dst == NULL) return;

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
    func_02041cc0(dst, 0x18);
    func_02041a90(dst, 0xc, 0x1f);

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
