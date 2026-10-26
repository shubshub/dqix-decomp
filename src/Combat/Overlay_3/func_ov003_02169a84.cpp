#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov003_02169a84_1261 = 0x4e9 };
#else
enum { Enum_ov003_02169a84_1261 = 0x4ed };
#endif

struct Container020e0310;
extern "C" int Text_AppendFrameTag(char* dst, int a1, int a2, int a3, int a4, int a5);
extern "C" int Text_AppendCursorTag(char* dst, int cursor);
extern "C" int KeyTable_Get(struct Container020e0310* c, int key);
extern "C" int Text_AppendNTag(char* dst, int n, const char* name);
extern "C" int Text_Append(char* dst, const char* src);

// USA: func_ov003_02169a84
extern "C" ARM void func_ov003_02169a84(char* base, char* dst, int flag) {
    if (dst == NULL) return;

    signed char cursor = *(signed char*)(base + Enum_ov003_02169a84_1261);
    if (flag) {
        Text_AppendFrameTag(dst, cursor, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, cursor);

    struct Container020e0310* c = (struct Container020e0310*)(base + 0x64);
    int i = 0;
    while (i < 3) {
        int name = KeyTable_Get(c, (short)i);
        Text_AppendNTag(dst, i, (const char*)name);
        if (i != 2) {
            int sep = KeyTable_Get(c, 0x64);
            Text_Append(dst, (const char*)sep);
        }
        i++;
    }
}
