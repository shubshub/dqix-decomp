#include <globaldefs.h>

#if defined(jpn)
enum { Enum_ov012_02189cbc_5088 = 0x1438, Enum_ov012_02189cbc_4924 = 0x1314, kSeparatorOffset = 0x1348 };
#else
enum { Enum_ov012_02189cbc_5088 = 0x13e0, Enum_ov012_02189cbc_4924 = 0x133c, kSeparatorOffset = 0x1378 };
#endif

extern "C" ARM int Text_AppendFrameTag(char* dst, int a1, int a2, int a3, int a4, int a5);
extern "C" ARM int Text_AppendCursorTag(char* dst, int cursor);
extern "C" ARM int Text_AppendNTag(char* dst, int n, const char* name);
extern "C" ARM int Text_Append(char* dst, const char* src);

struct TableA68;
extern "C" void* func_02072a68(struct TableA68* table, int key);

// USA: func_ov012_02189cbc
extern "C" ARM void func_ov012_02189cbc(char* self, char* dst, int flag) {
    if (dst == 0) return;

    int val = *(int*)(self + Enum_ov012_02189cbc_5088);
    if (flag != 0) {
        Text_AppendFrameTag(dst, val, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, val);

    int i;
    for (i = 0; i < 8; i++) {
        if (i != 0) {
            Text_Append(dst, *(const char**)(self + kSeparatorOffset));
        }
        const char* name = (const char*)func_02072a68((struct TableA68*)(self + Enum_ov012_02189cbc_4924), (short)(i + 0x27d8));
        Text_AppendNTag(dst, i, name);
    }
}
