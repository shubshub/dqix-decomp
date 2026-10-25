#include <globaldefs.h>

#if defined(jpn)
enum { kCursorOffset = 0x1450, kStringsOffset = 0x1314, kSeparatorOffset = 0x1348 };
#else
enum { kCursorOffset = 0x13f8, kStringsOffset = 0x133c, kSeparatorOffset = 0x1378 };
#endif

ARM int Text_AppendFrameTag(char* dst, int a1, int a2, int a3, int a4, int a5);
ARM int Text_AppendCursorTag(char* dst, int cursor);
ARM int Text_AppendNTag(char* dst, int n, const char* name);
ARM int Text_Append(char* dst, const char* src);

struct TableA68;
void* FindEntryByKey_02072a68(struct TableA68* table, int key);

// USA: func_ov012_02189fb0  (semantic: BuildBattleTag02189fb0)
extern "C" ARM void func_ov012_02189fb0(char* self, char* dst, int flag) {
    if (dst == 0) return;

    int val = *(int*)(self + kCursorOffset);
    if (flag != 0) {
        Text_AppendFrameTag(dst, val, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, val);

    const char* name1 = (const char*)FindEntryByKey_02072a68((struct TableA68*)(self + kStringsOffset), 0x10);
    Text_AppendNTag(dst, 0, name1);

    Text_Append(dst, *(const char**)(self + kSeparatorOffset));

    const char* name2 = (const char*)FindEntryByKey_02072a68((struct TableA68*)(self + kStringsOffset), 0x11);
    Text_AppendNTag(dst, 1, name2);
}
