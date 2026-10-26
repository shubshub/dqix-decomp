#include <globaldefs.h>

struct Container020e0310;

extern "C" int Font_GetTextWidth(const char* str, int flags);
extern "C" int Text_AppendFrameTag(char* dst, int a1, int a2, int a3, int a4, int a5);
extern "C" int Text_AppendCursorTag(char* dst, int cursor);
extern "C" int KeyTable_Get(struct Container020e0310* c, int key);
extern "C" int func_02041a28(char* dst, int x);
extern "C" int func_02041fac(char* buf, int a, int b);
extern "C" int Text_AppendNTag(char* dst, int n, const char* name);
extern "C" int Text_Append(char* dst, const char* src);

#if defined(jpn)
extern "C" int func_02042638(char* dst, int str, int a);
#endif

// USA: func_ov002_0215fbd4
#if defined(jpn)
extern "C" ARM void func_ov002_0215fbd4(char* obj, char* dst, int flag) {
    if (dst == NULL) return;

    int cursor = *(short*)(obj + 0x1a00 + 0xcc);
    short key = 0x109c;

    if (flag) {
        Text_AppendFrameTag(dst, cursor, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, cursor);

    func_02041a28(dst, 0xf);
    struct Container020e0310* c = (struct Container020e0310*)(obj + 0x8);
    cursor = KeyTable_Get(c, 0x109a);
    func_02042638(dst, cursor, 0x10);

    char* ptr;
    int i;
    i = 0;
    for (; i < 6; i++) {
        ptr = obj + 0x1000;
        short oldKey = key;
        key++;
        int name = KeyTable_Get(c, oldKey);
        Text_AppendNTag(dst, i, (const char*)name);
        if (i != 5) {
            Text_Append(dst, *(char**)(ptr + 0xaa4));
        }
    }
}
#else
extern "C" ARM void func_ov002_0215fbd4(char* obj, char* dst, int flag) {
    if (dst == NULL) return;

    int cursor = *(short*)(obj + 0x1c00 + 0x4);
    short key = 0x109c;

    if (flag) {
        Text_AppendFrameTag(dst, cursor, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, cursor);

    struct Container020e0310* c = (struct Container020e0310*)(obj + 0x20);
    cursor = KeyTable_Get(c, 0x109a);
    int width = Font_GetTextWidth((const char*)cursor, 0);
    func_02041a28(dst, (0x78 - width) >> 1);
    func_02041fac(dst, cursor, 0x10);

    char* ptr;
    int i;
    i = 0;
    ptr = obj + 0x1000;
    for (; i < 6; i++) {
        short oldKey = key;
        key++;
        int name = KeyTable_Get(c, oldKey);
        Text_AppendNTag(dst, i, (const char*)name);
        if (i != 5) {
            Text_Append(dst, *(char**)(ptr + 0xbdc));
        }
    }
}
#endif
