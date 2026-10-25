#include <globaldefs.h>

#if defined(jpn)
#define RG(u, j) (j)
extern "C" int func_02042638(char *arg0, int arg1, int arg2);
#define func_02041fac func_02042638
#else
#define RG(u, j) (u)
#endif

struct Container020e0310;
int KeyTable_Get(struct Container020e0310 *c, int key);
int Text_AppendFrameTag(char *dst, int a1, int a2, int a3, int a4, int a5);
int Text_AppendCursorTag(char *dst, int cursor);
int Text_AppendNTag(char *dst, int n, const char *name);
int Text_Append(char *dst, const char *src);
int AppendFormatted02041fac(char *dst, int str, int b);
extern "C" void __clear(void *buf, int n);

struct Struct_ov002_0215b8c8 {
    char *unknown_0_;
};
extern "C" void func_ov002_0215b8c8(struct Struct_ov002_0215b8c8 *arg0, const char *arg1,
                                                                        int arg2);

// USA: func_ov002_0215cd98
extern "C" ARM void func_ov002_0215cd98(unsigned char *arg0, char *arg1, int arg2) {
    if (arg1 == NULL) return;

    short var0   = 0x4b0;
    int var1 = *(short *) (arg0 + RG(0x1bea, 0x1ab2));

    if (flag) {
        Text_AppendFrameTag(dst, cursor, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, cursor);

    const char *title =
        (const char *) KeyTable_Get((Container020e0310 *) (obj + RG(0x20, 0x8)), id++);
#if defined(jpn)
    func_02041fac(arg1, (int) var2, 0x10);
#else
    char var3[0x80];
    __clear(var3, 0x80);
    struct Struct_ov002_0215b8c8 var4;
    var4.unknown_0_ = var3;
    func_ov002_0215b8c8(&var4, var2, 0);
    func_02041fac(arg1, (int) var3, 0x10);
#endif

    for (int i = 0; i < 4; i++) {
        int field = KeyTable_Get((Container020e0310 *) (obj + RG(0x20, 0x8)), id++);
        Text_AppendNTag(dst, i, (const char *) field);
        if (i != 3) {
            Text_Append(dst, *(char **) (obj + RG(0x1bdc, 0x1aa4)));
        }
    }
}
