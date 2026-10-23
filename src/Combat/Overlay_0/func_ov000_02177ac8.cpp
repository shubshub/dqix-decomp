#include <globaldefs.h>

#if defined(jpn)
#define data_ov000_021834e0 data_ov000_02184560
#endif
struct Struct_0201099c_3;

int KeyTable_Get(struct Container020e0310* c, int key);
extern "C" int func_020420e8(const char* text, int large);
int IsField0x118Equal2_ov000_0217542c(void* obj);
int AppendFrameTag02041c08(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag_02041ea4(char* dst, int cursor);
int AppendNameTag_02041b70(char* dst, int n, const char* name);
int AppendString02042058(char* dst, const char* src);
int AppendXTag_02041a28(char* dst, int x);

extern int data_ov000_021834e0[6];

// USA: func_ov000_02177ac8
extern "C" ARM void func_ov000_02177ac8(char* arg0, char* arg1) {
    if (arg1 == NULL) {
        return;
    }
#if defined(jpn)
    enum { Enum_ov000_02177ac8_7532 = 0x1fa4 };
    int var0 = 0x4d;
#else
    enum { Enum_ov000_02177ac8_7532 = 0x1d6c };
    int var0 = 0;
#endif
    signed char var1 = *(signed char*)(arg0 + Enum_ov000_02177ac8_7532);
#if !defined(jpn)
    for (int i = 0; i < 3; i++) {
        const char* name = (const char*)KeyTable_Get((struct Container020e0310*)(obj + 0xb8), (short)(i + 30014));
        int width = func_020420e8(name, 0);
        if (maxWidth < width) {
            maxWidth = width;
        }
    }
#endif
    if (func_ov000_0217542c(arg0)) {
        func_02041c08(arg1, var1, 8, 5, 5, 5);
    }
    AppendCursorTag_02041ea4(dst, cursor);
    for (int i = 0; i < 6; i++) {
        int id = data_ov000_021834e0[i];
        AppendNameTag_02041b70(dst, id, (const char*)KeyTable_Get((struct Container020e0310*)(obj + 0xb8), (short)(id + 30014)));
        if (i == 5) {
            break;
        }
        int odd = i & 1;
        if (odd) {
            AppendString02042058(dst, (const char*)KeyTable_Get((struct Container020e0310*)(obj + 0xb8), 0));
        }
        if (!var7) {
            func_02041a28(arg1, var0 + 0x20);
        }
    }
}
