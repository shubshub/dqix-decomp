#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov003_0215e13c_961 = 0x3d9 };
enum { Enum_ov003_0215e13c_100 = 0x7c };
enum { Enum_ov003_0215e13c_960 = 0x3d8 };
enum { Enum_ov003_0215e13c_957 = 0x3d5 };
#else
enum { Enum_ov003_0215e13c_961 = 0x3c1 };
enum { Enum_ov003_0215e13c_100 = 0x64 };
enum { Enum_ov003_0215e13c_960 = 0x3c0 };
enum { Enum_ov003_0215e13c_957 = 0x3bd };
#endif

struct Container020e0310;
extern "C" int Text_AppendFrameTag(char* dst, int a1, int a2, int a3, int a4, int a5);
extern "C" int Text_AppendCursorTag(char* dst, int cursor);
extern "C" int KeyTable_Get(struct Container020e0310* c, int key);
extern "C" int Text_AppendNTag(char* dst, int n, const char* name);
extern "C" int Text_Append(char* dst, const char* src);

extern char data_ov003_0217ff3e;

// USA: func_ov003_0215e13c
extern "C" ARM void func_ov003_0215e13c(char* base, char* dst, int flag) {
    if (dst == NULL) return;

    signed char cursor = *(signed char*)(base + Enum_ov003_0215e13c_961);
    if (flag) {
        Text_AppendFrameTag(dst, cursor, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, cursor);

    struct Container020e0310* c = (struct Container020e0310*)(base + Enum_ov003_0215e13c_100);
    int i = 0;
    while (i < *(unsigned char*)(base + Enum_ov003_0215e13c_960)) {
        unsigned char key = *(unsigned char*)(base + i + Enum_ov003_0215e13c_957);
        int name = KeyTable_Get(c, key);
        Text_AppendNTag(dst, i, (const char*)name);
        if (i != *(unsigned char*)(base + Enum_ov003_0215e13c_960) - 1) {
            Text_Append(dst, &data_ov003_0217ff3e);
        }
        i++;
    }
}
