#include <globaldefs.h>

#if defined(jpn)
#define RG(u, j) (j)
#else
#define RG(u, j) (u)
#endif

struct Container020e0310;
int KeyTable_Get(struct Container020e0310* c, int key);
int Text_AppendFrameTag(char* dst, int a1, int a2, int a3, int a4, int a5);
int Text_AppendCursorTag(char* dst, int cursor);
int Text_AppendNTag(char* dst, int n, const char* name);
int Text_Append(char* dst, const char* src);

// USA: func_ov002_0215dd0c  (semantic: AppendCursorAndFieldNames_0215dd0c)
extern "C" ARM void func_ov002_0215dd0c(unsigned char* obj, char* dst, int flag) {
    if (dst == NULL) return;

    int cursor = *(short*)(obj + RG(0x1bf2, 0x1aba));
    short id = 0x79f;

    if (flag) {
        Text_AppendFrameTag(dst, cursor, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, cursor);

    for (int i = 0; i < 2; i++) {
        int field = KeyTable_Get((Container020e0310*)(obj + RG(0x20, 0x8)), id++);
        Text_AppendNTag(dst, i, (const char*)field);
        if (i != 1) {
            Text_Append(dst, *(char**)(obj + RG(0x1bdc, 0x1aa4)));
        }
    }
}
