#include <globaldefs.h>

#if defined(jpn)
#define data_ov000_021834e0 data_ov000_02184560
#endif
struct Container020e0310;

extern "C" int KeyTable_Get(struct Container020e0310* c, int key);
extern "C" int Font_GetTextWidth(const char* text, int large);
extern "C" int func_ov000_0217542c(void* obj);
extern "C" int Text_AppendFrameTag(char* dst, int a1, int a2, int a3, int a4, int a5);
extern "C" int Text_AppendCursorTag(char* dst, int cursor);
extern "C" int Text_AppendNTag(char* dst, int n, const char* name);
extern "C" int Text_Append(char* dst, const char* src);
extern "C" int func_02041a28(char* dst, int x);

extern int data_ov000_021834e0[6];

// USA: func_ov000_02177ac8
extern "C" ARM void func_ov000_02177ac8(char* obj, char* dst) {
    if (dst == NULL) {
        return;
    }
#if defined(jpn)
    enum { Enum_ov000_02177ac8_7532 = 0x1fa4 };
    int var0 = 0x4d;
#else
    enum { Enum_ov000_02177ac8_7532 = 0x1d6c };
    int var0 = 0;
#endif
    signed char cursor = *(signed char*)(obj + Enum_ov000_02177ac8_7532);
#if !defined(jpn)
    for (int i = 0; i < 3; i++) {
        const char* name = (const char*)KeyTable_Get((struct Container020e0310*)(obj + 0xb8), (short)(i + 30014));
        int width = Font_GetTextWidth(name, 0);
        if (var0 < width) {
            var0 = width;
        }
    }
#endif
    if (func_ov000_0217542c(obj)) {
        Text_AppendFrameTag(dst, cursor, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, cursor);
    for (int i = 0; i < 6; i++) {
        int id = data_ov000_021834e0[i];
        Text_AppendNTag(dst, id, (const char*)KeyTable_Get((struct Container020e0310*)(obj + 0xb8), (short)(id + 30014)));
        if (i == 5) {
            break;
        }
        int var7 = i & 1;
        if (var7) {
            Text_Append(dst, (const char*)KeyTable_Get((struct Container020e0310*)(obj + 0xb8), 0));
        }
        if (!var7) {
            func_02041a28(dst, var0 + 0x20);
        }
    }
}
