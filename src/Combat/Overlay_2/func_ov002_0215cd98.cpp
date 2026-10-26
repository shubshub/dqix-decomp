#include <globaldefs.h>

#if defined(jpn)
#define RG(u, j) (j)
extern "C" int func_02042638(char *dst, int str, int b);
#define func_02041fac func_02042638
#else
#define RG(u, j) (u)
#endif

struct Container020e0310;
extern "C" int KeyTable_Get(struct Container020e0310 *c, int key);
extern "C" int Text_AppendFrameTag(char *dst, int a1, int a2, int a3, int a4, int a5);
extern "C" int Text_AppendCursorTag(char *dst, int cursor);
extern "C" int Text_AppendNTag(char *dst, int n, const char *name);
extern "C" int Text_Append(char *dst, const char *src);
extern "C" int func_02041fac(char *dst, int str, int b);
extern "C" void __clear(void *buf, int n);

struct Struct_ov002_0215b8c8 {
    char *dst;
};
extern "C" void func_ov002_0215b8c8(struct Struct_ov002_0215b8c8 *holder, const char *str,
                                                                        int value);

// USA: func_ov002_0215cd98
extern "C" ARM void func_ov002_0215cd98(unsigned char *obj, char *dst, int flag) {
    if (dst == NULL) return;

    short id   = 0x4b0;
    int cursor = *(short *) (obj + RG(0x1bea, 0x1ab2));

    if (flag) {
        Text_AppendFrameTag(dst, cursor, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, cursor);

    const char *title =
        (const char *) KeyTable_Get((Container020e0310 *) (obj + RG(0x20, 0x8)), id++);
#if defined(jpn)
    func_02041fac(dst, (int) title, 0x10);
#else
    char buf[0x80];
    __clear(buf, 0x80);
    struct Struct_ov002_0215b8c8 holder;
    holder.dst = buf;
    func_ov002_0215b8c8(&holder, title, 0);
    func_02041fac(dst, (int) buf, 0x10);
#endif

    for (int i = 0; i < 4; i++) {
        int field = KeyTable_Get((Container020e0310 *) (obj + RG(0x20, 0x8)), id++);
        Text_AppendNTag(dst, i, (const char *) field);
        if (i != 3) {
            Text_Append(dst, *(char **) (obj + RG(0x1bdc, 0x1aa4)));
        }
    }
}
